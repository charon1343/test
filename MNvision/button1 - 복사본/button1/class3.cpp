// class3.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "button1.h"
#include "class3.h"
#include "afxdialogex.h"


// class3 대화 상자입니다.

IMPLEMENT_DYNAMIC(class3, CDialogEx)

class3::class3(CWnd* pParent /*=NULL*/)
	: CDialogEx(class3::IDD, pParent)
{

}

class3::~class3()
{
}

void class3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(class3, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &class3::OnBnClickedButton1)
END_MESSAGE_MAP()


// class3 메시지 처리기입니다.


void class3::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
}
