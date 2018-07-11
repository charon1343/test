
// ButtonUIDlg.h : ��� ����
//
#include "TcpIpNum.h"
#include "Signal.h"
#pragma once


// CButtonUIDlg ��ȭ ����
class CButtonUIDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CButtonUIDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	TcpIpNum m_dlgTop;
	Signal m_dlgBottomLeft;
	Signal m_dlgBottomRight;
	

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_BUTTONUI_DIALOG };

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
	void On_InitTextLeft(void);
	void On_InitTextRight(void);
};
