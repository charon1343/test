#pragma once
#include <afxwin.h>

class CMNVDevice {
private:
	CWinThread *m_pThread;
public:
	CMNVDevice() { m_pThread = NULL; }
	void BeginThread() {
		if (m_pThread == NULL)
			m_pThread = AfxBeginThread(Thread_Create, this, 0, 0, 0);
	}
	void EndThread() {
		if (m_pThread != NULL)
			TerminateThread(m_pThread->m_hThread, 0);
	}
	virtual void Thread() { }
	static UINT Thread_Create(LPVOID pParam) {
		HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);// COINIT_APARTMENTTHREADED);

		((CMNVDevice *)pParam)->Thread();

		if (hr != RPC_E_CHANGED_MODE) CoUninitialize();
		return 0;
	}
};
