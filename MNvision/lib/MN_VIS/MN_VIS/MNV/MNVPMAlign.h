#pragma once
#include "MNVGraphicsCollection.h"

class CCogImageProc {
public:
	//static HRESULT MakeCrossImage( int nSize, int nWidth, int nGap, ICogImage8Grey **pImage, int nBackGray, int nForGray, double *dCenterX, double *dCenterY )
	//{
	//	//AFX_MANAGE_STATE(AfxGetAppModuleState());
	//	//HRESULT hr;
	//	//hr = CoInitialize(NULL);
	//	//if (FAILED(hr))
	//	//{
	//	//	return hr;
	//	//}
	//	//hr = ::CoCreateInstance(CLSID_CogImage8Grey, NULL, CLSCTX_ALL, __uuidof(ICogImage8Grey), (void**)pImage);
	//	//if (FAILED(hr))
	//	//	return hr;

	//	//int nExtend = nSize / 10;//30;
	//	//// 	if (nExtend < 30)
	//	//// 		nExtend = 30;
	//	//hr = (*pImage)->Allocate(nSize + nExtend * 2, nSize + nExtend * 2);
	//	//if (FAILED(hr))
	//	//	return hr;

	//	//CComPtr<ICogImage8Grey> pImg;
	//	//CComPtr<ICogCopyRegion> pCopyRegion;
	//	//pCopyRegion.CoCreateInstance(CLSID_CogCopyRegion);
	//	//pCopyRegion->put_RegionMode(cogRegionModePixelAlignedBoundingBoxAdjustMask);
	//	//pCopyRegion->put_FillBoundingBox(VARIANT_FALSE);
	//	//pCopyRegion->put_FillRegion(VARIANT_TRUE);
	//	//pCopyRegion->put_FillRegionValue(nBackGray);
	//	//hr = pCopyRegion->Execute(CComQIPtr<ICogImage>(*pImage), NULL,
	//	//	CComQIPtr<ICogImage>(*pImage), NULL, NULL, NULL, &CComQIPtr<ICogImage>(pImg));
	//	//if (FAILED(hr))
	//	//	return hr;


	//	//CComPtr<ICogPolygon> pPolygon;
	//	//pPolygon.CoCreateInstance(CLSID_CogPolygon);

	//	//pPolygon->put_NumVertices(12);
	//	//pPolygon->SetVertex(0, nExtend + (nSize - nWidth) / 2., nExtend);
	//	//pPolygon->SetVertex(1, nExtend + (nSize + nWidth) / 2., nExtend);
	//	//pPolygon->SetVertex(2, nExtend + (nSize + nWidth) / 2., nExtend + (nSize - nWidth) / 2.);
	//	//pPolygon->SetVertex(3, nExtend + nSize, nExtend + (nSize - nWidth) / 2.);
	//	//pPolygon->SetVertex(4, nExtend + nSize, nExtend + (nSize + nWidth) / 2.);
	//	//pPolygon->SetVertex(5, nExtend + (nSize + nWidth) / 2., nExtend + (nSize + nWidth) / 2.);
	//	//pPolygon->SetVertex(6, nExtend + (nSize + nWidth) / 2., nExtend + nSize);
	//	//pPolygon->SetVertex(7, nExtend + (nSize - nWidth) / 2., nExtend + nSize);
	//	//pPolygon->SetVertex(8, nExtend + (nSize - nWidth) / 2., nExtend + (nSize + nWidth) / 2.);
	//	//pPolygon->SetVertex(9, nExtend, nExtend + (nSize + nWidth) / 2.);
	//	//pPolygon->SetVertex(10, nExtend, nExtend + (nSize - nWidth) / 2.);
	//	//pPolygon->SetVertex(11, nExtend + (nSize - nWidth) / 2., nExtend + (nSize - nWidth) / 2.);

	//	//pCopyRegion->put_ImageAlignmentEnabled(VARIANT_TRUE);
	//	//pCopyRegion->put_FillRegionValue(nForGray);
	//	//hr = pCopyRegion->Execute(CComQIPtr<ICogImage>(*pImage), CComQIPtr<ICogRegion>(pPolygon),
	//	//	CComQIPtr<ICogImage>(*pImage), NULL, NULL, NULL, &CComQIPtr<ICogImage>(pImg));
	//	//if (FAILED(hr))
	//	//	return hr;

