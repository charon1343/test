// class5.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "button1.h"
#include "class5.h"
#include "afxdialogex.h"


// class5 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(class5, CDialogEx)

class5::class5(CWnd* pParent /*=NULL*/)
	: CDialogEx(class5::IDD, pParent)
{

}

class5::~class5()
{
}

void class5::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(class5, CDialogEx)
END_MESSAGE_MAP()


// class5 �޽��� ó�����Դϴ�.
