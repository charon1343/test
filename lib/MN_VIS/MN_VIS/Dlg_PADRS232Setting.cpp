// Dlg_PADRS232Setting.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MN_VIS.h"
#include "Dlg_PADRS232Setting.h"
#include "afxdialogex.h"


// CDlg_PADRS232Setting ��ȭ �����Դϴ�.

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


// CDlg_PADRS232Setting �޽��� ó�����Դϴ�.


BOOL CDlg_PADRS232Setting::OnInitDialog()
{
	CMNVDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
