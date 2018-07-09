// Dlg_MsgLoading.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MN_VIS.h"
#include "Dlg_MsgLoading.h"
#include "afxdialogex.h"


// CDlg_MsgLoading ��ȭ �����Դϴ�.

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


// CDlg_MsgLoading �޽��� ó�����Դϴ�.


BOOL CDlg_MsgLoading::OnInitDialog()
{
	CMNVDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	nCount = 0;
	isProcessing = true;
	CreateThread();
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
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