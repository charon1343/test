
// MN_VISDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "MN_VIS.h"
#include "MN_VISDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.
class CAboutDlg : public CMNVDialogEx
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
	virtual void OnOK() { CDialogEx::OnOK(); }
	//virtual void Thread() {
	//	int nCount = 0;
	//	while(nCount >= 0) {
	//		SetItemData(IDC_ABOUT_Message, ++nCount);
	//		Sleep(10);
	//		if (nCount > 500) {
	//			//CDialogEx::OnOK();
	//			nCount = -1;
	//		}
	//	}
	//}
	virtual BOOL OnInitDialog()
	{
		CMNVDialogEx::OnInitDialog();

		// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
		//CreateThread();

		return TRUE;  // return TRUE unless you set the focus to a control
		// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
	}
};

CAboutDlg::CAboutDlg() : CMNVDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMN_VISDlg ��ȭ ����




CMN_VISDlg::CMN_VISDlg(CWnd* pParent /*=NULL*/)
	: CMNVDialogEx(CMN_VISDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMN_VISDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMN_VISDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMN_VISDlg::OnBnClickedOk)
	ON_WM_WINDOWPOSCHANGED()
	ON_BN_CLICKED(IDCANCEL, &CMN_VISDlg::OnBnClickedCancel)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CMN_VISDlg �޽��� ó����

BOOL CMN_VISDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_strLayOut = _T("D:\\Setting\\LayOut.ini");
	//{
	//	wchar_t strBuf[1024];
	//	GetCurrentDirectory(1024, strBuf);
	//	m_strLayOut.Format(_T("D:\\Setting\\LayOut.ini"), strBuf);
	//	CMNVFile::CreatePath(m_strLayOut);
	//}

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
	//m_nChannel[0] = 0;
	//m_nChannel[1] = 1;
	//m_nChannel[2] = 2;
	//m_nChannel[3] = 3;
	
	m_dlgLoading.Create(IDD_MSG_LOADING, this, this);

	//m_pDevicePLC = new CMNV_DevicePLC;
	m_dlgHeader.Create(&m_Algorithm, this, this);
	m_dlgMain.Create(&m_Algorithm, this, this);
	m_dlgSDRun.Create(&m_Algorithm, this, this);
	SetSelectChannel(0);

	m_dlgFooter.Create(IDD_FRM_FOOTER, this, this);
	m_dlgSetting.Create(&m_Algorithm, this, this);

	CreateThread();
	m_dlgSetting.ShowWindow(false);
	ShowWindow(false);
	m_dlgLoading.ShowWindow(true);


	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}
void CMN_VISDlg::Thread()
{
	isDestroy = false;
	nCount = 0;

	m_dlgLoading.nCount = 10;
	m_Algorithm.m_PLC.PLC_Start(_T("D:\\Setting\\PLC.ini"));

	m_Algorithm.Grabber_Init();
	m_Algorithm.Light_Init();

	m_Algorithm.Begin();
	//m_pDevicePLC->BeginThread();
	m_dlgLoading.nCount = 20;
	//m_pDevicePLC->RunPLC();
	m_dlgLoading.nCount = 50;
	//{	// Device Loading : Camera
	//	m_pFrameGrabbers = new CMNVFrameGrabbers();
	//	m_cntCamInfo = 4;//m_pFrameGrabbers->GetCount();
	//	m_pCamInfo = new CCamInfo[m_cntCamInfo];
	//	m_dlgLoading.nCount = 60;

	//	CMNVFrameGrabber FrmGrabber;
	//	CString strName;
	//	for (int nIndex = 0; nIndex < m_cntCamInfo; ++nIndex) {
	//		strName.Format(_T("Camera Channel %d"), nIndex);
	//		if (m_pFrameGrabbers->GetFrameGrabber(nIndex, FrmGrabber)) {
	//			m_dlgLoading.nCount = 90;
	//			m_pCamInfo[nIndex].LoadCamInfo(_T("C:\\Users\\Administrator\\Desktop\\MN_VIS\\MN_VIS"), _T("CamSetting.ini"), strName);
	//			m_pCamInfo[nIndex].Init(strName, FrmGrabber);
	//			m_pCamInfo[nIndex].GrabStart();
	//			//FrmGrabber->Disconnect(VARIANT_TRUE);
	//			FrmGrabber.Release();
	//			m_dlgLoading.nCount = 95;
	//		}
	//		else  m_pCamInfo[nIndex].Init(strName);
	//	}
	//	m_pFrameGrabbers->Release();
	//}
	m_dlgLoading.nCount = 98;
	//m_dlgSetting.InitVisionData(4, m_cntCamInfo, m_pCamInfo);
	m_dlgSetting.InitSelector(m_Algorithm);
	m_dlgLoading.nCount = 100;
	while (m_dlgLoading.isProcessing) {
		Sleep(10);
	}
	LoadLayout();

	//CMNVImage imgBuf;
	while (true) {
		//m_Algorithm.Algorithm_Grab(0, imgBuf);
		//m_dlgMain.SetImage(imgBuf);
		Reflash_PLC();
		Sleep(10);
	}
}
void CMN_VISDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMN_VISDlg::OnPaint()
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
HCURSOR CMN_VISDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMN_VISDlg::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CMNVDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if ((lpwndpos->flags & SWP_NOSIZE) == 0) {
		CRect rect;
		if (isDestroy) return;
		GetClientRect(&rect);
		if (rect.Width() == 0 && rect.Height() == 0) {
			//m_dlgSetting.ShowWindow(false);
		}
		else { SetLayout(); }
	}
	//RedrawWindow();
}
