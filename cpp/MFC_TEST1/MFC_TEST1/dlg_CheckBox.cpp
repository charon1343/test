// dlg_CheckBox.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFC_TEST1.h"
#include "dlg_CheckBox.h"
#include "afxdialogex.h"


// dlg_CheckBox 대화 상자입니다.

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


// dlg_CheckBox 메시지 처리기입니다.


void dlg_CheckBox::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	

}


void dlg_CheckBox::OnBnClickedCheck1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if(m_check1 == TRUE)
		m_edit1 = "체크 상자가 체크되었습니다.";
	else
		m_edit1 = "체크 상자가 해제되었습니다.";
	UpdateData(FALSE);
}
