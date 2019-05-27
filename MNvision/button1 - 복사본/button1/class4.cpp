// class4.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "button1.h"
#include "class4.h"
#include "afxdialogex.h"


// class4 대화 상자입니다.

IMPLEMENT_DYNAMIC(class4, CDialogEx)

class4::class4(CWnd* pParent /*=NULL*/)
	: CDialogEx(class4::IDD, pParent)
{

}

class4::~class4()
{
}

void class4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(class4, CDialogEx)
END_MESSAGE_MAP()


// class4 메시지 처리기입니다.
