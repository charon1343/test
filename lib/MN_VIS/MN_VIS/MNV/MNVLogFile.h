#pragma once
#include <windows.h>
#include "MNVFile.h"
#include <winbase.h>

class CMNVLogFile {
	CString m_strPath;
	CString m_strFile;

	CString m_strSection;
	CString m_strProcess;
public:
	void WriteLog(LPCTSTR __strContents) {
		SYSTEMTIME stSysTime;
		GetLocalTime(&stSysTime);
		CString strFileName;
		strFileName.Format(_T("%s_%04d%02d%02d.log"), m_strFile, stSysTime.wYear, stSysTime.wMonth, stSysTime.wDay);
		CMNVFile File;
		CString strContents;
		strContents.Format(_T("[%04d-%02d-%02d %02d:%02d:%02d.%03d] %s\r\n")
				, stSysTime.wYear, stSysTime.wMonth, stSysTime.wDay, stSysTime.wHour, stSysTime.wMinute, stSysTime.wSecond, stSysTime.wMilliseconds
				, __strContents);
		File.WriteFile(m_strPath, strFileName, strContents);
	}

	CMNVLogFile(LPCTSTR __lpSection, LPCTSTR __lpProcess, LPCTSTR __lpPath, LPCTSTR __lpFile) {
		SYSTEMTIME stSysTime;
		GetLocalTime(&stSysTime);

		m_strPath = __lpPath;
		m_strFile = __lpFile;
		m_strSection = __lpSection;
		m_strProcess = __lpProcess;
		CString Temp;

		Temp.Format(_T("MNV %s.%s : Begin Process"), m_strSection, m_strProcess);
		WriteLog(Temp);
	}
	~CMNVLogFile() {
		CString Temp;
		Temp.Format(_T("MNV %s.%s : End Process"), m_strSection, m_strProcess);
		WriteLog(Temp);
	}
	void OutputMessage(LPCTSTR __lpMsg) {
		CString Temp;
		Temp.Format(_T("MNV %s.%s : Message[%s]"), m_strSection, m_strProcess, __lpMsg);
		WriteLog(Temp);
	}
	void OutputData(LPCTSTR __lpLabel, double __dValue) {
		CString Temp;
		Temp.Format(_T("MNV %s.%s : %s[%f]"), m_strSection, m_strProcess, __lpLabel, __dValue);
		WriteLog(Temp);
	}
	void OutputData(LPCTSTR __lpLabel, int __nValue) {
		CString Temp;
		Temp.Format(_T("MNV %s.%s : %s[%d]"), m_strSection, m_strProcess, __lpLabel, __nValue);
		WriteLog(Temp);
	}
	void OutputData(LPCTSTR __lpLabel, LPCTSTR __strValue) {
		CString Temp;
		Temp.Format(_T("MNV %s.%s : %s[%s]"), m_strSection, m_strProcess, __lpLabel, __strValue);
		WriteLog(Temp);
	}
	void OutputData(LPCTSTR __lpLabel, bool __isValue) {
		CString Temp;
		Temp.Format(_T("MNV %s.%s : %s[%s]"), m_strSection, m_strProcess, __lpLabel, __isValue ? _T("true") : _T("false"));
		WriteLog(Temp);
	}
};
