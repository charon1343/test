
// MFC_TEST1Dlg.h : ��� ����
//
#include "dlg_CheckBox.h"
#include "Progress.h"

#pragma once


// CMFC_TEST1Dlg ��ȭ ����
class CMFC_TEST1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMFC_TEST1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	dlg_CheckBox dlg_checkbox;
	Progress dlg_progress;

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MFC_TEST1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheckbox();
	CButton m_checkBox;
	afx_msg void OnBnClickedProgress();
};
