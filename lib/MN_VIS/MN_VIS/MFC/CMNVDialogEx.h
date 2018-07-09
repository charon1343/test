#pragma once
#include "..\stdafx.h"
//#include <afxwin.h>         // MFC 핵심 및 표준 구성 요소입니다.
//#include <afxext.h>         // MFC 확장입니다.
//#include <atlbase.h>


enum MNV_ThreadID {
		MNV_TID_Algorithm = 1
	,	MNV_TID_PLC
	,	MNV_TID_Display
};
enum MNV_Command {
		CMD_MENU_Run, CMD_MENU_Manual, CMD_MENU_Model, CMD_MENU_Vision, CMD_MENU_System, CMD_MENU_Mode
	,	CMD_SYS_Layout
	,	CMD_Run_View, CMD_RUN_SelectChannel
	, CMD_None, CMD_MMCRun, CMD_MMCInspect, CMD_MMCCalibration, CMD_MMCCamera
	, CMD_SelectChannel
	, CMD_GrabEnable, CMD_GrabCamera, CMD_ImageLoad
	, CMD_GrabLive, CMD_GrabSingle, CMD_GrabCross
	, CMD_RunStart, CMD_RunTrigger, CMD_RunModel
	, CMD_CAMResolutionSet, CMD_CAMResolutionSearch, CMD_CameraLoad, CMD_CameraSave, CMD_CameraSelect
	, CMD_InspectChannel, CMD_InspectMaster, CMD_InspectEdit, CMD_InspectAccept, CMD_InspectLoad, CMD_InspectSave, CMD_InspectTest

	, CMD_Manual_SetPLCOut, CMD_Manual_SetPLCIn
	, CMD_Thread_Enable
	, CMD_Light_SetValue
	, CMD_Light_AddValue
	, CMD_Light_SubValue
	, CMD_Light_Update
	, CMD_Camera_Setting
	, CMD_Model_Load
	, CMD_Model_Save
	, CMD_Model_Select

	, CMD_Pattern_ShowMaster
	, CMD_Pattern_SetPattern

	, CMD_Reflash
	, CMD_ModelLive, CMD_ModelCapture

	, CMD_DisplayResult
};

class CMNVWnd : public CWnd {
public:
	BOOL SetWindowPos(RECT & rect) {
		return CWnd::SetWindowPos(NULL, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, SWP_NOZORDER);
	}
	BOOL SetWindowPos(int __nX, int __nY, int __nWidth, int __nHeight) {
		return CWnd::SetWindowPos(NULL, __nX, __nY, __nWidth, __nHeight, SWP_NOZORDER);
	}
	BOOL SetWindowPos(const CWnd * pWndInsertAfter, int x, int y, int cx, int cy, UINT nFlags) {
		return CWnd::SetWindowPos(pWndInsertAfter, x, y, cx, cy, nFlags);
	}
};
typedef CMNVWnd * PCMNVWnd;

class CMNVDialogEx : public CDialogEx {
protected:
	CWinThread *m_pThread;
	DWORD dwThreadID;
	CMNVDialogEx * m_pParent;
public:
	virtual int GetID() { return 0; }
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
		m_pThread = NULL;
		m_pParent = __pParentDlg;
		int nID = GetID();
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

	void ShowWindow(int __nCmdShow) { CDialogEx::ShowWindow(__nCmdShow); }
	void ShowWindow(bool __isShow) {
		CDialogEx::ShowWindow(__isShow ? SW_SHOW : SW_HIDE);
		RedrawWindow();
	}
	void FullScreen(bool __isMax) {
		//CDialogEx::Get
		CDialogEx::ShowWindow(__isMax ? SW_MAXIMIZE : SW_SHOWNORMAL);
	}

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
	virtual int OnCmd_Command(MNV_Command __Cmd, WPARAM __wParam, LPARAM __lParam) {
		//AfxMessageBox(_T("OnCmd_Command"));
		return 0;
	}
	CMNVDialogEx(UINT nIDTemplete, CWnd * pParent = (CWnd *)NULL) : CDialogEx(nIDTemplete, pParent) { dwThreadID = 0; }

