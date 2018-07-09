// Dlg_MAView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MN_VIS.h"
#include "Dlg_MAView.h"
#include "afxdialogex.h"


// CDlg_MAView 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_MAView, CDialogEx)

CDlg_MAView::CDlg_MAView(CWnd* pParent /*=NULL*/)
	: CMNVDialogEx(CDlg_MAView::IDD, pParent)
{

}

CDlg_MAView::~CDlg_MAView()
{
}

void CDlg_MAView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_MAView, CDialogEx)
	ON_WM_WINDOWPOSCHANGED()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlg_MAView 메시지 처리기입니다.


BOOL CDlg_MAView::OnInitDialog()
{
	CMNVDialogEx::OnInitDialog();
	m_pcogCamInfo = NULL;
	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_cogDisplay.Create(GetDlgItem(IDC_COGDISPLAY1));

	m_cdDisplayMode = 0;
	//m_cogCamInfo.GrabStart();
	CreateThread();
	//CMNVProtocol_Yokogawa Test;
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlg_MAView::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CMNVDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


//BOOL CDlg_MAView::DestroyWindow()
//{
//	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
//	return CMNVDialogEx::DestroyWindow();
//}
//
//
//void CDlg_MAView::OnDestroy()
//{
//	CMNVDialogEx::OnDestroy();
//	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
//}
