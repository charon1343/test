// Polarity.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "button1.h"
#include "Polarity.h"
#include "afxdialogex.h"


// Polarity ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(Polarity, CDialogEx)

Polarity::Polarity(CWnd* pParent /*=NULL*/)
	: CDialogEx(Polarity::IDD, pParent)
{

}

Polarity::~Polarity()
{
}

void Polarity::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Polarity, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &Polarity::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON7, &Polarity::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON1, &Polarity::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &Polarity::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &Polarity::OnBnClickedButton5)
END_MESSAGE_MAP()


// Polarity �޽��� ó�����Դϴ�.


void Polarity::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}


void Polarity::OnBnClickedButton7()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	OnCancel();
}


void Polarity::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_nValue = 1;
}


void Polarity::OnBnClickedButton4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_nValue = 2;
}


void Polarity::OnBnClickedButton5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_nValue = 3;
}
