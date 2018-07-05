#pragma once


// CenterX 대화 상자입니다.

class CenterX : public CDialogEx
{
	DECLARE_DYNAMIC(CenterX)

public:
	CenterX(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CenterX();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CENTERX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit;
	CButton m_Sel1;
	CButton m_Sel2;
	CButton m_Sel3;
	CButton m_Sel4;
	CButton m_Sel5;
	CButton m_Sel6;
	CButton m_Sel7;
	CButton m_Sel8;
	CButton m_Sel9;
	CButton m_Sel0;
	CButton m_SelChangSign;
	CButton m_SelPoint;
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	CString value;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton18();
};
