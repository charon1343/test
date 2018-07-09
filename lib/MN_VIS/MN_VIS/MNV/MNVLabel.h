#pragma once
#include "MNVObject.h"

class CMNVLabel : public CComPtr<ICogGraphicLabel> {
public:
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogGraphicLabel>::Release();
	}
	CMNVLabel() : CComPtr<ICogGraphicLabel>() {}
	~CMNVLabel() { Release(); }
	HRESULT Create() { return CoCreateInstance(CLSID_CogGraphicLabel); }
	HRESULT Create(double __dX, double __dY, LPCTSTR __lpText ) {
		HRESULT Result = CoCreateInstance(CLSID_CogGraphicLabel);
		if(SUCCEEDED( Result )) Result = p->SetXYText(__dX, __dY, CComBSTR(__lpText));
		return Result;
	}
	HRESULT SetXYText(double __dX, double __dY, LPCTSTR __lpText ) { return p->SetXYText(__dX, __dY, CComBSTR(__lpText)); }

	bool SetFont(double __dFontSize, int __nWeight) {
		CY cy;
		CComPtr<IFontDisp> FontDisp;
		p->get_Font(&FontDisp);
		CComQIPtr<IFont> Font(FontDisp);
		Font->get_Size(&cy);
		cy.int64 = (LONGLONG)(__dFontSize * cy.int64);
		Font->put_Size(cy);
		Font->put_Name(CComBSTR("¸¼Àº °íµñ"));
		//Font->put_Bold(TRUE);
		Font->put_Weight(__nWeight);
		p->put_Font(FontDisp);
		return true;
	}
};
