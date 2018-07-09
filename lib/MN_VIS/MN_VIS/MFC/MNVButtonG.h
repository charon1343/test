#pragma once


// CMNVButton
enum MNVBTN_STATE { MNVBT_NORMAL = 0, MNVBT_PUSH = 1, MNVBT_CHECK = 2, MNVBT_CHECKPUSH = 3 };
struct MNVST_BtnStyle {
	CString strText;
	COLORREF refTextColor;
	COLORREF refBackColor;
	COLORREF refLight;
	COLORREF refDark;

	void operator = (MNVST_BtnStyle __Style) {
		strText = __Style.strText;
		refTextColor = __Style.refTextColor;
		refBackColor = __Style.refBackColor;
		refLight = __Style.refLight;
		refDark = __Style.refDark;
	}
};

class CMNVButton : public CButton
{
	DECLARE_DYNAMIC(CMNVButton)
	MNVST_BtnStyle m_stStyle[4];
	MNVBTN_STATE m_BtnState;

public:
	CMNVButton();
	virtual ~CMNVButton();

protected:
	DECLARE_MESSAGE_MAP()
public:
	void SetCheck(bool __isCheck) {
		switch(m_BtnState) {
		case MNVBT_PUSH: m_BtnState = __isCheck ? MNVBT_CHECKPUSH : MNVBT_PUSH; break;
		case MNVBT_CHECK: m_BtnState = __isCheck ? MNVBT_CHECK : MNVBT_NORMAL; break;
		case MNVBT_CHECKPUSH: m_BtnState = __isCheck ? MNVBT_CHECKPUSH : MNVBT_PUSH; break;
		default: m_BtnState = __isCheck ? MNVBT_CHECK : MNVBT_NORMAL; break;
		}
		RedrawWindow();
	}
	bool GetCheck() { return m_BtnState == MNVBT_CHECK || m_BtnState == MNVBT_CHECKPUSH; }
	void Toggle() {
		switch(m_BtnState) {
		case MNVBT_PUSH: m_BtnState = MNVBT_CHECKPUSH; break;
		case MNVBT_CHECK: m_BtnState = MNVBT_NORMAL; break;
		case MNVBT_CHECKPUSH: m_BtnState = MNVBT_PUSH; break;
		default: m_BtnState = MNVBT_CHECK; break;
		}
		RedrawWindow();
	}
	void InitButton(MNVST_BtnStyle & __Normal, MNVST_BtnStyle & __Push, MNVST_BtnStyle & __Check, MNVST_BtnStyle & __CheckPush, bool __isCheck) {
		m_BtnState = __isCheck ? MNVBT_CHECK : MNVBT_NORMAL;
		SetButtonStyle(GetButtonStyle() | BS_OWNERDRAW);
		m_stStyle[MNVBT_NORMAL] = __Normal;
		m_stStyle[MNVBT_CHECK] = __Check;
		m_stStyle[MNVBT_PUSH] = __Push;
		m_stStyle[MNVBT_CHECKPUSH] = __CheckPush;
	}
	virtual BOOL PreTranslateMessage(MSG* pMsg) {
		return CButton::PreTranslateMessage(pMsg);
	}
	afx_msg void OnPaint();
	afx_msg void OnNcPaint();
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
};


