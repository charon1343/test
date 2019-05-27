#pragma once

//#include <afxwin.h> 
//#include "..\stdafx.h"
#include "MNVFile.h"

//#include <atlbase.h>
//#include <atlstr.h>

#define SIZE_64K	65536
#define SIZE_512K	524288
#define SIZE_1MB	1048576

#include <map>
using namespace std;

#include "MNVLock.h"

typedef unsigned __int64 TPMNV_HashCode;
class CMNVHashCode {
	TPMNV_HashCode m_HashCode;
public:
	CMNVHashCode() { m_HashCode = 0; }
	void SetHashCode(LPCTSTR __lpValue) {
		char strMultiBytes[256] = {0,};
		WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK, __lpValue, (int)wcslen(__lpValue), strMultiBytes, 256, NULL, NULL);

		int nSize = ((int)strlen(strMultiBytes) + 7) / 8;

		TPMNV_HashCode * pData = (unsigned __int64 *)strMultiBytes;

		m_HashCode = 0;
		for(int nIndex = 0; nIndex < nSize; ++nIndex) {
			m_HashCode = m_HashCode ^ pData[nIndex];
		}
	}
	CMNVHashCode(LPCTSTR __lpValue) { SetHashCode(__lpValue); }
	CMNVHashCode(TPMNV_HashCode __uiValue) { m_HashCode = __uiValue; }
	operator TPMNV_HashCode() { return m_HashCode; }
	void operator = (LPCTSTR __lpValue) { SetHashCode(__lpValue); }
	void operator = (TPMNV_HashCode __uiValue) { m_HashCode = __uiValue; }
};

class MNVIniKey {
	MNVLock m_Lock;
	CString m_strKey;
	CString m_strValue;
public:
	MNVIniKey() {
		m_strKey = _T("");
		m_strValue = _T("");
	}
	MNVIniKey(LPCTSTR __lpKey, LPCTSTR __lpValue) {
		m_strKey = __lpKey;
		m_strValue = __lpValue;
	}
	void operator = (MNVIniKey & __Value) {
		CMNVLock Lock(&m_Lock, MNVLM_Write);
		m_strKey = __Value.m_strKey;
		m_strValue = __Value.m_strValue;
	}
	bool isHitKey(LPCTSTR __lpKey) {
		CMNVLock Lock(&m_Lock, MNVLM_Read);
		return m_strKey == __lpKey;
	}
	CString & GetKey() {
		CMNVLock Lock(&m_Lock, MNVLM_Read);
		return m_strKey;
	}
	CString & GetValue() {
		CMNVLock Lock(&m_Lock, MNVLM_Read);
		return m_strValue;
	}
	void SetValue(LPCTSTR __lpValue) {
		CMNVLock Lock(&m_Lock, MNVLM_Write);
		m_strValue = __lpValue;
	}
};
typedef multimap<TPMNV_HashCode, MNVIniKey>				TPMNV_IniKeyList;
typedef multimap<TPMNV_HashCode, MNVIniKey>::iterator	TPMNV_IniKeyItem;

__int8 Str2Num(LPCTSTR __lpValue, __int8 __bnDefault);
__int16 Str2Num(LPCTSTR __lpValue, __int16 __wdnDefault);
__int32 Str2Num(LPCTSTR __lpValue, __int32 __dwDefault);
__int64 Str2Num(LPCTSTR __lpValue, __int64 __qwnDefault);
double Str2Num(LPCTSTR __lpValue, double __dDefault);

class MNVIniSection {
public:
	MNVLock m_Lock;
	CString m_strSection;
	TPMNV_IniKeyList m_lstKeys;
	TPMNV_IniKeyItem m_itmKey;
	
public:
	MNVIniSection() { }
	MNVIniSection(LPCTSTR __lpSection) { m_strSection = __lpSection; }
	~MNVIniSection() {
		CMNVLock Lock(&m_Lock, MNVLM_Write);
		m_lstKeys.clear();
	}

