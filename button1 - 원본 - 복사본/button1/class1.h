#pragma once


// class1 대화 상자입니다.

class class1 : public CDialogEx
{
	DECLARE_DYNAMIC(class1)

public:
	class1(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~class1();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_BUTTON1_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
