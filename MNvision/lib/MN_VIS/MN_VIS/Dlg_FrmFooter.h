#pragma once


// CDlg_FrmFooter ��ȭ �����Դϴ�.

class CDlg_FrmFooter : public CMNVDialogEx
{
	DECLARE_DYNAMIC(CDlg_FrmFooter)

public:
	void MNVRelease() { EndThread(); }
	CDlg_FrmFooter(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlg_FrmFooter();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FRM_FOOTER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
