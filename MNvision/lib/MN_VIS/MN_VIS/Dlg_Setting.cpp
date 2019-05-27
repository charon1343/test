// Dlg_Setting.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MN_VIS.h"
#include "Dlg_Setting.h"
#include "afxdialogex.h"


// CDlg_Setting 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_Setting, CDialogEx)

CDlg_Setting::CDlg_Setting(CWnd* pParent /*=NULL*/)
	: CMNVDialogEx(CDlg_Setting::IDD, pParent)
{

}

CDlg_Setting::~CDlg_Setting()
{
}

void CDlg_Setting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_Setting, CDialogEx)
	ON_WM_WINDOWPOSCHANGED()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlg_Setting 메시지 처리기입니다.


void CDlg_Setting::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CMNVDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	SetLayout();
}


BOOL CDlg_Setting::OnInitDialog()
{
	CMNVDialogEx::OnInitDialog();
	m_strLayOut = _T("D:\\Setting\\LayOut.ini");
	//{
	//	wchar_t strBuf[1024];
	//	GetCurrentDirectory(1024, strBuf);
	//	m_strLayOut.Format(_T("%s\\LayOut.ini"), strBuf);
	//}

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	//m_LightControl.Init(_T("COM1"), CBR_9600, 8, NOPARITY, ONESTOPBIT);

	m_dlgHeader.Create(m_pAlgorithm, this, this);
	m_dlgMain.Create(m_pAlgorithm, this, this);
	m_dlgFooter.Create(IDD_FRM_FOOTER, this, this);

	m_dlgHeader.CheckMain(false);
	m_dlgHeader.ShowWindow(true);
	m_dlgMain.ShowWindow(true);
	m_dlgFooter.ShowWindow(true);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlg_Setting::OnDestroy()
{
	CMNVDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
