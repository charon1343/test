#pragma once
#include "MNVObject.h"
#include "MNVImage.h"
#include "CamInfo.h"
#include "MNVGraphicsCollection.h"

#include "MNVDisplay.h"

class CMNVCaliperScorerPositionNeg_Disp : public CComPtr<ICogCaliperScorerPositionNeg_Disp> {
public:
	void Release() {
		if(p != NULL) Detach()->Release();
		CComPtr<ICogCaliperScorerPositionNeg_Disp>::Release();
	}
	bool Create() { Release(); return SUCCEEDED(CoCreateInstance(CLSID_CogCaliperScorerPositionNeg)); }
public:
	CMNVCaliperScorerPositionNeg_Disp(bool __isCreate = true) { if (__isCreate) Create(); }
	~CMNVCaliperScorerPositionNeg_Disp() { Release(); }

	bool SetXYParameters(double __dX0, double __dX1, double __dXc, double __dY0, double __dY1) {
		if (p == NULL) return false;
		return SUCCEEDED( p->SetXYParameters(__dX0, __dX1, __dXc, __dY0, __dY1) );
	}
};

class CMNVCaliperScorers : public CComPtr<ICogCaliperScorers> {
public:
	void Release() {
		if(p != NULL) Detach()->Release();
		CComPtr<ICogCaliperScorers>::Release();
	}
	bool Create() { Release(); return SUCCEEDED(CoCreateInstance(CLSID_CogCaliperScorers)); }
public:
	CMNVCaliperScorers(bool __isCreate = true) { if (__isCreate) Create(); }
	~CMNVCaliperScorers() { Release(); }

	bool Clear() {
		if (p == NULL) 
			return Create();
		else
			return SUCCEEDED( p->Clear() );
	}
	bool Add(CMNVCaliperScorerPositionNeg_Disp & __Socrer, int nIndex = -1) {
		long nCnt = 0;
		if (p == NULL) return false;
		if (FAILED( p->get_Count(&nCnt) )) return false;
		return SUCCEEDED( p->Add(__Socrer, nCnt) );
	}
};

struct SetFindCaliper {
	long nCalipers;
	double dSearchLength;
	double dProjectionLength;
	double dSearchDirection;

	long nToIgnore;
	BOOL IsToIgnore;
};

class CMNVCaliperParams : public CComPtr<ICogCaliperParams> {
public:
	bool Create() { Release(); return SUCCEEDED( CoCreateInstance(CLSID_CogCaliperParams) ); }
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogCaliperParams>::Release();
	}

	CMNVCaliperParams(bool __isCreate = true) { if (__isCreate) Create(); }
	~CMNVCaliperParams() { Release(); }
