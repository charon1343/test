#pragma once
#include "MNVPLC.h"

#include "LightControl\CMNV_LFineControl.h"
#include "MFC\MNVDevice.h"
#include "MNV\CamInfo.h"
#include "MNV\MNVLock.h"
#include "MNV\MNVImage.h"

#include "MNV/MNVPMAlign.h"
#include "MNV/Algorithm_PolarUnwrapCaliper.h"
#include "MNV/Algorithm_AffineTransformCaliper.h"
#include "MNV\MNVHistogram.h"
class SourceID {
	int m_nID;
public:
	int GetID() { return m_nID; }
	int SetID(int __Model, int __Item, int __Vision, int __Channel, int __Grab) {
		m_nID = ((__Model & 0x0f) << 24) | ((__Item & 0x0f) << 20) | ((__Vision & 0x0f) << 16) | ((__Channel & 0x0f) << 12) | ((__Grab & 0x00fff));
		return m_nID;
	}
	int GetID(int & __Model, int & __Item, int & __Vision, int & __Channel, int & __Grab) {
		__Model = (m_nID >> 24) & 0x0f;
		__Item = (m_nID >> 20) & 0x0f;
		__Vision = (m_nID >> 16) & 0x0f;
		__Channel = (m_nID >> 12) & 0x0f;
		__Grab = m_nID & 0x0fff;
		return m_nID;
	}
	int ChangeID(int __Model, int __Item, int __Vision) {
		m_nID = ((__Model & 0x0f) << 24) | ((__Item & 0x0f) << 20) | ((__Vision & 0x0f) << 16) | (m_nID & 0x0ffff);
		return m_nID;
	}
	operator int() { return m_nID; }
};

class CMNVBlob_Segmentation : public CComPtr<ICogBlobSegmentationParams> {
public:
	bool Create() { Release(); return SUCCEEDED( CoCreateInstance(CLSID_CogBlobSegmentationParams) ); }
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogBlobSegmentationParams>::Release();
	}
public:
	CMNVBlob_Segmentation(bool __isCreate = true) : CComPtr<ICogBlobSegmentationParams>() { if (__isCreate) Create(); }
	~CMNVBlob_Segmentation() { Release(); }

	void SaveIni(LPCTSTR __strFile, LPCTSTR __strSection) {
		CogBlobSegmentationModeConstants cdSegmentation = (CogBlobSegmentationModeConstants) CMNVIni::GetValue(__strSection, _T("Segmentation"), (int)cogBlobSegmentationModeHardRelativeThreshold, __strFile);
		long nTailLow = CMNVIni::GetValue(__strSection, _T("TailLow"), (int)0, __strFile);
		long nTailHigh = CMNVIni::GetValue(__strSection, _T("TailHigh"), (int)0, __strFile);
		long nThresholdLow = CMNVIni::GetValue(__strSection, _T("Threshold(Low)"), (int)0, __strFile);
		long nThresholdHigh = CMNVIni::GetValue(__strSection, _T("ThresholdHigh"), (int)0, __strFile);
		long nSoftness = CMNVIni::GetValue(__strSection, _T("Softness"), (int)0, __strFile);
		CogBlobSegmentationPolarityConstants cdPolarity = (CogBlobSegmentationPolarityConstants) CMNVIni::GetValue(__strSection, _T("Polarity"), (int)cogBlobSegmentationPolarityDarkBlobs, __strFile);
		//CogBlobSegmentationPolarityConstants::cogBlobSegmentationPolarityDarkBlobs = 0;
		//CogBlobSegmentationPolarityConstants::cogBlobSegmentationPolarityLightBlobs = 1;
	}
	bool Prepare(LPCTSTR __strFile, LPCTSTR __strSection) {
		if (p == NULL && !Create()) return false;

		CogBlobSegmentationModeConstants cdSegmentation = (CogBlobSegmentationModeConstants) CMNVIni::GetValue(__strSection, _T("Segmentation"), (int)cogBlobSegmentationModeHardRelativeThreshold, __strFile);
		long nTailLow = CMNVIni::GetValue(__strSection, _T("TailLow"), (int)0, __strFile);
		long nTailHigh = CMNVIni::GetValue(__strSection, _T("TailHigh"), (int)0, __strFile);
		long nThresholdLow = CMNVIni::GetValue(__strSection, _T("Threshold(Low)"), (int)0, __strFile);
		long nThresholdHigh = CMNVIni::GetValue(__strSection, _T("ThresholdHigh"), (int)0, __strFile);
		long nSoftness = CMNVIni::GetValue(__strSection, _T("Softness"), (int)0, __strFile);
		CogBlobSegmentationPolarityConstants cdPolarity = (CogBlobSegmentationPolarityConstants) CMNVIni::GetValue(__strSection, _T("Polarity"), (int)cogBlobSegmentationPolarityDarkBlobs, __strFile);

		if (FAILED( p->put_Mode(cdSegmentation) )) return false;
		CMNVIni::SetValue(__strSection, _T("Segmentation"), (int)cdSegmentation, __strFile);
		CMNVIni::SetValue(__strSection, _T("TailLow"), (int)nTailLow, __strFile);
		CMNVIni::SetValue(__strSection, _T("TailHigh"), (int)nTailHigh, __strFile);
		CMNVIni::SetValue(__strSection, _T("Threshold(Low)"), (int)nThresholdLow, __strFile);
		CMNVIni::SetValue(__strSection, _T("ThresholdHigh"), (int)nThresholdHigh, __strFile);
		CMNVIni::SetValue(__strSection, _T("Softness"), (int)nSoftness, __strFile);
		CMNVIni::SetValue(__strSection, _T("Polarity"), (int)cdPolarity, __strFile);

		switch(cdSegmentation) {
		case cogBlobSegmentationModeHardDynamicThreshold:
			return SUCCEEDED( p->SetSegmentationHardDynamicThreshold(nTailLow, nTailHigh, cdPolarity) );
		case cogBlobSegmentationModeHardFixedThreshold:
			return SUCCEEDED( p->SetSegmentationHardFixedThreshold(nThresholdLow, cdPolarity) );
		case cogBlobSegmentationModeHardRelativeThreshold:
			return SUCCEEDED( p->SetSegmentationHardRelativeThreshold(nTailLow, nTailHigh, nThresholdLow, cdPolarity) );
		case cogBlobSegmentationModeSoftFixedThreshold:
			return SUCCEEDED( p->SetSegmentationSoftFixedThreshold(nThresholdLow, nThresholdHigh, nSoftness, cdPolarity) );
		case cogBlobSegmentationModeSoftRelativeThreshold:
			return SUCCEEDED( p->SetSegmentationSoftRelativeThreshold(nTailLow, nTailHigh, nThresholdLow, nThresholdHigh, nSoftness, cdPolarity) );
		//case cogBlobSegmentationModeMap:
		//	//p->SetSegmentationMap(SAFEARRAY **Map, long ScalingValue);
		//	break;
		//case cogBlobSegmentationModeNone:
		//	p->SetSegmentationNone(long ScalingValue);
		//	break;
		//case cogBlobSegmentationModeSubtractionImage:
		//	p->SetSegmentationSubtractionImage(SAFEARRAT ** PreMap, ICogImage8Gres * SubtractionImage, SAFEARRAY **PostMap, long ScalingValue, long SubTractionImageOffsetX, long SubtractionImageOffsetY);
		//	break;
		default: return false;
		}
	}
	CogBlobSegmentationModeConstants GetMode() {
		CogBlobSegmentationModeConstants Value;
		if (SUCCEEDED( p->get_Mode(&Value) )) return Value;
		else return cogBlobSegmentationModeNone;
	}
	
	int GetHardFixed_Threshold() {
		long nValue;
		if (SUCCEEDED( p->get_HardFixedThreshold(&nValue) )) return nValue;
		return 0;
	}
	CogBlobSegmentationPolarityConstants GetHardFixed_Polarity() {
		CogBlobSegmentationPolarityConstants nValue;
		if (SUCCEEDED( p->get_Polarity(&nValue) )) return nValue;
		return cogBlobSegmentationPolarityDarkBlobs;
	}

	int GetHardRelative_TailLow() {
		long nValue;
		if (SUCCEEDED( p->get_TailLow(&nValue) )) return nValue;
		return 0;
	}
	int GetHardRelative_TailHigh() {
		long nValue;
		if (SUCCEEDED( p->get_TailHigh(&nValue) )) return nValue;
		return 0;
	}
	int GetHardRelative_Threshold() {
		long nValue;
		if (SUCCEEDED( p->get_HardRelativeThreshold(&nValue) )) return nValue;
		return 0;
	}
	CogBlobSegmentationPolarityConstants GetHardRelative_Polarity() {
		CogBlobSegmentationPolarityConstants nValue;
		if (SUCCEEDED( p->get_Polarity(&nValue) )) return nValue;
		return cogBlobSegmentationPolarityDarkBlobs;
	}

	int GetHardDynamic_TailLow() {
		long nValue;
		if (SUCCEEDED( p->get_TailLow(&nValue) )) return nValue;
		return 0;
	}
	int GetHardDynamic_TailHigh() {
		long nValue;
		if (SUCCEEDED( p->get_TailHigh(&nValue) )) return nValue;
		return 0;
	}
	CogBlobSegmentationPolarityConstants GetHardDynamic_Polarity() {
		CogBlobSegmentationPolarityConstants nValue;
		if (SUCCEEDED( p->get_Polarity(&nValue) )) return nValue;
		return cogBlobSegmentationPolarityDarkBlobs;
	}

	int GetSoftFixed_ThresholdLow() {
		long nValue;
		if (SUCCEEDED( p->get_SoftFixedThresholdLow(&nValue) )) return nValue;
		return 0;
	}
	int GetSoftFixed_ThresholdHigh() {
		long nValue;
		if (SUCCEEDED( p->get_SoftFixedThresholdHigh(&nValue) )) return nValue;
		return 0;
	}
	int GetSoftFixed_Softness() {
		long nValue;
		if (SUCCEEDED( p->get_Softness(&nValue) )) return nValue;
		return 0;
	}
	CogBlobSegmentationPolarityConstants GetSoftFixed_Polarity() {
		CogBlobSegmentationPolarityConstants nValue;
		if (SUCCEEDED( p->get_Polarity(&nValue) )) return nValue;
		return cogBlobSegmentationPolarityDarkBlobs;
	}

	int GetSoftRelative_TailLow() {
		long nValue;
		if (SUCCEEDED( p->get_TailLow(&nValue) )) return nValue;
		return 0;
	}
	int GetSoftRelative_TailHigh() {
		long nValue; if (SUCCEEDED( p->get_TailHigh(&nValue) )) return nValue;
		return 0;
	}
	int GetSoftRelative_ThresholdLow() {
		long nValue;
		if (SUCCEEDED( p->get_SoftRelativeThresholdLow(&nValue) )) return nValue;
		return 0;
	}
	int GetSoftRelative_ThresholdHigh() {
		long nValue;
		if (SUCCEEDED( p->get_SoftRelativeThresholdHigh(&nValue) )) return nValue;
		return 0;
	}
	int GetSoftRelative_Softness() {
		long nValue;
		if (SUCCEEDED( p->get_Softness(&nValue) )) return nValue;
		return 0;
	}
	CogBlobSegmentationPolarityConstants GetSoftRelative_Polarity() {
		CogBlobSegmentationPolarityConstants nValue;
		if (SUCCEEDED( p->get_Polarity(&nValue) )) return nValue;
		return cogBlobSegmentationPolarityDarkBlobs;
	}

	bool SetMode(CogBlobSegmentationModeConstants __Mode) { return SUCCEEDED( p->put_Mode(__Mode) ); }
	
	bool SetHardFixed_Threshold(int __nValue) { return SUCCEEDED( p->put_HardFixedThreshold(__nValue) ); }
	bool SetHardFixed_Polarity(CogBlobSegmentationPolarityConstants __Polarity) { return SUCCEEDED( p->put_Polarity(__Polarity) ); }

	bool SetHardRelative_TailLow(int __nValue) { return SUCCEEDED( p->put_TailLow(__nValue) ); }
	bool SetHardRelative_TailHigh(int __nValue) { return SUCCEEDED( p->put_TailHigh(__nValue) ); }
	bool SetHardRelative_Threshold(int __nValue) { return SUCCEEDED( p->put_HardRelativeThreshold(__nValue) ); }
	bool SetHardRelative_Polarity(CogBlobSegmentationPolarityConstants __Polarity) { return SUCCEEDED( p->put_Polarity(__Polarity) ); }

	bool SetHardDynamic_TailLow(int __nValue) { return SUCCEEDED( p->put_TailLow(__nValue) ); }
	bool SetHardDynamic_TailHigh(int __nValue) { return SUCCEEDED( p->put_TailHigh(__nValue) ); }
	bool SetHardDynamic_Polarity(CogBlobSegmentationPolarityConstants __Polarity) { return SUCCEEDED( p->put_Polarity(__Polarity) ); }

	bool SetSoftFixed_ThresholdLow(int __nValue) { return SUCCEEDED( p->put_SoftFixedThresholdLow(__nValue) ); }
	bool SetSoftFixed_ThresholdHigh(int __nValue) { return SUCCEEDED( p->put_SoftFixedThresholdHigh(__nValue) ); }
	bool SetSoftFixed_Softness(int __nValue) { return SUCCEEDED( p->put_Softness(__nValue) ); }
	bool SetSoftFixed_Polarity(CogBlobSegmentationPolarityConstants __Polarity) { return SUCCEEDED( p->put_Polarity(__Polarity) ); }

	bool SetSoftRelative_TailLow(int __nValue) { return SUCCEEDED( p->put_TailLow(__nValue) ); }
	bool SetSoftRelative_TailHigh(int __nValue) { return SUCCEEDED( p->put_TailHigh(__nValue) ); }
	bool SetSoftRelative_ThresholdLow(int __nValue) { return SUCCEEDED( p->put_SoftRelativeThresholdLow(__nValue) ); }
	bool SetSoftRelative_ThresholdHigh(int __nValue) { return SUCCEEDED( p->put_SoftRelativeThresholdHigh(__nValue) ); }
	bool SetSoftRelative_Softness(int __nValue) { return SUCCEEDED( p->put_Softness(__nValue) ); }
	bool SetSoftRelative_Polarity(CogBlobSegmentationPolarityConstants __Polarity) { return SUCCEEDED( p->put_Polarity(__Polarity) ); }
};

