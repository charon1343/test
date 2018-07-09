#pragma once
#include "MNVParser.h"

class CMNVButton: public CButton {
public:
	//bool InitButton(LPTSTR __lpstrValue, bool __isCheck, bool __isEnable, bool __isShow) {
	//	SetWindowTextW(__lpstrValue);
	//	SetCheck(__isCheck ? TRUE : FALSE);
	//	ShowWindow(__isShow ? SW_SHOW : SW_HIDE);
	//	return EnableWindow(__isEnable ? TRUE : FALSE) == TRUE;
	//}

	bool GetItemCheck() {
		return GetCheck() == TRUE;
	}
	bool SetItemCheck(bool __isCheck = true, bool __isEnable = true) {
		SetCheck(__isCheck ? TRUE : FALSE);
		EnableWindow(__isEnable ? TRUE : FALSE);
		return true;
	}

	bool SetItemData(int __nValue, bool __isEnable = true, bool __isCheck = false, bool __isShow = true) {
		CString strTemp;
		strTemp.Format(_T("%d"), __nValue);
		SetWindowTextW(strTemp);
		SetCheck(__isCheck ? TRUE : FALSE);
		EnableWindow(__isEnable ? TRUE : FALSE);
		ShowWindow(__isShow ? SW_SHOW : SW_HIDE);
		return true;
	}

	bool SetItemData(float __rValue, bool __isEnable = true, LPCTSTR lpFormat = NULL) {
		CString strTemp;
		strTemp.Format((lpFormat == NULL) ? (_T("%f")) : (lpFormat), __rValue);
		SetWindowTextW(strTemp);
		EnableWindow(__isEnable ? TRUE : FALSE);
		return true;
	}
	bool SetItemData(__int64 __nValue, __int64 __nDenominator, bool __isEnable = true, LPCTSTR lpFormat = NULL) {
		int nLeng = (int)log10((double)__nDenominator);
		CString strFormat;
		strFormat.Format(_T("%%0.%df"), nLeng);
		CString strTemp;
		strTemp.Format((lpFormat == NULL) ? (strFormat) : (lpFormat), (double)__nValue / __nDenominator);

		SetWindowTextW(strTemp);
		EnableWindow(__isEnable ? TRUE : FALSE);
		return true;
	}
	bool SetItemData(double __dValue, bool __isEnable = true, LPCTSTR lpFormat = NULL) {
		CString strTemp;
		strTemp.Format((lpFormat == NULL) ? (_T("%f")) : (lpFormat), __dValue);
		strTemp.TrimRight(_T("0"));
		strTemp.TrimRight(_T("."));

		SetWindowTextW(strTemp);
		EnableWindow(__isEnable ? TRUE : FALSE);
		return true;
	}
	bool SetItemData(LPCTSTR __lpstrValue, bool __isEnable = true, bool __isCheck = false, bool __isShow = true)
	{
		SetWindowTextW(__lpstrValue);
		SetCheck(__isCheck ? TRUE : FALSE);
		EnableWindow(__isEnable ? TRUE : FALSE);
		ShowWindow(__isShow ? SW_SHOW : SW_HIDE);
		return true;
	}

	bool GetItemData(CString & __lpstrValue) {
		GetWindowTextW(__lpstrValue);
		return true;
	}
	bool GetItemData(LPTSTR __lpstrValue, int __nLength) {
		GetWindowText(__lpstrValue, __nLength);
		return true;
	}
	int GetItemData(int __nDefault) {
		CString strTemp;
		GetWindowTextW(strTemp);
		return CMNVParser::Str2Num(strTemp, __nDefault);
	}
	float GetItemData(float __rDefault) {
		CString strTemp;
		GetWindowTextW(strTemp);
		return CMNVParser::Str2Num(strTemp, __rDefault);
	}
	double GetItemData(double __dValue) {
		CString strTemp;
		GetWindowTextW(strTemp);
		return CMNVParser::Str2Num(strTemp, __dValue);
	}
	BOOL SetWindowPos(int __nX, int __nY, int __nWidth, int __nHeight) {
		return CButton::SetWindowPos(NULL, __nX, __nY, __nWidth, __nHeight, SWP_NOZORDER);
	}
	BOOL SetWindowPos(CRect & __rect) {
		return CButton::SetWindowPos(NULL, __rect.left, __rect.top, __rect.Width(), __rect.Height(), SWP_NOZORDER);
	}
};

