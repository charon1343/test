#pragma once
#include "resource.h"
#include "MNVAlgorithm.h"
// CDle_SDModel 대화 상자입니다.

#include "Dlg_CtrlModel.h"
#include "Dlg_CtrlCamera.h"
#include "Dlg_CtrlLight20.h"
#include "Dlg_CtrlPattern.h"
#include "Dlg_CtrlLight2Ch.h"
#include "Dlg_CtrlAlgorithm.h"

class CDlg_SDModel : public CMNVDialogEx
{
	DECLARE_DYNAMIC(CDlg_SDModel)

	CDlg_CtrlModel m_ctrlModel;
	CDlg_CtrlCamera m_ctrlCamera;
	CDlg_CtrlPattern m_ctrlPattern;
	CDlg_CtrlLight2Ch m_ctrlLight;
	CDlg_CtrlAlgorithm m_ctrlAlgorithm;
	//CDlg_CtrlLight20 m_ctrlLight;
	CMNVAlgorithm * m_pAlgorithm;
public:
	CDlg_SDModel(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_SDModel();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SD_Model };
	void Create(CMNVAlgorithm * __pAlgorithm, CWnd * __pWnd, CMNVDialogEx * __pParent) {
		m_pAlgorithm = __pAlgorithm;
		CMNVDialogEx::Create(IDD, __pWnd, __pParent);
	}

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	void SetAlgorithm(CMNVAlgorithm * __pAlgorithm) { m_pAlgorithm = __pAlgorithm; }
	virtual BOOL OnInitDialog();
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);

	void MNVRelease() { }

	void InitSetting() {
	}
	void OnReflash(CMNVAlgorithm & __Algorithm) {
		__Algorithm.m_PLC.GetCurrent_Model();
		__Algorithm.m_PLC.GetCurrent_Item();

		//m_ctrlModel.Reflash(__Algorithm);
		//m_ctrlLight.Reflash(__Algorithm);
		//m_ctrlCamera.OnReflash();
		m_ctrlLight.OnReflash();
	}

	void InitSelector(CMNVAlgorithm & __Algorithm) {
		m_ctrlCamera.InitSelector(__Algorithm);
	}
	void OnCameraSetting(CMNVAlgorithm & __Algorithm) {
		m_ctrlCamera.OnCameraSetting(__Algorithm);
	}
	void InitControl(CMNVAlgorithm & __Algorithm) {
		m_ctrlModel.InitControl(__Algorithm);
		m_ctrlCamera.InitControl(__Algorithm);
	}

	virtual int OnCmd_Command(MNV_Command __Cmd, WPARAM __wParam, LPARAM __lParam) {
		switch(__Cmd) {
		case CMD_Reflash:
			m_ctrlModel.OnReflash();
			m_ctrlLight.OnReflash();
			m_ctrlCamera.OnReflash();
			return 0;
		default:
			return m_pParent->OnCmd_Command(__Cmd, __wParam, __lParam);
		}
	}
	afx_msg void OnBnClickedSdmodelImaging();
	CMNVButton m_ctrlTab_Imaging;
	CMNVButton m_ctrlTab_Algorithm;
	afx_msg void OnBnClickedSdmodelAlgorithm();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};
