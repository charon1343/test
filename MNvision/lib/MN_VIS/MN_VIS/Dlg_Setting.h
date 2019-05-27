#pragma once


// CDlg_Setting 대화 상자입니다.
#include "Dlg_FrmHeader.h"
#include "Dlg_FrmMain.h"
#include "Dlg_FrmFooter.h"

// LightControl
#include "LightControl\CMNV_LFineControl.h"
#include "MNVAlgorithm.h"

class CDlg_Setting : public CMNVDialogEx
{
	DECLARE_DYNAMIC(CDlg_Setting)
	CString m_strLayOut;

	CDlg_FrmHeader	m_dlgHeader;
	CDlg_FrmMain	m_dlgMain;
	CDlg_FrmFooter	m_dlgFooter;

	//CMNV_LFineControl m_LightControl;
	CMNVAlgorithm * m_pAlgorithm;
public:
	void MNVRelease() {
		//m_dlgHeader.MNVRelease();
		m_dlgMain.MNVRelease();
		//m_dlgFooter.MNVRelease();

		EndThread();
	}
	CDlg_Setting(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_Setting();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MN_VIS_SETTING };
	void Create(CMNVAlgorithm * __pAlgorithm, CWnd * __pWnd, CMNVDialogEx * __pParent) {
		m_pAlgorithm = __pAlgorithm;
		CMNVDialogEx::Create(IDD, __pWnd, __pParent);
	}

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	void SetImage(int __nIndex, CMNVImage & __img) { m_dlgMain.SetImage(__nIndex, __img); }
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	//void InitVisionData(int __nChannel, int __nCamera, CCamInfo * __pCmaInfo) { m_dlgMain.InitVisionData(__nChannel, __nCamera, __pCmaInfo); }
	virtual BOOL OnInitDialog();
	virtual void OnCancel() {
		m_pParent->OnCmd_Command(CMD_MENU_Run, 1, 0);
		ShowWindow(false);
	}
	void SetLayout() {
		CRect rect;
		GetClientRect(&rect);
		int Header = CMNVIni::GetValue(_T("Main"), _T("Header"), 50, m_strLayOut);
		int Footer = CMNVIni::GetValue(_T("Main"), _T("Footer"), 20, m_strLayOut);
		int nMargin = CMNVIni::GetValue(_T("Main"), _T("Margin"), 5, m_strLayOut);

		int nTop[3];
		nTop[0] = rect.top + nMargin;
		nTop[1] = nTop[0] + nMargin + Header;
		nTop[2] = rect.bottom - nMargin - Footer;

		int nLeft = rect.left + nMargin;
		int nWidth = rect.Width() - nMargin * 2;
		int nHeight = rect.Height() - nMargin * 4 - Header - Footer;

		m_dlgHeader.SetWindowPos(nLeft, nTop[0], nWidth, Header);
		m_dlgMain.SetWindowPos(nLeft, nTop[1], nWidth, nHeight);
		m_dlgFooter.SetWindowPos(nLeft, nTop[2], nWidth, Footer);
	}
	void LoadLayout() {
		WINDOWINFO winfo;
		GetWindowInfo(&winfo);
		int PosX = CMNVIni::GetValue(_T("SubSetting"), _T("PosX"), 0, m_strLayOut);
		int PosY = CMNVIni::GetValue(_T("SubSetting"), _T("PosY"), 0, m_strLayOut);
		int SizeX = CMNVIni::GetValue(_T("SubSetting"), _T("SizeX"), 0, m_strLayOut);
		int SizeY = CMNVIni::GetValue(_T("SubSetting"), _T("SizeY"), 0, m_strLayOut);
		FullScreen(false);
		ShowWindow(false);
		SetWindowPos(PosX, PosY, SizeX, SizeY);
		if (CMNVIni::GetValue(_T("SubSetting"), _T("FullScreen"), 0, m_strLayOut) == 1) FullScreen(true);
		else ShowWindow(true);

		SetLayout();

		if ((winfo.dwStyle & WS_VISIBLE) != NULL) {
		}
		else {
			ShowWindow(false);
		}
	}
	void SetMode(Menu_Mode __Mode) {
		m_dlgHeader.SetMode(__Mode);
		if (__Mode == Mode_Opertor) {
			m_pParent->OnCmd_Command(CMD_MENU_Run, 1, 0);
		}
	}
	bool SetMenu(Menu_Select __Menu) {
		bool isRet = m_dlgHeader.CheckMenu(__Menu);
		m_dlgMain.SelectMenu(__Menu);
		if (__Menu == Menu_Main) {
			ShowWindow(false);
			return true;
		}
		else {
			ShowWindow(true);
			return isRet;
		}
	}
	virtual int OnCmd_Command(MNV_Command __Cmd, WPARAM __wParam, LPARAM __lParam) {
		switch(__Cmd) {
		case CMD_MENU_Model:
		case CMD_MENU_Manual:
		case CMD_MENU_Run:
		case CMD_MENU_System:
		case CMD_MENU_Vision:
			m_pParent->OnCmd_Command(__Cmd, 1, __lParam);
			break;
		default:
			m_pParent->OnCmd_Command(__Cmd, __wParam, __lParam);
			break;
		}
		return 0;
	}	
	afx_msg void OnDestroy();

	void OnReflash(CMNVAlgorithm & __Algorithm) {
		m_dlgMain.OnReflash(__Algorithm);
	}
	void InitSelector(CMNVAlgorithm & __Algorithm) {
		m_dlgMain.InitSelector(__Algorithm);
	}
	void OnCameraSetting(CMNVAlgorithm & __Algorithm) {
		m_dlgMain.OnCameraSetting(__Algorithm);
	}
	void InitControl(CMNVAlgorithm & __Algorithm) {
		m_dlgMain.InitControl(__Algorithm);
	}

	void OnCmd_ShowMaster(CMNVAlgorithm & __Algorithm) {
		m_dlgMain.OnCmd_ShowMaster(__Algorithm);
	}
	void OnCmd_SetPattern(CMNVAlgorithm & __Algorithm) {
		m_dlgMain.OnCmd_SetPattern(__Algorithm);
	}
};
