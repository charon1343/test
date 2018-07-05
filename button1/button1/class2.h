#pragma once
#include "Polarity.h"
#include "CenterX.h"


// class2 대화 상자입니다.

class class2 : public CDialogEx
{
	DECLARE_DYNAMIC(class2)

public:
	class2(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~class2();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
