#pragma once
#include "MNVObject.h"
#include "MNVImage.h"
#include "CamInfo.h"
#include "MNVGraphicsCollection.h"
#include "MNVCaliper.h"

class CMNV_FindLineResult : public CComPtr<ICogFindLineResult> {
public:
	CMNV_FindLineResult(bool __isCreate = true) { Create(); }
	~CMNV_FindLineResult() { Release(); }
	void Create() { CoCreateInstance(CLSID_CogFindLineResult); }
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogFindLineResult>::Release();
	}
};
class CMNV_FindLineResults : public CComPtr<ICogFindLineResults> {
public:
	CMNV_FindLineResults(bool __isCreate = true) { if (__isCreate) Create(); }
	~CMNV_FindLineResults() { Release(); }
	void Create() { CoCreateInstance(CLSID_CogFindLineResults); }
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogFindLineResults>::Release();
	}
};
class CMNV_FindLineParams : public CComPtr<ICogFindLineParams> {
public:
	CMNV_FindLineParams() { Create(); }
	~CMNV_FindLineParams() { Release(); }
	void Create() { CoCreateInstance(CLSID_CogFindLineParams); }
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogFindLineParams>::Release();
	}
};
class CMNV_FindLineAlgorithm : public CComPtr<ICogFindLine> {
	CMNV_FindLineResults m_LineResults;
public:
	CMNV_FindLineAlgorithm() { Create(); }
	~CMNV_FindLineAlgorithm() { Release(); }
	void Create() { CoCreateInstance(CLSID_CogFindLine); }
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogFindLine>::Release();
	}
	int GetCaliperCnt() {
		long lCnt = 0;
		if ( SUCCEEDED( m_LineResults->get_Count(&lCnt) ) )
			return (int)lCnt;
		else
			return -1;
	}
	bool GetCaliper(int __nIndex, double & __dX, double & __dY) {
		CMNV_FindLineResult FindResult;
		FindResult.Release();
		if ( FAILED(m_LineResults->get_Item(__nIndex, &FindResult)) ) return false;

		FindResult->get_X(&__dX);
		FindResult->get_Y(&__dY);
		return true;
	}
	bool GetCaliper(int __nIndex, CMNV_STPoint &__stPoint, bool &__isUsed, bool &__isFound) {
		CMNV_FindLineResult FindResult;
		VARIANT_BOOL vbUsed;
		FindResult.Release();
		if (FAILED(m_LineResults->get_Item(__nIndex, &FindResult))) return false;

		FindResult->get_X(&(__stPoint.m_dX));
		FindResult->get_Y(&(__stPoint.m_dY));
		FindResult->get_Used(&vbUsed);
		__isUsed = vbUsed == VARIANT_TRUE;
		FindResult->get_Found(&vbUsed);
		__isFound = vbUsed == VARIANT_TRUE;
		return true;
	}
	void SetFindLine(double __dWidth, double __dHeight, double __dDirection, int __cntCaliper, int __cntIgnore) {
		p->put_CaliperProjectionLength(__dWidth); // 프로젝션 길이
		p->put_CaliperSearchDirection(__dDirection);	// 검색 방향 (90 / -90)
		p->put_CaliperSearchLength(__dHeight);	// 검색 길이
		p->put_NumCalipers(__cntCaliper);	// 캘리퍼 수
		p->put_NumToIgnore(__cntIgnore);	// 무시할 숫자
	}
	void SetCaliperParam_Single(CogCaliperPolarityConstants __Polarity, double __dContrastThreshold, int __nHalfPixel) {
		CMNVCaliperParams _CaliperParam(false);
		p->get_CaliperRunParams(&_CaliperParam);

		_CaliperParam->put_EdgeMode(cogCaliperEdgeModeSingle);
		_CaliperParam->put_Edge0Polarity(__Polarity);
		_CaliperParam->put_ContrastThreshold(__dContrastThreshold);
		_CaliperParam->put_FilterHalfSizeInPixels(__nHalfPixel);
		{	CMNVCaliperScorers pCogCaliperScorers(false);
			_CaliperParam->get_SingleEdgeScorers(&pCogCaliperScorers);
			pCogCaliperScorers->Clear();
			CMNVCaliperScorerPositionNeg_Disp pCaliperScorerPositionNeg;
			pCaliperScorerPositionNeg->put_Enabled(VARIANT_TRUE);
			pCogCaliperScorers->Add(pCaliperScorerPositionNeg, 0);
			_CaliperParam->putref_SingleEdgeScorers(pCogCaliperScorers);
		}

		p->putref_CaliperRunParams(_CaliperParam);
	}
	bool FindLine_Excute(CMNVLineSegment &__LineSegment, CMNVImage &__imgSource, CMNVStaticGraphicCollection &__GCollection) {
		CMNVImage8Grey imgGray;
		__imgSource.Copy(imgGray);
		return FindLine_Excute(__LineSegment, imgGray, __GCollection);
	}
	bool FindLine_Excute(CMNVLineSegment &__LineSegment, CMNVImage8Grey &__imgSource, CMNVStaticGraphicCollection &__GCollection)
	{
		m_LineResults.Release();
		p->putref_ExpectedLineSegment(__LineSegment); // 예상 라인 세그먼트
		if (SUCCEEDED(p->Execute(__imgSource, &m_LineResults))) {
			//__GCollection.AddLineSegment(1, cogColorRed, __LineSegment);
			CMNV_FindLineResult FindResult;
			CMNV_STPoint stCaliper;
			bool isUsed, isFound;
			int nFound = 0;
			int nCnt = GetCaliperCnt();
			for (int nIndex = 0; nIndex < nCnt; ++nIndex) {
				GetCaliper(nIndex, stCaliper, isUsed, isFound);
				if (isFound && isUsed) ++nFound;
				__GCollection.AddPoint(stCaliper, 1, 3, isUsed ? cogColorYellow : cogColorRed);
			}
			return (nFound >= 2);
		}
		return false;
	}
	bool GetFindLine(CMNVLine &__LineResult)
	{
		if (m_LineResults == NULL) return false;
		__LineResult.Release();
		return SUCCEEDED(m_LineResults->GetLine(&__LineResult));
	}
};
#define ABSSUB(a, b) (((a) > (b)) ? ((a) - (b)): ((b) - (a)))
class CMNV_MathAlgorithm : public CComPtr<ICogMath>
{
public:
	CMNV_MathAlgorithm() { Create(); }
	~CMNV_MathAlgorithm() { Release(); }
	void Create() { CoCreateInstance(CLSID_CogMath); }
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogMath>::Release();
	}
	bool Intersect(CMNVLine &__Line1, CMNVLine &__Line2, CMNVImage &__imgGrey, CMNV_STPoint &__stPoint) {
		long lPoints;
		VARIANT_BOOL vbResult;
		if (SUCCEEDED(p->IntersectLineLine(__Line1, __Line2, __imgGrey, &lPoints, &(__stPoint.m_dX), &(__stPoint.m_dY), &(__stPoint.m_dR), &vbResult)))
			return vbResult == VARIANT_TRUE;
		else return false;
	}
	bool Intersect(CMNVLine &__Line1, CMNVLine &__Line2, CMNVImage &__imgGrey, CMNV_STPoint &__stPoint, CMNVStaticGraphicCollection &GCollection, CogColorConstants __Color) {
		long lPoints;
		VARIANT_BOOL vbResult;
		if (SUCCEEDED(p->IntersectLineLine(__Line1, __Line2, __imgGrey, &lPoints, &(__stPoint.m_dX), &(__stPoint.m_dY), &(__stPoint.m_dR), &vbResult))) {
			GCollection.AddGraphic(__Line1, 1, __Color);
			GCollection.AddGraphic(__Line2, 1, __Color);
			GCollection.AddPoint(__stPoint, 1, 50, __Color);
			return vbResult == VARIANT_TRUE;
		}
		else return false;
	}

	bool Intersect(CMNVLine & __Line, CMNVCircle & __Circle, CMNVImage &__imgGrey, CMNV_STPoint &__stPoint1, CMNV_STPoint &__stPoint2) {
		long lPoints;
		VARIANT_BOOL vbResult;
		if (SUCCEEDED( p->IntersectLineCircle(__Line, __Circle, __imgGrey, &lPoints, &__stPoint1.m_dX, &__stPoint1.m_dY, &__stPoint2.m_dX, &__stPoint2.m_dY, &vbResult) )) {
			return vbResult == VARIANT_TRUE;
		}
		return false;
	}
	bool Intersect(CMNVLine & __Line, CMNVCircle & __Circle, CMNV_STPoint &__stSide, CMNVImage &__imgGrey, CMNV_STPoint &__stResult) {
		CMNV_STPoint _Intersect[2];
		Intersect(__Line, __Circle, __imgGrey, _Intersect[0], _Intersect[1]);

		if (__stSide.Distance(_Intersect[0]) < __stSide.Distance(_Intersect[1])) {
			__stResult = _Intersect[0];
		}
		else {
			__stResult = _Intersect[1];
		}
		return true;
	}
	double Distance(CMNV_STPoint & __stPoint, CMNVLine & __stLine, CMNVImage &__imgGrey, CMNV_STPoint & __stLPoint) {
		double dDistance = -1;
		if (FAILED( p->DistancePointLine(__stPoint.m_dX, __stPoint.m_dY, __stLine, __imgGrey, &__stLPoint.m_dX, &__stLPoint.m_dY, &dDistance) )) {
			return -1;
		}
		return dDistance;
	}
	double Distance(CMNVPointMarker & __Point, CMNVLine & __Line, CMNVImage &__imgGrey, CMNV_STPoint & __stLPoint) {
		double dDistance = -1;
		if (FAILED( p->DistancePointLine(__Point.GetX(), __Point.GetY(), __Line, __imgGrey, &__stLPoint.m_dX, &__stLPoint.m_dY, &dDistance) )) {
			return -1;
		}
		return dDistance;
	}
};

