// Dlg_PADNumeric.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MN_VIS.h"
#include "Dlg_PADNumeric.h"
#include "afxdialogex.h"


// CDlg_PADNumeric 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_PADNumeric, CDialogEx)

CDlg_PADNumeric::CDlg_PADNumeric(PAD_InputMode __Mode, CWnd* pParent /*=NULL*/)
	: CMNVDialogEx(CDlg_PADNumeric::IDD, pParent)
{
	m_Mode = __Mode;
}

CDlg_PADNumeric::~CDlg_PADNumeric()
{
}

void CDlg_PADNumeric::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_PADNumeric, CDialogEx)
	ON_BN_CLICKED(IDC_NUM_1, &CDlg_PADNumeric::OnBnClickedNum1)
	ON_BN_CLICKED(IDC_NUM_2, &CDlg_PADNumeric::OnBnClickedNum2)
	ON_BN_CLICKED(IDC_NUM_3, &CDlg_PADNumeric::OnBnClickedNum3)
	ON_BN_CLICKED(IDC_NUM_4, &CDlg_PADNumeric::OnBnClickedNum4)
	ON_BN_CLICKED(IDC_NUM_5, &CDlg_PADNumeric::OnBnClickedNum5)
	ON_BN_CLICKED(IDC_NUM_6, &CDlg_PADNumeric::OnBnClickedNum6)
	ON_BN_CLICKED(IDC_NUM_7, &CDlg_PADNumeric::OnBnClickedNum7)
	ON_BN_CLICKED(IDC_NUM_8, &CDlg_PADNumeric::OnBnClickedNum8)
	ON_BN_CLICKED(IDC_NUM_9, &CDlg_PADNumeric::OnBnClickedNum9)
	ON_BN_CLICKED(IDC_NUM_0, &CDlg_PADNumeric::OnBnClickedNum0)
	ON_BN_CLICKED(IDC_NUM_DOT, &CDlg_PADNumeric::OnBnClickedNumDot)
	ON_WM_KEYDOWN()
	ON_WM_SYSKEYDOWN()
	ON_BN_CLICKED(IDC_NUM_Back, &CDlg_PADNumeric::OnBnClickedNumBack)
	ON_BN_CLICKED(IDC_NUM_Clear, &CDlg_PADNumeric::OnBnClickedNumClear)
	ON_BN_CLICKED(IDC_NUM_Minus, &CDlg_PADNumeric::OnBnClickedNumMinus)
END_MESSAGE_MAP()


// CDlg_PADNumeric 메시지 처리기입니다.


BOOL CDlg_PADNumeric::OnInitDialog()
{
	CMNVDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_isMinus = false;
	m_isDecimalPoint = false;
	m_nValue = 0;
	m_nDenominator = 1;
	SetItemData(IDC_NUM_VALUE, 0);
	switch(m_Mode) {
		case PAD_MDInteger: {
			SetItemData(IDC_NUM_VALUE, 0);
			SetItemCheck(IDC_NUM_DOT, false, false);
		} break;
		case PAD_MDReal: {
			SetItemData(IDC_NUM_VALUE, 0);
			SetItemCheck(IDC_NUM_DOT, false, true);
		}break;
		case PAD_MDPassword: {
			SetItemData(IDC_NUM_VALUE, _T(""));
			SetItemCheck(IDC_NUM_DOT, false, false);
		} break;
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlg_PADNumeric::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CMNVDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CDlg_PADNumeric::OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CMNVDialogEx::OnSysKeyDown(nChar, nRepCnt, nFlags);
}


BOOL CDlg_PADNumeric::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	char Temp = 0;
	switch(pMsg->message) {
	case WM_CHAR: 
		{
			if (0x30 <= pMsg->wParam && pMsg->wParam <= 0x39)
				InputNumber((int)pMsg->wParam - 0x30);
			else if (pMsg->wParam == '.')
				InputDot();
			else if (pMsg->wParam == '-')
				InputMinus();
			else if (pMsg->wParam == 0x08) {
				InputBackSpace();
			}
		}
	}
	return CMNVDialogEx::PreTranslateMessage(pMsg);
}
