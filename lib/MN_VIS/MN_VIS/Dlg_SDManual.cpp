// Dlg_SDManual.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MN_VIS.h"
#include "Dlg_SDManual.h"
#include "afxdialogex.h"


// CDlg_SDManual 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_SDManual, CDialogEx)

CDlg_SDManual::CDlg_SDManual(CWnd* pParent /*=NULL*/)
	: CMNVDialogEx(CDlg_SDManual::IDD, pParent)
{

}

CDlg_SDManual::~CDlg_SDManual()
{
}

void CDlg_SDManual::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_SDManual, CDialogEx)
	ON_WM_WINDOWPOSCHANGED()
	ON_BN_CLICKED(IDC_Manual_VisionWait, &CDlg_SDManual::OnBnClickedManualVisionwait)
	ON_BN_CLICKED(IDC_Manual_VisionReady, &CDlg_SDManual::OnBnClickedManualVisionready)
	ON_BN_CLICKED(IDC_Manual_VisionInspect, &CDlg_SDManual::OnBnClickedManualVisioninspect)
	ON_BN_CLICKED(IDC_Manual_VisionResult, &CDlg_SDManual::OnBnClickedManualVisionresult)
	ON_BN_CLICKED(IDC_Manual_VisionSelect, &CDlg_SDManual::OnBnClickedManualVisionselect)
	ON_BN_CLICKED(IDC_Manual_VisionSetting, &CDlg_SDManual::OnBnClickedManualVisionsetting)
	ON_BN_CLICKED(IDC_Manual_VisionModel, &CDlg_SDManual::OnBnClickedManualVisionmodel)
	ON_BN_CLICKED(IDC_Manual_VisionItem, &CDlg_SDManual::OnBnClickedManualVisionitem)
	ON_BN_CLICKED(IDC_Manual_VisionSpeed, &CDlg_SDManual::OnBnClickedManualVisionspeed)
	ON_BN_CLICKED(IDC_Manual_VisionWorking, &CDlg_SDManual::OnBnClickedManualVisionworking)
	ON_BN_CLICKED(IDC_Manual_VisionOK, &CDlg_SDManual::OnBnClickedManualVisionok)
	ON_BN_CLICKED(IDC_Manual_VisionNG, &CDlg_SDManual::OnBnClickedManualVisionng)
	ON_BN_CLICKED(IDC_Manual_VisionAlarm, &CDlg_SDManual::OnBnClickedManualVisionalarm)
	ON_BN_CLICKED(IDC_Manual_PLCPrepare, &CDlg_SDManual::OnBnClickedManualPlcprepare)
	ON_BN_CLICKED(IDC_Manual_PLCTrigger, &CDlg_SDManual::OnBnClickedManualPlctrigger)
	ON_BN_CLICKED(IDC_Manual_PLCFinish, &CDlg_SDManual::OnBnClickedManualPlcfinish)
	ON_BN_CLICKED(IDC_Manual_PLCEnd, &CDlg_SDManual::OnBnClickedManualPlcend)
	ON_BN_CLICKED(IDC_Manual_PLCSelectOK, &CDlg_SDManual::OnBnClickedManualPlcselectok)
	ON_BN_CLICKED(IDC_Manual_PLCSelectNG, &CDlg_SDManual::OnBnClickedManualPlcselectng)
	ON_BN_CLICKED(IDC_Manual_PLCSettingOK, &CDlg_SDManual::OnBnClickedManualPlcsettingok)
	ON_BN_CLICKED(IDC_Manual_PLCSettingNG, &CDlg_SDManual::OnBnClickedManualPlcsettingng)
	ON_BN_CLICKED(IDC_Manual_PLCModel, &CDlg_SDManual::OnBnClickedManualPlcmodel)
	ON_BN_CLICKED(IDC_Manual_PLCItem, &CDlg_SDManual::OnBnClickedManualPlcitem)
	ON_BN_CLICKED(IDC_Manual_PLCSpeed, &CDlg_SDManual::OnBnClickedManualPlcspeed)
	ON_BN_CLICKED(IDC_Manual_PLCWorking, &CDlg_SDManual::OnBnClickedManualPlcworking)
	ON_BN_CLICKED(IDC_Manual_Algorithm, &CDlg_SDManual::OnBnClickedManualAlgorithm)
	ON_BN_CLICKED(IDC_Manual_PLC, &CDlg_SDManual::OnBnClickedManualPlc)
	ON_BN_CLICKED(IDC_Manual_VisionGrab, &CDlg_SDManual::OnBnClickedManualVisiongrab)
END_MESSAGE_MAP()


// CDlg_SDManual 메시지 처리기입니다.