class CMNVBlob_Item : public CComPtr<ICogBlobResult> {
public:
	bool Create() { Release(); return SUCCEEDED( CoCreateInstance(CLSID_CogBlobResult) ); }
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogBlobResult>::Release();
	}
public:
	CMNVBlob_Item(bool __isCreate = true) : CComPtr<ICogBlobResult>() { if (__isCreate) Create(); }
	~CMNVBlob_Item() { Release(); }
};

class CMNVBlob_Collection : public CComPtr<ICogBlobResultCollection> {
public:
	bool Create() { Release(); return SUCCEEDED( CoCreateInstance(CLSID_CogBlobResultCollection) ); }
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogBlobResultCollection>::Release();
	}
public:
	CMNVBlob_Collection(bool __isCreate = true) : CComPtr<ICogBlobResultCollection>() { if (__isCreate) Create(); }
	~CMNVBlob_Collection() { Release(); }

	int GetCount() {
		long nCount;
		if (SUCCEEDED( p->get_Count(&nCount) )) return (int)nCount;
		else return 0;
	}
	bool GetItem(int __nIndex, CMNVBlob_Item & __Item) {
		if (p == NULL) return false;
		__Item.Release();
		return SUCCEEDED( p->get_Item(__nIndex, &__Item) );
	}
};

class CMNVBlob_Results : public CComPtr<ICogBlobResults> {
public:
	bool Create() { Release(); return SUCCEEDED( CoCreateInstance(CLSID_CogBlobResults) ); }
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogBlobResults>::Release();
	}
public:
	CMNVBlob_Results(bool __isCreate = true) : CComPtr<ICogBlobResults>() { if (__isCreate) Create(); }
	~CMNVBlob_Results() { Release(); }
};

class CMNVBlob_Algorithm : public CComPtr<ICogBlob>{
private:
	CMNVBlob_Segmentation m_Segmentation;
public:
	CogBlobSegmentationModeConstants GetMode() { return m_Segmentation.GetMode(); }
	int GetHardFixed_Threshold() { return m_Segmentation.GetHardFixed_Threshold(); }
	CogBlobSegmentationPolarityConstants GetHardFixed_Polarity() { return m_Segmentation.GetHardFixed_Polarity(); }

	int GetHardRelative_TailLow() { return m_Segmentation.GetHardRelative_TailLow(); }
	int GetHardRelative_TailHigh() { return m_Segmentation.GetHardRelative_TailHigh(); }
	int GetHardRelative_Threshold() { return m_Segmentation.GetHardRelative_Threshold(); }
	CogBlobSegmentationPolarityConstants GetHardRelative_Polarity() { return m_Segmentation.GetHardRelative_Polarity(); }

	int GetHardDynamic_TailLow() { return m_Segmentation.GetHardDynamic_TailLow(); }
	int GetHardDynamic_TailHigh() { return m_Segmentation.GetHardDynamic_TailHigh(); }
	CogBlobSegmentationPolarityConstants GetHardDynamic_Polarity() { return m_Segmentation.GetHardDynamic_Polarity(); }

	int GetSoftFixed_ThresholdLow() { return m_Segmentation.GetSoftFixed_ThresholdLow(); }
	int GetSoftFixed_ThresholdHigh() { return m_Segmentation.GetSoftFixed_ThresholdHigh(); }
	int GetSoftFixed_Softness() { return m_Segmentation.GetSoftFixed_Softness(); }
	CogBlobSegmentationPolarityConstants GetSoftFixed_Polarity() { return m_Segmentation.GetSoftFixed_Polarity(); }

	int GetSoftRelative_TailLow() { return m_Segmentation.GetSoftRelative_TailLow(); }
	int GetSoftRelative_TailHigh() { return m_Segmentation.GetSoftRelative_TailHigh(); }
	int GetSoftRelative_ThresholdLow() { return m_Segmentation.GetSoftRelative_ThresholdLow(); }
	int GetSoftRelative_ThresholdHigh() { return m_Segmentation.GetSoftRelative_ThresholdHigh(); }
	int GetSoftRelative_Softness() { return m_Segmentation.GetSoftRelative_Softness(); }
	CogBlobSegmentationPolarityConstants GetSoftRelative_Polarity() { return m_Segmentation.GetSoftRelative_Polarity(); }

	bool SetMode(CogBlobSegmentationModeConstants __Mode) { return m_Segmentation.SetMode(__Mode); }
	
	bool SetHardFixed_Threshold(int __nValue) { return m_Segmentation.SetHardFixed_Threshold(__nValue); }
	bool SetHardFixed_Polarity(CogBlobSegmentationPolarityConstants __Polarity) { return m_Segmentation.SetHardFixed_Polarity(__Polarity); }

