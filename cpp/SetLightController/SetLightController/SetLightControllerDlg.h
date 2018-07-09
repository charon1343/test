
// SetLightControllerDlg.h : ��� ����
//
#include "ControllerList.h"
#include "ModelSet.h"

#pragma once


// CSetLightControllerDlg ��ȭ ����
class CSetLightControllerDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CSetLightControllerDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	ModelSet m_modelSet;
	ControllerList m_controllerList;

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SETLIGHTCONTROLLER_DIALOG };

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
	void On_WindPos(void);
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
};
