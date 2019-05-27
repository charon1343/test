// Dlg_MsgLoading.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MN_VIS.h"
#include "Dlg_MsgLoading.h"
#include "afxdialogex.h"


// CDlg_MsgLoading 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_MsgLoading, CDialogEx)

CDlg_MsgLoading::CDlg_MsgLoading(CWnd* pParent /*=NULL*/)
	: CMNVDialogEx(CDlg_MsgLoading::IDD, pParent)
{

}

CDlg_MsgLoading::~CDlg_MsgLoading()
{
}

void CDlg_MsgLoading::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_MsgLoading, CDialogEx)
END_MESSAGE_MAP()


// CDlg_MsgLoading 메시지 처리기입니다.


BOOL CDlg_MsgLoading::OnInitDialog()
{
	CMNVDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	nCount = 0;
	isProcessing = true;
	CreateThread();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
void CDlg_MsgLoading::Thread()
{
	int nMax = 300;
	int Cnt = 0;
	while(Cnt >= 0) {
		SetProgress(Cnt * 100 / nMax);
		Sleep(50);
		if (Cnt < (nCount * nMax / 100) ) ++Cnt;
		if (Cnt >= nMax) {
			//Sleep(500);
			Cnt = -1;
		}
	}
	Sleep(100);
	ShowWindow(false);
	isProcessing = false;
}