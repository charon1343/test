#pragma once
#include "MNVCogClass.h"
#include "MNVRegion.h"

class CMNVHistogramResult : public CComPtr<ICogHistogramResult>
{
public:
	void Create();
	void Release();
public:
	CMNVHistogramResult();
	~CMNVHistogramResult();
	long GetMinimum(long __Default = 0);				// 최소값
	long GetMaximum(long __Default = 0);				// 최대값
	long GetMedian(long __Default = 0);					// 중앙값
	long GetMode(long __Default = 0);					// 모드
	double GetMean(double __Default = 0);				// 평균
	double GetMeanPercent(double __default = 0);
	double GetStandardDeviation(double __Default = 0);	// 표준 편차
	double GetVariance(double __Default = 0);			// 분산
	long GetNumSamples(long __Default = 0);				// 샘플
};


class CMNVHistogram : public CComPtr<ICogHistogram>
{
	CMNVHistogramResult m_Result;
public:
	bool Create();
	void Release();
public:
	CMNVHistogram();
	~CMNVHistogram();
	bool Execute(CMNVImage8Grey & __imgGrey, CMNVRegion & __Region, CogHistogramBinModeConstants __BinMode, CogRegionModeConstants __RegionMode, long __nNumBins = 0);
	bool Execute(CMNVImage & __imgSrc, CMNVRegion & __Region
		, CogHistogramBinModeConstants __BinMode = cogHistogramBinModeAuto
		, CogRegionModeConstants __RegionMode = cogRegionModePixelAlignedBoundingBoxAdjustMask
		, long __nNumBins = 0);
	long GetMinimum(long __Default = 0) { return m_Result.GetMinimum(__Default); }				// 최소값
	long GetMaximum(long __Default = 0) { return m_Result.GetMaximum(__Default); }				// 최대값
	long GetMedian(long __Default = 0) { return m_Result.GetMedian(__Default); }					// 중앙값
	long GetMode(long __Default = 0) { return m_Result.GetMode(__Default); }					// 모드
	double GetMean(double __Default = 0) { return m_Result.GetMean(__Default); }				// 평균
	double GetMeanPercnet(double __Default = 0) { return m_Result.GetMean(__Default) * 100.0 / 256.0; }				// 평균
	
	double GetStandardDeviation(double __Default = 0) { return m_Result.GetStandardDeviation(__Default); }	// 표준 편차
	double GetVariance(double __Default = 0) { return m_Result.GetVariance(__Default); }			// 분산
	long GetNumSamples(long __Default = 0) { return m_Result.GetNumSamples(__Default); }				// 샘플
};

