// MNVButton.cpp : 구현 파일입니다.
//

#include "stdafx.h"
//#include "LFine_LightControl.h"
#include "MNVButton.h"


// CMNVButton

IMPLEMENT_DYNAMIC(CMNVButton, CButton)

CMNVButton::CMNVButton()
{
	m_BtnState = MNVBT_NORMAL;
}

CMNVButton::~CMNVButton()
{
}


BEGIN_MESSAGE_MAP(CMNVButton, CButton)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()

// CMNVButton 메시지 처리기입니다.


void CMNVButton::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CRect rect;
	GetClientRect(&rect);
	//dc.Rectangle(rect);
	CPen Light(PS_SOLID, 1, m_stStyle[m_BtnState].refLight);
	CPen Dark(PS_SOLID, 1, m_stStyle[m_BtnState].refDark);

	CPen * Old;
	dc.FillSolidRect(rect.left, rect.top, rect.Width(), rect.Height(), m_stStyle[m_BtnState].refBackColor);

	dc.MoveTo(rect.left, rect.bottom);

	Old = dc.SelectObject(&Light);
	dc.LineTo(rect.left, rect.top);
	dc.LineTo(rect.right, rect.top);
	
	dc.SelectObject(&Dark);
	dc.LineTo(rect.right, rect.bottom);
	dc.LineTo(rect.left, rect.bottom);
	dc.SelectObject(Old);

	dc.SetTextColor(m_stStyle[m_BtnState].refTextColor);
	dc.DrawText(m_stStyle[m_BtnState].strText, rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CButton::OnPaint()을(를) 호출하지 마십시오.
}


void CMNVButton::OnNcPaint()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CButton::OnNcPaint()을(를) 호출하지 마십시오.
	//GetDC()->FillSolidRect(0, 0, 100, 100, RGB(255,0,0));
}



void CMNVButton::DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/)
{

	// TODO:  지정된 항목을 그리는 코드를 추가합니다.
}

void CMNVButton::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch(m_BtnState) {
		case MNVBT_CHECK: m_BtnState = MNVBT_CHECKPUSH; break;
		case MNVBT_PUSH: m_BtnState = MNVBT_PUSH; break;
		case MNVBT_CHECKPUSH: m_BtnState = MNVBT_CHECKPUSH; break;
		default: m_BtnState = MNVBT_PUSH; break;
	}
	RedrawWindow();
	CButton::OnLButtonDown(nFlags, point);
}


void CMNVButton::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch(m_BtnState) {
		case MNVBT_CHECK: m_BtnState = MNVBT_CHECK; break;
		case MNVBT_PUSH: m_BtnState = MNVBT_NORMAL; break;
		case MNVBT_CHECKPUSH: m_BtnState = MNVBT_CHECK; break;
		default: m_BtnState = MNVBT_NORMAL; break;
	}
	RedrawWindow();
	CButton::OnLButtonUp(nFlags, point);
}

void CMNVButton::OnMouseLeave()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch(m_BtnState) {
		case MNVBT_CHECK: m_BtnState = MNVBT_CHECK; break;
		case MNVBT_PUSH: m_BtnState = MNVBT_NORMAL; break;
		case MNVBT_CHECKPUSH: m_BtnState = MNVBT_CHECK; break;
		default: m_BtnState = MNVBT_NORMAL; break;
	}
	RedrawWindow();
	CButton::OnMouseLeave();
}
