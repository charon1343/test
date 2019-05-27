#pragma once
#include "Define_Cog.h"

class CMNVRectangle : public CComPtr<ICogRectangle> {
public:
	bool Create() { Release(); return SUCCEEDED(CoCreateInstance(CLSID_CogRectangle)); }
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogRectangle>::Release();
	}
public:
	double GetCenterX() {
		double dValue;
		if (p == NULL) return 0;
		if (SUCCEEDED(p->get_CenterX(&dValue))) return dValue;
		else return 0;
	}
	double GetCenterY() {
		double dValue;
		if (p == NULL) return 0;
		if (SUCCEEDED(p->get_CenterY(&dValue))) return dValue;
		else return 0;
	}
	double GetWidth() {
		double dValue;
		if (p == NULL) return 0;
		if (SUCCEEDED(p->get_Width(&dValue))) return dValue;
		else return 0;
	}
	double GetHeight() {
		double dValue;
		if (p == NULL) return 0;
		if (SUCCEEDED(p->get_Height(&dValue))) return dValue;
		else return 0;
	}
	double GetX() {
		double dValue;
		if (p == NULL) return 0;
		if (SUCCEEDED(p->get_X(&dValue))) return dValue;
		else return 0;
	}
	double GetY() {
		double dValue;
		if (p == NULL) return 0;
		if (SUCCEEDED(p->get_Y(&dValue))) return dValue;
		else return 0;
	}
public:
	CMNVRectangle(bool __isCreate = true) : CComPtr<ICogRectangle>() { if (__isCreate) Create(); }
	CMNVRectangle(double __dx, double __dy, double __dWidth, double __dHeight, bool __isCenter = true) : CComPtr<ICogRectangle>() {
		CoCreateInstance(CLSID_CogRectangle);
		if(__isCenter) p->SetCenterWidthHeight(__dx, __dy, __dWidth, __dHeight);
		else p->SetXYWidthHeight(__dx, __dy, __dWidth, __dHeight);
	}
	~CMNVRectangle() { Release(); }
	bool Create(CogRectangleDOFConstants __DOFEnable, VARIANT_BOOL __isInteractive, BSTR __pSpaceName) {
		if (!Create()) return false;
		if (FAILED(p->put_GraphicDOFEnable(__DOFEnable))) return false;
		if (FAILED(p->put_Interactive(__isInteractive))) return false;
		if (FAILED(p->put_SelectedSpaceName(__pSpaceName))) return false;
		return true;
	}
	//HRESULT SetRectXY(double __dx, double __dy, double __dWidth, double __dHeight) { 
	//	return p->SetCenterWidthHeight(__dx, __dy, __dWidth, __dHeight);
	//}
	bool SetInterectiveRect() {
		if (FAILED(p->put_GraphicDOFEnable(cogRectangleDOFAll))) return false;
		//if (FAILED( p->put_XDirectionAdornment(cogRectangleAffineDirectionAdornmentSolidArrow) )) return false;
		//if (FAILED( p->put_YDirectionAdornment(cogRectangleAffineDirectionAdornmentArrow) )) return false;
		if (FAILED(p->put_Interactive(VARIANT_TRUE))) return false;
		return SUCCEEDED(p->put_SelectedSpaceName(CComBSTR("#")));
	}
	bool GetRect_CenterWH(double & __dCX, double & __dCY, double & __dW, double & __dH) {
		bool ret = true;
		//// 서로간에 연관성이 없기 때문에 FAILED가 발생하면 ret값을 false로 변경한다.
		//// 즉 한개라도 오류가 나면 실패로 리턴을 하지만 모두 실행을 하도록 한다.
		if (FAILED(p->get_CenterX(&__dCX))) ret = false;
		if (FAILED(p->get_CenterY(&__dCY))) ret = false;
		if (FAILED(p->get_Width(&__dW))) ret = false;
		if (FAILED(p->get_Height(&__dH))) ret = false;
		return ret;
	}
	HRESULT SetRect_CenterWH(double __dCX, double __dCY, double __dW, double __dH) {
		return p->SetCenterWidthHeight(__dCX, __dCY, __dW, __dH);
	}
	HRESULT SetRect_XYWH(double __dSX, double __dSY, double __dW, double __dH) {
		return p->SetXYWidthHeight(__dSX, __dSY, __dW, __dH);
	}
};

class CMNVCircle : public CComPtr<ICogCircle> {
public:
public:
	bool Create() { Release(); return SUCCEEDED(CoCreateInstance(CLSID_CogCircle)); }
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogCircle>::Release();
	}