BOOL CDlg_SDManual::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlg_SDManual::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CRect rect;
	GetClientRect(&rect);
	int nMargin = 5;

	rect.left += nMargin;
	rect.top += nMargin;
	rect.right -= nMargin;
	rect.bottom -= nMargin;

	int nWidth = (rect.Width() + nMargin) / 4;
	int nHeight = (rect.Height() + nMargin) / 18;
	nHeight -= nMargin;

	int nLeft[4];
	nLeft[0] = rect.left;
	nLeft[1] = nLeft[0] + nWidth;
	nLeft[2] = nLeft[1] + nWidth;
	nLeft[3] = nLeft[2] + nWidth;
	nWidth -= nMargin;
	int nWidthx2 = nWidth * 2 + nMargin;
	int nWidthx4 = nWidthx2 * 2 + nMargin;


	int nTop[18];
	nTop[0] = rect.top;
	nTop[1] = nTop[0] + nHeight;
	nTop[2] = nTop[1] + nHeight;
	nTop[3] = nTop[2] + nHeight;
	nTop[4] = nTop[3] + nHeight;
	nTop[5] = nTop[4] + nHeight;
	nTop[6] = nTop[5] + nHeight;
	nTop[7] = nTop[6] + nHeight;
	nTop[8] = nTop[7] + nHeight;
	nTop[9] = nTop[8] + nHeight;
	nTop[10] = nTop[9] + nHeight;
	nTop[11] = nTop[10] + nHeight;
	nTop[12] = nTop[11] + nHeight;
	nTop[13] = nTop[12] + nHeight;
	nTop[14] = nTop[13] + nHeight;
	nTop[15] = nTop[14] + nHeight;
	nTop[16] = nTop[15] + nHeight;
	nTop[17] = nTop[16] + nHeight;
	nHeight -= nMargin;

	SetWindowPos(IDC_STATIC_Algorithm, nLeft[0], nTop[0], nWidthx2, nHeight);
	SetWindowPos(IDC_Manual_Algorithm, nLeft[2], nTop[0], nWidth, nHeight);
	SetWindowPos(IDC_Manual_PLC, nLeft[3], nTop[0], nWidth, nHeight);

	SetWindowPos(IDC_STATIC_PLC, nLeft[0], nTop[1], nWidthx4, nHeight);

	SetWindowPos(IDC_Manual_PLCPrepare, nLeft[0], nTop[2], nWidth, nHeight);
	SetWindowPos(IDC_Manual_PLCTrigger, nLeft[1], nTop[2], nWidth, nHeight);
	SetWindowPos(IDC_Manual_PLCFinish, nLeft[2], nTop[2], nWidth, nHeight);
	SetWindowPos(IDC_Manual_PLCEnd, nLeft[3], nTop[2], nWidth, nHeight);

	SetWindowPos(IDC_Manual_PLCSelectOK, nLeft[0], nTop[3], nWidth, nHeight);
	SetWindowPos(IDC_Manual_PLCSelectNG, nLeft[1], nTop[3], nWidth, nHeight);
	SetWindowPos(IDC_Manual_PLCSettingOK, nLeft[2], nTop[3], nWidth, nHeight);
	SetWindowPos(IDC_Manual_PLCSettingNG, nLeft[3], nTop[3], nWidth, nHeight);

	SetWindowPos(IDC_STATIC_PLCModel, nLeft[0], nTop[4], nWidthx2, nHeight);
	SetWindowPos(IDC_Manual_PLCModel, nLeft[2], nTop[4], nWidthx2, nHeight);

	SetWindowPos(IDC_STATIC_PLCItem, nLeft[0], nTop[5], nWidthx2, nHeight);
	SetWindowPos(IDC_Manual_PLCItem, nLeft[2], nTop[5], nWidthx2, nHeight);

	SetWindowPos(IDC_STATIC_PLCSpeed, nLeft[0], nTop[6], nWidthx2, nHeight);
	SetWindowPos(IDC_Manual_PLCSpeed, nLeft[2], nTop[6], nWidthx2, nHeight);

	SetWindowPos(IDC_STATIC_PLCWorking, nLeft[0], nTop[7], nWidthx2, nHeight);
	SetWindowPos(IDC_Manual_PLCWorking, nLeft[2], nTop[7], nWidthx2, nHeight);

	SetWindowPos(IDC_STATIC_Vision, nLeft[0], nTop[8], nWidthx4, nHeight);

	SetWindowPos(IDC_Manual_VisionWait, nLeft[0], nTop[9], nWidth, nHeight);
	SetWindowPos(IDC_Manual_VisionReady, nLeft[1], nTop[9], nWidth, nHeight);
	SetWindowPos(IDC_Manual_VisionGrab, nLeft[2], nTop[9], nWidth, nHeight);
	SetWindowPos(IDC_Manual_VisionInspect, nLeft[3], nTop[9], nWidth, nHeight);

	SetWindowPos(IDC_Manual_VisionResult, nLeft[0], nTop[10], nWidth, nHeight);
	SetWindowPos(IDC_Manual_VisionOK, nLeft[1], nTop[10], nWidth, nHeight);
	SetWindowPos(IDC_Manual_VisionNG, nLeft[2], nTop[10], nWidth, nHeight);
	SetWindowPos(IDC_Manual_VisionAlarm, nLeft[3], nTop[10], nWidth, nHeight);

	SetWindowPos(IDC_Manual_VisionSelect, nLeft[0], nTop[11], nWidth, nHeight);
	SetWindowPos(IDC_Manual_VisionSetting, nLeft[1], nTop[11], nWidth, nHeight);

	SetWindowPos(IDC_STATIC_VisionModel, nLeft[0], nTop[12], nWidthx2, nHeight);
	SetWindowPos(IDC_Manual_VisionModel, nLeft[2], nTop[12], nWidthx2, nHeight);
	SetWindowPos(IDC_STATIC_VisionItem, nLeft[0], nTop[13], nWidthx2, nHeight);
	SetWindowPos(IDC_Manual_VisionItem, nLeft[2], nTop[13], nWidthx2, nHeight);
	SetWindowPos(IDC_STATIC_VisionSpeed, nLeft[0], nTop[14], nWidthx2, nHeight);
	SetWindowPos(IDC_Manual_VisionSpeed, nLeft[2], nTop[14], nWidthx2, nHeight);
	SetWindowPos(IDC_STATIC_VisionWorking, nLeft[0], nTop[15], nWidthx2, nHeight);
	SetWindowPos(IDC_Manual_VisionWorking, nLeft[2], nTop[15], nWidthx2, nHeight);
}
