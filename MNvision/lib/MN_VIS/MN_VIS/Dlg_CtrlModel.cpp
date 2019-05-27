// Dlg_CtrlModel.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Dlg_CtrlModel.h"
#include "afxdialogex.h"


// CDlg_CtrlModel ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlg_CtrlModel, CDialogEx)

CDlg_CtrlModel::CDlg_CtrlModel(CWnd* pParent /*=NULL*/)
	: CMNVDialogEx(CDlg_CtrlModel::IDD, pParent)
{

}

CDlg_CtrlModel::~CDlg_CtrlModel()
{
}

void CDlg_CtrlModel::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_CtrlModel, CDialogEx)
	ON_WM_WINDOWPOSCHANGED()
	ON_BN_CLICKED(IDC_MODEL_ModelNo, &CDlg_CtrlModel::OnBnClickedModelModelno)
	ON_BN_CLICKED(IDC_MODEL_ItemNo, &CDlg_CtrlModel::OnBnClickedModelItemno)
	ON_BN_CLICKED(IDC_MODEL_VisionNo, &CDlg_CtrlModel::OnBnClickedModelVisionno)
	ON_BN_CLICKED(IDC_MODEL_Load, &CDlg_CtrlModel::OnBnClickedModelLoad)
	ON_BN_CLICKED(IDC_MODEL_Save, &CDlg_CtrlModel::OnBnClickedModelSave)
END_MESSAGE_MAP()


// CDlg_CtrlModel �޽��� ó�����Դϴ�.


BOOL CDlg_CtrlModel::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CDlg_CtrlModel::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CDialogEx::OnWindowPosChanged(lpwndpos);

	CRect rect;
	GetClientRect(&rect);
	int nMargin = 5;

	rect.left += nMargin;
	rect.top += nMargin;
	rect.right -= nMargin;
	rect.bottom -= nMargin;

	int nWidthX2 = rect.Width();
	int nWidth = (nWidthX2 - nMargin) / 2;

	int nHeight = (rect.Height()+ nMargin) / 4 - nMargin;

	int nTop[4];
	nTop[0] = rect.top;
	nTop[1] = nTop[0] + nHeight + nMargin;
	nTop[2] = nTop[1] + nHeight + nMargin;
	nTop[3] = nTop[2] + nHeight + nMargin;

	int nLeft[2];
	nLeft[0] = rect.left;
	nLeft[1] = nLeft[0] + nWidth + nMargin;

	SetWindowPos(IDC_MODEL_ModelNo, nLeft[0], nTop[0], nWidthX2, nHeight);
	SetWindowPos(IDC_MODEL_ItemNo, nLeft[0], nTop[1], nWidthX2, nHeight);
	SetWindowPos(IDC_MODEL_VisionNo, nLeft[0], nTop[2], nWidthX2, nHeight);
	SetWindowPos(IDC_MODEL_Load, nLeft[0], nTop[3], nWidth, nHeight);
	SetWindowPos(IDC_MODEL_Save, nLeft[1], nTop[3], nWidth, nHeight);
}
