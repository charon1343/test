
// _mfcDlg.h : ��� ����
//

#pragma once


// C_mfcDlg ��ȭ ����
class C_mfcDlg : public CDialogEx
{
// �����Դϴ�.
public:
	C_mfcDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD__MFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnClickedButtonHello();
	afx_msg void OnClickedButtonExit();
	CString m_strResult;
	afx_msg void OnBnClickedButtonYn();
	afx_msg void OnBnClickedButtonOc();
};
