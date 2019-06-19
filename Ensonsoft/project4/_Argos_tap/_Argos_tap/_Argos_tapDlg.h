
// _Argos_tapDlg.h : 헤더 파일
//

#pragma once


// C_Argos_tapDlg 대화 상자
class C_Argos_tapDlg : public CDialogEx
{
// 생성입니다.
public:
	C_Argos_tapDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD__ARGOS_TAP_DIALOG };

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
	BOOL m_check_tap5_check1;
	BOOL m_check_tap5_check2;
	BOOL m_check_tap5_check3;
	CString m_combo_tap4_combo1;
	CString m_edit_tap1_edit1;
	CString m_edit_tap2_edit1;
	CString m_edit_tap2_edit2;
	CString m_edit_tap3_edit1;
	CString m_edit_tap4_edit1;
	CString m_edit_tap4_edit2;
	CString m_edit_tap5_edit1;
	CString m_edit_tap5_edit2;
	CString m_edit_tap5_edit3;
	CString m_edit_tap5_edit4;
	CTabCtrl m_tabArea;
	afx_msg void OnSelchangeTabArea(NMHDR *pNMHDR, LRESULT *pResult);
};