	int GetSelectData(int __nID, int __nDefault) {
		CComboBox *pWnd = (CComboBox *)GetDlgItem(__nID);
		CString strTemp;
		pWnd->GetLBText(pWnd->GetCurSel(), strTemp);
		return CMNVParser::Str2Num(strTemp, __nDefault);
	}
	void SetSelectIndex(int __nID, int __nIndex) {
		CComboBox *pWnd = (CComboBox *)GetDlgItem(__nID);
		pWnd->SetCurSel(__nIndex);
	}
	void SetSelectValue(int __nID, int __nValue) {
		CComboBox *pWnd = (CComboBox *)GetDlgItem(__nID);

		CString strTemp;
		int nCount = pWnd->GetCount();
		for(int nIndex = 0; nIndex < nCount; ++nIndex) {
			pWnd->GetLBText(nIndex, strTemp);
			if (CMNVParser::Str2Num(strTemp, 0) == __nValue) {
				pWnd->SetCurSel(nIndex);
				return;
			}
		}
	}
	void SetSelectValue(int __nID, LPCTSTR __strValue) {
		CComboBox *pWnd = (CComboBox *)GetDlgItem(__nID);

		CString strTemp;
		int nCount = pWnd->GetCount();
		for(int nIndex = 0; nIndex < nCount; ++nIndex) {
			pWnd->GetLBText(nIndex, strTemp);
			if (strTemp == __strValue) {
				pWnd->SetCurSel(nIndex);
				return;
			}
		}
	}

	int GetSelectIndex(int __nID) {
		CComboBox *pWnd = (CComboBox *)GetDlgItem(__nID);
		return pWnd->GetCurSel();
	}
	bool GetSelectData(int __nID, CString & __lpstrValue) {
		CComboBox *pWnd = (CComboBox *)GetDlgItem(__nID);
		pWnd->GetLBText(pWnd->GetCurSel(), __lpstrValue);
		return true;
	}
	bool GetSelectData(int __nID, wchar_t * __pstrValue, int __nBuf) {
		CComboBox *pWnd = (CComboBox *)GetDlgItem(__nID);
		CString strTemp;
		pWnd->GetLBText(pWnd->GetCurSel(), strTemp);
		//strTemp.Left(__nBuf - 1);
		wsprintf(__pstrValue, _T("%s"), strTemp.Left(__nBuf - 1));
		return true;
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
	bool SetItemData(int __nID, __int64 __nValue, __int64 __nDenominator, bool __isEnable = true, LPCTSTR lpFormat = NULL) {
		int nLeng = (int)log10((double)__nDenominator);
		CString strFormat;
		strFormat.Format(_T("%%0.%df"), nLeng);
		CString strTemp;
		strTemp.Format((lpFormat == NULL) ? (strFormat) : (lpFormat), (double)__nValue / __nDenominator);
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
		return CMNVParser::Str2Num(strTemp, __nDefault);
	}
	float GetItemData(int __nID, float __rDefault) {
		CWnd * pWnd = GetDlgItem(__nID);
		if (pWnd == NULL) return false;

		CString strTemp;
		pWnd->GetWindowTextW(strTemp);
		return CMNVParser::Str2Num(strTemp, __rDefault);
	}
	double GetItemData(int __nID, double __dValue) {
		CWnd * pWnd = GetDlgItem(__nID);
		if (pWnd == NULL) return false;

		CString strTemp;
		pWnd->GetWindowTextW(strTemp);
		return CMNVParser::Str2Num(strTemp, __dValue);
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

	void CreateThread() { m_pThread = AfxBeginThread(Thread_Create, this, 0, 0, 0); }
	void EndThread() { 
		if (m_pThread != NULL)
			TerminateThread(m_pThread->m_hThread, 0);
	}
	static UINT Thread_Create(LPVOID pParam) {
		HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);// COINIT_APARTMENTTHREADED);

		((CMNVDialogEx *)pParam)->Thread();

		if (hr != RPC_E_CHANGED_MODE) CoUninitialize();
		return 0;
	}
	virtual void Thread() { }
	BOOL SetWindowPos(RECT & rect) {
		return CDialogEx::SetWindowPos(NULL, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, SWP_NOZORDER);
	}
	BOOL SetWindowPos(int __nX, int __nY, int __nWidth, int __nHeight) {
		return CDialogEx::SetWindowPos(NULL, __nX, __nY, __nWidth, __nHeight, SWP_NOZORDER);
	}
	BOOL SetWindowPos(const CWnd * pWndInsertAfter, int x, int y, int cx, int cy, UINT nFlags) {
		return CDialogEx::SetWindowPos(pWndInsertAfter, x, y, cx, cy, nFlags);
	}

	BOOL SetWindowPos(int __nID, RECT& rect) {
		CWnd * pWnd = GetDlgItem(__nID);
		if (pWnd != NULL)
			return pWnd->SetWindowPos(NULL, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, SWP_NOZORDER);
		return FALSE;
	}
	BOOL SetWindowPos(int __nID, int __nX, int __nY, int __nWidth, int __nHeight) {
		CWnd * pWnd = GetDlgItem(__nID);
		if (pWnd != NULL)
			return pWnd->SetWindowPos(NULL, __nX, __nY, __nWidth, __nHeight, SWP_NOZORDER);
		return FALSE;
	}
};