	bool SetHardRelative_TailLow(int __nValue) { return m_Segmentation.SetHardRelative_TailLow(__nValue); }
	bool SetHardRelative_TailHigh(int __nValue) { return m_Segmentation.SetHardRelative_TailHigh(__nValue); }
	bool SetHardRelative_Threshold(int __nValue) { return m_Segmentation.SetHardRelative_Threshold(__nValue); }
	bool SetHardRelative_Polarity(CogBlobSegmentationPolarityConstants __Polarity) { return m_Segmentation.SetHardRelative_Polarity(__Polarity); }

	bool SetHardDynamic_TailLow(int __nValue) { return m_Segmentation.SetHardDynamic_TailLow(__nValue); }
	bool SetHardDynamic_TailHigh(int __nValue) { return m_Segmentation.SetHardDynamic_TailHigh(__nValue); }
	bool SetHardDynamic_Polarity(CogBlobSegmentationPolarityConstants __Polarity) { return m_Segmentation.SetHardDynamic_Polarity(__Polarity); }

	bool SetSoftFixed_ThresholdLow(int __nValue) { return m_Segmentation.SetSoftFixed_ThresholdLow(__nValue); }
	bool SetSoftFixed_ThresholdHigh(int __nValue) { return m_Segmentation.SetSoftFixed_ThresholdHigh(__nValue); }
	bool SetSoftFixed_Softness(int __nValue) { return m_Segmentation.SetSoftFixed_Softness(__nValue); }
	bool SetSoftFixed_Polarity(CogBlobSegmentationPolarityConstants __Polarity) { return m_Segmentation.SetSoftFixed_Polarity(__Polarity); }

	bool SetSoftRelative_TailLow(int __nValue) { return m_Segmentation.SetSoftRelative_TailLow(__nValue); }
	bool SetSoftRelative_TailHigh(int __nValue) { return m_Segmentation.SetSoftRelative_TailHigh(__nValue); }
	bool SetSoftRelative_ThresholdLow(int __nValue) { return m_Segmentation.SetSoftRelative_ThresholdLow(__nValue); }
	bool SetSoftRelative_ThresholdHigh(int __nValue) { return m_Segmentation.SetSoftRelative_ThresholdHigh(__nValue); }
	bool SetSoftRelative_Softness(int __nValue) { return m_Segmentation.SetSoftRelative_Softness(__nValue); }
	bool SetSoftRelative_Polarity(CogBlobSegmentationPolarityConstants __Polarity) { return m_Segmentation.SetSoftRelative_Polarity(__Polarity); }

private:
	CMNVBlob_Results m_Results;
public:
	bool Create() { Release(); return SUCCEEDED( CoCreateInstance(CLSID_CogBlob) ); }
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogBlob>::Release();
	}
public:
	CMNVBlob_Algorithm(bool __isCreate = true) : CComPtr<ICogBlob>() { if (__isCreate) Create(); }
	~CMNVBlob_Algorithm() { Release(); }
	bool Prepare(LPCTSTR __strFile, LPCTSTR __strSection) {
		if (p == NULL && !Create()) return false;

		p->put_ConnectivityCleanup(cogBlobConnectivityCleanupFill); // 정리
		p->put_ConnectivityMinPixels(10); // 최소영역
		p->put_ConnectivityMode(cogBlobConnectivityModeGreyScale); // 모드

		if (! m_Segmentation.Prepare(__strFile, __strSection)) return false;
		p->putref_SegmentationParams(m_Segmentation);
		return true;
	}
	bool Execute(CMNVImage & __imgSrc, CMNVRectangleAffine & __Region, CMNVStaticGraphicCollection & __sgcResult) {
		m_Results.Release();
		CMNVImage8Grey imgGrey;
		__imgSrc.Copy(imgGrey);
		return SUCCEEDED( p->Execute(imgGrey, CMNVRegion(__Region), &m_Results) );
	}
	bool Execute(CMNVImage & __imgSrc, MNVCircularAnnulusSection & __Region, CMNVStaticGraphicCollection & __sgcResult) {
		m_Results.Release();
		CMNVImage8Grey imgGrey;
		__imgSrc.Copy(imgGrey);
		return SUCCEEDED( p->Execute(imgGrey, CMNVRegion(__Region), &m_Results) );
	}
	bool GetResultCollection(CMNVBlob_Collection & __Collection) {
		__Collection.Release();
		return SUCCEEDED( m_Results->get_Blobs(VARIANT_TRUE, &__Collection) );
	}
	//void Func() {
	//	AlgBlob->putref_SegmentationParams(ICogBlobSegmentationParams * pVal);


	//	ParamBlob->put_Mode(CogBlobSegmentationModeConstants::cogBlobSegmentationModeHardRelativeThreshold);
	//	ParamBlob->SetSegmentationHardRelativeThreshold(long TailLow, long TailHigh, long Threshold, cogBlobSegmentationPolarityDarkBlobs);


	//	// 영역
	//	AlgBlob->put_RegionMode(CogRegionModeConstants::cogRegionModePixelAlignedBoundingBoxAdjustMask);

	//	AlgBlob->Execute(ICogImage8Grey, ICogRegion, ICogBlobResults);

	//	AlgBlob->putref_InputImageMask(ICogImage8Grey * pVal);

	//	// 설정 - 모폴로지 오퍼레이션
	//	AlgBlob->putref_MorphologyOperations(ICogBlobMorphologyCollection * pVal);

	//	// 측정
	//	AlgBlob->putref_RunTimeMeasures(ICogBlobMeasureCollection * pVal);

	//	// 설정 - 연결

	//	//// 측정 익스트리머
	//	//AlgBlob->put_ExtremaAngle(double pVal);
	//	//AlgBlob->put_ExtremaExcludeArea(double pVal);
	//	//AlgBlob->put_ExtremaExcludeAreaPercent(double pVal);
	//	//AlgBlob->put_ExtremaExcludeAreaPixels(double pVal);
	//	//AlgBlob->put_ExtremaExcludeMode(CogBlobExtremaExcludeConstants:: pVal);

	//	//AlgBlob->put_InputImageMaskOffsetX(long pVal);
	//	//AlgBlob->put_InputImageMaskOffsetY(long pVal);
	//	
	//	//// 그래픽
	//	//AlgBlob->put_SaveSegmentedImage(VARIANT_BOOL pVal);
	//	//AlgBlob->put_SaveSegmentedImageBeforeMasking(VARIANT_BOOL pVal);
	//	//AlgBlob->put_SaveSegmentedImageBeforeMorphology(VARIANT_BOOL pVal);

	//	//// 측정 - 정렬
	//	//AlgBlob->put_SortAscending(VARIANT_BOOL pVal);
	//	//AlgBlob->put_SortEnabled(VARIANT_BOOL pVal);
	//	//AlgBlob->put_SortMeasure(CogBlobMeasureConstants pVal);
	//}
};

class CInspect_CircularAnnulusSection_Blob {
public:
	double m_dThresHold[4];
	CMNV_FindCircle m_FindInner;
	CMNV_FindCircle m_FindOuter;
	CMNVCircularArc m_CircurlarArc;
	CString m_strModel;

	CMNVBlob_Algorithm m_AlgorithmBlob;

	double m_dAreaMin;
	double m_dAreaMax;
	double m_dAreaRate;

	struct {
		double dCenterX;
		double dCenterY;
		double dDistance;
		double dWidth;
	} m_stAllow[2];

	bool Prepare(LPCTSTR __strFile) {
		m_strModel = __strFile;
		m_dThresHold[0] = CMNVIni::GetValue(_T("FindCircle"), _T("Threshold1"), (double)20, __strFile);
		m_dThresHold[1] = CMNVIni::GetValue(_T("FindCircle"), _T("Threshold2"), (double)20, __strFile);
		m_dThresHold[2] = CMNVIni::GetValue(_T("FindCircle"), _T("Threshold3"), (double)20, __strFile);
		m_dThresHold[3] = CMNVIni::GetValue(_T("FindCircle"), _T("Threshold4"), (double)20, __strFile);

		m_dAreaMin = CMNVIni::GetValue(_T("Inspect"), _T("AreaMin"), (double)100, m_strModel);
		m_dAreaMax = CMNVIni::GetValue(_T("Inspect"), _T("AreaMax"), (double)100, m_strModel);
		m_dAreaRate = CMNVIni::GetValue(_T("Inspect"), _T("AreaRate"), (double)100, m_strModel);

		m_stAllow[0].dCenterX = CMNVIni::GetValue(_T("Hole1"), _T("CenterX"), (double)100, m_strModel);
		m_stAllow[0].dCenterY = CMNVIni::GetValue(_T("Hole1"), _T("CenterY"), (double)100, m_strModel);
		m_stAllow[0].dDistance = CMNVIni::GetValue(_T("Hole1"), _T("Distance"), (double)100, m_strModel);
		m_stAllow[0].dWidth = CMNVIni::GetValue(_T("Hole1"), _T("Width"), (double)100, m_strModel);

		m_stAllow[1].dCenterX = CMNVIni::GetValue(_T("Hole2"), _T("CenterX"), (double)100, m_strModel);
		m_stAllow[1].dCenterY = CMNVIni::GetValue(_T("Hole2"), _T("CenterY"), (double)100, m_strModel);
		m_stAllow[1].dDistance = CMNVIni::GetValue(_T("Hole2"), _T("Distance"), (double)100, m_strModel);
		m_stAllow[1].dWidth = CMNVIni::GetValue(_T("Hole2"), _T("Width"), (double)100, m_strModel);

		//m_FindOuter.Prepare(__strFile, _T("OuterCircle"));
		//m_FindInner.Prepare(__strFile, _T("InnerCircle"));

		//m_FindOuter.SaveIni(__strFile, _T("OuterCircle"));
		//m_FindInner.SaveIni(__strFile, _T("InnerCircle"));
		return true;
	}
	bool Excute(CMNVImage & __imgSrc) {
		bool isOuter = m_FindOuter.Excute(__imgSrc);
		bool isInner = m_FindInner.Excute(__imgSrc);

		//m_CircurlarArc
		return true;
	}
	bool GetResult(CMNVStaticGraphicCollection & __sgcResult) {
		if (__sgcResult == NULL && !(__sgcResult.Create())) return false;

		m_FindOuter.GetResult(__sgcResult);
		m_FindInner.GetResult(__sgcResult);
		return true;
	}