class CMNVStatic : public CStatic {
public:
	bool InitStatic(LPTSTR __lpstrValue, bool __isShow) {
		SetWindowTextW(__lpstrValue);
		return ShowWindow(__isShow ? SW_SHOW : SW_HIDE) == TRUE;
	}

	bool SetItemData(int __nValue, bool __isEnable = true) {
		CString strTemp;
		strTemp.Format(_T("%d"), __nValue);
		SetWindowTextW(strTemp);
		EnableWindow(__isEnable ? TRUE : FALSE);
		return true;
	}
	bool SetItemData(float __rValue, bool __isEnable = true, LPCTSTR lpFormat = NULL) {
		CString strTemp;
		strTemp.Format((lpFormat == NULL) ? (_T("%f")) : (lpFormat), __rValue);
		SetWindowTextW(strTemp);
		EnableWindow(__isEnable ? TRUE : FALSE);
		return true;
	}
	bool SetItemData(__int64 __nValue, __int64 __nDenominator, bool __isEnable = true, LPCTSTR lpFormat = NULL) {
		int nLeng = (int)log10((double)__nDenominator);
		CString strFormat;
		strFormat.Format(_T("%%0.%df"), nLeng);
		CString strTemp;
		strTemp.Format((lpFormat == NULL) ? (strFormat) : (lpFormat), (double)__nValue / __nDenominator);

		SetWindowTextW(strTemp);
		EnableWindow(__isEnable ? TRUE : FALSE);
		return true;
	}
	bool SetItemData(double __dValue, bool __isEnable = true, LPCTSTR lpFormat = NULL) {
		CString strTemp;
		strTemp.Format((lpFormat == NULL) ? (_T("%f")) : (lpFormat), __dValue);
		strTemp.TrimRight(_T("0"));
		strTemp.TrimRight(_T("."));

		SetWindowTextW(strTemp);
		EnableWindow(__isEnable ? TRUE : FALSE);
		return true;
	}
	bool SetItemData(LPCTSTR __lpstrValue, bool __isEnable = true, bool __isShow = true)
	{
		SetWindowTextW(__lpstrValue);
		EnableWindow(__isEnable ? TRUE : FALSE);
		ShowWindow(__isShow ? SW_SHOW : SW_HIDE);
		return true;
	}

	bool GetItemData(CString & __lpstrValue) {
		GetWindowTextW(__lpstrValue);
		return true;
	}
	bool GetItemData(LPTSTR __lpstrValue, int __nLength) {
		GetWindowText(__lpstrValue, __nLength);
		return true;
	}
	int GetItemData(int __nDefault) {
		CString strTemp;
		GetWindowTextW(strTemp);
		return CMNVParser::Str2Num(strTemp, __nDefault);
	}
	float GetItemData(float __rDefault) {
		CString strTemp;
		GetWindowTextW(strTemp);
		return CMNVParser::Str2Num(strTemp, __rDefault);
	}
	double GetItemData(double __dValue) {
		CString strTemp;
		GetWindowTextW(strTemp);
		return CMNVParser::Str2Num(strTemp, __dValue);
	}
	BOOL SetWindowPos(int __nX, int __nY, int __nWidth, int __nHeight) {
		return CStatic::SetWindowPos(NULL, __nX, __nY, __nWidth, __nHeight, SWP_NOZORDER);
	}
	BOOL SetWindowPos(CRect & __rect) {
		return CStatic::SetWindowPos(NULL, __rect.left, __rect.top, __rect.Width(), __rect.Height(), SWP_NOZORDER);
	}
};
