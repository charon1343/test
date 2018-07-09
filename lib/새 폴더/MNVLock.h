#pragma once
#include <WinBase.h>
#include "MNVLogFile.h"

enum LockMode { MNVLM_None = 0, MNVLM_Write = 1, MNVLM_Read = 2, MNVLM_TryWrite = 3, MNVLM_TryRead = 4 };
class MNVLock : public SRWLOCK {
public:
	//CMNVLogFile * m_pLog;
	MNVLock() {
		InitializeSRWLock(this);
		//wchar_t Section[100]; swprintf_s(Section, _T("%08x"), this);
		//wchar_t Process[100]; swprintf_s(Process, _T("%08x"), Ptr);
		//m_pLog = new CMNVLogFile(Section, Process, _T(""), _T("MNVLock"));
	}
	~MNVLock() { }
	int GetLockCount() {
		int nCount = (int)Ptr >> 4;
		if (nCount == 0) return (int)Ptr > 0 ? -1 : 0;
		return nCount;
	} // | ((int)Ptr & 0x0f); }
	int GetLockID() { return (int)(this); }
	static int GetLockCount(PSRWLOCK __Lock) {
		int nCount = (int)__Lock->Ptr >> 4;
		if (nCount == 0) return (int)__Lock->Ptr > 0 ? -1 : 0;
		return nCount;
	}
	static int GetLockID(PSRWLOCK __Lock) { return (int)(__Lock); }
};
class CMNVLock {
protected:
	MNVLock * m_pLock;
	LockMode m_LockMode;
public:
	bool IsSuccess() { return m_LockMode != MNVLM_None; }
	CMNVLock(MNVLock * __pLock, LockMode __LockMode = MNVLM_None) {
		//__pLock->m_pLog->OutputMessage(_T("Create Lock"));
		m_pLock = __pLock;
		switch(__LockMode) {
		case MNVLM_Read:
			AcquireSRWLockShared((PSRWLOCK)m_pLock);
			m_LockMode = __LockMode;
			//__pLock->m_pLog->OutputData(_T("MNV Lock"), m_LockMode);
			break;
		case MNVLM_TryRead:
			m_LockMode = (TryAcquireSRWLockShared((PSRWLOCK)m_pLock) == TRUE) ? MNVLM_TryRead : MNVLM_None;
			//__pLock->m_pLog->OutputData(_T("MNV Lock"), m_LockMode);
			break;
		case MNVLM_Write:
			AcquireSRWLockExclusive((PSRWLOCK)m_pLock);
			m_LockMode = __LockMode;
			//__pLock->m_pLog->OutputData(_T("MNV Lock"), m_LockMode);
			break;
		case MNVLM_TryWrite:
			m_LockMode = (TryAcquireSRWLockExclusive((PSRWLOCK)m_pLock) == TRUE) ? MNVLM_TryWrite : MNVLM_None;
			//__pLock->m_pLog->OutputData(_T("MNV Lock"), m_LockMode);
			break;
		default:
			m_LockMode = MNVLM_None;
			//__pLock->m_pLog->OutputData(_T("MNV Lock"), m_LockMode);
		}
	}
	bool Lock(LockMode __LockMode) {
		switch (__LockMode) {
		case MNVLM_Read:
			AcquireSRWLockShared((PSRWLOCK)m_pLock);
			m_LockMode = __LockMode;
			break;
		case MNVLM_TryRead:
			m_LockMode = (TryAcquireSRWLockShared((PSRWLOCK)m_pLock) == TRUE) ? MNVLM_TryRead : MNVLM_None;
			break;
		case MNVLM_Write:
			AcquireSRWLockExclusive((PSRWLOCK)m_pLock);
			m_LockMode = __LockMode;
			break;
		case MNVLM_TryWrite:
			m_LockMode = (TryAcquireSRWLockExclusive((PSRWLOCK)m_pLock) == TRUE) ? MNVLM_TryWrite : MNVLM_None;
			break;
		default:
			m_LockMode = MNVLM_None;
			break;
		}
		return IsSuccess();
	}

	~CMNVLock() {
		switch(m_LockMode) {
		case MNVLM_Read:
			ReleaseSRWLockShared((PSRWLOCK)m_pLock);
			//m_pLock->m_pLog->OutputData(_T("MNV UnLock"), m_LockMode);
			break;
		case MNVLM_TryRead:
			ReleaseSRWLockShared((PSRWLOCK)m_pLock);
			//m_pLock->m_pLog->OutputData(_T("MNV UnLock"), m_LockMode);
			break;
		case MNVLM_Write:
			ReleaseSRWLockExclusive((PSRWLOCK)m_pLock);
			//m_pLock->m_pLog->OutputData(_T("MNV UnLock"), m_LockMode);
			break;
		case MNVLM_TryWrite:
			ReleaseSRWLockExclusive((PSRWLOCK)m_pLock);
			//m_pLock->m_pLog->OutputData(_T("MNV UnLock"), m_LockMode);
			break;
		}
		m_LockMode = MNVLM_None;
		//m_pLock->m_pLog->OutputMessage(_T("Destroy Lock"));
	}
	static void Create(PSRWLOCK __pSRWLock) { InitializeSRWLock(__pSRWLock); }
};