	//	//if (nGap > 0 && nGap < nWidth / 2)
	//	//{
	//	//	pPolygon->put_NumVertices(12);
	//	//	pPolygon->SetVertex(0, nExtend + (nSize - nWidth) / 2. + nGap, nExtend + nGap);
	//	//	pPolygon->SetVertex(1, nExtend + (nSize + nWidth) / 2. - nGap, nExtend + nGap);
	//	//	pPolygon->SetVertex(2, nExtend + (nSize + nWidth) / 2. - nGap, nExtend + (nSize - nWidth) / 2. + nGap);
	//	//	pPolygon->SetVertex(3, nExtend + nSize - nGap, nExtend + (nSize - nWidth) / 2. + nGap);
	//	//	pPolygon->SetVertex(4, nExtend + nSize - nGap, nExtend + (nSize + nWidth) / 2. - nGap);
	//	//	pPolygon->SetVertex(5, nExtend + (nSize + nWidth) / 2. - nGap, nExtend + (nSize + nWidth) / 2. - nGap);
	//	//	pPolygon->SetVertex(6, nExtend + (nSize + nWidth) / 2. - nGap, nExtend + nSize - nGap);
	//	//	pPolygon->SetVertex(7, nExtend + (nSize - nWidth) / 2. + nGap, nExtend + nSize - nGap);
	//	//	pPolygon->SetVertex(8, nExtend + (nSize - nWidth) / 2. + nGap, nExtend + (nSize + nWidth) / 2. - nGap);
	//	//	pPolygon->SetVertex(9, nExtend + nGap, nExtend + (nSize + nWidth) / 2. - nGap);
	//	//	pPolygon->SetVertex(10, nExtend + nGap, nExtend + (nSize - nWidth) / 2. + nGap);
	//	//	pPolygon->SetVertex(11, nExtend + (nSize - nWidth) / 2. + nGap, nExtend + (nSize - nWidth) / 2. + nGap);

	//	//	pCopyRegion->put_ImageAlignmentEnabled(VARIANT_TRUE);
	//	//	pCopyRegion->put_FillRegionValue(nBackGray);
	//	//	hr = pCopyRegion->Execute(CComQIPtr<ICogImage>(*pImage), CComQIPtr<ICogRegion>(pPolygon),
	//	//		CComQIPtr<ICogImage>(*pImage), NULL, NULL, NULL, &CComQIPtr<ICogImage>(pImg));
	//	//	if (FAILED(hr))
	//	//		return hr;
	//	//}

	//	//*dCenterX = nExtend + nSize / 2.;
	//	//*dCenterY = nExtend + nSize / 2.;

	//	//CoUninitialize();

	//	return hr;
	//}
	//static HRESULT MakeCircleImage( int nSize, int nWidth, ICogImage8Grey **pImage, int nBackGray, int nForGray, double *dCenterX, double *dCenterY )
	//{
	//	AFX_MANAGE_STATE(AfxGetAppModuleState());

	//	HRESULT hr;
	//	hr = CoInitialize(NULL);
	//	if (FAILED(hr))
	//	{
	//		return hr;
	//	}

	//	hr = ::CoCreateInstance(CLSID_CogImage8Grey, NULL, CLSCTX_ALL, __uuidof(ICogImage8Grey), (void**)pImage);
	//	if (FAILED(hr))
	//		return hr;

	//	int nExtend = nSize / 10;//30;
	//	// 	if (nExtend < 30)
	//	// 		nExtend = 30;
	//	hr = (*pImage)->Allocate(nSize + nExtend * 2, nSize + nExtend * 2);
	//	if (FAILED(hr))
	//		return hr;

	//	long lWidth, lHeight;
	//	(*pImage)->get_Width(&lWidth);
	//	(*pImage)->get_Height(&lHeight);

	//	CComPtr<ICogImage8Grey> pImg;
	//	CComPtr<ICogCopyRegion> pCopyRegion;
	//	pCopyRegion.CoCreateInstance(CLSID_CogCopyRegion);
	//	pCopyRegion->put_RegionMode(cogRegionModePixelAlignedBoundingBoxAdjustMask);
	//	pCopyRegion->put_FillBoundingBox(VARIANT_FALSE);
	//	pCopyRegion->put_FillRegion(VARIANT_TRUE);
	//	pCopyRegion->put_FillRegionValue(nBackGray);
	//	hr = pCopyRegion->Execute(CComQIPtr<ICogImage>(*pImage), NULL,
	//		CComQIPtr<ICogImage>(*pImage), NULL, NULL, NULL, &CComQIPtr<ICogImage>(pImg));
	//	if (FAILED(hr))
	//		return hr;

	//	CComPtr<ICogCircle> pCircle;
	//	pCircle.CoCreateInstance(CLSID_CogCircle);
	//	pCircle->SetCenterRadius(lWidth / 2., lHeight / 2., nSize / 2.);

