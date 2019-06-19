
// _Argos_tapDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "_Argos_tap.h"
#include "_Argos_tapDlg.h"
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


// C_Argos_tapDlg 대화 상자




C_Argos_tapDlg::C_Argos_tapDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C_Argos_tapDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_combo_tap4_combo1 = _T("");
	m_edit_tap1_edit1 = _T("");
	m_edit_tap2_edit1 = _T("");
	m_edit_tap2_edit2 = _T("");
	m_edit_tap3_edit1 = _T("");
	m_edit_tap4_edit1 = _T("");
	m_edit_tap4_edit2 = _T("");
	m_edit_tap5_edit1 = _T("");
	m_edit_tap5_edit2 = _T("");
	m_edit_tap5_edit3 = _T("");
	m_edit_tap5_edit4 = _T("");
}

void C_Argos_tapDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_tap5_check, m_check_tap5_check1);
	DDX_Check(pDX, IDC_CHECK_tap5_check2, m_check_tap5_check2);
	DDX_Check(pDX, IDC_CHECK_tap5_check3, m_check_tap5_check3);
	DDX_CBString(pDX, IDC_COMBO_tap4_combo1, m_combo_tap4_combo1);
	DDX_Text(pDX, IDC_EDIT_tab1_edit, m_edit_tap1_edit1);
	DDX_Text(pDX, IDC_EDIT_tap2_edit1, m_edit_tap2_edit1);
	DDX_Text(pDX, IDC_EDIT_tap2_edit2, m_edit_tap2_edit2);
	DDX_Text(pDX, IDC_EDIT_tap3_edit1, m_edit_tap3_edit1);
	DDX_Text(pDX, IDC_EDIT_tap4_edit1, m_edit_tap4_edit1);
	DDX_Text(pDX, IDC_EDIT_tap4_edit2, m_edit_tap4_edit2);
	DDX_Text(pDX, IDC_EDIT_tap5_edit1, m_edit_tap5_edit1);
	DDX_Text(pDX, IDC_EDIT_tap5_edit2, m_edit_tap5_edit2);
	DDX_Text(pDX, IDC_EDIT_tap5_edit3, m_edit_tap5_edit3);
	DDX_Text(pDX, IDC_EDIT_tap5_edit4, m_edit_tap5_edit4);
	DDX_Control(pDX, IDC_TAB_AREA, m_tabArea);
}

BEGIN_MESSAGE_MAP(C_Argos_tapDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_AREA, &C_Argos_tapDlg::OnSelchangeTabArea)
END_MESSAGE_MAP()


// C_Argos_tapDlg 메시지 처리기

