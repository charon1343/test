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
	DDX_Control(pDX, IDC_EDIT7, m_edit);
	DDX_Control(pDX, IDC_BUTTON1, m_Sel1);
	DDX_Control(pDX, IDC_BUTTON4, m_Sel2);
	DDX_Control(pDX, IDC_BUTTON5, m_Sel3);
	DDX_Control(pDX, IDC_BUTTON2, m_Sel4);
	DDX_Control(pDX, IDC_BUTTON7, m_Sel5);
	DDX_Control(pDX, IDC_BUTTON8, m_Sel6);
	DDX_Control(pDX, IDC_BUTTON9, m_Sel7);
	DDX_Control(pDX, IDC_BUTTON10, m_Sel8);
	DDX_Control(pDX, IDC_BUTTON11, m_Sel9);
	DDX_Control(pDX, IDC_BUTTON18, m_Sel0);
	DDX_Control(pDX, IDC_BUTTON12, m_SelChangSign);
	DDX_Control(pDX, IDC_BUTTON13, m_SelPoint);
}


BEGIN_MESSAGE_MAP(CenterX, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CenterX::OnBnClickedButton1)
END_MESSAGE_MAP()


// CenterX 메시지 처리기입니다.


void CenterX::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_edit.SetWindowTextW(_T("1"));
}
