
// ButtonColorDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ButtonColor.h"
#include "ButtonColorDlg.h"
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


// CButtonColorDlg 대화 상자




CButtonColorDlg::CButtonColorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CButtonColorDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CButtonColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CButtonColorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_WM_DRAWITEM()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CButtonColorDlg 메시지 처리기

BOOL CButtonColorDlg::OnInitDialog()
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

void CButtonColorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CButtonColorDlg::OnPaint()
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
HCURSOR CButtonColorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//void CButtonColorDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
//{
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//
//	CDialogEx::OnDrawItem(nIDCtl, lpDrawItemStruct);
//	if(nIDCtl == IDC_BUTTON1)
//
//	{
//
//		CDC dc;
//
//		RECT rect;
//
//		dc.Attach(lpDrawItemStruct->hDC);	//Get the Button DC to CDC
//
//
//
//		rect = lpDrawItemStruct->rcItem	;	//Store the Button rect to local rect
//
//		dc.Draw3dRect(&rect, RGB(0,0,0), RGB(0,0,0));
//
//		dc.FillSolidRect(&rect, RGB(0,0,0));
//
//		
//
//		
//
//		//Show the Effect of Click Event
//
//		UINT state = lpDrawItemStruct->itemState;
//
//		if((state & ODS_SELECTED))
//
//		{
//
//			dc.DrawEdge(&rect, EDGE_SUNKEN, BF_RECT);
//
//		}
//
//		else
//
//		{
//
//			dc.DrawEdge(&rect, EDGE_RAISED, BF_RECT);
//
//		}
//
//
//
//		//Draw Color Text
//
//		dc.SetBkColor(RGB(0,0,0));		//Setting the Text Background Color
//
//		dc.SetTextColor(RGB(255,255,255));		//Setting the Text Color
//
//
//
//		TCHAR buffer[MAX_PATH];
//
//		ZeroMemory(buffer, MAX_PATH);
//
//		::GetWindowText(lpDrawItemStruct->hwndItem, buffer, MAX_PATH);
//
//
//
//		dc.DrawText(buffer, &rect, DT_CENTER|DT_VCENTER |DT_SINGLELINE);
//
//		dc.Detach();							//Detach the Button DC
//
//
//
//	}
//
//}


HBRUSH CButtonColorDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	switch(nCtlColor){
	case CTLCOLOR_DLG:   /// 다이얼로그 배경색을 white로.
		{
			return (HBRUSH)GetStockObject(WHITE_BRUSH);
			break;
		}
	case CTLCOLOR_BTN :    // 버튼의 배경색을 투명으로...
		{
			pDC->SetTextColor(RGB(255,255,255));
			pDC->SetBkMode(TRANSPARENT);
			return (HBRUSH)::GetStockObject(BLACK_BRUSH);
		}
	case CTLCOLOR_STATIC:
		{
			pDC->SetTextColor(RGB(255,0,0));  // static text 글자색 변경
			pDC->SetBkMode(TRANSPARENT);   // static text 배경색 투명
			return (HBRUSH)::GetStockObject(NULL_BRUSH);
		} 
	}
	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;

}