	//	pCopyRegion->put_ImageAlignmentEnabled(VARIANT_TRUE);
	//	pCopyRegion->put_FillRegionValue(nForGray);
	//	hr = pCopyRegion->Execute(CComQIPtr<ICogImage>(*pImage), CComQIPtr<ICogRegion>(pCircle),
	//		CComQIPtr<ICogImage>(*pImage), NULL, NULL, NULL, &CComQIPtr<ICogImage>(pImg));
	//	if (FAILED(hr))
	//		return hr;

	//	pCircle->SetCenterRadius(lWidth / 2., lHeight / 2., (nSize - nWidth) / 2.);

	//	pCopyRegion->put_ImageAlignmentEnabled(VARIANT_TRUE);
	//	pCopyRegion->put_FillRegionValue(nBackGray);
	//	hr = pCopyRegion->Execute(CComQIPtr<ICogImage>(*pImage), CComQIPtr<ICogRegion>(pCircle),
	//		CComQIPtr<ICogImage>(*pImage), NULL, NULL, NULL, &CComQIPtr<ICogImage>(pImg));
	//	if (FAILED(hr))
	//		return hr;

	//	*dCenterX = nExtend + nSize / 2.;
	//	*dCenterY = nExtend + nSize / 2.;

	//	CoUninitialize();

	//	return hr;
	//}
};

class CMNVPMAlignZoneAngle : public CComPtr<ICogPMAlignZoneAngle> {
public:
	bool Create() { 
		Release();
		return SUCCEEDED( CoCreateInstance(CLSID_CogPMAlignZoneAngle) );
	}
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogPMAlignZoneAngle>::Release();
	}
public:
	CMNVPMAlignZoneAngle(bool __isCreate = true) : CComPtr<ICogPMAlignZoneAngle>() { if(__isCreate) Create(); }
	~CMNVPMAlignZoneAngle() { Release(); }
};
class CMNVPMAlignZoneScale : public CComPtr<ICogPMAlignZoneScale> {
public:
	bool Create() { 
		Release();
		return SUCCEEDED( CoCreateInstance(CLSID_CogPMAlignZoneScale) );
	}
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogPMAlignZoneScale>::Release();
	}
public:
	CMNVPMAlignZoneScale(bool __isCreate = true) : CComPtr<ICogPMAlignZoneScale>() { if(__isCreate) Create(); }
	~CMNVPMAlignZoneScale() { Release(); }
};

struct ST_APPLY {
	bool	m_isUsed;
	double	m_dMin;
	double	m_dMax;
	void Set(bool __isUsed, double __dMin, double __dMax) {
		m_isUsed = __isUsed;
		m_dMin = __dMin;
		m_dMax = __dMax;
	}
	void SetEnable(double __dMin, double __dMax) {
		m_isUsed = true;
		m_dMin = __dMin;
		m_dMax = __dMax;
	}
	void SetDisable() {
		m_isUsed = false;
		m_dMin = 0;
		m_dMax = 0;
	}
};

class CMNVPMAlignResults : public CComPtr<ICogPMAlignResults> {
public:
	bool Create() { 
		Release();
		return SUCCEEDED( CoCreateInstance(CLSID_CogPMAlignResults) );
	}
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogPMAlignResults>::Release();
	}
public:
	CMNVPMAlignResults(bool __isCreate = true) : CComPtr<ICogPMAlignResults>() { if(__isCreate) Create(); }
	~CMNVPMAlignResults() { Release(); }
};
class CMNVPMAlignResult : public CComPtr<ICogPMAlignResult> {
public:
	bool Create() {
		Release();
		return SUCCEEDED( CoCreateInstance(CLSID_CogPMAlignResult) );
	}
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogPMAlignResult>::Release();
	}
public:
	CMNVPMAlignResult(bool __isCreate = true) : CComPtr<ICogPMAlignResult>() { if(__isCreate) Create(); }
	~CMNVPMAlignResult() { Release(); }
};

class CMNVTransform2DLinear : public CComPtr<ICogTransform2DLinear>{
public:
	bool Create() { 
		Release();
		return SUCCEEDED( CoCreateInstance(CLSID_CogTransform2DLinear) );
	}
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogTransform2DLinear>::Release();
	}
public:
	CMNVTransform2DLinear(bool __isCreate = true) : CComPtr<ICogTransform2DLinear>() {
		if (__isCreate) Create();
	}
	~CMNVTransform2DLinear() { Release(); }
};

class CMNVPMAlignRunParams : public CComPtr<ICogPMAlignRunParams> {
public:
	bool Create() { 
		Release();
		return SUCCEEDED( CoCreateInstance(CLSID_CogPMAlignRunParams) );
	}
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogPMAlignRunParams>::Release();
	}
