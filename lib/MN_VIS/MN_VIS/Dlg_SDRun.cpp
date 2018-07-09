// Dlg_SDRun.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MN_VIS.h"
#include "Dlg_SDRun.h"
#include "afxdialogex.h"


// CDlg_SDRun 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_SDRun, CDialogEx)

CDlg_SDRun::CDlg_SDRun(CWnd* pParent /*=NULL*/)
	: CMNVDialogEx(CDlg_SDRun::IDD, pParent)
{

}

CDlg_SDRun::~CDlg_SDRun()
{
}

void CDlg_SDRun::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RUN_SelectModel, m_ctrlSelectModel);
	DDX_Control(pDX, IDC_RUN_SelectItem, m_ctrlSelectItem);
	DDX_Control(pDX, IDC_RUN_Result1, m_ctrlResult[0]);
	DDX_Control(pDX, IDC_RUN_Result2, m_ctrlResult[1]);
	DDX_Control(pDX, IDC_RUN_Result3, m_ctrlResult[2]);
	DDX_Control(pDX, IDC_RUN_Result4, m_ctrlResult[3]);
}


BEGIN_MESSAGE_MAP(CDlg_SDRun, CDialogEx)
	ON_WM_WINDOWPOSCHANGED()
	ON_BN_CLICKED(IDC_SDR_InitBtn, &CDlg_SDRun::OnBnClickedSdrInitbtn)
	ON_BN_CLICKED(IDC_RUN_Algorithm, &CDlg_SDRun::OnBnClickedRunAlgorithm)
	ON_BN_CLICKED(IDC_RUN_Result1, &CDlg_SDRun::OnBnClickedRunResult1)
	ON_BN_CLICKED(IDC_RUN_Result2, &CDlg_SDRun::OnBnClickedRunResult2)
	ON_BN_CLICKED(IDC_RUN_Result3, &CDlg_SDRun::OnBnClickedRunResult3)
	ON_BN_CLICKED(IDC_RUN_Result4, &CDlg_SDRun::OnBnClickedRunResult4)
END_MESSAGE_MAP()


// CDlg_SDRun 메시지 처리기입니다.


BOOL CDlg_SDRun::OnInitDialog()
{
	CMNVDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlg_SDRun::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CMNVDialogEx::OnWindowPosChanged(lpwndpos);
	if (lpwndpos->flags & SWP_NOSIZE) return;

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CRect rect;
	GetClientRect(&rect);
	int nMargin = 2;

	rect.top += nMargin;
	rect.bottom -= nMargin;
	rect.left += nMargin;
	rect.right -= nMargin;

	CRect rctModel[2];
	{
		int nHeight = 50;
		int nWidth = (rect.Width() - nMargin) / 2;

		rctModel[0].SetRect(rect.left, rect.top, rect.left + nWidth, rect.top + nHeight);
		rctModel[1].SetRect(rect.right - nWidth, rect.top, rect.right, rect.top + nHeight);

		m_ctrlSelectModel.SetWindowPos(rctModel[0]);
		m_ctrlSelectItem.SetWindowPos(rctModel[1]);
	}

	//int nItem = 30;
	int nWidth = (rect.Width() - nMargin) / 2;
	int nHeight = 50;
	int nWidthX2 = nWidth * 2 + nMargin;

	int nLeft[2];
	nLeft[0] = rect.left + nMargin;
	nLeft[1] = nLeft[0] + nWidth;
	nWidth -= nMargin;

	int nTop[9];
	nTop[0] = rect.top + nMargin;
	nTop[1] = nTop[0] + nHeight;
	nTop[2] = nTop[1] + nHeight;
	nTop[3] = nTop[2] + nHeight;
	nTop[4] = nTop[3] + nHeight;
	nTop[5] = nTop[4] + nHeight;
	nTop[6] = nTop[5] + nHeight;
	nTop[7] = nTop[6] + nHeight;
	nTop[8] = nTop[7] + nHeight;
	nHeight -= nMargin;

	GetDlgItem(IDC_RUN_Algorithm)->SetWindowPos(NULL, nLeft[0], nTop[1], nWidthX2, nHeight, SWP_NOZORDER);

	GetDlgItem(IDC_RUN_AlgState)->SetWindowPos(NULL, nLeft[0], nTop[2], nWidthX2, nHeight, SWP_NOZORDER);
	
	GetDlgItem(IDC_RUN_VisionLabel)->SetWindowPos(NULL, nLeft[0], nTop[3], nWidth, nHeight, SWP_NOZORDER);
	GetDlgItem(IDC_RUN_VisionSignal)->SetWindowPos(NULL, nLeft[1], nTop[3], nWidth, nHeight, SWP_NOZORDER);

	GetDlgItem(IDC_RUN_PLCLabel)->SetWindowPos(NULL, nLeft[0], nTop[4], nWidth, nHeight, SWP_NOZORDER);
	GetDlgItem(IDC_RUN_PLCSignal)->SetWindowPos(NULL, nLeft[1], nTop[4], nWidth, nHeight, SWP_NOZORDER);

	m_ctrlResult[0].SetWindowPos(nLeft[0], nTop[5], nWidthX2, nHeight);
	m_ctrlResult[1].SetWindowPos(nLeft[0], nTop[6], nWidthX2, nHeight);
	m_ctrlResult[2].SetWindowPos(nLeft[0], nTop[7], nWidthX2, nHeight);
	m_ctrlResult[3].SetWindowPos(nLeft[0], nTop[8], nWidthX2, nHeight);

	GetDlgItem(IDC_SDR_History)->SetWindowPos(NULL, nLeft[0], nTop[8], rect.Width() - nMargin * 2, rect.Height() - nTop[4] - nMargin * 2, SWP_NOZORDER);
}


void CDlg_SDRun::OnBnClickedSdrInitbtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//m_pParent->OnCmd_Command(CMD_SYS_Layout, 0, 0);
}
