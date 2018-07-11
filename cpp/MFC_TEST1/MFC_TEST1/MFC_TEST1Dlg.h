
// MFC_TEST1Dlg.h : 헤더 파일
//
#include "dlg_CheckBox.h"
#include "Progress.h"

#pragma once


// CMFC_TEST1Dlg 대화 상자
class CMFC_TEST1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMFC_TEST1Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
	dlg_CheckBox dlg_checkbox;
	Progress dlg_progress;

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MFC_TEST1_DIALOG };

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
	afx_msg void OnBnClickedCheckbox();
	CButton m_checkBox;
	afx_msg void OnBnClickedProgress();
};
