// TcpIpNum.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ButtonUI.h"
#include "TcpIpNum.h"
#include "afxdialogex.h"


// TcpIpNum 대화 상자입니다.

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


// TcpIpNum 메시지 처리기입니다.
	



void TcpIpNum::OnBnClickedIpaddress()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void TcpIpNum::OnBnClickedIpaddressvalue()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void TcpIpNum::OnBnClickedPortnum()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void TcpIpNum::OnBnClickedPortnumvalue()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void TcpIpNum::OnBnClickedTcpipconnect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	On_WindTopPos();
	m_tcpIpConnect.SetWindowTextW(_T("Connect"));

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void TcpIpNum::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if ((lpwndpos->flags & SWP_NOSIZE) == 0) { On_WindTopPos();}
}