public:
	CogCaliperEdgeModeConstants GetEdgeMode() {
		CogCaliperEdgeModeConstants Value = cogCaliperEdgeModeSingle;
		if (SUCCEEDED( p->get_EdgeMode(&Value) )) return Value;
		else return cogCaliperEdgeModeSingle;
	}
	CogCaliperPolarityConstants GetEdge1Porarity() {
		CogCaliperPolarityConstants Value;
		if (SUCCEEDED( p->get_Edge0Polarity(&Value) )) return Value;
		else return cogCaliperPolarityDontCare;
	}
	CogCaliperPolarityConstants GetEdge2Porarity() {
		CogCaliperPolarityConstants Value;
		if (SUCCEEDED( p->get_Edge1Polarity(&Value) )) return Value;
		else return cogCaliperPolarityDontCare;
	}
	double GetEdge1Position() {
		double Value;
		if (SUCCEEDED( p->get_Edge0Position(&Value) )) return Value;
		else return -5;
	}
	double GetEdge2Position() {
		double Value;
		if (SUCCEEDED( p->get_Edge1Position(&Value) )) return Value;
		else return 5;
	}
	double GetEdgeWidth() { return GetEdge2Position() - GetEdge1Position(); }
	int GetHalfPixel() {
		long Value;
		if (SUCCEEDED( p->get_FilterHalfSizeInPixels(&Value) )) return Value;
		else return 5;
	}
	double GetThreshold() {
		double Value;
		if (SUCCEEDED( p->get_ContrastThreshold(&Value) )) return Value;
		else return 2;
	}

	void SetEdgeMode(CogCaliperPolarityConstants __Polarity) {
		CMNVLogFile Log(_T("CMNVCaliperParams"), _T("SetEdgeMode Single"), _T("D:\\Log"), _T("MNVision.txt"));
		p->put_EdgeMode(cogCaliperEdgeModeSingle);
		p->put_Edge0Polarity(__Polarity);
		//p->put_Edge0Position(0);
	}
	void SetEdgeMode(CogCaliperPolarityConstants __Polarity1, CogCaliperPolarityConstants __Polarity2, double __dSize) {
		CMNVLogFile Log(_T("CMNVCaliperParams"), _T("SetEdgeMode Pair"), _T("D:\\Log"), _T("MNVision.txt"));
		p->put_EdgeMode(cogCaliperEdgeModePair);
		p->put_Edge0Polarity(__Polarity1);
		p->put_Edge0Position(-(__dSize / 2));
		p->put_Edge1Polarity(__Polarity2);
		p->put_Edge1Position(__dSize / 2);
	}
	void SetEdgeParam(int __nHalfPixel, double __dThreshold) {
		CMNVLogFile Log(_T("CMNVCaliperParams"), _T("SetEdgeParam"), _T("D:\\Log"), _T("MNVision.txt"));
		p->put_ContrastThreshold(__dThreshold);
		p->put_FilterHalfSizeInPixels(__nHalfPixel);
	}

	bool SetHalfPixel(int __nValue) { return SUCCEEDED( p->put_FilterHalfSizeInPixels(__nValue) ); }
	bool SetThreshold(double __dValue) { return SUCCEEDED( p->put_ContrastThreshold(__dValue) ); }

	void Prepare(LPCTSTR __strFile, LPCTSTR __strSection) {
		CMNVLogFile Log(_T("CMNVCaliperParams"), _T("Prepare"), _T("D:\\Log"), _T("MNVision.txt"));
		//CogCaliperPolarityConstants::cogCaliperPolarityDontCare = 3
		//CogCaliperPolarityConstants::cogCaliperPolarityDarkToLight = 1
		//CogCaliperPolarityConstants::cogCaliperPolarityLightToDark = 2
		//Create();
		int nEdgeMode = CMNVIni::GetValue(__strSection, _T("EdgeMode"), 0, __strFile);
		if (nEdgeMode == cogCaliperEdgeModePair) {
			SetEdgeMode(
				(CogCaliperPolarityConstants) CMNVIni::GetValue(__strSection, _T("Polarity1"), 3, __strFile)
				, (CogCaliperPolarityConstants) CMNVIni::GetValue(__strSection, _T("Polarity2"), 3, __strFile)
				, CMNVIni::GetValue(__strSection, _T("EdgeWidth"), double(10), __strFile)
			);
		}
		else {
			SetEdgeMode( (CogCaliperPolarityConstants) CMNVIni::GetValue(__strSection, _T("Polarity1"), 3, __strFile) );
		}
		SetEdgeParam(
				CMNVIni::GetValue(__strSection, _T("HalfPixel"), 2, __strFile)
			,	CMNVIni::GetValue(__strSection, _T("Threshold1"), (double)5, __strFile)
			);
		{
			CMNVCaliperScorerPositionNeg_Disp Score;
			Score.SetXYParameters(-100, 2000, 2000, 1, 0);
			CMNVCaliperScorers Scorers(false);
			p->get_SingleEdgeScorers(&Scorers);
			Scorers.Clear();
			Scorers.Add(Score);
		}
	}
	void SaveSetting(LPCTSTR __strFile, LPCTSTR __strSection) {
		CogCaliperEdgeModeConstants edgemode =  GetEdgeMode();
		if (edgemode == cogCaliperEdgeModePair) {
			CMNVIni::SetValue(__strSection, _T("EdgeMode"), (int)cogCaliperEdgeModePair, __strFile);
			CMNVIni::SetValue(__strSection, _T("Polarity1"), (int)GetEdge1Porarity(), __strFile);
			CMNVIni::SetValue(__strSection, _T("Polarity2"), (int)GetEdge2Porarity(), __strFile);
			CMNVIni::SetValue(__strSection, _T("EdgeWidth"), GetEdgeWidth(), __strFile);

		}
		else {
			CMNVIni::SetValue(__strSection, _T("EdgeMode"), (int)cogCaliperEdgeModeSingle, __strFile);
			CMNVIni::SetValue(__strSection, _T("Polarity1"), (int)GetEdge1Porarity(), __strFile);
		}
		CMNVIni::SetValue(__strSection, _T("HalfPixel"), GetHalfPixel(), __strFile);
		CMNVIni::SetValue(__strSection, _T("Threshold"), GetThreshold(), __strFile);
	}
};
class CMNVCaliperResult : public CComPtr<ICogCaliperResult> {
public:
	void Release() {
		if(p != NULL) Detach()->Release();
		CComPtr<ICogCaliperResult>::Release();
	}
	void Create() { CoCreateInstance(CLSID_CogCaliperResult); }
public:
	CMNVCaliperResult(bool isCreate = true) { if (isCreate) CoCreateInstance(CLSID_CogCaliperResult); }
	~CMNVCaliperResult() { Release(); }
};