class CMNV_FindCircleResult : public CComPtr<ICogFindCircleResult> {
public:
	CMNV_FindCircleResult(bool __isCreate = false) { if (__isCreate) Create(); }
	~CMNV_FindCircleResult() { Release(); }
	void Create() { CoCreateInstance(CLSID_CogFindCircleResult); }
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogFindCircleResult>::Release();
	}
public:
};

class CMNV_FindCircleResults : public CComPtr<ICogFindCircleResults> {
public:
	CMNV_FindCircleResults(bool __isCreate = false) { if (__isCreate) Create(); }
	~CMNV_FindCircleResults() { Release(); }
	void Create() { CoCreateInstance(CLSID_CogFindCircleResults); }
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogFindCircleResults>::Release();
	}
public:
	bool GetResult(CMNVCircle & __Circle) {
		if (p == NULL) return false;
		long nCnt = 0;
		p->get_Count(&nCnt);
		if (nCnt > 0) {
			__Circle.Release();
			return SUCCEEDED( p->GetCircle(&__Circle));
		}
		else {
			return false;
		}
	}
	bool GetResult(CMNVCircularArc & __Circle) {
		if (p == NULL) return false;
		long nCnt = 0;
		p->get_Count(&nCnt);
		if (nCnt > 0) {
			__Circle.Release();
			return SUCCEEDED( p->GetCircularArc(&__Circle));
		}
		else {
			return false;
		}
	}
	
	//void Func() {
	//	CMNVCircle Circle(false);
	//	p->GetCircle(&Circle);
	//	double CenterX = Circle.GetCenterX();
	//	double CenterY = Circle.GetCenterY();
	//	double Radius = Circle.GetRadius();
	//}
};
class CMNV_FindCircle : public CComPtr<ICogFindCircle> {
public:
	CMNV_FindCircleResults m_Results;
	CMNVCaliperParams m_Params;
	long m_cntCaliper;
	long m_lengProjection;
	long m_lengSearch;
	bool m_isIgnore;
	long m_cntIgnore;
	double m_dRadiusConstraint;
	bool m_isRadiusConstraint;
	CogFindCircleSearchDirectionConstants m_SearchDirection;
public:
	CMNVCircularArc m_CircurlarArc;
	long GetCount_Caliper() { return m_cntCaliper; }
	long GetLength_Projection() { return m_lengProjection; }
	long GetLength_Search() { return m_lengSearch; }
	bool GetEnable_Ignore() { return m_isIgnore; }
	long GetCount_Ignore() { return m_cntIgnore; }
	double GetDouble_RadiusConstraint() { return m_dRadiusConstraint; }
	bool GetEnable_RadiusConstraint() { return m_isRadiusConstraint; }
	CogFindCircleSearchDirectionConstants GetConst_SearchDirection() { return m_SearchDirection; }

