#pragma once
#include "MNVCogClass.h"

#define BLOB_POLARITY		CogBlobSegmentationPolarityConstants
#define BLOB_PLR_DARK		cogBlobSegmentationPolarityDarkBlobs
#define BLOB_PLR_LIGHT		cogBlobSegmentationPolarityLightBlobs

#define BLOB_MODE			CogBlobSegmentationModeConstants
#define BLOB_MODE_NONE		cogBlobSegmentationModeNone
#define BLOB_MODE_MAP		cogBlobSegmentationModeMap
#define BLOB_MODE_HFIXED	cogBlobSegmentationModeHardFixedThreshold
#define BLOB_MODE_HRELATIVE	cogBlobSegmentationModeHardRelativeThreshold
#define BLOB_MODE_HDYNAMIC	cogBlobSegmentationModeHardDynamicThreshold
#define BLOB_MODE_SFIXED	cogBlobSegmentationModeSoftFixedThreshold
#define BLOB_MODE_SRELATIVE	cogBlobSegmentationModeSoftRelativeThreshold
#define BLOB_MODE_SUBIMAGE	cogBlobSegmentationModeSubtractionImage

class CMNVBlobResult : public CComPtr<ICogBlobResult> {
public:
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogBlobResult>::Release();
	}
	CMNVBlobResult() : CComPtr<ICogBlobResult>() {}
	~CMNVBlobResult() { Release(); }
	void Create() { CoCreateInstance(CLSID_CogBlobResult); }

	HRESULT GetCenter(double & __dCenterX, double & __dCenterY) {
		HRESULT Result = (p == NULL) ? E_FAIL : S_OK;
		if(SUCCEEDED( Result )) Result = p->get_CenterOfMassX(&__dCenterX);
		if(SUCCEEDED( Result )) Result = p->get_CenterOfMassY(&__dCenterY);
		return Result;
	}
	bool GetCenter(CMNV_STPoint & __stCenter) {
		if (p == NULL) return false;
		__stCenter.m_dR = 0;
		if(FAILED( p->get_CenterOfMassX(&__stCenter.m_dX) )) return false;
		if(FAILED( p->get_CenterOfMassY(&__stCenter.m_dY) )) return false;
		return true;
	}
};
class CMNVBlobResultCollection : public CComPtr<ICogBlobResultCollection> {
public:
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogBlobResultCollection>::Release();
	}
	CMNVBlobResultCollection() : CComPtr<ICogBlobResultCollection>() {}
	~CMNVBlobResultCollection() { Release(); }
	void Create() { CoCreateInstance(CLSID_CogBlobResultCollection); }
};
class CMNVBlobResults : public CComPtr<ICogBlobResults> {
	CMNVBlobResultCollection m_pCollection;
public:
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogBlobResults>::Release();
	}
	CMNVBlobResults() : CComPtr<ICogBlobResults>() {}
	~CMNVBlobResults() { Release(); }
	void Create() { CoCreateInstance(CLSID_CogBlobResults); }
	HRESULT SetResult() { p->get_Blobs(VARIANT_TRUE, &m_pCollection); }
};
struct MNVSTBlobNone {
	long nScale;
};
struct MNVSTBlobMap {
	SAFEARRAY arMap;
	long nScale;
};
struct MNVSTBlobHardFixed {
	long nThreshold;
};
struct MNVSTBlobHardRelative {
	long nThreshold;
	long nTailLow;
	long nTailHigh;
};
struct MNVSTBlobHardDynamic {
	long nTailLow;
	long nTailHigh;
};
struct MNVSTBlobSoftFixed {
	long nThresholdLow;
	long nThresholdHigh;
	long nSoftness;
};
struct MNVSTBlobSoftRelative {
	long nThresholdLow;
	long nThresholdHigh;
	long nTailLow;
	long nTailHigh;
	long nSoftness;
};
struct MNVSTBlobSubtractionImg {
	SAFEARRAY arPreMap;
	SAFEARRAY arPostMap;
	long nScale;
};
union MNVSTBlobParam {
	MNVSTBlobNone	stNone;
	MNVSTBlobMap	stMap;
	MNVSTBlobHardFixed stHFixed;
	MNVSTBlobHardRelative stHRelative;
	MNVSTBlobHardDynamic stHDynamic;
	MNVSTBlobSoftFixed stSFixed;
	MNVSTBlobSoftRelative stSRelative;
	MNVSTBlobSubtractionImg stSubImg;
};
typedef long Threshold;	// unsigned byte (with softness)
typedef __int32 Scale;	// unsigned byte 
typedef __int16 Tail;	// Percent
// Map Input(0~255) => Output(0~255)

