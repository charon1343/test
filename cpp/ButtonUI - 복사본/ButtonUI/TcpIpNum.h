#pragma once
#include "MNVButton.h"

// TcpIpNum 대화 상자입니다.

class TcpIpNum : public CDialogEx
{
	DECLARE_DYNAMIC(TcpIpNum)

public:
	TcpIpNum(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~TcpIpNum();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_TCPIPNUM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedIpaddress();
	afx_msg void OnBnClickedIpaddressvalue();
	afx_msg void OnBnClickedPortnum();
	afx_msg void OnBnClickedPortnumvalue();
	afx_msg void OnBnClickedTcpipconnect();
	CMNVButton m_ipaddress;
	CMNVButton m_ipaddressValue;
	CMNVButton m_portNum;
	CMNVButton m_portNumValue;
	CMNVButton m_tcpIpConnect;
	void On_WindTopPos(void);
	virtual BOOL OnInitDialog();
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
};
