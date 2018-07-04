// class1.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "button1.h"
#include "class1.h"
#include "afxdialogex.h"


// class1 대화 상자입니다.

IMPLEMENT_DYNAMIC(class1, CDialogEx)

class1::class1(CWnd* pParent /*=NULL*/)
	: CDialogEx(class1::IDD, pParent)
{

}

class1::~class1()
{
}

void class1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(class1, CDialogEx)
END_MESSAGE_MAP()


// class1 메시지 처리기입니다.