	bool GetKeyValue(LPCTSTR __lpKey, CString & __strValue) {
		CMNVHashCode uiKey = __lpKey;
		CMNVLock Lock(& m_Lock, MNVLM_Read);

		TPMNV_IniKeyItem itmCurrent = m_lstKeys.lower_bound(uiKey);
		TPMNV_IniKeyItem itmEnd = m_lstKeys.upper_bound(uiKey);

		for(; itmCurrent != itmEnd; ++itmCurrent) {
			if (itmCurrent->second.isHitKey(__lpKey)) {
				__strValue = itmCurrent->second.GetValue();
				return true;
			}
		}
		return false;
	}
	bool GetKeyValue(LPCTSTR __lpKey, int & __nValue) {
		CMNVHashCode uiKey = __lpKey;

		CMNVLock Lock(& m_Lock, MNVLM_Read);
		TPMNV_IniKeyItem itmCurrent = m_lstKeys.lower_bound(uiKey);
		TPMNV_IniKeyItem itmEnd = m_lstKeys.upper_bound(uiKey);

		for(; itmCurrent != itmEnd; ++itmCurrent) {
			if (itmCurrent->second.isHitKey(__lpKey)) {
				__nValue = Str2Num(itmCurrent->second.GetValue(), (int)0);
				return true;
			}
		}
		return false;
	}
	bool GetKeyValue(LPCTSTR __lpKey, double & __dValue) {
		CMNVHashCode uiKey = __lpKey;

		CMNVLock Lock(& m_Lock, MNVLM_Read);
		TPMNV_IniKeyItem itmCurrent = m_lstKeys.lower_bound(uiKey);
		TPMNV_IniKeyItem itmEnd = m_lstKeys.upper_bound(uiKey);

		for(; itmCurrent != itmEnd; ++itmCurrent) {
			if (itmCurrent->second.isHitKey(__lpKey)) {
				__dValue = Str2Num(itmCurrent->second.GetValue(), (double)0);
				return true;
			}
		}
		return false;
	}

	bool SetKey(LPCTSTR __lpKey, LPCTSTR __lpValue) {
		CMNVHashCode uiKey = __lpKey;

		CMNVLock Lock(& m_Lock, MNVLM_Write);
		TPMNV_IniKeyItem itemLower = m_lstKeys.lower_bound(uiKey);
		TPMNV_IniKeyItem itemUpper = m_lstKeys.upper_bound(uiKey);
		for(; itemLower != itemUpper; ++itemLower) {
			if( itemLower->second.isHitKey(__lpKey)) {
				itemLower->second.SetValue(__lpValue);
				return true;
			}
		}
		
		m_lstKeys.insert(pair<TPMNV_HashCode, MNVIniKey>(uiKey, MNVIniKey(__lpKey, __lpValue)));
		return false;
	}
	bool RemoveKey(LPCTSTR __lpKey) {
		CMNVHashCode uiKey = __lpKey;

		CMNVLock Lock(& m_Lock, MNVLM_Write);
		TPMNV_IniKeyItem itemLower = m_lstKeys.lower_bound(uiKey);
		TPMNV_IniKeyItem itemUpper = m_lstKeys.upper_bound(uiKey);
		for(; itemLower != itemUpper; ++itemLower) {
			if( itemLower->second.isHitKey(__lpKey)) {
				if (itemLower == m_itmKey) m_itmKey = m_lstKeys.end();
				m_lstKeys.erase(itemLower);
				return true;
			}
		}
		return false;
	}
	bool RemoveAll() { 
		CMNVLock Lock(& m_Lock, MNVLM_Write);

		m_itmKey = m_lstKeys.end();
		m_lstKeys.clear();
		return true;
	}
	bool SaveAll(LPCTSTR __lpFileName) {
		CMNVLock Lock(& m_Lock, MNVLM_Read);

		TPMNV_IniKeyItem itmCurrent = m_lstKeys.begin();
		TPMNV_IniKeyItem itmEnd = m_lstKeys.end();

		for(; itmCurrent != itmEnd; ++ itmCurrent) {
			WritePrivateProfileString(m_strSection, itmCurrent->second.GetKey(), itmCurrent->second.GetValue(), __lpFileName);
		}
		return true;
	}
	int GetPrivateProfileKeys(LPCWSTR __lpFileName)
	{
		WCHAR Buff[SIZE_64K];
		WCHAR Data[SIZE_64K];
		ZeroMemory(Buff, sizeof(WCHAR) * SIZE_64K);
		int nLength = GetPrivateProfileSection(m_strSection, Buff, sizeof(WCHAR) * SIZE_64K, __lpFileName);
		int nIndex = 0;
		int nCount = 0;
		CString strTemp;

		int nKeyLen = 0;
		//CMNVLock Lock(&m_Lock, MNVLM_Write);
		while (nIndex < nLength) {
			strTemp = &(Buff[nIndex]);
			nKeyLen = strTemp.Find(_T('='));
			if (nKeyLen > 0) {
				strTemp = strTemp.Left(nKeyLen);
				strTemp = strTemp.Trim();
				GetPrivateProfileString(m_strSection, strTemp, _T(""), Data, sizeof(WCHAR) * SIZE_64K, __lpFileName);
				SetKey(strTemp, Data);
			}
			nIndex += ((int)wcslen(&(Buff[nIndex])) + 1);
			++nCount;
		}
		return nCount;
	}

