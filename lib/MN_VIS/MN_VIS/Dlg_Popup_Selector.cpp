// Dlg_Popup_Selector.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Dlg_Popup_Selector.h"
#include "afxdialogex.h"


// CDlg_Popup_Selector 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_Popup_Selector, CDialogEx)

CDlg_Popup_Selector::CDlg_Popup_Selector(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlg_Popup_Selector::IDD, pParent)
{
	//m_strData = NULL;
}

CDlg_Popup_Selector::~CDlg_Popup_Selector()
{
}

void CDlg_Popup_Selector::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SELECT1, m_ctrlSelect[0]);
	DDX_Control(pDX, IDC_SELECT2, m_ctrlSelect[1]);
	DDX_Control(pDX, IDC_SELECT3, m_ctrlSelect[2]);
	DDX_Control(pDX, IDC_SELECT4, m_ctrlSelect[3]);
	DDX_Control(pDX, IDC_SELECT5, m_ctrlSelect[4]);
}


BEGIN_MESSAGE_MAP(CDlg_Popup_Selector, CDialogEx)
	ON_BN_CLICKED(IDC_SELECT1, &CDlg_Popup_Selector::OnClickedSelect1)
	ON_BN_CLICKED(IDC_SELECT2, &CDlg_Popup_Selector::OnClickedSelect2)
	ON_BN_CLICKED(IDC_SELECT3, &CDlg_Popup_Selector::OnClickedSelect3)
	ON_BN_CLICKED(IDC_SELECT4, &CDlg_Popup_Selector::OnClickedSelect4)
	ON_BN_CLICKED(IDC_SELECT5, &CDlg_Popup_Selector::OnClickedSelect5)
END_MESSAGE_MAP()


// CDlg_Popup_Selector 메시지 처리기입니다.


BOOL CDlg_Popup_Selector::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	if (m_strData != NULL) {
		SetWindowText(m_strData[0]);
		for(int nIndex = 0; nIndex < 5; ++nIndex) {
			if (m_strData[nIndex + 1].GetLength() > 0)
				m_ctrlSelect[nIndex].SetItemData(m_strData[nIndex + 1], true, false, true);
			else m_ctrlSelect[nIndex].SetItemData(_T("Empty"), false, false, false);
		}
	}
	OnReflash();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
