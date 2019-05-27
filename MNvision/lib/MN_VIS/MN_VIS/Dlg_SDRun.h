#pragma once

#include "MNVAlgorithm.h"
// CDlg_SDRun 대화 상자입니다.

class CDlg_SDRun : public CMNVDialogEx
{
	DECLARE_DYNAMIC(CDlg_SDRun)
	CMNVAlgorithm * m_pAlgorithm;
public:
	void MNVRelease() { EndThread(); }
	CDlg_SDRun(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_SDRun();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SD_Run };
	virtual int GetID() { return IDD; }
	int m_nChannel[4];
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	void Create(CMNVAlgorithm * __pAlgorithm, CWnd * __pWnd, CMNVDialogEx * __pParent) {
		m_pAlgorithm = __pAlgorithm;
		CMNVDialogEx::Create(IDD, __pWnd, __pParent);
	}
	//void Create(CWnd * pParent, CMNVDialogEx * pCmd) { CMNVDialogEx::Create(IDD, pParent, pCmd); }
	virtual BOOL OnInitDialog();
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	afx_msg void OnBnClickedSdrInitbtn();
	//afx_msg void OnBnClickedSdrView();

	void OnReflash(CMNVAlgorithm & __Algorithm) {
		{
			CString strTemp;
			strTemp.Format(_T("Model_%02d"), __Algorithm.m_PLC.GetCurrent_Model());
			SetItemData(IDC_RUN_SelectModel, strTemp);
			strTemp.Format(_T("Item_%02d"), __Algorithm.m_PLC.GetCurrent_Item());
			SetItemData(IDC_RUN_SelectItem, strTemp);
		}
		SetItemCheck(IDC_RUN_Algorithm, __Algorithm.IsAlgorithmEnable());
		if (__Algorithm.IsAlgorithmEnable()) {
			switch(__Algorithm.GetState()) {
			case Algorithm_START:	SetItemData(IDC_RUN_AlgState, _T("START")); break;
			case Algorithm_INIT:	SetItemData(IDC_RUN_AlgState, _T("INITED"));	break;
			case Algorithm_WAIT:	SetItemData(IDC_RUN_AlgState, _T("WAIT")); break;
			case Algorithm_PREPARE:	SetItemData(IDC_RUN_AlgState, _T("PREPARE")); break;
			case Algorithm_READY:	SetItemData(IDC_RUN_AlgState, _T("READY")); break;
			case Algorithm_TRIGGER:	SetItemData(IDC_RUN_AlgState, _T("GRAB")); break;
			case Algorithm_RUN:		SetItemData(IDC_RUN_AlgState, _T("INSPECT")); break;
			case Algorithm_RESULT:	SetItemData(IDC_RUN_AlgState, _T("RESULT")); break;
			case Algorithm_FINISH:	SetItemData(IDC_RUN_AlgState, _T("FINISH")); break;
			case Algorithm_END:		SetItemData(IDC_RUN_AlgState, _T("END")); break;
			case Algorithm_ALARM:	SetItemData(IDC_RUN_AlgState, _T("ALARM")); break;
			case Setting_Model:		SetItemData(IDC_RUN_AlgState, _T("Model Setting")); break;
			case Setting_Vision:	SetItemData(IDC_RUN_AlgState, _T("Vision Setting")); break;
			case Setting_System:	SetItemData(IDC_RUN_AlgState, _T("System Setting")); break;
			}
		}
		else {
			SetItemData(IDC_RUN_AlgState, _T("STOP"));
		}

	
	
		{
			switch(__Algorithm.m_PLC.Vision_GetSignalCode()) {
			case 16:SetItemData(IDC_RUN_VisionSignal, _T("RESULT")); break;
			case 8:	SetItemData(IDC_RUN_VisionSignal, _T("INSPECT")); break;
			case 4:	SetItemData(IDC_RUN_VisionSignal, _T("GRAB")); break;
			case 2:	SetItemData(IDC_RUN_VisionSignal, _T("READY")); break;
			case 1:	SetItemData(IDC_RUN_VisionSignal, _T("WAIT")); break;
			default:SetItemData(IDC_RUN_VisionSignal, _T("<<No Signal>>")); break;
			}
		}

		{
			switch(__Algorithm.m_PLC.PLC_GetSignalCode()) {
			case 8:	SetItemData(IDC_RUN_PLCSignal, _T("END")); break;
			case 4:	SetItemData(IDC_RUN_PLCSignal, _T("FINISH")); break;
			case 2:	SetItemData(IDC_RUN_PLCSignal, _T("TRIGGER")); break;
			case 1:	SetItemData(IDC_RUN_PLCSignal, _T("READY")); break;
			default:SetItemData(IDC_RUN_PLCSignal, _T("<<No Signal>>")); break;
			}
		}
		CString strResult;
		__Algorithm.GetResult(0, strResult); m_ctrlResult[0].SetWindowText(strResult);
		__Algorithm.GetResult(1, strResult); m_ctrlResult[1].SetWindowText(strResult);
		__Algorithm.GetResult(2, strResult); m_ctrlResult[2].SetWindowText(strResult);
		__Algorithm.GetResult(3, strResult); m_ctrlResult[3].SetWindowText(strResult);
	}
	afx_msg void OnBnClickedRunAlgorithm() {
		m_pParent->OnCmd_Command(CMD_Thread_Enable, 0, MNV_TID_Algorithm);
	}
	CMNVButton m_ctrlSelectModel;
	CMNVButton m_ctrlSelectItem;
	CMNVButton m_ctrlResult[4];
	afx_msg void OnBnClickedRunResult1() { m_pParent->OnCmd_Command(CMD_DisplayResult, 1, 0); }
	afx_msg void OnBnClickedRunResult2() { m_pParent->OnCmd_Command(CMD_DisplayResult, 2, 0); }
	afx_msg void OnBnClickedRunResult3() { m_pParent->OnCmd_Command(CMD_DisplayResult, 3, 0); }
	afx_msg void OnBnClickedRunResult4() { m_pParent->OnCmd_Command(CMD_DisplayResult, 4, 0); }
	bool DisplayResult(int __nItem) {
		m_ctrlResult[0].SetItemCheck(__nItem == 1);
		m_ctrlResult[1].SetItemCheck(__nItem == 2);
		m_ctrlResult[2].SetItemCheck(__nItem == 3);
		m_ctrlResult[3].SetItemCheck(__nItem == 4);
		return true;
	}
};
