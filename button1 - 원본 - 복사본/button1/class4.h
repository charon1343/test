#pragma once


// class4 ��ȭ �����Դϴ�.

class class4 : public CDialogEx
{
	DECLARE_DYNAMIC(class4)

public:
	class4(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~class4();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
