#pragma once


// CenterX ��ȭ �����Դϴ�.

class CenterX : public CDialogEx
{
	DECLARE_DYNAMIC(CenterX)

public:
	CenterX(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CenterX();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CENTERX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