	bool FindKey(LPCTSTR __lpKey) {
		CMNVHashCode uiKey = __lpKey;
		CMNVLock Lock(&m_Lock, MNVLM_Read);
		TPMNV_IniKeyItem itmCurrent = m_lstKeys.lower_bound(uiKey);
		TPMNV_IniKeyItem itmEnd = m_lstKeys.upper_bound(uiKey);

		for(; itmCurrent != itmEnd; ++itmCurrent) {
			if (itmCurrent->second.isHitKey(__lpKey)) {
				m_itmKey = itmCurrent;
				return true;
			}
		}
		m_itmKey = m_lstKeys.begin();
		return false;
	}

	CMNVLock * BeginRead() { return new CMNVLock(&m_Lock, MNVLM_Read); }
	CMNVLock * BeginWrite() { return new CMNVLock(&m_Lock, MNVLM_Write); }
	bool BeginKey() {
		m_itmKey = m_lstKeys.begin();
		return m_itmKey != m_lstKeys.end();
	}
	bool NextKey(CString * __pKey = NULL, CString * __pValue = NULL) {
		if (m_itmKey != m_lstKeys.end()) {
			if (__pKey != NULL) { *__pKey = m_itmKey->second.GetKey(); }
			if (__pValue != NULL) { *__pValue = m_itmKey->second.GetValue(); }
			++m_itmKey;
			return true;
		}
		else
			return false;
	}
};
typedef multimap<TPMNV_HashCode, MNVIniSection>				TPMNV_IniSectionList;
typedef multimap<TPMNV_HashCode, MNVIniSection>::iterator	TPMNV_IniSectionItem;


