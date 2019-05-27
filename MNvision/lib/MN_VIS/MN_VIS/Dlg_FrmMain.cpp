// Dlg_FrmMain.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MN_VIS.h"
#include "Dlg_FrmMain.h"
#include "afxdialogex.h"


// CDlg_FrmMain 대화 상자입니다.

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


// CDlg_FrmMain 메시지 처리기입니다.


BOOL CDlg_FrmMain::OnInitDialog()
{
	CMNVDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_View.Create(m_pAlgorithm, this, this);

	m_SDRun.Create(m_pAlgorithm, this, m_pParent);
	m_SDVision.Create(m_SDVision.IDD, this, this);
	m_SDManual.Create(m_SDManual.IDD, this, this);

	m_SDModel.Create(m_pAlgorithm, this, this);

	m_IOMap.Create(IDD_MA_IOMap, this, this);
	m_Light.Create(IDD_MA_LIGHT, this, this);
	m_PLC.Create(IDD_MA_PLC, this, this);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlg_FrmMain::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CMNVDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
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

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	//m_View.DestroyWindow();
	//m_SDRun.DestroyWindow();
	//m_SDVision.DestroyWindow();
	//m_SDModel.DestroyWindow();

	//m_IOMap.DestroyWindow();
	//m_Light.DestroyWindow();
	//m_PLC.DestroyWindow();
	//EndThread();
}
