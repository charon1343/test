// Dlg_CtrlPattern.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Dlg_CtrlPattern.h"
#include "afxdialogex.h"


// CDlg_CtrlPattern 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_CtrlPattern, CDialogEx)

CDlg_CtrlPattern::CDlg_CtrlPattern(CWnd* pParent /*=NULL*/)
	: CMNVDialogEx(CDlg_CtrlPattern::IDD, pParent)
{

}

CDlg_CtrlPattern::~CDlg_CtrlPattern()
{
}

void CDlg_CtrlPattern::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_CtrlPattern, CDialogEx)
	ON_WM_WINDOWPOSCHANGED()
	ON_BN_CLICKED(IDC_PATTERN_SHOWMASTER, &CDlg_CtrlPattern::OnBnClickedPatternShowmaster)
	ON_BN_CLICKED(IDC_PATTERN_SetPattern, &CDlg_CtrlPattern::OnBnClickedPatternSetpattern)
END_MESSAGE_MAP()


// CDlg_CtrlPattern 메시지 처리기입니다.


BOOL CDlg_CtrlPattern::OnInitDialog()
{
	CMNVDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlg_CtrlPattern::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CMNVDialogEx::OnWindowPosChanged(lpwndpos);

	int nTop[7];
	int nLeft[5];
	int nWidth[2];
	int nHeight[2];
	int nMargin = 5;

	CRect rect;
	GetClientRect(&rect);

	nWidth[0] = (rect.Width() - nMargin * 4) / 5;
	nHeight[0] = (rect.Height() - nMargin * 6) / 7;

	nTop[0] = rect.top;
	nTop[1] = nTop[0] + nHeight[0] + nMargin;
	nTop[2] = nTop[1] + nHeight[0] + nMargin;
	nTop[3] = nTop[2] + nHeight[0] + nMargin;
	nTop[4] = nTop[3] + nHeight[0] + nMargin;
	nTop[5] = nTop[4] + nHeight[0] + nMargin;
	nTop[6] = nTop[5] + nHeight[0] + nMargin;

	nLeft[0] = rect.left;
	nLeft[1] = nLeft[0] + nWidth[0] + nMargin;
	nLeft[2] = nLeft[1] + nWidth[0] + nMargin;
	nLeft[3] = nLeft[2] + nWidth[0] + nMargin;
	nLeft[4] = nLeft[3] + nWidth[0] + nMargin;

	/*SetWindowPos(IDC_LIGHT_ALL, nLeft[0], nTop[0], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_12H, nLeft[1], nTop[0], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_3H,  nLeft[2], nTop[0], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_6H,  nLeft[3], nTop[0], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_9H,  nLeft[4], nTop[0], nWidth[0], nHeight[0]);

	SetWindowPos(IDC_LIGHT_DF,  nLeft[0], nTop[1], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH1, nLeft[1], nTop[1], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH2, nLeft[2], nTop[1], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH3, nLeft[3], nTop[1], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH4, nLeft[4], nTop[1], nWidth[0], nHeight[0]);

	SetWindowPos(IDC_LIGHT_LA,  nLeft[0], nTop[2], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH5, nLeft[1], nTop[2], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH6, nLeft[2], nTop[2], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH7, nLeft[3], nTop[2], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH8, nLeft[4], nTop[2], nWidth[0], nHeight[0]);

	SetWindowPos(IDC_LIGHT_MA,   nLeft[0], nTop[3], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH9,  nLeft[1], nTop[3], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH10, nLeft[2], nTop[3], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH11, nLeft[3], nTop[3], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH12, nLeft[4], nTop[3], nWidth[0], nHeight[0]);

	SetWindowPos(IDC_LIGHT_HA,   nLeft[0], nTop[4], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH13, nLeft[1], nTop[4], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH14, nLeft[2], nTop[4], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH15, nLeft[3], nTop[4], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH16, nLeft[4], nTop[4], nWidth[0], nHeight[0]);

	SetWindowPos(IDC_LIGHT_FR,   nLeft[0], nTop[5], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH17, nLeft[1], nTop[5], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH18, nLeft[2], nTop[5], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH19, nLeft[3], nTop[5], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_CH20, nLeft[4], nTop[5], nWidth[0], nHeight[0]);

	SetWindowPos(IDC_LIGHT_LEVEL,  nLeft[1], nTop[6], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_BTNADD, nLeft[2], nTop[6], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_BTNSUB, nLeft[3], nTop[6], nWidth[0], nHeight[0]);
	SetWindowPos(IDC_LIGHT_BTNSET, nLeft[4], nTop[6], nWidth[0], nHeight[0]);*/

	
}
