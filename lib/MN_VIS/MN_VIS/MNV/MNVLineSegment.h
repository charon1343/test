#pragma once
#include "Define_Cog.h"

class CMNVLineSegment : public CComPtr<ICogLineSegment> {
public:
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogLineSegment>::Release();
	}
	CMNVLineSegment(bool __isCreate = true) : CComPtr<ICogLineSegment>() { if (__isCreate) Create(); }
	CMNVLineSegment(CMNV_STPoint & __stPointA, CMNV_STPoint & __stPointB) : CComPtr<ICogLineSegment>() {
		Create();
		SetLine(__stPointA, __stPointB);
	}
	
	~CMNVLineSegment() { Release(); }
	void Create() { CoCreateInstance(CLSID_CogLineSegment); }
	HRESULT Create(long __nWidth, CogColorConstants __Color, double __dStartX, double __dStartY, double __dEndX, double __dEndY) {
		Release();
		HRESULT Result = CoCreateInstance(CLSID_CogLineSegment);
		if (FAILED( Result )) return Result;
		Result = p->put_LineWidthInScreenPixels(__nWidth);
		if (FAILED( Result )) return Result;
		Result = p->put_Color(__Color);
		if (FAILED( Result )) return Result;
		Result = p->SetStartEnd(__dStartX, __dStartY, __dEndX, __dEndY);
		return Result;
	}
	bool SetInterectiveRegion() {
		if (FAILED(p->put_GraphicDOFEnable(cogLineSegmentDOFAll))) return false;
		//if (FAILED(p->put_Adornment(CogLineAdornmentConstants::(cogRectangleAffineDirectionAdornmentSolidArrow))) return false;
		//if (FAILED(p->put_YDirectionAdornment(cogRectangleAffineDirectionAdornmentArrow))) return false;
		if (FAILED(p->put_Interactive(VARIANT_TRUE))) return false;
		return SUCCEEDED(p->put_SelectedSpaceName(CComBSTR("#")));
	}

	bool SetLine(CMNV_STPoint &__stP1, CMNV_STPoint &__stP2) {
		if (p == NULL) return false;
		return SUCCEEDED( p->SetStartEnd(__stP1.m_dX, __stP1.m_dY, __stP2.m_dX, __stP2.m_dY) );
	}
};
