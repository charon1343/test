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
	DDX_Control(pDX, IDC_CHECK5, m_DontCare);
	DDX_Control(pDX, IDC_CHECK6, m_DarkToLight);
	DDX_Control(pDX, IDC_CHECK7, m_LightToDark);
}


BEGIN_MESSAGE_MAP(Polarity, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &Polarity::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON7, &Polarity::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON1, &Polarity::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &Polarity::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &Polarity::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_CHECK5, &Polarity::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_CHECK6, &Polarity::OnBnClickedCheck6)
	ON_BN_CLICKED(IDC_CHECK7, &Polarity::OnBnClickedCheck7)
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
}


void Polarity::OnBnClickedButton4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void Polarity::OnBnClickedButton5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_nValue = 3;
}


void Polarity::OnBnClickedCheck5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_nValue = 1;
	m_DontCare.SetCheck(true,false);
	m_DarkToLight.SetCheck(false);
	m_LightToDark.SetCheck(false);
}


void Polarity::OnBnClickedCheck6()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_nValue = 2;
	m_DontCare.SetCheck(false);
	m_DarkToLight.SetCheck(true,false);
	m_LightToDark.SetCheck(false);

}


void Polarity::OnBnClickedCheck7()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_nValue = 3;
	m_DontCare.SetCheck(false);
	m_DarkToLight.SetCheck(false);
	m_LightToDark.SetCheck(true,false);
}
