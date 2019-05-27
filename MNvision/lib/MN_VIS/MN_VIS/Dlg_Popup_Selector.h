#pragma once
#include "resource.h"

// CDlg_Popup_Selector 대화 상자입니다.

class CDlg_Popup_Selector : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_Popup_Selector)

public:
	CDlg_Popup_Selector(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_Popup_Selector();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_POPUP_Select };
	CString * m_strData;
	int m_nSelect;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CMNVButton m_ctrlSelect[5];
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedSelect1() { m_nSelect = 1; OnReflash(); }
	afx_msg void OnClickedSelect2() { m_nSelect = 2; OnReflash(); }
	afx_msg void OnClickedSelect3() { m_nSelect = 3; OnReflash(); }
	afx_msg void OnClickedSelect4() { m_nSelect = 4; OnReflash(); }
	afx_msg void OnClickedSelect5() { m_nSelect = 5; OnReflash(); }

	void OnReflash() {
		m_ctrlSelect[0].SetCheck(m_nSelect == 1 ? TRUE : FALSE);
		m_ctrlSelect[1].SetCheck(m_nSelect == 2 ? TRUE : FALSE);
		m_ctrlSelect[2].SetCheck(m_nSelect == 3 ? TRUE : FALSE);
		m_ctrlSelect[3].SetCheck(m_nSelect == 4 ? TRUE : FALSE);
		m_ctrlSelect[4].SetCheck(m_nSelect == 5 ? TRUE : FALSE);
	}
};
