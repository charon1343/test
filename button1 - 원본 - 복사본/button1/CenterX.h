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
};
