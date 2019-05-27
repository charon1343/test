#pragma once


// CDlg_FrmMain 대화 상자입니다.
#include "Dlg_MAView.h"
#include "Dlg_MAIOMap.h"
#include "Dlg_MALight.h"
#include "Dlg_MAPLC.h"

//#include "Dlg_MAView.h"
#include "Dlg_SDRun.h"
#include "Dlg_SDManual.h"
#include "Dlg_SDVision.h"
#include "Dlg_SDModel.h"

/// Menu 관련 상수 등 접근을 위해 추가
#include "Dlg_HDMenu.h"

class CDlg_FrmMain : public CMNVDialogEx
{
	DECLARE_DYNAMIC(CDlg_FrmMain)
	CDlg_MAView m_View;
	CDlg_SDRun m_SDRun;
	CDlg_SDModel m_SDModel;
	CDlg_SDVision m_SDVision;
	CDlg_SDManual m_SDManual;

	CDlg_MAIOMap m_IOMap;
	CDlg_MALight m_Light;
	CDlg_MAPLC m_PLC;
	CMNVAlgorithm * m_pAlgorithm;
public:
	void MNVRelease() {
		m_View.MNVRelease();
		m_SDRun.MNVRelease();
		m_SDVision.MNVRelease();
		m_SDManual.MNVRelease();
		m_SDModel.MNVRelease();

		m_IOMap.MNVRelease();
		m_Light.MNVRelease();
		m_PLC.MNVRelease();
		EndThread();
	}
	CDlg_FrmMain(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_FrmMain();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FRM_MAIN };
	void Create(CMNVAlgorithm * __pAlgorithm, CWnd * __pWnd, CMNVDialogEx * __pParent) {
		m_pAlgorithm = __pAlgorithm;
		CMNVDialogEx::Create(IDD, __pWnd, __pParent);
	}

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	//void InitVisionData(int __nChannel, int __nCamera, CCamInfo * __pCmaInfo) { m_SDVision.InitData(__nChannel, __nCamera, __pCmaInfo); }
	virtual BOOL OnInitDialog();
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);

	//void SetCamInfo(CCamInfo * __CamInfo) { m_View.SetCamInfo(__CamInfo); }
	void SetImage(int __nIndex, CMNVImage &__img) {
		if (m_SDVision.GetSelectedCamera() == __nIndex) {
			//m_View.m_isCrossLine = m_SDVision.ISCorssLine();




			//if (m_SDVision.ISLive()) m_View.SetImage(__img);
			//if (m_SDVision.ISGrab()) {
			//	m_View.SetImage(__img);
			//	m_SDVision.SetGrab(false);
			//}
		}
	}
	void SelectMenu(Menu_Select __menu) {

		switch(__menu) {
		case Menu_Main:
			m_View.ShowWindow(true);
			m_IOMap.ShowWindow(false);
			m_Light.ShowWindow(false);
			m_PLC.ShowWindow(false);

			m_SDRun.ShowWindow(true);
			m_SDVision.ShowWindow(false);
			m_SDManual.ShowWindow(false);
			m_SDModel.ShowWindow(false);
			
			m_View.m_cdDisplayMode = 0;
			m_View.LiveOff();
			break;
		case Menu_Manual:
			m_View.ShowWindow(true);
			m_IOMap.ShowWindow(false);
			m_Light.ShowWindow(false);
			m_PLC.ShowWindow(false);

			m_SDRun.ShowWindow(false);
			m_SDVision.ShowWindow(false);
			m_SDManual.ShowWindow(true);
			m_SDModel.ShowWindow(false);

			m_View.m_cdDisplayMode = 0;
			m_View.LiveOff();
			break;
		case Menu_Model:
			m_View.ShowWindow(true);
			m_IOMap.ShowWindow(false);
			m_Light.ShowWindow(false);
			m_PLC.ShowWindow(false);
			
			m_SDRun.ShowWindow(false);
			m_SDVision.ShowWindow(false);
			m_SDManual.ShowWindow(false);
			m_SDModel.ShowWindow(true);

			m_View.m_cdDisplayMode = 1;
			break;
		case Menu_Vision:
			m_View.ShowWindow(true);
			m_IOMap.ShowWindow(false);
			m_Light.ShowWindow(false);
			m_PLC.ShowWindow(false);

			m_SDRun.ShowWindow(false);
			m_SDVision.ShowWindow(true);
			m_SDManual.ShowWindow(false);
			m_SDModel.ShowWindow(false);

			m_View.m_cdDisplayMode = 1;
			break;
		case Menu_System:
			m_View.ShowWindow(false);
			m_IOMap.ShowWindow(false);
			m_Light.ShowWindow(true);
			m_PLC.ShowWindow(true);

			m_SDRun.ShowWindow(false);
			m_SDVision.ShowWindow(false);
			m_SDManual.ShowWindow(false);
			m_SDModel.ShowWindow(false);

			m_View.m_cdDisplayMode = 1;
			break;
		}
	}
	afx_msg void OnDestroy();

	void OnReflash(CMNVAlgorithm & __Algorithm) {
		//m_View.OnReflash(__Algorithm);
		m_SDManual.Reflash(__Algorithm);
		m_SDModel.OnReflash(__Algorithm);
	}

	void InitSelector(CMNVAlgorithm & __Algorithm) {
		m_SDModel.InitSelector(__Algorithm);
	}
	void OnCameraSetting(CMNVAlgorithm & __Algorithm) {
		m_SDModel.OnCameraSetting(__Algorithm);
	}
	void InitControl(CMNVAlgorithm & __Algorithm) {
		m_SDModel.InitControl(__Algorithm);
	}
	void OnCmd_ShowMaster(CMNVAlgorithm & __Algorithm) {
		m_View.OnCmd_ShowMaster(__Algorithm);
	}
	void OnCmd_SetPattern(CMNVAlgorithm & __Algorithm) {
		m_View.OnCmd_SetPattern(__Algorithm);
	}

	virtual int OnCmd_Command(MNV_Command __Cmd, WPARAM __wParam, LPARAM __lParam) {
		switch(__Cmd) {
		case CMD_ModelLive:
			return m_View.OnCmd_Live() ? TRUE : FALSE;
		case CMD_ModelCapture:
			return m_View.OnCmd_Capture();
		default:
			return m_pParent->OnCmd_Command(__Cmd, __wParam, __lParam);
		}
	}
};
