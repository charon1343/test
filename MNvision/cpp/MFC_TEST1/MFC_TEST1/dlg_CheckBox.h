#pragma once


// dlg_CheckBox ��ȭ �����Դϴ�.

class dlg_CheckBox : public CDialogEx
{
	DECLARE_DYNAMIC(dlg_CheckBox)

public:
	dlg_CheckBox(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~dlg_CheckBox();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CHECKBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
//	CButton m_check1;
//	CEdit m_edit1;
	BOOL m_check1;
	CString m_edit1;
	afx_msg void OnBnClickedCheck1();
};
