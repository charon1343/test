// MNVButton.cpp : ���� �����Դϴ�.
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

// CMNVButton �޽��� ó�����Դϴ�.


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

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CButton::OnPaint()��(��) ȣ������ ���ʽÿ�.
}


void CMNVButton::OnNcPaint()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CButton::OnNcPaint()��(��) ȣ������ ���ʽÿ�.
	//GetDC()->FillSolidRect(0, 0, 100, 100, RGB(255,0,0));
}



void CMNVButton::DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/)
{

	// TODO:  ������ �׸��� �׸��� �ڵ带 �߰��մϴ�.
}

void CMNVButton::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	switch(m_BtnState) {
		case MNVBT_CHECK: m_BtnState = MNVBT_CHECK; break;
		case MNVBT_PUSH: m_BtnState = MNVBT_NORMAL; break;
		case MNVBT_CHECKPUSH: m_BtnState = MNVBT_CHECK; break;
		default: m_BtnState = MNVBT_NORMAL; break;
	}
	RedrawWindow();
	CButton::OnMouseLeave();
}
