#pragma once
#include <WinBase.h>

enum MNVWaitResult { MNVWR_Event = 0,  MNVWR_TimeOut = 1, MNVWR_Break = 2, MNVWR_Error = 3 };
class CMNVEvent {
	HANDLE m_hEvent;
	bool m_isBreak;
	bool m_isReset;
	bool m_isEvent;
public:
	CMNVEvent() { m_isReset = false; m_hEvent = INVALID_HANDLE_VALUE; m_isBreak = false;}
	~CMNVEvent() { Release(); }

	bool Create() {
		if (m_hEvent == INVALID_HANDLE_VALUE) {
			m_hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
			m_isEvent = false;
			return true;
		}
		return false;
	}
	void Create(BOOL __bManualReset, BOOL __bInitialState) { 
		m_hEvent = CreateEvent(NULL, __bManualReset, __bInitialState, NULL);
		m_isEvent = __bInitialState == TRUE;
	}
	bool Release() {
		if (m_hEvent != INVALID_HANDLE_VALUE) {
			return ::CloseHandle(m_hEvent) == TRUE;
		}
		return false;
	}
	void SetBreak() { m_isBreak = true; }
	void ResetBreak() { m_isBreak = false; }

	bool SetEvent(bool __isReset = false) {
		m_isReset = __isReset;
		m_isEvent = true;
		return ::SetEvent(m_hEvent) == TRUE;
	}
	bool ResetEvent() { m_isEvent= false; return ::ResetEvent(m_hEvent) == TRUE; }
	bool Toggle() {
		if (m_isEvent) {
			m_isEvent = false;
			::ResetEvent(m_hEvent);
		}
		else {
			m_isEvent = true;
			::SetEvent(m_hEvent);
		}
		return m_isEvent;
	}
	MNVWaitResult Wait(DWORD __dwTimeOut = INFINITE) { 
		DWORD Result = ::WaitForSingleObject(m_hEvent, __dwTimeOut);
		if (m_isReset) ResetEvent();
		if (m_isBreak) return MNVWR_Break;
		switch(Result) {
		case WAIT_OBJECT_0: return MNVWR_Event;
		case WAIT_TIMEOUT: return MNVWR_TimeOut;
			//case WAIT_ABANDONED
			//case WAIT_FAILED
		default: return MNVWR_Error;
		}
	}

	operator HANDLE() { return m_hEvent; }
	operator bool() { return m_isBreak; }
	bool isBreak() { return m_isBreak; }
	static BOOL SetEvent(CMNVEvent & __cEvent) { return ::SetEvent(__cEvent); }
	static BOOL ResetEvent(CMNVEvent & __cEvent) { return ::ResetEvent(__cEvent); }
	static MNVWaitResult Wait(CMNVEvent & __cEvent, DWORD __dwTimeOut = INFINITE) { 
		DWORD Result = ::WaitForSingleObject(__cEvent, __dwTimeOut);
		if (__cEvent.m_isReset) __cEvent.ResetEvent();
		if (__cEvent.isBreak()) return MNVWR_Break;
		switch(Result) {
		case WAIT_OBJECT_0: return MNVWR_Event;
		case WAIT_TIMEOUT: return MNVWR_TimeOut;
			//case WAIT_ABANDONED
			//case WAIT_FAILED
		default: return MNVWR_Error;
		}
	}
};