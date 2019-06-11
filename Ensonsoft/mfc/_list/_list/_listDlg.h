
// _listDlg.h : 헤더 파일
//

#pragma once


// C_listDlg 대화 상자
class C_listDlg : public CDialogEx
{
// 생성입니다.
public:
	C_listDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD__LIST_DIALOG };

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
	CString m_strName;
	CString m_strNum;
	CString m_strCell;
	BOOL m_chA;
	BOOL m_chB;
	CButton m_rOnline;
	CComboBox m_cbPoint1;
	CComboBox m_cbPoint2;
	CListCtrl m_listView;
	int m_nSelected;
	void Init(void);
	afx_msg void OnClickedButtonInput();
	afx_msg void OnClickedButtonDel();
	afx_msg void OnClickedButtonInit();
	afx_msg void OnClickedButtonExit();
};
