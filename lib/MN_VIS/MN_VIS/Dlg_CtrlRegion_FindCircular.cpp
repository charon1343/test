// Dlg_CtrlRegion_FindCircular.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Dlg_CtrlRegion_FindCircular.h"
#include "afxdialogex.h"


// CDlg_CtrlRegion_FindCircular 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_CtrlRegion_FindCircular, CDialogEx)

CDlg_CtrlRegion_FindCircular::CDlg_CtrlRegion_FindCircular(CWnd* pParent /*=NULL*/)
	: CMNVDialogEx(CDlg_CtrlRegion_FindCircular::IDD, pParent)
{

}

CDlg_CtrlRegion_FindCircular::~CDlg_CtrlRegion_FindCircular()
{
}

void CDlg_CtrlRegion_FindCircular::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_CtrlRegion_FindCircular, CDialogEx)
	ON_WM_WINDOWPOSCHANGED()
END_MESSAGE_MAP()


// CDlg_CtrlRegion_FindCircular 메시지 처리기입니다.


BOOL CDlg_CtrlRegion_FindCircular::OnInitDialog()
{
	CMNVDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlg_CtrlRegion_FindCircular::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CMNVDialogEx::OnWindowPosChanged(lpwndpos);
	if (m_pAlgorithm->m_Model.m_cdType == MNV_AT_CircularBlob) {
	}
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
