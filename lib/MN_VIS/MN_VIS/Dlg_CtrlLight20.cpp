// Dlg_CtrlLight20.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MN_VIS.h"
#include "Dlg_CtrlLight20.h"
#include "afxdialogex.h"

// CDlg_CtrlLight20 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_CtrlLight20, CDialogEx)

CDlg_CtrlLight20::CDlg_CtrlLight20(CWnd* pParent /*=NULL*/)
	: CMNVDialogEx(CDlg_CtrlLight20::IDD, pParent)
{
	m_IDChannel[0] = IDC_LIGHT_CH1;
	m_IDChannel[1] = IDC_LIGHT_CH2;
	m_IDChannel[2] = IDC_LIGHT_CH3;
	m_IDChannel[3] = IDC_LIGHT_CH4;
	m_IDChannel[4] = IDC_LIGHT_CH5;
	m_IDChannel[5] = IDC_LIGHT_CH6;
	m_IDChannel[6] = IDC_LIGHT_CH7;
	m_IDChannel[7] = IDC_LIGHT_CH8;
	m_IDChannel[8] = IDC_LIGHT_CH9;
	m_IDChannel[9] = IDC_LIGHT_CH10;
	m_IDChannel[10] = IDC_LIGHT_CH11;
	m_IDChannel[11] = IDC_LIGHT_CH12;
	m_IDChannel[12] = IDC_LIGHT_CH13;
	m_IDChannel[13] = IDC_LIGHT_CH14;
	m_IDChannel[14] = IDC_LIGHT_CH15;
	m_IDChannel[15] = IDC_LIGHT_CH16;
	m_IDChannel[16] = IDC_LIGHT_CH17;
	m_IDChannel[17] = IDC_LIGHT_CH18;
	m_IDChannel[18] = IDC_LIGHT_CH19;
	m_IDChannel[19] = IDC_LIGHT_CH20;
}

CDlg_CtrlLight20::~CDlg_CtrlLight20()
{
}

void CDlg_CtrlLight20::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIGHT_CH1, m_ctrlBtn_Channel[0]);
	DDX_Control(pDX, IDC_LIGHT_CH2, m_ctrlBtn_Channel[1]);
	DDX_Control(pDX, IDC_LIGHT_CH3, m_ctrlBtn_Channel[2]);
	DDX_Control(pDX, IDC_LIGHT_CH4, m_ctrlBtn_Channel[3]);
	DDX_Control(pDX, IDC_LIGHT_CH5, m_ctrlBtn_Channel[4]);
	DDX_Control(pDX, IDC_LIGHT_CH6, m_ctrlBtn_Channel[5]);
	DDX_Control(pDX, IDC_LIGHT_CH7, m_ctrlBtn_Channel[6]);
	DDX_Control(pDX, IDC_LIGHT_CH8, m_ctrlBtn_Channel[7]);
	DDX_Control(pDX, IDC_LIGHT_CH9, m_ctrlBtn_Channel[8]);
	DDX_Control(pDX, IDC_LIGHT_CH10, m_ctrlBtn_Channel[9]);
	DDX_Control(pDX, IDC_LIGHT_CH11, m_ctrlBtn_Channel[10]);
	DDX_Control(pDX, IDC_LIGHT_CH12, m_ctrlBtn_Channel[11]);
	DDX_Control(pDX, IDC_LIGHT_CH13, m_ctrlBtn_Channel[12]);
	DDX_Control(pDX, IDC_LIGHT_CH14, m_ctrlBtn_Channel[13]);
	DDX_Control(pDX, IDC_LIGHT_CH15, m_ctrlBtn_Channel[14]);
	DDX_Control(pDX, IDC_LIGHT_CH16, m_ctrlBtn_Channel[15]);
	DDX_Control(pDX, IDC_LIGHT_CH17, m_ctrlBtn_Channel[16]);
	DDX_Control(pDX, IDC_LIGHT_CH18, m_ctrlBtn_Channel[17]);
	DDX_Control(pDX, IDC_LIGHT_CH19, m_ctrlBtn_Channel[18]);
	DDX_Control(pDX, IDC_LIGHT_CH20, m_ctrlBtn_Channel[19]);
}


