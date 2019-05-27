// Dlg_PADRS232Setting.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MN_VIS.h"
#include "Dlg_PADRS232Setting.h"
#include "afxdialogex.h"


// CDlg_PADRS232Setting 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_PADRS232Setting, CDialogEx)

CDlg_PADRS232Setting::CDlg_PADRS232Setting(CWnd* pParent /*=NULL*/)
	: CMNVDialogEx(CDlg_PADRS232Setting::IDD, pParent)
{

}

CDlg_PADRS232Setting::~CDlg_PADRS232Setting()
{
}

void CDlg_PADRS232Setting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_PADRS232Setting, CDialogEx)
END_MESSAGE_MAP()


// CDlg_PADRS232Setting 메시지 처리기입니다.


BOOL CDlg_PADRS232Setting::OnInitDialog()
{
	CMNVDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
