#pragma once
#include "MNVButton.h"

// TcpIpNum ��ȭ �����Դϴ�.

class TcpIpNum : public CDialogEx
{
	DECLARE_DYNAMIC(TcpIpNum)

public:
	TcpIpNum(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~TcpIpNum();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TCPIPNUM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
