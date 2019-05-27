
// MN_VISDlg.h : 헤더 파일
//

#pragma once

#include "Dlg_MsgLoading.h"

#include "Dlg_FrmHeader.h"
#include "Dlg_FrmMain.h"
#include "Dlg_FrmFooter.h"

#include "Dlg_Setting.h"

#include "MNVAlgorithm.h"

// CMN_VISDlg 대화 상자
class CMN_VISDlg : public CMNVDialogEx
{
	//CMNV_DevicePLC * m_pDevicePLC;
// 생성입니다.
	CDlg_Setting	m_dlgSetting;
	CDlg_MsgLoading m_dlgLoading;
	CDlg_FrmHeader	m_dlgHeader;
	CDlg_SDRun		m_dlgSDRun;
	CDlg_MAView		m_dlgMain;
	CDlg_FrmFooter	m_dlgFooter;

	CMNVAlgorithm m_Algorithm;
	int m_nSelectChannel;
public:
	void MNVRelease() {
		{	//
			m_dlgHeader.MNVRelease();
			m_dlgMain.MNVRelease();
			m_dlgSDRun.MNVRelease();
			m_dlgFooter.MNVRelease();
		}
		m_dlgSetting.MNVRelease();
		m_Algorithm.MNVRelease();
		EndThread();
		Sleep(100);
		exit(0);
	}
	CString m_strLayOut;
	CMN_VISDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MN_VIS_DIALOG };
	//void Create(CMNVAlgorithm * __pAlgorithm, CWnd * __pWnd, CMNVDialogEx * __pParent) {
	//	m_pAlgorithm = __pAlgorithm;
	//	CMNVDialogEx::Create(IDD, __pWnd, __pParent);
	//}

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

	int GetSelectChannel() { return m_nSelectChannel; }
	void SetSelectChannel(int __nChannel) {
		m_nSelectChannel = __nChannel;
		switch(m_nSelectChannel) {
		case 0:
			m_dlgSDRun.SetItemCheck(IDC_RUN_Channel1, true);
			m_dlgSDRun.SetItemCheck(IDC_RUN_Channel2, false);
			m_dlgSDRun.SetItemCheck(IDC_RUN_Channel3, false);
			m_dlgSDRun.SetItemCheck(IDC_RUN_Channel4, false);
			break;
		case 1:
			m_dlgSDRun.SetItemCheck(IDC_RUN_Channel1, false);
			m_dlgSDRun.SetItemCheck(IDC_RUN_Channel2, true);
			m_dlgSDRun.SetItemCheck(IDC_RUN_Channel3, false);
			m_dlgSDRun.SetItemCheck(IDC_RUN_Channel4, false);
			break;
		case 2:
			m_dlgSDRun.SetItemCheck(IDC_RUN_Channel1, false);
			m_dlgSDRun.SetItemCheck(IDC_RUN_Channel2, false);
			m_dlgSDRun.SetItemCheck(IDC_RUN_Channel3, true);
			m_dlgSDRun.SetItemCheck(IDC_RUN_Channel4, false);
			break;
		case 3:
			m_dlgSDRun.SetItemCheck(IDC_RUN_Channel1, false);
			m_dlgSDRun.SetItemCheck(IDC_RUN_Channel2, false);
			m_dlgSDRun.SetItemCheck(IDC_RUN_Channel3, false);
			m_dlgSDRun.SetItemCheck(IDC_RUN_Channel4, true);
			break;
		default:
			m_nSelectChannel = 0;
			m_dlgSDRun.SetItemCheck(IDC_RUN_Channel1, true);
			m_dlgSDRun.SetItemCheck(IDC_RUN_Channel2, false);
			m_dlgSDRun.SetItemCheck(IDC_RUN_Channel3, false);
			m_dlgSDRun.SetItemCheck(IDC_RUN_Channel4, false);
			break;
		}
	}
// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk() {
		CDialogEx::OnOK();
	}
	afx_msg void OnBnClickedCancel() {
		MNVRelease();
		//CDialogEx::OnCancel();
	}
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	int nCount;
	bool m_isLayout;
	bool isDestroy;
	virtual void Thread();
	void SetLayout(int __nWidth = 300) {
		CRect rect;
		GetClientRect(&rect);

		int Header = CMNVIni::GetValue(_T("Main"), _T("Header"), 50, m_strLayOut);
		int Footer = CMNVIni::GetValue(_T("Main"), _T("Footer"), 20, m_strLayOut);
		int nMargin = CMNVIni::GetValue(_T("Main"), _T("Margin"), 5, m_strLayOut);
		int nPadding = CMNVIni::GetValue(_T("Main"), _T("Padding"), 5, m_strLayOut);

		rect.top += nMargin;
		rect.left += nMargin;
		rect.bottom -= nMargin;
		rect.right -= nMargin;

		int nTop[3];
		nTop[0] = rect.top;
		nTop[1] = nTop[0] + nPadding + Header;
		//nTop[2] = rect.bottom - Footer;

		int nLeft = rect.left;
		int nWidth = rect.Width();
		int nHeight = rect.Height() - nPadding * 2 - Header;

		m_dlgHeader.SetWindowPos(nLeft, nTop[0], nWidth, Header);
		m_dlgMain.SetWindowPos(nLeft, nTop[1], nWidth - __nWidth, nHeight);
		m_dlgSDRun.SetWindowPos(rect.right - __nWidth, nTop[1], __nWidth, nHeight);
		//m_dlgFooter.SetWindowPos(nLeft, nTop[2], nWidth, Footer);
	}
	void LoadLayout() {
		int PosX = CMNVIni::GetValue(_T("Main"), _T("PosX"), 0, m_strLayOut);
		int PosY = CMNVIni::GetValue(_T("Main"), _T("PosY"), 0, m_strLayOut);
		int SizeX = CMNVIni::GetValue(_T("Main"), _T("SizeX"), 0, m_strLayOut);
		int SizeY = CMNVIni::GetValue(_T("Main"), _T("SizeY"), 0, m_strLayOut);
		SetWindowPos(NULL, PosX, PosY, SizeX, SizeY, SWP_NOZORDER);
		ShowWindow(false);
		if (CMNVIni::GetValue(_T("Main"), _T("FullScreen"), 0, m_strLayOut) == 1) FullScreen(true);
		else ShowWindow(true);
		
		m_dlgHeader.CheckMain(true);
		m_dlgHeader.ShowWindow(true);
		m_dlgMain.ShowWindow(true);
		m_dlgSDRun.ShowWindow(true);
		m_dlgFooter.ShowWindow(false);

		//m_dlgSetting.ShowWindow(false);

		SetLayout();
		m_dlgSetting.LoadLayout();
	}
	void Select_Menu(Menu_Select __Menu, WPARAM __wParam, LPARAM __lParam) {
		if ( !m_dlgSetting.SetMenu(__Menu) && __wParam == 0) {
			WINDOWINFO wInfo;
			m_dlgSetting.GetWindowInfo(&wInfo);
			if ((wInfo.dwStyle & WS_VISIBLE) != 0) {
				GetWindowInfo(&wInfo);
				m_dlgSetting.FullScreen((wInfo.dwStyle & WS_MAXIMIZE) != 0);
				m_dlgSetting.MoveWindow(wInfo.rcWindow.left, wInfo.rcWindow.top, wInfo.rcWindow.right - wInfo.rcWindow.left, wInfo.rcWindow.bottom - wInfo.rcWindow.top, 1000);
			}
		}
		//m_dlgMain.SelectMenu(Menu_Main);
		m_dlgHeader.CheckMenu(__Menu);
		m_dlgSetting.InitControl(m_Algorithm);
		//RedrawWindow();
	}
	void ChangeMode(Menu_Mode __Mode) {
		switch (__Mode) {
			case Mode_Manager: {
				CDlg_PADNumeric dlg(PAD_MDPassword);
				if(dlg.DoModal() == IDOK) {
					if ((int)dlg.GetValue() == 1) {
						m_dlgHeader.SetMode(__Mode);
						m_dlgSetting.SetMode(__Mode);
					}
				}
			} break;
			case Mode_Opertor: {
				m_dlgHeader.SetMode(__Mode);
				m_dlgSetting.SetMode(__Mode);
			} break;
		}
	}
	virtual int OnCmd_Command(MNV_Command __Cmd, WPARAM __wParam, LPARAM __lParam) {
		switch(__Cmd) {
		case CMD_MENU_Model:
			m_Algorithm.State_SetMODEL();
			Select_Menu(Menu_Model, __wParam, __lParam);
			break;
		case CMD_MENU_Manual:
			m_Algorithm.State_SetSTART();
			Select_Menu(Menu_Manual, __wParam, __lParam);
			break;
		case CMD_MENU_Run:
			m_Algorithm.State_SetSTART();
			Select_Menu(Menu_Main, __wParam, __lParam);
			break;
		case CMD_MENU_System:
			m_Algorithm.State_SetSYSTEM();
			Select_Menu(Menu_System, __wParam, __lParam);
			break;
		case CMD_MENU_Vision:
			m_Algorithm.State_SetVISION();
			Select_Menu(Menu_Vision, __wParam, __lParam);
			break;
			///////////////////////////////////////////////////////
		case CMD_SYS_Layout:	LoadLayout();	break;

		case CMD_MENU_Mode:		ChangeMode((Menu_Mode)__lParam); break;
		//case CMD_Run_View:		SetLayout((int)__wParam); break;

		case CMD_RUN_SelectChannel:	SetSelectChannel((int)__wParam); break;
		case CMD_Manual_SetPLCIn: OnManual_SetPLCIn((int)__lParam); break;
		case CMD_Manual_SetPLCOut: OnManual_SetPLCOut((int)__lParam ); break;
		case CMD_Thread_Enable:	OnThread_Enable((MNV_ThreadID)__lParam); break;

		case CMD_Light_AddValue: m_Algorithm.Light_AddValue((int)__wParam, (int)__lParam); break;
		case CMD_Light_SetValue: m_Algorithm.Light_SetValue((int)__wParam, (int)__lParam); break;
		case CMD_Light_SubValue: m_Algorithm.Light_SubValue((int)__wParam, (int)__lParam); break;
		case CMD_Light_Update: m_Algorithm.Light_Update(); break;

		case CMD_Camera_Setting: m_dlgSetting.OnCameraSetting(m_Algorithm); break;

		case CMD_Model_Load:
			{
				STModel * pstModel = (STModel *)__lParam;
				m_Algorithm.Proc_LoadModel(pstModel->m_nModel, pstModel->m_nItem, pstModel->m_nVision);
			} break;
		case CMD_Model_Save:
			{
				STModel * pstModel = (STModel *)__lParam;
				m_Algorithm.Proc_SaveModel();
			} break;
		case CMD_Pattern_ShowMaster:
			{
				m_dlgSetting.OnCmd_ShowMaster(m_Algorithm);
			} break;
		case CMD_Pattern_SetPattern:
			{
				m_dlgSetting.OnCmd_SetPattern(m_Algorithm);
			} break;
		case CMD_DisplayResult:
			{
				m_dlgSDRun.DisplayResult( m_dlgMain.OnReflash((int)__wParam) );
			} break;
		}
		return 0;
	}
	bool GetInputValue(int & __nValue) {
		CDlg_PADNumeric dlg(PAD_MDInteger);
		if(dlg.DoModal() == IDOK) {
			__nValue = (int)dlg.GetValue();
			return true;
		}
		return false;
	}
	void OnManual_SetPLCIn(int __nIndex) {
		int nTemp;
		//__nIndex -= 1;
		switch(m_Algorithm.m_PLC.PLC_GetType(__nIndex)) {
		case MNVT_MemBit:
			nTemp = (m_Algorithm.m_PLC.PLC_GetValue(__nIndex) != 0) ? 0 : 1;
			m_Algorithm.m_PLC.PLC_SetValue(__nIndex, nTemp);
			break;
		case MNVT_MemWord:
			if (GetInputValue(nTemp))
				m_Algorithm.m_PLC.PLC_SetValue(__nIndex, nTemp);
			break;
		case MNVT_MemDWord:
			if (GetInputValue(nTemp))
				m_Algorithm.m_PLC.PLC_SetValue(__nIndex, nTemp);
			break;
		default:
			AfxMessageBox(_T("Error"));
			break;
		}
	}
	void OnManual_SetPLCOut(int __nIndex) {
		int nTemp;
		switch(m_Algorithm.m_PLC.Vision_GetType(__nIndex)) {
		case MNVT_MemBit:
			nTemp = (m_Algorithm.m_PLC.Vision_GetValue(__nIndex) != 0) ? 0 : 1;
			m_Algorithm.m_PLC.Vision_SetValue(__nIndex, nTemp);
			break;
		case MNVT_MemWord:
			if (GetInputValue(nTemp))
				m_Algorithm.m_PLC.Vision_SetValue(__nIndex, nTemp);
			break;
		case MNVT_MemDWord:
			if (GetInputValue(nTemp))
				m_Algorithm.m_PLC.Vision_SetValue(__nIndex, nTemp);
			break;
		default:
			AfxMessageBox(_T("Error"));
			break;
		}
	}

	void Reflash_PLC() {
		//m_dlgMain.OnReflash(m_Algorithm);
		m_dlgSDRun.OnReflash(m_Algorithm);
		m_dlgSetting.OnReflash(m_Algorithm);
	}
	void OnThread_Enable(MNV_ThreadID __nThreadID) {
		switch(__nThreadID) {
		case MNV_TID_Algorithm:
			m_Algorithm.AlgorithmEnable(!m_Algorithm.IsAlgorithmEnable());
			break;
		case MNV_TID_PLC:
			m_Algorithm.m_PLC.PLCEnable(!m_Algorithm.m_PLC.IsPLCEnable());
			break;
		}
	}
};
