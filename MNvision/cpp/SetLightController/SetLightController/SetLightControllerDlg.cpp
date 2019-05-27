
// SetLightControllerDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "SetLightController.h"
#include "SetLightControllerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
//	virtual BOOL OnInitDialog();
//	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
//	afx_msg void OnSize(UINT nType, int cx, int cy);
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//	ON_WM_WINDOWPOSCHANGED()
//	ON_WM_SIZE()
END_MESSAGE_MAP()


// CSetLightControllerDlg 대화 상자




CSetLightControllerDlg::CSetLightControllerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSetLightControllerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSetLightControllerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSetLightControllerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_WINDOWPOSCHANGED()
END_MESSAGE_MAP()


// CSetLightControllerDlg 메시지 처리기

BOOL CSetLightControllerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_modelSet.Create(m_modelSet.IDD,this);
	m_controllerList.Create(m_controllerList.IDD,this);

	m_modelSet.ShowWindow(SW_SHOW);
	m_controllerList.ShowWindow(SW_SHOW);

	On_WindPos();
	On_InitTextTop();
	On_InitTextBottom();


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CSetLightControllerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CSetLightControllerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CSetLightControllerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSetLightControllerDlg::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if ((lpwndpos->flags & SWP_NOSIZE) == 0) { On_WindPos();}

}

void CSetLightControllerDlg::On_WindPos(void)
{
	CRect rctClient;
	GetClientRect(&rctClient);

	CRect rctTab = rctClient;
	
	rctTab.bottom=rctClient.top + 200;
	m_modelSet.SetWindowPos(NULL, rctTab.left, rctTab.top, rctTab.Width(), rctTab.Height() ,SWP_NOZORDER);

	rctTab.top = rctTab.bottom;
	rctTab.bottom=rctClient.bottom;
	m_controllerList.SetWindowPos(NULL, rctTab.left, rctTab.top, rctTab.Width(), rctTab.Height() ,SWP_NOZORDER);
}



void CSetLightControllerDlg::On_InitTextTop(void)
{
	m_modelSet.m_modelName.SetWindowTextW(_T("Model"));
	m_modelSet.m_modelNameValue.SetWindowTextW(_T(""));
	m_modelSet.m_modelComPort.SetWindowTextW(_T("Com Port"));
	m_modelSet.m_modelComPortValue.SetWindowTextW(_T(""));
	m_modelSet.m_modelAuto.SetWindowTextW(_T("Auto (Manual)"));
	m_modelSet.m_modelBaudRate.SetWindowTextW(_T("Baud Rate"));
	m_modelSet.m_modelBaudRateValue.SetWindowTextW(_T(""));
	m_modelSet.m_modelParity.SetWindowTextW(_T("Parity"));
	m_modelSet.m_modelParityValue.SetWindowTextW(_T(""));
	m_modelSet.m_modelDataBits.SetWindowTextW(_T("Data Bits"));
	m_modelSet.m_modelDataBitsValue.SetWindowTextW(_T(""));
	m_modelSet.m_modelStopBits.SetWindowTextW(_T("Stop Bits"));
	m_modelSet.m_modelStopBitsValue.SetWindowTextW(_T(""));
	m_modelSet.m_lightChannel.SetWindowTextW(_T("Channel"));
	m_modelSet.m_lightChannelValue.SetWindowTextW(_T(""));
	m_modelSet.m_lightMax.SetWindowTextW(_T("Max."));
	m_modelSet.m_lightMaxValue.SetWindowTextW(_T(""));
}


