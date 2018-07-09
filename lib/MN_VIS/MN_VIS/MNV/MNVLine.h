#pragma once
#include "Define_Cog.h"
#include "MNV_STPoint.h"
#include "MNVLineSegment.h"

class CMNVLine : public CComPtr<ICogLine> {
public:
	CMNVLine(bool __isCreate = true) : CComPtr<ICogLine>() { if (__isCreate) Create(); }
	CMNVLine(CMNV_STPoint & __stPointA, CMNV_STPoint & __stPointB) : CComPtr<ICogLine>() {
		Create();
		SetLine(__stPointA, __stPointB);
	}
	~CMNVLine() { Release(); }
public:
	double GetCenterX() { double dX; p->get_X(&dX); return dX; }
	double GetCenterY() { double dY; p->get_Y(&dY); return dY; }
	double GetAngle() { double dAngle; p->get_Rotation(&dAngle); return dAngle; }
	bool SetInterectiveRegion() {
		if (FAILED(p->put_GraphicDOFEnable(cogLineDOFAll))) return false;
		//if (FAILED(p->put_Adornment(CogLineAdornmentConstants::(cogRectangleAffineDirectionAdornmentSolidArrow))) return false;
		//if (FAILED(p->put_YDirectionAdornment(cogRectangleAffineDirectionAdornmentArrow))) return false;
		if (FAILED(p->put_Interactive(VARIANT_TRUE))) return false;
		return SUCCEEDED(p->put_SelectedSpaceName(CComBSTR("#")));
	}
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogLine>::Release();
	}
	void Create() { 
		Release();
		CoCreateInstance(CLSID_CogLine);
	}
	bool Create(long __nWidth, CogColorConstants __Color, double __dCenterX, double __dCenterY, double __dAngle) {
		Release();
		HRESULT Result = CoCreateInstance(CLSID_CogLine);
		if (FAILED( Result )) return false;
		Result = p->put_LineWidthInScreenPixels(__nWidth);
		if (FAILED( Result )) return false;
		Result = p->put_Color(__Color);
		if (FAILED( Result )) return false;
		Result = p->SetXYRotation(__dCenterX, __dCenterY, __dAngle);
		return SUCCEEDED( Result );
	}
	bool SetLine(double __dCenterX, double __dCenterY, double __dRotation) {
		if (p == NULL) Create();
		SetInterectiveRegion();
		return SUCCEEDED( p->SetXYRotation(__dCenterX, __dCenterY, __dRotation) );
	}
	bool SetLine(double __dPos1X, double __dPos1Y, double __dPos2X, double __dPos2Y) {
		return SUCCEEDED( p->SetFromStartXYEndXY(__dPos1X, __dPos1Y, __dPos2X, __dPos2Y) );
	}
	bool SetLine(CMNV_STPoint &__stP1, CMNV_STPoint &__stP2) {
		return SUCCEEDED( p->SetFromStartXYEndXY(__stP1.m_dX, __stP1.m_dY, __stP2.m_dX, __stP2.m_dY) );
	}
	bool SetLine(CMNVLineSegment & __pLineSegment) {
		return SUCCEEDED( p->SetFromLineSegment(__pLineSegment) );
	}
};