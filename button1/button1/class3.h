#pragma once


// class3 대화 상자입니다.

class class3 : public CDialogEx
{
	DECLARE_DYNAMIC(class3)

public:
	class3(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~class3();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