BOOL C_Argos_tapDlg::OnInitDialog()
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

	TC_ITEM tabItem;
	LPSTR tabName[5] = {_T("개요"),_T("일반정보"),_T("라이센스"),_T("저장정보"),_T("서버정보")};
	for(int nIndex = 0;nIndex<5;nIndex++)
	{
		tabItem.mask = TCIF_TEXT;
		tabItem.pszText = tabName[nIndex];
		m_tabArea.InsertItem(nIndex, &tabItem);
	}

	GetDlgItem(IDC_EDIT_tab1_edit)->SetWindowText("시스템설정은 다음과 같습니다.\n0사이트 정보 설정\n0사이트 정보 설정\n0라이센스확인\n저장영상설정\n차번서버 정보설정\n\n\n각 페이지의 설정을 적용하려면 \"필히\"저장버튼을 눌러주세요.\n\n설정을 종료하려면 아무창에서나 마침을 클릭하세요. ");
	GetDlgItem(IDC_EDIT_tab1_edit)->ShowWindow(true);

	GetDlgItem(IDC_EDIT_tap2_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap2_edit2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tab2_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap2_static2)->ShowWindow(false);

	GetDlgItem(IDC_STATIC_tap3_static1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap3_edit1)->ShowWindow(false);

	GetDlgItem(IDC_STATIC_tap4_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_static2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_static3)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_group1)->ShowWindow(false);
	GetDlgItem(IDC_COMBO_tap4_combo1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap4_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap4_edit2)->ShowWindow(false);
	GetDlgItem(IDC_COMBO_tap4_combo1)->ShowWindow(false);
	
	GetDlgItem(IDC_EDIT_tap5_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit2)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit3)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit4)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_group1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_group2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static3)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static4)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check2)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check3)->ShowWindow(false);
	
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void C_Argos_tapDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C_Argos_tapDlg::OnPaint()
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
HCURSOR C_Argos_tapDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C_Argos_tapDlg::OnSelchangeTabArea(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	int nSelect = m_tabArea.GetCurSel();

	switch(nSelect)
	{
	case 0:
	GetDlgItem(IDC_EDIT_tab1_edit)->ShowWindow(true);

	GetDlgItem(IDC_EDIT_tap2_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap2_edit2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tab2_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap2_static2)->ShowWindow(false);

	GetDlgItem(IDC_STATIC_tap3_static1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap3_edit1)->ShowWindow(false);

	GetDlgItem(IDC_STATIC_tap4_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_static2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_static3)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_group1)->ShowWindow(false);
	GetDlgItem(IDC_COMBO_tap4_combo1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap4_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap4_edit2)->ShowWindow(false);
	GetDlgItem(IDC_COMBO_tap4_combo1)->ShowWindow(false);
	
	GetDlgItem(IDC_EDIT_tap5_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit2)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit3)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit4)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_group1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_group2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static3)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static4)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check2)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check3)->ShowWindow(false);
	break;

	case 1:
	GetDlgItem(IDC_EDIT_tab1_edit)->ShowWindow(false);

	GetDlgItem(IDC_EDIT_tap2_edit1)->ShowWindow(true);
	GetDlgItem(IDC_EDIT_tap2_edit2)->ShowWindow(true);
	GetDlgItem(IDC_STATIC_tab2_static1)->ShowWindow(true);
	GetDlgItem(IDC_STATIC_tap2_static2)->ShowWindow(true);

	GetDlgItem(IDC_STATIC_tap3_static1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap3_edit1)->ShowWindow(false);

	GetDlgItem(IDC_STATIC_tap4_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_static2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_static3)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_group1)->ShowWindow(false);
	GetDlgItem(IDC_COMBO_tap4_combo1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap4_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap4_edit2)->ShowWindow(false);
	GetDlgItem(IDC_COMBO_tap4_combo1)->ShowWindow(false);
	
	GetDlgItem(IDC_EDIT_tap5_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit2)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit3)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit4)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_group1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_group2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static3)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static4)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check2)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check3)->ShowWindow(false);
	break;

	case 2:
	GetDlgItem(IDC_EDIT_tab1_edit)->ShowWindow(false);

	GetDlgItem(IDC_EDIT_tap2_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap2_edit2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tab2_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap2_static2)->ShowWindow(false);

	GetDlgItem(IDC_STATIC_tap3_static1)->ShowWindow(true);
	GetDlgItem(IDC_EDIT_tap3_edit1)->ShowWindow(true);

	GetDlgItem(IDC_STATIC_tap4_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_static2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_static3)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_group1)->ShowWindow(false);
	GetDlgItem(IDC_COMBO_tap4_combo1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap4_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap4_edit2)->ShowWindow(false);
	GetDlgItem(IDC_COMBO_tap4_combo1)->ShowWindow(false);
	
	GetDlgItem(IDC_EDIT_tap5_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit2)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit3)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit4)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_group1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_group2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static3)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static4)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check2)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check3)->ShowWindow(false);
	break;

	case 3:
	GetDlgItem(IDC_EDIT_tab1_edit)->ShowWindow(false);

	GetDlgItem(IDC_EDIT_tap2_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap2_edit2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tab2_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap2_static2)->ShowWindow(false);

	GetDlgItem(IDC_STATIC_tap3_static1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap3_edit1)->ShowWindow(false);

	GetDlgItem(IDC_STATIC_tap4_static1)->ShowWindow(true);
	GetDlgItem(IDC_STATIC_tap4_static2)->ShowWindow(true);
	GetDlgItem(IDC_STATIC_tap4_static3)->ShowWindow(true);
	GetDlgItem(IDC_STATIC_tap4_group1)->ShowWindow(true);
	GetDlgItem(IDC_COMBO_tap4_combo1)->ShowWindow(true);
	GetDlgItem(IDC_EDIT_tap4_edit1)->ShowWindow(true);
	GetDlgItem(IDC_EDIT_tap4_edit2)->ShowWindow(true);
	GetDlgItem(IDC_COMBO_tap4_combo1)->ShowWindow(true);
	
	GetDlgItem(IDC_EDIT_tap5_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit2)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit3)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit4)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_group1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_group2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static3)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static4)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check2)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check3)->ShowWindow(false);
	break;

	case 4:
	GetDlgItem(IDC_EDIT_tab1_edit)->ShowWindow(false);

	GetDlgItem(IDC_EDIT_tap2_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap2_edit2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tab2_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap2_static2)->ShowWindow(false);

	GetDlgItem(IDC_STATIC_tap3_static1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap3_edit1)->ShowWindow(false);

	GetDlgItem(IDC_STATIC_tap4_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_static2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_static3)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_group1)->ShowWindow(false);
	GetDlgItem(IDC_COMBO_tap4_combo1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap4_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap4_edit2)->ShowWindow(false);
	GetDlgItem(IDC_COMBO_tap4_combo1)->ShowWindow(false);
	
	GetDlgItem(IDC_EDIT_tap5_edit1)->ShowWindow(true);
	GetDlgItem(IDC_EDIT_tap5_edit2)->ShowWindow(true);
	GetDlgItem(IDC_EDIT_tap5_edit3)->ShowWindow(true);
	GetDlgItem(IDC_EDIT_tap5_edit4)->ShowWindow(true);
	GetDlgItem(IDC_STATIC_tap5_group1)->ShowWindow(true);
	GetDlgItem(IDC_STATIC_tap5_group2)->ShowWindow(true);
	GetDlgItem(IDC_STATIC_tap5_static1)->ShowWindow(true);
	GetDlgItem(IDC_STATIC_tap5_static2)->ShowWindow(true);
	GetDlgItem(IDC_STATIC_tap5_static3)->ShowWindow(true);
	GetDlgItem(IDC_STATIC_tap5_static4)->ShowWindow(true);
	GetDlgItem(IDC_CHECK_tap5_check)->ShowWindow(true);
	GetDlgItem(IDC_CHECK_tap5_check2)->ShowWindow(true);
	GetDlgItem(IDC_CHECK_tap5_check3)->ShowWindow(true);
	break;
	}
	*pResult = 0;

}
