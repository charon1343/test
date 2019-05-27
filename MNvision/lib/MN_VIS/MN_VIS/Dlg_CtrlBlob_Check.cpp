// Dlg_CtrlBlob_Check.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Dlg_CtrlBlob_Check.h"
#include "afxdialogex.h"


// CDlg_CtrlBlob_Check ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlg_CtrlBlob_Check, CDialogEx)

CDlg_CtrlBlob_Check::CDlg_CtrlBlob_Check(CWnd* pParent /*=NULL*/)
	: CMNVDialogEx(CDlg_CtrlBlob_Check::IDD, pParent)
{

}

CDlg_CtrlBlob_Check::~CDlg_CtrlBlob_Check()
{
}

void CDlg_CtrlBlob_Check::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BlobLabel_CenterX, m_ctrlLabel_CenterX);
	DDX_Control(pDX, IDC_BlobLabel_CenterY, m_ctrlLabel_CenterY);
	DDX_Control(pDX, IDC_BlobLabel_Distance, m_ctrlLabel_Distance);
	DDX_Control(pDX, IDC_BlobLabel_Width, m_ctrlLabel_Width);
	DDX_Control(pDX, IDC_BlobSet_CenterX, m_ctrlSet_CenterX);
	DDX_Control(pDX, IDC_BlobSet_CenterY, m_ctrlSet_CenterY);
	DDX_Control(pDX, IDC_BlobSet_Distance, m_ctrlSet_Distance);
	DDX_Control(pDX, IDC_BlobSet_Width, m_ctrlSet_Width);
	DDX_Control(pDX, IDC_BlobSet_CenterX2, m_ctrlSet_CenterX2);
	DDX_Control(pDX, IDC_BlobSet_CenterY2, m_ctrlSet_CenterY2);
	DDX_Control(pDX, IDC_BlobSet_Distance2, m_ctrlSet_Distance2);
	DDX_Control(pDX, IDC_BlobSet_Width2, m_ctrlSet_Width2);
}


BEGIN_MESSAGE_MAP(CDlg_CtrlBlob_Check, CDialogEx)
	ON_WM_WINDOWPOSCHANGED()
END_MESSAGE_MAP()


// CDlg_CtrlBlob_Check �޽��� ó�����Դϴ�.


BOOL CDlg_CtrlBlob_Check::OnInitDialog()
{
	CMNVDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CDlg_CtrlBlob_Check::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CMNVDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if ((lpwndpos->flags & SWP_NOSIZE) == 0) {
		CRect rctCurrent;
		GetClientRect(&rctCurrent);
		rctCurrent.left += 5;
		rctCurrent.top += 5;
		rctCurrent.right -= 5;
		rctCurrent.bottom -= 5;

		int nHeight = 35;
		int nInterval = 2;
		int nWidth = (rctCurrent.Width() + nInterval) / 3 - nInterval;

		CRect rctSetting2 = rctCurrent;
		rctSetting2.left = rctSetting2.right - nWidth;
		rctCurrent.right = rctSetting2.left - nInterval;

		CRect rctSetting = rctCurrent;
		rctSetting.left = rctSetting.right - nWidth;
		rctCurrent.right = rctSetting.left - nInterval;

		CRect rctLable = rctCurrent;

		rctLable.bottom = rctLable.top + nHeight;
		rctSetting.bottom = rctLable.bottom;
		rctSetting2.bottom = rctLable.bottom;
		m_ctrlLabel_CenterX.SetWindowPos(rctLable);
		m_ctrlSet_CenterX.SetWindowPos(rctSetting);
		m_ctrlSet_CenterX2.SetWindowPos(rctSetting2);

		rctLable.top = rctLable.bottom + nInterval;
		rctLable.bottom = rctLable.top + nHeight;
		rctSetting.top = rctLable.top;
		rctSetting.bottom = rctLable.bottom;
		rctSetting2.top = rctLable.top;
		rctSetting2.bottom = rctLable.bottom;
		m_ctrlLabel_CenterY.SetWindowPos(rctLable);
		m_ctrlSet_CenterY.SetWindowPos(rctSetting);
		m_ctrlSet_CenterY2.SetWindowPos(rctSetting2);

		rctLable.top = rctLable.bottom + nInterval;
		rctLable.bottom = rctLable.top + nHeight;
		rctSetting.top = rctLable.top;
		rctSetting.bottom = rctLable.bottom;
		rctSetting2.top = rctLable.top;
		rctSetting2.bottom = rctLable.bottom;
		m_ctrlLabel_Distance.SetWindowPos(rctLable);
		m_ctrlSet_Distance.SetWindowPos(rctSetting);
		m_ctrlSet_Distance2.SetWindowPos(rctSetting2);

		rctLable.top = rctLable.bottom + nInterval;
		rctLable.bottom = rctLable.top + nHeight;
		rctSetting.top = rctLable.top;
		rctSetting.bottom = rctLable.bottom;
		rctSetting2.top = rctLable.top;
		rctSetting2.bottom = rctLable.bottom;
		m_ctrlLabel_Width.SetWindowPos(rctLable);
		m_ctrlSet_Width.SetWindowPos(rctSetting);
		m_ctrlSet_Width2.SetWindowPos(rctSetting2);
	}
}