public:
	CMNVPMAlignRunParams(bool __isCreate = true) : CComPtr<ICogPMAlignRunParams>() { if(__isCreate) Create(); }
	~CMNVPMAlignRunParams() { Release(); }
public:
	bool SetParams(VARIANT_BOOL __bSaveMatchInfo, VARIANT_BOOL _bScoreUsingClutter, long __nApproximateNumberToFind, double __dAcceptThreshold) {
		Release();
		if ( !Create() ) return false;
		if (FAILED( p->put_SaveMatchInfo(__bSaveMatchInfo) )) return false;
		if (FAILED( p->put_ScoreUsingClutter(_bScoreUsingClutter) )) return false;
		if (FAILED( p->put_ApproximateNumberToFind(__nApproximateNumberToFind) )) return false;
		if (FAILED( p->put_AcceptThreshold(__dAcceptThreshold) )) return false;
		return true;
	}
	bool SetAngle(double __dAngleMin, double __dAngleMax) {
		CComPtr<ICogPMAlignZoneAngle> _Angle;
		if (FAILED( p->get_ZoneAngle(& _Angle) )) return false;
		if (FAILED( _Angle->put_Configuration(cogPMAlignZoneLowHigh) )) return false;
		if (FAILED( _Angle->put_High(__dAngleMax) )) return false;
		if (FAILED( _Angle->put_Low(__dAngleMin) )) return false;
		return true;
	}
	bool SetAngle() {
		CMNVPMAlignZoneAngle cogPMAlignAngle(false);
		if (FAILED( p->get_ZoneAngle(& cogPMAlignAngle) )) return false;
		if (FAILED( cogPMAlignAngle->put_Configuration(cogPMAlignZoneNominal) )) return false;
		if (FAILED( p->putref_ZoneAngle(cogPMAlignAngle) )) return false;
		return true;
	}
	bool SetAngle(ST_APPLY & __stAngle) {
		if (__stAngle.m_isUsed) 
			return SetAngle(__stAngle.m_dMin * PI / 180, __stAngle.m_dMax * PI / 180);
		else SetAngle();
	}

	bool SetScale() {
		CMNVPMAlignZoneScale cogPMAlignScale(false);
		if (FAILED( p->get_ZoneScale(& cogPMAlignScale) )) return false;
		if (FAILED( cogPMAlignScale->put_Configuration(cogPMAlignZoneNominal) )) return false;
		if (FAILED( p->putref_ZoneScale(cogPMAlignScale) )) return false;
		return true;
	}
	bool SetScale(double __dScaleMin, double __dScaleMax) {
		CMNVPMAlignZoneScale cogPMAlignScale(false);
		if (FAILED( p->get_ZoneScale(& cogPMAlignScale) )) return false;
		if (FAILED( cogPMAlignScale->put_Configuration(cogPMAlignZoneLowHigh) )) return false;
		if (FAILED( cogPMAlignScale->put_High(__dScaleMax) )) return false;
		if (FAILED( cogPMAlignScale->put_Low(__dScaleMin) )) return false;
		if (FAILED( cogPMAlignScale->put_Configuration(cogPMAlignZoneNominal) )) return false;
		if (FAILED( p->putref_ZoneScale(cogPMAlignScale) )) return false;
		return true;
	}
	bool SetScale(ST_APPLY & __stScale) {
		if (__stScale.m_isUsed) return SetScale(__stScale.m_dMin, __stScale.m_dMax);
		else return SetScale();
	}
};

class CMNVPMAlignPattern : public CComPtr<ICogPMAlignPattern> {
	CMNVPMAlignResults m_Results;
	bool m_bFinded;
	double m_dX;
	double m_dY;
	double m_dT;
	double m_dScore;
public:
	CMNVPMAlignRunParams m_Params;
	bool GetFinded() { return m_bFinded; }
	double GetScore() { return m_dScore; }
	double GetAlignX() { return m_dX; }
	double GetAlignY() { return m_dY; }
	double GetAlignT() { return m_dT; }
	
	void Release() {
		if(p != NULL) Detach()->Release();
		CComPtr<ICogPMAlignPattern>::Release();
	}
	bool Create() { Release(); return SUCCEEDED( CoCreateInstance(CLSID_CogPMAlignPattern) ); }
public:
	CMNVPMAlignPattern(bool __isCreate = true) : CComPtr<ICogPMAlignPattern>() { if (__isCreate) Create(); }
	~CMNVPMAlignPattern() { Release(); }
	bool SetOrigin(double __dOriginX, double __dOriginY) {
		CMNVTransform2DLinear _Transform2DLiner(false);
		if (FAILED( p->get_Origin(&_Transform2DLiner) )) return false;
		if (FAILED( _Transform2DLiner->put_TranslationX(__dOriginX) )) return false;
		if (FAILED( _Transform2DLiner->put_TranslationY(__dOriginY) )) return false;
		if (FAILED( p->putref_Origin(_Transform2DLiner) )) return false;
		return true;
	}