class CMNVCaliperResults : public CComPtr<ICogCaliperResults> {
public:
	void Release() {
		if(p != NULL) Detach()->Release();
		CComPtr<ICogCaliperResults>::Release();
	}
	void Create() { Release(); CoCreateInstance(CLSID_CogCaliperResults); }
public:
	CMNVCaliperResults(bool isCreate = true) { if (isCreate) Create(); }
	~CMNVCaliperResults() { Release(); }
};

class CMNVCompositeShape : public CComPtr<ICogCompositeShape> {
public:
	void Relese() {
		if(p != NULL) Detach()->Release();
		CComPtr<ICogCompositeShape>::Release();
	}
	bool Create() {
		Release();
		return SUCCEEDED( CoCreateInstance(CLSID_CogCompositeShape) );
	}
public:
	CMNVCompositeShape(bool __isCreate = true) { if(__isCreate) Create(); }
	~CMNVCompositeShape() { Release(); }
};

class CMNVCaliperEdge : public CComPtr<ICogCaliperEdge> {
public:
	bool Create() {
		Release();
		return SUCCEEDED( CoCreateInstance(CLSID_CogCaliperEdge) );
	}
	void Release() {
		if(p != NULL) Detach()->Release();
		CComPtr<ICogCaliperEdge>::Release();
	}
public:
	CMNVCaliperEdge() { Create(); }
	~CMNVCaliperEdge() { Release(); }
};

