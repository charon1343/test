// CenterX.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "button1.h"
#include "CenterX.h"
#include "afxdialogex.h"


// CenterX ��ȭ �����Դϴ�.

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


// CenterX �޽��� ó�����Դϴ�.

BOOL CenterX::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_edit.SetWindowTextW(_T("0"));
	value="";
	minus = true;
	

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CenterX::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	value.Append(_T("1"));
	m_edit.SetWindowTextW(value);
}

void CenterX::OnBnClickedButton4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	value.Append(_T("2"));
	m_edit.SetWindowTextW(value);
}


void CenterX::OnBnClickedButton5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	value.Append(_T("3"));
	m_edit.SetWindowTextW(value);
}


void CenterX::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	value.Append(_T("4"));
	m_edit.SetWindowTextW(value);
}


void CenterX::OnBnClickedButton7()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	value.Append(_T("5"));
	m_edit.SetWindowTextW(value);
}


void CenterX::OnBnClickedButton8()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	value.Append(_T("6"));
	m_edit.SetWindowTextW(value);
}


void CenterX::OnBnClickedButton9()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	value.Append(_T("7"));
	m_edit.SetWindowTextW(value);
}


void CenterX::OnBnClickedButton10()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	value.Append(_T("8"));
	m_edit.SetWindowTextW(value);
}


void CenterX::OnBnClickedButton11()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	value.Append(_T("9"));
	m_edit.SetWindowTextW(value);
}


void CenterX::OnBnClickedButton18()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	value.Append(_T("0"));
	m_edit.SetWindowTextW(value);
}


void CenterX::OnBnClickedButton13()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	value.Append(_T("."));
	m_edit.SetWindowTextW(value);
}


void CenterX::OnBnClickedButton12()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