BEGIN_MESSAGE_MAP(CDlg_CtrlLight20, CDialogEx)
	ON_BN_CLICKED(IDC_LIGHT_BTNADD, &CDlg_CtrlLight20::OnBnClickedLightBtnadd)
	ON_BN_CLICKED(IDC_LIGHT_BTNSET, &CDlg_CtrlLight20::OnBnClickedLightBtnset)
	ON_WM_WINDOWPOSCHANGED()
	ON_BN_CLICKED(IDC_LIGHT_ALL, &CDlg_CtrlLight20::OnBnClickedLightAll)
	ON_BN_CLICKED(IDC_LIGHT_DF, &CDlg_CtrlLight20::OnBnClickedLightDf)
	ON_BN_CLICKED(IDC_LIGHT_LA, &CDlg_CtrlLight20::OnBnClickedLightLa)
	ON_BN_CLICKED(IDC_LIGHT_MA, &CDlg_CtrlLight20::OnBnClickedLightMa)
	ON_BN_CLICKED(IDC_LIGHT_HA, &CDlg_CtrlLight20::OnBnClickedLightHa)
	ON_BN_CLICKED(IDC_LIGHT_FR, &CDlg_CtrlLight20::OnBnClickedLightFr)
	ON_BN_CLICKED(IDC_LIGHT_12H, &CDlg_CtrlLight20::OnBnClickedLight12h)
	ON_BN_CLICKED(IDC_LIGHT_3H, &CDlg_CtrlLight20::OnBnClickedLight3h)
	ON_BN_CLICKED(IDC_LIGHT_6H, &CDlg_CtrlLight20::OnBnClickedLight6h)
	ON_BN_CLICKED(IDC_LIGHT_9H, &CDlg_CtrlLight20::OnBnClickedLight9h)
	ON_BN_CLICKED(IDC_LIGHT_BTNSUB, &CDlg_CtrlLight20::OnBnClickedLightBtnsub)
END_MESSAGE_MAP()


// CDlg_CtrlLight20 메시지 처리기입니다.


void CDlg_CtrlLight20::OnBnClickedLightBtnadd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nValue = GetItemData(IDC_LIGHT_LEVEL, 0);
	for(int nIndex = 0; nIndex < 20; ++nIndex) {
		if (GetItemCheck(m_IDChannel[nIndex])) {
			m_pParent->OnCmd_Command(CMD_Light_AddValue, nIndex, nValue);
		}
	}
	m_pParent->OnCmd_Command(CMD_Light_Update, 0, 0);

	//m_pDeviceLFine->LoadSetting(m_strFilePath);
	//m_pDeviceLFine->SendValue();
	//Reflash();
}


void CDlg_CtrlLight20::OnBnClickedLightBtnset()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nValue = GetItemData(IDC_LIGHT_LEVEL, 0);
	nValue = (nValue > 1000) ? 1000 : nValue;
	for(int nIndex = 0; nIndex < 20; ++nIndex) {
		if (GetItemCheck(m_IDChannel[nIndex])) {
			m_pParent->OnCmd_Command(CMD_Light_SetValue, nIndex, nValue);
		}
		//else {
		//	OnCmd_Command(CMD_Light_SubValue, nIndex, 0);
		//}
	}
	m_pParent->OnCmd_Command(CMD_Light_Update, 0, 0);
	//m_pDeviceLFine->LoadSetting(m_strFilePath);
	//m_pDeviceLFine->SendValue();
	//Reflash();
}
void CDlg_CtrlLight20::OnBnClickedLightBtnsub()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nValue = GetItemData(IDC_LIGHT_LEVEL, 0);
	for(int nIndex = 0; nIndex < 20; ++nIndex) {
		if (GetItemCheck(m_IDChannel[nIndex])) {
			m_pParent->OnCmd_Command(CMD_Light_SubValue, nIndex, nValue);
		}
	}
	m_pParent->OnCmd_Command(CMD_Light_Update, 0, 0);
	//m_pDeviceLFine->LoadSetting(m_strFilePath);
	//m_pDeviceLFine->SendValue();
	//Reflash();
}


