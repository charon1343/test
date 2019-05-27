#pragma once
#include <afxwin.h>
#include <math.h>

class CMNVParser {
public:
	static __int8 Str2Num(LPCTSTR __lpValue, __int8 __bnDefault) {
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
	static __int16 Str2Num(LPCTSTR __lpValue, __int16 __wdnDefault) {
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
	static __int32 Str2Num(LPCTSTR __lpValue, __int32 __dwnDefault) {
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
	static __int64 Str2Num(LPCTSTR __lpValue, __int64 __qwnDefault) {
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
	static double Str2Num(LPCTSTR __lpValue, double __dDefault) {
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
	static float Str2Num(LPCTSTR __lpValue, float __dDefault) {
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
};
