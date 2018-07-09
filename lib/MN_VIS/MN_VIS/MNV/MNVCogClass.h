#pragma once
#include "MNVImage.h"
#include "MNVLabel.h"
//#include "MNVRectangle.h"
//#include "MNVRectangleAffine.h"

enum MNVDisplayMode { MNVDM_None = 0, MNVDM_Image, MNVDM_Teaching, MNVDM_Result, MNVDM_Edit };
enum MNVDisplayPlane {MNVDP_None = 0, MNVDP_Red, MNVDP_Green, MNVDP_Blue };

class CMNVBlobSegParams : public CComPtr<ICogBlobSegmentationParams> {
public:
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogBlobSegmentationParams>::Release();
	}
	CMNVBlobSegParams() : CComPtr<ICogBlobSegmentationParams>() { }
	~CMNVBlobSegParams() { Release(); }

	HRESULT SetDarkBlob() { return p->put_Polarity(cogBlobSegmentationPolarityDarkBlobs); }
	HRESULT SetLightBlob() { return p->put_Polarity(cogBlobSegmentationPolarityLightBlobs); }

	HRESULT SetModeNone(long __nScale) {
		HRESULT Result = p->put_Mode(cogBlobSegmentationModeNone);
		if (SUCCEEDED(Result)) Result = p->put_ScalingValue(__nScale);
		return Result;
	}
	HRESULT SetModeMap(SAFEARRAY ** __pMap, long __nScale) {
		HRESULT Result = p->put_Mode(cogBlobSegmentationModeMap);
		if (SUCCEEDED(Result)) Result = p->put_Map(__pMap);
		if (SUCCEEDED(Result)) Result = p->put_ScalingValue(__nScale);
		return Result;
	}
	HRESULT SetModeHardFixedThreshold(long __nThreshold) {
		HRESULT Result = p->put_Mode(cogBlobSegmentationModeHardFixedThreshold);
		if (SUCCEEDED(Result)) Result = p->put_HardFixedThreshold(__nThreshold);
		return Result;
	}
	HRESULT	SetModeHardRelativeThreshold(long __nThreshold, long __nTailLow, long __nTailHigh) {
		HRESULT Result = p->put_Mode(cogBlobSegmentationModeHardRelativeThreshold);
		if (SUCCEEDED(Result)) Result = p->put_HardRelativeThreshold(__nThreshold);
		if (SUCCEEDED(Result)) Result = p->put_TailLow(__nTailLow);
		if (SUCCEEDED(Result)) Result = p->put_TailHigh(__nTailHigh);
		return Result;
	}
	HRESULT SetModeHardDynamicThreshold(long __nTailLow, long __nTailHigh) {
		HRESULT Result = p->put_Mode(cogBlobSegmentationModeHardDynamicThreshold);
		if (SUCCEEDED(Result)) Result = p->put_TailLow(__nTailLow);
		if (SUCCEEDED(Result)) Result = p->put_TailHigh(__nTailHigh);
		return Result;
	}
	HRESULT SetModeSoftFixedThreshold(long __nThresholdLow, long __nThresholdHigh, long __nSoftness) {
		HRESULT Result = p->put_Mode(cogBlobSegmentationModeSoftFixedThreshold);
		if (SUCCEEDED(Result)) Result = p->put_SoftFixedThresholdLow(__nThresholdLow);
		if (SUCCEEDED(Result)) Result = p->put_SoftFixedThresholdHigh(__nThresholdHigh);
		if (SUCCEEDED(Result)) Result = p->put_Softness(__nSoftness);
		return Result;
	}
	HRESULT SetModeSoftRelativeThreshold(long __nThresholdLow, long __nThresholdHigh, long __nTailLow, long __nTailHigh, long __nSoftness) {
		HRESULT Result = p->put_Mode(cogBlobSegmentationModeSoftRelativeThreshold);
		if (SUCCEEDED(Result)) Result = p->put_SoftRelativeThresholdLow(__nThresholdLow);
		if (SUCCEEDED(Result)) Result = p->put_SoftRelativeThresholdHigh(__nThresholdHigh);
		if (SUCCEEDED(Result)) Result = p->put_TailLow(__nTailLow);
		if (SUCCEEDED(Result)) Result = p->put_TailHigh(__nTailHigh);
		if (SUCCEEDED(Result)) Result = p->put_Softness(__nSoftness);
		return Result;
	}
	HRESULT SetModeSubtractionImage(SAFEARRAY ** __pPreMap, SAFEARRAY ** __pPostMap, long __nScale) {
		HRESULT Result = p->put_Mode(cogBlobSegmentationModeSubtractionImage);
		if (SUCCEEDED(Result)) Result = p->put_PreMap(__pPreMap);
		if (SUCCEEDED(Result)) Result = p->put_PostMap(__pPostMap);
		if (SUCCEEDED(Result)) Result = p->put_ScalingValue(__nScale);
		return Result;
	}
};
