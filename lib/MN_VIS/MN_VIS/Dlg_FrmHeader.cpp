// Dlg_FrmHeader.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MN_VIS.h"
#include "Dlg_FrmHeader.h"
#include "afxdialogex.h"


// CDlg_FrmHeader 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_FrmHeader, CDialogEx)

CDlg_FrmHeader::CDlg_FrmHeader(CWnd* pParent /*=NULL*/)
	: CMNVDialogEx(CDlg_FrmHeader::IDD, pParent)
{

}

CDlg_FrmHeader::~CDlg_FrmHeader()
{
}

void CDlg_FrmHeader::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_FrmHeader, CDialogEx)
	ON_WM_WINDOWPOSCHANGED()
END_MESSAGE_MAP()


// CDlg_FrmHeader 메시지 처리기입니다.


BOOL CDlg_FrmHeader::OnInitDialog()
{
	CMNVDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_dlgMenu.Create(m_pAlgorithm, this, m_pParent);

	//CRect rect;
	//GetClientRect(&rect);
	//int Header = 50;
	//int Footer = 50;
	//m_dlgMenu.SetWindowPos(NULL, rect.left, rect.top, rect.Width(), Header, SWP_NOZORDER);
	//m_dlgMenu.ShowWindow(true);
	//RedrawWindow();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlg_FrmHeader::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CMNVDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CRect rect;
	GetClientRect(&rect);
	//int Header = 50;
	//int Footer = 50;
	m_dlgMenu.SetWindowPos(NULL, rect.left, rect.top, rect.Width(), rect.Height(), SWP_NOZORDER);
	m_dlgMenu.ShowWindow(true);
	//RedrawWindow();
}


BOOL CDlg_FrmHeader::DestroyWindow()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_dlgMenu.DestroyWindow();
	return CMNVDialogEx::DestroyWindow();
}
