// Dlg_CtrlBlobSetting.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Dlg_CtrlBlobSetting.h"
#include "afxdialogex.h"


// CDlg_CtrlBlobSetting 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_CtrlBlobSetting, CDialogEx)

CDlg_CtrlBlobSetting::CDlg_CtrlBlobSetting(CWnd* pParent /*=NULL*/)
	: CMNVDialogEx(CDlg_CtrlBlobSetting::IDD, pParent)
{

}

CDlg_CtrlBlobSetting::~CDlg_CtrlBlobSetting()
{
}

void CDlg_CtrlBlobSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BlobLabel_Mode, m_ctrlLabel_Mode);
	DDX_Control(pDX, IDC_BlobLabel_Polarity, m_ctrlLabel_Polarity);
	DDX_Control(pDX, IDC_BlobLabel_Softness, m_ctrlLabel_Softness);
	DDX_Control(pDX, IDC_BlobLabel_TailHigh, m_ctrlLabel_TailHigh);
	DDX_Control(pDX, IDC_BlobLabel_TailLow, m_ctrlLabel_TailLow);
	DDX_Control(pDX, IDC_BlobLabel_ThresholdHigh, m_ctrlLabel_ThresholdHigh);
	DDX_Control(pDX, IDC_BlobLabel_ThresholdLow, m_ctrlLabel_ThresholdLow);
	DDX_Control(pDX, IDC_BlobSet_Mode, m_ctrlSet_Mode);
	DDX_Control(pDX, IDC_BlobSet_Polarity, m_ctrlSet_Polarity);
	DDX_Control(pDX, IDC_BlobSet_Softness, m_ctrlSet_Softness);
	DDX_Control(pDX, IDC_BlobSet_TailHigh, m_ctrlSet_TailHigh);
	DDX_Control(pDX, IDC_BlobSet_TailLow, m_ctrlSet_TailLow);
	DDX_Control(pDX, IDC_BlobSet_ThresholdHigh, m_ctrlSet_ThresholdHigh);
	DDX_Control(pDX, IDC_BlobSet_ThresholdLow, m_ctrlSet_ThresholdLow);
	DDX_Control(pDX, IDC_BlobSet_Polarity2, m_ctrlSet_Polarity2);
	DDX_Control(pDX, IDC_BlobSet_Softness2, m_ctrlSet_Softness2);
	DDX_Control(pDX, IDC_BlobSet_TailHigh2, m_ctrlSet_TailHigh2);
	DDX_Control(pDX, IDC_BlobSet_TailLow2, m_ctrlSet_TailLow2);
	DDX_Control(pDX, IDC_BlobSet_ThresholdHigh2, m_ctrlSet_ThresholdHigh2);
	DDX_Control(pDX, IDC_BlobSet_ThresholdLow2, m_ctrlSet_ThresholdLow2);
}


BEGIN_MESSAGE_MAP(CDlg_CtrlBlobSetting, CDialogEx)
	ON_WM_WINDOWPOSCHANGED()
END_MESSAGE_MAP()


// CDlg_CtrlBlobSetting 메시지 처리기입니다.


BOOL CDlg_CtrlBlobSetting::OnInitDialog()
{
	CMNVDialogEx::OnInitDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlg_CtrlBlobSetting::OnWindowPosChanged(WINDOWPOS* lpwndpos)
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
		int nWidth = (rctCurrent.Width() + nInterval) / 3 - nInterval;

		CRect rctSetting2 = rctCurrent;
		rctSetting2.left = rctSetting2.right - nWidth;
		rctCurrent.right = rctSetting2.left - nInterval;

		CRect rctSetting = rctCurrent;
		rctSetting.left = rctSetting.right - nWidth;
		rctCurrent.right = rctSetting.left - nInterval;

		CRect rctLable = rctCurrent;

		rctCurrent.SetRect(rctSetting.left, rctSetting.top, rctSetting2.right, rctSetting2.bottom);

		rctLable.bottom = rctLable.top + nHeight;
		rctSetting.bottom = rctLable.bottom;
		rctSetting2.bottom = rctLable.bottom;
		rctCurrent.bottom = rctLable.bottom;
		m_ctrlLabel_Mode.SetWindowPos(rctLable);
		m_ctrlSet_Mode.SetWindowPos(rctCurrent);

		rctLable.top = rctLable.bottom + nInterval;
		rctLable.bottom = rctLable.top + nHeight;
		rctSetting.top = rctLable.top;
		rctSetting.bottom = rctLable.bottom;
		rctSetting2.top = rctLable.top;
		rctSetting2.bottom = rctLable.bottom;
		m_ctrlLabel_Polarity.SetWindowPos(rctLable);
		m_ctrlSet_Polarity.SetWindowPos(rctSetting);
		m_ctrlSet_Polarity2.SetWindowPos(rctSetting2);

		rctLable.top = rctLable.bottom + nInterval;
		rctLable.bottom = rctLable.top + nHeight;
		rctSetting.top = rctLable.top;
		rctSetting.bottom = rctLable.bottom;
		rctSetting2.top = rctLable.top;
		rctSetting2.bottom = rctLable.bottom;
		m_ctrlLabel_TailLow.SetWindowPos(rctLable);
		m_ctrlSet_TailLow.SetWindowPos(rctSetting);
		m_ctrlSet_TailLow2.SetWindowPos(rctSetting2);

		rctLable.top = rctLable.bottom + nInterval;
		rctLable.bottom = rctLable.top + nHeight;
		rctSetting.top = rctLable.top;
		rctSetting.bottom = rctLable.bottom;
		rctSetting2.top = rctLable.top;
		rctSetting2.bottom = rctLable.bottom;
		m_ctrlLabel_TailHigh.SetWindowPos(rctLable);
		m_ctrlSet_TailHigh.SetWindowPos(rctSetting);
		m_ctrlSet_TailHigh2.SetWindowPos(rctSetting2);

		rctLable.top = rctLable.bottom + nInterval;
		rctLable.bottom = rctLable.top + nHeight;
		rctSetting.top = rctLable.top;
		rctSetting.bottom = rctLable.bottom;
		rctSetting2.top = rctLable.top;
		rctSetting2.bottom = rctLable.bottom;
		m_ctrlLabel_ThresholdLow.SetWindowPos(rctLable);
		m_ctrlSet_ThresholdLow.SetWindowPos(rctSetting);
		m_ctrlSet_ThresholdLow2.SetWindowPos(rctSetting2);

		rctLable.top = rctLable.bottom + nInterval;
		rctLable.bottom = rctLable.top + nHeight;
		rctSetting.top = rctLable.top;
		rctSetting.bottom = rctLable.bottom;
		rctSetting2.top = rctLable.top;
		rctSetting2.bottom = rctLable.bottom;
		m_ctrlLabel_ThresholdHigh.SetWindowPos(rctLable);
		m_ctrlSet_ThresholdHigh.SetWindowPos(rctSetting);
		m_ctrlSet_ThresholdHigh2.SetWindowPos(rctSetting2);

		rctLable.top = rctLable.bottom + nInterval;
		rctLable.bottom = rctLable.top + nHeight;
		rctSetting.top = rctLable.top;
		rctSetting.bottom = rctLable.bottom;
		rctSetting2.top = rctLable.top;
		rctSetting2.bottom = rctLable.bottom;
		m_ctrlLabel_Softness.SetWindowPos(rctLable);
		m_ctrlSet_Softness.SetWindowPos(rctSetting);
		m_ctrlSet_Softness2.SetWindowPos(rctSetting2);
	}
}