	bool Train(ICogImage8Grey * __imgPattern, ICogImage8Grey * __imgMask, double __dAcceptThreshold, double __dOriginX, double __dOriginY, double __dAngleMin, double __dAngleMax, double __dScaleMin, double __dScaleMax) {
		if (!m_Params.SetParams(VARIANT_TRUE, VARIANT_FALSE, 1, __dAcceptThreshold)) {
			AfxMessageBox(_T("Error! : Set Threshold"));
			return false;
		}
		if (__dAngleMin == 0 && __dAngleMax == 0) {
			if (!m_Params.SetAngle()) {
				AfxMessageBox(_T("Error! : Set Angle()"));
				return false;
			}
		}
		else {
			if (!m_Params.SetAngle(__dAngleMin, __dAngleMax)) {
				AfxMessageBox(_T("Error! : Set Angle(Min, Max)"));
				return false;
			}
		}
		if (__dScaleMin == 0 && __dScaleMax == 0) {
			if (!m_Params.SetScale()) {
				AfxMessageBox(_T("Error! : Set Scale()"));
				return false;
			}
		}
		else {
			if (!m_Params.SetScale(__dScaleMin, __dScaleMax)) {
				AfxMessageBox(_T("Error! : Set Scale(Min, Max)"));
				return false;
			}
		}
		if (!SetOrigin(__dOriginX, __dOriginY)) {
			AfxMessageBox(_T("Error! : Set Origin"));
			return false;
		}

		if (FAILED( p->putref_TrainImage(__imgPattern) )) {
			AfxMessageBox(_T("Error! : Set Pattern Image"));
			return false;
		}
		if (FAILED( p->putref_TrainImageMask(__imgMask) )) {
			AfxMessageBox(_T("Error! : Set Mask Image"));
			return false;
		}
		if (FAILED( p->putref_TrainRegion(NULL) )) {
			AfxMessageBox(_T("Error! : Set Region"));
			return false;
		}
		if (FAILED( p->put_TrainAlgorithm(cogPMAlignTrainAlgorithmPatMax) )) {
			AfxMessageBox(_T("Error! : Set Algorithm"));
			return false;
		}
		//if (FAILED( p->put_TrainAlgorithm(cogPMAlignTrainAlgorithmPatQuick) )) return false;

		if (FAILED( p->put_IgnorePolarity(VARIANT_TRUE) )) {
			AfxMessageBox(_T("Error! : Set Polarity"));
			return false; /* VARIANT_FALSE */
		}
		HRESULT hResult;
		if (FAILED( hResult = p->Train() )) {
			CString strTemp;
			strTemp.Format(_T("Error! : Set Train [%d : %x]"), hResult);
			AfxMessageBox(strTemp);
			return false;
		}
		//AfxMessageBox(_T("Train OK"));
		return true;
	}

	bool IsTrained() {
		if (p != NULL) {
			VARIANT_BOOL bTrained;
			if (FAILED( p->get_Trained(&bTrained) )) return false;
			return bTrained == VARIANT_TRUE;
		}
		return false;
	}
	bool Execute(ICogImage8Grey * __imgSource, ICogRegion * __pRegion, CMNVStaticGraphicCollection & __pGraphicCollection) {
		if (IsTrained()) {
			m_Results.Release();
			bool isSuccess = SUCCEEDED( p->Execute(__imgSource, __pRegion, m_Params, &m_Results) );
			if(isSuccess) {
				long Count;
				m_Results->get_Count(&Count);

				CMNVPMAlignResult pPMResult(false);
				if (Count > 0) {
					m_Results->get_Item(0, &pPMResult);
					CogPMAlignResultGraphicConstants pmgc = 
						(CogPMAlignResultGraphicConstants)(cogPMAlignResultGraphicMatchRegion | cogPMAlignResultGraphicOrigin);
					pmgc = (CogPMAlignResultGraphicConstants)(pmgc | cogPMAlignResultGraphicMatchFeatures);
					CComPtr<ICogCompositeShape> pCompositeShape;
					pPMResult->CreateResultGraphics(pmgc, &pCompositeShape);
					__pGraphicCollection.Create();
					__pGraphicCollection->Add(CComQIPtr<ICogGraphic>(pCompositeShape), -1);
					__pGraphicCollection.AddLabel(0, 0, 10,100,_T("OK"), cogColorGreen, cogColorNone, cogGraphicLabelAlignmentTopLeft);
					return true;
				}
				else {
					__pGraphicCollection.Create();
					__pGraphicCollection.AddLabel(0, 0, 10,100,_T("NG"), cogColorRed, cogColorNone, cogGraphicLabelAlignmentTopLeft);
					return false;
				}
			}
		}
		return false;
	}

