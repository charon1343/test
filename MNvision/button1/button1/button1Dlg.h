
// button1Dlg.h : 헤더 파일
//
#include "class2.h"
#include "class3.h"
#include "class4.h"
#include "class5.h"


#pragma once


// Cbutton1Dlg 대화 상자
class Cbutton1Dlg : public CDialogEx
{
// 생성입니다.
public:
	Cbutton1Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
	class2 m_dlg1;
	class3 m_dlg2;
	class4 m_dlg3;
	class5 m_dlg4;


// 대화 상자 데이터입니다.
	enum { IDD = IDD_BUTTON1_DIALOG };

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
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	CMNVButton m_ctrlCheck1;
	CMNVButton m_ctrlCheck2;
	CMNVButton m_ctrlCheck3;
	CMNVButton m_ctrlCheck4;
	
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);

	void On_WindPos();
	
};