	bool Find_innerCircle(CMNVImage8Grey & __imgSrc, CMNVCircle & __circleBase, double __dThresHold, CogCaliperPolarityConstants __Polarity, CMNVCircle & __circleOutput) {
		m_FindOuter.SetExpectedCircularArc(__circleBase.GetCenterX(), __circleBase.GetCenterY(), __circleBase.GetRadius() / 2);
		m_FindOuter.SetLength_Search((long)__circleBase.GetRadius());
		m_FindOuter.SetPolarity(__Polarity);
		m_FindOuter.m_Params.SetThreshold(__dThresHold);
		m_FindOuter.Prepare();
		m_FindOuter.Excute(__imgSrc);
		m_FindOuter.GetResult(__circleOutput);
		return true;
	}
	bool Inspector(CMNVBlob_Collection & __ResultCollection, double __dOriginX, double __dOriginY, int __nIndex, CMNVStaticGraphicCollection & __sgcResult) {
		double dHoleCenterX = __dOriginX + m_stAllow[__nIndex].dCenterX;
		double dHoleCenterY = __dOriginY + m_stAllow[__nIndex].dCenterY;
		bool m_isFind = false;
		CMNVCircle AreaHole(m_stAllow[__nIndex].dCenterX, m_stAllow[__nIndex].dCenterY, m_stAllow[__nIndex].dDistance);
		__sgcResult.AddGraphic(AreaHole, 1, cogColorYellow);

		int nCount = __ResultCollection.GetCount();
		CMNVBlob_Item ResultItem(false);
		CMNVPolygon Polygon(false);
		CMNVRectangleAffine Rect(false);
		CString strTemp;
		double dArea;
		double dCenterX;
		double dCenterY;
		double dWidth;
		double dHeight;
		double dDistX;
		double dDistY;
		double dDistance;
		for(int nIndex = 0; nIndex < nCount; ++nIndex) {
			if ( __ResultCollection.GetItem(nIndex, ResultItem) ) {
				Polygon.Release();
				Rect.Release();
				ResultItem->get_Area(&dArea);
				ResultItem->GetBoundary(&Polygon);
				ResultItem->GetBoundingBox(cogBlobAxisPrincipal, &Rect);
				dWidth = Rect.GetWidth();
				dHeight = Rect.GetHeight();
				dCenterX = Rect.GetCenterX();
				dCenterY = Rect.GetCenterY();

				dDistX = dCenterX - dHoleCenterX;
				dDistY = dCenterY - dHoleCenterY;
				dDistance = sqrt(dDistX * dDistX + dDistY * dDistY);
				__sgcResult.AddPoint(dCenterX, dCenterY, 0, 1, 20, cogColorYellow);
				if (!m_isFind && (dDistance < m_stAllow[__nIndex].dDistance)) {
					if (dWidth < m_stAllow[__nIndex].dWidth) {
						__sgcResult.AddGraphic(Polygon, 1, cogColorGreen);
						strTemp.Format(_T("%0.2f / %0.2f (%0.2f:%0.2f) %0.2f"), dWidth, dHeight, dArea / (dWidth * dHeight), dArea, dWidth / dHeight);
						__sgcResult.AddLabel(Rect.GetCenterX(), Rect.GetCenterY(), 1, 100, strTemp, cogColorGreen, cogColorNone, cogGraphicLabelAlignmentBottomLeft);
						strTemp.Format(_T("%0.2f, %0.2f"), dCenterX, dCenterY);
						__sgcResult.AddLabel(Rect.GetCenterX(), Rect.GetCenterY() - 50, 1, 100, strTemp, cogColorGreen, cogColorNone, cogGraphicLabelAlignmentBottomLeft);
					}
					else {
						__sgcResult.AddGraphic(Polygon, 1, cogColorRed);
						strTemp.Format(_T("%0.2f / %0.2f (%0.2f:%0.2f) %0.2f"), dWidth, dHeight, dArea / (dWidth * dHeight), dArea, dWidth / dHeight);
						__sgcResult.AddLabel(Rect.GetCenterX(), Rect.GetCenterY(), 1, 100, strTemp, cogColorRed, cogColorNone, cogGraphicLabelAlignmentBottomLeft);
						strTemp.Format(_T("%0.2f, %0.2f"), dCenterX, dCenterY);
						__sgcResult.AddLabel(Rect.GetCenterX(), Rect.GetCenterY() - 50, 1, 100, strTemp, cogColorRed, cogColorNone, cogGraphicLabelAlignmentBottomLeft);
					}
				}
				else if (m_dAreaMin > dArea || dArea > m_dAreaMax || (dArea / (dWidth * dHeight)) < m_dAreaRate) {
					__sgcResult.AddGraphic(Polygon, 1, cogColorYellow);
				}
				else {
					__sgcResult.AddGraphic(Polygon, 1, cogColorRed);
					strTemp.Format(_T("%0.2f / %0.2f (%0.2f:%0.2f) %0.2f"), dWidth, dHeight, dArea / (dWidth * dHeight), dArea, dWidth / dHeight);
					__sgcResult.AddLabel(Rect.GetCenterX(), Rect.GetCenterY(), 1, 100, strTemp, cogColorRed, cogColorNone, cogGraphicLabelAlignmentBottomLeft);
					strTemp.Format(_T("%0.2f, %0.2f"), dCenterX - __dOriginX, dCenterY - __dOriginY);
					__sgcResult.AddLabel(Rect.GetCenterX(), Rect.GetCenterY() - 50, 1, 100, strTemp, cogColorRed, cogColorNone, cogGraphicLabelAlignmentBottomLeft);
				}
			}
		}
		return true;
	}
	bool Excute(CMNVImage & __imgSrc, CMNVStaticGraphicCollection & __sgcResult) {
		CMNVCircle m_circleFind[5];
		m_FindOuter.Prepare(m_strModel, _T("FindCircle"));

		CMNVImage8Grey imgGray;
		__imgSrc.Copy(imgGray);

		m_circleFind[0].SetCircle(__imgSrc.GetWidth() / 2, __imgSrc.GetHeight() / 2, __imgSrc.GetWidth() / 2);
		Find_innerCircle(imgGray, m_circleFind[0], m_dThresHold[0], cogCaliperPolarityDarkToLight, m_circleFind[1]);
		Find_innerCircle(imgGray, m_circleFind[1], m_dThresHold[1], cogCaliperPolarityLightToDark, m_circleFind[2]);
		Find_innerCircle(imgGray, m_circleFind[2], m_dThresHold[2], cogCaliperPolarityDarkToLight, m_circleFind[3]);
		Find_innerCircle(imgGray, m_circleFind[3], m_dThresHold[3], cogCaliperPolarityLightToDark, m_circleFind[4]);


		__sgcResult.AddGraphic(m_circleFind[0], 1, cogColorYellow);
		__sgcResult.AddGraphic(m_circleFind[1], 1, cogColorYellow);
		__sgcResult.AddGraphic(m_circleFind[2], 1, cogColorYellow);
		__sgcResult.AddGraphic(m_circleFind[3], 1, cogColorYellow);
		__sgcResult.AddGraphic(m_circleFind[4], 1, cogColorYellow);


		MNVCircularAnnulusSection m_Region[2];
		m_Region[0].SetFromCircle(m_circleFind[1], m_circleFind[2], 2);
		m_Region[1].SetFromCircle(m_circleFind[3], m_circleFind[4], 2);

		__sgcResult.AddGraphic(m_Region[0], 1, cogColorBlue);
		__sgcResult.AddGraphic(m_Region[1], 1, cogColorBlue);

		CMNVBlob_Collection ResultCollection(false);
		m_AlgorithmBlob.Prepare(m_strModel, _T("Blob"));

		if (m_AlgorithmBlob.Execute(__imgSrc, m_Region[0], __sgcResult)) {
			if (m_AlgorithmBlob.GetResultCollection(ResultCollection)) {
				Inspector(ResultCollection, m_Region[0].GetCenterX(), m_Region[0].GetCenterY(), 0, __sgcResult);
			}
		}

		if (m_AlgorithmBlob.Execute(__imgSrc, m_Region[1], __sgcResult)) {
			if (m_AlgorithmBlob.GetResultCollection(ResultCollection)) {
				Inspector(ResultCollection, m_Region[1].GetCenterX(), m_Region[1].GetCenterY(), 1, __sgcResult);
			}
		}

		//CMNVCircle m_inner;
		//m_FindInner.Prepare(m_strModel, _T("InnerCircle1"));
		//m_FindInner.Excute(__imgSrc);
		//m_FindInner.GetResult(__sgcResult);
		//m_FindInner.GetResult(m_inner);
		//

		//


		////CMNVCircle m_Outer;
		//m_FindOuter.Prepare(m_strModel, _T("OuterCircle2"));
		//m_FindOuter.Excute(__imgSrc);
		//m_FindOuter.GetResult(__sgcResult);
		//m_FindOuter.GetResult(m_Outer);

		////CMNVCircle m_inner;
		//m_FindInner.Prepare(m_strModel, _T("InnerCircle2"));
		//m_FindInner.Excute(__imgSrc);
		//m_FindInner.GetResult(__sgcResult);
		//m_FindInner.GetResult(m_inner);

		//dRadius = m_Outer.GetRadius() - 5;
		//dScale = (m_inner.GetRadius() + 5) / dRadius;
		//m_Region.SetSection(m_Outer.GetCenterX(), m_Outer.GetCenterY(), dRadius, dScale, 0, PI * 2);

		//__sgcResult.AddGraphic(m_Region, 1, cogColorBlue);
		//
		//m_AlgorithmBlob.Prepare(m_strModel, _T("Blob"));
		//Result = m_AlgorithmBlob.Execute(__imgSrc, m_Region, __sgcResult);

		return true;
	}
};
class CInspect_RectangleAffine_Blob {
public:
	//double m_dThresHold[4];
	//CMNV_FindCircle m_FindInner;
	//CMNV_FindCircle m_FindOuter;
	CMNVCircularArc m_CircurlarArc;
	CMNVRectangleAffine m_Region;
	CString m_strModel;