	void SetCount_Caliper(long __cntCaliper) { m_cntCaliper = __cntCaliper; }
	void SetLength_Projection(long __lengProjection) { m_lengProjection = __lengProjection; }
	void SetLength_Search(long __lengSearch) { m_lengSearch = __lengSearch; }
	void SetEnable_Ignore(bool __isIgnore) { m_isIgnore = __isIgnore; }
	void SetCount_Ignore(long __cntIgnore) { m_cntIgnore = __cntIgnore; }
	void SetDouble_RadiusConstraint(double __dRadiusConstraint) { m_dRadiusConstraint = __dRadiusConstraint; }
	void SetEnable_RadiusConstraint(bool __isRadiusConstraint) { m_isRadiusConstraint = __isRadiusConstraint; }
	void SetConst_SearchDirection(CogFindCircleSearchDirectionConstants __SearchDirection) { m_SearchDirection = __SearchDirection; }

	void SetPolarity(CogCaliperPolarityConstants __Polarity) { m_Params.SetEdgeMode(__Polarity); }

	double GetCenterX() { return m_CircurlarArc.GetCenterX(); }
	double GetCenterY() { return m_CircurlarArc.GetCenterY(); }
	double GetRadius() { return m_CircurlarArc.GetRadius(); }
	double GetStart() { return m_CircurlarArc.GetAngleStart(); }
	double GetSpan() { return m_CircurlarArc.GetAngleSpan(); }

