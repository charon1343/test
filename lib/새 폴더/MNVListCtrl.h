#pragma once

#include <afxwin.h>

#include "MNVParser.h"

class CMNVListCtrl : public CListCtrl {
public:
	void GetItem(int __nItem, int __nSubItem, CString & __strValue) {
		__strValue = GetItemText(__nItem, __nSubItem);
	}
	void GetItem(int __nItem, int __nSubItem, wchar_t * __strValue, int __nLength) {
		CString strTemp;
		strTemp = GetItemText(__nItem, __nSubItem);
		wsprintf(__strValue, _T("%s"), strTemp.Left(__nLength - 1));
	}
	int GetItem(int __nItem, int __nSubItem, int __nDefault) {
		CString strTemp = GetItemText(__nItem, __nSubItem);
		return CMNVParser::Str2Num(strTemp, __nDefault);
	}
	float GetItem(int __nItem, int __nSubItem, float __nDefault) {
		CString strTemp = GetItemText(__nItem, __nSubItem);
		return CMNVParser::Str2Num(strTemp, __nDefault);
	}
	double GetItem(int __nItem, int __nSubItem, double __nDefault) {
		CString strTemp = GetItemText(__nItem, __nSubItem);
		return CMNVParser::Str2Num(strTemp, __nDefault);
	}

	void SetItem(int __nItem, int __nSubItem, LPCTSTR __strValue) {
		SetItemText(__nItem, __nSubItem, __strValue);
	}
	void SetItem(int __nItem, int __nSubItem, double __dValue, LPCTSTR lpFormat = NULL) {
		CString strValue;
		strValue.Format( (lpFormat == NULL) ? (_T("%.3f")) : (lpFormat), __dValue);
		SetItemText(__nItem, __nSubItem, strValue);
	}
	void SetItem(int __nItem, int __nSubItem, int __nValue) {
		CString strValue;
		strValue.Format(_T("%d"), __nValue);
		SetItemText(__nItem, __nSubItem, strValue);
	}
	void SetItem(int __nItem, int __nSubItem, float __fValue, LPCTSTR lpFormat = NULL) {
		CString strValue;
		strValue.Format( (lpFormat == NULL) ? (_T("%.3f")) : (lpFormat), __fValue);
		SetItemText(__nItem, __nSubItem, strValue);
	}
	void SetItem(int __nItem, int __nSubItem, bool __fValue) {
		SetItemText(__nItem, __nSubItem, __fValue ? _T("True") : _T("False"));
	}
	void SetItem(int __nItem, int __nSubItem, SYSTEMTIME & __stTime) {
		CString strValue;
		strValue.Format(_T("%04d/%02d/%02d %02d:%02d:%02d.%03d"), __stTime.wYear, __stTime.wMonth, __stTime.wDay, __stTime.wHour, __stTime.wMinute, __stTime.wSecond, __stTime.wMilliseconds);
		SetItemText(__nItem, __nSubItem, strValue);
	}
	int InsertFirst(int __nLimit) {
		while (GetItemCount() > (__nLimit - 1)) { DeleteItem(GetItemCount() - 1); }
		return CListCtrl::InsertItem(0, _T(""));
	}
	int InsertEnd(int __nLimit) {
		while (GetItemCount() > (__nLimit - 1)) { DeleteItem(0); }
		return CListCtrl::InsertItem(GetItemCount(), _T(""));
	}
	int InsertFirst(LPCTSTR __str, int __nLimit) {
		while (GetItemCount() > (__nLimit - 1)) { DeleteItem(GetItemCount() - 1); }
		return CListCtrl::InsertItem(0, __str);
	}
	int InsertEnd(LPCTSTR __str, int __nLimit) {
		while (GetItemCount() > (__nLimit - 1)) { DeleteItem(0); }
		return CListCtrl::InsertItem(GetItemCount(), __str);
	}
};
