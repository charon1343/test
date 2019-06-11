
// _bitmapDlg.h : ��� ����
//

#pragma once


// C_bitmapDlg ��ȭ ����
class C_bitmapDlg : public CDialogEx
{
// �����Դϴ�.
public:
	C_bitmapDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	////////
	HINSTANCE m_hInstance;

	int m_nWidth;
	int m_nHeight;

	////////

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD__BITMAP_DIALOG };

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
	afx_msg void OnFileExit();
	afx_msg void OnHelpAbout();
	int m_menuID;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnZoomIn();
	afx_msg void OnZoomOut();
	afx_msg void OnClickedButtonExit();
};
