#pragma once


// CDlg_FrmFooter 대화 상자입니다.

class CDlg_FrmFooter : public CMNVDialogEx
{
	DECLARE_DYNAMIC(CDlg_FrmFooter)

public:
	void MNVRelease() { EndThread(); }
	CDlg_FrmFooter(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_FrmFooter();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FRM_FOOTER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
