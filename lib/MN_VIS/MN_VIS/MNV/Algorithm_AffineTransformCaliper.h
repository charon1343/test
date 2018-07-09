#pragma once
#include "Image_AffineTransform.h"
#include "MNVCaliper.h"
class CMNVInspect_AffineTransformCaliper {
public:
	//CMNVImage m_imgSource;
	CMNVImage m_imgAffineTransform;
	CMNVImage  m_imgOutputMask;
	MNVAffineTransform m_AlgProcessing;
	CMNVCaliper m_InspectCaliper;
	CMNVStaticGraphicCollection m_sgcRegion;
	int m_nCount;
	int m_nHalfPixel;
	double m_dThreshold;
	int m_nMaxResult;
	void LoadIni(LPCTSTR __strFilePath) {
		m_AlgProcessing.LoadIni(__strFilePath);

		m_nCount = CMNVIni::GetValue(_T("Caliper"), _T("RegionH"), (int)10, __strFilePath);
		m_nHalfPixel = CMNVIni::GetValue(_T("Caliper"), _T("HalfPixel"), (int)10, __strFilePath);
		m_dThreshold = CMNVIni::GetValue(_T("Caliper"), _T("Threshold"), (double)10, __strFilePath);
		m_nMaxResult = CMNVIni::GetValue(_T("Caliper"), _T("MaxResult"), (int)10, __strFilePath);
		//[Caliper]
		//RegionW=1
		//RegionH=10
		//HalfPixel=30
		//Threshold=20
		//MaxResult=10
	}
	void SaveIni(LPCTSTR __strFilePath) {
		m_AlgProcessing.SaveIni(__strFilePath);
		CMNVIni::GetValue(_T("Caliper"), _T("RegionH"), m_nCount, __strFilePath);
		CMNVIni::GetValue(_T("Caliper"), _T("HalfPixel"), m_nHalfPixel, __strFilePath);
		CMNVIni::GetValue(_T("Caliper"), _T("Threshold"), m_dThreshold, __strFilePath);
		CMNVIni::GetValue(_T("Caliper"), _T("MaxResult"), m_nMaxResult, __strFilePath);
	}
	void Excute(CMNVImage & __imgSource, CMNVStaticGraphicCollection & __sgcResult) {
		//__imgSource.Copy(m_imgSource);

		__sgcResult.AddGraphic(m_AlgProcessing.m_Region, 1, cogColorYellow);
		//m_AlgProcessing.Excute(__imgSource, m_imgOutputMask, m_imgAffineTransform);
		//m_imgAffineTransform.Copy(__imgSource);
		//double dWidth = m_imgAffineTransform.GetWidth();
		//double dHeight = m_imgAffineTransform.GetHeight();

		//CMNV_STPoint stCenter;
		//CMNV_STPoint stInterval;
		//stCenter.Set(dWidth / 2, dHeight / (m_nCount * 2));
		//stInterval.Set(0, dHeight / m_nCount);

		double dX, dY, dScore;
		double dCenterX = m_AlgProcessing.m_Region.GetCenterX();
		double dCenterY = m_AlgProcessing.m_Region.GetCenterY();
		double dWidth = m_AlgProcessing.m_Region.GetWidth();
		double dHeight = m_AlgProcessing.m_Region.GetHeight();
		double dLeft = dCenterX - dWidth / 2;
		double dTop = dCenterY - dHeight / 2;
		double dCX, dCY, dW, dH;
		CMNVRectangleAffine rectaRegion;
		CString strScore;
		bool isFirst = true;
		for(int nIndex = 0; nIndex < m_nCount; ++nIndex) {
			dCX = dLeft + dWidth / 2;
			dCY = dTop + (dHeight / (m_nCount * 2)) + ((dHeight / m_nCount) * nIndex);
			dW = dWidth;
			dH = (dHeight / m_nCount);

			rectaRegion.SetRect_CenterWH(dCX, dCY, dW, dH, 0, 0);
			m_InspectCaliper.Create();

			m_InspectCaliper.Execute_Center(__imgSource, rectaRegion, m_nMaxResult, m_dThreshold, m_nHalfPixel);

			int idxResult = 0;
			isFirst = true;
			while ( m_InspectCaliper.GetResult(idxResult, dX, dY, dScore) ) {
//				m_AlgProcessing->
				if (AddResult(dX, dY, dScore, dX, dY, dScore, isFirst)) {
					strScore.Format(_T("%d"), (int)dScore);
					__sgcResult.AddCircleSegment(1, cogColorYellow, dX, dY, dScore);
					//__sgcResult.AddPoint(dX, dY, 0, 1, (dHeight / m_nCount) / 2, cogColorRed);
					//__sgcResult.AddLabel(dX, dY, 1, 1, strScore, cogColorGreen, cogColorNone, cogGraphicLabelAlignmentTopCenter);
				}
				isFirst = false;
				++idxResult;
			}
			//stCenter.m_dY += stInterval.GetY();
		}
	}
	bool AddResult(double __dX, double __dY, double __dScore, double & __dResultX, double & __dResultY, double &__dResultS, bool __isFirst = false) {
		static double dLastX = 0, dLastY = 0, dLastS = 0;
		double dDist = abs(dLastX - __dX);
		if (dDist > 100) __isFirst = true;

		if (__isFirst) {
			dLastX = __dX, dLastY = __dY, dLastS = __dScore;
		}
		else {
			if (( __dScore * dLastS) > 0) { // 부호가 같음
				dLastX = (dLastX * abs(dLastS) + __dX  * abs(__dScore)) / abs(dLastS + __dScore);
				dLastY = (dLastY * abs(dLastS) + __dY  * abs(__dScore)) / abs(dLastS + __dScore);
				dLastS = dLastS + __dScore;
			}
			else {	// 부호가 다름 (Edge 쌍 검출)
				__dResultS = abs(__dX - dLastX);
				__dResultX = (__dX + dLastX) / 2;
				__dResultY = (__dY + dLastY) / 2;

				//strScore.Format(_T("%d"), (int)dDist);
				//m_ImageProcessing->GetInputPointFromOutputPoint(__imgSource, CComQIPtr<ICogRegion>(m_ImageProcessing.m_Region), dX, dY, &dX, &dY);
				//__sgcResult.AddPoint(dX, dY, 0, 1, stInterval.GetY() / 2, cogColorRed);
				//__sgcResult.AddLabel(dX, dY, 0.5, 1, strScore, cogColorRed, cogColorNone, cogGraphicLabelAlignmentTopCenter);
				return true;
			}
		}
		return false;
	}
};
