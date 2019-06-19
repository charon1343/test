
// _Argos_settingDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "_Argos_setting.h"
#include "_Argos_settingDlg.h"
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


// C_Argos_settingDlg ��ȭ ����




C_Argos_settingDlg::C_Argos_settingDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C_Argos_settingDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_fileserver_ip = _T("");
	m_license_path = _T("");
	m_saveformat = _T("");
	m_site_code = _T("");
	m_site_name = _T("");
	m_server_ip = _T("");
}

void C_Argos_settingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_fileserver_ip, m_fileserver_ip);
	DDX_Text(pDX, IDC_EDIT_license_path, m_license_path);
	DDX_Text(pDX, IDC_EDIT_saveformat, m_saveformat);
	DDX_Text(pDX, IDC_EDIT_site_code, m_site_code);
	DDX_Text(pDX, IDC_EDIT_site_name, m_site_name);
	DDX_Text(pDX, IDC_EDIT_server_ip, m_server_ip);
}

BEGIN_MESSAGE_MAP(C_Argos_settingDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C_Argos_settingDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C_Argos_settingDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// C_Argos_settingDlg �޽��� ó����

BOOL C_Argos_settingDlg::OnInitDialog()
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

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void C_Argos_settingDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C_Argos_settingDlg::OnPaint()
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
HCURSOR C_Argos_settingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C_Argos_settingDlg::OnBnClickedButton1()
{

	char site_code[100] = {0};
	char site_name[100] = {0};
	char saveformat[100] = {0};
	char fileserver_ip[100] = {0};
	char license_path[100] = {0};
	char server_ip[100] = {0};
	char programpath[_MAX_PATH];

	UpdateData(TRUE);
	
	GetCurrentDirectory( _MAX_PATH, programpath);

	strcat_s(programpath,"\\setting.ini");

	GetPrivateProfileString("COMMON","site_code",NULL,site_code,sizeof(site_code),programpath);
	GetPrivateProfileString("COMMON","site_name",NULL,site_name,sizeof(site_name),programpath);
	GetPrivateProfileString("SAVE","SaveFormat",NULL,saveformat,sizeof(saveformat),programpath);
	GetPrivateProfileString("SENDER","fileserver_ip",NULL,fileserver_ip,sizeof(fileserver_ip),programpath);
	GetPrivateProfileString("SENDER","license_path",NULL,license_path,sizeof(license_path),programpath);
	GetPrivateProfileString("MANAGER","server_ip",NULL,server_ip,sizeof(server_ip),programpath);

	DWORD dwError = GetLastError();
	m_site_code=site_code;
	m_site_name=site_name;
	m_saveformat=saveformat;
	m_fileserver_ip=fileserver_ip;
	m_license_path=license_path;
	m_server_ip=server_ip;
	UpdateData(FALSE);

	
	int aaa = 0;
}



void C_Argos_settingDlg::OnBnClickedButton2()
{
	char site_code[100] = {0};
	char site_name[100] = {0};
	char saveformat[100] = {0};
	char fileserver_ip[100] = {0};
	char license_path[100] = {0};
	char server_ip[100] = {0};
	char programpath[_MAX_PATH];

	UpdateData(TRUE);
	
	GetCurrentDirectory( _MAX_PATH, programpath);

	strcpy(site_code,m_site_code);
	strcpy(site_name,m_site_name);
	strcpy(saveformat,m_saveformat);
	strcpy(fileserver_ip,m_fileserver_ip);
	strcpy(license_path,m_license_path);
	strcpy(server_ip,m_server_ip);

	strcat_s(programpath,"\\setting.ini");
	WritePrivateProfileString("COMMON","site_code",site_code,programpath);
	WritePrivateProfileString("COMMON","site_name",site_name,programpath);
	WritePrivateProfileString("SAVE","SaveFormat",saveformat,programpath);
	WritePrivateProfileString("SENDER","fileserver_ip",fileserver_ip,programpath);
	WritePrivateProfileString("SENDER","license_path",license_path,programpath);
	WritePrivateProfileString("MANAGER","server_ip",server_ip,programpath);
	UpdateData(FALSE);
}