	CMNVBlob_Algorithm m_AlgorithmBlob;
	CMNVBlob_Algorithm m_AlgorithmBlob2;

	double m_dAreaMin;
	double m_dAreaMax;
	double m_dAreaRate;

	bool Prepare(LPCTSTR __strFile) {
		m_strModel = __strFile;
		m_Region.LoadIni(m_strModel, _T("RectangleAffine"));
		m_AlgorithmBlob.Prepare(m_strModel, _T("Blob_Dark"));
		m_AlgorithmBlob2.Prepare(m_strModel, _T("Blob_Light"));

		m_dAreaMin = CMNVIni::GetValue(_T("Inspect"), _T("AreaMin"), (double)100, m_strModel);
		m_dAreaMax = CMNVIni::GetValue(_T("Inspect"), _T("AreaMax"), (double)100, m_strModel);
		m_dAreaRate = CMNVIni::GetValue(_T("Inspect"), _T("AreaRate"), (double)100, m_strModel);

		return true;
	}
	//bool Excute(CMNVImage & __imgSrc) {
	//	bool isOuter = m_FindOuter.Excute(__imgSrc);
	//	bool isInner = m_FindInner.Excute(__imgSrc);

	//	//m_CircurlarArc
	//	return true;
	//}
	//bool GetResult(CMNVStaticGraphicCollection & __sgcResult) {
	//	if (__sgcResult == NULL && !(__sgcResult.Create())) return false;

	//	m_FindOuter.GetResult(__sgcResult);
	//	m_FindInner.GetResult(__sgcResult);
	//	return true;
	//}

	//bool Find_innerCircle(CMNVImage8Grey & __imgSrc, CMNVCircle & __circleBase, double __dThresHold, CogCaliperPolarityConstants __Polarity, CMNVCircle & __circleOutput) {
	//	m_FindOuter.SetExpectedCircularArc(__circleBase.GetCenterX(), __circleBase.GetCenterY(), __circleBase.GetRadius() / 2);
	//	m_FindOuter.SetLength_Search(__circleBase.GetRadius());
	//	m_FindOuter.SetPolarity(__Polarity);
	//	m_FindOuter.m_Params.SetThreshold(__dThresHold);
	//	m_FindOuter.Prepare();
	//	m_FindOuter.Excute(__imgSrc);
	//	m_FindOuter.GetResult(__circleOutput);
	//	return true;
	//}
	bool Inspector(CMNVBlob_Collection & __ResultCollection, CMNVStaticGraphicCollection & __sgcResult) {
		int nCount = __ResultCollection.GetCount();
		CMNVBlob_Item ResultItem(false);
		CMNVPolygon Polygon(false);
		CMNVRectangleAffine Rect(false);
		CString strTemp;
		double dArea;
		double dCenterX;
		double dCenterY;
		double dWidth;
		double dHeight;
		//double dDistX;
		//double dDistY;
		//double dDistance;
		for(int nIndex = 0; nIndex < nCount; ++nIndex) {
			if ( __ResultCollection.GetItem(nIndex, ResultItem) ) {
				Polygon.Release();
				Rect.Release();
				ResultItem->get_Area(&dArea);
				ResultItem->GetBoundary(&Polygon);
				ResultItem->GetBoundingBox(cogBlobAxisPrincipal, &Rect);
				dWidth = Rect.GetWidth();
				dHeight = Rect.GetHeight();
				dCenterX = Rect.GetCenterX();
				dCenterY = Rect.GetCenterY();

				__sgcResult.AddPoint(dCenterX, dCenterY, 0, 1, 20, cogColorYellow);

				if (m_dAreaMin > dArea || dArea > m_dAreaMax || (dArea / (dWidth * dHeight)) < m_dAreaRate) {
					__sgcResult.AddGraphic(Polygon, 1, cogColorYellow);
				}
				else {
					__sgcResult.AddGraphic(Polygon, 1, cogColorRed);
					strTemp.Format(_T("%0.2f / %0.2f (%0.2f:%0.2f) %0.2f"), dWidth, dHeight, dArea / (dWidth * dHeight), dArea, dWidth / dHeight);
					__sgcResult.AddLabel(Rect.GetCenterX(), Rect.GetCenterY(), 1, 100, strTemp, cogColorRed, cogColorNone, cogGraphicLabelAlignmentBottomLeft);
				}
			}
		}
		return true;
	}
	bool Excute(CMNVImage & __imgSrc, CMNVStaticGraphicCollection & __sgcResult) {
		//CMNVCircle m_circleFind[5];
		//m_FindOuter.Prepare(m_strModel, _T("FindCircle"));
		
		CMNVImage8Grey imgGray;
		__imgSrc.Copy(imgGray);

		__sgcResult.AddGraphic(m_Region, 1, cogColorBlue);

		CMNVBlob_Collection ResultCollection(false);

		if (m_AlgorithmBlob.Execute(__imgSrc, m_Region, __sgcResult)) {
			if (m_AlgorithmBlob.GetResultCollection(ResultCollection)) {
				Inspector(ResultCollection, __sgcResult);
			}
		}
		if (m_AlgorithmBlob2.Execute(__imgSrc, m_Region, __sgcResult)) {
			if (m_AlgorithmBlob2.GetResultCollection(ResultCollection)) {
				Inspector(ResultCollection, __sgcResult);
			}
		}
		//CMNVCircle m_inner;
		//m_FindInner.Prepare(m_strModel, _T("InnerCircle1"));
		//m_FindInner.Excute(__imgSrc);
		//m_FindInner.GetResult(__sgcResult);
		//m_FindInner.GetResult(m_inner);
		//

		//


		////CMNVCircle m_Outer;
		//m_FindOuter.Prepare(m_strModel, _T("OuterCircle2"));
		//m_FindOuter.Excute(__imgSrc);
		//m_FindOuter.GetResult(__sgcResult);
		//m_FindOuter.GetResult(m_Outer);

		////CMNVCircle m_inner;
		//m_FindInner.Prepare(m_strModel, _T("InnerCircle2"));
		//m_FindInner.Excute(__imgSrc);
		//m_FindInner.GetResult(__sgcResult);
		//m_FindInner.GetResult(m_inner);

		//dRadius = m_Outer.GetRadius() - 5;
		//dScale = (m_inner.GetRadius() + 5) / dRadius;
		//m_Region.SetSection(m_Outer.GetCenterX(), m_Outer.GetCenterY(), dRadius, dScale, 0, PI * 2);

		//__sgcResult.AddGraphic(m_Region, 1, cogColorBlue);
		//
		//m_AlgorithmBlob.Prepare(m_strModel, _T("Blob"));
		//Result = m_AlgorithmBlob.Execute(__imgSrc, m_Region, __sgcResult);

		return true;
	}
};
enum MNV_InspectResult { 
	MNVIR_NOR = 0
	, MNVIR_OK = 1
	, MNVIR_NG = 2
	, MNVIR_PASS = 3
};
class CInspect_RelativeHistogram {
public:
	bool m_isEnable;
	CMNVImage m_imgSrc;
	CMNVHistogram m_Inspect_Histogram;
	CMNVCircle m_cirOpen[2];
	CMNVCircle m_cirClose[2];
	double m_dResult_Open[2];
	double m_dResult_Close[2];
	double m_dAccept;
	bool m_isFind;

