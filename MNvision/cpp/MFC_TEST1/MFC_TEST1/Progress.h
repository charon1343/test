#pragma once


// Progress 대화 상자입니다.

class Progress : public CDialogEx
{
	DECLARE_DYNAMIC(Progress)

public:
	Progress(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~Progress();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_PROGRESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CButton m_button1;
	CButton m_button2;
	CProgressCtrl m_progress1;
};
