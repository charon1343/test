#pragma once
#include "MNVCogClass.h"

class CMNVRegion : public CComQIPtr<ICogRegion> {
public:
	void Release() {
		if (p != NULL) Detach()->Release();
		CComQIPtr<ICogRegion>::Release();
	}
	CMNVRegion() : CComQIPtr<ICogRegion>() { }
	CMNVRegion(ICogRegion * __lp) : CComQIPtr<ICogRegion>(__lp) { }
	CMNVRegion(IUnknown * __lp) : CComQIPtr<ICogRegion>(__lp) { }
	CMNVRegion(CComQIPtr<ICogRegion> __lp) : CComQIPtr<ICogRegion>(__lp) { }
	~CMNVRegion() { Release(); }
};