	bool LoadModel(LPCTSTR __strFile) {
		m_isEnable = true;
		m_isFind = false;
		if (!m_cirOpen[0].SetCircle(_T("Open1"), __strFile)) m_isEnable = false;
		if (!m_cirOpen[1].SetCircle(_T("Open2"), __strFile)) m_isEnable = false;
		if (!m_cirClose[0].SetCircle(_T("Close1"), __strFile)) m_isEnable = false;
		if (!m_cirClose[1].SetCircle(_T("Close2"), __strFile)) m_isEnable = false;
		m_dAccept = CMNVIni::GetValue(_T("Result"), _T("Accept"), (double)-1, __strFile);
		if (m_dAccept < 0) m_isEnable = false;

		return m_isEnable;
	}
	bool GetSourceImage(CMNVImage & __img) { return m_imgSrc.Copy(__img);}
	bool AddRegion(CMNVStaticGraphicCollection & __sgcRegion) {
		if (m_isEnable) {
			__sgcRegion.AddGraphic(m_cirOpen[0], 1, cogColorBlue);
			__sgcRegion.AddGraphic(m_cirOpen[1], 1, cogColorBlue);
			__sgcRegion.AddGraphic(m_cirClose[0], 1, cogColorRed);
			__sgcRegion.AddGraphic(m_cirClose[1], 1, cogColorRed);
			return true;
		}
		else { return false; }
	}
	bool GetResult() {
		if (m_isFind) {
			return (m_dResult_Open[0] / m_dResult_Close[0]) > m_dAccept && (m_dResult_Open[1] / m_dResult_Close[1]) > m_dAccept;
		}
		else return false;
	}
	bool GetResult(CMNVStaticGraphicCollection & __sgcResult) {
		if (m_isFind) {
			CString strTemp;
			//__sgcResult.Clear();

			strTemp.Format(_T("%0.1f"), m_dResult_Open[0]);
			__sgcResult.AddGraphic(m_cirOpen[0], 1, cogColorBlue);
			__sgcResult.AddLabel(m_cirOpen[0].GetCenterX(), m_cirOpen[0].GetCenterY(), 2, 10, strTemp, cogColorGreen, cogColorNone, cogGraphicLabelAlignmentTopCenter);

			strTemp.Format(_T("%0.1f"), m_dResult_Open[1]);
			__sgcResult.AddGraphic(m_cirOpen[1], 1, cogColorBlue);
			__sgcResult.AddLabel(m_cirOpen[0].GetCenterX(), m_cirOpen[0].GetCenterY(), 2, 10, strTemp, cogColorGreen, cogColorNone, cogGraphicLabelAlignmentTopCenter);

			strTemp.Format(_T("%0.1f"), m_dResult_Close[0]);
			__sgcResult.AddGraphic(m_cirClose[0], 1, cogColorRed);
			__sgcResult.AddLabel(m_cirClose[0].GetCenterX(), m_cirClose[0].GetCenterY(), 2, 10, strTemp, cogColorGreen, cogColorNone, cogGraphicLabelAlignmentTopCenter);

			strTemp.Format(_T("%0.1f"), m_dResult_Close[1]);
			__sgcResult.AddGraphic(m_cirClose[1], 1, cogColorRed);
			__sgcResult.AddLabel(m_cirClose[1].GetCenterX(), m_cirClose[1].GetCenterY(), 2, 10, strTemp, cogColorGreen, cogColorNone, cogGraphicLabelAlignmentTopCenter);

			return (m_dResult_Open[0] / m_dResult_Close[0]) > m_dAccept && (m_dResult_Open[1] / m_dResult_Close[1]) > m_dAccept;
		}
		else {
			__sgcResult.AddLabel(10, 100, 2, 10, _T("Not Find"), cogColorRed, cogColorNone, cogGraphicLabelAlignmentTopLeft);
			return false;
		}

	}

	bool Excute(CMNVImage & __imgSrc) {
		m_isFind = false;
		//m_dResult_Open = 0;
		//m_dResult_Close = 0;
		if (m_Inspect_Histogram == NULL) m_Inspect_Histogram.Create();
		if (__imgSrc.Copy(m_imgSrc)) {
			if ( !m_Inspect_Histogram.Execute(m_imgSrc, CMNVRegion(m_cirOpen[0])) ) return false;
			m_dResult_Open[0] = m_Inspect_Histogram.GetMean();
			if ( !m_Inspect_Histogram.Execute(m_imgSrc, CMNVRegion(m_cirOpen[1])) ) return false;
			m_dResult_Open[1] = m_Inspect_Histogram.GetMean();
			if ( !m_Inspect_Histogram.Execute(m_imgSrc, CMNVRegion(m_cirClose[0])) ) return false;
			m_dResult_Close[0] = m_Inspect_Histogram.GetMean();
			if ( !m_Inspect_Histogram.Execute(m_imgSrc, CMNVRegion(m_cirClose[1])) ) return false;
			m_dResult_Close[1] = m_Inspect_Histogram.GetMean();
			m_isFind = true;
			return true;
		}
		else return false;
	}
};

enum MNVAlgorithm_Type {
	MNV_AT_CircularCaliper = 1
	, MNV_AT_RelativeHistogram = 2
	, MNV_AT_AffineCaliper = 3
	, MNV_AT_CircularBlob = 4
	, MNV_AT_RectBlob = 5
};

struct STMNV_Model {
	MNVLock Lock;
	MNVAlgorithm_Type m_cdType;
	CMNVPMAlignPattern m_Algorithm;
	CMNVInspect_PolarUnwrapCaliper m_Inspect_PolarUnwrapCaliper;
	CMNVInspect_AffineTransformCaliper m_Inspect_AffineTransformCaliper;
	CInspect_RelativeHistogram m_RelativeHistogram;

	CInspect_CircularAnnulusSection_Blob m_InspectCircularBlob;
	CInspect_RectangleAffine_Blob m_InspectRectanbleBlob;

	CMNVStaticGraphicCollection m_sgcRegion;

	CMNVImage m_imgMaster;
	CMNVImage8Grey m_imgPattern;
	CMNVImage8Grey m_imgMask;
	//CMNVImage m_imgSrc;

	CMNVRectangleAffine m_retRegion;

	bool __isResult;
	MNV_InspectResult m_Result;

	double m_dAcceptThreshold;
	double m_dOriginX;
	double m_dOriginY;
	double m_dAngleMin;
	double m_dAngleMax;
	double m_dScaleMin;
	double m_dScaleMax;
	void Load_Pattern();
	bool Excute(int __nMode, CMNVImage & __imgSource, CMNVStaticGraphicCollection & __sgcResult);
	void Save_Pattern();
	//bool Prepare();
	bool GetRegion(CMNVStaticGraphicCollection & __sgcCollection);
	bool GetResult(CMNVStaticGraphicCollection & __sgcCollection);
	STMNV_Model::STMNV_Model() {
	}

	bool Prepare(int __nModel, int __nItem, int __nVision) {
		CMNVLogFile Log(_T("STMNV_Model"), _T("Prepare"), _T("D:\\Log"), _T("MNVision.txt"));

		CString strModel;
		strModel.Format(_T("D:\\Model\\Model%02d_%02d\\Vision.ini"), __nModel, __nItem); 
		m_cdType = (MNVAlgorithm_Type) CMNVIni::GetValue(_T("Algorithm"), _T("Type"), 0, strModel);
		switch(m_cdType) {
		case MNV_AT_CircularCaliper:
			strModel.Format(_T("D:\\Model\\Model%02d_%02d\\PolarUnwrap.ini"), __nModel, __nItem); 

			m_Inspect_PolarUnwrapCaliper.LoadIni(strModel);
			double dCenterX, dCenterY, dInner, dOuter;
			m_Inspect_PolarUnwrapCaliper.m_ImageProcessing.m_Region.GetCircle(dCenterX, dCenterY, dOuter, dInner);

			m_sgcRegion.Clear();
			m_sgcRegion.AddCircleSegment(1, cogColorYellow, dCenterX, dCenterY, dOuter);
			m_sgcRegion.AddCircleSegment(1, cogColorYellow, dCenterX, dCenterY, dInner);
			break;
		case MNV_AT_RelativeHistogram: // [Drill Hole Inspect] Region Histogram
			strModel.Format(_T("D:\\Model\\Model%02d_%02d\\RegionHistogram.ini"), __nModel, __nItem); 
			m_RelativeHistogram.LoadModel(strModel);
			/*m_circleOpen[0].SetCircle(_T("Open1"), strModel);
			m_circleOpen[1].SetCircle(_T("Open2"), strModel);
			m_circleClose[0].SetCircle(_T("Close1"), strModel);
			m_circleClose[1].SetCircle(_T("Close2"), strModel);
			m_dAccept = CMNVIni::GetValue(_T("Result"), _T("Accept"), (double)100, strModel);

			m_sgcRegion.Clear();
			m_sgcRegion.AddGraphic(m_circleOpen[0], 1, cogColorBlue);
			m_sgcRegion.AddGraphic(m_circleOpen[1], 1, cogColorBlue);
			m_sgcRegion.AddGraphic(m_circleClose[0], 1, cogColorRed);
			m_sgcRegion.AddGraphic(m_circleClose[1], 1, cogColorRed);*/
			break;
		case MNV_AT_AffineCaliper:
			strModel.Format(_T("D:\\Model\\Model%02d_%02d\\AffineTransform.ini"), __nModel, __nItem); 
			m_Inspect_AffineTransformCaliper.LoadIni(strModel);
			m_sgcRegion.Clear();
			m_sgcRegion.AddGraphic(m_Inspect_AffineTransformCaliper.m_AlgProcessing.m_Region, 1, cogColorYellow);
			break;
		case MNV_AT_CircularBlob:
			strModel.Format(_T("D:\\Model\\Model%02d_%02d\\CircularBlob.ini"), __nModel, __nItem); 
			m_InspectCircularBlob.Prepare(strModel);
			m_sgcRegion.Clear();
			//m_sgcRegion.AddGraphic(m_Inspect_AffineTransformCaliper.m_AlgProcessing.m_Region, 1, cogColorYellow);
			break;
		case MNV_AT_RectBlob:
			strModel.Format(_T("D:\\Model\\Model%02d_%02d\\RectBlob.ini"), __nModel, __nItem); 
			m_InspectRectanbleBlob.Prepare(strModel);
			m_sgcRegion.Clear();
			break;
			//m_sgcRegion.AddGraphic(m_Inspect_AffineTransformCaliper.m_AlgProcessing.m_Region, 1, cogColorYellow);
		}
		return true;
	}
};

