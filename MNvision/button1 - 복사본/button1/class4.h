#pragma once


// class4 대화 상자입니다.

class class4 : public CDialogEx
{
	DECLARE_DYNAMIC(class4)

public:
	class4(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~class4();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
