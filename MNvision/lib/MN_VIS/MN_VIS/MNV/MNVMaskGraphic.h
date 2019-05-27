#pragma once
#include "Define_Cog.h"

class CMNVMaskGraphic : public CComPtr<ICogMaskGraphic> {
public:
	bool Create() { Release(); return SUCCEEDED(CoCreateInstance(CLSID_CogMaskGraphic)); }
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogMaskGraphic>::Release();
	}
public:
	CMNVMaskGraphic() { Create(); }
	~CMNVMaskGraphic() { Release(); }
	bool SetImage(CMNVImage8Grey & __Image) {
		Create();
		return SUCCEEDED(p->putref_Image(__Image));
	}
};
