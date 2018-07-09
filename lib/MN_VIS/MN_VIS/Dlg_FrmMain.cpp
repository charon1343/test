// Dlg_FrmMain.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MN_VIS.h"
#include "Dlg_FrmMain.h"
#include "afxdialogex.h"


// CDlg_FrmMain ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlg_FrmMain, CDialogEx)

CDlg_FrmMain::CDlg_FrmMain(CWnd* pParent /*=NULL*/)
	: CMNVDialogEx(CDlg_FrmMain::IDD, pParent)
{

}

CDlg_FrmMain::~CDlg_FrmMain()
{
}

void CDlg_FrmMain::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_FrmMain, CDialogEx)
	ON_WM_WINDOWPOSCHANGED()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlg_FrmMain �޽��� ó�����Դϴ�.


BOOL CDlg_FrmMain::OnInitDialog()
{
	CMNVDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_View.Create(m_pAlgorithm, this, this);

	m_SDRun.Create(m_pAlgorithm, this, m_pParent);
	m_SDVision.Create(m_SDVision.IDD, this, this);
	m_SDManual.Create(m_SDManual.IDD, this, this);

	m_SDModel.Create(m_pAlgorithm, this, this);

	m_IOMap.Create(IDD_MA_IOMap, this, this);
	m_Light.Create(IDD_MA_LIGHT, this, this);
	m_PLC.Create(IDD_MA_PLC, this, this);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CDlg_FrmMain::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CMNVDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	CRect rect;
	GetClientRect(&rect);

	if (m_View.GetSafeHwnd() != INVALID_HANDLE_VALUE) {
		m_View.SetWindowPos(NULL, rect.left, rect.top, rect.Width() - 300, rect.Height(), SWP_NOZORDER);
		//m_View.ShowWindow(true);
	}

	m_SDRun.SetWindowPos(NULL, rect.Width() - 300, rect.top, 300, rect.Height(), SWP_NOZORDER);
	m_SDModel.SetWindowPos(NULL, rect.Width() - 300, rect.top, 300, rect.Height(), SWP_NOZORDER);
	m_SDVision.SetWindowPos(NULL, rect.Width() - 300, rect.top, 300, rect.Height(), SWP_NOZORDER);
	m_SDManual.SetWindowPos(NULL, rect.Width() - 300, rect.top, 300, rect.Height(), SWP_NOZORDER);

	m_IOMap.SetWindowPos(rect.left, rect.top, rect.Width() - 300, rect.Height());
	{
		CRect Left = rect;
		CRect Right = rect;
		Left.right = Left.left + Left.Width() / 2;
		Right.left = Left.right;
		m_Light.SetWindowPos(Left);
		m_PLC.SetWindowPos(Right);
	}
	//m_SDRun.ShowWindow(true);
}


void CDlg_FrmMain::OnDestroy()
{
	CMNVDialogEx::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	//m_View.DestroyWindow();
	//m_SDRun.DestroyWindow();
	//m_SDVision.DestroyWindow();
	//m_SDModel.DestroyWindow();

	//m_IOMap.DestroyWindow();
	//m_Light.DestroyWindow();
	//m_PLC.DestroyWindow();
	//EndThread();
}
