
// SetLightControllerDlg.h : 헤더 파일
//
#include "ControllerList.h"
#include "ModelSet.h"

#pragma once


// CSetLightControllerDlg 대화 상자
class CSetLightControllerDlg : public CDialogEx
{
// 생성입니다.
public:
	CSetLightControllerDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
	ModelSet m_modelSet;
	ControllerList m_controllerList;

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SETLIGHTCONTROLLER_DIALOG };

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
};
