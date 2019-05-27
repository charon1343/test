#pragma once
#include "Define_Cog.h"
#include "MNVObject.h"
////// 이미지 상에사 위치(Pointer)를 표현 혹은 편집하기 위해서 사용하는 그래픽 객체
class CMNVPointMarker : public CComPtr<ICogPointMarker> {
public:
	bool Create() { Release(); return SUCCEEDED(CoCreateInstance(CLSID_CogPointMarker)); }
	bool Create(CogPointMarkerDOFConstants __DOFEnable, VARIANT_BOOL __isInteractive, BSTR __pSpaceName) {
		if (!Create()) return false;
		if (FAILED(p->put_GraphicDOFEnable(__DOFEnable))) return false;
		if (FAILED(p->put_Interactive(__isInteractive))) return false;
		if (FAILED(p->put_SelectedSpaceName(CComBSTR("#")))) return false;
		return true;
	}
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogPointMarker>::Release();
	}
public:
	double GetX() {
		if (p == NULL) return (double)0;
		double dValue;
		if (SUCCEEDED(p->get_X(&dValue))) return dValue;
		return (double)0;
	}
	double GetY() {
		if (p == NULL) return (double)0;
		double dValue;
		if (SUCCEEDED(p->get_Y(&dValue))) return dValue;
		return (double)0;
	}
	double GetAngle() {
		if (p == NULL) return (double)0;
		double dValue;
		if (SUCCEEDED(p->get_Rotation(&dValue))) return dValue;
		return (double)0;
	}
	CMNVPointMarker(bool __isCreate = true) : CComPtr<ICogPointMarker>() { if (__isCreate) Create(); }
	CMNVPointMarker(CMNV_STPoint __Point, long __SizeInScreen) : CComPtr<ICogPointMarker>() {
		Create();
		SetPointMarker(__Point, __SizeInScreen);
	}
	~CMNVPointMarker() { Release(); }
	bool SetInterectiveOrigin() {
		if (FAILED(p->put_GraphicDOFEnable(cogPointMarkerDOFAll))) return false;
		if (FAILED(p->put_Interactive(VARIANT_TRUE))) return false;
		return SUCCEEDED(p->put_SelectedSpaceName(CComBSTR("#")));
	}
	bool SetPointMarker(double __dX, double __dY, double __dRotation, long __SizeInScreen) {
		if (p == NULL) Create(cogPointMarkerDOFPosition, TRUE, CComBSTR("#"));
		return SUCCEEDED(p->SetCenterRotationSize(__dX, __dY, __dRotation, __SizeInScreen));
	}
	bool SetPointMarker(CMNV_STPoint __Point, long __SizeInScreen) {
		if (p == NULL) Create(cogPointMarkerDOFPosition, TRUE, CComBSTR("#"));
		return SUCCEEDED(p->SetCenterRotationSize(__Point.m_dX, __Point.m_dY, __Point.m_dR, __SizeInScreen));
	}
	bool SetPointMarker(double __dX, double __dY) {
		if (p == NULL) return false;
		if (FAILED(p->put_X(__dX))) return false;
		return SUCCEEDED(p->put_Y(__dY));
	}
	bool SetPointMarker(CMNV_STPoint __Point) {
		if (p == NULL) return false;
		if (FAILED(p->put_X(__Point.m_dX))) return false;
		return SUCCEEDED(p->put_Y(__Point.m_dY));
	}
};
