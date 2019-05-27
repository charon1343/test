#pragma once


// CDlg_FrmHeader 대화 상자입니다.
#include "Dlg_HDMenu.h"
#include "MNVAlgorithm.h"

class CDlg_FrmHeader : public CMNVDialogEx
{
	DECLARE_DYNAMIC(CDlg_FrmHeader)
	CDlg_HDMenu m_dlgMenu;
	CMNVAlgorithm * m_pAlgorithm;

public:
	void MNVRelease() { EndThread(); }
	CDlg_FrmHeader(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_FrmHeader();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FRM_HEADER };
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
	virtual BOOL DestroyWindow();
	void CheckMain(bool __isCheck) { m_dlgMenu.CheckMain(__isCheck); }
	bool CheckMenu(Menu_Select __Menu) {
		if (m_dlgMenu.m_SelectMenu == __Menu) return false;
		m_dlgMenu.m_SelectMenu = __Menu;
		return true;
	}
	void SetMode(Menu_Mode __Mode) {
		m_dlgMenu.SetMode(__Mode);
	}
};
