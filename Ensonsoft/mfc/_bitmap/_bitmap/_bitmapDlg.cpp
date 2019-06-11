
// _bitmapDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "_bitmap.h"
#include "_bitmapDlg.h"
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


// C_bitmapDlg 대화 상자




C_bitmapDlg::C_bitmapDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C_bitmapDlg::IDD, pParent)
	, m_menuID(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C_bitmapDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C_bitmapDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_FILE_EXIT, &C_bitmapDlg::OnFileExit)
	ON_COMMAND(ID_HELP_ABOUT, &C_bitmapDlg::OnHelpAbout)
	ON_WM_SIZE()
	ON_COMMAND(ID_ZOOM_IN, &C_bitmapDlg::OnZoomIn)
	ON_COMMAND(ID_ZOOM_OUT, &C_bitmapDlg::OnZoomOut)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &C_bitmapDlg::OnClickedButtonExit)
END_MESSAGE_MAP()


// C_bitmapDlg 메시지 처리기

BOOL C_bitmapDlg::OnInitDialog()
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

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void C_bitmapDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C_bitmapDlg::OnPaint()
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
		CPaintDC dc(this);
		HBITMAP hbitmap = ::LoadBitmap(m_hInstance, MAKEINTRESOURCE(IDB_BITMAP2));

		HDC hMemDC = ::CreateCompatibleDC(NULL);

		SelectObject(hMemDC,hbitmap);

		switch(m_menuID)
		{
		case ID_ZOOM_IN:
			::StretchBlt(dc.m_hDC,0,0,m_nWidth,m_nHeight,hMemDC,0,0,300,300,SRCCOPY);
			break;

		case ID_ZOOM_OUT:
			::StretchBlt(dc.m_hDC,0,0,150,150,hMemDC,0,0,300,300,SRCCOPY);
			break;

		default:
			::StretchBlt(dc.m_hDC,50,50,300,300,hMemDC,0,0,250,250,SRCCOPY);
		}

		::DeleteDC(hMemDC);
		::DeleteObject(hbitmap);
		///////

		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR C_bitmapDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C_bitmapDlg::OnFileExit()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	OnOK();
}


void C_bitmapDlg::OnHelpAbout()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	 CAboutDlg dlg;
	 dlg.DoModal();

}


void C_bitmapDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	m_nWidth = cx;
	m_nHeight = cy;
	Invalidate();
}


void C_bitmapDlg::OnZoomIn()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_menuID = ID_ZOOM_IN;
	Invalidate();
}


void C_bitmapDlg::OnZoomOut()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_menuID = ID_ZOOM_OUT;
	Invalidate();
}


void C_bitmapDlg::OnClickedButtonExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}
