#pragma once

#include "StdAfx.h"
enum MNV_Command { CMD_None, CMD_MMCRun, CMD_MMCInspect, CMD_MMCCalibration, CMD_MMCCamera
	, CMD_SelectChannel
	, CMD_GrabEnable, CMD_GrabCamera, CMD_ImageLoad
	, CMD_GrabLive, CMD_GrabSingle, CMD_GrabCross
	, CMD_RunStart, CMD_RunTrigger, CMD_RunModel
	, CMD_CAMResolutionSet, CMD_CAMResolutionSearch, CMD_CameraLoad, CMD_CameraSave, CMD_CameraSelect
	, CMD_InspectChannel, CMD_InspectMaster, CMD_InspectEdit, CMD_InspectAccept, CMD_InspectLoad, CMD_InspectSave, CMD_InspectTest
};

class CMNVDialogEx : public CDialogEx {
protected:
	CMNVDialogEx * m_pParent;
public:
	bool LoadString(int __nID, CString & __strTemp) {
		wchar_t lpBuffer[1024];
		int nLength = ::LoadStringW(NULL, __nID, lpBuffer, 1024);
		__strTemp.Format(_T("%s"), lpBuffer);
		return nLength > 0;
	}
	bool IsVisible() {
		return (this->GetStyle() & WS_VISIBLE) == WS_VISIBLE;
	}
	void Create(UINT __nIDTemplate, CWnd * __pWnd, CMNVDialogEx * __pParentDlg) {
		m_pParent = __pParentDlg;
		CDialogEx::Create(__nIDTemplate, __pWnd);
	}
	virtual void OnOK() { }
	virtual void OnCancel() { }
	void MoveDlgItem(int __nID, int __nX, int __nY, int __sX, int __sY, int __nWidth, int __nHeigth, int __nMargin) {
		GetDlgItem(__nID)->MoveWindow
			(	__nMargin + __nWidth * __nX
			,	__nMargin + __nHeigth * __nY
			,	__nWidth * __sX - __nMargin
			,	__nHeigth * __sY - __nMargin);
	}

