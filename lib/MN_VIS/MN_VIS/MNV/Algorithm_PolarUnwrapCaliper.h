#pragma once
#include "Image_PolarUnwrap.h"
#include "MNVCaliper.h"
#include "MNVRegion.h"
#include "MNV_FindLine.h"

class CMNVInspect_PolarUnwrapCaliper {
public:
	//CMNVImage m_imgSource;
	CMNV_FindCircle m_FindCircle;
	CMNVImage m_imgPolarUnwarp;
	MNVPolarUnwrap m_ImageProcessing;
	CMNVCaliper m_InspectAlgorithm;
	CMNVStaticGraphicCollection m_sgcRegion;
	int m_nCount;
	int m_nHalfPixel;
	double m_dThreshold;
	int m_nMaxResult;
	double m_dMinSize;
	double m_dMaxSize;
	void LoadIni(LPCTSTR __strFilePath) {
		CMNVLogFile Log(_T("PolarUnwrapCaliper"), _T("LoadIni"), _T("D:\\Log"), _T("MNVision.txt"));
		bool isResult = m_ImageProcessing.LoadIni(__strFilePath);

		m_nCount = CMNVIni::GetValue(_T("Caliper"), _T("RegionH"), (int)10, __strFilePath);
		m_nHalfPixel = CMNVIni::GetValue(_T("Caliper"), _T("HalfPixel"), (int)10, __strFilePath);
		m_dThreshold = CMNVIni::GetValue(_T("Caliper"), _T("Threshold"), (double)10, __strFilePath);
		m_nMaxResult = CMNVIni::GetValue(_T("Caliper"), _T("MaxResult"), (int)10, __strFilePath);

		m_dMinSize = CMNVIni::GetValue(_T("Size"), _T("Min"), (double)10, __strFilePath);
		m_dMaxSize = CMNVIni::GetValue(_T("Size"), _T("Max"), (double)100, __strFilePath);

		Log.OutputMessage(_T("m_FindCircle.Prepare"));
		m_FindCircle.Prepare(__strFilePath, _T("FindCircle"));
	}
	void SaveIni(LPCTSTR __strFilePath) {
		m_ImageProcessing.SaveIni(__strFilePath);
		m_FindCircle.SaveIni(__strFilePath, _T("FindCircle"));
		CMNVIni::GetValue(_T("Size"), _T("Min"), m_dMinSize, __strFilePath);
		CMNVIni::GetValue(_T("Size"), _T("Max"), m_dMaxSize, __strFilePath);
	}
	bool Excute(CMNVImage & __imgSource, CMNVStaticGraphicCollection & __sgcResult) {
		//__imgSource.Copy(m_imgSource);
		double dCenterX = 0, dCenterY = 0;
		//if( !m_FindCircle.Excute(__imgSource) ) {
		m_FindCircle.Excute(__imgSource);
		CMNVCircle circleResult;
		m_FindCircle.GetResult(circleResult);
		if (circleResult == NULL) {
			__sgcResult.AddGraphic(m_FindCircle.m_CircurlarArc, 1, cogColorYellow);
			__sgcResult.AddLabel(10, 100, 1.5, 100, _T("Circle Not Find"), cogColorRed, cogColorNone, cogGraphicLabelAlignmentTopLeft);
		}
		else {
			m_FindCircle.GetResult(__sgcResult);
			dCenterX = circleResult.GetCenterX();
			dCenterY = circleResult.GetCenterY();
			__sgcResult.AddLabel(10, 100, 1.5, 100, _T("Circle Find"), cogColorGreen, cogColorNone, cogGraphicLabelAlignmentTopLeft);
		}
		//}
		//else  {
		//}
		m_ImageProcessing.Excute(__imgSource, m_imgPolarUnwarp, dCenterX, dCenterY);
		//m_imgPolarUnwarp.Copy(__imgSource);


		double dWidth = m_imgPolarUnwarp.GetWidth();
		double dHeight = m_imgPolarUnwarp.GetHeight();

		CMNV_STPoint stCenter;
		CMNV_STPoint stInterval;
		{
			//stCenter.Set(dWidth / 2, dHeight / (m_nCount * 2));
			//stInterval.Set(0, dHeight / m_nCount);
			stCenter.Set(dWidth / (m_nCount * 2), dHeight / 2);
			stInterval.Set(dHeight / m_nCount, 0);
		}
		m_nCount = (m_nCount > (int)(dHeight / 2)) ? (int)(dHeight / 2) : m_nCount;
		double dX, dY, dScore;
		double dCX, dCY, dW, dH;
		CMNVRectangleAffine rectaRegion;
		CString strScore;
		int nCount = 0;
		bool isFirst = true;
		for(int nIndex = 0; nIndex < m_nCount; ++nIndex) {
			dCX = /*(dWidth / (m_nCount * 2)) + ((dWidth / m_nCount) * nIndex);*/dWidth / 2;
			dCY = /*(dHeight / 2);*/ (dHeight / (m_nCount * 2)) + ((dHeight / m_nCount) * nIndex);
			dW = /*(dWidth / m_nCount);*/ dWidth;
			dH = /*dHeight;*/ (dHeight / m_nCount);

			rectaRegion.SetRect_CenterWH(dCX, dCY, dW, dH, 0, 0);
			m_InspectAlgorithm.Create();

			m_InspectAlgorithm.Execute_Center(m_imgPolarUnwarp, rectaRegion, m_nMaxResult, m_dThreshold, m_nHalfPixel);

			//m_ImageProcessing->GetOutputPointFromInputPoint(inputImage, AnnularRegion, InputX, InputY, OutputX, OutputY, revolution

			int idxResult = 0;
			double dLX = 0, dLY = 0, dLS = 0;
			//double dDist;
			double X[4], Y[4];
			double hW, hH;
			hH = dH / 2;
			isFirst = true;
			while ( m_InspectAlgorithm.GetResult(idxResult, dX, dY, dScore) ) {
				if (AddResult(dX, dY, dScore, dX, dY, dScore, isFirst)) {
					if (m_dMinSize <= dScore && dScore <= m_dMaxSize) {
						++nCount;
						strScore.Format(_T("%d"), (int)dScore);
						hW = dScore / 2;
						m_ImageProcessing->GetInputPointFromOutputPoint(__imgSource, CComQIPtr<ICogRegion>(m_ImageProcessing.m_Region), dX - hW, dY - hH, &(X[0]), &(Y[0]));
						m_ImageProcessing->GetInputPointFromOutputPoint(__imgSource, CComQIPtr<ICogRegion>(m_ImageProcessing.m_Region), dX - hW, dY + hH, &(X[1]), &(Y[1]));
						m_ImageProcessing->GetInputPointFromOutputPoint(__imgSource, CComQIPtr<ICogRegion>(m_ImageProcessing.m_Region), dX + hW, dY + hH, &(X[2]), &(Y[2]));
						m_ImageProcessing->GetInputPointFromOutputPoint(__imgSource, CComQIPtr<ICogRegion>(m_ImageProcessing.m_Region), dX + hW, dY - hH, &(X[3]), &(Y[3]));

						CMNVRectangleAffine rect;
						CMNVPolygon Polygon;
						HRESULT P1 = Polygon->AddVertex(X[0], Y[0], 0);
						HRESULT P2 = Polygon->AddVertex(X[1], Y[1], 1);
						HRESULT P3 = Polygon->AddVertex(X[2], Y[2], 2);
						HRESULT P4 = Polygon->AddVertex(X[3], Y[3], 3);
						bool R = __sgcResult.AddGraphic(Polygon, 1, cogColorYellow);

						m_ImageProcessing->GetInputPointFromOutputPoint(__imgSource, CComQIPtr<ICogRegion>(m_ImageProcessing.m_Region), dX, dY, &dX, &dY);
						__sgcResult.AddPoint(dX, dY, 0, 1, (int)dScore, cogColorRed);

						__sgcResult.AddLabel(dX, dY, 0.8, 1, strScore, cogColorRed, cogColorNone, cogGraphicLabelAlignmentTopCenter);
					}
				}
				else {
				}
				//if (dLS > 0) {
				//	if (dScore < 0) {
				//		dDist = abs(dX - dLX);
				//		dX = (dX + dLX) / 2;
				//		dY = (dY + dLY) / 2;
				//		else {
				//			//strScore.Format(_T("%d"), (int)dDist);
				//			//m_ImageProcessing->GetInputPointFromOutputPoint(__imgSource, CComQIPtr<ICogRegion>(m_ImageProcessing.m_Region), dX, dY, &dX, &dY);
				//			//__sgcResult.AddPoint(dX, dY, 0, 1, stInterval.GetY() / 2, cogColorYellow);
				//			//__sgcResult.AddLabel(dX, dY, 0.5, 1, strScore, cogColorGreen, cogColorNone, cogGraphicLabelAlignmentTopCenter);
				//		}
				//		dLX = 0;
				//		dLY = 0;
				//		dLS = 0;
				//	}
				//	else if (dScore > 0) {
				//		dLX = dX;
				//		dLY = dY;
				//		dLS = dScore;
				//	}
				//	else {
				//	}
				//}
				//else if(dLS < 0) {
				//	if (dScore > 0) {
				//		dDist = abs(dX - dLX);
				//		dX = (dX + dLX) / 2;
				//		dY = (dY + dLY) / 2;
				//		if (m_dMinSize <= dDist && dDist <= m_dMaxSize) {
				//			++nCount;
				//			strScore.Format(_T("%d"), (int)dDist);
				//			m_ImageProcessing->GetInputPointFromOutputPoint(__imgSource, CComQIPtr<ICogRegion>(m_ImageProcessing.m_Region), dX, dY, &dX, &dY);
				//			__sgcResult.AddPoint(dX, dY, 0, 1, stInterval.GetY() / 2, cogColorRed);
				//			__sgcResult.AddLabel(dX, dY, 0.5, 1, strScore, cogColorRed, cogColorNone, cogGraphicLabelAlignmentTopCenter);
				//		}
				//		else {
				//			//strScore.Format(_T("%d"), (int)dDist);
				//			//m_ImageProcessing->GetInputPointFromOutputPoint(__imgSource, CComQIPtr<ICogRegion>(m_ImageProcessing.m_Region), dX, dY, &dX, &dY);
				//			//__sgcResult.AddPoint(dX, dY, 0, 1, stInterval.GetY() / 2, cogColorYellow);
				//			//__sgcResult.AddLabel(dX, dY, 0.5, 1, strScore, cogColorGreen, cogColorNone, cogGraphicLabelAlignmentTopCenter);
				//		}
				//		dLX = 0;
				//		dLY = 0;
				//		dLS = 0;
				//	}
				//	else if (dScore < 0) {
				//		dLX = dX;
				//		dLY = dY;
				//		dLS = dScore;
				//	}
				//	else {
				//	}
				//}
				//else {
				//	dLX = dX;
				//	dLY = dY;
				//	dLS = dScore;
				isFirst = false;
				++idxResult;
			}
			stCenter.m_dY += stInterval.GetY();
		}
		return nCount == 0;
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

class MNVIP_TwoImageMinMax : public CComPtr<ICogIPTwoImageMinMax> {
public:
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogIPTwoImageMinMax>::Release();
	}
	bool Create() { Release(); return SUCCEEDED(CoCreateInstance(CLSID_CogIPTwoImageMinMax)); }

	MNVIP_TwoImageMinMax() : CComPtr<ICogIPTwoImageMinMax>() { Create(); }
	~MNVIP_TwoImageMinMax() { Release(); }
public:
	bool Excute(CMNVImage & __ImageA, CMNVImage & __ImageB, CMNVImage & __ImageOut, bool __isAlign, double __dAlignX, double __dAlignY) {
		HRESULT Result = 0;
		if (__isAlign) {
			Result = p->put_ImageAlignmentEnabled(VARIANT_TRUE);
			Result = p->put_ImageBAlignmentX(__dAlignX);
			Result = p->put_ImageBAlignmentY(__dAlignY);
		}
		else {
			Result = p->put_ImageAlignmentEnabled(VARIANT_FALSE);
		}
		//p->put_ImageAAlignmentX(double pVal);
		//p->put_ImageAAlignmentY(double pVal);
		//p->put_MergedSpaceTreeName(BSTR pVal);
		//Result = p->put_Operation(CogIPTwoImageMinMaxOperationConstants::cogIPTwoImageMinMaxOperationMin);
		//Result = p->put_OutputImageFormat(CogIPTwoImageMinMaxFormatConstants::cogIPTwoImageMinMaxFormatDeepestOfInputImages);
		//Result = p->put_RegionModeA(CogRegionModeConstants::cogRegionModeAffineTransform);
		//Result = p->put_RegionModeB(CogRegionModeConstants::cogRegionModeAffineTransform);
		//Result = p->put_SpaceTreeMode(CogIPTwoImageSpaceTreeModeConstants::cogIPTwoImageSpaceTreeModeCopyA);
		CMNVRectangleAffine RegionA;
		RegionA.SetRect_OriginWH(0, 0, __ImageA.GetWidth(), __ImageA.GetHeight(), 0, 0);

		CMNVRectangleAffine RegionB;
		RegionB.SetRect_OriginWH(0, 0, __ImageB.GetWidth(), __ImageB.GetHeight(), 0, 0);
		__ImageOut.Release();
		Result = p->Execute(__ImageA, __ImageB, CComQIPtr<ICogRegion>(RegionA), CComQIPtr<ICogRegion>(RegionB), &__ImageOut);
		 //0x8004e103   -2147163901
		
		return true;
	}
};

class MNVIP_TwoImageAdd : public CComPtr<ICogIPTwoImageAdd> {
public:
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogIPTwoImageAdd>::Release();
	}
	bool Create() { Release(); return SUCCEEDED(CoCreateInstance(CLSID_CogIPTwoImageAdd)); }

