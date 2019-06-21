
// _Argos_setting_12Dlg.h : 헤더 파일
//

#pragma once


// C_Argos_setting_12Dlg 대화 상자
class C_Argos_setting_12Dlg : public CDialogEx
{
// 생성입니다.
public:
	C_Argos_setting_12Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD__ARGOS_SETTING_12_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_dispq_count;
	CString m_exposure_recogcount;
	CString m_io_config_mode;
	CString m_readyq_count;
	CString m_site_code;
	CString m_site_name;
	CString m_time_expire_sec;
	CString m_triggermode;
	CString m_violationspeed;
	CString m_backup_path;
	CString m_insertplate;
	CString m_keep_store_days;
	CString m_log_store_days;
	CString m_saveheight;
	CString m_savepath;
	CString m_savewidth;
	CString m_sequenceimgcount;
	CString m_saveformat;
//	CString m_height;
//	CString m_width;
	CString m_tap3_height;
	CString m_tap3_width;
	CString m_bitrate;
	CString m_tap4_height;
	CString m_tap4_width;
	CString m_plateheight;
	CString m_platepositionbottom;
	CString m_platewidth;
	CString m_streamname;
	CString m_streamport;
//	CString m_udp_alive_period;
//	CString m_udp_port;
	CString m_file_arrange;
//	CString m_filie_gathering_time;
	CString m_file_send;
//	CString m_sileserver_ip;
	CString m_fileserver_port;
	CString m_ftp_id;
	CString m_ftp_passive;
	CString m_ftp_pw;
	CString m_ftp_subdir;
	CString m_transfer_format;
	CString m_transfer_mode;
	CString m_transfer_sitecode;
	CString m_transfer_sitecode2;
	CString m_tap5_udp_alive_period;
	CString m_tap6_udp_alive_period;
	CString m_tap5_udp_port;
	CString m_tap6_udp_port;
//	CString m_user_recog1;
	CString m_use_recog2;
	CString m_use_recog3;
	CString m_duration_sec;
	CString m_host_ip;
	CString m_manageprogcount;
	CString m_manageprogid_0;
	CString m_manageprogid_1;
	CString m_manageprogid_2;
	CString m_manageprogname_0;
	CString m_manageprogname_1;
//	CString m_managerprogname_2;
	CString m_progname;
	CString m_server_ip;
	CString m_server_port;
	CString m_udp_bind_port;
	
	CString m_companyformat;
	CString m_transfer_sitecode_2;
	afx_msg void OnBnClickedButtonread();
	afx_msg void OnBnClickedButtonwrite();
	CString m_fileserver_ip;
	CString m_file_gathering_time;
	CString m_use_recog1;
	CString m_manageprogname_2;
	CTabCtrl m_tabarea;
};
