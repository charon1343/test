#pragma once
#include <WinBase.h>

class MNVDebugString {
	CString m_strSection;
	CString m_strProcess;
public:
	MNVDebugString(LPCTSTR __lpSection, LPCTSTR __lpProcess) {
		m_strSection = __lpSection;
		m_strProcess = __lpProcess;
		CString Temp;
		Temp.Format(_T("MNV %s.%s : Begin Process"), m_strSection, m_strProcess);
		OutputDebugString(Temp);
	}
	~MNVDebugString() {
		CString Temp;
		Temp.Format(_T("MNV %s.%s : End Process"), m_strSection, m_strProcess);
		OutputDebugString(Temp);
	}
	void OutputMessage(LPCTSTR __lpMsg) {
		CString Temp;
		Temp.Format(_T("MNV %s.%s : Message[%s]"), m_strSection, m_strProcess, __lpMsg);
		OutputDebugString(Temp);
	}
	void OutputData(LPCTSTR __lpLabel, double __dValue) {
		CString Temp;
		Temp.Format(_T("MNV %s.%s : %s[%f]"), m_strSection, m_strProcess, __lpLabel, __dValue);
		OutputDebugString(Temp);
	}
	void OutputData(LPCTSTR __lpLabel, int __nValue) {
		CString Temp;
		Temp.Format(_T("MNV %s.%s : %s[%d]"), m_strSection, m_strProcess, __lpLabel, __nValue);
		OutputDebugString(Temp);
	}
	void OutputData(LPCTSTR __lpLabel, LPCTSTR __strValue) {
		CString Temp;
		Temp.Format(_T("MNV %s.%s : %s[%s]"), m_strSection, m_strProcess, __lpLabel, __strValue);
		OutputDebugString(Temp);
	}
	void OutputData(LPCTSTR __lpLabel, bool __isValue) {
		CString Temp;
		Temp.Format(_T("MNV %s.%s : %s[%s]"), m_strSection, m_strProcess, __lpLabel, __isValue ? _T("true") : _T("false"));
		OutputDebugString(Temp);
	}
};
class CallStack {
	CString strMsg;
public:
	CallStack(LPCTSTR __lpMsg) {
		strMsg = __lpMsg;
		CString Temp;
		Temp.Format(_T("[MNV:0x%08x]BEGIN: %s"), this, strMsg);
		OutputDebugString(Temp);
	}
	~CallStack() {
		CString Temp;
		Temp.Format(_T("[MNV:0x%08x]END: %s"), this, strMsg);
		OutputDebugString(Temp);
	}
	void OutputData(LPCTSTR __lpMsg) {
		CString Temp;
		Temp.Format(_T("[MNV:0x%08x]Msg: %s"), this, __lpMsg);
		OutputDebugString(Temp);
	}
	void OutputData(double __dValue) {
		CString Temp;
		Temp.Format(_T("[MNV:0x%08x]Msg: %f"), this, __dValue);
		OutputDebugString(Temp);
	}
	void OutputData(int __nValue) {
		CString Temp;
		Temp.Format(_T("[MNV:0x%08x]Msg: %d"), this, __nValue);
		OutputDebugString(Temp);
	}
};
