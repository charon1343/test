#pragma once


// class1 ��ȭ �����Դϴ�.

class class1 : public CDialogEx
{
	DECLARE_DYNAMIC(class1)

public:
	class1(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~class1();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_BUTTON1_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
