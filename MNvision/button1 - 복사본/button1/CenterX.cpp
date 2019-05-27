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
	, value(_T(""))

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
	ON_BN_CLICKED(IDC_BUTTON4, &CenterX::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CenterX::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON2, &CenterX::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON7, &CenterX::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CenterX::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CenterX::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CenterX::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CenterX::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON18, &CenterX::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON13, &CenterX::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON12, &CenterX::OnBnClickedButton12)
	ON_EN_CHANGE(IDC_EDIT7, &CenterX::OnEnChangeEdit7)
END_MESSAGE_MAP()


// CenterX 메시지 처리기입니다.

BOOL CenterX::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_edit.SetWindowTextW(_T("0"));
	value="";
	minus = true;
	

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CenterX::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	value.Append(_T("1"));
	m_edit.SetWindowTextW(value);
}

void CenterX::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	value.Append(_T("2"));
	m_edit.SetWindowTextW(value);
}


void CenterX::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	value.Append(_T("3"));
	m_edit.SetWindowTextW(value);
}


void CenterX::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	value.Append(_T("4"));
	m_edit.SetWindowTextW(value);
}


void CenterX::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	value.Append(_T("5"));
	m_edit.SetWindowTextW(value);
}


void CenterX::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	value.Append(_T("6"));
	m_edit.SetWindowTextW(value);
}


void CenterX::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	value.Append(_T("7"));
	m_edit.SetWindowTextW(value);
}


void CenterX::OnBnClickedButton10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	value.Append(_T("8"));
	m_edit.SetWindowTextW(value);
}


void CenterX::OnBnClickedButton11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	value.Append(_T("9"));
	m_edit.SetWindowTextW(value);
}


void CenterX::OnBnClickedButton18()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	value.Append(_T("0"));
	m_edit.SetWindowTextW(value);
}


void CenterX::OnBnClickedButton13()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	value.Append(_T("."));
	m_edit.SetWindowTextW(value);
}


void CenterX::OnBnClickedButton12()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(minus)
	{
		CString a = _T("-");
		a.Append(value);
		value = a;
		m_edit.SetWindowTextW(value);
		minus=!minus;
	}
	else
	{
		value=value.Mid(1);
		m_edit.SetWindowTextW(value);
		minus=!minus;
	}
}


void CenterX::OnEnChangeEdit7()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
