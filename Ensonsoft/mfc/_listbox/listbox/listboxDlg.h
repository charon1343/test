
// listboxDlg.h : ��� ����
//

#pragma once


// ClistboxDlg ��ȭ ����
class ClistboxDlg : public CDialogEx
{
// �����Դϴ�.
public:
	ClistboxDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_LISTBOX_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listMeal;
	CListBox m_listDessert;
	CListBox m_listResult;
	afx_msg void OnClickedButtonMeal();
	afx_msg void OnClickedButtonDessert();
	CString m_strEtc;
	afx_msg void OnClickedButtonEtc();
	afx_msg void OnClickedButtonDel();
	afx_msg void OnClickedButtonReset();
};
