
// _Argos_setting_12Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "_Argos_setting_12.h"
#include "_Argos_setting_12Dlg.h"
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


// C_Argos_setting_12Dlg 대화 상자




C_Argos_setting_12Dlg::C_Argos_setting_12Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C_Argos_setting_12Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_dispq_count = _T("");
	m_exposure_recogcount = _T("");
	m_io_config_mode = _T("");
	m_readyq_count = _T("");
	m_site_code = _T("");
	m_site_name = _T("");
	m_time_expire_sec = _T("");
	m_triggermode = _T("");
	m_violationspeed = _T("");
	m_backup_path = _T("");
	m_insertplate = _T("");
	m_keep_store_days = _T("");
	m_log_store_days = _T("");
	m_saveheight = _T("");
	m_savepath = _T("");
	m_savewidth = _T("");
	m_sequenceimgcount = _T("");
	m_saveformat = _T("");
	//  m_height = _T("");
	//  m_width = _T("");
	m_tap3_height = _T("");
	m_tap3_width = _T("");
	m_bitrate = _T("");
	m_tap4_height = _T("");
	m_tap4_width = _T("");
	m_plateheight = _T("");
	m_platepositionbottom = _T("");
	m_platewidth = _T("");
	m_streamname = _T("");
	m_streamport = _T("");
	//  m_udp_alive_period = _T("");
	//  m_udp_port = _T("");
	m_file_arrange = _T("");
	//  m_filie_gathering_time = _T("");
	m_file_send = _T("");
	//  m_sileserver_ip = _T("");
	m_fileserver_port = _T("");
	m_ftp_id = _T("");
	m_ftp_passive = _T("");
	m_ftp_pw = _T("");
	m_ftp_subdir = _T("");
	m_transfer_format = _T("");
	m_transfer_mode = _T("");
	m_transfer_sitecode = _T("");
	m_transfer_sitecode2 = _T("");
	m_tap5_udp_alive_period = _T("");
	m_tap6_udp_alive_period = _T("");
	m_tap5_udp_port = _T("");
	m_tap6_udp_port = _T("");
	//  m_user_recog1 = _T("");
	m_use_recog2 = _T("");
	m_use_recog3 = _T("");
	m_duration_sec = _T("");
	m_host_ip = _T("");
	m_manageprogcount = _T("");
	m_manageprogid_0 = _T("");
	m_manageprogid_1 = _T("");
	m_manageprogid_2 = _T("");
	m_manageprogname_0 = _T("");
	m_manageprogname_1 = _T("");
	//  m_managerprogname_2 = _T("");
	m_progname = _T("");
	m_server_ip = _T("");
	m_server_port = _T("");
	m_udp_bind_port = _T("");
	m_companyformat = _T("");
	m_transfer_sitecode_2 = _T("");
	m_fileserver_ip = _T("");
	m_file_gathering_time = _T("");
	m_use_recog1 = _T("");
	m_manageprogname_2 = _T("");
}

