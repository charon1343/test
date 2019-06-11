
// _tapcontrolDlg.h : ��� ����
//

#pragma once


// C_tapcontrolDlg ��ȭ ����
class C_tapcontrolDlg : public CDialogEx
{
// �����Դϴ�.
public:
	C_tapcontrolDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD__TAPCONTROL_DIALOG };

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
	CTabCtrl m_tabArea;
//	double m_dCirR;
//	double m_dCirResult;
//	double m_dTriA;
//	double m_dTriB;
//	double m_dRectA;
//	double m_dRectB;
	double m_dRectA;
	double m_dRectB;
	double m_dCirR;
	double m_dTriA;
	double m_dTriB;
	double m_dTriResult;
	double m_dCirResult;
	double m_dRectResult;
	afx_msg void OnSelchangeTabArea(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickedButtonCir();
	afx_msg void OnClickedButtonRect();
	afx_msg void OnClickedButtonTri();
	afx_msg void OnClickedButtonShow();
	afx_msg void OnClickedButtonExit();
};
