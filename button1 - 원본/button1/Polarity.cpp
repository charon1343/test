// Polarity.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "button1.h"
#include "Polarity.h"
#include "afxdialogex.h"


// Polarity 대화 상자입니다.

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


// Polarity 메시지 처리기입니다.


void Polarity::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}


void Polarity::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	OnCancel();
}


void Polarity::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_nValue = 1;
}


void Polarity::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_nValue = 2;
}


void Polarity::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_nValue = 3;
}