	//bool Excute(CMNVImage8Grey __imgSource
	//	, CMNVGraphicCollection __pGraphicCollection, ST_PMAResult& __OutResult, TPCoordinate2D & __TPOffset)
	//{
	//	CMNVPMAlignPattern cogPMAlignPattern;
	//	CMNVPMAlignRunParams cogPMAlignRunParam;
	//
	//	CMNVPMAlignZoneAngle cogPMAlignZoneAngle(false);
	//	CMNVPMAlignZoneScale cogPMAlignZoneScale(false);

	//	cogPMAlignRunParam.Create();
	//	cogPMAlignRunParam.SetAngle(m_stAngle);
	//	cogPMAlignRunParam.SetScale(m_stScale);
	//	cogPMAlignRunParam->put_SaveMatchInfo(VARIANT_TRUE);
	//	cogPMAlignRunParam->put_ScoreUsingClutter(VARIANT_FALSE);
	//	cogPMAlignRunParam->put_ApproximateNumberToFind(1);
	//	cogPMAlignRunParam->put_ContrastThreshold(m_dContrastThreshold);
	//	cogPMAlignRunParam->put_AcceptThreshold(m_dAcceptTheshold);
	//	cogPMAlignRunParam->put_RunAlgorithm(cogPMAlignRunAlgorithmPatMax);
	//	CMNVTransform2DLinear cogTransferm2DLinear(false);

	//	cogPMAlignPattern->get_Origin(&cogTransferm2DLinear);
	//	cogTransferm2DLinear->put_TranslationX(m_Point_Origin.GetX() - m_Rect_Pattern.GetX());
	//	cogTransferm2DLinear->put_TranslationY(m_Point_Origin.GetY() - m_Rect_Pattern.GetY());
	//	cogPMAlignPattern->putref_Origin(cogTransferm2DLinear);
	//	cogPMAlignPattern->putref_TrainRegion(NULL);
	//	cogPMAlignPattern->putref_TrainImage(m_imgPattern);
	//	cogPMAlignPattern->putref_TrainImageMask(m_imgMask);
	//	cogPMAlignPattern->put_TrainAlgorithm(cogPMAlignTrainAlgorithmPatMax);
	//	cogPMAlignPattern->put_IgnorePolarity(m_nPolarity == 2 ? VARIANT_TRUE : VARIANT_FALSE);

	//	cogPMAlignPattern->Train();
	//	Sleep(100);
	//	VARIANT_BOOL bTrained;
	//	HRESULT hr = cogPMAlignPattern->get_Trained(&bTrained);
	//	if (FAILED(hr) || bTrained == VARIANT_FALSE) {
	//		__OutResult.SetResult(RESULT_MARK::MARK_PATTERN, 0, 0, 0, 0, 0);
	//		return false;
	//	}
	//	CMNVPMAlignResult pPMResult(false);
	//	CMNVPMAlignResults pPMResults(false);
	//	long nCount = -1;

	//	CMNVRectangleAffine m_RectA(m_RectA_Region, __TPOffset);

	//	CogPMAlignResultGraphicConstants pmgc = (CogPMAlignResultGraphicConstants)(cogPMAlignResultGraphicMatchRegion | cogPMAlignResultGraphicOrigin);
	//	pmgc = (CogPMAlignResultGraphicConstants)(pmgc | cogPMAlignResultGraphicMatchFeatures);
	//	if (SUCCEEDED( cogPMAlignPattern->Execute(__imgSource, CMNVRegion(m_RectA), cogPMAlignRunParam, &pPMResults) )) {
	//		pPMResults->get_Count(&nCount);
	//		if (nCount > 0)
	//		{
	//			hr = pPMResults->get_Item(0, &pPMResult);
	//			if (SUCCEEDED(hr))
	//			{
	//				VARIANT_BOOL bRet = VARIANT_FALSE;
	//				pPMResult->get_Accepted(&bRet);
	//				if (bRet == VARIANT_TRUE)
	//				{
	//					CMNVTransform2DLinear cogTransform2DLinear(false);
	//					pPMResult->GetPose(&cogTransform2DLinear);

