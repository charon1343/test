#pragma once
#include "MNVButton.h"


// Polarity 대화 상자입니다.

class Polarity : public CDialogEx
{
	DECLARE_DYNAMIC(Polarity)
public:
	int m_nValue;
	Polarity(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~Polarity();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIAPOLARITY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	CMNVButton m_DontCare;
	CMNVButton m_DarkToLight;
	CMNVButton m_LightToDark;
	afx_msg void OnBnClickedCheck5();
	afx_msg void OnBnClickedCheck6();
	afx_msg void OnBnClickedCheck7();
};
