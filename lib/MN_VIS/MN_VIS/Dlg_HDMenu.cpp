// Dlg_HDMenu.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MN_VIS.h"
#include "Dlg_HDMenu.h"
#include "afxdialogex.h"


// CDlg_HDMenu ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlg_HDMenu, CDialogEx)

CDlg_HDMenu::CDlg_HDMenu(CWnd* pParent /*=NULL*/)
	: CMNVDialogEx(CDlg_HDMenu::IDD, pParent)
{

}

CDlg_HDMenu::~CDlg_HDMenu()
{
}

void CDlg_HDMenu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_HDMenu, CDialogEx)
	ON_WM_WINDOWPOSCHANGED()
	ON_BN_CLICKED(IDC_MENU_Main, &CDlg_HDMenu::OnBnClickedMenuMain)
	ON_BN_CLICKED(IDC_MENU_Manual, &CDlg_HDMenu::OnBnClickedMenuManual)
	ON_BN_CLICKED(IDC_MENU_Model, &CDlg_HDMenu::OnBnClickedMenuModel)
	ON_BN_CLICKED(IDC_MENU_Vision, &CDlg_HDMenu::OnBnClickedMenuVision)
	ON_BN_CLICKED(IDC_MENU_System, &CDlg_HDMenu::OnBnClickedMenuSystem)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_MENU_Mode, &CDlg_HDMenu::OnBnClickedMenuMode)

	ON_BN_CLICKED(IDC_MENU_Image1, &CDlg_HDMenu::OnBnClickedImage1)
	ON_BN_CLICKED(IDC_MENU_Image2, &CDlg_HDMenu::OnBnClickedImage2)
END_MESSAGE_MAP()


// CDlg_HDMenu �޽��� ó�����Դϴ�.


BOOL CDlg_HDMenu::OnInitDialog()
{
	CMNVDialogEx::OnInitDialog();

	m_SelectMenu = Menu_Main;
	m_Mode = Mode_Opertor;
	CreateThread();
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CDlg_HDMenu::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CMNVDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	const int nCOUNT = 8;
	CWnd * pWnd[nCOUNT];
	pWnd[0] = GetDlgItem(IDC_MENU_Main);
	pWnd[1] = GetDlgItem(IDC_MENU_Manual);
	pWnd[2] = GetDlgItem(IDC_MENU_Model);
	pWnd[3] = GetDlgItem(IDC_MENU_Vision);
	pWnd[4] = GetDlgItem(IDC_MENU_System);
	pWnd[5] = GetDlgItem(IDC_MENU_Image1);
	pWnd[6] = GetDlgItem(IDC_MENU_Image2);
	pWnd[7] = GetDlgItem(IDC_MENU_Mode);
	CRect rect;
	GetClientRect(&rect);
	int nMargin = 2;
	int nWidth = rect.Width() / nCOUNT;
	int nHeight = rect.Height();
	int nLeft[nCOUNT];
	int nTop = 0;
	for(int nIndex = 0; nIndex < nCOUNT; ++nIndex)
		nLeft[nIndex] = nWidth * nIndex;
	nWidth -= nMargin;

	//int nLeft = 0;
	for(int nIndex = 0; nIndex < nCOUNT; ++nIndex) {
		pWnd[nIndex]->SetWindowPos(NULL, nLeft[nIndex], nTop, nWidth, nHeight, SWP_NOZORDER);
	}
	RedrawWindow();
}


BOOL CDlg_HDMenu::DestroyWindow()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	//AfxMessageBox(_T("DestroyWindow"));
	//dwThreadID = 0;
	//while(dwThreadID == 0) {
	//	Sleep(10);
	//}
	return CMNVDialogEx::DestroyWindow();
}


void CDlg_HDMenu::OnDestroy()
{
	//AfxMessageBox(_T("DestroyWindow"));
	CMNVDialogEx::OnDestroy();
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	//
}
