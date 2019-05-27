#pragma once


// CDlg_HDMenu 대화 상자입니다.
#include "Dlg_PADNumeric.h"
#include "MNVAlgorithm.h"

enum Menu_Select { Menu_Main, Menu_Manual, Menu_Model, Menu_Vision, Menu_System };
enum Menu_Mode { Mode_Opertor, Mode_Manager };
class CDlg_HDMenu : public CMNVDialogEx
{
	DECLARE_DYNAMIC(CDlg_HDMenu)
	Menu_Mode m_Mode;
	CMNVAlgorithm * m_pAlgorithm;
public:
	CDlg_HDMenu(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_HDMenu();
	Menu_Select m_SelectMenu;
// 대화 상자 데이터입니다.
	enum { IDD = IDD_HD_Menu };
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
	bool m_isMain;
	void CheckMain(bool __isCheck) { m_isMain = __isCheck; SetItemCheck(IDC_MENU_Main, __isCheck); }
	virtual void Thread() {
		static int value = 0;
		bool isEnable = false;
		while(true) {
			SetItemCheck(IDC_MENU_Mode, false);
			isEnable = m_Mode == Mode_Manager;
			if (m_Mode == Mode_Manager) {
				SetItemData(IDC_MENU_Mode, _T("관리자")); }
			else {
				SetItemData(IDC_MENU_Mode, _T("운영자"));
			}
			SetItemCheck(IDC_MENU_Main, m_isMain);
			switch(m_SelectMenu) {
			case Menu_Main:
				//SetItemCheck(IDC_MENU_Main, true);
				SetItemCheck(IDC_MENU_Manual, false, isEnable);
				SetItemCheck(IDC_MENU_Model, false, isEnable);
				SetItemCheck(IDC_MENU_Vision, false, isEnable);
				SetItemCheck(IDC_MENU_System, false, isEnable);
				//_SelectMenu = Menu_Manual;
				break;
			case Menu_Manual:
				//SetItemCheck(IDC_MENU_Main, false);
				SetItemCheck(IDC_MENU_Manual, true, isEnable);
				SetItemCheck(IDC_MENU_Model, false, isEnable);
				SetItemCheck(IDC_MENU_Vision, false, isEnable);
				SetItemCheck(IDC_MENU_System, false, isEnable);
				//m_SelectMenu = Menu_Model;
				break;
			case Menu_Model:
				//SetItemCheck(IDC_MENU_Main, false);
				SetItemCheck(IDC_MENU_Manual, false, isEnable);
				SetItemCheck(IDC_MENU_Model, true, isEnable);
				SetItemCheck(IDC_MENU_Vision, false, isEnable);
				SetItemCheck(IDC_MENU_System, false, isEnable);
				//m_SelectMenu = Menu_Vision;
				break;
			case Menu_Vision:
				//SetItemCheck(IDC_MENU_Main, false);
				SetItemCheck(IDC_MENU_Manual, false, isEnable);
				SetItemCheck(IDC_MENU_Model, false, isEnable);
				SetItemCheck(IDC_MENU_Vision, true, isEnable);
				SetItemCheck(IDC_MENU_System, false, isEnable);
				//m_SelectMenu = Menu_System;
				break;
			case Menu_System:
				//SetItemCheck(IDC_MENU_Main, false);
				SetItemCheck(IDC_MENU_Manual, false, isEnable);
				SetItemCheck(IDC_MENU_Model, false, isEnable);
				SetItemCheck(IDC_MENU_Vision, false, isEnable);
				SetItemCheck(IDC_MENU_System, true, isEnable);
				//m_SelectMenu = Menu_Main;
				break;
			default:
				//SetItemCheck(IDC_MENU_Main, false);
				SetItemCheck(IDC_MENU_Manual, false, isEnable);
				SetItemCheck(IDC_MENU_Model, false, isEnable);
				SetItemCheck(IDC_MENU_Vision, false, isEnable);
				SetItemCheck(IDC_MENU_System, false, isEnable);
				//m_SelectMenu = Menu_Main;
				break;
			}
			value++;
			Sleep(10);
		}
		//dwThreadID = -1;
		//AfxMessageBox(_T("DestroyWindow"));
	}
	afx_msg void OnBnClickedMenuMain() { m_pParent->OnCmd_Command(CMD_MENU_Run, 0, 0); }
	afx_msg void OnBnClickedMenuManual() { m_pParent->OnCmd_Command(CMD_MENU_Manual, 0, 0); }
	afx_msg void OnBnClickedMenuModel() { m_pParent->OnCmd_Command(CMD_MENU_Model, 0, 0); }
	afx_msg void OnBnClickedMenuVision() { m_pParent->OnCmd_Command(CMD_MENU_Vision, 0, 0); }
	afx_msg void OnBnClickedMenuSystem() { m_pParent->OnCmd_Command(CMD_MENU_System, 0, 0); }
	virtual BOOL DestroyWindow();
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedMenuMode() {
		switch (m_Mode) {
			case Mode_Opertor: {
				m_pParent->OnCmd_Command(CMD_MENU_Mode, 0, Mode_Manager);
			} break;
			case Mode_Manager: {
				m_pParent->OnCmd_Command(CMD_MENU_Mode, 0, Mode_Opertor);
			} break;
		}
	}
	void SetMode(Menu_Mode __Mode) { m_Mode = __Mode; }

	afx_msg void OnBnClickedImage1() {
		m_pAlgorithm->m_pCamInfo[0].ImageLoad();
	}
	afx_msg void OnBnClickedImage2() {
		m_pAlgorithm->m_pCamInfo[1].ImageLoad();
	}
};
