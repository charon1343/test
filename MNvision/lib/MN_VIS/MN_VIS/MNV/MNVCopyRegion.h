#pragma once
#include "Define_Cog.h"

class CMNVCopyRegion : public CComPtr<ICogCopyRegion> {
public:
	bool Create() {
		Release();
		return SUCCEEDED( CoCreateInstance(CLSID_CogCopyRegion) );
	}
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogCopyRegion>::Release();
	}
public:
	CMNVCopyRegion(bool __isCreate = true) : CComPtr<ICogCopyRegion>() {
		if (__isCreate) Create();
	}
	~CMNVCopyRegion() {}

	//bool Excute(CMNVImage8Grey & __imgSour, CMNVRegion & __regSour, CMNVImage8Grey & __imgDest, CMNVRegion & __regDest) {
	//	CMNVImage pImg;
	//	VARIANT_BOOL bSourceClipped, bDestinationClipped;
	//	if (FAILED( p->put_RegionMode(cogRegionModeAffineTransform) )) return false;
	//	if (FAILED( p->Execute(__imgSour, __regSour, __imgDest, &bSourceClipped, &bDestinationClipped, &__regDest, &pImg) )) return false;
	//	pImg.Copy(__imgDest);
	//	return true;
	//}
};