enum MNVAlgorithm_MODE {
	MNVAlgorithm_MDRun
	, MNVAlgorithm_MDManual
	, MNVAlgorithm_MDModel
	, MNVAlgorithm_MDVision
	, MNVAlgorithm_MDSystem
};
enum MNVS_Algorithm {
		Algorithm_START = 0
	,	Algorithm_INIT
	,	Algorithm_WAIT
	,	Algorithm_PREPARE
	,	Algorithm_READY
	,	Algorithm_TRIGGER
	,	Algorithm_RUN
	,	Algorithm_FINISH
	,	Algorithm_RESULT
	,	Algorithm_END
	,	Algorithm_ALARM

	,	Setting_Model
	,	Setting_Vision
	,	Setting_System
};

struct STMNV_VisionResult {
	SourceID m_ID;
	CMNVImage m_imgSource;
	CMNVStaticGraphicCollection m_sgcResult;
	MNV_InspectResult m_nResult; /// 0 Not, 1 Grab, 2,OK, -1 NG
};

class CMNVAlgorithm : public CMNVDevice
{
////// Frame Grabber
private:
	CMNVImage m_imgGrabber;
	int m_IDGrabber;

	CMNVImage m_imgRaw[10];
	STMNV_VisionResult m_stResult[10];
	bool m_isChangeProd;

	int m_maxVision;
	int m_msDelay;

	CMNVFrameGrabbers * m_pFrameGrabbers;
	int m_cntFrameGrabber;
	//int m_nGrabChannel;

public:
	CCamInfo * m_pCamInfo;

	STMNV_Model m_Model;
	void GetResult(int __nIndex, CString &strResult) {
		int nCurrentIDX = m_PLC.GetCurrent_Item() - 1;
		switch(m_stResult[__nIndex].m_nResult) {
		case MNVIR_OK: strResult = _T("OK"); break;
		case MNVIR_NG: strResult = _T("NG"); break;
		case MNVIR_PASS: strResult = _T("PASS"); break;
		default: 
			if(nCurrentIDX == __nIndex) strResult = _T("Inspect");
			else if (nCurrentIDX > __nIndex) strResult = _T("PASS");
			else strResult = _T("");
			break;
		}
	}
	//bool LiveOn(CMNVDisplay & cogDisplay) {
	//	m_pCamInfo[m_nChannel-1].LiveOn(cogDisplay);
	//	return true;
	//}
	bool IsChannel() { return 0 < m_nChannel && m_nChannel <= m_cntFrameGrabber; }
	bool IsExposure(double __dValue) { return (0 < __dValue && __dValue <= 100); }
	bool IsContrast(double __dValue) { return (0 <= __dValue && __dValue <= 1); }
	bool IsBrightness(double __dValue) { return (0 <= __dValue && __dValue <= 1); }

	CCamInfo * CurrentCamInfo() { return &(m_pCamInfo[m_nChannel - 1]); }
	double GetCurrentExposure() { return IsChannel() ?  m_pCamInfo[m_nChannel - 1].GetExposure() : (double)10; }
	double GetCurrentBrightness() { return IsChannel() ?  m_pCamInfo[m_nChannel - 1].GetBrightness() : (double)0; }
	double GetCurrentContrast() { return IsChannel() ?  m_pCamInfo[m_nChannel - 1].GetContrast() : (double)0; }

	bool Cmd_SetExposure(double __dValue) {
		if (IsChannel() && IsExposure(__dValue)) {
			return CurrentCamInfo()->SetExposure(__dValue);
		}
		return false;
	}
	bool Cmd_SetContrast(double __dValue) {
		if (IsChannel() && IsContrast(__dValue)) {
			return CurrentCamInfo()->SetContrast(__dValue);
		}
		return false;
	}
	bool Cmd_SetBrightness(double __dValue) {
		if (IsChannel() && IsBrightness(__dValue)) {
			return CurrentCamInfo()->SetBrightness(__dValue);
		}
		return false;
	}
	void Cmd_LoadCamSetting(LPCTSTR __strFile = NULL, LPCTSTR __strSection = NULL) {
		CString strFile; 
		if (__strFile == NULL) {
			strFile.Format(_T("d:\\Model\\Model%02d_%02d.ini"), m_PLC.GetCurrent_Model(), m_PLC.GetCurrent_Item());
			CMNVFile::CreatePath(strFile);
		}
		else strFile = __strFile;

		CString strSection;
		if (__strSection == NULL) { strSection.Format(_T("Grab_%02d"), m_PLC.GetCurrent_Vision() + 1); }
		else strSection = __strSection;

		m_nChannel = CMNVIni::GetValue(strSection, _T("Channel"), -1, strFile);
		m_stSetting.dContrast = CMNVIni::GetValue(strSection, _T("Contrast"), (double)-1, strFile);
		m_stSetting.dBrightness = CMNVIni::GetValue(strSection, _T("Brightness"), (double)-1, strFile);
		m_stSetting.dExposure = CMNVIni::GetValue(strSection, _T("Exposure"), (double)-1, strFile);
		m_stSetting.msDelay = CMNVIni::GetValue(strSection, _T("Delay"), (int)0, strFile);
		if(IsChannel() && m_stSetting.isCheck()) {
			CurrentCamInfo()->SetCamSetting(m_stSetting);
		}
	}
	void Cmd_SaveCamSetting(LPCTSTR __strFile = NULL, LPCTSTR __strSection = NULL) {
		CString strFile; 
		if (__strFile == NULL) {
			strFile.Format(_T("d:\\Model\\Model%02d_%02d.ini"), m_PLC.GetCurrent_Model(), m_PLC.GetCurrent_Item());
			CMNVFile::CreatePath(strFile);
		}
		else strFile = __strFile;

		CString strSection;
		if (__strSection == NULL) { strSection.Format(_T("Grab_%02d"), m_PLC.GetCurrent_Vision() + 1); }
		else strSection = __strSection;

		if(IsChannel()) {
			CurrentCamInfo()->GetCamSetting(m_stSetting);
		}
		//else m_stSetting.
		CMNVIni::SetValue(strSection, _T("Channel"), m_nChannel, strFile);
		CMNVIni::SetValue(strSection, _T("Contrast"), GetCurrentContrast(), strFile);
		CMNVIni::SetValue(strSection, _T("Brightness"), GetCurrentBrightness(), strFile);
		CMNVIni::SetValue(strSection, _T("Exposure"), GetCurrentExposure(), strFile);

	}

	//void Cmd_
	void Frame_Grab();
	void GetRegion(CMNVStaticGraphicCollection &__sgcRegion) {
		m_Model.GetRegion(__sgcRegion);
	}
	void Grabber_Init() {
		m_IDGrabber = 0;
		m_isLive = false;
		m_isGrab = false;
		m_nChannel = 0;
		m_pFrameGrabbers = new CMNVFrameGrabbers();
		m_cntFrameGrabber = m_pFrameGrabbers->GetCount();
		m_cntFrameGrabber = 2;
		m_pCamInfo = new CCamInfo[m_cntFrameGrabber];

		CMNVFrameGrabber FrmGrabber;
		CString strName;
		for (int nIndex = 0; nIndex < m_cntFrameGrabber; ++nIndex) {
			strName.Format(_T("Channel%d"), nIndex);
			if (m_pFrameGrabbers->GetFrameGrabber(nIndex, FrmGrabber)) {
				m_pCamInfo[nIndex].LoadCamInfo(_T("D:\\Setting"), _T("FrameGrabber.ini"), strName);
				m_pCamInfo[nIndex].SaveCamInfo(_T("D:\\Setting"), _T("FrameGrabber.ini"), strName);
				m_pCamInfo[nIndex].Init(strName, FrmGrabber);
				m_pCamInfo[nIndex].GrabStart();
				FrmGrabber.Release();
			}
			else  m_pCamInfo[nIndex].Init(strName);
		}
		m_pFrameGrabbers->Release();
	}
	void Grabber_Release() {
		for(int nIndex = 0; nIndex < m_cntFrameGrabber; ++nIndex) {
			m_pCamInfo[nIndex].Release();
		}
	}


	void Algorithm_Grab(int __nIndex, CMNVImage & __imgBuffer) {
		if (m_cntFrameGrabber > __nIndex) m_pCamInfo[__nIndex].GetBuffer(__imgBuffer);
	}

	int Algorithm_Result(CMNVImage & __imgBuffer, CMNVStaticGraphicCollection &__sgcResult, int __nID);
	int Algorithm_Result(int __nIndex, CMNVImage & __imgBuffer, CMNVStaticGraphicCollection &__sgcResult, int __nID);
	void Algorithm_Grab(CMNVImage & __imgBuffer) {
		//if (0 > m_idxVision || m_idxVision > 99) return;
		//if (m_imgBuffer[m_idxVision] != NULL)
		//	m_imgBuffer[m_idxVision].Copy(__imgBuffer);
	}
	bool Grabber_GetBuffer(CMNVImage & __imgBuffer) { return m_pCamInfo[m_nChannel-1].GetBuffer(__imgBuffer); }
	bool Grabber_Grab(CMNVImage & __imgBuffer) { return m_pCamInfo[m_nChannel-1].Grab(__imgBuffer); }

