#include "MNVHistogram.h"

void CMNVHistogramResult::Create()
{
	CoCreateInstance(CLSID_CogHistogramResult);
}
void CMNVHistogramResult::Release()
{
	if (p != NULL) Detach()->Release();
	CComPtr<ICogHistogramResult>::Release();
}
CMNVHistogramResult::CMNVHistogramResult() : CComPtr<ICogHistogramResult>()
{
}
CMNVHistogramResult::~CMNVHistogramResult() {
	Release();
}
long CMNVHistogramResult::GetMinimum(long __Default) {	// 최소값
	if (p != NULL) {
		long Val;
		if (SUCCEEDED( p->get_Minimum(&Val) ) ) {
			return Val;
		}
	}
	return __Default;
}
long CMNVHistogramResult::GetMaximum(long __Default) {		// 최대값
	if (p != NULL) {
		long Val;
		if (SUCCEEDED( p->get_Maximum(&Val) ) ) {
			return Val;
		}
	}
	return __Default;
}
long CMNVHistogramResult::GetMedian(long __Default) {	// 중앙값
	if (p != NULL) {
		long Val;
		if (SUCCEEDED( p->get_Median(&Val) ) ) {
			return Val;
		}
	}
	return __Default;
}
long CMNVHistogramResult::GetMode(long __Default) {	// 모드
	if (p != NULL) {
		long Val;
		if (SUCCEEDED( p->get_Mode(&Val) ) ) {
			return Val;
		}
	}
	return __Default;
}
double CMNVHistogramResult::GetMean(double __Default) {	// 평균
	if (p != NULL) {
		double Val;
		if (SUCCEEDED( p->get_Mean(&Val) ) ) {
			return Val;
		}
	}
	return __Default;
}
double CMNVHistogramResult::GetMeanPercent(double __Default) {	// 평균
	if (p != NULL) {
		double Val;
		if (SUCCEEDED( p->get_Mean(&Val) ) ) {
			return Val * (double)100 / (double)256;
		}
	}
	return __Default;
}
double CMNVHistogramResult::GetStandardDeviation(double __Default) {	// 표준 편차
	if (p != NULL) {
		double Val;
		if (SUCCEEDED( p->get_StandardDeviation(&Val) ) ) {
			return Val;
		}
	}
	return __Default;
}
double CMNVHistogramResult::GetVariance(double __Default) {	// 분산
	if (p != NULL) {
		double Val;
		if (SUCCEEDED( p->get_Variance(&Val) ) ) {
			return Val;
		}
	}
	return __Default;
}
long CMNVHistogramResult::GetNumSamples(long __Default) {	// 샘플
	if (p != NULL) {
		long Val;
		if (SUCCEEDED( p->get_NumSamples(&Val) ) ) {
			return Val;
		}
	}
	return __Default;
}



bool CMNVHistogram::Create()
{
	Release();
	return SUCCEEDED( CoCreateInstance(CLSID_CogHistogram) );
}
void CMNVHistogram::Release() {
	if (p != NULL) { Detach()->Release(); }
	CComPtr<ICogHistogram>::Release();
	m_Result.Release();
}

CMNVHistogram::CMNVHistogram() { Create(); }
CMNVHistogram::~CMNVHistogram() { Release(); }
bool CMNVHistogram::Execute(CMNVImage8Grey & __imgGrey, CMNVRegion & __Region, CogHistogramBinModeConstants __BinMode, CogRegionModeConstants __RegionMode, long __nNumBins)
{
	if(p != NULL) {
		m_Result.Release();
		if (FAILED( p->put_BinMode(__BinMode) ) ) return false;
		if (__BinMode != cogHistogramBinModeAuto )
			if ( FAILED( p->put_NumBins(__nNumBins) ) ) return false;
		if (FAILED( p->put_RegionMode(__RegionMode) )) return false;

		return SUCCEEDED( p->Execute(__imgGrey, __Region, &m_Result) );
	}
	return false;
}
bool CMNVHistogram::Execute(CMNVImage & __imgSrc, CMNVRegion & __Region, CogHistogramBinModeConstants __BinMode, CogRegionModeConstants __RegionMode, long __nNumBins)
{
	CMNVImage8Grey __imgRaw;
	__imgSrc.Copy(__imgRaw);
	if(p != NULL) {
		m_Result.Release();
		if (FAILED( p->put_BinMode(__BinMode) ) ) return false;
		if (__BinMode != cogHistogramBinModeAuto )
			if ( FAILED( p->put_NumBins(__nNumBins) ) ) return false;
		if (FAILED( p->put_RegionMode(__RegionMode) )) return false;

		return SUCCEEDED( p->Execute(__imgSrc, __Region, &m_Result) );
	}
	return false;
}

