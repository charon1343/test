// Dlg_SDVision.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MN_VIS.h"
#include "Dlg_SDVision.h"
#include "afxdialogex.h"


// CDlg_SDVision 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_SDVision, CDialogEx)

CDlg_SDVision::CDlg_SDVision(CWnd* pParent /*=NULL*/)
	: CMNVDialogEx(CDlg_SDVision::IDD, pParent)
{

}

CDlg_SDVision::~CDlg_SDVision()
{
}

void CDlg_SDVision::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_SDVision, CDialogEx)
	ON_WM_WINDOWPOSCHANGED()
	ON_BN_CLICKED(IDC_VISION_InputExposure, &CDlg_SDVision::OnBnClickedVisionInputexposure)
	ON_BN_CLICKED(IDC_VISION_InputContrast, &CDlg_SDVision::OnBnClickedVisionInputcontrast)
	ON_BN_CLICKED(IDC_VISION_InputBrightness, &CDlg_SDVision::OnBnClickedVisionInputbrightness)
	ON_BN_CLICKED(IDC_VISION_Live, &CDlg_SDVision::OnBnClickedVisionLive)
	ON_BN_CLICKED(IDC_VISION_Grab, &CDlg_SDVision::OnBnClickedVisionGrab)
	ON_BN_CLICKED(IDC_VISION_CrossLine, &CDlg_SDVision::OnBnClickedVisionCrossline)
	ON_BN_CLICKED(IDC_VISION_Accept, &CDlg_SDVision::OnBnClickedVisionAccept)
	ON_BN_CLICKED(IDC_VISION_Cancel, &CDlg_SDVision::OnBnClickedVisionCancel)
	ON_CBN_SELCHANGE(IDC_VISION_InputCamera, &CDlg_SDVision::OnCbnSelchangeVisionInputcamera)
	ON_BN_CLICKED(IDC_VISION_Load, &CDlg_SDVision::OnBnClickedVisionLoad)
	ON_BN_CLICKED(IDC_VISION_Save, &CDlg_SDVision::OnBnClickedVisionSave)
	ON_CBN_SELCHANGE(IDC_VISION_InputChannel, &CDlg_SDVision::OnCbnSelchangeVisionInputchannel)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlg_SDVision 메시지 처리기입니다.


