#pragma once


// class3 ��ȭ �����Դϴ�.

class class3 : public CDialogEx
{
	DECLARE_DYNAMIC(class3)

public:
	class3(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~class3();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
