// Dlg_MAView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MN_VIS.h"
#include "Dlg_MAView.h"
#include "afxdialogex.h"


// CDlg_MAView ��ȭ �����Դϴ�.

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


// CDlg_MAView �޽��� ó�����Դϴ�.


BOOL CDlg_MAView::OnInitDialog()
{
	CMNVDialogEx::OnInitDialog();
	m_pcogCamInfo = NULL;
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_cogDisplay.Create(GetDlgItem(IDC_COGDISPLAY1));

	m_cdDisplayMode = 0;
	//m_cogCamInfo.GrabStart();
	CreateThread();
	//CMNVProtocol_Yokogawa Test;
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CDlg_MAView::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CMNVDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


//BOOL CDlg_MAView::DestroyWindow()
//{
//	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
//	return CMNVDialogEx::DestroyWindow();
//}
//
//
//void CDlg_MAView::OnDestroy()
//{
//	CMNVDialogEx::OnDestroy();
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
//}