//class CMNVBlobParameter {
//	CogBlobSegmentationPolarityConstants	m_Polarity;
//	CogBlobSegmentationModeConstants		m_Mode;
//	MNVSTBlobParam	m_Param;
//public:
//	CMNVBlobParameter() {
//		m_Polarity = BLOB_PLR_DARK;
//		m_Mode = BLOB_MODE_NONE;
//	}
//	CMNVBlobParameter(Threshold __Threshold) {}
//	CMNVBlobParameter(Scale __Scale) {}
//	CMNVBlobParameter(Tail __Tail) {}
//
//	CMNVBlobParameter(BLOB_POLARITY __Polarity, MNVSTBlobNone & __stBlobPara) {
//		m_Polarity = __Polarity;
//		m_Mode = BLOB_MODE_NONE;
//		m_Param.stNone.nScale = __stBlobPara.nScale;
//	}
//	CMNVBlobParameter(BLOB_POLARITY __Polarity, MNVSTBlobMap & __stBlobPara) {
//		m_Polarity = __Polarity;
//		m_Mode = BLOB_MODE_MAP;
//		m_Param.stMap.arMap = __stBlobPara.arMap;
//		m_Param.stMap.nScale = __stBlobPara.nScale;
//	}
//	CMNVBlobParameter(BLOB_POLARITY __Polarity, MNVSTBlobHardFixed & __stBlobPara) {
//		m_Polarity = __Polarity;
//		m_Mode = BLOB_MODE_HFIXED;
//		m_Param.stHFixed.nThreshold = __stBlobPara.nThreshold;
//	}
//	CMNVBlobParameter(BLOB_POLARITY __Polarity, MNVSTBlobHardRelative & __stBlobPara) {
//		m_Polarity = __Polarity;
//		m_Mode = BLOB_MODE_HRELATIVE;
//		m_Param.stHRelative.nThreshold = __stBlobPara.nThreshold;
//		m_Param.stHRelative.nTailLow = __stBlobPara.nTailLow;
//		m_Param.stHRelative.nTailHigh = __stBlobPara.nTailHigh;
//	}
//	CMNVBlobParameter(BLOB_POLARITY __Polarity, MNVSTBlobHardDynamic & __stBlobPara) {
//		m_Polarity = __Polarity;
//		m_Mode = BLOB_MODE_HDYNAMIC;
//		m_Param.stHRelative.nTailLow = __stBlobPara.nTailLow;
//		m_Param.stHRelative.nTailHigh = __stBlobPara.nTailHigh;
//	}
//	CMNVBlobParameter(BLOB_POLARITY __Polarity, MNVSTBlobSoftFixed & __stBlobPara) {
//		m_Polarity = __Polarity;
//		m_Mode = BLOB_MODE_SFIXED;
//		m_Param.stSFixed.nThresholdLow = __stBlobPara.nThresholdLow;
//		m_Param.stSFixed.nThresholdHigh = __stBlobPara.nThresholdHigh;
//		m_Param.stSFixed.nSoftness = __stBlobPara.nSoftness;
//	}
//	CMNVBlobParameter(BLOB_POLARITY __Polarity, MNVSTBlobSoftRelative & __stBlobPara) {
//		m_Polarity = __Polarity;
//		m_Mode = BLOB_MODE_SRELATIVE;
//		m_Param.stSRelative.nThresholdLow = __stBlobPara.nThresholdLow;
//		m_Param.stSRelative.nThresholdHigh = __stBlobPara.nThresholdHigh;
//		m_Param.stSRelative.nTailLow = __stBlobPara.nTailLow;
//		m_Param.stSRelative.nTailHigh = __stBlobPara.nTailHigh;
//		m_Param.stSRelative.nSoftness = __stBlobPara.nSoftness;
//	}
//	CMNVBlobParameter(BLOB_POLARITY __Polarity, MNVSTBlobSubtractionImg & __stBlobPara) {
//		m_Polarity = __Polarity;
//		m_Mode = BLOB_MODE_SUBIMAGE;
//		m_Param.stSubImg.arPreMap = __stBlobPara.arPreMap;
//		m_Param.stSubImg.arPostMap = __stBlobPara.arPostMap;
//		m_Param.stSubImg.nScale = __stBlobPara.nScale;
//	}
//};
#ifdef COGNEX_USB
#define ICOG_BLOB ICogEdgeBlob
#define CLSID_COGBLOB CLSID_CogEdgeBlob
#else
#define ICOG_BLOB ICogBlob
#define CLSID_COGBLOB CLSID_CogBlob
#endif