void C_Argos_setting_12Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_tap1_dispq_count, m_dispq_count);
	DDX_Text(pDX, IDC_EDIT_tap1_exposure_recogcount, m_exposure_recogcount);
	DDX_Text(pDX, IDC_EDIT_tap1_io_config_mode, m_io_config_mode);
	DDX_Text(pDX, IDC_EDIT_tap1_readyq_count, m_readyq_count);
	DDX_Text(pDX, IDC_EDIT_tap1_site_code, m_site_code);
	DDX_Text(pDX, IDC_EDIT_tap1_site_name, m_site_name);
	DDX_Text(pDX, IDC_EDIT_tap1_time_expire_sec, m_time_expire_sec);
	DDX_Text(pDX, IDC_EDIT_tap1_triggermode, m_triggermode);
	DDX_Text(pDX, IDC_EDIT_tap1_violationspeed, m_violationspeed);
	DDX_Text(pDX, IDC_EDIT_tap2_backup_path, m_backup_path);
	DDX_Text(pDX, IDC_EDIT_tap2_insertplate, m_insertplate);
	DDX_Text(pDX, IDC_EDIT_tap2_keep_store_days, m_keep_store_days);
	DDX_Text(pDX, IDC_EDIT_tap2_log_store_days, m_log_store_days);
	DDX_Text(pDX, IDC_EDIT_tap2_saveheight, m_saveheight);
	DDX_Text(pDX, IDC_EDIT_tap2_savepath, m_savepath);
	DDX_Text(pDX, IDC_EDIT_tap2_savewidth, m_savewidth);
	DDX_Text(pDX, IDC_EDIT_tap2_sequenceimgcount, m_sequenceimgcount);
	DDX_Text(pDX, IDC_EDIT_tap2_saveformat, m_saveformat);
	//  DDX_Text(pDX, IDC_EDIT_tap3_height, m_height);
	//  DDX_Text(pDX, IDC_EDIT_tap3_width, m_width);
	DDX_Text(pDX, IDC_EDIT_tap3_height, m_tap3_height);
	DDX_Text(pDX, IDC_EDIT_tap3_width, m_tap3_width);
	DDX_Text(pDX, IDC_EDIT_tap4_bitrate, m_bitrate);
	DDX_Text(pDX, IDC_EDIT_tap4_height, m_tap4_height);
	DDX_Text(pDX, IDC_EDIT_tap4_width, m_tap4_width);
	DDX_Text(pDX, IDC_EDIT_tap4_plateheight, m_plateheight);
	DDX_Text(pDX, IDC_EDIT_tap4_platepositionbottom, m_platepositionbottom);
	DDX_Text(pDX, IDC_EDIT_tap4_platewidth, m_platewidth);
	DDX_Text(pDX, IDC_EDIT_tap4_streamname, m_streamname);
	DDX_Text(pDX, IDC_EDIT_tap4_streamport, m_streamport);
	//  DDX_Text(pDX, IDC_EDIT_tap5_udp_alive_period, m_udp_alive_period);
	//  DDX_Text(pDX, IDC_EDIT_tap5_udp_port, m_udp_port);
	DDX_Text(pDX, IDC_EDIT_tap6_file_arrange, m_file_arrange);
	//  DDX_Text(pDX, IDC_EDIT_tap6_file_gathering_time, m_filie_gathering_time);
	DDX_Text(pDX, IDC_EDIT_tap6_file_send, m_file_send);
	//  DDX_Text(pDX, IDC_EDIT_tap6_fileserver_ip, m_sileserver_ip);
	DDX_Text(pDX, IDC_EDIT_tap6_fileserver_port, m_fileserver_port);
	DDX_Text(pDX, IDC_EDIT_tap6_ftp_id, m_ftp_id);
	DDX_Text(pDX, IDC_EDIT_tap6_ftp_passive, m_ftp_passive);
	DDX_Text(pDX, IDC_EDIT_tap6_ftp_pw, m_ftp_pw);
	DDX_Text(pDX, IDC_EDIT_tap6_ftp_subdir, m_ftp_subdir);
	DDX_Text(pDX, IDC_EDIT_tap6_transfer_format, m_transfer_format);
	DDX_Text(pDX, IDC_EDIT_tap6_transfer_mode, m_transfer_mode);
	DDX_Text(pDX, IDC_EDIT_tap6_transfer_sitecode, m_transfer_sitecode);
	DDX_Text(pDX, IDC_EDIT_tap6_transfer_sitecode_2, m_transfer_sitecode2);
	DDX_Text(pDX, IDC_EDIT_tap5_udp_alive_period, m_tap5_udp_alive_period);
	DDX_Text(pDX, IDC_EDIT_tap6_udp_alive_period, m_tap6_udp_alive_period);
	DDX_Text(pDX, IDC_EDIT_tap5_udp_port, m_tap5_udp_port);
	DDX_Text(pDX, IDC_EDIT_tap6_udp_port, m_tap6_udp_port);
	//  DDX_Text(pDX, IDC_EDIT_tap6_use_recog1, m_user_recog1);
	DDX_Text(pDX, IDC_EDIT_tap6_use_recog2, m_use_recog2);
	DDX_Text(pDX, IDC_EDIT_tap6_use_recog3, m_use_recog3);
	DDX_Text(pDX, IDC_EDIT_tap7_duration_sec, m_duration_sec);
	DDX_Text(pDX, IDC_EDIT_tap7_host_ip, m_host_ip);
	DDX_Text(pDX, IDC_EDIT_tap7_manageprogcount, m_manageprogcount);
	DDX_Text(pDX, IDC_EDIT_tap7_manageprogid_0, m_manageprogid_0);
	DDX_Text(pDX, IDC_EDIT_tap7_manageprogid_1, m_manageprogid_1);
	DDX_Text(pDX, IDC_EDIT_tap7_manageprogid_2, m_manageprogid_2);
	DDX_Text(pDX, IDC_EDIT_tap7_manageprogname_0, m_manageprogname_0);
	DDX_Text(pDX, IDC_EDIT_tap7_manageprogname_1, m_manageprogname_1);
	//  DDX_Text(pDX, IDC_EDIT_tap7_manageprogname_2, m_managerprogname_2);
	DDX_Text(pDX, IDC_EDIT_tap7_progname, m_progname);
	DDX_Text(pDX, IDC_EDIT_tap7_server_ip, m_server_ip);
	DDX_Text(pDX, IDC_EDIT_tap7_server_port, m_server_port);
	DDX_Text(pDX, IDC_EDIT_tap7_udp_bind_port, m_udp_bind_port);
	DDX_Text(pDX, IDC_EDIT_tap2_companyformat, m_companyformat);
	DDX_Text(pDX, IDC_EDIT_tap6_transfer_sitecode_2, m_transfer_sitecode_2);
	DDX_Text(pDX, IDC_EDIT_tap6_fileserver_ip, m_fileserver_ip);
	DDX_Text(pDX, IDC_EDIT_tap6_file_gathering_time, m_file_gathering_time);
	DDX_Text(pDX, IDC_EDIT_tap6_use_recog1, m_use_recog1);
	DDX_Text(pDX, IDC_EDIT_tap7_manageprogname_2, m_manageprogname_2);
	DDX_Control(pDX, IDC_TAB_AREA, m_tabarea);
}

