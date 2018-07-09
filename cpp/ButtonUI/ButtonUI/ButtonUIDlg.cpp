// ButtonUIDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ButtonUI.h"
#include "ButtonUIDlg.h"
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
//	void On_WindPos(void);
//	void On_WindPos(void);
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CButtonUIDlg 대화 상자




CButtonUIDlg::CButtonUIDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CButtonUIDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CButtonUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CButtonUIDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_WINDOWPOSCHANGED()
END_MESSAGE_MAP()


// CButtonUIDlg 메시지 처리기

BOOL CButtonUIDlg::OnInitDialog()
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
	
	m_dlgTop.Create(m_dlgTop.IDD,this);
	m_dlgBottomLeft.Create(m_dlgBottomLeft.IDD,this);
	m_dlgBottomRight.Create(m_dlgBottomRight.IDD,this);


	m_dlgTop.ShowWindow(SW_SHOW);
	m_dlgBottomLeft.ShowWindow(SW_SHOW);
	m_dlgBottomRight.ShowWindow(SW_SHOW);

	On_WindPos();
	On_InitTextLeft();
	On_InitTextRight();
	
	

	
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CButtonUIDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CButtonUIDlg::OnPaint()
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
HCURSOR CButtonUIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CButtonUIDlg::On_WindPos(void)
{
	CRect rctClient;
	GetClientRect(&rctClient);

	CRect rctTab = rctClient;
	rctTab.bottom = rctTab.top + 70;
	CRect rctSub = rctClient;
	rctSub.top = rctTab.bottom + 1;

	m_dlgTop.SetWindowPos(NULL, rctTab.left, rctTab.top, rctTab.Width(), rctTab.Height() ,SWP_NOZORDER);
	m_dlgBottomLeft.SetWindowPos(NULL, rctSub.left, rctSub.top, rctSub.Width()/2, rctSub.Height() ,SWP_NOZORDER);
	m_dlgBottomRight.SetWindowPos(NULL, rctSub.Width()/2+rctSub.left, rctSub.top, rctSub.Width()/2, rctSub.Height() ,SWP_NOZORDER);
}



void CButtonUIDlg::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if ((lpwndpos->flags & SWP_NOSIZE) == 0) { On_WindPos();}

}


void CButtonUIDlg::On_InitTextLeft(void)
{
	m_dlgBottomLeft.m_signalDestination.SetWindowTextW(_T("PLC(Robot) -> PC(Vision)"));
	m_dlgBottomLeft.m_signalSegment.SetWindowTextW(_T("Segment"));
	m_dlgBottomLeft.m_signalSegmentValue.SetWindowTextW(_T(""));
	m_dlgBottomLeft.m_signalSize.SetWindowTextW(_T("Size"));
	m_dlgBottomLeft.m_signalSizeValue.SetWindowTextW(_T(""));
	m_dlgBottomLeft.m_signalTitleName.SetWindowTextW(_T("Name"));
	m_dlgBottomLeft.m_signalTitleOffset.SetWindowTextW(_T("Offset"));
	m_dlgBottomLeft.m_signalTitleType.SetWindowTextW(_T("Type"));
	m_dlgBottomLeft.m_signalTitleBit.SetWindowTextW(_T("Bit"));
	m_dlgBottomLeft.m_signalName1.SetWindowTextW(_T("Prepare"));
	m_dlgBottomLeft.m_signalName2.SetWindowTextW(_T("Triger"));
	m_dlgBottomLeft.m_signalName3.SetWindowTextW(_T("Finish"));
	m_dlgBottomLeft.m_signalName4.SetWindowTextW(_T("End"));
	m_dlgBottomLeft.m_signalName5.SetWindowTextW(_T("Model"));
	m_dlgBottomLeft.m_signalName6.SetWindowTextW(_T("Inspect Item"));
	m_dlgBottomLeft.m_signalName7.SetWindowTextW(_T(""));
	m_dlgBottomLeft.m_signalName8.SetWindowTextW(_T(""));
	m_dlgBottomLeft.m_signalName9.SetWindowTextW(_T(""));
	m_dlgBottomLeft.m_signalName10.SetWindowTextW(_T(""));
}





void CButtonUIDlg::On_InitTextRight(void)
{
	m_dlgBottomRight.m_signalDestination.SetWindowTextW(_T("PC(Vision) -> PLC(Robot)"));
	m_dlgBottomRight.m_signalSegment.SetWindowTextW(_T("Segment"));
	m_dlgBottomRight.m_signalSegmentValue.SetWindowTextW(_T(""));
	m_dlgBottomRight.m_signalSize.SetWindowTextW(_T("Size"));
	m_dlgBottomRight.m_signalSizeValue.SetWindowTextW(_T(""));
	m_dlgBottomRight.m_signalTitleName.SetWindowTextW(_T("Name"));
	m_dlgBottomRight.m_signalTitleOffset.SetWindowTextW(_T("Offset"));
	m_dlgBottomRight.m_signalTitleType.SetWindowTextW(_T("Type"));
	m_dlgBottomRight.m_signalTitleBit.SetWindowTextW(_T("Bit"));
	m_dlgBottomRight.m_signalName1.SetWindowTextW(_T("Wait"));
	m_dlgBottomRight.m_signalName2.SetWindowTextW(_T("Ready"));
	m_dlgBottomRight.m_signalName3.SetWindowTextW(_T("Grab"));
	m_dlgBottomRight.m_signalName4.SetWindowTextW(_T("Inspect"));
	m_dlgBottomRight.m_signalName5.SetWindowTextW(_T("Result"));
	m_dlgBottomRight.m_signalName6.SetWindowTextW(_T("OK"));
	m_dlgBottomRight.m_signalName7.SetWindowTextW(_T("NG"));
	m_dlgBottomRight.m_signalName8.SetWindowTextW(_T("Alarm"));
	m_dlgBottomRight.m_signalName9.SetWindowTextW(_T("Model"));
	m_dlgBottomRight.m_signalName10.SetWindowTextW(_T("Inspect Item"));
}

