#pragma once
#include "MNVButton.h"


// Polarity ��ȭ �����Դϴ�.

class Polarity : public CDialogEx
{
	DECLARE_DYNAMIC(Polarity)
public:
	int m_nValue;
	Polarity(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~Polarity();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIAPOLARITY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
