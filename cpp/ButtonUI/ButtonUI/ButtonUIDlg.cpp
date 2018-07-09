// ButtonUIDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ButtonUI.h"
#include "ButtonUIDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CButtonUIDlg ��ȭ ����




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


// CButtonUIDlg �޽��� ó����

BOOL CButtonUIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	
	m_dlgTop.Create(m_dlgTop.IDD,this);
	m_dlgBottomLeft.Create(m_dlgBottomLeft.IDD,this);
	m_dlgBottomRight.Create(m_dlgBottomRight.IDD,this);


	m_dlgTop.ShowWindow(SW_SHOW);
	m_dlgBottomLeft.ShowWindow(SW_SHOW);
	m_dlgBottomRight.ShowWindow(SW_SHOW);

	On_WindPos();
	On_InitTextLeft();
	On_InitTextRight();
	
	

	
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CButtonUIDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
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

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
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

