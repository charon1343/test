#pragma once
#include "MNVGraphicsCollection.h"

/// Region Object

// Algorithm
class MNVAffineTransform : public CComPtr<ICogAffineTransform>
{
public:
	CMNVRectangleAffine m_Region;
	bool SetRegion_Section(double __dCenterX, double __dCenterY, double __dWidth, double __dHeight, double __dAngle, double __dSkew) {
		return m_Region.SetRect_CenterWH(__dCenterX, __dCenterY, __dWidth, __dHeight, __dAngle, __dSkew);
	}
	bool SetRegion_Interactive(bool __isEnable) {
		return m_Region.SetInterectiveRegion(__isEnable);
	}
	bool SetRegion_Style(CogGraphicLineStyleConstants __LineStyle, CogColorConstants __Color, int __nLineWidth) {
		return m_Region.SetStyle(__LineStyle, __Color, __nLineWidth);
	}

	bool Create() { 
		Release();
		return SUCCEEDED( CoCreateInstance(CLSID_CogAffineTransform) );
	}
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogAffineTransform>::Release();
	}

	MNVAffineTransform(): CComPtr<ICogAffineTransform>() { Create(); }
	~MNVAffineTransform() { Release(); }

	bool InitProcessing(CogAffineTransformSamplingModeConstants __SamplingMode, double __dScaleX, double __dScaleY) {
		//CogPolarUnwrapSamplingModeConstants::cogPolarUnwrapSamplingModeBilinearInterpolation;
		//CogPolarUnwrapSamplingModeConstants::cogPolarUnwrapSamplingModeNearestNeighbor;

		//p->put_ClipFillPlane0Value(long pVal);
		//p->put_ClipFillPlane1Value(long pVal);
		//p->put_ClipFillPlane2Value(long pVal);
		//p->put_ClipFillValue(long pVal);
		//p->put_ClipMode(CogAffineTransformClipModeConstants::cogAffineTransformClipModeError);
		//CogAffineTransformClipModeConstants::cogAffineTransformClipModeFill;
		//CogAffineTransformClipModeConstants::cogAffineTransformClipModeZeroes;

		//p->put_SamplingMode(CogAffineTransformSamplingModeConstants::cogAffineTransformSamplingModeBilinearAccurate); 양선형 정확도
		//CogAffineTransformSamplingModeConstants::cogAffineTransformSamplingModeBilinearInterpolation; 양선형 보간법
		//CogAffineTransformSamplingModeConstants::cogAffineTransformSamplingModeHighPrecision; 최고 정밀도


		//p->put_ScalingX(double pVal);
		//p->put_ScalingY(double pVal);

		if (p == NULL && !Create()) return false;
		if ( FAILED( p->put_ClipFillValue(cogAffineTransformClipModeZeroes) ) ) return false; // 클리핑 모드 : 0으로 처리

		if ( FAILED( p->put_SamplingMode(__SamplingMode) ) ) return false; // 양선형 보간법
		if ( FAILED( p->put_ScalingX(__dScaleX) ) ) return false; // X배율 인수
		return SUCCEEDED( p->put_ScalingY(__dScaleY) ); // Y배율 인수
	}
	bool Excute(CMNVImage & __imgSource, CMNVImage & __imgOutputMask, CMNVImage & __imgDest) {
		if (p == NULL) return false;
		__imgDest.Release();
		return SUCCEEDED( p->Execute(__imgSource, m_Region, &__imgOutputMask, &__imgDest) );
	}

	bool Excute(CMNVImage & __imgSource, CMNVRectangleAffine & __Region, CMNVImage & __imgOutputMask, CMNVImage & __imgDest) {
		if (p == NULL) return false;
		return SUCCEEDED( p->Execute(__imgSource, __Region, &__imgOutputMask, &__imgDest) );
	}

	bool Excute(CMNVImage & __imgSource, CMNVRectangleAffine & __Region, CogAffineTransformSamplingModeConstants __SamplingMode, double __dScaleX, double __dScaleY, CMNVImage &  __imgOutputMask, CMNVImage & __imgDest) {
		if ( InitProcessing(__SamplingMode, __dScaleX, __dScaleY) ) {
			return Excute(__imgSource, __Region, __imgOutputMask, __imgDest);
		}
		return false;
	}

	void Func() {
		//CMNVImage imgSource;
		//CMNVImage imgDest;

		//MNVCircularAnnulusSection Section;
		//p->put_SamplingMode(CogPolarUnwrapSamplingModeConstants::cogPolarUnwrapSamplingModeNearestNeighbor); // 인접 픽셀 샘플링

		//p->Execute(imgSource, CComQIPtr<ICogRegion>(Section), &imgDest);
	}

	bool LoadIni(LPCTSTR __strFilePath) {
		double dScaleX = CMNVIni::GetValue(_T("Setting"), _T("ScaleX"), (double)1, __strFilePath);
		double dScaleY = CMNVIni::GetValue(_T("Setting"), _T("ScaleY"), (double)1, __strFilePath);
		int nSampling = CMNVIni::GetValue(_T("Setting"), _T("Sampling"), (int)0, __strFilePath);
		if (! InitProcessing((CogAffineTransformSamplingModeConstants)nSampling, dScaleX, dScaleY) ) return false;
		
		double dCenterX = CMNVIni::GetValue(_T("Region"), _T("CenterX"), (double)1, __strFilePath);
		double dCenterY = CMNVIni::GetValue(_T("Region"), _T("CenterY"), (double)1, __strFilePath);
		double dWidth = CMNVIni::GetValue(_T("Region"), _T("Width"), (double)1, __strFilePath);
		double dHeight = CMNVIni::GetValue(_T("Region"), _T("Height"), (double)1, __strFilePath);
		double dAngle = CMNVIni::GetValue(_T("Region"), _T("Angle"), (double)1, __strFilePath);
		double dSkew = CMNVIni::GetValue(_T("Region"), _T("Skew"), (double)1, __strFilePath);
		return SetRegion_Section(dCenterX, dCenterY, dWidth, dHeight, dAngle, dSkew);
	}
	bool SaveIni(LPCTSTR __strFilePath) {
		double dScaleX, dScaleY;
		CogAffineTransformSamplingModeConstants nSampling;

		p->get_SamplingMode(&nSampling);
		p->get_ScalingX(&dScaleX);
		p->get_ScalingY(&dScaleY);
		
		CMNVIni::SetValue(_T("Setting"), _T("ScaleX"), dScaleX, __strFilePath);
		CMNVIni::SetValue(_T("Setting"), _T("ScaleY"), dScaleY, __strFilePath);
		CMNVIni::SetValue(_T("Setting"), _T("Sampling"), (int)nSampling, __strFilePath);

		double dCenterX, dCenterY, dWidth, dHeight, dAngle, dSkew;
		m_Region.GetRect_CenterWH(dCenterX, dCenterY, dWidth, dHeight, dAngle, dSkew);
		CMNVIni::SetValue(_T("Region"), _T("CenterX"), dCenterX, __strFilePath);
		CMNVIni::SetValue(_T("Region"), _T("CenterY"), dCenterY, __strFilePath);
		CMNVIni::SetValue(_T("Region"), _T("Width"), dWidth, __strFilePath);
		CMNVIni::SetValue(_T("Region"), _T("Height"), dHeight, __strFilePath);
		CMNVIni::SetValue(_T("Region"), _T("Angle"), dAngle, __strFilePath);
		CMNVIni::SetValue(_T("Region"), _T("Skew"), dSkew, __strFilePath);
	}
};