BEGIN_MESSAGE_MAP(C_Argos_setting_12Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_read, &C_Argos_setting_12Dlg::OnBnClickedButtonread)
	ON_BN_CLICKED(IDC_BUTTON_write, &C_Argos_setting_12Dlg::OnBnClickedButtonwrite)
END_MESSAGE_MAP()


// C_Argos_setting_12Dlg 메시지 처리기

BOOL C_Argos_setting_12Dlg::OnInitDialog()
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
	LPSTR tabName[6] = {_T("[COMMON]"),_T("[SAVE]"),_T("[VIEW/ARGOS]"),_T("[STREAM]"),_T("[SENDER]"),_T("[MANAGER]")};
	for(int nIndex = 0;nIndex<6;nIndex++)
	{
		tabItem.mask = TCIF_TEXT;
		tabItem.pszText = tabName[nIndex];
		m_tabarea.InsertItem(nIndex, &tabItem);
	}

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void C_Argos_setting_12Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C_Argos_setting_12Dlg::OnPaint()
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
HCURSOR C_Argos_setting_12Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void C_Argos_setting_12Dlg::OnBnClickedButtonread()
{
	char programpath[_MAX_PATH];

	char site_code[100] = {0};
	char site_name[100] = {0};
	char triggermode[100] = {0};
	char readyq_count[100] = {0};
	char dispq_count[100] = {0};
	char time_expire_sec[100] = {0};
	char exposure_recogcount[100] = {0};
	char io_config_mode[100] = {0};
	char violationspeed[100] = {0};

	char savepath[100] = {0};
	char backup_path[100] = {0};
	char keep_store_days[100] = {0};
	char log_store_days[100] = {0};
	char savewidth[100] = {0};
	char saveheight[100] = {0};
	char companyformat[100] = {0};
	char insertplate[100] = {0};
	char sequenceimgcount[100] = {0};
	char saveformat[100] = {0};

	char tap3_width[100] = {0};
	char tap3_height[100] = {0};

	char tap4_width[100] = {0};
	char tap4_height[100] = {0};
	char platewidth[100] = {0};
	char plateheight[100] = {0};
	char platepositionbottom[100] = {0};
	char bitrate[100] = {0};
	char streamname[100] = {0};
	char streamport[100] = {0};

	char tap5_udp_port[100] = {0};
	char tap5_udp_alive_period[100] = {0};

	char fileserver_ip[100] = {0};
	char fileserver_port[100] = {0};
	char file_gathering_time[100] = {0};
	char tap6_udp_port[100] = {0};
	char tap6_udp_alive_period[100] = {0};
	char use_recog1[100] = {0};
	char use_recog2[100] = {0};
	char use_recog3[100] = {0};
	char file_send[100] = {0};
	char file_arrange[100] = {0};
	char ftp_id[100] = {0};
	char ftp_pw[100] = {0};
	char ftp_passive[100] = {0};
	char ftp_subdir[100] = {0};
	char transfer_mode[100] = {0};
	char transfer_format[100] = {0};
	char transfer_sitecode[100] = {0};
	char transfer_sitecode_2[100] = {0};

	char server_ip[100] = {0};
	char server_port[100] = {0};
	char host_ip[100] = {0};
	char udp_bind_port[100] = {0};
	char duration_sec[100] = {0};
	char progname[100] = {0};
	char manageprogcount[100] = {0};
	char manageprogid_0[100] = {0};
	char manageprogid_1[100] = {0};
	char manageprogid_2[100] = {0};
	char manageprogname_0[100] = {0};
	char manageprogname_1[100] = {0};
	char manageprogname_2[100] = {0};

	GetCurrentDirectory( _MAX_PATH, programpath);

	strcat_s(programpath,"\\setting.ini");

	GetPrivateProfileString("COMMON","site_code",NULL,site_code,sizeof(site_code),programpath);
	GetPrivateProfileString("COMMON","site_name",NULL,site_name,sizeof(site_name),programpath);
	GetPrivateProfileString("COMMON","TriggerMode",NULL,triggermode,sizeof(triggermode),programpath);
	GetPrivateProfileString("COMMON","ReadyQ_Count",NULL,readyq_count,sizeof(readyq_count),programpath);
	GetPrivateProfileString("COMMON","DispQ_Count",NULL,dispq_count,sizeof(dispq_count),programpath);
	GetPrivateProfileString("COMMON","time_expire_sec",NULL,time_expire_sec,sizeof(time_expire_sec),programpath);
	GetPrivateProfileString("COMMON","Exposure_RecogCount",NULL,exposure_recogcount,sizeof(exposure_recogcount),programpath);
	GetPrivateProfileString("COMMON","IO_Config_Mode",NULL,io_config_mode,sizeof(io_config_mode),programpath);
	GetPrivateProfileString("COMMON","ViolationSpeed",NULL,violationspeed,sizeof(violationspeed),programpath);

	GetPrivateProfileString("SAVE","SavePath",NULL,savepath,sizeof(savepath),programpath);
	GetPrivateProfileString("SAVE","backup_path",NULL,backup_path,sizeof(backup_path),programpath);
	GetPrivateProfileString("SAVE","keep_store_days",NULL,keep_store_days,sizeof(keep_store_days),programpath);
	GetPrivateProfileString("SAVE","log_store_days",NULL,log_store_days,sizeof(log_store_days),programpath);
	GetPrivateProfileString("SAVE","SaveWidth",NULL,savewidth,sizeof(savewidth),programpath);
	GetPrivateProfileString("SAVE","SaveHeight",NULL,saveheight,sizeof(saveheight),programpath);
	GetPrivateProfileString("SAVE","CompanyFormat",NULL,companyformat,sizeof(companyformat),programpath);
	GetPrivateProfileString("SAVE","InsertPlate",NULL,insertplate,sizeof(insertplate),programpath);
	GetPrivateProfileString("SAVE","SequenceImgCount",NULL,sequenceimgcount,sizeof(sequenceimgcount),programpath);
	GetPrivateProfileString("SAVE","SaveFormat",NULL,saveformat,sizeof(saveformat),programpath);

	GetPrivateProfileString("VIEW","Width",NULL,tap3_width,sizeof(tap3_width),programpath);
	GetPrivateProfileString("VIEW","Height",NULL,tap3_height,sizeof(tap3_height),programpath);

	GetPrivateProfileString("STREAM","Width",NULL,tap4_width,sizeof(tap4_width),programpath);
	GetPrivateProfileString("STREAM","Height",NULL,tap4_height,sizeof(tap4_height),programpath);
	GetPrivateProfileString("STREAM","PlateWidth",NULL,platewidth,sizeof(platewidth),programpath);
	GetPrivateProfileString("STREAM","PlateHeight",NULL,plateheight,sizeof(plateheight),programpath);
	GetPrivateProfileString("STREAM","PlatePositionBottom",NULL,platepositionbottom,sizeof(platepositionbottom),programpath);
	GetPrivateProfileString("STREAM","bitrate",NULL,bitrate,sizeof(bitrate),programpath);
	GetPrivateProfileString("STREAM","StreamName",NULL,streamname,sizeof(streamname),programpath);
	GetPrivateProfileString("STREAM","StreamPort",NULL,streamport,sizeof(streamport),programpath);

	GetPrivateProfileString("ARGOS","udp_port",NULL,tap5_udp_port,sizeof(tap5_udp_port),programpath);
	GetPrivateProfileString("ARGOS","udp_alive_period",NULL,tap5_udp_alive_period,sizeof(tap5_udp_alive_period),programpath);

	GetPrivateProfileString("SENDER","fileserver_ip",NULL,fileserver_ip,sizeof(fileserver_ip),programpath);
	GetPrivateProfileString("SENDER","fileserver_port",NULL,fileserver_port,sizeof(fileserver_port),programpath);
	GetPrivateProfileString("SENDER","file_gathering_time",NULL,file_gathering_time,sizeof(file_gathering_time),programpath);
	GetPrivateProfileString("SENDER","udp_port",NULL,tap6_udp_port,sizeof(tap6_udp_port),programpath);
	GetPrivateProfileString("SENDER","udp_alive_period",NULL,tap6_udp_alive_period,sizeof(tap6_udp_alive_period),programpath);
	GetPrivateProfileString("SENDER","use_recog1",NULL,use_recog1,sizeof(use_recog1),programpath);
	GetPrivateProfileString("SENDER","use_recog2",NULL,use_recog2,sizeof(use_recog2),programpath);
	GetPrivateProfileString("SENDER","use_recog3",NULL,use_recog3,sizeof(use_recog3),programpath);
	GetPrivateProfileString("SENDER","file_send",NULL,file_send,sizeof(file_send),programpath);
	GetPrivateProfileString("SENDER","file_arrange",NULL,file_arrange,sizeof(file_arrange),programpath);
	GetPrivateProfileString("SENDER","ftp_id",NULL,ftp_id,sizeof(ftp_id),programpath);
	GetPrivateProfileString("SENDER","ftp_pw",NULL,ftp_pw,sizeof(ftp_pw),programpath);
	GetPrivateProfileString("SENDER","ftp_passive",NULL,ftp_passive,sizeof(ftp_passive),programpath);
	GetPrivateProfileString("SENDER","ftp_subdir",NULL,ftp_subdir,sizeof(ftp_subdir),programpath);
	GetPrivateProfileString("SENDER","ftp_subdir",NULL,ftp_subdir,sizeof(ftp_subdir),programpath);
	GetPrivateProfileString("SENDER","transfer_mode",NULL,transfer_mode,sizeof(transfer_mode),programpath);
	GetPrivateProfileString("SENDER","transfer_format",NULL,transfer_format,sizeof(transfer_format),programpath);
	GetPrivateProfileString("SENDER","transfer_sitecode",NULL,transfer_sitecode,sizeof(transfer_sitecode),programpath);
	GetPrivateProfileString("SENDER","transfer_sitecode_2",NULL,transfer_sitecode_2,sizeof(transfer_sitecode_2),programpath);

	GetPrivateProfileString("MANAGER","server_ip",NULL,server_ip,sizeof(server_ip),programpath);
	GetPrivateProfileString("MANAGER","server_port",NULL,server_port,sizeof(server_port),programpath);
	GetPrivateProfileString("MANAGER","host_ip",NULL,host_ip,sizeof(host_ip),programpath);
	GetPrivateProfileString("MANAGER","udp_bind_port",NULL,udp_bind_port,sizeof(udp_bind_port),programpath);
	GetPrivateProfileString("MANAGER","Duration_Sec",NULL,duration_sec,sizeof(duration_sec),programpath);
	GetPrivateProfileString("MANAGER","ProgName",NULL,progname,sizeof(progname),programpath);
	GetPrivateProfileString("MANAGER","ManageProgCount",NULL,manageprogcount,sizeof(manageprogcount),programpath);
	GetPrivateProfileString("MANAGER","ManageProgID_0",NULL,manageprogid_0,sizeof(manageprogid_0),programpath);
	GetPrivateProfileString("MANAGER","ManageProgID_1",NULL,manageprogid_1,sizeof(manageprogid_1),programpath);
	GetPrivateProfileString("MANAGER","ManageProgID_2",NULL,manageprogid_2,sizeof(manageprogid_2),programpath);
	GetPrivateProfileString("MANAGER","ManageProgName_0",NULL,manageprogname_0,sizeof(manageprogname_0),programpath);

	GetDlgItem(IDC_EDIT_tap1_site_code)->SetWindowText(site_code);
	GetDlgItem(IDC_EDIT_tap1_site_name)->SetWindowText(site_name);
	GetDlgItem(IDC_EDIT_tap1_triggermode)->SetWindowText(triggermode);
	GetDlgItem(IDC_EDIT_tap1_readyq_count)->SetWindowText(readyq_count);
	GetDlgItem(IDC_EDIT_tap1_dispq_count)->SetWindowText(dispq_count);
	GetDlgItem(IDC_EDIT_tap1_time_expire_sec)->SetWindowText(time_expire_sec);
	GetDlgItem(IDC_EDIT_tap1_exposure_recogcount)->SetWindowText(exposure_recogcount);
	GetDlgItem(IDC_EDIT_tap1_io_config_mode)->SetWindowText(io_config_mode);
	GetDlgItem(IDC_EDIT_tap1_violationspeed)->SetWindowText(violationspeed);

	GetDlgItem(IDC_EDIT_tap2_savepath)->SetWindowText(savepath);
	GetDlgItem(IDC_EDIT_tap2_backup_path)->SetWindowText(backup_path);
	GetDlgItem(IDC_EDIT_tap2_keep_store_days)->SetWindowText(keep_store_days);
	GetDlgItem(IDC_EDIT_tap2_log_store_days)->SetWindowText(log_store_days);
	GetDlgItem(IDC_EDIT_tap2_savewidth)->SetWindowText(savewidth);
	GetDlgItem(IDC_EDIT_tap2_saveheight)->SetWindowText(saveheight);
	GetDlgItem(IDC_EDIT_tap2_companyformat)->SetWindowText(companyformat);
	GetDlgItem(IDC_EDIT_tap2_insertplate)->SetWindowText(insertplate);
	GetDlgItem(IDC_EDIT_tap2_sequenceimgcount)->SetWindowText(sequenceimgcount);
	GetDlgItem(IDC_EDIT_tap2_saveformat)->SetWindowText(saveformat);
	
	GetDlgItem(IDC_EDIT_tap3_width)->SetWindowText(tap3_width);
	GetDlgItem(IDC_EDIT_tap3_height)->SetWindowText(tap3_height);
	
	GetDlgItem(IDC_EDIT_tap4_width)->SetWindowText(tap4_width);
	GetDlgItem(IDC_EDIT_tap4_height)->SetWindowText(tap4_height);
	GetDlgItem(IDC_EDIT_tap4_platewidth)->SetWindowText(platewidth);
	GetDlgItem(IDC_EDIT_tap4_plateheight)->SetWindowText(plateheight);
	GetDlgItem(IDC_EDIT_tap4_platepositionbottom)->SetWindowText(platepositionbottom);
	GetDlgItem(IDC_EDIT_tap4_bitrate)->SetWindowText(bitrate);
	GetDlgItem(IDC_EDIT_tap4_streamname)->SetWindowText(streamname);
	GetDlgItem(IDC_EDIT_tap4_streamport)->SetWindowText(streamport);

	GetDlgItem(IDC_EDIT_tap5_udp_port)->SetWindowText(tap5_udp_port);
	GetDlgItem(IDC_EDIT_tap5_udp_alive_period)->SetWindowText(tap5_udp_alive_period);

	GetDlgItem(IDC_EDIT_tap6_fileserver_ip)->SetWindowText(fileserver_ip);
	GetDlgItem(IDC_EDIT_tap6_fileserver_port)->SetWindowText(fileserver_port);
	GetDlgItem(IDC_EDIT_tap6_file_gathering_time)->SetWindowText(file_gathering_time);
	GetDlgItem(IDC_EDIT_tap6_udp_port)->SetWindowText(tap6_udp_port);
	GetDlgItem(IDC_EDIT_tap6_udp_alive_period)->SetWindowText(tap6_udp_alive_period);
	GetDlgItem(IDC_EDIT_tap6_use_recog1)->SetWindowText(use_recog1);
	GetDlgItem(IDC_EDIT_tap6_use_recog2)->SetWindowText(use_recog2);
	GetDlgItem(IDC_EDIT_tap6_use_recog3)->SetWindowText(use_recog3);
	GetDlgItem(IDC_EDIT_tap6_file_send)->SetWindowText(file_send);
	GetDlgItem(IDC_EDIT_tap6_file_arrange)->SetWindowText(file_arrange);
	GetDlgItem(IDC_EDIT_tap6_ftp_id)->SetWindowText(ftp_id);
	GetDlgItem(IDC_EDIT_tap6_ftp_pw)->SetWindowText(ftp_pw);
	GetDlgItem(IDC_EDIT_tap6_ftp_passive)->SetWindowText(ftp_passive);
	GetDlgItem(IDC_EDIT_tap6_ftp_subdir)->SetWindowText(ftp_subdir);
	GetDlgItem(IDC_EDIT_tap6_transfer_mode)->SetWindowText(transfer_mode);
	GetDlgItem(IDC_EDIT_tap6_transfer_format)->SetWindowText(transfer_format);
	GetDlgItem(IDC_EDIT_tap6_transfer_sitecode)->SetWindowText(transfer_sitecode);
	GetDlgItem(IDC_EDIT_tap6_transfer_sitecode_2)->SetWindowText(transfer_sitecode_2);

	GetDlgItem(IDC_EDIT_tap7_server_ip)->SetWindowText(server_ip);
	GetDlgItem(IDC_EDIT_tap7_server_port)->SetWindowText(server_port);
	GetDlgItem(IDC_EDIT_tap7_host_ip)->SetWindowText(host_ip);
	GetDlgItem(IDC_EDIT_tap7_udp_bind_port)->SetWindowText(udp_bind_port);
	GetDlgItem(IDC_EDIT_tap7_duration_sec)->SetWindowText(duration_sec);
	GetDlgItem(IDC_EDIT_tap7_progname)->SetWindowText(progname);
	GetDlgItem(IDC_EDIT_tap7_manageprogcount)->SetWindowText(manageprogcount);
	GetDlgItem(IDC_EDIT_tap7_manageprogid_0)->SetWindowText(manageprogid_0);
	GetDlgItem(IDC_EDIT_tap7_manageprogid_1)->SetWindowText(manageprogid_1);
	GetDlgItem(IDC_EDIT_tap7_manageprogid_2)->SetWindowText(manageprogid_2);
}


