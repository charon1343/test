#pragma once
#include "resource.h"

// CDlg_CtrlPattern ��ȭ �����Դϴ�.

class CDlg_CtrlPattern : public CMNVDialogEx
{
	DECLARE_DYNAMIC(CDlg_CtrlPattern)

public:
	CDlg_CtrlPattern(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlg_CtrlPattern();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CTRL_PATTERN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	afx_msg void OnBnClickedPatternShowmaster() {
		m_pParent->OnCmd_Command(CMD_Pattern_ShowMaster, 0, 0);
	}
	afx_msg void OnBnClickedPatternSetpattern() {
		m_pParent->OnCmd_Command(CMD_Pattern_SetPattern, 0, 0);
	}
};
