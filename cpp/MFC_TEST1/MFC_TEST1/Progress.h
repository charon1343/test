#pragma once


// Progress ��ȭ �����Դϴ�.

class Progress : public CDialogEx
{
	DECLARE_DYNAMIC(Progress)

public:
	Progress(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~Progress();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PROGRESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CButton m_button1;
	CButton m_button2;
	CProgressCtrl m_progress1;
};