public:
	CMNVCircle(bool __isCreate = true) : CComPtr<ICogCircle>() { if (__isCreate) Create(); }
	CMNVCircle(double __dx, double __dy, double __dRadius) : CComPtr<ICogCircle>() {
		Create();
		p->SetCenterRadius(__dx, __dy, __dRadius);
	}
	CMNVCircle(CMNV_STPoint __stPoint, double __dRadius) : CComPtr<ICogCircle>() {
		Create();
		SetCircle(__stPoint, __dRadius);
	}
	~CMNVCircle() { Release(); }

	bool SetCircle(double __dx, double __dy, double __dRadius) {
		if (p == NULL && !Create()) return false;
		if (FAILED( p->SetCenterRadius(__dx, __dy, __dRadius) )) return false;
		return true;
	}
	bool SetCircle(LPCTSTR __Section, LPCTSTR __File) {
		double dx, dy, dR;
		dx = CMNVIni::GetValue(__Section, _T("CenterX"), (double)0, __File);
		dy = CMNVIni::GetValue(__Section, _T("CenterY"), (double)0, __File);
		dR = CMNVIni::GetValue(__Section, _T("Radius"), (double)0, __File);
		if (dR == 0) return false;
		if (p == NULL && !Create()) return false;
		return SUCCEEDED( p->SetCenterRadius(dx, dy, dR) );
	}
	bool SetCircle(CMNV_STPoint __stPoint, double __dRadius) {
		if (p == NULL) return false;
		if (FAILED( p->SetCenterRadius(__stPoint.m_dX, __stPoint.m_dY, __dRadius) )) return false;
		return true;
	}

	double GetCenterX() {
		double dValue = 0;
		p->get_CenterX(&dValue);
		return dValue;
	}
	double GetCenterY() {
		double dValue = 0;
		p->get_CenterY(&dValue);
		return dValue;
	}
	double GetRadius() {
		double dValue = 0;
		p->get_Radius(&dValue);
		return dValue;
	}
};

class CMNVCircularArc : public CComPtr<ICogCircularArc> {
public:
public:
	bool Create() { Release(); return SUCCEEDED(CoCreateInstance(CLSID_CogCircularArc)); }
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogCircularArc>::Release();
	}
public:
	CMNVCircularArc(bool __isCreate = true) : CComPtr<ICogCircularArc>() { if (__isCreate) Create(); }
	CMNVCircularArc(double __dx, double __dy, double __dRadius, double __dStart, double __dSpan) : CComPtr<ICogCircularArc>() {
		Create();
		p->SetCenterRadiusAngleStartAngleSpan(__dx, __dy, __dRadius, __dStart, __dSpan);
	}
	CMNVCircularArc(CMNV_STPoint __stPoint, double __dRadius, double __dStart, double __dSpan) : CComPtr<ICogCircularArc>() {
		Create();
		SetCircle(__stPoint, __dRadius, __dStart, __dSpan);
	}
	~CMNVCircularArc() { Release(); }

	bool SetCircle(double __dx, double __dy, double __dRadius, double __dStart, double __dSpan) {
		if (p == NULL && !Create()) return false;
		if (FAILED( p->SetCenterRadiusAngleStartAngleSpan(__dx, __dy, __dRadius, __dStart, __dSpan) )) return false;
		return true;
	}
	bool SetCircle(LPCTSTR __Section, LPCTSTR __File) {
		double dx, dy, dR, dStart, dSpan;
		dx = CMNVIni::GetValue(__Section, _T("CenterX"), (double)0, __File);
		dy = CMNVIni::GetValue(__Section, _T("CenterY"), (double)0, __File);
		dR = CMNVIni::GetValue(__Section, _T("Radius"), (double)0, __File);
		dStart = CMNVIni::GetValue(__Section, _T("Start"), (double)0, __File);
		dSpan = CMNVIni::GetValue(__Section, _T("Span"), (double)0, __File);
		if (dR == 0) return false;
		if (p == NULL && !Create()) return false;
		return SUCCEEDED( p->SetCenterRadiusAngleStartAngleSpan(dx, dy, dR, dStart, dSpan) );
	}
	bool SetCircle(CMNV_STPoint __stPoint, double __dRadius, double __dStart, double __dSpan) {
		if (p == NULL) return false;
		if (FAILED( p->SetCenterRadiusAngleStartAngleSpan(__stPoint.m_dX, __stPoint.m_dY, __dRadius, __dStart, __dSpan) )) return false;
		return true;
	}

	double GetCenterX() {
		double dValue = 0;
		p->get_CenterX(&dValue);
		return dValue;
	}
	double GetCenterY() {
		double dValue = 0;
		p->get_CenterY(&dValue);
		return dValue;
	}
	double GetRadius() {
		double dValue = 0;
		p->get_Radius(&dValue);
		return dValue;
	}
	double GetAngleStart() {
		double dValue = 0;
		p->get_AngleStart(&dValue);
		return dValue;
	}
	double GetAngleSpan() {
		double dValue = 0;
		p->get_AngleSpan(&dValue);
		return dValue;
	}

	bool SetCenterX(double __dValue) { return SUCCEEDED( p->put_CenterX(__dValue) ); }
	bool SetCenterY(double __dValue) { return SUCCEEDED( p->put_CenterY(__dValue) ); }
	bool SetRadius(double __dValue) { return SUCCEEDED( p->put_Radius(__dValue) ); }
	bool SetAngleStart(double __dValue) { return SUCCEEDED( p->put_AngleStart(__dValue) ); }
	bool SetAngleSpan(double __dValue) { return SUCCEEDED( p->put_AngleSpan(__dValue) ); }
};
