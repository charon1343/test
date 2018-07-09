#pragma once

#include "MNV/CamInfo.h"
// CDlg_SDVision 대화 상자입니다.
#include "Dlg_PADNumeric.h"

#include "Dlg_CtrlLight20.h"

class CDlg_SDVision : public CMNVDialogEx
{
	DECLARE_DYNAMIC(CDlg_SDVision)

	CDlg_CtrlLight20 m_ctrlLight20;
	//int m_cntChannel;
	//int m_cntCamera;
	//int m_nVision[4];
	//CCamInfo * m_pCamInfo;

	//CMNV_LFineControl m_DeviceLFine;
public:
	void MNVRelease() {
		EndThread();
	}
	int GetSelectedChannel() { return GetSelectIndex(IDC_VISION_InputChannel); }
	int GetSelectedCamera() { return GetSelectIndex(IDC_VISION_InputCamera); }

	bool ISLive() { return GetItemCheck(IDC_VISION_Live); }
	bool ISGrab() { return GetItemCheck(IDC_VISION_Grab); }
	bool ISCorssLine() { return GetItemCheck(IDC_VISION_CrossLine); }
	void SetGrab(bool __isEnable) { SetItemCheck(IDC_VISION_Grab, __isEnable); }
	CDlg_SDVision(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_SDVision();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SD_Vision };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	//void InitData(int __cntChannel, int __cntCamera, CCamInfo * __pCamInfo) {
	//	m_cntChannel = __cntChannel;
	//	m_cntCamera = __cntCamera;
	//	m_pCamInfo = __pCamInfo;

	//	CComboBox * pChannel = (CComboBox *)GetDlgItem(IDC_VISION_InputChannel);
	//	CComboBox * pCamera = (CComboBox *)GetDlgItem(IDC_VISION_InputCamera);

	//	CString strTemp;
	//	pChannel->Clear();
	//	for(int nIndex = 0; nIndex < m_cntChannel; ++nIndex) {
	//		strTemp.Format(_T("Vision %02d"), nIndex + 1);
	//		pChannel->AddString(strTemp);
	//	}
	//	pChannel->SetCurSel(0);
	//	pCamera->Clear();
	//	for(int nIndex = 0; nIndex < m_cntCamera; ++nIndex) {
	//		strTemp.Format(_T("Camera %02d"), nIndex + 1);
	//		pCamera->AddString(strTemp);
	//	}
	//	pCamera->SetCurSel(0);

	//	SetItemData(IDC_VISION_InputExposure, m_pCamInfo[0].GetExposure());
	//	SetItemData(IDC_VISION_InputContrast, m_pCamInfo[0].GetContrast());
	//	SetItemData(IDC_VISION_InputBrightness, m_pCamInfo[0].GetBrightness());
	//}
	virtual BOOL OnInitDialog();
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	afx_msg void OnBnClickedVisionInputexposure() {
		double dInputValue;
		if (InputReal(dInputValue)) {
			dInputValue = dInputValue;
			SetItemData(IDC_VISION_InputExposure, dInputValue);
			//m_pCamInfo[GetSelectIndex(IDC_VISION_InputCamera)].SetExposure(dInputValue);
		}
	}
	afx_msg void OnBnClickedVisionInputcontrast() {
		double dInputValue;
		if (InputReal(dInputValue)) {
			SetItemData(IDC_VISION_InputContrast, dInputValue);
			//m_pCamInfo[GetSelectIndex(IDC_VISION_InputCamera)].SetContrast(dInputValue);
		}
	}
	afx_msg void OnBnClickedVisionInputbrightness() {
		double dInputValue;
		if (InputReal(dInputValue)) {
			SetItemData(IDC_VISION_InputBrightness, dInputValue);
			//m_pCamInfo[GetSelectIndex(IDC_VISION_InputCamera)].SetBrightness(dInputValue);
		}
	}

	bool InputReal(double & __Value) {
		CDlg_PADNumeric dlg(PAD_MDReal);
		if(dlg.DoModal() == IDOK) {
			__Value = dlg.GetValue();
			return true;
		}
		return false;
	}
	afx_msg void OnBnClickedVisionLive() {
	}
	afx_msg void OnBnClickedVisionGrab() {
		SetItemCheck(IDC_VISION_Live, false);
	}
	afx_msg void OnBnClickedVisionCrossline() {
	}
	afx_msg void OnBnClickedVisionAccept();
	afx_msg void OnBnClickedVisionCancel();

	virtual void Thread();
	afx_msg void OnCbnSelchangeVisionInputcamera() {
		//STCamSetting stSetting;
		//m_pCamInfo[GetSelectIndex(IDC_VISION_InputCamera)].GetCamSetting(stSetting);

		//SetItemData(IDC_VISION_InputExposure, stSetting.dExposure);
		//SetItemData(IDC_VISION_InputContrast, stSetting.dContrast * 100);
		//SetItemData(IDC_VISION_InputBrightness, stSetting.dBrightness * 100);

		//SetItemCheck(IDC_VISION_Cancel, false);
	}
	afx_msg void OnCbnSelchangeVisionInputchannel() {
		//SetSelectIndex(IDC_VISION_InputCamera, m_nVision[GetSelectIndex(IDC_VISION_InputChannel)]);

		//STCamSetting stSetting;
		//m_pCamInfo[GetSelectIndex(IDC_VISION_InputCamera)].GetCamSetting(stSetting);

		//SetItemData(IDC_VISION_InputExposure, stSetting.dExposure);
		//SetItemData(IDC_VISION_InputContrast, stSetting.dContrast * 100);
		//SetItemData(IDC_VISION_InputBrightness, stSetting.dBrightness * 100);
	}

	afx_msg void OnBnClickedVisionLoad() {
		//wchar_t Current[1024];
		//{ GetCurrentDirectory(1024, Current); }
		//CString strTemp;
		//for (int nIndex = 0; nIndex < 4; ++nIndex) {
		//	strTemp.Format(_T("Camera%02d"), nIndex);
		//	m_pCamInfo[nIndex].LoadCamInfo(Current, _T("Camera.mnv"), strTemp);
		//}
		//m_nVision[0];
		//m_nVision[1];
		//m_nVision[2];
		//m_nVision[3];
	}
	afx_msg void OnBnClickedVisionSave() {
		//wchar_t Current[1024];
		//{ GetCurrentDirectory(1024, Current); }
		//CString strTemp;
		//for (int nIndex = 0; nIndex < 4; ++nIndex) {
		//	strTemp.Format(_T("Camera%02d"), nIndex);
		//	m_pCamInfo[nIndex].SaveCamInfo(Current, _T("Camera.mnv"), strTemp);
		//}
	}
	afx_msg void OnDestroy();
};
