// Dlg_CtrlCamera.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Dlg_CtrlCamera.h"
#include "afxdialogex.h"


// CDlg_CtrlCamera 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_CtrlCamera, CDialogEx)

CDlg_CtrlCamera::CDlg_CtrlCamera(CWnd* pParent /*=NULL*/)
	: CMNVDialogEx(CDlg_CtrlCamera::IDD, pParent)
{
	m_pAlgorithm = NULL;
}

CDlg_CtrlCamera::~CDlg_CtrlCamera()
{
}

void CDlg_CtrlCamera::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CAM_LabelChannel, m_ctrlLabel_Channel);
	DDX_Control(pDX, IDC_CAM_SelectChannel, m_ctrlSelect_Channel);
	DDX_Control(pDX, IDC_CAM_LabelExposure, m_ctrlLabel_Exposure);
	DDX_Control(pDX, IDC_CAM_InputExposure, m_ctrlSelect_Exposure);
	DDX_Control(pDX, IDC_CAM_LabelContrast, m_ctrlLabel_Contrast);
	DDX_Control(pDX, IDC_CAM_InputContast, m_ctrlSelect_Contrast);
	DDX_Control(pDX, IDC_CAM_LabelBrightness, m_ctrlLabel_Brightness);
	DDX_Control(pDX, IDC_CAM_InputBrightness, m_ctrlSelect_Brightness);
	DDX_Control(pDX, IDC_CAM_Setting, m_ctrlButton_Accept);
	DDX_Control(pDX, IDC_CAM_Cancel, m_ctrlButton_Cancel);
	DDX_Control(pDX, IDC_CAM_Live, m_ctrlButton_Live);
	DDX_Control(pDX, IDC_CAM_Capture, m_ctrlButton_Capture);
}


BEGIN_MESSAGE_MAP(CDlg_CtrlCamera, CDialogEx)
	ON_WM_WINDOWPOSCHANGED()
	ON_BN_CLICKED(IDC_CAM_Cancel, &CDlg_CtrlCamera::OnBnClickedCamCancel)
	ON_BN_CLICKED(IDC_CAM_Setting, &CDlg_CtrlCamera::OnBnClickedCamSetting)
	ON_BN_CLICKED(IDC_CAM_InputExposure, &CDlg_CtrlCamera::OnBnClickedCamInputexposure)
	ON_BN_CLICKED(IDC_CAM_InputContast, &CDlg_CtrlCamera::OnBnClickedCamInputcontast)
	ON_BN_CLICKED(IDC_CAM_InputBrightness, &CDlg_CtrlCamera::OnBnClickedCamInputbrightness)
	ON_BN_CLICKED(IDC_CAM_Live, &CDlg_CtrlCamera::OnBnClickedCamLive)
	ON_BN_CLICKED(IDC_CAM_Capture, &CDlg_CtrlCamera::OnBnClickedCamCapture)
	ON_BN_CLICKED(IDC_CAM_SelectChannel, &CDlg_CtrlCamera::OnBnClickedCamSelectchannel)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// CDlg_CtrlCamera 메시지 처리기입니다.


BOOL CDlg_CtrlCamera::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlg_CtrlCamera::OnWindowPosChanged(WINDOWPOS* lpwndpos)
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

	int nWidthX2 = rect.Width();
	int nWidth = (nWidthX2 - nMargin) / 2;

	int nHeight = (rect.Height()+ nMargin) / 2 - nMargin;

	int nTop[2];
	nTop[0] = rect.top;
	nTop[1] = nTop[0] + nHeight + nMargin;
	//nTop[2] = nTop[1] + nHeight + nMargin;
	//nTop[3] = nTop[2] + nHeight + nMargin;
	//nTop[4] = nTop[3] + nHeight + nMargin;
	//nTop[5] = nTop[4] + nHeight + nMargin;

	int nLeft[2];
	nLeft[0] = rect.left;
	nLeft[1] = nLeft[0] + nWidth + nMargin;

	m_ctrlLabel_Channel.SetWindowPos(nLeft[0], nTop[0], nWidth, nHeight);
	m_ctrlSelect_Channel.SetWindowPos(nLeft[1], nTop[0], nWidth, nHeight);

	//m_ctrlLabel_Exposure.SetWindowPos(nLeft[0], nTop[1], nWidth, nHeight);
	//m_ctrlSelect_Exposure.SetWindowPos(nLeft[1], nTop[1], nWidth, nHeight);
	//m_ctrlLabel_Contrast.SetWindowPos(nLeft[0], nTop[2], nWidth, nHeight);
	//m_ctrlSelect_Contrast.SetWindowPos(nLeft[1], nTop[2], nWidth, nHeight);
	//m_ctrlLabel_Brightness.SetWindowPos(nLeft[0], nTop[3], nWidth, nHeight);
	//m_ctrlSelect_Brightness.SetWindowPos(nLeft[1], nTop[3], nWidth, nHeight);
	//m_ctrlButton_Accept.SetWindowPos(nLeft[0], nTop[4], nWidth, nHeight);
	//m_ctrlButton_Cancel.SetWindowPos(nLeft[1], nTop[4], nWidth, nHeight);
	m_ctrlLabel_Exposure.ShowWindow(SW_HIDE);
	m_ctrlSelect_Exposure.ShowWindow(SW_HIDE);
	m_ctrlLabel_Contrast.ShowWindow(SW_HIDE);
	m_ctrlSelect_Contrast.ShowWindow(SW_HIDE);
	m_ctrlLabel_Brightness.ShowWindow(SW_HIDE);
	m_ctrlSelect_Brightness.ShowWindow(SW_HIDE);
	m_ctrlButton_Accept.ShowWindow(SW_HIDE);
	m_ctrlButton_Cancel.ShowWindow(SW_HIDE);

	SetWindowPos(IDC_CAM_Live, nLeft[0], nTop[1], nWidth, nHeight);
	SetWindowPos(IDC_CAM_Capture, nLeft[1], nTop[1], nWidth, nHeight);
}



void CDlg_CtrlCamera::OnBnClickedCamSelectchannel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nValue = 0;
	CDlg_PADNumeric dlg(PAD_MDInteger);
	if(dlg.DoModal() == IDOK) {
		m_nChannel = (int)dlg.GetValue();
		m_pAlgorithm->Cmd_SelectChannel(m_nChannel);
		OnReflash();
	}
}


void CDlg_CtrlCamera::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CMNVDialogEx::OnShowWindow(bShow, nStatus);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	m_ctrlButton_Live.SetItemCheck(false);
	m_ctrlButton_Capture.SetItemCheck(false);
}