class CMNVIni {
	MNVLock m_Lock;
	CString m_strFilePath;
	TPMNV_IniSectionList m_lstSections;
	TPMNV_IniSectionItem m_itmSection;

public:
	CMNVIni();
	CMNVIni(LPCTSTR __lpFilePath);
	void SetFilePath(LPCTSTR __lpFilePath);
	void clear();
	int GetPrivateProfileSections(LPCWSTR __lpFileName);
	bool LoadIni();
	bool SaveIni(LPCTSTR __lpFileName);
	bool FindSection(LPCTSTR __lpSection);
	bool BeginSection();
	bool NextSection(CString * __pStr = NULL);
	bool FindKey(LPCTSTR __lpKey);
	bool BeginKey();
	bool NextKey(CString * pStr = NULL);
	bool GetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, CString & __strValue);
	bool GetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, int & __nValue);
	bool GetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, double & __dValue);
	bool SetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, CString __strValue);
	bool SetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, int __nValue);
	bool SetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, double __dValue);
	bool RemoveSection(LPCTSTR __lpSection);
	bool RemoveKey(LPCTSTR __lpSection, LPCTSTR __lpKey);

	static bool GetCurrentDir(CString & __strDir) {
		wchar_t Buffer[1024];
		if (GetCurrentDirectory(1024, Buffer) > 0) {
			__strDir.Format(_T("%s"), Buffer);
			return true;
		}
		return false;
	}
	static bool GetCurrentDirPath(CString & __strPath, LPCTSTR __strFile)
	{
		wchar_t Buffer[1024];
		if (GetCurrentDirectory(1024, Buffer) > 0) {
			__strPath.Format(_T("%s\\%s"), Buffer, __strFile);
			return true;
		}
		return false;
	}
	static bool GetCurrentDirPath(CString & __strPath, LPCTSTR __strFile, LPCTSTR __strAddDir)
	{
		wchar_t Buffer[1024];
		if (GetCurrentDirectory(1024, Buffer) > 0) {
			__strPath.Format(_T("%s\\%s\\%s"), Buffer, __strAddDir, __strFile);
			return true;
		}
		return false;
	}
	static bool GetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, CString & __strValue, LPCTSTR __lpFilepath) {
		wchar_t Buf[1024];
		DWORD nResult = GetPrivateProfileString(__lpSection, __lpKey, _T(""), Buf, sizeof(wchar_t) * 1024, __lpFilepath);
		if (nResult > 0) {
			__strValue = Buf;
			return true;
		}
		return false;
	}
	static bool GetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, CString & __strValue, LPCTSTR __lpDefault, LPCTSTR __lpFilepath) {
		wchar_t Buf[1024];
		DWORD nResult = GetPrivateProfileString(__lpSection, __lpKey, _T(""), Buf, sizeof(wchar_t) * 1024, __lpFilepath);
		if (nResult > 0) {
			__strValue = Buf;
			return true;
		}
		__strValue = __lpDefault;
		return false;
	}
	static bool GetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, LPCTSTR __strValue, LPCTSTR __lpDefault, LPCTSTR __lpFilepath) {
		DWORD nResult = GetPrivateProfileString(__lpSection, __lpKey, _T(""), (LPWSTR)__strValue, sizeof(wchar_t) * 1024, __lpFilepath);
		if (nResult > 0) {
			return true;
		}
		wsprintf((LPWSTR)__strValue, __lpDefault); 
		return false;
	}

	static bool GetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, double & __dValue, double __dDefault, LPCTSTR __lpFilepath) {
		wchar_t Buf[1024];
		DWORD nResult = GetPrivateProfileString(__lpSection, __lpKey, _T(""), Buf, sizeof(wchar_t) * 1024, __lpFilepath);
		if (nResult > 0) {
			__dValue = Str2Num(Buf, __dDefault);
			return true;
		}
		return false;
	}
	static bool GetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, __int8 & __bnValue, __int8 __nbDefault, LPCTSTR __lpFilepath) {
		wchar_t Buf[1024];
		DWORD nResult = GetPrivateProfileString(__lpSection, __lpKey, _T(""), Buf, sizeof(wchar_t) * 1024, __lpFilepath);
		if (nResult > 0) {
			__bnValue = Str2Num(Buf, __nbDefault);
			return true;
		}
		return false;
	}
	static bool GetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, __int16 & __wdnValue, __int16 __nwdDefault, LPCTSTR __lpFilepath) {
		wchar_t Buf[1024];
		DWORD nResult = GetPrivateProfileString(__lpSection, __lpKey, _T(""), Buf, sizeof(wchar_t) * 1024, __lpFilepath);
		if (nResult > 0) {
			__wdnValue = Str2Num(Buf, __nwdDefault);
			return true;
		}
		return false;
	}
	static bool GetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, __int32 & __dwnValue, __int32 __dwnDefault, LPCTSTR __lpFilepath) {
		wchar_t Buf[1024];
		DWORD nResult = GetPrivateProfileString(__lpSection, __lpKey, _T(""), Buf, sizeof(wchar_t) * 1024, __lpFilepath);
		if (nResult > 0) {
			__dwnValue = Str2Num(Buf, __dwnDefault);
			return true;
		}
		return false;
	}
	static bool GetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, __int64 & __qwnValue, __int64 __qwnDefault, LPCTSTR __lpFilepath) {
		wchar_t Buf[1024];
		DWORD nResult = GetPrivateProfileString(__lpSection, __lpKey, _T(""), Buf, sizeof(wchar_t) * 1024, __lpFilepath);
		if (nResult > 0) {
			__qwnValue = Str2Num(Buf, __qwnDefault);
			return true;
		}
		return false;
	}

	static double GetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, double __dDefault, LPCTSTR __lpFilepath) {
		wchar_t Buf[1024];
		DWORD nResult = GetPrivateProfileString(__lpSection, __lpKey, _T(""), Buf, sizeof(wchar_t) * 1024, __lpFilepath);
		if (nResult > 0) {
			return Str2Num(Buf, __dDefault);
		}
		return __dDefault;
	}
	static char GetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, char __cDefault, LPCTSTR __lpFilepath) {
		wchar_t Buf[1024];
		DWORD nResult = GetPrivateProfileString(__lpSection, __lpKey, _T(""), Buf, sizeof(wchar_t) * 1024, __lpFilepath);
		if (nResult > 0) {
			return (char)Buf[0];
		}
		return __cDefault;
	}
	static __int16 GetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, __int16 __nwdDefault, LPCTSTR __lpFilepath) {
		wchar_t Buf[1024];
		DWORD nResult = GetPrivateProfileString(__lpSection, __lpKey, _T(""), Buf, sizeof(wchar_t) * 1024, __lpFilepath);
		if (nResult > 0) {
			return Str2Num(Buf, __nwdDefault);
		}
		return __nwdDefault;
	}
	static __int32 GetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, __int32 __dwnDefault, LPCTSTR __lpFilepath) {
		wchar_t Buf[1024];
		DWORD nResult = GetPrivateProfileString(__lpSection, __lpKey, _T(""), Buf, sizeof(wchar_t) * 1024, __lpFilepath);
		if (nResult > 0) {
			return Str2Num(Buf, __dwnDefault);
		}
		return __dwnDefault;
	}
	static __int64 GetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, __int64 __qwnDefault, LPCTSTR __lpFilepath) {
		wchar_t Buf[1024];
		DWORD nResult = GetPrivateProfileString(__lpSection, __lpKey, _T(""), Buf, sizeof(wchar_t) * 1024, __lpFilepath);
		if (nResult > 0) {
			return Str2Num(Buf, __qwnDefault);
		}
		return __qwnDefault;
	}

	static bool SetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, CString & __strValue, LPCTSTR __lpFilePath) {
		CMNVFile::CreatePath(__lpFilePath);
		return WritePrivateProfileString(__lpSection, __lpKey, __strValue, __lpFilePath) == TRUE;
	}
	static bool SetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, LPCTSTR __strValue, LPCTSTR __lpFilePath) {
		CMNVFile::CreatePath(__lpFilePath);
		return WritePrivateProfileString(__lpSection, __lpKey, __strValue, __lpFilePath) == TRUE;
	}
	static bool SetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, double __dValue, LPCTSTR __lpFilePath) {
		CMNVFile::CreatePath(__lpFilePath);
		CString strValue = _T("");
		strValue.Format(_T("%f"), __dValue);
		return WritePrivateProfileString(__lpSection, __lpKey, strValue, __lpFilePath) == TRUE;
	}
	static bool SetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, char __bValue, LPCTSTR __lpFilePath) {
		CMNVFile::CreatePath(__lpFilePath);
		CString strValue = _T("");
		strValue.Format(_T("%c"), __bValue);
		return WritePrivateProfileString(__lpSection, __lpKey, strValue, __lpFilePath) == TRUE;
	}
	static bool SetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, __int16 __wdValue, LPCTSTR __lpFilePath) {
		CMNVFile::CreatePath(__lpFilePath);
		CString strValue = _T("");
		strValue.Format(_T("%d"), __wdValue);
		return WritePrivateProfileString(__lpSection, __lpKey, strValue, __lpFilePath) == TRUE;
	}
	static bool SetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, __int32 __dwValue, LPCTSTR __lpFilePath) {
		CMNVFile::CreatePath(__lpFilePath);
		CString strValue = _T("");
		strValue.Format(_T("%d"), __dwValue);
		return WritePrivateProfileString(__lpSection, __lpKey, strValue, __lpFilePath) == TRUE;
	}
	static bool SetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, __int64 __qwValue, LPCTSTR __lpFilePath) {
		CMNVFile::CreatePath(__lpFilePath);
		CString strValue = _T("");
		strValue.Format(_T("%I64d"), __qwValue);
		return WritePrivateProfileString(__lpSection, __lpKey, strValue, __lpFilePath) == TRUE;
	}
};
