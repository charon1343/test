// Progress.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFC_TEST1.h"
#include "Progress.h"
#include "afxdialogex.h"


// Progress ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(Progress, CDialogEx)

Progress::Progress(CWnd* pParent /*=NULL*/)
	: CDialogEx(Progress::IDD, pParent)
{

}

Progress::~Progress()
{
}

void Progress::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_button1);
	DDX_Control(pDX, IDC_BUTTON2, m_button2);
	DDX_Control(pDX, IDC_PROGRESS1, m_progress1);
}


BEGIN_MESSAGE_MAP(Progress, CDialogEx)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_PROGRESS1, &Progress::OnNMCustomdrawProgress1)
	ON_BN_CLICKED(IDC_BUTTON1, &Progress::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Progress::OnBnClickedButton2)
END_MESSAGE_MAP()


// Progress �޽��� ó�����Դϴ�.


void Progress::OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}


void Progress::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_progress1.SetRange(0,255);
	m_progress1.SetStep(1);

	for(int a=0; a<255; a++)
	{
		m_progress1.StepIt();
		Sleep(100);
	}
}


void Progress::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}