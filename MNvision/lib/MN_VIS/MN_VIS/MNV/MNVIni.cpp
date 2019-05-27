#include "MNVIni.h"

__int8 Str2Num(LPCTSTR __lpValue, __int8 __bnDefault) {
	int nSigned = 1;
	int nResult = 0;
	int nLength = (int)wcslen(__lpValue);
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
__int16 Str2Num(LPCTSTR __lpValue, __int16 __wdnDefault) {
	__int64 nResult = 0;
	int nSigned = 1;
	int nLength = (int)wcslen(__lpValue);
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
__int32 Str2Num(LPCTSTR __lpValue, __int32 __dwnDefault) {
	__int64 nResult = 0;
	int nSigned = 1;
	int nLength = (int)wcslen(__lpValue);
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
__int64 Str2Num(LPCTSTR __lpValue, __int64 __qwnDefault) {
	__int64 nResult = 0;
	int nSigned = 1;
	int nLength = (int)wcslen(__lpValue);
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
double Str2Num(LPCTSTR __lpValue, double __dDefault) {
	int nSigned = 1;
	int nLength = (int)wcslen(__lpValue);

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
float Str2Num(LPCTSTR __lpValue, float __dDefault) {
	int nSigned = 1;
	int nLength = (int)wcslen(__lpValue);

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

CMNVIni::CMNVIni() { }
CMNVIni::CMNVIni(LPCTSTR __lpFilePath)
{
	m_strFilePath = __lpFilePath;
}
void CMNVIni::SetFilePath(LPCTSTR __lpFilePath)
{
	clear();
	m_strFilePath = __lpFilePath;
}
void CMNVIni::clear()
{
	CMNVLock Lock(&m_Lock, MNVLM_Write);
	TPMNV_IniSectionItem itmCurrent = m_lstSections.begin();
	TPMNV_IniSectionItem itmEnd = m_lstSections.end();

	for(; itmCurrent != itmEnd; ++itmCurrent) {
		itmCurrent->second.m_lstKeys.clear();
	}
	m_lstSections.clear();
	m_itmSection = m_lstSections.begin();
}
int CMNVIni::GetPrivateProfileSections(LPCWSTR __lpFileName)
{
	clear();

	WCHAR Buff[SIZE_64K];
	ZeroMemory(Buff, sizeof(WCHAR) * SIZE_64K);
	int nLength = GetPrivateProfileSectionNames(Buff, sizeof(WCHAR) * SIZE_64K, __lpFileName);
	CMNVHashCode uiKey;
	int nIndex = 0;
	int nCount = 0;

	CMNVLock Lock(&m_Lock, MNVLM_Write);
	while (nIndex < nLength) {
		uiKey = &(Buff[nIndex]);
		m_lstSections.insert(pair<TPMNV_HashCode, MNVIniSection>(uiKey, MNVIniSection(&(Buff[nIndex]))));
		nIndex += ((int)wcslen(&(Buff[nIndex])) + 1);
		++nCount;
	}
	return nCount;
}
bool CMNVIni::LoadIni()
{
	if(m_strFilePath.IsEmpty()) return false;
	int cntSection = GetPrivateProfileSections(m_strFilePath);
	
	CMNVLock Lock(&m_Lock, MNVLM_Read);
	TPMNV_IniSectionItem itmCurrent = m_lstSections.begin();
	TPMNV_IniSectionItem itmEnd = m_lstSections.end();
		
	for(; itmCurrent != itmEnd; ++itmCurrent) {
		itmCurrent->second.GetPrivateProfileKeys(m_strFilePath);
	}
	return true;
}
bool CMNVIni::SaveIni(LPCTSTR __lpFileName)
{
	CMNVLock Lock(&m_Lock, MNVLM_Read);
	CString strFileName = (__lpFileName == NULL) ? m_strFilePath : __lpFileName;
	CString strKey;
	CString strValue;
	bool Result = false;

	TPMNV_IniSectionItem itmCurrent = m_lstSections.begin();
	TPMNV_IniSectionItem itmEnd = m_lstSections.end();
	for(;itmCurrent != itmEnd; ++itmCurrent) {
		itmCurrent->second.SaveAll(strFileName);
	}
	return Result;
}

bool CMNVIni::FindSection(LPCTSTR __lpSection)
{
	CMNVHashCode uiKey = __lpSection;

	CMNVLock Lock(&m_Lock, MNVLM_Read);
	TPMNV_IniSectionItem itmCurrent = m_lstSections.lower_bound(uiKey);
	TPMNV_IniSectionItem itmEnd = m_lstSections.upper_bound(uiKey);

	for(; itmCurrent != itmEnd; ++itmCurrent) {
		if (itmCurrent->second.m_strSection == __lpSection) {
			m_itmSection = itmCurrent;
			return true;
		}
	}
	m_itmSection = m_lstSections.begin();
	return false;
}

bool CMNVIni::BeginSection()
{
	m_itmSection = m_lstSections.begin();
	return m_itmSection != m_lstSections.end();
}
bool CMNVIni::NextSection(CString * __pStr)
{
	if (m_itmSection != m_lstSections.end()) {
		if (__pStr != NULL)
			* __pStr = m_itmSection->second.m_strSection;
		++m_itmSection;
		return true;
	}
	else
		return false;
}
bool CMNVIni::FindKey(LPCTSTR __lpKey)
{ 
	if (m_itmSection == m_lstSections.end()) return false;
	return m_itmSection->second.FindKey(__lpKey);
}
bool CMNVIni::BeginKey()
{
	if (m_itmSection == m_lstSections.end()) return false;
	return m_itmSection->second.BeginKey();
}
bool CMNVIni::NextKey(CString * pStr)
{
	if (m_itmSection == m_lstSections.end()) return false;
	return m_itmSection->second.NextKey(pStr);
}

bool CMNVIni::GetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, CString & __strValue)
{
	CMNVHashCode uiKey = __lpSection;
	CMNVLock Lock(&m_Lock, MNVLM_Read);
	TPMNV_IniSectionItem itmCurrent = m_lstSections.lower_bound(uiKey);
	TPMNV_IniSectionItem itmEnd = m_lstSections.upper_bound(uiKey);

	for(; itmCurrent != itmEnd; ++itmCurrent) {
		if (itmCurrent->second.m_strSection == __lpSection) {
			itmCurrent->second.GetKeyValue(__lpKey, __strValue);
			return true;
		}
	}
	return false;
}
bool CMNVIni::GetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, int & __nValue)
{
	CMNVHashCode uiKey = __lpSection;
	CMNVLock Lock(&m_Lock, MNVLM_Read);
	TPMNV_IniSectionItem itmCurrent = m_lstSections.lower_bound(uiKey);
	TPMNV_IniSectionItem itmEnd = m_lstSections.upper_bound(uiKey);

	for(; itmCurrent != itmEnd; ++itmCurrent) {
		if (itmCurrent->second.m_strSection == __lpSection) {
			itmCurrent->second.GetKeyValue(__lpKey, __nValue);
			return true;
		}
	}
	return false;
}
bool CMNVIni::GetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, double & __dValue)
{
	CMNVHashCode uiKey = __lpSection;
	CMNVLock Lock(&m_Lock, MNVLM_Read);
	TPMNV_IniSectionItem itmCurrent = m_lstSections.lower_bound(uiKey);
	TPMNV_IniSectionItem itmEnd = m_lstSections.upper_bound(uiKey);

	for(; itmCurrent != itmEnd; ++itmCurrent) {
		if (itmCurrent->second.m_strSection == __lpSection) {
			itmCurrent->second.GetKeyValue(__lpKey, __dValue);
			return true;
		}
	}
	return false;
}

bool CMNVIni::SetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, CString __strValue)
{
	CMNVHashCode uiKey = __lpSection;
	{	// Section을 찾아서 Key 값을 설정한다.
		CMNVLock Lock(&m_Lock, MNVLM_Read);
		TPMNV_IniSectionItem itmCurrent = m_lstSections.lower_bound(uiKey);
		TPMNV_IniSectionItem itmEnd = m_lstSections.upper_bound(uiKey);

		for(; itmCurrent != itmEnd; ++itmCurrent) {
			if (itmCurrent->second.m_strSection == __lpSection) {
				itmCurrent->second.SetKey(__lpKey, __strValue);
				return true;
			}
		}
	}
	{	// Section이 없으므로 생성 후 Key값을 설정한다.
		CMNVLock Lock(&m_Lock, MNVLM_Write);
		TPMNV_IniSectionItem itmCurrent = m_lstSections.insert(pair<TPMNV_HashCode, MNVIniSection>(uiKey, MNVIniSection(__lpSection)));
		itmCurrent->second.SetKey(__lpKey, __strValue);
		return false;
	}
}
bool CMNVIni::SetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, int __nValue)
{	// SetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, CString __strValue) 를 호출하기 때문에 여기서는 Lock 설정을 하지 않는다.
	CString strValue;
	strValue.Format(_T("%d"), __nValue);
	return SetValue(__lpSection, __lpKey, strValue);
}
bool CMNVIni::SetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, double __dValue)
{	// SetValue(LPCTSTR __lpSection, LPCTSTR __lpKey, CString __strValue) 를 호출하기 때문에 여기서는 Lock 설정을 하지 않는다.
	CString strValue;
	strValue.Format(_T("%f"), __dValue);
	return SetValue(__lpSection, __lpKey, strValue);
}

