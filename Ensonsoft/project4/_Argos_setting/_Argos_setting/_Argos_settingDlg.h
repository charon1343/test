
// _Argos_settingDlg.h : ��� ����
//

#pragma once


// C_Argos_settingDlg ��ȭ ����
class C_Argos_settingDlg : public CDialogEx
{
// �����Դϴ�.
public:
	C_Argos_settingDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD__ARGOS_SETTING_DIALOG };

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
	CString m_fileserver_ip;
	CString m_license_path;
	CString m_saveformat;
	CString m_site_code;
	CString m_site_name;
	CString m_server_ip;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