void C_Argos_setting_12Dlg::OnBnClickedButtonwrite()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	char programpath[_MAX_PATH];

	char site_code[100] = {0};
	char site_name[100] = {0};
	char triggermode[100] = {0};
	char readyq_count[100] = {0};
	char dispq_count[100] = {0};
	char time_expire_sec[100] = {0};
	char exposure_recogcount[100] = {0};
	char io_config_mode[100] = {0};
	char violationspeed[100] = {0};

	char savepath[100] = {0};
	char backup_path[100] = {0};
	char keep_store_days[100] = {0};
	char log_store_days[100] = {0};
	char savewidth[100] = {0};
	char saveheight[100] = {0};
	char companyformat[100] = {0};
	char insertplate[100] = {0};
	char sequenceimgcount[100] = {0};
	char saveformat[100] = {0};

	char tap3_width[100] = {0};
	char tap3_height[100] = {0};

	char tap4_width[100] = {0};
	char tap4_height[100] = {0};
	char platewidth[100] = {0};
	char plateheight[100] = {0};
	char platepositionbottom[100] = {0};
	char bitrate[100] = {0};
	char streamname[100] = {0};
	char streamport[100] = {0};

	char tap5_udp_port[100] = {0};
	char tap5_udp_alive_period[100] = {0};

	char fileserver_ip[100] = {0};
	char fileserver_port[100] = {0};
	char file_gathering_time[100] = {0};
	char tap6_udp_port[100] = {0};
	char tap6_udp_alive_period[100] = {0};
	char use_recog1[100] = {0};
	char use_recog2[100] = {0};
	char use_recog3[100] = {0};
	char file_send[100] = {0};
	char file_arrange[100] = {0};
	char ftp_id[100] = {0};
	char ftp_pw[100] = {0};
	char ftp_passive[100] = {0};
	char ftp_subdir[100] = {0};
	char transfer_mode[100] = {0};
	char transfer_format[100] = {0};
	char transfer_sitecode[100] = {0};
	char transfer_sitecode_2[100] = {0};

	char server_ip[100] = {0};
	char server_port[100] = {0};
	char host_ip[100] = {0};
	char udp_bind_port[100] = {0};
	char duration_sec[100] = {0};
	char progname[100] = {0};
	char manageprogcount[100] = {0};
	char manageprogid_0[100] = {0};
	char manageprogid_1[100] = {0};
	char manageprogid_2[100] = {0};
	char manageprogname_0[100] = {0};
	char manageprogname_1[100] = {0};
	char manageprogname_2[100] = {0};

	
	UpdateData(TRUE);

	GetCurrentDirectory( _MAX_PATH, programpath);
	
	strcat_s(programpath,"\\setting.ini");

	strcpy_s(site_code,m_site_code);
	strcpy_s(site_name,m_site_name);
	strcpy_s(triggermode,m_triggermode);
	strcpy_s(readyq_count,m_readyq_count);
	strcpy_s(dispq_count,m_dispq_count);
	strcpy_s(time_expire_sec,m_time_expire_sec);
	strcpy_s(exposure_recogcount,m_exposure_recogcount);
	strcpy_s(io_config_mode,m_io_config_mode);
	strcpy_s(violationspeed,m_violationspeed);

	strcpy_s(savepath,m_savepath);
	strcpy_s(backup_path,m_savepath);
	strcpy_s(keep_store_days,m_keep_store_days);
	strcpy_s(log_store_days,m_log_store_days);
	strcpy_s(savewidth,m_savewidth);
	strcpy_s(saveheight,m_saveheight);
	strcpy_s(companyformat,m_companyformat);
	strcpy_s(insertplate,m_insertplate);
	strcpy_s(sequenceimgcount,m_sequenceimgcount);
	strcpy_s(saveformat,m_saveformat);

	strcpy_s(tap3_width,m_tap3_width);
	strcpy_s(tap3_height,m_tap3_height);

	strcpy_s(tap4_width,m_tap4_width);
	strcpy_s(tap4_height,m_tap4_height);
	strcpy_s(platewidth,m_platewidth);
	strcpy_s(plateheight,m_plateheight);
	strcpy_s(platepositionbottom,m_platepositionbottom);
	strcpy_s(bitrate,m_bitrate);
	strcpy_s(streamname,m_streamname);
	strcpy_s(streamport,m_streamport);

	strcpy_s(tap5_udp_port,m_tap5_udp_port);
	strcpy_s(tap5_udp_alive_period,m_tap5_udp_alive_period);

	strcpy_s(fileserver_ip,m_fileserver_ip);
	strcpy_s(fileserver_port,m_fileserver_port);
	strcpy_s(file_gathering_time,m_file_gathering_time);
	strcpy_s(tap6_udp_port,m_tap6_udp_port);
	strcpy_s(tap6_udp_alive_period,m_tap6_udp_alive_period);
	strcpy_s(use_recog1,m_use_recog1);
	strcpy_s(use_recog2,m_use_recog2);
	strcpy_s(use_recog3,m_use_recog3);
	strcpy_s(file_send,m_file_send);
	strcpy_s(file_arrange,m_file_arrange);
	strcpy_s(ftp_id,m_ftp_id);
	strcpy_s(ftp_pw,m_ftp_pw);
	strcpy_s(ftp_passive,m_ftp_passive);
	strcpy_s(ftp_subdir,m_ftp_subdir);
	strcpy_s(transfer_mode,m_transfer_mode);
	strcpy_s(transfer_format,m_transfer_format);
	strcpy_s(transfer_sitecode,m_transfer_sitecode);
	strcpy_s(transfer_sitecode_2,m_transfer_sitecode_2);
	strcpy_s(transfer_sitecode_2,m_transfer_sitecode_2);

	strcpy_s(server_ip,m_server_ip);
	strcpy_s(server_port,m_server_port);
	strcpy_s(host_ip,m_host_ip);
	strcpy_s(duration_sec,m_duration_sec);
	strcpy_s(progname,m_progname);
	strcpy_s(manageprogcount,m_manageprogcount);
	strcpy_s(manageprogid_0,m_manageprogid_0);
	strcpy_s(manageprogid_1,m_manageprogid_1);
	strcpy_s(manageprogid_2,m_manageprogid_2);
	strcpy_s(manageprogname_0,m_manageprogname_0);
	strcpy_s(manageprogname_1,m_manageprogname_1);
	strcpy_s(manageprogname_2,m_manageprogname_2);

	WritePrivateProfileString("COMMON","site_code",site_code,programpath);
	WritePrivateProfileString("COMMON","site_name",site_name,programpath);
	WritePrivateProfileString("COMMON","TriggerMode",triggermode,programpath);
	WritePrivateProfileString("COMMON","ReadyQ_Count",readyq_count,programpath);
	WritePrivateProfileString("COMMON","DispQ_Count",dispq_count,programpath);
	WritePrivateProfileString("COMMON","time_expire_sec",time_expire_sec,programpath);
	WritePrivateProfileString("COMMON","Exposure_RecogCount",exposure_recogcount,programpath);
	WritePrivateProfileString("COMMON","IO_Config_Mode",io_config_mode,programpath);
	WritePrivateProfileString("COMMON","ViolationSpeed",violationspeed,programpath);

	WritePrivateProfileString("SAVE","SavePath",savepath,programpath);
	WritePrivateProfileString("SAVE","backup_path",backup_path,programpath);
	WritePrivateProfileString("SAVE","keep_store_days",keep_store_days,programpath);
	WritePrivateProfileString("SAVE","log_store_days",log_store_days,programpath);
	WritePrivateProfileString("SAVE","SaveWidth",savewidth,programpath);
	WritePrivateProfileString("SAVE","SaveHeight",saveheight,programpath);
	WritePrivateProfileString("SAVE","CompanyFormat",companyformat,programpath);
	WritePrivateProfileString("SAVE","InsertPlate",insertplate,programpath);
	WritePrivateProfileString("SAVE","SequenceImgCount",sequenceimgcount,programpath);
	WritePrivateProfileString("SAVE","SaveFormat",saveformat,programpath);

	WritePrivateProfileString("VIEW","Width",tap3_width,programpath);
	WritePrivateProfileString("VIEW","Height",tap3_height,programpath);

	WritePrivateProfileString("STREAM","Width",tap4_width,programpath);
	WritePrivateProfileString("STREAM","Height",tap4_height,programpath);
	WritePrivateProfileString("STREAM","PlateWidth",platewidth,programpath);
	WritePrivateProfileString("STREAM","PlateHeight",plateheight,programpath);
	WritePrivateProfileString("STREAM","PlatePositionBottom",platepositionbottom,programpath);
	WritePrivateProfileString("STREAM","bitrate",bitrate,programpath);
	WritePrivateProfileString("STREAM","StreamName",streamname,programpath);
	WritePrivateProfileString("STREAM","StreamPort",streamport,programpath);

	WritePrivateProfileString("ARGOS","udp_port",tap5_udp_port,programpath);
	WritePrivateProfileString("ARGOS","udp_alive_period",tap5_udp_alive_period,programpath);

	WritePrivateProfileString("SENDER","fileserver_ip",fileserver_ip,programpath);
	WritePrivateProfileString("SENDER","fileserver_port",fileserver_port,programpath);
	WritePrivateProfileString("SENDER","file_gathering_time",file_gathering_time,programpath);
	WritePrivateProfileString("SENDER","udp_port",tap6_udp_port,programpath);
	WritePrivateProfileString("SENDER","udp_alive_period",tap6_udp_alive_period,programpath);
	WritePrivateProfileString("SENDER","use_recog1",use_recog1,programpath);
	WritePrivateProfileString("SENDER","use_recog2",use_recog2,programpath);
	WritePrivateProfileString("SENDER","use_recog3",use_recog3,programpath);
	WritePrivateProfileString("SENDER","file_send",file_send,programpath);
	WritePrivateProfileString("SENDER","file_arrange",file_arrange,programpath);
	WritePrivateProfileString("SENDER","ftp_id",ftp_id,programpath);
	WritePrivateProfileString("SENDER","ftp_pw",ftp_pw,programpath);
	WritePrivateProfileString("SENDER","ftp_passive",ftp_passive,programpath);
	WritePrivateProfileString("SENDER","ftp_subdir",ftp_subdir,programpath);
	WritePrivateProfileString("SENDER","ftp_subdir",ftp_subdir,programpath);
	WritePrivateProfileString("SENDER","transfer_mode",transfer_mode,programpath);
	WritePrivateProfileString("SENDER","transfer_format",transfer_format,programpath);
	WritePrivateProfileString("SENDER","transfer_sitecode",transfer_sitecode,programpath);
	WritePrivateProfileString("SENDER","transfer_sitecode_2",transfer_sitecode_2,programpath);

	WritePrivateProfileString("MANAGER","server_ip",server_ip,programpath);
	WritePrivateProfileString("MANAGER","server_port",server_port,programpath);
	WritePrivateProfileString("MANAGER","host_ip",host_ip,programpath);
	WritePrivateProfileString("MANAGER","udp_bind_port",udp_bind_port,programpath);
	WritePrivateProfileString("MANAGER","Duration_Sec",duration_sec,programpath);
	WritePrivateProfileString("MANAGER","ProgName",progname,programpath);
	WritePrivateProfileString("MANAGER","ManageProgCount",manageprogcount,programpath);
	WritePrivateProfileString("MANAGER","ManageProgID_0",manageprogid_0,programpath);
	WritePrivateProfileString("MANAGER","ManageProgID_1",manageprogid_1,programpath);
	WritePrivateProfileString("MANAGER","ManageProgID_2",manageprogid_2,programpath);
	WritePrivateProfileString("MANAGER","ManageProgName_0",manageprogname_0,programpath);
	UpdateData(FALSE);
}

