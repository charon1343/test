#pragma once
#include "resource.h"

#include "Dlg_PADNumeric.h"

// CDlg_CtrlCamera 대화 상자입니다.
#include "MNVAlgorithm.h"

class CDlg_CtrlCamera : public CMNVDialogEx
{
	DECLARE_DYNAMIC(CDlg_CtrlCamera)
	CMNVAlgorithm * m_pAlgorithm;
public:
	CDlg_CtrlCamera(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_CtrlCamera();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CTRL_CAMERA };
	void Create(CMNVAlgorithm * __pAlgorithm, CWnd * __pWnd, CMNVDialogEx * __pParent) {
		m_pAlgorithm = __pAlgorithm;
		CMNVDialogEx::Create(IDD, __pWnd, __pParent);
	}
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);

	void InitSelector(CMNVAlgorithm & __Algorithm) {
		int nCamCount = __Algorithm.GetGrabberCount();
		//CComboBox * ctrl = (CComboBox *)GetDlgItem(IDC_CAM_SelectChannel);
		//CString strTemp;
		//for(int nIndex = 0; nIndex < nCamCount; ++nIndex) {
		//	strTemp.Format(_T("Camera %02d"), nIndex + 1);
		//	ctrl->AddString(strTemp);
		//}
	}

	STCamSetting m_stCamSetting;
	int m_nChannel;
	void Redraw() {
		//if (m_nChannel >= 0) {
		//	SetSelectIndex(IDC_CAM_SelectChannel, m_nChannel);
		//}
		SetItemData(IDC_CAM_InputExposure, m_stCamSetting.dExposure);
		SetItemData(IDC_CAM_InputContast, m_stCamSetting.dContrast);
		SetItemData(IDC_CAM_InputBrightness, m_stCamSetting.dBrightness);
	}
	void OnReflash() {
		m_nChannel = m_pAlgorithm->GetCurrentGrabber(m_stCamSetting);
		m_ctrlSelect_Channel.SetItemData(m_nChannel);
		m_ctrlSelect_Exposure.SetItemData(m_stCamSetting.dExposure);
		m_ctrlSelect_Contrast.SetItemData(m_stCamSetting.dContrast);
		m_ctrlSelect_Brightness.SetItemData(m_stCamSetting.dBrightness);
	}
	afx_msg void OnBnClickedCamCancel() {
		m_pAlgorithm->Cmd_LoadCamSetting();
		OnReflash();
	}
	afx_msg void OnBnClickedCamSetting() {
		m_pAlgorithm->Cmd_SaveCamSetting();
		//m_pParent->OnCmd_Command(CMD_Camera_Setting, 0, 0);
	}
	void OnCameraSetting(CMNVAlgorithm & __Algorithm) {
		//S/TCamSetting stSetting;
		m_nChannel = m_ctrlSelect_Channel.GetItemData(1);
		m_stCamSetting.dExposure = m_ctrlSelect_Exposure.GetItemData((double)0);
		m_stCamSetting.dContrast = m_ctrlSelect_Contrast.GetItemData((double)0);
		m_stCamSetting.dBrightness= m_ctrlSelect_Brightness.GetItemData((double)0);
		
		m_pAlgorithm->SetCurrentGrabber(m_nChannel, m_stCamSetting);

		//if (!__Algorithm.SetCurrentGrabber(GetSelectIndex(IDC_CAM_SelectChannel), stSetting)) {
		//	AfxMessageBox(_T("Error"));
		//}
	}
	void InitControl(CMNVAlgorithm & __Algorithm) {
		InitSelector(__Algorithm);
		OnReflash();
		Redraw();
	}
	bool InputReal(double & __dValue) {
		CDlg_PADNumeric dlg(PAD_MDReal);
		if(dlg.DoModal() == IDOK) {
			__dValue = dlg.GetValue();
			return true;
		}
		return false;
	}
	afx_msg void OnBnClickedCamInputexposure() {
		double dValue;
		if (InputReal(dValue)) {
			//SetItemData(IDC_CAM_InputExposure, dValue);
			m_pAlgorithm->Cmd_SetExposure(dValue);
			OnReflash();
		}
		else {
		}
	}
	afx_msg void OnBnClickedCamInputcontast() {
		double dValue;
		if (InputReal(dValue)) {
			//SetItemData(IDC_CAM_InputContast, dValue);
			m_pAlgorithm->Cmd_SetContrast(dValue);
			OnReflash();
		}
		else {
		}
	}
	afx_msg void OnBnClickedCamInputbrightness() {
		double dValue;
		if (InputReal(dValue)) {
			m_pAlgorithm->Cmd_SetBrightness(dValue);
			OnReflash();
		}
		else {
		}
	}
	afx_msg void OnBnClickedCamLive() {
		m_ctrlButton_Live.SetItemCheck(true, false);
		if (m_pAlgorithm == NULL) return;
		bool isCheck = m_pParent->OnCmd_Command(CMD_ModelLive, 0, 0) == TRUE;
		m_ctrlButton_Live.SetItemCheck( isCheck, true );
	}
	afx_msg void OnBnClickedCamCapture() {
		if (m_pAlgorithm == NULL) return;
		m_ctrlButton_Live.SetItemCheck( false );
		m_pParent->OnCmd_Command(CMD_ModelCapture, 0, 0);
		m_ctrlButton_Capture.SetItemCheck( false);
	}
	CMNVStatic m_ctrlLabel_Channel;
	CMNVButton m_ctrlSelect_Channel;
	CMNVStatic m_ctrlLabel_Exposure;
	CMNVButton m_ctrlSelect_Exposure;
	CMNVStatic m_ctrlLabel_Contrast;
	CMNVButton m_ctrlSelect_Contrast;
	CMNVStatic m_ctrlLabel_Brightness;
	CMNVButton m_ctrlSelect_Brightness;
	CMNVButton m_ctrlButton_Accept;
	CMNVButton m_ctrlButton_Cancel;
	afx_msg void OnBnClickedCamSelectchannel();
	CMNVButton m_ctrlButton_Live;
	CMNVButton m_ctrlButton_Capture;
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};