	int GetGrabberCount() { return m_maxVision; }
	int GetCurrentGrabber(STCamSetting & __stSetting) {
		if (0 < m_nChannel && m_nChannel <= m_cntFrameGrabber) {
			m_pCamInfo[m_nChannel - 1].GetCamSetting(__stSetting);
			return m_nChannel;
		}
		return -1;
	}
	//bool GetCurrentVision() {
	//}
	bool SetCurrentGrabber(int __nChannel, STCamSetting & __stSetting) {
		if (0 < __nChannel && __nChannel <= m_cntFrameGrabber) {
			m_nChannel = __nChannel;
			m_pCamInfo[m_nChannel - 1].SetCamSetting(__stSetting);
			return true;
		}
		return false;
	}
	bool m_isLive;
	bool m_isGrab;
	void OnLive(bool __isLive = true) {
		if (__isLive) {
			for(int nIndex = 0; nIndex < m_cntFrameGrabber; ++nIndex) {
				m_pCamInfo[m_nChannel-1].GrabStart();
			}
		}
		else {
			for(int nIndex = 0; nIndex < m_cntFrameGrabber; ++nIndex) {
				m_pCamInfo[m_nChannel-1].GrabStop();
			}
		}
	}
	void OnGrab() {
		m_isLive = false;
		m_isGrab = true;
	}
	///// Light Control
public:
	CMNV_LFineControl m_DeviceLFine;
public:
	void Light_Init() {
		m_DeviceLFine.LoadSetting(_T("d:\\Setting\\LightControl.ini"));
		m_DeviceLFine.InitSetting();
		m_DeviceLFine.SaveSetting(_T("d:\\Setting\\LightControl.ini"));
	}
	void Light_LoadSet(int __nSetting) {
		m_DeviceLFine.LoadSetting(_T("d:\\Setting\\LightControl.ini"));
		int nLimit = m_DeviceLFine.GetCount();
		for(int nIndex = 0; nIndex < nLimit; ++nIndex) {
			m_DeviceLFine.SetValue(nIndex, 100);
		}
		m_DeviceLFine.SendValue();
	}
	void Light_Off() {
		int nLimit = m_DeviceLFine.GetCount();
		for(int nIndex = 0; nIndex < nLimit; ++nIndex)
			m_DeviceLFine.SetValue(nIndex, 0);
		m_DeviceLFine.LoadSetting(_T("d:\\Setting\\LightControl.ini"));
		m_DeviceLFine.SendValue();
	}

	int Light_GetChannelCount() { return m_DeviceLFine.GetCount(); }
	int Light_GetChannelValue(int __nIndex) { return m_DeviceLFine.GetValue(__nIndex); }

	void Light_SetValue(int __nIndex, int __nValue) { m_DeviceLFine.SetValue(__nIndex, __nValue); }
	void Light_AddValue(int __nIndex, int __nValue) { m_DeviceLFine.AddValue(__nIndex, __nValue); }
	void Light_SubValue(int __nIndex, int __nValue) { m_DeviceLFine.SubValue(__nIndex, __nValue); }

	void Light_Update() { m_DeviceLFine.SendValue(); }

///// Algorithm
private:
	MNVS_Algorithm m_steAlgorithm;
	MNVAlgorithm_MODE m_mdAlgorithm;
	//int m_nModel;
	//int m_nItem;
public:
	CMNVPLC m_PLC;

	virtual void Thread();
	void Thread_Auto();
	void Thread_Model();
	void Thread_Vision();
	void Thread_System();

	void MNVRelease() {
		EndThread();
		
		m_PLC.Release();

	}
	MNVS_Algorithm GetState() { return m_steAlgorithm; }
	CMNVAlgorithm(void);
	~CMNVAlgorithm(void);
	bool Proc_LoadModel(int __nModel, int __nItem, int __nVision);
	void Proc_SaveModel();
public:
	void Cmd_SetMode(MNVAlgorithm_MODE __algMode) {
		m_mdAlgorithm = __algMode;
	}

	void Create() {
		m_ThreadEvent.Create(TRUE, FALSE);
	}
	void Release() {
		for(int nIndex = 0; nIndex < m_cntFrameGrabber; ++nIndex) {
			m_pCamInfo[nIndex].EndThread();
			m_pCamInfo[nIndex].Release();
		}
		m_pFrameGrabbers->Release();
	}
	void Begin() {
		State_SetSTART();
		m_isStop = false;
		m_ThreadEvent.Create(TRUE, FALSE);
		BeginThread();
	}
	void End() {
		EndThread();
		Release();
	}
	void Run() {
		m_ThreadEvent.SetEvent();
	}
	void Stop() { m_isStop = true;
		m_ThreadEvent.ResetEvent();
	}
	void Pause() {
		m_ThreadEvent.ResetEvent();
	}
	bool m_isStop;
	CMNVEvent m_ThreadEvent;
	bool IsAlgorithmEnable() { return (m_ThreadEvent.Wait(0) == MNVWR_Event); }
	void AlgorithmEnable(bool __isEnable) { 
		if (__isEnable) {
			State_SetSTART();
			m_ThreadEvent.SetEvent();
		}
		else {
			m_ThreadEvent.ResetEvent();
		}
	}

	//int m_nLiveChannel;
	STCamSetting m_stSetting;
	int m_nChannel;
	void Cmd_SelectChannel(int __nChannel) { m_nChannel = __nChannel; }
	void ProcPreProcess() {
		/// Stop 신호 확인
		if (m_isStop) {
			State_SetSTART();
			m_ThreadEvent.ResetEvent();
		}

		/// Algorithm 활성 상태 확인 .... 실패시 Algorithm Alarm
		if (m_ThreadEvent.Wait() != MNVWR_Event) {
			State_SetALARM();
			//Vision_SetAlarm();
		}
	}
	void Cmd_LoadLight(LPCTSTR __strFile = NULL, LPCTSTR __strSection = NULL) {	// Load Light Setting
		CString strFile; 
		if (__strFile == NULL) {
			strFile.Format(_T("d:\\Model\\Model%02d_%02d.ini"), m_PLC.GetCurrent_Model(), m_PLC.GetCurrent_Item());
			CMNVFile::CreatePath(strFile);
		}
		else strFile = __strFile;

		CString strSection;
		if (__strSection == NULL) { strSection.Format(_T("Grab_%02d"), m_PLC.GetCurrent_Vision() + 1); }
		else strSection = __strSection;

		int nLimit = m_DeviceLFine.GetCount();
		CString strTemp;
		int nValue;
		m_DeviceLFine.SendBegin();
		for(int nIndex = 0; nIndex < nLimit; ++nIndex) {
			strTemp.Format(_T("Light_%02d"), nIndex);
			nValue = CMNVIni::GetValue(strSection, strTemp, 0, strFile);

			if(nValue != m_DeviceLFine.GetValue(nIndex)) {
				m_DeviceLFine.SetValue(nIndex, nValue );
				m_DeviceLFine.SendValue(nIndex);
			}
		}
		m_DeviceLFine.SendEnd();
		/*m_DeviceLFine.SendValue();*/
	}
	void Cmd_SaveLight(LPCTSTR __strFile = NULL, LPCTSTR __strSection = NULL) {
		CString strFile; 
		if (__strFile == NULL) {
			strFile.Format(_T("d:\\Model\\Model%02d_%02d.ini"), m_PLC.GetCurrent_Model(), m_PLC.GetCurrent_Item());
			CMNVFile::CreatePath(strFile);
		}
		else strFile = __strFile;

		CString strSection;
		if (__strSection == NULL) { strSection.Format(_T("Grab_%02d"), m_PLC.GetCurrent_Vision() + 1); }
		else strSection = __strSection;

		int nLimit = m_DeviceLFine.GetCount();
		CString strKey;
		//int nValue;
		for(int nIndex = 0; nIndex < nLimit; ++nIndex) {
			strKey.Format(_T("Light_%02d"), nIndex);
			CMNVIni::SetValue(strSection, strKey, m_DeviceLFine.GetValue(nIndex), strFile);
		}
		m_DeviceLFine.SendValue();
	}

	void ProcWait();
	void ProcPrepare();
	void ProcReady();
	void ProcTrigger();
	void ProcResult();
	void ProcFinish();
	void ProcAlarm();
	void ProcRun();

	/// SetState Function
	void State_SetSTART() {
		m_steAlgorithm = Algorithm_START;
		m_PLC.SetSTART();
	}
	void State_SetINIT() {
		m_steAlgorithm = Algorithm_INIT;
	}
	void State_SetWAIT() {
		m_steAlgorithm = Algorithm_WAIT;
		m_PLC.SetWAIT();
	}
	void State_SetPREPARE() {
		m_steAlgorithm = Algorithm_PREPARE;
		m_PLC.SetPREPARE();
	}
	void State_SetREADY() {
		m_steAlgorithm = Algorithm_READY;
		m_PLC.SetREADY();
	}
	void State_SetTRIGGER() {
		m_steAlgorithm = Algorithm_TRIGGER;
		m_PLC.SetTRIGGER();
	}
	void State_SetINSPECT() {
		m_steAlgorithm = Algorithm_RUN;
		m_PLC.SetINSPECT();
	}
	void State_SetRESULT() {
		m_steAlgorithm = Algorithm_RESULT;
	}
	void State_SetFINISH(bool __isOK) {
		m_steAlgorithm = Algorithm_FINISH;
		m_PLC.SetFINISH(__isOK);
	}
	void State_SetEND() {
		m_steAlgorithm = Algorithm_END;
	}
	void State_SetALARM() {
		m_steAlgorithm = Algorithm_ALARM;
		m_PLC.SetALARM();
	}

	void State_SetMODEL() {
		m_steAlgorithm = Setting_Model;
		m_PLC.SetNONE();
	}
	void State_SetVISION() {
		m_steAlgorithm = Setting_Vision;
		m_PLC.SetNONE();
	}
	void State_SetSYSTEM() {
		m_steAlgorithm = Setting_System;
		m_PLC.SetNONE();
	}
};

