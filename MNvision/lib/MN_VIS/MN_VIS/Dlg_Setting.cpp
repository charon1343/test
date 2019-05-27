// Dlg_Setting.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MN_VIS.h"
#include "Dlg_Setting.h"
#include "afxdialogex.h"


// CDlg_Setting ��ȭ �����Դϴ�.

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


// CDlg_Setting �޽��� ó�����Դϴ�.


void CDlg_Setting::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CMNVDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
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

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	//m_LightControl.Init(_T("COM1"), CBR_9600, 8, NOPARITY, ONESTOPBIT);

	m_dlgHeader.Create(m_pAlgorithm, this, this);
	m_dlgMain.Create(m_pAlgorithm, this, this);
	m_dlgFooter.Create(IDD_FRM_FOOTER, this, this);

	m_dlgHeader.CheckMain(false);
	m_dlgHeader.ShowWindow(true);
	m_dlgMain.ShowWindow(true);
	m_dlgFooter.ShowWindow(true);
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CDlg_Setting::OnDestroy()
{
	CMNVDialogEx::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}
