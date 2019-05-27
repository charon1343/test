#pragma once
#include "MNVGraphicsCollection.h"

/// Region Object

// Algorithm
class MNVPolarUnwrap : public CComPtr<ICogPolarUnwrap>
{
public:
	MNVCircularAnnulusSection m_Region;
	bool SetRegion_Section(double __dCenterX, double __dCenterY, double __dRadius, double __dRadiusScale, double __dAngleStart, double __dAngleSpan) {
		return m_Region.SetSection(__dCenterX, __dCenterY, __dRadius, __dRadiusScale, __dAngleStart, __dAngleSpan);
	}
	bool SetRegion_Interactive(bool __isEnable) {
		return m_Region.SetInteractive(__isEnable);
	}
	bool SetRegion_Style(CogGraphicLineStyleConstants __LineStyle, CogColorConstants __Color, int __nLineWidth) {
		return m_Region.SetStyle(__LineStyle, __Color, __nLineWidth);
	}

	bool Create() { 
		Release();
		return SUCCEEDED( CoCreateInstance(CLSID_CogPolarUnwrap) );
	}
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogPolarUnwrap>::Release();
	}

	MNVPolarUnwrap(): CComPtr<ICogPolarUnwrap>() { Create(); }
	~MNVPolarUnwrap() { Release(); }

	bool InitProcessing(CogPolarUnwrapSamplingModeConstants __SamplingMode, double __dScaleX, double __dScaleY) {
		//CogPolarUnwrapSamplingModeConstants::cogPolarUnwrapSamplingModeBilinearInterpolation;
		//CogPolarUnwrapSamplingModeConstants::cogPolarUnwrapSamplingModeNearestNeighbor;

		if (p == NULL && !Create()) return false;
		if ( FAILED( p->put_SamplingMode(__SamplingMode) ) ) return false; // 양선형 보간법
		if ( FAILED( p->put_ScalingX(__dScaleX) ) ) return false; // X배율 인수
		return SUCCEEDED( p->put_ScalingY(__dScaleY) ); // Y배율 인수
	}
	bool Excute(CMNVImage & __imgSource, CMNVImage & __imgDest, double __dCenterX = 0, double __dCenterY = 0) {
		if (p == NULL) return false;
		__imgDest.Release();
		if (__dCenterX != 0 && __dCenterY != 0) m_Region.SetCenter(__dCenterX, __dCenterY);
		return SUCCEEDED( p->Execute(__imgSource, CComQIPtr<ICogRegion>(m_Region), &__imgDest) );
	}

	bool Excute(CMNVImage & __imgSource, MNVCircularAnnulusSection & __Region, CMNVImage & __imgDest) {
		if (p == NULL) return false;
		return SUCCEEDED( p->Execute(__imgSource, CComQIPtr<ICogRegion>(__Region), &__imgDest) );
	}

	bool Excute(CMNVImage & __imgSource, MNVCircularAnnulusSection & __Region, CogPolarUnwrapSamplingModeConstants __SamplingMode, double __dScaleX, double __dScaleY, CMNVImage & __imgDest) {
		if ( InitProcessing(__SamplingMode, __dScaleX, __dScaleY) ) {
			return Excute(__imgSource, __Region, __imgDest);
		}
		return false;
	}

	void Func() {
		CMNVImage imgSource;
		CMNVImage imgDest;

		MNVCircularAnnulusSection Section;
		p->put_SamplingMode(cogPolarUnwrapSamplingModeNearestNeighbor); // 인접 픽셀 샘플링

		p->Execute(imgSource, CComQIPtr<ICogRegion>(Section), &imgDest);
	}

	bool LoadIni(LPCTSTR __strFilePath) {
		double dScaleX = CMNVIni::GetValue(_T("Setting"), _T("ScaleX"), (double)1, __strFilePath);
		double dScaleY = CMNVIni::GetValue(_T("Setting"), _T("ScaleY"), (double)1, __strFilePath);
		int nSampling = CMNVIni::GetValue(_T("Setting"), _T("Sampling"), (int)0, __strFilePath);
		if (! InitProcessing((CogPolarUnwrapSamplingModeConstants)nSampling, dScaleX, dScaleY) ) return false;
		
		double dCenterX = CMNVIni::GetValue(_T("Region"), _T("CenterX"), (double)1, __strFilePath);
		double dCenterY = CMNVIni::GetValue(_T("Region"), _T("CenterY"), (double)1, __strFilePath);
		double dRadius = CMNVIni::GetValue(_T("Region"), _T("Radius"), (double)1, __strFilePath);
		double dRadiusScale = CMNVIni::GetValue(_T("Region"), _T("RadiusScale"), (double)1, __strFilePath);
		double dAngleStart = CMNVIni::GetValue(_T("Region"), _T("AngleStart"), (double)1, __strFilePath);
		double dAngleSpan = CMNVIni::GetValue(_T("Region"), _T("AngleSpan"), (double)1, __strFilePath);
		return SetRegion_Section(dCenterX, dCenterY, dRadius, dRadiusScale, dAngleStart, dAngleSpan);
	}
	bool SaveIni(LPCTSTR __strFilePath) {
		double dScaleX, dScaleY;
		CogPolarUnwrapSamplingModeConstants nSampling;

		p->get_SamplingMode(&nSampling);
		p->get_ScalingX(&dScaleX);
		p->get_ScalingY(&dScaleY);
		
		CMNVIni::SetValue(_T("Setting"), _T("ScaleX"), dScaleX, __strFilePath);
		CMNVIni::SetValue(_T("Setting"), _T("ScaleY"), dScaleY, __strFilePath);
		CMNVIni::SetValue(_T("Setting"), _T("Sampling"), (int)nSampling, __strFilePath);

		double dCenterX, dCenterY, dRadius, dRadiusScale, dAngleStart, dAngleSpan;
		m_Region->GetCenterRadiusAngleStartAngleSpanRadialScale(&dCenterX, &dCenterY, &dRadius, &dAngleStart, &dAngleSpan, &dRadiusScale);

		CMNVIni::SetValue(_T("Region"), _T("CenterX"), dCenterX, __strFilePath);
		CMNVIni::SetValue(_T("Region"), _T("CenterY"), dCenterY, __strFilePath);
		CMNVIni::SetValue(_T("Region"), _T("Radius"), dRadius, __strFilePath);
		CMNVIni::SetValue(_T("Region"), _T("RadiusScale"), dRadiusScale, __strFilePath);
		CMNVIni::SetValue(_T("Region"), _T("AngleStart"), dAngleStart, __strFilePath);
		CMNVIni::SetValue(_T("Region"), _T("AngleSpan"), dAngleSpan, __strFilePath);
	}
};
