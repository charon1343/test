#pragma once
#include "resource.h"
// CDlg_CtrlLight2Ch 대화 상자입니다.
#include "Dlg_PADNumeric.h"
#include "MNVAlgorithm.h"

class CDlg_CtrlLight2Ch : public CMNVDialogEx
{
	DECLARE_DYNAMIC(CDlg_CtrlLight2Ch)
	CMNVAlgorithm * m_pAlgorithm;
public:
	CDlg_CtrlLight2Ch(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_CtrlLight2Ch();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CTRL_LIGHT2 };
	void Create(CMNVAlgorithm * __pAlgorithm, CWnd * __pWnd, CMNVDialogEx * __pParent) {
		m_pAlgorithm = __pAlgorithm;
		CMNVDialogEx::Create(IDD, __pWnd, __pParent);
	}

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CMNVStatic m_ctrlLabel[4];
	CMNVButton m_ctrlValue[4];
	CMNVButton m_ctrlBtnAdd[4];
	CMNVButton m_ctrlBtnSub[4];

	CMNVButton m_ctrlValue_Step;
	CMNVStatic m_ctrlLabel_Step;
	virtual BOOL OnInitDialog();
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	afx_msg void OnBnClickedLight2chStep();
	afx_msg void OnBnClickedLight2chCh1value();
	afx_msg void OnBnClickedLight2chCh2value();
	afx_msg void OnBnClickedLight2chCh1sub();
	afx_msg void OnBnClickedLight2chCh2sub();
	afx_msg void OnBnClickedLight2chCh1add();
	afx_msg void OnBnClickedLight2chCh2add();
	afx_msg void OnBnClickedLight2chCh3sub();
	afx_msg void OnBnClickedLight2chCh3value();
	afx_msg void OnBnClickedLight2chCh3add();

	void OnReflash() {
		if (m_pAlgorithm == NULL) return;

		m_ctrlValue[0].SetItemData(m_pAlgorithm->Light_GetChannelValue(0));
		m_ctrlValue[1].SetItemData(m_pAlgorithm->Light_GetChannelValue(1));
		m_ctrlValue[2].SetItemData(m_pAlgorithm->Light_GetChannelValue(2));
		m_ctrlValue[3].SetItemData(m_pAlgorithm->Light_GetChannelValue(3));
	}
	afx_msg void OnBnClickedLight2chCh4sub();
	afx_msg void OnBnClickedLight2chCh4value();
	afx_msg void OnBnClickedLight2chCh4add();
};
