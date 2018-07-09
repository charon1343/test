#pragma once
#include "Define_Cog.h"

class CMNVGraphic : public CComQIPtr<ICogGraphic> {
public:
	void Release() {
		if (p != NULL) Detach()->Release();
		CComQIPtr<ICogGraphic>::Release();
	}
	CMNVGraphic() : CComQIPtr<ICogGraphic>() {}
	//CMNVGraphic(CMNVLineSegment & __pLineSegment) : CComQIPtr<ICogGraphic>(__pLineSegment) {}
	//CMNVGraphic(CMNVLabel & __pLabel) : CComQIPtr<ICogGraphic>(__pLabel) {}
	CMNVGraphic(IUnknown * __pSegment) : CComQIPtr<ICogGraphic>(__pSegment) {}
	~CMNVGraphic() { Release(); }
};
