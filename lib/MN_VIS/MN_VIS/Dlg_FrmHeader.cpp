// Dlg_FrmHeader.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MN_VIS.h"
#include "Dlg_FrmHeader.h"
#include "afxdialogex.h"


// CDlg_FrmHeader ��ȭ �����Դϴ�.

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


// CDlg_FrmHeader �޽��� ó�����Դϴ�.


BOOL CDlg_FrmHeader::OnInitDialog()
{
	CMNVDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_dlgMenu.Create(m_pAlgorithm, this, m_pParent);

	//CRect rect;
	//GetClientRect(&rect);
	//int Header = 50;
	//int Footer = 50;
	//m_dlgMenu.SetWindowPos(NULL, rect.left, rect.top, rect.Width(), Header, SWP_NOZORDER);
	//m_dlgMenu.ShowWindow(true);
	//RedrawWindow();

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CDlg_FrmHeader::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CMNVDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_dlgMenu.DestroyWindow();
	return CMNVDialogEx::DestroyWindow();
}
