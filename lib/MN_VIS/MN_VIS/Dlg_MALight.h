#pragma once


// CDlg_MALight 대화 상자입니다.
#include "LightControl\CMNV_LFineControl.h"

class CDlg_MALight : public CMNVDialogEx
{
	DECLARE_DYNAMIC(CDlg_MALight)

public:
	void MNVRelease() { EndThread(); }

	CDlg_MALight(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_MALight();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MA_LIGHT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedLightTest();
	afx_msg void OnBnClickedLightSetting();
	CMNVListCtrl m_ctrlLightList;
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedListLightchannel(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickListLightchannel(NMHDR *pNMHDR, LRESULT *pResult);
};
