#pragma once
#include "Polarity.h"
#include "CenterX.h"


// class2 ��ȭ �����Դϴ�.

class class2 : public CDialogEx
{
	DECLARE_DYNAMIC(class2)

public:
	class2(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~class2();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CMNVButton m_FindLine;
	CMNVButton m_Calipers;
	CMNVButton m_CalipersValue;
	CMNVButton m_Projection;
	CMNVButton m_ProjectionValue;
	CMNVButton m_Search;
	CMNVButton m_SearchValue;
	CMNVButton m_Polarity;
	CMNVButton m_DarkToLight;
	CMNVButton m_Threashold;
	CMNVButton m_ThreasholdValue;
	CMNVButton m_HalfPixel;
	CMNVButton m_HalfPixelValue;
	CMNVButton m_Ignore;
	CMNVButton m_IgnoreValue;
	CButton m_Find;

	void On_WindPosACL();
	
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	afx_msg void OnBnClickedButton11();

	Polarity m_polarity;
	CenterX m_Centerx;


	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton10();
};
