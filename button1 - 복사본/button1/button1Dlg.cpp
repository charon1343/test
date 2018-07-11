
// button1Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "button1.h"
#include "button1Dlg.h"
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


// Cbutton1Dlg ��ȭ ����




Cbutton1Dlg::Cbutton1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cbutton1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cbutton1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_ctrlCheck1);
	DDX_Control(pDX, IDC_CHECK2, m_ctrlCheck2);
	DDX_Control(pDX, IDC_CHECK3, m_ctrlCheck3);
	DDX_Control(pDX, IDC_CHECK4, m_ctrlCheck4);
	
}

BEGIN_MESSAGE_MAP(Cbutton1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK1, &Cbutton1Dlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &Cbutton1Dlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &Cbutton1Dlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &Cbutton1Dlg::OnBnClickedCheck4)
	ON_WM_WINDOWPOSCHANGED()
END_MESSAGE_MAP()


// Cbutton1Dlg �޽��� ó����

BOOL Cbutton1Dlg::OnInitDialog()
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
	m_dlg1.Create(m_dlg1.IDD,this);
	m_dlg2.Create(m_dlg2.IDD,this);
	m_dlg3.Create(m_dlg3.IDD,this);
	m_dlg4.Create(m_dlg4.IDD,this);
	On_WindPos();
	m_dlg1.ShowWindow(SW_SHOW);
	m_dlg2.ShowWindow(SW_HIDE);
	m_dlg3.ShowWindow(SW_HIDE);
	m_dlg4.ShowWindow(SW_HIDE);
	m_ctrlCheck1.SetCheck(true, false);
	m_ctrlCheck2.SetCheck(false);
	m_ctrlCheck3.SetCheck(false);
	m_ctrlCheck4.SetCheck(false);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void Cbutton1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Cbutton1Dlg::OnPaint()
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
HCURSOR Cbutton1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cbutton1Dlg::OnBnClickedCheck1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_dlg1.ShowWindow(SW_SHOW);
	m_dlg2.ShowWindow(SW_HIDE);
	m_dlg3.ShowWindow(SW_HIDE);
	m_dlg4.ShowWindow(SW_HIDE);
	m_ctrlCheck1.SetCheck(true, false);
	m_ctrlCheck2.SetCheck(false);
	m_ctrlCheck3.SetCheck(false);
	m_ctrlCheck4.SetCheck(false);
}


void Cbutton1Dlg::OnBnClickedCheck2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_dlg1.ShowWindow(SW_HIDE);
	m_dlg2.ShowWindow(SW_SHOW);
	m_dlg3.ShowWindow(SW_HIDE);
	m_dlg4.ShowWindow(SW_HIDE);
	m_ctrlCheck1.SetCheck(false);
	m_ctrlCheck2.SetCheck(true, false);
	m_ctrlCheck3.SetCheck(false);
	m_ctrlCheck4.SetCheck(false);
}


void Cbutton1Dlg::OnBnClickedCheck3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_dlg1.ShowWindow(SW_HIDE);
	m_dlg2.ShowWindow(SW_HIDE);
	m_dlg3.ShowWindow(SW_SHOW);
	m_dlg4.ShowWindow(SW_HIDE);
	m_ctrlCheck1.SetCheck(false);
	m_ctrlCheck2.SetCheck(false);
	m_ctrlCheck3.SetCheck(true, false);
	m_ctrlCheck4.SetCheck(false);
}


void Cbutton1Dlg::OnBnClickedCheck4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_dlg1.ShowWindow(SW_HIDE);
	m_dlg2.ShowWindow(SW_HIDE);
	m_dlg3.ShowWindow(SW_HIDE);
	m_dlg4.ShowWindow(SW_SHOW);
	m_ctrlCheck1.SetCheck(false);
	m_ctrlCheck2.SetCheck(false);
	m_ctrlCheck3.SetCheck(false);
	m_ctrlCheck4.SetCheck(true, false);
}


void Cbutton1Dlg::On_WindPos()
{
	CRect rctClient;
	GetClientRect(&rctClient);
	rctClient.top += 5;
	rctClient.left += 5;
	rctClient.bottom -= 5;
	rctClient.right -= 5;

	CRect rctTab = rctClient;
	rctTab.bottom = rctTab.top + 40;
	CRect rctSub = rctClient;
	rctSub.top = rctTab.bottom + 1;

	int nWidth = (rctClient.Width() + 1) / 4 - 1;

	rctTab.right = rctTab.left + nWidth;
	m_ctrlCheck1.SetWindowPos(rctTab);
	
	rctTab.left = rctTab.right + 1;
	rctTab.right = rctTab.left + nWidth;
	m_ctrlCheck2.SetWindowPos(rctTab);

	rctTab.left = rctTab.right + 1;
	rctTab.right = rctTab.left + nWidth;
	m_ctrlCheck3.SetWindowPos(rctTab);

	rctTab.left = rctTab.right + 1;
	rctTab.right = rctTab.left + nWidth;
	m_ctrlCheck4.SetWindowPos(rctTab);

	m_dlg1.SetWindowPos(NULL, rctSub.left, rctSub.top, rctSub.Width(), rctSub.Height() ,SWP_NOZORDER);
	m_dlg2.SetWindowPos(NULL, rctSub.left, rctSub.top, rctSub.Width(), rctSub.Height() ,SWP_NOZORDER);
	m_dlg3.SetWindowPos(NULL, rctSub.left, rctSub.top, rctSub.Width(), rctSub.Height() ,SWP_NOZORDER);
	m_dlg4.SetWindowPos(NULL, rctSub.left, rctSub.top, rctSub.Width(), rctSub.Height() ,SWP_NOZORDER);
}

void Cbutton1Dlg::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if ((lpwndpos->flags & SWP_NOSIZE) == 0) { On_WindPos();}
}

//void Cbutton1Dlg::On_WindPosACL(){
//	CRect rctClient;
//	GetClientRect(&rctClient);
//	rctClient.top += 5;
//	rctClient.left += 5;
//	rctClient.bottom -= 5;
//	rctClient.right -= 5;
//
//	CRect rctTab = rctClient;
//	rctTab.bottom = rctTab.top + 40;
//	CRect rctSub = rctClient;
//	rctSub.top = rctTab.bottom + 1;
//
//	int nWidth = (rctClient.Width() + 1) / 4 - 1;
//	rctTab.right = rctTab.left + nWidth;
//	m_FindLine.SetWindowPos(rctTab);
//	
//}