	MNVIP_TwoImageAdd() : CComPtr<ICogIPTwoImageAdd>() { Create(); }
	~MNVIP_TwoImageAdd() { Release(); }
public:
	bool Excute(CMNVImage & __ImageA, CMNVImage & __ImageB, CMNVImage & __ImageOut, CogIPTwoImageAddOverflowModeConstants __mdOverflow = cogIPTwoImageAddOverflowModeShift) {
		// 설정 : 오버플로 모드
		//CogIPTwoImageAddOverflowModeConstants::cogIPTwoImageAddOverflowModeBounded = 0; // 바운드됨
		//CogIPTwoImageAddOverflowModeConstants::cogIPTwoImageAddOverflowModeWrap = 1; // 랩
		//CogIPTwoImageAddOverflowModeConstants::cogIPTwoImageAddOverflowModeShift = 2; // 시프트
		p->put_OverflowMode(__mdOverflow);

		// 영역
		//CogRegionModeConstants::cogRegionModePixelAlignedBoundingBoxAdjustMask = 0; // Vision Pro 확인결과 사용않함
		//CogRegionModeConstants::cogRegionModePixelAlignedBoundingBox = 1; // 경계상자 : 기본사용
		//CogRegionModeConstants::cogRegionModeAffineTransform = 2; // 아핀변환
		p->put_RegionModeA(cogRegionModePixelAlignedBoundingBox);
		p->put_RegionModeB(cogRegionModePixelAlignedBoundingBox);
		p->put_ImageAlignmentEnabled(VARIANT_FALSE);

		p->Execute(__ImageA, __ImageB, NULL, NULL, &__ImageOut); // 전체 이미지의 경우 Region NULL

		// 얼라인먼트
		//p->put_ImageAAlignmentX(double pVal);
		//p->put_ImageAAlignmentY(double pVal);
		//p->put_ImageBAlignmentX(double pVal);
		//p->put_ImageBAlignmentY(double pVal);

		// 그래픽
		//p->put_MergedSpaceTreeName(BSTR pval);
		//p->put_OutputImageFormat(CogIPTwoImageAddFormatConstants:: pVal);
		//p->put_SpaceTreeMode(CogIPTwoImageSpaceTreeModeConstants:: pVal);

		return true;
	}
};
