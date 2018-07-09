#pragma once
#include "ControllerList.h"	//??MNVButton은 왜 참조불가능입니까??

// ModelSet 대화 상자입니다.

class ModelSet : public CDialogEx
{
	DECLARE_DYNAMIC(ModelSet)

public:
	ModelSet(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~ModelSet();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ModelSet };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedModelname();
	afx_msg void OnBnClickedModelnamevalue();
	afx_msg void OnBnClickedModelcomport();
	afx_msg void OnBnClickedModelcomportvalue();
	afx_msg void OnBnClickedModelauto();
	afx_msg void OnBnClickedModelbaudrate();
	afx_msg void OnBnClickedModelbaudratevalue();
	afx_msg void OnBnClickedModelparity();
	afx_msg void OnBnClickedModelparityvalue();
	afx_msg void OnBnClickedModeldatabits();
	afx_msg void OnBnClickedModeldatabitsvalue();
	afx_msg void OnBnClickedModelstopbits();
	afx_msg void OnBnClickedModelstopbitsvalue();
	CMNVButton m_modelAuto;
	CMNVButton m_modelBaudRate;
	CMNVButton m_modelBaudRateValue;
	CMNVButton m_modelComPort;
	CMNVButton m_modelComPortValue;
	CMNVButton m_modelDataBits;
	CMNVButton m_ModelDataBitsValue;
	CMNVButton m_modelName;
	CMNVButton m_modelNameValue;
	CMNVButton m_modelParity;
	CMNVButton m_modelParityValue;
	CMNVButton m_modelStopBits;
	CMNVButton m_modelStopBitsValue;
	CMNVButton m_lightChannel;
	CMNVButton m_lightChannelValue;
	CMNVButton m_lightMax;
	CMNVButton m_lightMaxValue;
	afx_msg void OnBnClickedLightchannel();
	afx_msg void OnBnClickedLightchannelvalue();
	afx_msg void OnBnClickedLightmax();
	afx_msg void OnBnClickedLightmaxvalue();
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	virtual BOOL OnInitDialog();
	void On_WindTopPos(void);
	
};