bool CMNVIni::RemoveSection(LPCTSTR __lpSection)
{
	CMNVHashCode uiKey = __lpSection;
	CMNVLock Lock(&m_Lock, MNVLM_Write);
	TPMNV_IniSectionItem itmCurrent = m_lstSections.lower_bound(uiKey);
	TPMNV_IniSectionItem itmEnd = m_lstSections.upper_bound(uiKey);

	for(; itmCurrent != itmEnd; ++itmCurrent) {
		if (itmCurrent->second.m_strSection == __lpSection) {
			if (m_itmSection == itmCurrent) m_itmSection = m_lstSections.end();
			itmCurrent->second.RemoveAll();
			m_lstSections.erase(itmCurrent);
			return true;
		}
	}
	return false;
}
bool CMNVIni::RemoveKey(LPCTSTR __lpSection, LPCTSTR __lpKey)
{
	CMNVHashCode uiKey = __lpSection;
	CMNVLock Lock(&m_Lock, MNVLM_Read);
	TPMNV_IniSectionItem itmCurrent = m_lstSections.lower_bound(uiKey);
	TPMNV_IniSectionItem itmEnd = m_lstSections.upper_bound(uiKey);

	for(; itmCurrent != itmEnd; ++itmCurrent) {
		if (itmCurrent->second.m_strSection == __lpSection) {
			itmCurrent->second.RemoveKey(__lpKey);
			return true;
		}
	}
	return false;
}