class CMNVCaliper : public CComPtr<ICogCaliper> {
	CMNVCaliperResults m_Results;
public:
	bool Create() {
		Release();
		return SUCCEEDED( CoCreateInstance(CLSID_CogCaliper) );
	}
	void Release() {
		if(p != NULL) Detach()->Release();
		CComPtr<ICogCaliper>::Release();
	}
public:
	CMNVCaliper() { Create(); }
	~CMNVCaliper() { Release(); }
public:
	bool DisplayResult(CMNVStaticGraphicCollection & __GCollection) {
		long nCount = 0;
		if ( SUCCEEDED( m_Results->get_Count(&nCount) ) && nCount > 0 ) {
			CMNVCaliperResult CResult(false);
			if ( SUCCEEDED( m_Results->get_Item( 0, &CResult ) ) ) {
				CMNVCompositeShape CompositeShape(false);
				CResult->CreateResultGraphics(cogCaliperResultGraphicAll, &CompositeShape);
				__GCollection->Add(CMNVGraphic(CompositeShape), 0);
				return true;
			}
		}
		return false;
	}
	int GetRCount() {
		long nCount = 0;
		m_Results->get_Count(&nCount);
		return (int)nCount;
	}
	bool GetResult(int __nIndex, double & __dX, double & __dY, double & __dScore) {
		CMNVCaliperEdge Edge;
		long nCount = 0;
		if (m_Results == NULL) return false;
		if ( SUCCEEDED( m_Results->get_Count(&nCount) ) && nCount > 0 ) {
			if (__nIndex < nCount) {
				CMNVCaliperResult CResult(false);
				if (SUCCEEDED(m_Results->get_Item(__nIndex, &CResult))) {
					//if (FAILED(CResult->get_Score(&__dScore))) return false;
					if (FAILED(CResult->get_PositionX(&__dX))) return false;
					if (FAILED(CResult->get_PositionY(&__dY))) return false;
					Edge.Release();
					CResult->get_Edge0(&Edge);
					Edge->get_Contrast(&__dScore);
					return true;
				}
			}
			else {
				return false;
			}
		}
		return false;
	}
	bool Execute(ICogImage8Grey * __pImage, CMNVRectangleAffine &__Region) {
		//bool Result = false;
		m_Results.Release();
		return SUCCEEDED( p->Execute(__pImage, __Region, &m_Results) );
		//return Result;
	}
	bool Execute(ICogImage8Grey * __pImage, CMNV_STPoint & __Origin, CMNV_STPoint & __Horizontal, CMNV_STPoint & __Verticality) {
		bool Result = false;
		CMNVRectangleAffine Region;
		if ( SUCCEEDED( Region->SetOriginCornerXCornerY(__Origin.GetX(), __Origin.GetY(), __Horizontal.GetX(), __Horizontal.GetY(), __Verticality.GetX(), __Verticality.GetY()) ) ) {
			return SUCCEEDED( p->Execute(__pImage, Region, &m_Results) );
		}
		return false;
	}
	bool Execute_Origin(ICogImage8Grey * __pImage, CMNV_STPoint & __Origin, double __Width, double __Height, double __Rotation, double __Skew) {
		bool Result = false;
		CMNVRectangleAffine Region;
		if (FAILED( Region->SetOriginLengthsRotationSkew(__Origin.GetX(), __Origin.GetY(), __Width, __Height, __Rotation, __Skew) )) return false;
		return SUCCEEDED( p->Execute(__pImage, Region, &m_Results) );
	}
	bool Execute_Center(ICogImage8Grey * __pImage, CMNV_STPoint & __Center, double __Width, double __Height, double __Rotation, double __Skew) {
		bool Result = false;
		CMNVRectangleAffine Region;
		if ( SUCCEEDED( Region->SetCenterLengthsRotationSkew(__Center.GetX(), __Center.GetY(), __Width, __Height, __Rotation, __Skew) ) ) {
			return SUCCEEDED( p->Execute(__pImage, Region, &m_Results) );
		}
		return false;
	}
	bool Execute_Center(CMNVImage & __imgSource, CMNV_STPoint & __Center, double __Width, double __Height, double __Rotation, double __Skew) {
		CMNVImage8Grey imgGrey;
		__imgSource.Copy(imgGrey);
		bool Result = false;
		CMNVRectangleAffine Region;
		if ( SUCCEEDED( Region->SetCenterLengthsRotationSkew(__Center.GetX(), __Center.GetY(), __Width, __Height, __Rotation, __Skew) ) ) {
			m_Results.Release();
			p->put_MaxResults(20);
			p->put_EdgeMode(cogCaliperEdgeModeSingle);
			p->put_Edge0Polarity(cogCaliperPolarityDontCare);
			p->put_Edge0Position(0);
			p->put_ContrastThreshold(10);
			p->put_FilterHalfSizeInPixels(10);
			return SUCCEEDED( p->Execute(imgGrey, Region, &m_Results) );
		}
		return false;
	}
	bool Execute_Center(CMNVImage & __imgSource, CMNVRectangleAffine & __rectaRegion, int __nMaxResult, double __dThreshold, int __nHalfPixel) {
		CMNVImage8Grey imgGrey;
		__imgSource.Copy(imgGrey);
		bool Result = false;

		m_Results.Release();
		p->put_MaxResults(__nMaxResult);
		p->put_EdgeMode(cogCaliperEdgeModeSingle);
		p->put_Edge0Polarity(cogCaliperPolarityDontCare);
		p->put_Edge0Position(0);
		p->put_ContrastThreshold(__dThreshold);
		p->put_FilterHalfSizeInPixels(__nHalfPixel);

		return SUCCEEDED( p->Execute(imgGrey, __rectaRegion, &m_Results) );
	}
	void Func() {

	}
};

