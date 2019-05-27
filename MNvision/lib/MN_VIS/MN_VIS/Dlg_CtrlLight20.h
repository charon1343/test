#pragma once


// CDlg_CtrlLight20 대화 상자입니다.
#include "LightControl\CMNV_LFineControl.h"
#include "MNVAlgorithm.h"

class CDlg_CtrlLight20 : public CMNVDialogEx
{
	CString m_strFilePath;
	DECLARE_DYNAMIC(CDlg_CtrlLight20)
	int m_IDChannel[20];
	//CMNV_LFineControl * m_pDeviceLFine;
public:
	//void SetLightControl(CMNV_LFineControl * __pCtrl) { m_pDeviceLFine = __pCtrl; }
	CMNVButton m_ctrlBtn_Channel[20];

	CDlg_CtrlLight20(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_CtrlLight20();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CTRL_LIGHT20 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedLightBtnadd();
	afx_msg void OnBnClickedLightBtnset();
	virtual BOOL OnInitDialog();
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	afx_msg void OnBnClickedLightAll();
	afx_msg void OnBnClickedLightDf();
	afx_msg void OnBnClickedLightLa();
	afx_msg void OnBnClickedLightMa();
	afx_msg void OnBnClickedLightHa();
	afx_msg void OnBnClickedLightFr();
	afx_msg void OnBnClickedLight12h();
	afx_msg void OnBnClickedLight3h();
	afx_msg void OnBnClickedLight6h();
	afx_msg void OnBnClickedLight9h();

	void Reflash(CMNVAlgorithm & __Algorithm) {
		int nCount = __Algorithm.Light_GetChannelCount();
		nCount = (nCount > 20) ? 20 : nCount;
		for(int nIndex = 0; nIndex < nCount; ++nIndex)
			SetItemData(m_IDChannel[nIndex], __Algorithm.Light_GetChannelValue(nIndex));
	}
	afx_msg void OnBnClickedLightBtnsub();
};
