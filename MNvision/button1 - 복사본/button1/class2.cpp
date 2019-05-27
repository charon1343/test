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
	ON_BN_CLICKED(IDC_BUTTON5, &class2::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &class2::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &class2::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &class2::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &class2::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &class2::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON12, &class2::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &class2::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &class2::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &class2::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &class2::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &class2::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON10, &class2::OnBnClickedButton10)
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
		case 1: m_DarkToLight.SetWindowTextW(_T("Don't Care"));	break;
		case 2: m_DarkToLight.SetWindowTextW(_T("Dark to Light")); break;
		case 3: m_DarkToLight.SetWindowTextW(_T("Light to Dark")); break;
		}

	}
}

void class2::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (centerx.DoModal() == IDOK) {
		centerx.classvalue.calipers=CMNVParser::Str2Num(centerx.value,0.0);
		CString value;
		value.Format( _T("%0.4lf"), centerx.classvalue.calipers);
		value.TrimRight(_T('0'));
		m_CalipersValue.SetWindowTextW(value);
	}
}


void class2::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (centerx.DoModal() == IDOK) {
		centerx.classvalue.calipers=CMNVParser::Str2Num(centerx.value,0.0);
		CString value;
		value.Format( _T("%0.4lf"), centerx.classvalue.calipers);
		value.TrimRight(_T('0'));
		m_CalipersValue.SetWindowTextW(value);

	}
}


void class2::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (centerx.DoModal() == IDOK) { 
		centerx.classvalue.projection=CMNVParser::Str2Num(centerx.value,0.0);
		CString value;
		value.Format( _T("%0.4lf"), centerx.classvalue.projection);
		value.TrimRight(_T('0'));
		m_ProjectionValue.SetWindowTextW(value);
	}
}


void class2::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (centerx.DoModal() == IDOK) {
		centerx.classvalue.projection=CMNVParser::Str2Num(centerx.value,0.0);
		CString value;
		value.Format( _T("%0.4lf"), centerx.classvalue.projection);
		value.TrimRight(_T('0'));
		m_ProjectionValue.SetWindowTextW(value);
	}
}


void class2::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (centerx.DoModal() == IDOK) {
		centerx.classvalue.search=CMNVParser::Str2Num(centerx.value,0.0);
		CString value;
		value.Format( _T("%0.4lf"), centerx.classvalue.search);
		value.TrimRight(_T('0'));
		m_SearchValue.SetWindowTextW(value);
	}
}


void class2::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (centerx.DoModal() == IDOK) {
		centerx.classvalue.search=CMNVParser::Str2Num(centerx.value,0.0);
		CString value;
		value.Format( _T("%0.4lf"), centerx.classvalue.search);
		value.TrimRight(_T('0'));
		m_SearchValue.SetWindowTextW(value);
	}
}


void class2::OnBnClickedButton12()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (centerx.DoModal() == IDOK) {
		centerx.classvalue.threashold=CMNVParser::Str2Num(centerx.value,0.0);
		CString value;
		value.Format( _T("%0.4lf"), centerx.classvalue.threashold);
		value.TrimRight(_T('0'));
		m_ThreasholdValue.SetWindowTextW(value);
	}
}



void class2::OnBnClickedButton13()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (centerx.DoModal() == IDOK) {
		centerx.classvalue.threashold=CMNVParser::Str2Num(centerx.value,0.0);
		CString value;
		value.Format( _T("%0.4lf"), centerx.classvalue.threashold);
		value.TrimRight(_T('0'));
		m_ThreasholdValue.SetWindowTextW(value);
	}
}


void class2::OnBnClickedButton14()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (centerx.DoModal() == IDOK) {
		centerx.classvalue.halfpixel=CMNVParser::Str2Num(centerx.value,0.0);
		CString value;
		value.Format( _T("%0.4lf"), centerx.classvalue.halfpixel);
		value.TrimRight(_T('0'));
		m_HalfPixelValue.SetWindowTextW(value);
	}
}


void class2::OnBnClickedButton15()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (centerx.DoModal() == IDOK) {
		centerx.classvalue.halfpixel=CMNVParser::Str2Num(centerx.value,0.0);
		CString value;
		value.Format( _T("%0.4lf"), centerx.classvalue.halfpixel);
		value.TrimRight(_T('0'));
		m_HalfPixelValue.SetWindowTextW(value);
	}
}


void class2::OnBnClickedButton16()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (centerx.DoModal() == IDOK) {
		centerx.classvalue.ignore=CMNVParser::Str2Num(centerx.value,0.0);
		CString value;
		value.Format( _T("%0.4lf"), centerx.classvalue.ignore);
		value.TrimRight(_T('0'));
		m_IgnoreValue.SetWindowTextW(value);
	}
}


void class2::OnBnClickedButton17()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (centerx.DoModal() == IDOK) {
		centerx.classvalue.ignore=CMNVParser::Str2Num(centerx.value,0.0);
		CString value;
		value.Format( _T("%0.4lf"), centerx.classvalue.ignore);
		value.TrimRight(_T('0'));
		m_IgnoreValue.SetWindowTextW(value);
	}
}


void class2::OnBnClickedButton10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Polarity dlg;
	dlg.m_nValue = 3;
	if (dlg.DoModal() == IDOK) {
		switch(	dlg.m_nValue) {
		case 1: m_DarkToLight.SetWindowTextW(_T("Don't Care"));	break;
		case 2: m_DarkToLight.SetWindowTextW(_T("Dark to Light")); break;
		case 3: m_DarkToLight.SetWindowTextW(_T("Light to Dark")); break;
		}

	}
}


BOOL class2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
