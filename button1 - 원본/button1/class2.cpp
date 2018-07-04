// class2.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "button1.h"
#include "class2.h"
#include "afxdialogex.h"


// class2 대화 상자입니다.

IMPLEMENT_DYNAMIC(class2, CDialogEx)

class2::class2(CWnd* pParent /*=NULL*/)
	: CDialogEx(class2::IDD, pParent)
{

}

class2::~class2()
{
}

void class2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_Find);
	DDX_Control(pDX, IDC_BUTTON3, m_FindLine);
	DDX_Control(pDX, IDC_BUTTON4, m_Calipers);
	DDX_Control(pDX, IDC_BUTTON5, m_CalipersValue);
	DDX_Control(pDX, IDC_BUTTON6, m_Projection);
	DDX_Control(pDX, IDC_BUTTON7, m_ProjectionValue);
	DDX_Control(pDX, IDC_BUTTON8, m_Search);
	DDX_Control(pDX, IDC_BUTTON9, m_SearchValue);
	DDX_Control(pDX, IDC_BUTTON10, m_Polarity);
	DDX_Control(pDX, IDC_BUTTON11, m_DarkToLight);
	DDX_Control(pDX, IDC_BUTTON12, m_Threashold);
	DDX_Control(pDX, IDC_BUTTON13, m_ThreasholdValue);
	DDX_Control(pDX, IDC_BUTTON14, m_HalfPixel);
	DDX_Control(pDX, IDC_BUTTON15, m_HalfPixelValue);
	DDX_Control(pDX, IDC_BUTTON16, m_Ignore);
	DDX_Control(pDX, IDC_BUTTON17, m_IgnoreValue);
	
}


BEGIN_MESSAGE_MAP(class2, CDialogEx)
	ON_WM_WINDOWPOSCHANGED()
	ON_BN_CLICKED(IDC_BUTTON11, &class2::OnBnClickedButton11)
END_MESSAGE_MAP()


// class2 메시지 처리기입니다.

void class2::On_WindPosACL()
{
	CRect rctClient;
	GetClientRect(&rctClient);

	rctClient.top += 5;
	rctClient.left += 5;
	rctClient.bottom -= 5;
	rctClient.right -= 5;

	CRect rctSub = rctClient;
	rctSub.top = rctClient.top + 1;

	int nWidth = (rctClient.Width() + 1) / 4 - 1;
	int nHeight = (rctClient.Height() + 1 ) / 5 - 1;

	
	rctSub.right = rctSub.left+(nWidth*3)+2;
	rctSub.bottom = rctSub.top + nHeight;
	m_FindLine.SetWindowPos(rctSub);
	
	rctSub.top = rctSub.bottom + 1;
	rctSub.bottom = rctSub.top + nHeight;
	rctSub.right = rctSub.left+nWidth;
	m_Calipers.SetWindowPos(rctSub);
	
	rctSub.left = rctSub.right + 1;
	rctSub.right = rctSub.left+nWidth;
	m_CalipersValue.SetWindowPos(rctSub);

	rctSub.left = rctSub.right + 1;
	rctSub.right = rctSub.left+nWidth;
	m_Threashold.SetWindowPos(rctSub);

	rctSub.left = rctSub.right + 1;
	rctSub.right = rctSub.left+nWidth;
	m_ThreasholdValue.SetWindowPos(rctSub);

	rctSub.left = rctClient.left;
	rctSub.right = rctSub.left + nWidth;
	rctSub.top = rctSub.bottom + 1;
	rctSub.bottom = rctSub.top + nHeight;
	m_Projection.SetWindowPos(rctSub);

	rctSub.left = rctSub.right + 1;
	rctSub.right = rctSub.left+nWidth;
	m_ProjectionValue.SetWindowPos(rctSub);

	rctSub.left = rctSub.right + 1;
	rctSub.right = rctSub.left+nWidth;
	m_HalfPixel.SetWindowPos(rctSub);

	rctSub.left = rctSub.right + 1;
	rctSub.right = rctSub.left+nWidth;
	m_HalfPixelValue.SetWindowPos(rctSub);

	rctSub.left = rctClient.left;
	rctSub.right = rctSub.left + nWidth;
	rctSub.top = rctSub.bottom + 1;
	rctSub.bottom = rctSub.top + nHeight;
	m_Search.SetWindowPos(rctSub);

	rctSub.left = rctSub.right + 1;
	rctSub.right = rctSub.left+nWidth;
	m_SearchValue.SetWindowPos(rctSub);

	rctSub.left = rctSub.right + 1;
	rctSub.right = rctSub.left+nWidth;
	m_Ignore.SetWindowPos(rctSub);

	rctSub.left = rctSub.right + 1;
	rctSub.right = rctSub.left+nWidth;
	m_IgnoreValue.SetWindowPos(rctSub);

	rctSub.left = rctClient.left;
	rctSub.right = rctSub.left + nWidth;
	rctSub.top = rctSub.bottom + 1;
	rctSub.bottom = rctSub.top + nHeight;
	m_Polarity.SetWindowPos(rctSub);

	rctSub.left = rctSub.right + 1;
	rctSub.right = rctSub.left+(nWidth*3)+2;
	m_DarkToLight.SetWindowPos(rctSub);

	rctSub.left = rctClient.left+nWidth*3+2;
	rctSub.top = rctClient.top;
	rctSub.bottom = rctSub.top + nHeight;
	m_Find.SetWindowPos(&CWnd::wndTopMost,rctSub.left,rctSub.top,rctSub.right-rctSub.left,rctSub.bottom-rctSub.top,SWP_NOZORDER);

}


void class2::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CDialogEx::OnWindowPosChanged(lpwndpos);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if ((lpwndpos->flags & SWP_NOSIZE) == 0) { On_WindPosACL();}

}


void class2::OnBnClickedButton11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Polarity dlg;
	dlg.m_nValue = 3;
	if (dlg.DoModal() == IDOK) {
		switch(	dlg.m_nValue) {
			case 1: AfxMessageBox(_T("Don't Care")); break;
			case 2: AfxMessageBox(_T("Dark to Light")); break;
			case 3: AfxMessageBox(_T("Light to Dark")); break;
		}
		
	}
}