	//					//m_pTransform2DLinear->
	//					cogTransform2DLinear->get_TranslationX(& __OutResult.dCX);
	//					cogTransform2DLinear->get_TranslationY(& __OutResult.dCY);
	//					cogTransform2DLinear->get_Rotation(& __OutResult.dAngle);
	//					cogTransform2DLinear->get_Scaling(& __OutResult.dScale);
	//					pPMResult->get_Score(& __OutResult.dScore);

	//					//__Result.SetFind(TPCoordinate2D(dX, dY), dT, dScore, dScale);
	//					if (__pGraphicCollection)
	//					{
	//						CComPtr<ICogCompositeShape> pCompositeShape;
	//						pPMResult->CreateResultGraphics(pmgc, &pCompositeShape);

	//						__pGraphicCollection->Add(CComQIPtr<ICogGraphic>(pCompositeShape), -1);
	//						//__pGraphicCollection.AddLine(1, cogColorYellow, dX, dY, 0);
	//						//__pGraphicCollection.AddLine(1, cogColorYellow, dX, dY, PI / 2);
	//					}
	//					
	//					__OutResult.cdResult = RESULT_MARK::MARK_OK;
	//					return true;
	//				}
	//			}
	//		}
	//	}
	//	__OutResult.SetResult(RESULT_MARK::MARK_PATTERN, 0, 0, 0, 0, 0);
	//	return false;
	//}
	bool LoadResult(int __nIndex) {
		long nCount;
		m_Results->get_Count(&nCount);
		if (nCount > __nIndex) {
			CMNVPMAlignResult Result;
			Result.Release();
			if (SUCCEEDED( m_Results->get_Item(__nIndex, &Result) )) {
				VARIANT_BOOL bRet = VARIANT_FALSE;
				Result->get_Accepted(&bRet);
				if (bRet == VARIANT_TRUE) {
					CMNVTransform2DLinear Transform2DLinear(false);
					Result->GetPose(&Transform2DLinear);
					Transform2DLinear->get_TranslationX(& m_dX);
					Transform2DLinear->get_TranslationY(& m_dY);
					Transform2DLinear->get_Rotation(& m_dT);
					m_dT *= 180 / PI;

					Result->get_Score(& m_dScore);
					m_bFinded= true;
					//CoUninitialize();
					return true;
				}
			}
		}
		return false;
	}
};
//
//enum MNV_PMAlign_State { MNVPMAS_NONE = 0, MNVPMAS_PROCESS = 1, MNVPMAS_FINDED = 2, MNVPMAS_NOTFIND = 3 };
//
//struct TPResultMark{
//public:
//	MNV_PMAlign_State m_Status;
//	TPCoordinate2D m_Mark;
//	TPCoordinate2D m_Size;
//	TPCoordinate2D m_Origin;
//	TPCoordinate2D m_Resolution;
//	double m_ResolutionT;
//
//	TPCoordinate2D m_Find;
//	TPCoordinate2D m_Align;
//	TPCoordinate2D m_Result;
//	TPCoordinate2D m_CenterResult;
//	double m_dTheta;
//	double m_dDeg;
//	double m_dScore;	// 검사 결과 : 매칭률
//	double m_dScale;
//public:
//	TPCoordinate2D m_Result2;
//	TPResultMark() {
//		m_Status = MNVPMAS_NONE;
//		m_Mark.Set(0, 0);
//		m_Size.Set(0, 0);
//		m_Origin.Set(0, 0);
//		m_Resolution.Set(0, 0);
//
//		m_Find.Set(0, 0);
//		m_Align.Set(0, 0);
//		m_Result.Set(0, 0);
//		m_Result2.Set(0, 0);
//
//		m_dTheta = 0;
//		m_dDeg = 0;
//		m_dScore = 0;
//		m_dScale = 0;
//	}
//	void InitData() {
//		m_Status = MNVPMAS_NONE;
//		m_Mark.Set(0, 0);
//		m_Size.Set(0, 0);
//		m_Origin.Set(0, 0);
//		m_Resolution.Set(0, 0);
//
//		m_Find.Set(0, 0);
//		m_Align.Set(0, 0);
//		m_Result.Set(0, 0);
//
//		m_dTheta = 0;
//		m_dDeg = 0;
//		m_dScore = 0;
//		m_dScale = 0;
//	}
//	void InitData(const TPCoordinate2D & __Mark, const TPCoordinate2D & __Size, const TPCoordinate2D & __Origin, const TPCoordinate2D & __Resolution, double __ResolutionT) {
//		m_Mark = __Mark;
//		m_Size = __Size;
//		m_Origin = __Origin;
//		m_Resolution = __Resolution;
//		m_ResolutionT = __ResolutionT;
//		m_Find.Set(0, 0);
//		m_Align.Set(0, 0);
//		m_Result.Set(0, 0);
//
//		m_dTheta = 0;
//		m_dDeg = 0;
//		m_dScore = 0;
//		m_dScale = 0;
//	}
//	void SetFind(const TPCoordinate2D & __Coordinate, double __dTheta, double __dScore, double __dScale) {
//		m_Find = __Coordinate;	/// 찾은 패턴의 좌표
//		m_dTheta = __dTheta;	/// 찾은 패턴의 Angle
//		m_Align = m_Find + TPCoordinate2D::Rotation(m_dTheta, m_Origin - m_Mark);	// 등록 패턴의 원전 기준 찾은 패턴의 좌표 추적  (angle오차 있을 수 있음)
//		//TPCoordinate2D::Rotation(-m_ResolutionT, m_Align - m_Origin);
//		m_Result = TPCoordinate2D::Rotation(-m_ResolutionT, m_Align - m_Origin) * m_Resolution;	// Vision 틀어진 정도 적용
//		m_Result2 = (m_Find - TPCoordinate2D(800, 600)) * m_Resolution;	// 찾은 패턴과 이미지 중심과의 거리
//		m_CenterResult = (m_Align - TPCoordinate2D(800, 600)) * m_Resolution;	// 찾은 패턴의 원점과 이미지 중심과의 거리
//		m_dDeg = m_dTheta * 180 / PI;	// 패턴의 회전량
//		m_dScore = __dScore;
//		m_dScale = __dScale;
//	}
//	void SetStatus(MNV_PMAlign_State __Status) { m_Status = __Status; }
//
//	MNV_PMAlign_State GetStatus() { return m_Status; }
//	bool GetFinded() { return MNVPMAS_FINDED == m_Status; }
//	bool GetActive() { return MNVPMAS_PROCESS != m_Status; }
//
//	double GetMarkX() { return m_Mark.dX; }
//	double GetMarkY() { return m_Mark.dY; }
//	TPCoordinate2D GetMark() { return m_Mark; }
//	double GetMarkW() { return m_Size.dX; }
//	double GetMarkH() { return m_Size.dY; }
//	TPCoordinate2D GetSize() { return m_Size; }
//	double GetOriginX() { return m_Origin.dX; }
//	double GetOriginY() { return m_Origin.dY; }
//	TPCoordinate2D GetOrigin() { return m_Origin; }
//	double GetResolutionX() { return m_Resolution.dX; }
//	double GetResolutionY() { return m_Resolution.dY; }
//	TPCoordinate2D GetResolution() { return m_Resolution; }
//
//	double GetFindX() { return m_Find.dX; }
//	double GetFindY() { return m_Find.dY; }
//	TPCoordinate2D GetFind() { return m_Find; }
//	double GetAlignX() { return m_Align.dX; }
//	double GetAlignY() { return m_Align.dY; }
//	TPCoordinate2D GetAlign() { return m_Align; }
//	double GetResultX() { return m_Result.dX; }
//	double GetResultY() { return m_Result.dY; }
//	TPCoordinate2D GetResult() { return m_Result; }
//	double GetTheta() { return m_dTheta; }
//	double GetScore() { return m_dScore; }
//	double GetScale() { return m_dScale; }
//	double GetDeg() { return m_dDeg; }
//
//	double GetCResultX() { return m_CenterResult.dX; }
//	double GetCResultY() { return m_CenterResult.dY; }
//	TPCoordinate2D GetCResult() { return m_CenterResult; }
//	//bool IsMarkOK(double __dAcceptScore) { return /*m_bFinded &&*/ (m_dScore >= __dAcceptScore); }
//	//double GetRadi() { return m_dTheta * PI / 180; }
//	void LogString(CString & __strLog, LPCTSTR __strVisionName, double __dAcceptScore, SYSTEMTIME & __SysTime) {
//		__strLog.AppendFormat(_T("[%04d/%02d/%02d], [%02d:%02d:%02d.%03d], %s, %4.3f, %4.3f, %3.4f, %3.4f, %3.4f, %.3f\r\n")
//			, __SysTime.wYear, __SysTime.wMonth, __SysTime.wDay, __SysTime.wHour, __SysTime.wMinute, __SysTime.wSecond, __SysTime.wMilliseconds
//			, __strVisionName, m_Find.dX, m_Find.dY, m_Result.dX, m_Result.dY, m_dDeg, m_dScore);
//	}
//	//void ResultString(CString & strResult) { strResult.Format(_T("Result : X=%.3f, Y=%.3f, T=%.3f, Score=%.3f") , m_Axis.dX, m_Axis.dY, m_dTheta, m_dScore); }
//};


#define RADIAN(deg) (PI * (deg) / 180)
#define DEGREE(radi) (180 * (radi) / PI)



