// class3.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "button1.h"
#include "class3.h"
#include "afxdialogex.h"


// class3 ��ȭ �����Դϴ�.

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


// class3 �޽��� ó�����Դϴ�.


void class3::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	
}
