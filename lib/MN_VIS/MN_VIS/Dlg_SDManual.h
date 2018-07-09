#pragma once


// CDlg_SDManual 대화 상자입니다.
#include "MNVAlgorithm.h"
#define COUNT_PLC_DATA 8
#define COUNT_VISION_DATA 10
class CDlg_SDManual : public CMNVDialogEx
{
	DECLARE_DYNAMIC(CDlg_SDManual)
public:
	void MNVRelease() {
		EndThread();
	}
	CDlg_SDManual(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_SDManual();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SD_Manual };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);

	void Reflash(CMNVAlgorithm & __Algorithm) {
		CString strState;
		switch(__Algorithm.GetState()) {
			case Algorithm_START:	SetItemData(IDC_STATIC_Algorithm, _T("START"));	break;
			case Algorithm_INIT:	SetItemData(IDC_STATIC_Algorithm, _T("INITED"));	break;
			case Algorithm_ALARM:	SetItemData(IDC_STATIC_Algorithm, _T("ALARM"));	break;
			case Algorithm_END:		SetItemData(IDC_STATIC_Algorithm, _T("END"));		break;
			case Algorithm_FINISH:	SetItemData(IDC_STATIC_Algorithm, _T("FINISH"));	break;
			case Algorithm_PREPARE:	SetItemData(IDC_STATIC_Algorithm, _T("PREPARE"));	break;
			case Algorithm_READY:	SetItemData(IDC_STATIC_Algorithm, _T("READY"));	break;
			case Algorithm_RESULT:	SetItemData(IDC_STATIC_Algorithm, _T("RESULT"));	break;
			case Algorithm_RUN:		SetItemData(IDC_STATIC_Algorithm, _T("RUN"));		break;
			case Algorithm_TRIGGER:	SetItemData(IDC_STATIC_Algorithm, _T("TRIGGER"));	break;
			case Algorithm_WAIT:	SetItemData(IDC_STATIC_Algorithm, _T("WAIT"));	break;
			default:				SetItemData(IDC_STATIC_Algorithm, _T("ERROR"));	break;
		}

		SetItemCheck(IDC_Manual_Algorithm, __Algorithm.IsAlgorithmEnable());
		SetItemCheck(IDC_Manual_PLC, __Algorithm.m_PLC.IsPLCEnable());

		SetItemCheck(IDC_Manual_PLCPrepare, 0 != __Algorithm.m_PLC.PLC_GetValue(MNVMap_PLC_Prepare));
		SetItemCheck(IDC_Manual_PLCTrigger, 0 != __Algorithm.m_PLC.PLC_GetValue(MNVMap_PLC_Trigger));
		SetItemCheck(IDC_Manual_PLCFinish, 0 != __Algorithm.m_PLC.PLC_GetValue(MNVMap_PLC_Finish));
		SetItemCheck(IDC_Manual_PLCEnd, 0 != __Algorithm.m_PLC.PLC_GetValue(MNVMap_PLC_End));

		SetItemCheck(IDC_Manual_PLCSelectOK, 0 != __Algorithm.m_PLC.PLC_GetValue(MNVMap_PLC_SelectOK));
		SetItemCheck(IDC_Manual_PLCSelectNG, 0 != __Algorithm.m_PLC.PLC_GetValue(MNVMap_PLC_SelectNG));

		SetItemCheck(IDC_Manual_PLCSettingOK, 0 != __Algorithm.m_PLC.PLC_GetValue(MNVMap_PLC_SettingOK));
		SetItemCheck(IDC_Manual_PLCSettingNG, 0 != __Algorithm.m_PLC.PLC_GetValue(MNVMap_PLC_SettingNG));

		SetItemData(IDC_Manual_PLCModel, __Algorithm.m_PLC.PLC_GetValue(MNVMap_PLC_Model));
		SetItemData(IDC_Manual_PLCItem, __Algorithm.m_PLC.PLC_GetValue(MNVMap_PLC_Item));
		SetItemData(IDC_Manual_PLCSpeed, __Algorithm.m_PLC.PLC_GetValue(MNVMap_PLC_Speed));
		SetItemData(IDC_Manual_PLCWorking, __Algorithm.m_PLC.PLC_GetValue(MNVMap_PLC_Working));

		SetItemCheck(IDC_Manual_VisionWait, 0 != __Algorithm.m_PLC.Vision_GetValue(MNVMap_Vision_Wait));
		SetItemCheck(IDC_Manual_VisionReady, 0 != __Algorithm.m_PLC.Vision_GetValue(MNVMap_Vision_Ready));
		SetItemCheck(IDC_Manual_VisionGrab, 0 != __Algorithm.m_PLC.Vision_GetValue(MNVMap_Vision_Grab));
		SetItemCheck(IDC_Manual_VisionInspect, 0 != __Algorithm.m_PLC.Vision_GetValue(MNVMap_Vision_Inspect));

		SetItemCheck(IDC_Manual_VisionResult, 0 != __Algorithm.m_PLC.Vision_GetValue(MNVMap_Vision_Result));
		SetItemCheck(IDC_Manual_VisionOK, 0 != __Algorithm.m_PLC.Vision_GetValue(MNVMap_Vision_OK));
		SetItemCheck(IDC_Manual_VisionNG, 0 != __Algorithm.m_PLC.Vision_GetValue(MNVMap_Vision_NG));
		SetItemCheck(IDC_Manual_VisionAlarm, 0 != __Algorithm.m_PLC.Vision_GetValue(MNVMap_Vision_Alarm));

		SetItemCheck(IDC_Manual_VisionSelect, 0 != __Algorithm.m_PLC.Vision_GetValue(MNVMap_Vision_SelectReq));
		SetItemCheck(IDC_Manual_VisionSetting, 0 != __Algorithm.m_PLC.Vision_GetValue(MNVMap_Vision_SettingReq));

		SetItemData(IDC_Manual_VisionModel, __Algorithm.m_PLC.Vision_GetValue(MNVMap_Vision_Model));
		SetItemData(IDC_Manual_VisionItem, __Algorithm.m_PLC.Vision_GetValue(MNVMap_Vision_Item));
		SetItemData(IDC_Manual_VisionSpeed, __Algorithm.m_PLC.Vision_GetValue(MNVMap_Vision_Speed));
		SetItemData(IDC_Manual_VisionWorking, __Algorithm.m_PLC.Vision_GetValue(MNVMap_Vision_Working));
	}
	afx_msg void OnBnClickedManualVisionwait() { m_pParent->OnCmd_Command(CMD_Manual_SetPLCOut, 0, MNVMap_Vision_Wait); }
	afx_msg void OnBnClickedManualVisionready() { m_pParent->OnCmd_Command(CMD_Manual_SetPLCOut, 0, MNVMap_Vision_Ready); }
	afx_msg void OnBnClickedManualVisiongrab() { m_pParent->OnCmd_Command(CMD_Manual_SetPLCOut, 0, MNVMap_Vision_Grab); }
	afx_msg void OnBnClickedManualVisioninspect() { m_pParent->OnCmd_Command(CMD_Manual_SetPLCOut, 0, MNVMap_Vision_Inspect); }

	afx_msg void OnBnClickedManualVisionresult() { m_pParent->OnCmd_Command(CMD_Manual_SetPLCOut, 0, MNVMap_Vision_Result); }
	afx_msg void OnBnClickedManualVisionok() { m_pParent->OnCmd_Command(CMD_Manual_SetPLCOut, 0, MNVMap_Vision_OK); }
	afx_msg void OnBnClickedManualVisionng() { m_pParent->OnCmd_Command(CMD_Manual_SetPLCOut, 0, MNVMap_Vision_NG); }
	afx_msg void OnBnClickedManualVisionalarm() { m_pParent->OnCmd_Command(CMD_Manual_SetPLCOut, 0, MNVMap_Vision_Alarm); }

	afx_msg void OnBnClickedManualVisionselect() { m_pParent->OnCmd_Command(CMD_Manual_SetPLCOut, 0, MNVMap_Vision_SelectReq); }
	afx_msg void OnBnClickedManualVisionsetting() { m_pParent->OnCmd_Command(CMD_Manual_SetPLCOut, 0, MNVMap_Vision_SettingReq); }

	afx_msg void OnBnClickedManualVisionmodel() { m_pParent->OnCmd_Command(CMD_Manual_SetPLCOut, 0, MNVMap_Vision_Model); }
	afx_msg void OnBnClickedManualVisionitem() { m_pParent->OnCmd_Command(CMD_Manual_SetPLCOut, 0, MNVMap_Vision_Item); }
	afx_msg void OnBnClickedManualVisionspeed() { m_pParent->OnCmd_Command(CMD_Manual_SetPLCOut, 0, MNVMap_Vision_Speed); }
	afx_msg void OnBnClickedManualVisionworking() { m_pParent->OnCmd_Command(CMD_Manual_SetPLCOut, 0, MNVMap_Vision_Working); }

	afx_msg void OnBnClickedManualPlcprepare() { m_pParent->OnCmd_Command(CMD_Manual_SetPLCIn, 0, MNVMap_PLC_Prepare); }
	afx_msg void OnBnClickedManualPlctrigger() { m_pParent->OnCmd_Command(CMD_Manual_SetPLCIn, 0, MNVMap_PLC_Trigger); }
	afx_msg void OnBnClickedManualPlcfinish() { m_pParent->OnCmd_Command(CMD_Manual_SetPLCIn, 0, MNVMap_PLC_Finish); }
	afx_msg void OnBnClickedManualPlcend() { m_pParent->OnCmd_Command(CMD_Manual_SetPLCIn, 0, MNVMap_PLC_End); }
	afx_msg void OnBnClickedManualPlcselectok() { m_pParent->OnCmd_Command(CMD_Manual_SetPLCIn, 0, MNVMap_PLC_SelectOK); }
	afx_msg void OnBnClickedManualPlcselectng() { m_pParent->OnCmd_Command(CMD_Manual_SetPLCIn, 0, MNVMap_PLC_SelectNG); }
	afx_msg void OnBnClickedManualPlcsettingok() { m_pParent->OnCmd_Command(CMD_Manual_SetPLCIn, 0, MNVMap_PLC_SettingOK); }
	afx_msg void OnBnClickedManualPlcsettingng() { m_pParent->OnCmd_Command(CMD_Manual_SetPLCIn, 0, MNVMap_PLC_SettingNG); }
	afx_msg void OnBnClickedManualPlcmodel() { m_pParent->OnCmd_Command(CMD_Manual_SetPLCIn, 0, MNVMap_PLC_Model); }
	afx_msg void OnBnClickedManualPlcitem() { m_pParent->OnCmd_Command(CMD_Manual_SetPLCIn, 0, MNVMap_PLC_Item); }
	afx_msg void OnBnClickedManualPlcspeed() { m_pParent->OnCmd_Command(CMD_Manual_SetPLCIn, 0, MNVMap_PLC_Speed); }
	afx_msg void OnBnClickedManualPlcworking() { m_pParent->OnCmd_Command(CMD_Manual_SetPLCIn, 0, MNVMap_PLC_Working); }
	afx_msg void OnBnClickedManualAlgorithm() { m_pParent->OnCmd_Command(CMD_Thread_Enable, 0, MNV_TID_Algorithm); }
	afx_msg void OnBnClickedManualPlc() { m_pParent->OnCmd_Command(CMD_Thread_Enable, 0, MNV_TID_PLC); }

};