void CSetLightControllerDlg::On_InitTextBottom(void)
{
	m_controllerList.m_lightTitleNo.SetWindowTextW(_T("NO."));
	m_controllerList.m_lightTitleName.SetWindowTextW(_T("NAME"));
	m_controllerList.m_lightTitleChannel.SetWindowTextW(_T("Channel"));
	m_controllerList.m_lightTitleMax.SetWindowTextW(_T("Max"));
	m_controllerList.m_lightTitleTest.SetWindowTextW(_T("Test"));
	m_controllerList.m_lightNo1.SetWindowTextW(_T("1"));
	m_controllerList.m_lightName1.SetWindowTextW(_T(""));
	m_controllerList.m_lightChannel1.SetWindowTextW(_T(""));
	m_controllerList.m_lightMax1.SetWindowTextW(_T(""));
	m_controllerList.m_lightTest1.SetWindowTextW(_T(""));
	m_controllerList.m_lightNo2.SetWindowTextW(_T("2"));
	m_controllerList.m_lightName2.SetWindowTextW(_T(""));
	m_controllerList.m_lightChannel2.SetWindowTextW(_T(""));
	m_controllerList.m_lightMax2.SetWindowTextW(_T(""));
	m_controllerList.m_lightTest2.SetWindowTextW(_T(""));
	m_controllerList.m_lightNo3.SetWindowTextW(_T("3"));
	m_controllerList.m_lightName3.SetWindowTextW(_T(""));
	m_controllerList.m_lightChannel3.SetWindowTextW(_T(""));
	m_controllerList.m_lightMax3.SetWindowTextW(_T(""));
	m_controllerList.m_lightTest3.SetWindowTextW(_T(""));
	m_controllerList.m_lightNo4.SetWindowTextW(_T("4"));
	m_controllerList.m_lightName4.SetWindowTextW(_T(""));
	m_controllerList.m_lightChannel4.SetWindowTextW(_T(""));
	m_controllerList.m_lightMax4.SetWindowTextW(_T(""));
	m_controllerList.m_lightTest4.SetWindowTextW(_T(""));
	m_controllerList.m_lightNo5.SetWindowTextW(_T("5"));
	m_controllerList.m_lightName5.SetWindowTextW(_T(""));
	m_controllerList.m_lightChannel5.SetWindowTextW(_T(""));
	m_controllerList.m_lightMax5.SetWindowTextW(_T(""));
	m_controllerList.m_lightTest5.SetWindowTextW(_T(""));
	m_controllerList.m_lightNo6.SetWindowTextW(_T("6"));
	m_controllerList.m_lightName6.SetWindowTextW(_T(""));
	m_controllerList.m_lightChannel6.SetWindowTextW(_T(""));
	m_controllerList.m_lightMax6.SetWindowTextW(_T(""));
	m_controllerList.m_lightTest6.SetWindowTextW(_T(""));
	m_controllerList.m_lightNo7.SetWindowTextW(_T("7"));
	m_controllerList.m_lightName7.SetWindowTextW(_T(""));
	m_controllerList.m_lightChannel7.SetWindowTextW(_T(""));
	m_controllerList.m_lightMax7.SetWindowTextW(_T(""));
	m_controllerList.m_lightTest7.SetWindowTextW(_T(""));
	m_controllerList.m_lightNo8.SetWindowTextW(_T("8"));
	m_controllerList.m_lightName8.SetWindowTextW(_T(""));
	m_controllerList.m_lightChannel8.SetWindowTextW(_T(""));
	m_controllerList.m_lightMax8.SetWindowTextW(_T(""));
	m_controllerList.m_lightTest8.SetWindowTextW(_T(""));
	m_controllerList.m_lightNo9.SetWindowTextW(_T("9"));
	m_controllerList.m_lightName9.SetWindowTextW(_T(""));
	m_controllerList.m_lightChannel9.SetWindowTextW(_T(""));
	m_controllerList.m_lightMax9.SetWindowTextW(_T(""));
	m_controllerList.m_lightTest9.SetWindowTextW(_T(""));
	m_controllerList.m_lightNo10.SetWindowTextW(_T("10"));
	m_controllerList.m_lightName10.SetWindowTextW(_T(""));
	m_controllerList.m_lightChannel10.SetWindowTextW(_T(""));
	m_controllerList.m_lightMax10.SetWindowTextW(_T(""));
	m_controllerList.m_lightTest10.SetWindowTextW(_T(""));
	m_controllerList.m_lightNo11.SetWindowTextW(_T("11"));
	m_controllerList.m_lightName11.SetWindowTextW(_T(""));
	m_controllerList.m_lightChannel11.SetWindowTextW(_T(""));
	m_controllerList.m_lightMax11.SetWindowTextW(_T(""));
	m_controllerList.m_lightTest11.SetWindowTextW(_T(""));
	m_controllerList.m_lightNo12.SetWindowTextW(_T("12"));
	m_controllerList.m_lightName12.SetWindowTextW(_T(""));
	m_controllerList.m_lightChannel12.SetWindowTextW(_T(""));
	m_controllerList.m_lightMax12.SetWindowTextW(_T(""));
	m_controllerList.m_lightTest12.SetWindowTextW(_T(""));
	m_controllerList.m_lightNo13.SetWindowTextW(_T("13"));
	m_controllerList.m_lightName13.SetWindowTextW(_T(""));
	m_controllerList.m_lightChannel13.SetWindowTextW(_T(""));
	m_controllerList.m_lightMax13.SetWindowTextW(_T(""));
	m_controllerList.m_lightTest13.SetWindowTextW(_T(""));
	m_controllerList.m_lightNo14.SetWindowTextW(_T("14"));
	m_controllerList.m_lightName14.SetWindowTextW(_T(""));
	m_controllerList.m_lightChannel14.SetWindowTextW(_T(""));
	m_controllerList.m_lightMax14.SetWindowTextW(_T(""));
	m_controllerList.m_lightTest14.SetWindowTextW(_T(""));
	m_controllerList.m_lightNo15.SetWindowTextW(_T("15"));
	m_controllerList.m_lightName15.SetWindowTextW(_T(""));
	m_controllerList.m_lightChannel15.SetWindowTextW(_T(""));
	m_controllerList.m_lightMax15.SetWindowTextW(_T(""));
	m_controllerList.m_lightTest15.SetWindowTextW(_T(""));
	m_controllerList.m_lightNo16.SetWindowTextW(_T("16"));
	m_controllerList.m_lightName16.SetWindowTextW(_T(""));
	m_controllerList.m_lightChannel16.SetWindowTextW(_T(""));
	m_controllerList.m_lightMax16.SetWindowTextW(_T(""));
	m_controllerList.m_lightTest16.SetWindowTextW(_T(""));
	m_controllerList.m_lightNo17.SetWindowTextW(_T("17"));
	m_controllerList.m_lightName17.SetWindowTextW(_T(""));
	m_controllerList.m_lightChannel17.SetWindowTextW(_T(""));
	m_controllerList.m_lightMax17.SetWindowTextW(_T(""));
	m_controllerList.m_lightTest17.SetWindowTextW(_T(""));
	m_controllerList.m_lightNo18.SetWindowTextW(_T("18"));
	m_controllerList.m_lightName18.SetWindowTextW(_T(""));
	m_controllerList.m_lightChannel18.SetWindowTextW(_T(""));
	m_controllerList.m_lightMax18.SetWindowTextW(_T(""));
	m_controllerList.m_lightTest18.SetWindowTextW(_T(""));
	m_controllerList.m_lightNo19.SetWindowTextW(_T("19"));
	m_controllerList.m_lightName19.SetWindowTextW(_T(""));
	m_controllerList.m_lightChannel19.SetWindowTextW(_T(""));
	m_controllerList.m_lightMax19.SetWindowTextW(_T(""));
	m_controllerList.m_lightTest19.SetWindowTextW(_T(""));
	m_controllerList.m_lightNo20.SetWindowTextW(_T("20"));
	m_controllerList.m_lightName20.SetWindowTextW(_T(""));
	m_controllerList.m_lightChannel20.SetWindowTextW(_T(""));
	m_controllerList.m_lightMax20.SetWindowTextW(_T(""));
	m_controllerList.m_lightTest20.SetWindowTextW(_T(""));

}