class CMNV_Caliper {
public:
	CMNVCaliper m_AlgCaliper;
	double m_dContrastThreshold; /* 5*/
	double m_dAcceptScore;
	CogCaliperPolarityConstants m_Polarity; //cogCaliperPolarityDontCare
	CogCaliperEdgeModeConstants m_EdgeMode; // cogCaliperEdgeModeSingle
	int m_nHalfSizeInPixels; // 2
	int m_nMaxResults; // 1
					   //ST_RECT_CENTERWH m_stRegion;
	CMNVRectangleAffine m_RectA_Region;
public:
	CMNV_Caliper() { InitData(); }
	void InitData() {
		m_dContrastThreshold = (double)5;
		m_dAcceptScore = (double)0.5;

		m_Polarity = cogCaliperPolarityDontCare;
		m_EdgeMode = cogCaliperEdgeModeSingle;
		m_nHalfSizeInPixels = 2;
		m_nMaxResults = 10;

		m_RectA_Region.Create();
		m_RectA_Region.SetInterectiveRegion();
		m_RectA_Region.SetRect_CenterWH((double)800, (double)600, (double)300, (double)300, (double)0 / 2, 0);
	}
	void SetRotateRegion(int __cnt90) {
		m_RectA_Region->put_Rotation(PI / 2 * __cnt90);
	}
	bool Excute(CMNVImage8Grey & __imgSource, CMNVStaticGraphicCollection & pGraphicCollection) {
		m_AlgCaliper->put_ContrastThreshold(m_dContrastThreshold);
		m_AlgCaliper->put_Edge0Polarity(m_Polarity);
		m_AlgCaliper->put_FilterHalfSizeInPixels(m_nHalfSizeInPixels);
		m_AlgCaliper->put_EdgeMode(m_EdgeMode);
		m_AlgCaliper->put_MaxResults(m_nMaxResults);

		//CMNVCaliperScorerPositionNeg_Disp pCaliperScorerPositionNeg;
		//pCaliperScorerPositionNeg->put_Enabled(VARIANT_TRUE);
		//long nCount;
		//CMNVCaliperScorers pCogCaliperScorers(false);
		//m_AlgCaliper->get_SingleEdgeScorers(&pCogCaliperScorers);
		//pCogCaliperScorers->get_Count(&nCount);
		//pCogCaliperScorers->Clear();
		//pCogCaliperScorers->Add(pCaliperScorerPositionNeg, 0);

		//pGraphicCollection.AddRectSegment(1, cogColorBlue, m_RectA_Region);

		if (!m_AlgCaliper.Execute(__imgSource, m_RectA_Region)) {
			AfxMessageBox(_T("Error"));
			return false;
		}
		else return true;
	}
	void LoadData(LPCTSTR __strDir, LPCTSTR __strFile, LPCTSTR __strSection) {
		CString strFilePath = _T(""); strFilePath.Format(_T("%s\\%s"), __strDir, __strFile);

		m_dContrastThreshold = CMNVIni::GetValue(__strSection, _T("ContrastThreshold"), (double)5, strFilePath);
		m_dAcceptScore = CMNVIni::GetValue(__strSection, _T("AcceptScore"), (double)0.5, strFilePath);
		m_Polarity = (CogCaliperPolarityConstants)CMNVIni::GetValue(__strSection, _T("Polarity"), (int)cogCaliperPolarityDontCare, strFilePath);
		m_EdgeMode = (CogCaliperEdgeModeConstants)CMNVIni::GetValue(__strSection, _T("EdgeMode"), (int)cogCaliperEdgeModeSingle, strFilePath);
		m_nHalfSizeInPixels = CMNVIni::GetValue(__strSection, _T("HalfSizeInPixels"), 2, strFilePath);
		m_nMaxResults = CMNVIni::GetValue(__strSection, _T("MaxResults"), 1, strFilePath);

		m_RectA_Region.Create();
		m_RectA_Region->put_Color(cogColorGreen);
		m_RectA_Region.SetInterectiveRegion();
		m_RectA_Region.SetRect_CenterWH(CMNVIni::GetValue(__strSection, _T("RegionCX"), (double)800, strFilePath)
			, CMNVIni::GetValue(__strSection, _T("RegionCY"), (double)600, strFilePath)
			, CMNVIni::GetValue(__strSection, _T("RegionSX"), (double)300, strFilePath)
			, CMNVIni::GetValue(__strSection, _T("RegionSY"), (double)300, strFilePath)
			, CMNVIni::GetValue(__strSection, _T("RegionR"), (double)-PI / 2, strFilePath)
			, CMNVIni::GetValue(__strSection, _T("RegionSkew"), (double)0, strFilePath));
	}
	void SaveData(LPCTSTR __strDir, LPCTSTR __strFile, LPCTSTR __strSection) {
		CString strFilePath = _T("");
		strFilePath.Format(_T("%s\\%s"), __strDir, __strFile);

		CMNVIni::SetValue(__strSection, _T("ContrastThreshold"), m_dContrastThreshold, strFilePath);
		CMNVIni::SetValue(__strSection, _T("AcceptScore"), m_dAcceptScore, strFilePath);
		CMNVIni::SetValue(__strSection, _T("Polarity"), (int)m_Polarity, strFilePath);
		CMNVIni::SetValue(__strSection, _T("EdgeMode"), (int)m_EdgeMode, strFilePath);
		CMNVIni::SetValue(__strSection, _T("HalfSizeInPixels"), m_nHalfSizeInPixels, strFilePath);
		CMNVIni::SetValue(__strSection, _T("MaxResults"), m_nMaxResults, strFilePath);

		CMNVIni::SetValue(__strSection, _T("RegionCX"), m_RectA_Region.GetCenterX(), strFilePath);
		CMNVIni::SetValue(__strSection, _T("RegionCY"), m_RectA_Region.GetCenterY(), strFilePath);
		CMNVIni::SetValue(__strSection, _T("RegionSX"), m_RectA_Region.GetWidth(), strFilePath);
		CMNVIni::SetValue(__strSection, _T("RegionSY"), m_RectA_Region.GetHeight(), strFilePath);
		CMNVIni::SetValue(__strSection, _T("RegionR"), m_RectA_Region.GetRotation(), strFilePath);
		CMNVIni::SetValue(__strSection, _T("RegionSkew"), m_RectA_Region.GetSkew(), strFilePath);
	}

	bool DisplayEdit(CMNVDisplay & __pDisplay) {
		CMNVInteractiveGraphicCollection IGCollection;
		IGCollection.AddGraphic(m_RectA_Region, cogColorGreen, 1);

		__pDisplay.Clear_Graphic();
		__pDisplay.AddGraphic(IGCollection, false);
		return true;
	}
	bool DisplayPattern(CMNVDisplay & __pDisplay) {
		__pDisplay.Clear_Graphic();
		__pDisplay.Clear_Image();
		return true;
	}
};
