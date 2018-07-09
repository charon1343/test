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
	long GetMinimum(long __Default = 0);				// �ּҰ�
	long GetMaximum(long __Default = 0);				// �ִ밪
	long GetMedian(long __Default = 0);					// �߾Ӱ�
	long GetMode(long __Default = 0);					// ���
	double GetMean(double __Default = 0);				// ���
	double GetMeanPercent(double __default = 0);
	double GetStandardDeviation(double __Default = 0);	// ǥ�� ����
	double GetVariance(double __Default = 0);			// �л�
	long GetNumSamples(long __Default = 0);				// ����
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
	long GetMinimum(long __Default = 0) { return m_Result.GetMinimum(__Default); }				// �ּҰ�
	long GetMaximum(long __Default = 0) { return m_Result.GetMaximum(__Default); }				// �ִ밪
	long GetMedian(long __Default = 0) { return m_Result.GetMedian(__Default); }					// �߾Ӱ�
	long GetMode(long __Default = 0) { return m_Result.GetMode(__Default); }					// ���
	double GetMean(double __Default = 0) { return m_Result.GetMean(__Default); }				// ���
	double GetMeanPercnet(double __Default = 0) { return m_Result.GetMean(__Default) * 100.0 / 256.0; }				// ���
	
	double GetStandardDeviation(double __Default = 0) { return m_Result.GetStandardDeviation(__Default); }	// ǥ�� ����
	double GetVariance(double __Default = 0) { return m_Result.GetVariance(__Default); }			// �л�
	long GetNumSamples(long __Default = 0) { return m_Result.GetNumSamples(__Default); }				// ����
};