	void ShowWindow(bool __isShow) { CDialogEx::ShowWindow(__isShow ? SW_SHOW : SW_HIDE); }
	void SaveCaptureImage(CWnd *__pWnd, LPCTSTR __FilePath) {
		CWindowDC SrcDC(__pWnd);
		CRect Rect;
		GetWindowRect(&Rect);
		CImage Image;
		int cx = Rect.Width();
		int cy = Rect.Height();
		Image.Create(cx, cy, SrcDC.GetDeviceCaps(BITSPIXEL));
		CDC* pDC = CDC::FromHandle(Image.GetDC());
		pDC->BitBlt(0, 0, cx, cy, &SrcDC, 0, 0, SRCCOPY);
		Image.ReleaseDC();
		Image.Save(__FilePath, Gdiplus::ImageFormatJPEG);
	}
	void SaveCaptureImage(LPCTSTR __FilePath) {
		CWindowDC SrcDC(this);
		CRect Rect;
		GetWindowRect(&Rect);
		CImage Image;
		int cx = Rect.Width();
		int cy = Rect.Height();
		Image.Create(cx, cy, SrcDC.GetDeviceCaps(BITSPIXEL));
		CDC* pDC = CDC::FromHandle(Image.GetDC());
		pDC->BitBlt(0, 0, cx, cy, &SrcDC, 0, 0, SRCCOPY);
		Image.ReleaseDC();
		Image.Save(__FilePath, Gdiplus::ImageFormatJPEG);
	}
	void SetParent(CMNVDialogEx * __pDlg) { m_pParent = __pDlg; }
	virtual void OnCmd_Command(MNV_Command __Cmd, WPARAM __wParam, LPARAM __lParam) {
		//AfxMessageBox(_T("OnCmd_Command"));
	}
	CMNVDialogEx(UINT nIDTemplete, CWnd * pParent = (CWnd *)NULL) : CDialogEx(nIDTemplete, pParent) { }
	static __int8 Str2Num(LPCTSTR __lpValue, __int8 __bnDefault) {
		int nSigned = 1;
		int nResult = 0;
		int nLength = wcslen(__lpValue);
		int nIndex = 0;
		if (_T('-') == __lpValue[nIndex]) {
			++nIndex;
			nSigned = -1;
		}
		for(; nIndex < nLength; ++nIndex) {
			if (_T('0') <= __lpValue[nIndex] && __lpValue[nIndex] <= _T('9')) {
				nResult = nResult * 10 + __lpValue[nIndex] - _T('0');
			}
			else if (_T('.') == __lpValue[nIndex]) {
				break;
			}
			else {
				return __bnDefault;
			}
		}
		return (__int8)(nResult * nSigned);
	}
	static __int16 Str2Num(LPCTSTR __lpValue, __int16 __wdnDefault) {
		__int64 nResult = 0;
		int nSigned = 1;
		int nLength = wcslen(__lpValue);
		int nIndex = 0;
		if (_T('-') == __lpValue[nIndex]) {
			++nIndex;
			nSigned = -1;
		}
		for(; nIndex < nLength; ++nIndex) {
			if (_T('0') <= __lpValue[nIndex] && __lpValue[nIndex] <= _T('9')) {
				nResult = nResult * 10 + __lpValue[nIndex] - _T('0');
			}
			else if (_T('.') == __lpValue[nIndex]) {
				break;
			}
			else {
				return __wdnDefault;
			}
		}
		return (__int16)nResult * nSigned;
	}
	static __int32 Str2Num(LPCTSTR __lpValue, __int32 __dwnDefault) {
		__int64 nResult = 0;
		int nSigned = 1;
		int nLength = wcslen(__lpValue);
		int nIndex = 0;
		if (_T('-') == __lpValue[nIndex]) {
			++nIndex;
			nSigned = -1;
		}
		for(; nIndex < nLength; ++nIndex) {
			if (_T('0') <= __lpValue[nIndex] && __lpValue[nIndex] <= _T('9')) {
				nResult = nResult * 10 + __lpValue[nIndex] - _T('0');
			}
			else if (_T('.') == __lpValue[nIndex]) {
				break;
			}
			else {
				return __dwnDefault;
			}
		}
		return (__int32)(nResult * nSigned);
	}
	static __int64 Str2Num(LPCTSTR __lpValue, __int64 __qwnDefault) {
		__int64 nResult = 0;
		int nSigned = 1;
		int nLength = wcslen(__lpValue);
		int nIndex = 0;
		if (_T('-') == __lpValue[nIndex]) {
			++nIndex;
			nSigned = -1;
		}
		for(; nIndex < nLength; ++nIndex) {
			if (_T('0') <= __lpValue[nIndex] && __lpValue[nIndex] <= _T('9')) {
				nResult = nResult * 10 + __lpValue[nIndex] - _T('0');
			}
			else if (_T('.') == __lpValue[nIndex]) {
				break;
			}
			else {
				return __qwnDefault;
			}
		}
		return nResult * nSigned;
	}
	static double Str2Num(LPCTSTR __lpValue, double __dDefault) {
		int nSigned = 1;
		int nLength = wcslen(__lpValue);

		int nValue = 0;
		double nDenominator = 0;
		double nNumerator = 0;
		int nIndex = 0;
		if (_T('-') == __lpValue[nIndex]) {
			++nIndex;
			nSigned = -1;
		}
		for(;nIndex < nLength; ++nIndex) {
			if (_T('0') <= __lpValue[nIndex] && __lpValue[nIndex] <= _T('9')) {
				nNumerator = nNumerator * 10 + __lpValue[nIndex] - _T('0');
				nDenominator *= 10;
			}
			else if (_T('.') == __lpValue[nIndex]) {
				nDenominator = 1;
			}
			else {
				return __dDefault;
			}
		}
		if (nDenominator == 0) 
			return ((double)nNumerator) * nSigned;
		else
			return ((double)nNumerator / nDenominator) * nSigned;
	}
	static float Str2Num(LPCTSTR __lpValue, float __dDefault) {
		int nSigned = 1;
		int nLength = wcslen(__lpValue);

		int nValue = 0;
		float nDenominator = 0;
		float nNumerator = 0;
		int nIndex = 0;
		if (_T('-') == __lpValue[nIndex]) {
			++nIndex;
			nSigned = -1;
		}
		for(;nIndex < nLength; ++nIndex) {
			if (_T('0') <= __lpValue[nIndex] && __lpValue[nIndex] <= _T('9')) {
				nNumerator = nNumerator * 10 + __lpValue[nIndex] - _T('0');
				nDenominator *= 10;
			}
			else if (_T('.') == __lpValue[nIndex]) {
				nDenominator = 1;
			}
			else {
				return __dDefault;
			}
		}
		if (nDenominator == 0) 
			return ((float)nNumerator) * nSigned;
		else
			return ((float)nNumerator / nDenominator) * nSigned;
	}

