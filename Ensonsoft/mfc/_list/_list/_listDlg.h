
// _listDlg.h : ��� ����
//

#pragma once


// C_listDlg ��ȭ ����
class C_listDlg : public CDialogEx
{
// �����Դϴ�.
public:
	C_listDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD__LIST_DIALOG };

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
	CString m_strName;
	CString m_strNum;
	CString m_strCell;
	BOOL m_chA;
	BOOL m_chB;
	CButton m_rOnline;
	CComboBox m_cbPoint1;
	CComboBox m_cbPoint2;
	CListCtrl m_listView;
	int m_nSelected;
	void Init(void);
	afx_msg void OnClickedButtonInput();
	afx_msg void OnClickedButtonDel();
	afx_msg void OnClickedButtonInit();
	afx_msg void OnClickedButtonExit();
};