class CMNVBlob : public CComPtr<ICOG_BLOB>
{
	CMNVBlobSegParams	m_pSegParams;
	CMNVBlobResults		m_pResults;
	CMNVBlobResultCollection m_pRCollection;
public:
	void Release() {
		
		m_pResults.Release();
		m_pRCollection.Release();

		if (p != NULL) Detach()->Release();
		CComPtr<ICOG_BLOB>::Release();
	}
	CMNVBlob() : CComPtr<ICOG_BLOB>() { }
	~CMNVBlob() { Release(); }
	HRESULT Create() {
		HRESULT Result = CoCreateInstance(CLSID_COGBLOB);
		if(SUCCEEDED(Result)) Result = p->get_SegmentationParams(&m_pSegParams);
		return Result;
	}
	HRESULT SetDarkBlob() { return m_pSegParams->put_Polarity(cogBlobSegmentationPolarityDarkBlobs); }
	HRESULT SetLightBlob() { return m_pSegParams->put_Polarity(cogBlobSegmentationPolarityLightBlobs); }

	HRESULT SetModeNone(long __nScale) {
		HRESULT Result = m_pSegParams->put_Mode(cogBlobSegmentationModeNone);
		if (SUCCEEDED(Result)) Result = m_pSegParams->put_ScalingValue(__nScale);
		return Result;
	}
	HRESULT SetModeMap(SAFEARRAY ** __pMap, long __nScale) {
		HRESULT Result = m_pSegParams->put_Mode(cogBlobSegmentationModeMap);
		if (SUCCEEDED(Result)) Result = m_pSegParams->put_Map(__pMap);
		if (SUCCEEDED(Result)) Result = m_pSegParams->put_ScalingValue(__nScale);
		
		return Result;
	}
	HRESULT SetModeHardFixedThreshold(long __nThreshold) {
		HRESULT Result = m_pSegParams->put_Mode(cogBlobSegmentationModeHardFixedThreshold);
		if (SUCCEEDED(Result)) Result = m_pSegParams->put_HardFixedThreshold(__nThreshold);
		return Result;
	}
	HRESULT	SetModeHardRelativeThreshold(long __nThreshold, long __nTailLow, long __nTailHigh) {
		HRESULT Result = m_pSegParams->put_Mode(cogBlobSegmentationModeHardRelativeThreshold);
		if (SUCCEEDED(Result)) Result = m_pSegParams->put_HardRelativeThreshold(__nThreshold);
		if (SUCCEEDED(Result)) Result = m_pSegParams->put_TailLow(__nTailLow);
		if (SUCCEEDED(Result)) Result = m_pSegParams->put_TailHigh(__nTailHigh);
		return Result;
	}
	HRESULT SetModeHardDynamicThreshold(long __nTailLow, long __nTailHigh) {
		HRESULT Result = m_pSegParams->put_Mode(cogBlobSegmentationModeHardDynamicThreshold);
		if (SUCCEEDED(Result)) Result = m_pSegParams->put_TailLow(__nTailLow);
		if (SUCCEEDED(Result)) Result = m_pSegParams->put_TailHigh(__nTailHigh);
		return Result;
	}
	HRESULT SetModeSoftFixedThreshold(long __nThresholdLow, long __nThresholdHigh, long __nSoftness) {
		HRESULT Result = m_pSegParams->put_Mode(cogBlobSegmentationModeSoftFixedThreshold);
		if (SUCCEEDED(Result)) Result = m_pSegParams->put_SoftFixedThresholdLow(__nThresholdLow);
		if (SUCCEEDED(Result)) Result = m_pSegParams->put_SoftFixedThresholdHigh(__nThresholdHigh);
		if (SUCCEEDED(Result)) Result = m_pSegParams->put_Softness(__nSoftness);
		return Result;
	}
	HRESULT SetModeSoftRelativeThreshold(long __nThresholdLow, long __nThresholdHigh, long __nTailLow, long __nTailHigh, long __nSoftness) {
		HRESULT Result = m_pSegParams->put_Mode(cogBlobSegmentationModeSoftRelativeThreshold);
		if (SUCCEEDED(Result)) Result = m_pSegParams->put_SoftRelativeThresholdLow(__nThresholdLow);
		if (SUCCEEDED(Result)) Result = m_pSegParams->put_SoftRelativeThresholdHigh(__nThresholdHigh);
		if (SUCCEEDED(Result)) Result = m_pSegParams->put_TailLow(__nTailLow);
		if (SUCCEEDED(Result)) Result = m_pSegParams->put_TailHigh(__nTailHigh);
		if (SUCCEEDED(Result)) Result = m_pSegParams->put_Softness(__nSoftness);
		return Result;
	}
	HRESULT SetModeSubtractionImage(SAFEARRAY ** __pPreMap, SAFEARRAY ** __pPostMap, long __nScale) {
		HRESULT Result = m_pSegParams->put_Mode(cogBlobSegmentationModeSubtractionImage);
		if (SUCCEEDED(Result)) Result = m_pSegParams->put_PreMap(__pPreMap);
		if (SUCCEEDED(Result)) Result = m_pSegParams->put_PostMap(__pPostMap);
		if (SUCCEEDED(Result)) Result = m_pSegParams->put_ScalingValue(__nScale);
		return Result;
	}

