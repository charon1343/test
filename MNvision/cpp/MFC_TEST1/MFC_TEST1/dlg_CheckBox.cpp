// dlg_CheckBox.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFC_TEST1.h"
#include "dlg_CheckBox.h"
#include "afxdialogex.h"


// dlg_CheckBox ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(dlg_CheckBox, CDialogEx)

dlg_CheckBox::dlg_CheckBox(CWnd* pParent /*=NULL*/)
	: CDialogEx(dlg_CheckBox::IDD, pParent)
{

	m_edit1 = _T("");
}

dlg_CheckBox::~dlg_CheckBox()
{
}

void dlg_CheckBox::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_CHECK1, m_check1);
	//  DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Check(pDX, IDC_CHECK1, m_check1);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
}


BEGIN_MESSAGE_MAP(dlg_CheckBox, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &dlg_CheckBox::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_CHECK1, &dlg_CheckBox::OnBnClickedCheck1)
END_MESSAGE_MAP()


// dlg_CheckBox �޽��� ó�����Դϴ�.


void dlg_CheckBox::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	

}


void dlg_CheckBox::OnBnClickedCheck1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	if(m_check1 == TRUE)
		m_edit1 = "üũ ���ڰ� üũ�Ǿ����ϴ�.";
	else
		m_edit1 = "üũ ���ڰ� �����Ǿ����ϴ�.";
	UpdateData(FALSE);
}
