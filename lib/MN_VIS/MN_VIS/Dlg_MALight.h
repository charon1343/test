#pragma once


// CDlg_MALight ��ȭ �����Դϴ�.
#include "LightControl\CMNV_LFineControl.h"

class CDlg_MALight : public CMNVDialogEx
{
	DECLARE_DYNAMIC(CDlg_MALight)

public:
	void MNVRelease() { EndThread(); }

	CDlg_MALight(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlg_MALight();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MA_LIGHT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedLightTest();
	afx_msg void OnBnClickedLightSetting();
	CMNVListCtrl m_ctrlLightList;
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedListLightchannel(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickListLightchannel(NMHDR *pNMHDR, LRESULT *pResult);
};