	bool SetItemData(int __nID, int __nValue, bool __isEnable = true) {
			CString strTemp;
			strTemp.Format(_T("%d"), __nValue);
			CWnd * pWnd = GetDlgItem(__nID);
			if (pWnd != NULL) {
				pWnd->SetWindowTextW(strTemp);
				pWnd->EnableWindow(__isEnable ? TRUE : FALSE);
				return true;
			}
			return false;
	}
	bool SetItemData(int __nID, float __rValue, bool __isEnable = true, LPCTSTR lpFormat = NULL) {
		CString strTemp;
		strTemp.Format((lpFormat == NULL) ? (_T("%f")) : (lpFormat), __rValue);
		CWnd * pWnd = GetDlgItem(__nID);
		if (pWnd != NULL) {
			pWnd->SetWindowTextW(strTemp);
			pWnd->EnableWindow(__isEnable ? TRUE : FALSE);
			return true;
		}
		return false;
	}
	bool SetItemData(int __nID, double __dValue, bool __isEnable = true, LPCTSTR lpFormat = NULL) {
		CString strTemp;
		strTemp.Format((lpFormat == NULL) ? (_T("%f")) : (lpFormat), __dValue);
		strTemp.TrimRight(_T("0"));
		strTemp.TrimRight(_T("."));

		CWnd * pWnd = GetDlgItem(__nID);
		if (pWnd != NULL) {
			pWnd->SetWindowTextW(strTemp);
			pWnd->EnableWindow(__isEnable ? TRUE : FALSE);
			return true;
		}
		return false;
	}
	bool SetItemData(int __nID, LPCTSTR __lpstrValue, bool __isEnable = true)
	{
		CWnd * pWnd = GetDlgItem(__nID);
		if (pWnd != NULL) {
			pWnd->SetWindowTextW(__lpstrValue);
			pWnd->EnableWindow(__isEnable ? TRUE : FALSE);
			return true;
		}
		return false;
	}

	bool GetItemData(int __nID, CString & __lpstrValue) {
		CWnd * pWnd = GetDlgItem(__nID);
		if (pWnd == NULL) return false;

		pWnd->GetWindowTextW(__lpstrValue);
		return true;
	}
	bool GetItemData(int __nID, LPTSTR __lpstrValue, int __nLength) {
		CWnd * pWnd = GetDlgItem(__nID);
		if (pWnd == NULL) return false;

		pWnd->GetWindowText(__lpstrValue, __nLength);
		return true;
	}
	int GetItemData(int __nID, int __nDefault) {
		CWnd * pWnd = GetDlgItem(__nID);
		if (pWnd == NULL) return false;

		CString strTemp;
		pWnd->GetWindowTextW(strTemp);
		return Str2Num(strTemp, __nDefault);
	}
	float GetItemData(int __nID, float __rDefault) {
		CWnd * pWnd = GetDlgItem(__nID);
		if (pWnd == NULL) return false;

		CString strTemp;
		pWnd->GetWindowTextW(strTemp);
		return Str2Num(strTemp, __rDefault);
	}
	double GetItemData(int __nID, double __dValue) {
		CWnd * pWnd = GetDlgItem(__nID);
		if (pWnd == NULL) return false;

		CString strTemp;
		pWnd->GetWindowTextW(strTemp);
		return Str2Num(strTemp, __dValue);
	}

	bool GetItemCheck(int __nID) {
		CButton * pBtn = (CButton*)GetDlgItem(__nID);
		if (pBtn == NULL) return false;
		return pBtn->GetCheck() == TRUE;
	}
	bool SetItemCheck(int __nID, bool __isCheck = true, bool __isEnable = true) {
		CButton * pBtn = (CButton*)GetDlgItem(__nID);
		if (pBtn == NULL) return false;
		pBtn->SetCheck(__isCheck ? TRUE : FALSE);
		pBtn->EnableWindow(__isEnable ? TRUE : FALSE);
		return true;
	}

	int GetItemSize(int __nID, int & __nWidth, int & __nHeight) {
		CRect rect;
		GetDlgItem(__nID)->GetWindowRect(rect);
		__nWidth = rect.Width();
		__nHeight = rect.Height();
		return __nWidth > __nHeight ? __nHeight : __nWidth;
	}
};

class CMNVListCtrl : public CListCtrl {
public:
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
	void InsertFirst(int __nLimit) {
		CListCtrl::InsertItem(0, _T(""));
		while (GetItemCount() > __nLimit) { DeleteItem(GetItemCount() - 1); }
	}
	void InsertEnd(int __nLimit) {
		CListCtrl::InsertItem(GetItemCount(), _T(""));
		while (GetItemCount() > __nLimit) { DeleteItem(0); }
	}
};