	//HRESULT SetArea(double __dx, double __dy, double __dWidth, double __dHeight) {
	//	CMNVRectangle pRect(__dx, __dy, __dWidth, __dHeight);
	//	CMNVRegion pRegion(pRect);
	//}
	HRESULT Execute(CMNVImage8Grey & __pInputImage, CMNVRectangle __Rect) {
		HRESULT Result = p->Execute(__pInputImage, __Rect.GetRegion(), &m_pResults);
		if(SUCCEEDED( Result )) Result = m_pResults->get_Blobs(VARIANT_TRUE, &m_pRCollection);
		return Result;
	}
	HRESULT Execute(CMNVImage8Grey & __pInputImage, CMNVRectangleAffine __Rect) {
		HRESULT Result = p->Execute(__pInputImage, __Rect.GetRegion(), &m_pResults);
		if(SUCCEEDED( Result )) Result = m_pResults->get_Blobs(VARIANT_TRUE, &m_pRCollection);
		return Result;
	}
	HRESULT Execute(CMNVImage8Grey & __pInputImage, double __dx, double __dy, double __dWidth, double __dHeight) {
		CMNVRectangle pRect(__dx, __dy, __dWidth, __dHeight);
		HRESULT Result = p->Execute(__pInputImage, pRect.GetRegion(), &m_pResults);
		if(SUCCEEDED( Result )) Result = m_pResults->get_Blobs(VARIANT_TRUE, &m_pRCollection);
		return Result;
	}
	HRESULT ExecuteCenter(CMNVImage8Grey & __pInputImage, double __dx, double __dy, double __dWidth, double __dHeight) {
		CMNVRectangle pRect;
		pRect.SetRectCenter(__dx, __dy, __dWidth, __dHeight);
		HRESULT Result = p->Execute(__pInputImage, pRect.GetRegion(), &m_pResults);
		if(SUCCEEDED( Result )) Result = m_pResults->get_Blobs(VARIANT_TRUE, &m_pRCollection);
		return Result;
	}
	long GetBlobCount() { 
		long lValue = -1;
		if (m_pRCollection != NULL && SUCCEEDED( m_pRCollection->get_Count(&lValue) )) { return lValue; }
		else return -1;
	}
	HRESULT GetCenterXY(long __nIndex, double & __dX, double & __dY) {
		HRESULT Result = E_FAIL;
		long nBlobCnt = GetBlobCount();
		if (__nIndex < 0 || __nIndex >= nBlobCnt) return Result;

		CMNVBlobResult pResult;
		Result = m_pRCollection->get_Item(__nIndex, &pResult);
		if (SUCCEEDED( Result )) Result = pResult.GetCenter(__dX, __dY);
		return Result;
	}
	HRESULT GetBlobRect(long __nIndex, CMNVRectangle & __MNVRect) {
		HRESULT Result = E_FAIL;
		long nBlobCnt = GetBlobCount();
		if (__nIndex < 0 || __nIndex >= nBlobCnt) return Result;

		CMNVBlobResult pResult;
		CComPtr<ICogRectangleAffine> RectAffine;
		Result = m_pRCollection->get_Item(__nIndex, &pResult);
		if (SUCCEEDED( Result )) Result = pResult->GetBoundingBox(cogBlobAxisExtremaAngle, &RectAffine);
		if (SUCCEEDED( Result )) {
			double dx, dy, dw, dh;
			RectAffine->get_CenterX(&dx);
			RectAffine->get_CenterY(&dx);
			RectAffine->get_SideXLength(&dx);
			RectAffine->get_SideYLength(&dx);
			RectAffine->get_Area(&dx);
			RectAffine.Detach()->Release();
			RectAffine.Release();
			__MNVRect.SetRectXY(dx, dy, dw, dh);
		}
		return Result;
	}
	HRESULT GetBlobResult(long __nIndex, CMNVRectangle & __MNVRect, double & __dArea) {
		HRESULT Result = E_FAIL;
		long nBlobCnt = GetBlobCount();
		if (__nIndex < 0 || __nIndex >= nBlobCnt) return Result;

		CMNVBlobResult pResult;
		CComPtr<ICogRectangleAffine> RectAffine;
		Result = m_pRCollection->get_Item(__nIndex, &pResult);
		if (SUCCEEDED( Result )) Result = pResult->get_Area(&__dArea);
		if (SUCCEEDED( Result )) Result = pResult->GetBoundingBox(cogBlobAxisExtremaAngle, &RectAffine);
		if (SUCCEEDED( Result )) {
			double dx=0, dy=0, dw=0, dh=0;
			RectAffine->get_CenterX(&dx);
			RectAffine->get_CenterY(&dy);
			RectAffine->get_SideXLength(&dw);
			RectAffine->get_SideYLength(&dh);
			//RectAffine->get_Area(&__dArea);
			if (__MNVRect == NULL) __MNVRect.Create();
			__MNVRect.SetRectCenter(dx, dy, dw, dh);
		}
		if (RectAffine != NULL) {
			RectAffine.Detach()->Release();
		}
		return Result;
	}
	HRESULT GetBlobResult(long __nIndex, double & __dArea) {
		HRESULT Result = E_FAIL;
		long nBlobCnt = GetBlobCount();
		if (__nIndex < 0 || __nIndex >= nBlobCnt) return Result;

		CMNVBlobResult pResult;
		Result = m_pRCollection->get_Item(__nIndex, &pResult);
		if (SUCCEEDED( Result )) Result = pResult->get_Area(&__dArea);
		return Result;
	}
};


//	CComQIPtr<ICogBlob> d();
//	CComQIPtr<ICogBlob> d(ICodBlob * lp);
//	CComQIPtr<ICogBlob> d(IUnknown * lp);
//	CComQIPtr<ICogBlob> d(const ATL::CComQIPtr<ICogBlob, & __uuidof(ICogBlob)> &lp);
//
//	CComPtr<ICogBlob> d();
//	CComPtr<ICogBlob> d(ICogBlob * lp);
//	CComPtr<ICogBlob> d(ATL::CComPtr(ICogBlob) &&lp);
//	CComPtr<ICogBlob> d(const ATL::CComPtr(ICogBlob) &lp);

//class Temp {
//public:
//	void TestComPtr () {
//		CComPtr<ICogImage> Image;
//		CComPtr<ICogImage24PlanarColor> Image2;
//
//		CComQIPtr<ICogImage> Image3(Image2);
//		CComQIPtr<ICogImage24PlanarColor> Image4(Image);
//		CComPtr<ICogImage> Image5;
//		Image5.CoCreateInstance(CLSID_CogImage);
//		Image5.QueryInterface(&Image2);
//	}
//};
