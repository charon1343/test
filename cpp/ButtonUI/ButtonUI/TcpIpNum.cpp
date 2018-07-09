// TcpIpNum.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ButtonUI.h"
#include "TcpIpNum.h"
#include "afxdialogex.h"


// TcpIpNum ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(TcpIpNum, CDialogEx)

TcpIpNum::TcpIpNum(CWnd* pParent /*=NULL*/)
	: CDialogEx(TcpIpNum::IDD, pParent)
{

}

TcpIpNum::~TcpIpNum()
{
}

void TcpIpNum::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IPAddress, m_ipaddress);
	DDX_Control(pDX, IDC_IPAddressValue, m_ipaddressValue);
	DDX_Control(pDX, IDC_PortNum, m_portNum);
	DDX_Control(pDX, IDC_PortNumValue, m_portNumValue);
	DDX_Control(pDX, IDC_TCPIPConnect, m_tcpIpConnect);
}


BEGIN_MESSAGE_MAP(TcpIpNum, CDialogEx)
	ON_BN_CLICKED(IDC_IPAddress, &TcpIpNum::OnBnClickedIpaddress)
	ON_BN_CLICKED(IDC_IPAddressValue, &TcpIpNum::OnBnClickedIpaddressvalue)
	ON_BN_CLICKED(IDC_PortNum, &TcpIpNum::OnBnClickedPortnum)
	ON_BN_CLICKED(IDC_PortNumValue, &TcpIpNum::OnBnClickedPortnumvalue)
	ON_BN_CLICKED(IDC_TCPIPConnect, &TcpIpNum::OnBnClickedTcpipconnect)
	ON_WM_WINDOWPOSCHANGED()
END_MESSAGE_MAP()


// TcpIpNum �޽��� ó�����Դϴ�.
	



void TcpIpNum::OnBnClickedIpaddress()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void TcpIpNum::OnBnClickedIpaddressvalue()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void TcpIpNum::OnBnClickedPortnum()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void TcpIpNum::OnBnClickedPortnumvalue()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void TcpIpNum::OnBnClickedTcpipconnect()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void TcpIpNum::On_WindTopPos(void)
{
	CRect rctTop;
	GetClientRect(&rctTop);
	rctTop.top += 5;
	rctTop.left += 5;
	rctTop.bottom -= 5;
	rctTop.right -= 5;

	CRect rctTab = rctTop;

	int nWidth = (rctTop.Width() + 1) / 6;

	rctTab.bottom = rctTop.top+rctTop.Height()*0.5 -1;
	rctTab.right = rctTop.left+nWidth;
	m_ipaddress.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth*2;
	m_ipaddressValue.SetWindowPos(rctTab);

	CRect rctSub = rctTab;

	rctSub.left = rctTab.right+1;
	rctSub.right = rctSub.left+nWidth*3;
	rctSub.top = rctTab.bottom + 1;
	rctSub.bottom = rctSub.top +rctTop.Height()*0.5 -1;
	m_tcpIpConnect.SetWindowPos(rctSub);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_portNum.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth*2;
	m_portNumValue.SetWindowPos(rctTab);
}


BOOL TcpIpNum::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	On_WindTopPos();
	m_tcpIpConnect.SetWindowTextW(_T("Connect"));

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void TcpIpNum::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if ((lpwndpos->flags & SWP_NOSIZE) == 0) { On_WindTopPos();}
}