	bool SetCenterX(double __dValue) { return m_CircurlarArc.SetCenterX(__dValue); }
	bool SetCenterY(double __dValue) { return m_CircurlarArc.SetCenterY(__dValue); }
	bool SetRadius(double __dValue) { return m_CircurlarArc.SetRadius(__dValue); }
	bool SetStart(double __dValue) { return m_CircurlarArc.SetAngleStart(__dValue); }
	bool SetSpan(double __dValue) { return m_CircurlarArc.SetAngleSpan(__dValue); }

	CMNV_FindCircle() { Create(); }
	~CMNV_FindCircle() { Release(); }
	void Create() { Release(); CoCreateInstance(CLSID_CogFindCircle); }
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogFindCircle>::Release();
	}

	bool Prepare() {
		if (p == NULL) Create();
		m_Results.Release();
		p->put_CaliperProjectionLength(m_lengProjection);
		p->put_CaliperSearchDirection(m_SearchDirection);
		p->put_CaliperSearchLength(m_lengSearch);
		p->put_DecrementNumToIgnore(m_isIgnore ? VARIANT_TRUE : VARIANT_FALSE);
		p->put_NumCalipers(m_cntCaliper);
		p->put_NumToIgnore(m_cntIgnore);
		if (m_isRadiusConstraint) {
			p->put_RadiusConstraintEnabled(m_isRadiusConstraint ? VARIANT_TRUE : VARIANT_FALSE);
			p->put_RadiusConstraint(m_isRadiusConstraint);
		}
		p->putref_ExpectedCircularArc(m_CircurlarArc);
		return true;
	}
	bool Prepare(LPCTSTR __strFile, LPCTSTR __strSection) {
		if (p == NULL) Create();

		m_cntCaliper = CMNVIni::GetValue(__strSection, _T("NumCalipers"), (long)30, __strFile);
		m_lengProjection = CMNVIni::GetValue(__strSection, _T("CaliperProjectionLength"), (long)30, __strFile);
		m_lengSearch = CMNVIni::GetValue(__strSection, _T("CaliperSearchLength"), (long)250, __strFile);
		m_isIgnore = CMNVIni::GetValue(__strSection, _T("DecrementNumToIgnore"), 0, __strFile) != 0;
		m_cntIgnore = CMNVIni::GetValue(__strSection, _T("NumToIgnore"), (long)10, __strFile);
		m_dRadiusConstraint = CMNVIni::GetValue(__strSection, _T("RadiusConstraint"), (double)0, __strFile);
		m_isRadiusConstraint = CMNVIni::GetValue(__strSection, _T("RadiusConstraintEnabled"), 0, __strFile) != 0;
		m_SearchDirection = (CogFindCircleSearchDirectionConstants)CMNVIni::GetValue(__strSection, _T("CaliperSearchDirection"), (int)cogFindCircleSearchDirectionOutward, __strFile);

		m_CircurlarArc.Create();
		m_CircurlarArc.SetCircle(
			CMNVIni::GetValue(__strSection, _T("CenterX"), (double)1200, __strFile)
			, CMNVIni::GetValue(__strSection, _T("CenterY"), (double)1037, __strFile)
			, CMNVIni::GetValue(__strSection, _T("Redius"), (double)900, __strFile)
			, CMNVIni::GetValue(__strSection, _T("Start"), (double)0, __strFile)
			, CMNVIni::GetValue(__strSection, _T("Span"), (double)PI * 2, __strFile)
			);

		m_Params.Release();
		p->get_CaliperRunParams(&m_Params);
		m_Params.Prepare(__strFile, __strSection);

		//SaveIni(__strFile, __strSection);
		Prepare();
		return true;
	}
	bool SetExpectedCircularArc(double __dCenterX, double __dCenterY, double __dRadius) {
		m_CircurlarArc.SetCenterX(__dCenterX);
		m_CircurlarArc.SetCenterY(__dCenterY);
		m_CircurlarArc.SetRadius(__dRadius);
		p->putref_ExpectedCircularArc(m_CircurlarArc);
		return true;
	}
	bool SaveIni(LPCTSTR __strFile, LPCTSTR __strSection) {
		CMNVIni::SetValue(__strSection, _T("NumCalipers"), m_cntCaliper, __strFile);
		CMNVIni::SetValue(__strSection, _T("CaliperProjectionLength"), m_lengProjection, __strFile);
		CMNVIni::SetValue(__strSection, _T("CaliperSearchLength"), m_lengSearch, __strFile);
		CMNVIni::SetValue(__strSection, _T("DecrementNumToIgnore"), m_isIgnore ? 1 : 0, __strFile);
		CMNVIni::SetValue(__strSection, _T("NumToIgnore"), m_cntIgnore, __strFile);
		CMNVIni::SetValue(__strSection, _T("RadiusConstraint"), m_dRadiusConstraint, __strFile);
		CMNVIni::SetValue(__strSection, _T("RadiusConstraintEnabled"), m_isRadiusConstraint ? 1 : 0, __strFile);
		CMNVIni::SetValue(__strSection, _T("CaliperSearchDirection"), (int)m_SearchDirection, __strFile);

		CMNVIni::SetValue(__strSection, _T("CenterX"), m_CircurlarArc.GetCenterX(), __strFile);
		CMNVIni::SetValue(__strSection, _T("CenterY"), m_CircurlarArc.GetCenterY(), __strFile);
		CMNVIni::SetValue(__strSection, _T("Redius"), m_CircurlarArc.GetRadius(), __strFile);
		CMNVIni::SetValue(__strSection, _T("Start"), m_CircurlarArc.GetAngleStart(), __strFile);
		CMNVIni::SetValue(__strSection, _T("Span"), m_CircurlarArc.GetAngleSpan(), __strFile);

		m_Params.SaveSetting(__strFile, __strSection);
		return true;
	}

	bool Excute(CMNVImage8Grey &__imgSource) {
		p->putref_CaliperRunParams(m_Params);
		m_Results.Release();
		if ( SUCCEEDED( p->Execute(__imgSource, &m_Results) )) {
			m_Results.GetResult(m_CircurlarArc);
			return true;
			//m_Results.Release();
			//p->putref_ExpectedCircularArc(m_CircurlarArc);
			//if ( SUCCEEDED( p->Execute(__imgSource, &m_Results) )) {
			//	m_Results.GetResult(m_CircurlarArc);
			//	return true;
			//}
			//return false;
		}
		else {
			return false;
		}
	}

	bool Excute(CMNVImage &__imgSource) {
		CMNVLogFile Log(_T("Find Line"), _T("Excute"), _T("D:\\Log"), _T("MNVision.txt"));
		if (m_Results == NULL && p != NULL) {
			Log.OutputMessage(_T("Copy Image"));
			CMNVImage8Grey imgGray;
			__imgSource.Copy(imgGray);
			Log.OutputMessage(_T("Excute Find Line"));
			//CMNVCaliperParams CaliperParam;
			
			return Excute(imgGray);
		}
		else {
			//Alarm
			return false;
		}
	}
	bool GetResult(CMNVCircle & __Circle) { return m_Results.GetResult(__Circle); }
	bool GetResult(CMNVStaticGraphicCollection & __sgcResult) {
		if (__sgcResult == NULL && !(__sgcResult.Create())) return false;
		CMNVCircle circle;
		m_Results.GetResult(circle);
		__sgcResult.AddGraphic(m_CircurlarArc, 1, cogColorCyan);

		__sgcResult.AddGraphic(circle, 1, cogColorYellow);
		return true;
	}
};
