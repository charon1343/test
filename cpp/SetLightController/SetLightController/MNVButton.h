#include "stdafx.h"

class CMNVButton : public CButton {
public:
	bool SetCheck(bool __isCheck, bool __isEnable = true) {
		CButton::SetCheck(__isCheck ? TRUE : FALSE);
		CButton::EnableWindow(__isEnable ? TRUE : FALSE);
		return CButton::GetCheck() == TRUE;
	}
	
	bool SetWindowPos_LTRB(int __nLeft, int __nTop, int __nRight, int __nBottom) {
		return TRUE == CButton::SetWindowPos(NULL, __nLeft, __nTop, __nRight - __nLeft, __nBottom - __nTop, SWP_NOZORDER);
	}
	bool SetWindowPos_XYWH(int __nX, int __nY, int __nW, int __nH) {
		return TRUE == CButton::SetWindowPos(NULL, __nX, __nY, __nW, __nH, SWP_NOZORDER);
	}
	bool SetWindowPos(CRect & __Rect) {
		return TRUE == CButton::SetWindowPos(NULL, __Rect.left, __Rect.top, __Rect.Width(), __Rect.Height(), SWP_NOZORDER);
	}

};