// Dlg_CtrlRegion_FindCircular.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Dlg_CtrlRegion_FindCircular.h"
#include "afxdialogex.h"


// CDlg_CtrlRegion_FindCircular ��ȭ �����Դϴ�.

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


// CDlg_CtrlRegion_FindCircular �޽��� ó�����Դϴ�.


BOOL CDlg_CtrlRegion_FindCircular::OnInitDialog()
{
	CMNVDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CDlg_CtrlRegion_FindCircular::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CMNVDialogEx::OnWindowPosChanged(lpwndpos);
	if (m_pAlgorithm->m_Model.m_cdType == MNV_AT_CircularBlob) {
	}
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}
