
// _Argos_tapDlg.h : ��� ����
//

#pragma once


// C_Argos_tapDlg ��ȭ ����
class C_Argos_tapDlg : public CDialogEx
{
// �����Դϴ�.
public:
	C_Argos_tapDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD__ARGOS_TAP_DIALOG };

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
	BOOL m_check_tap5_check1;
	BOOL m_check_tap5_check2;
	BOOL m_check_tap5_check3;
	CString m_combo_tap4_combo1;
	CString m_edit_tap1_edit1;
	CString m_edit_tap2_edit1;
	CString m_edit_tap2_edit2;
	CString m_edit_tap3_edit1;
	CString m_edit_tap4_edit1;
	CString m_edit_tap4_edit2;
	CString m_edit_tap5_edit1;
	CString m_edit_tap5_edit2;
	CString m_edit_tap5_edit3;
	CString m_edit_tap5_edit4;
	CTabCtrl m_tabArea;
	afx_msg void OnSelchangeTabArea(NMHDR *pNMHDR, LRESULT *pResult);
};