BOOL CDlg_CtrlLight20::OnInitDialog()
{
	CMNVDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	//{
	//	wchar_t Buf[1024];
	//	GetCurrentDirectory(1024, Buf);
	//	m_strFilePath.Format(_T("d:\\Setting\\LightControl.ini"), Buf);
	//	CMNVFile::CreatePath(m_strFilePath);
	//}

	//m_pDeviceLFine->LoadSetting(m_strFilePath);
	//m_pDeviceLFine->InitSetting();
	//m_pDeviceLFine->SaveSetting(m_strFilePath);
	//Reflash();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDlg_CtrlLight20::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CMNVDialogEx::OnWindowPosChanged(lpwndpos);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	int nTop[7];
	int nLeft[5];
	int nWidth[2];
	int nHeight[2];
	int nMargin = 5;

	CRect rect;
	GetClientRect(&rect);

	nWidth[0] = (rect.Width() - nMargin * 4) / 5;
	nHeight[0] = (rect.Height() - nMargin * 6) / 7;

	nTop[0] = rect.top;
	nTop[1] = nTop[0] + nHeight[0] + nMargin;
	nTop[2] = nTop[1] + nHeight[0] + nMargin;
	nTop[3] = nTop[2] + nHeight[0] + nMargin;
	nTop[4] = nTop[3] + nHeight[0] + nMargin;
	nTop[5] = nTop[4] + nHeight[0] + nMargin;
	nTop[6] = nTop[5] + nHeight[0] + nMargin;

	nLeft[0] = rect.left;
	nLeft[1] = nLeft[0] + nWidth[0] + nMargin;
	nLeft[2] = nLeft[1] + nWidth[0] + nMargin;
	nLeft[3] = nLeft[2] + nWidth[0] + nMargin;
	nLeft[4] = nLeft[3] + nWidth[0] + nMargin;

	SetWindowPos(IDC_LIGHT_ALL, nLeft[0], nTop[0], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_12H, nLeft[1], nTop[0], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_3H,  nLeft[2], nTop[0], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_6H,  nLeft[3], nTop[0], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_9H,  nLeft[4], nTop[0], nWidth[0], nHeight[0]);

	SetWindowPos(IDC_LIGHT_DF,  nLeft[0], nTop[1], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH1, nLeft[1], nTop[1], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH2, nLeft[2], nTop[1], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH3, nLeft[3], nTop[1], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH4, nLeft[4], nTop[1], nWidth[0], nHeight[0]);

	SetWindowPos(IDC_LIGHT_LA,  nLeft[0], nTop[2], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH5, nLeft[1], nTop[2], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH6, nLeft[2], nTop[2], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH7, nLeft[3], nTop[2], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH8, nLeft[4], nTop[2], nWidth[0], nHeight[0]);

	SetWindowPos(IDC_LIGHT_MA,   nLeft[0], nTop[3], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH9,  nLeft[1], nTop[3], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH10, nLeft[2], nTop[3], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH11, nLeft[3], nTop[3], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH12, nLeft[4], nTop[3], nWidth[0], nHeight[0]);

	SetWindowPos(IDC_LIGHT_HA,   nLeft[0], nTop[4], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH13, nLeft[1], nTop[4], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH14, nLeft[2], nTop[4], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH15, nLeft[3], nTop[4], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH16, nLeft[4], nTop[4], nWidth[0], nHeight[0]);

	SetWindowPos(IDC_LIGHT_FR,   nLeft[0], nTop[5], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH17, nLeft[1], nTop[5], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH18, nLeft[2], nTop[5], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH19, nLeft[3], nTop[5], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH20, nLeft[4], nTop[5], nWidth[0], nHeight[0]);

	SetWindowPos(IDC_LIGHT_LEVEL,  nLeft[1], nTop[6], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_BTNADD, nLeft[2], nTop[6], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_BTNSUB, nLeft[3], nTop[6], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_BTNSET, nLeft[4], nTop[6], nWidth[0], nHeight[0]);
}


void CDlg_CtrlLight20::OnBnClickedLightAll()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	bool isSelect = GetItemCheck(IDC_LIGHT_ALL);
	for(int nIndex = 0; nIndex < 20; ++nIndex) {
		SetItemCheck(m_IDChannel[nIndex], isSelect);
	}
}


void CDlg_CtrlLight20::OnBnClickedLightDf()
{
	bool isSelect = GetItemCheck(IDC_LIGHT_DF);
	for(int nIndex = 0; nIndex < 4; ++nIndex) {
		SetItemCheck(m_IDChannel[nIndex], isSelect);
	}
}


void CDlg_CtrlLight20::OnBnClickedLightLa()
{
	bool isSelect = GetItemCheck(IDC_LIGHT_LA);
	for(int nIndex = 4; nIndex < 8; ++nIndex) {
		SetItemCheck(m_IDChannel[nIndex], isSelect);
	}
}


void CDlg_CtrlLight20::OnBnClickedLightMa()
{
	bool isSelect = GetItemCheck(IDC_LIGHT_MA);
	for(int nIndex = 8; nIndex < 12; ++nIndex) {
		SetItemCheck(m_IDChannel[nIndex], isSelect);
	}
}


void CDlg_CtrlLight20::OnBnClickedLightHa()
{
	bool isSelect = GetItemCheck(IDC_LIGHT_HA);
	for(int nIndex = 12; nIndex < 16; ++nIndex) {
		SetItemCheck(m_IDChannel[nIndex], isSelect);
	}
}


void CDlg_CtrlLight20::OnBnClickedLightFr()
{
	bool isSelect = GetItemCheck(IDC_LIGHT_FR);
	for(int nIndex = 16; nIndex < 20; ++nIndex) {
		SetItemCheck(m_IDChannel[nIndex], isSelect);
	}
}


void CDlg_CtrlLight20::OnBnClickedLight12h()
{
	bool isSelect = GetItemCheck(IDC_LIGHT_12H);
	for(int nIndex = 0; nIndex < 20; nIndex += 4) {
		SetItemCheck(m_IDChannel[nIndex], isSelect);
	}
}


void CDlg_CtrlLight20::OnBnClickedLight3h()
{
	bool isSelect = GetItemCheck(IDC_LIGHT_3H);
	for(int nIndex = 1; nIndex < 20; nIndex += 4) {
		SetItemCheck(m_IDChannel[nIndex], isSelect);
	}
}


void CDlg_CtrlLight20::OnBnClickedLight6h()
{
	bool isSelect = GetItemCheck(IDC_LIGHT_6H);
	for(int nIndex = 2; nIndex < 20; nIndex += 4) {
		SetItemCheck(m_IDChannel[nIndex], isSelect);
	}
}


void CDlg_CtrlLight20::OnBnClickedLight9h()
{
	bool isSelect = GetItemCheck(IDC_LIGHT_9H);
	for(int nIndex = 3; nIndex < 20; nIndex += 4) {
		SetItemCheck(m_IDChannel[nIndex], isSelect);
	}
}