BOOL CDlg_SDVision::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	//m_ctrlLight20.SetLightControl(&m_DeviceLFine);
	m_ctrlLight20.Create(m_ctrlLight20.IDD, this, this);
	m_ctrlLight20.ShowWindow(true);
	CreateThread();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlg_SDVision::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CRect rect;
	GetClientRect(&rect);

	int nHeight = 35; //rect.Height() / 5;

	int nMargin = 5;
	int nPadding = 5;
	rect.top += nMargin;
	rect.left += nMargin;
	rect.right -= nMargin;
	rect.bottom -= nMargin;

	int nPosY[7];
	nPosY[0] = rect.top;
	nPosY[1] = nPosY[0] + nHeight;
	nPosY[2] = nPosY[1] + nHeight;
	nPosY[3] = nPosY[2] + nHeight;
	nPosY[4] = nPosY[3] + nHeight;
	nPosY[5] = nPosY[4] + nHeight;
	nPosY[6] = nPosY[5] + nHeight;
	nHeight -= nPadding;

	int nWidth = rect.Width() / 3;
	int nPosX[3];
	nPosX[0] = rect.left;
	nPosX[1] = nPosX[0] + nWidth;
	nPosX[2] = nPosX[1] + nWidth;
	nWidth -= nPadding;
	GetDlgItem(IDC_VISION_Live)->SetWindowPos(NULL, nPosX[0], nPosY[0], nWidth, nHeight, NULL);
	GetDlgItem(IDC_VISION_Grab)->SetWindowPos(NULL, nPosX[1], nPosY[0], nWidth, nHeight, NULL);
	GetDlgItem(IDC_VISION_CrossLine)->SetWindowPos(NULL, nPosX[2], nPosY[0], nWidth, nHeight, NULL);

	GetDlgItem(IDC_VISION_Accept)->SetWindowPos(NULL, nPosX[1], nPosY[6], nWidth, nHeight, NULL);
	GetDlgItem(IDC_VISION_Cancel)->SetWindowPos(NULL, nPosX[2], nPosY[6], nWidth, nHeight, NULL);
	GetDlgItem(IDC_VISION_LightState)->SetWindowPos(NULL, nPosX[0], nPosY[6], nWidth, nHeight, NULL);

	nWidth = rect.Width() / 2;
	nPosX[0] = rect.left;
	nPosX[1] = nPosX[0] + nWidth;
	nWidth -= nPadding;

	GetDlgItem(IDC_VISION_LabelChannel)->SetWindowPos(NULL, nPosX[0], nPosY[1], nWidth, nHeight, NULL);
	GetDlgItem(IDC_VISION_LabelCamera)->SetWindowPos(NULL, nPosX[0], nPosY[2], nWidth, nHeight, NULL);
	GetDlgItem(IDC_VISION_LabelExposure)->SetWindowPos(NULL, nPosX[0], nPosY[3], nWidth, nHeight, NULL);
	GetDlgItem(IDC_VISION_LabelContrast)->SetWindowPos(NULL, nPosX[0], nPosY[4], nWidth, nHeight, NULL);
	GetDlgItem(IDC_VISION_LabelBrightness)->SetWindowPos(NULL, nPosX[0], nPosY[5], nWidth, nHeight, NULL);

	GetDlgItem(IDC_VISION_InputChannel)->SetWindowPos(NULL, nPosX[1], nPosY[1], nWidth, nHeight, NULL);
	GetDlgItem(IDC_VISION_InputCamera)->SetWindowPos(NULL, nPosX[1], nPosY[2], nWidth, nHeight, NULL);
	GetDlgItem(IDC_VISION_InputExposure)->SetWindowPos(NULL, nPosX[1], nPosY[3], nWidth, nHeight, NULL);
	GetDlgItem(IDC_VISION_InputContrast)->SetWindowPos(NULL, nPosX[1], nPosY[4], nWidth, nHeight, NULL);
	GetDlgItem(IDC_VISION_InputBrightness)->SetWindowPos(NULL, nPosX[1], nPosY[5], nWidth, nHeight, NULL);

	CRect rectCtrl = rect;
	rectCtrl.top = nPosY[6] + 10 + nHeight;
	rectCtrl.bottom = rectCtrl.top + 300;
	m_ctrlLight20.SetWindowPos(rectCtrl);
}
bool isCamSetting = false;
double dSleep;
afx_msg void CDlg_SDVision::OnBnClickedVisionAccept() {
	SetItemCheck(IDC_VISION_Accept, true, false);
	STCamSetting stSetting;

	//m_nVision[GetSelectIndex(IDC_VISION_InputChannel)] = GetSelectIndex(IDC_VISION_InputCamera);

	//m_pCamInfo[GetSelectIndex(IDC_VISION_InputCamera)].GetCamSetting(stSetting);

	//dSleep = stSetting.dExposure;

	stSetting.dExposure = GetItemData(IDC_VISION_InputExposure, 0.0);
	stSetting.dContrast = GetItemData(IDC_VISION_InputContrast, 0.0) / 100;
	stSetting.dBrightness = GetItemData(IDC_VISION_InputBrightness, 0.0) / 100;

	dSleep += stSetting.dExposure;
	//m_pCamInfo[GetSelectIndex(IDC_VISION_InputCamera)].SetCamSetting(stSetting);
	if (ISLive()) {
		SetItemCheck(IDC_VISION_Accept, false, true);
	}
	else {
		isCamSetting = true;
	}
}
afx_msg void CDlg_SDVision::OnBnClickedVisionCancel() {
	//STCamSetting stSetting;
	//m_pCamInfo[GetSelectIndex(IDC_VISION_InputCamera)].GetCamSetting(stSetting);

	//SetItemData(IDC_VISION_InputExposure, stSetting.dExposure);
	//SetItemData(IDC_VISION_InputContrast, stSetting.dContrast * 100);
	//SetItemData(IDC_VISION_InputBrightness, stSetting.dBrightness * 100);

	SetItemCheck(IDC_VISION_Cancel, false);
}

void CDlg_SDVision::Thread()
{
	while(1) {
		//SetItemData(IDC_VISION_LightState, m_DeviceLFine.m_isConnect ? _T("Connect") : _T("Error"));

		if (isCamSetting) {
			isCamSetting = false;
			dSleep = (dSleep * 2);
			if (dSleep < 300) {
				dSleep = 300;
			}
			Sleep((DWORD)dSleep);
			SetGrab(true);
			SetItemCheck(IDC_VISION_Accept, false, true);
		}
		Sleep(10);
	}
}


void CDlg_SDVision::OnDestroy()
{
	CMNVDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
