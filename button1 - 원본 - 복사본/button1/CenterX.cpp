// CenterX.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "button1.h"
#include "CenterX.h"
#include "afxdialogex.h"


// CenterX 대화 상자입니다.

IMPLEMENT_DYNAMIC(CenterX, CDialogEx)

CenterX::CenterX(CWnd* pParent /*=NULL*/)
	: CDialogEx(CenterX::IDD, pParent)
{

}

CenterX::~CenterX()
{
}

void CenterX::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CenterX, CDialogEx)
END_MESSAGE_MAP()


// CenterX 메시지 처리기입니다.
