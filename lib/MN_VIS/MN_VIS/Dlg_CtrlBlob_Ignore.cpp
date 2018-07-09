// Dlg_CtrlBlob_Ignore.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Dlg_CtrlBlob_Ignore.h"
#include "afxdialogex.h"


// CDlg_CtrlBlob_Ignore 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_CtrlBlob_Ignore, CDialogEx)

CDlg_CtrlBlob_Ignore::CDlg_CtrlBlob_Ignore(CWnd* pParent /*=NULL*/)
	: CMNVDialogEx(CDlg_CtrlBlob_Ignore::IDD, pParent)
{

}

CDlg_CtrlBlob_Ignore::~CDlg_CtrlBlob_Ignore()
{
}

void CDlg_CtrlBlob_Ignore::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BlobLabel_AreaMax, m_ctrlLabel_AreaMax);
	DDX_Control(pDX, IDC_BlobLabel_AreaMin, m_ctrlLabel_AreaMin);
	DDX_Control(pDX, IDC_BlobLabel_AreaRate, m_ctrlLabel_AreaRate);
	DDX_Control(pDX, IDC_BlobSet_AreaMax, m_ctrlSet_AreaMax);
	DDX_Control(pDX, IDC_BlobSet_AreaMin, m_ctrlSet_AreaMin);
	DDX_Control(pDX, IDC_BlobSet_AreaRate, m_ctrlSet_AreaRate);
}


BEGIN_MESSAGE_MAP(CDlg_CtrlBlob_Ignore, CDialogEx)
	ON_WM_WINDOWPOSCHANGED()
END_MESSAGE_MAP()


// CDlg_CtrlBlob_Ignore 메시지 처리기입니다.


BOOL CDlg_CtrlBlob_Ignore::OnInitDialog()
{
	CMNVDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlg_CtrlBlob_Ignore::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CMNVDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if ((lpwndpos->flags & SWP_NOSIZE) == 0) {
		CRect rctCurrent;
		GetClientRect(&rctCurrent);
		rctCurrent.left += 5;
		rctCurrent.top += 5;
		rctCurrent.right -= 5;
		rctCurrent.bottom -= 5;

		int nHeight = 35;
		int nInterval = 2;
		int nWidth = (rctCurrent.Width() + nInterval) / 2 - nInterval;

		CRect rctLabel = rctCurrent;
		CRect rctSet = rctCurrent;

		rctLabel.right = rctLabel.left + nWidth;
		rctSet.left = rctLabel.right + nInterval;
		rctLabel.bottom = rctLabel.top + nHeight;
		rctSet.bottom = rctLabel.bottom;
		m_ctrlLabel_AreaRate.SetWindowPos(rctLabel);
		m_ctrlSet_AreaRate.SetWindowPos(rctSet);

		rctLabel.top = rctLabel.bottom + nInterval;
		rctLabel.bottom = rctLabel.top + nHeight;
		rctSet.top = rctLabel.top;
		rctSet.bottom = rctLabel.bottom;
		m_ctrlLabel_AreaMin.SetWindowPos(rctLabel);
		m_ctrlSet_AreaMin.SetWindowPos(rctSet);

		rctLabel.top = rctLabel.bottom + nInterval;
		rctLabel.bottom = rctLabel.top + nHeight;
		rctSet.top = rctLabel.top;
		rctSet.bottom = rctLabel.bottom;
		m_ctrlLabel_AreaMax.SetWindowPos(rctLabel);
		m_ctrlSet_AreaMax.SetWindowPos(rctSet);
	}
}
