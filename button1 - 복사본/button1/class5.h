#pragma once


// class5 ��ȭ �����Դϴ�.

class class5 : public CDialogEx
{
	DECLARE_DYNAMIC(class5)

public:
	class5(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~class5();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
