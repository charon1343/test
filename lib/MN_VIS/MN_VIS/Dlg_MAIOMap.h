#pragma once


// CDlg_MAIOMap 대화 상자입니다.
#include "Dlg_PADNumeric.h"
class CDlg_MAIOMap : public CMNVDialogEx
{
	DECLARE_DYNAMIC(CDlg_MAIOMap)

public:
	void MNVRelease() { EndThread(); }
	CDlg_MAIOMap(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_MAIOMap();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MA_IOMap };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedIoVisionmodel() {
		CDlg_PADNumeric __PadNumeric(PAD_MDReal);
		if (__PadNumeric.DoModal() == IDOK) {
			CString strTemp;
			//strTemp.Format(_T("%.20f"), __PadNumeric.GetValue());
			SetItemData(IDC_IO_VisionModel, __PadNumeric.GetValue());
		}
	}
	afx_msg void OnBnClickedCheck18() {
		CDlg_PADNumeric __PadNumeric(PAD_MDInteger);
		if (__PadNumeric.DoModal() == IDOK) {
			CString strTemp;
			//strTemp.Format(_T("%.20f"), __PadNumeric.GetValue());
			SetItemData(IDC_CHECK18, __PadNumeric.GetValue());
		}
	}
};
