
// ButtonUIDlg.h : 헤더 파일
//
#include "TcpIpNum.h"
#include "Signal.h"
#pragma once


// CButtonUIDlg 대화 상자
class CButtonUIDlg : public CDialogEx
{
// 생성입니다.
public:
	CButtonUIDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
	TcpIpNum m_dlgTop;
	Signal m_dlgBottomLeft;
	Signal m_dlgBottomRight;
	

// 대화 상자 데이터입니다.
	enum { IDD = IDD_BUTTONUI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
