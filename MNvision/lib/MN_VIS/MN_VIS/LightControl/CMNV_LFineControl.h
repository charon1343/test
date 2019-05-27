#pragma once

#define BUFSIZE 512
#include <afxwin.h>         // MFC 핵심 및 표준 구성 요소입니다.
#include "../MNV/MNVIni.h"
#include "../MNV/MNVLock.h"

void err_quit(LPCTSTR __lpStr);
enum ChannelFlag {
	FlagCH01 = 0x00000001,	FlagCH02 = 0x00000002,	FlagCH03 = 0x00000004,	FlagCH04 = 0x00000008
,	FlagCH05 = 0x00000010,	FlagCH06 = 0x00000020,	FlagCH07 = 0x00000040,	FlagCH08 = 0x00000080
,	FlagCH09 = 0x00000100,	FlagCH10 = 0x00000200,	FlagCH11 = 0x00000400,	FlagCH12 = 0x00000800
,	FlagCH13 = 0x00001000,	FlagCH14 = 0x00002000,	FlagCH15 = 0x00004000,	FlagCH16 = 0x00008000
,	FlagCH17 = 0x00010000,	FlagCH18 = 0x00020000,	FlagCH19 = 0x00040000,	FlagCH20 = 0x00080000
};

class CMNV_LFineControl
{
	MNVLock m_Lock;
	HANDLE m_hComm;
	BYTE m_pBuf[4096];
	int m_nLength;

	int m_nChannel[20];
	int m_nValue[20];
	int m_nMax;
	int m_nPort;
	int m_nRate;
	int m_nBytes;
	int m_nParity;
	int m_nStop;
	int m_nCount;
	char m_cCmd;
	void _SetValue(int __nIndex, int __nValue) {
		if (__nValue < 0)
			m_nValue[__nIndex] = 0;
		else if (__nValue > m_nMax)
			m_nValue[__nIndex] = m_nMax;
		else
			m_nValue[__nIndex] = __nValue;
	}
public:
	bool m_isConnect;
	int GetPort() { return m_nPort; }
	int GetRate() { return m_nRate; }
	int GetBytes() { return m_nBytes; }
	int GetParity() { return m_nParity; }
	int GetStop() { return m_nStop; }
	int GetChannel(int __nIndex) { return m_nChannel[__nIndex]; }
	int GetValue(int __nIndex) { return m_nValue[__nIndex]; }
	int GetCount() { return m_nCount; }

	void SetPort(int __nValue) { m_nPort = __nValue; }
	void SetRate(int __nValue) { m_nRate = __nValue; }
	void SetBytes(int __nValue) { m_nBytes = __nValue; }
	void SetParity(int __nValue) { m_nParity = __nValue; }
	void SetStop(int __nValue) { m_nStop = __nValue; }
	void SetChannel(int __nIndex, int __nChannel) { m_nChannel[__nIndex] = __nChannel; }
	void SetValue(int __nIndex, int __nValue) {
		if (0 <= __nIndex && __nIndex < 20) {
			_SetValue(__nIndex, __nValue);
		}
	}
	void AddValue(int __nIndex, int __nValue) { 
		if (0 <= __nIndex && __nIndex < 20) {
			_SetValue(__nIndex, m_nValue[__nIndex] + __nValue);
		}
	}
	void SubValue(int __nIndex, int __nValue) {
		if (0 <= __nIndex && __nIndex < 20) {
			_SetValue(__nIndex, m_nValue[__nIndex] - __nValue);
		}
	}
	void SetCount (int __nValue) { m_nCount = __nValue; }

	void InitSetting() {
		for(int nIndex = 0; nIndex < 20; ++nIndex) {
			m_nValue[nIndex] = 0;
		}
		SendValue();
	}
	void LoadSetting(LPCTSTR __lpFilePath)
	{
		CMNVLock Lock(&m_Lock, MNVLM_Write);

		CString strCmd;
		m_nPort = CMNVIni::GetValue(_T("LightControl"), _T("Port"), 1, __lpFilePath); 
		m_nRate = CMNVIni::GetValue(_T("LightControl"), _T("Rate"), 9600, __lpFilePath); 
		m_nBytes = CMNVIni::GetValue(_T("LightControl"), _T("Bytes"), 8, __lpFilePath); 
		m_nParity = CMNVIni::GetValue(_T("LightControl"), _T("Parity"), 0, __lpFilePath); 
		m_nStop = CMNVIni::GetValue(_T("LightControl"), _T("Stop"), 0, __lpFilePath);
		m_cCmd = CMNVIni::GetValue(_T("LightControl"), _T("Cmd"), 'w', __lpFilePath);
		m_nCount = CMNVIni::GetValue(_T("LightControl"), _T("Count"), 20, __lpFilePath);

		CString strKey;
		for(int nIndex = 0; nIndex < 20; ++nIndex) {
			strKey.Format(_T("Channel%02d"), nIndex + 1);
			m_nChannel[nIndex] = CMNVIni::GetValue(_T("LightControl"), strKey, nIndex + 1, __lpFilePath); 
		}
	}
	void SaveSetting(LPCTSTR __lpFilePath)
	{
		CMNVLock Lock(&m_Lock, MNVLM_Write);
		CMNVIni::SetValue(_T("LightControl"), _T("Port"), m_nPort, __lpFilePath); 
		CMNVIni::SetValue(_T("LightControl"), _T("Rate"), m_nRate, __lpFilePath); 
		CMNVIni::SetValue(_T("LightControl"), _T("Bytes"), m_nBytes, __lpFilePath); 
		CMNVIni::SetValue(_T("LightControl"), _T("Parity"), m_nParity, __lpFilePath); 
		CMNVIni::SetValue(_T("LightControl"), _T("Stop"), m_nStop, __lpFilePath); 
		CMNVIni::SetValue(_T("LightControl"), _T("Cmd"), m_cCmd, __lpFilePath);
		CMNVIni::SetValue(_T("LightControl"), _T("Count"), m_nCount, __lpFilePath);
		CString strKey;
		for(int nIndex = 0; nIndex < 20; ++nIndex) {
			strKey.Format(_T("Channel%02d"), nIndex + 1);
			CMNVIni::SetValue(_T("LightControl"), strKey, m_nChannel[nIndex], __lpFilePath); 
		}
	}

	void Close() {
		CMNVLock Lock(&m_Lock, MNVLM_Write);
		if (m_hComm != INVALID_HANDLE_VALUE)
			CloseHandle(m_hComm);
		m_hComm = INVALID_HANDLE_VALUE;
	}
	bool Open(LPCTSTR __lpstrPort, DWORD __BaudRate, BYTE __ByteSize, BYTE __Parity, BYTE __StopBit) {
		CMNVLock Lock(&m_Lock, MNVLM_Write);

		if (m_hComm == INVALID_HANDLE_VALUE)
			m_hComm = CreateFile(__lpstrPort, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
		if(m_hComm == INVALID_HANDLE_VALUE) {
			return false;
		}

		DCB dcb;
		if(!GetCommState(m_hComm, &dcb)) {
			Close();
			return false;
		}
		dcb.BaudRate = __BaudRate;	// CBR_110 CBR_300 CBR_600
									// CBR_1200 CBR_2400 CBR_4800 CBR_9600
									// CBR_14400 CBR_19200 CBR_38400 CBR_56000 CBR_57600
									// CBR_115200 CBR_128000 CBR_256000
		dcb.fParity = FALSE;		// FALSE / TRUE
		dcb.fNull = FALSE;			// FALSE / TRUE
		dcb.ByteSize = __ByteSize;			// 
		dcb.Parity = __Parity; // NOPARITY / ODDPARITY / EVENPARITY
		dcb.StopBits = __StopBit;	// ONESTOPBIT ONE5STOPBITS TWOSTOPBITS

		if (!SetCommState(m_hComm, &dcb)) {
			Close();
			return false;
		}

		COMMTIMEOUTS timeouts;
		timeouts.ReadIntervalTimeout = 0;
		timeouts.ReadTotalTimeoutMultiplier = 1;
		timeouts.ReadTotalTimeoutConstant = 0;
		timeouts.WriteTotalTimeoutMultiplier = 0;
		timeouts.WriteTotalTimeoutConstant = 0;
		if(!SetCommTimeouts(m_hComm, &timeouts)) {
			Close();
			return false;
		}
		return true;
	}
	void SendValue() {
		CString strPort;
		strPort.Format(_T("COM%d"), m_nPort);
		if (!Open(strPort, m_nRate, m_nBytes, m_nParity, m_nStop)) {
			m_isConnect = false;
			return;
		}

		{	CMNVLock Lock(&m_Lock, MNVLM_Write);
			int __nValue;
			int __nChannel;

			BYTE pBuf[4096];
		
			DWORD BytesWritten;
			char * pOffset = (char *)pBuf;
			int nTotal = 0;
			int len = 0;

			for(int nIndex = 0; nIndex < m_nCount; ++nIndex) {
				__nChannel = m_nChannel[nIndex];
				__nValue = m_nValue[nIndex];

				if (0 > __nValue) __nValue = 0;
				if (1023 < __nValue) __nValue = 1023;

				sprintf_s(pOffset, 100, "%c%c%c%04d%c", 0x02, __nChannel + 0x2f, m_cCmd, __nValue, 0x03);

				len = (int)strlen(pOffset);
				pOffset += len;
				nTotal += len;
			}
			WriteFile(m_hComm, pBuf, nTotal, &BytesWritten, NULL);
			m_isConnect = (nTotal == (int)BytesWritten);
		}
		Sleep(30);
		Close();
	}
	void SendBegin() {
		CString strPort;
		strPort.Format(_T("COM%d"), m_nPort);
		if (!Open(strPort, m_nRate, m_nBytes, m_nParity, m_nStop)) {
			m_isConnect = false;
			return;
		}
	}
	void SendValue(int __nIndex) {
		{	CMNVLock Lock(&m_Lock, MNVLM_Write);
			//int __nValue;
			//int __nChannel;

			BYTE pBuf[4096];
		
			DWORD BytesWritten;
			int nTotal = 0;

			sprintf_s((char *)pBuf, 100, "%c%c%c%04d%c", 0x02, m_nChannel[__nIndex] + 0x2f, m_cCmd, m_nValue[__nIndex], 0x03);
			nTotal = (int)strlen((char *)pBuf);

			WriteFile(m_hComm, pBuf, nTotal, &BytesWritten, NULL);
			m_isConnect = (nTotal == (int)BytesWritten);
		}
	}
	void SendEnd() {
		Close();
	}
public:
	CMNV_LFineControl(void) {
		CMNVLock Lock(&m_Lock, MNVLM_Write);
		m_hComm = INVALID_HANDLE_VALUE;
		ZeroMemory(m_pBuf, 4096);
		m_nLength = 0;
		m_isConnect = false;
		m_nMax = 1023;
		return;
	}
	~CMNV_LFineControl(void)
	{
		if (m_hComm != INVALID_HANDLE_VALUE) CloseHandle(m_hComm);
	}
	//Init(CBR_9600, 8, NOPARITY, ONESTOPBIT)
	//void Init(LPCTSTR __lpstrPort, DWORD __BaudRate, BYTE __ByteSize, BYTE __Parity, BYTE __StopBit) {
	//	if (m_hComm == INVALID_HANDLE_VALUE)
	//		m_hComm = CreateFile(__lpstrPort, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
	//	if(m_hComm == INVALID_HANDLE_VALUE) {
	//		err_quit(_T("SetCommState()"));
	//		return;
	//	}

	//	DCB dcb;
	//	if(!GetCommState(m_hComm, &dcb)) {
	//		err_quit(_T("SetCommState()"));
	//		return;
	//	}
	//	dcb.BaudRate = __BaudRate;	// CBR_110 CBR_300 CBR_600
	//								// CBR_1200 CBR_2400 CBR_4800 CBR_9600
	//								// CBR_14400 CBR_19200 CBR_38400 CBR_56000 CBR_57600
	//								// CBR_115200 CBR_128000 CBR_256000
	//	dcb.fParity = FALSE;		// FALSE / TRUE
	//	dcb.fNull = FALSE;			// FALSE / TRUE
	//	dcb.ByteSize = __ByteSize;			// 
	//	dcb.Parity = __Parity; // NOPARITY / ODDPARITY / EVENPARITY
	//	dcb.StopBits = __StopBit;	// ONESTOPBIT ONE5STOPBITS TWOSTOPBITS

	//	if (!SetCommState(m_hComm, &dcb)) {
	//		err_quit(_T("SetCommState()"));
	//		return;
	//	}

	//	COMMTIMEOUTS timeouts;
	//	timeouts.ReadIntervalTimeout = 0;
	//	timeouts.ReadTotalTimeoutMultiplier = 1;
	//	timeouts.ReadTotalTimeoutConstant = 0;
	//	timeouts.WriteTotalTimeoutMultiplier = 0;
	//	timeouts.WriteTotalTimeoutConstant = 0;
	//	if(!SetCommTimeouts(m_hComm, &timeouts)) {
	//		err_quit(_T("SetCommTimeouts()"));
	//		return;
	//	}
	//}
	//int Init(LPCTSTR __lpFileName, int __nChannel) {
	//	CString strFilePath;
	//	{
	//		wchar_t Buf[1024];
	//		GetCurrentDirectory(1024, Buf);
	//		strFilePath.Format(_T("%s\\%s"), Buf, __lpFileName);
	//	}
	//	CString strSection;
	//	strSection.Format(_T("Channel%d"), __nChannel);

	//	CString strPort;
	//	DWORD dwBaudRate;
	//	BYTE bByteSize;
	//	BYTE bParity;
	//	BYTE bStopBit;
	//	int nChannel;

	//	CMNVIni::GetValue(strSection, _T("Port"), strPort, _T("COM1"), __lpFileName);
	//	dwBaudRate = CMNVIni::GetValue(strSection, _T("BaudRate"), CBR_9600, __lpFileName);
	//	bByteSize = CMNVIni::GetValue(strSection, _T("ByteSize"), 8, __lpFileName);
	//	bParity = CMNVIni::GetValue(strSection, _T("Parity"), NOPARITY, __lpFileName);
	//	bStopBit = CMNVIni::GetValue(strSection, _T("StopBit"), ONESTOPBIT, __lpFileName);
	//	Init(strPort, dwBaudRate, bByteSize, bParity, bStopBit);
	//	nChannel = CMNVIni::GetValue(strSection, _T("Channel"), 1, __lpFileName);
	//	return nChannel;
	//}

	//void SendOnOff(int __nChannel, bool __isOn) {
	//	DWORD BytesWritten;
	//	BYTE pBuf[100];
	//	ZeroMemory(pBuf, 100);
	//	sprintf_s((char*)pBuf, 100, "%c%c%c%c", 0x02, __nChannel + 0x2f, __isOn ? 'o' : 'f', 0x03);
	//	int len = (int)strlen((char *)pBuf);
	//	WriteFile(m_hComm, pBuf, len, &BytesWritten, NULL);
	//}
	//void SendValue(int __nChannel, int __nValue) {
	//	if (0 > __nValue) __nValue = 0;
	//	if (1023 < __nValue) __nValue = 1023;

	//	DWORD BytesWritten;
	//	BYTE pBuf[100];
	//	ZeroMemory(pBuf, 100);
	//	if (__nChannel > 0) sprintf_s((char*)pBuf, 100, "%c%cw%04d%c", 0x02, __nChannel + 0x2f, __nValue, 0x03);
	//	else  sprintf_s((char*)pBuf, 100, "%czw%04d%c", 0x02, __nValue, 0x03);
	//	int len = (int)strlen((char *)pBuf);
	//	WriteFile(m_hComm, pBuf, len, &BytesWritten, NULL);
	//}
	//void AddSend(int __nChannel, int __nValue) {
	//	if (0 > __nValue) __nValue = 0;
	//	if (1023 < __nValue) __nValue = 1023;

	//	if (__nChannel > 0) 
	//		sprintf_s((char*)(&(m_pBuf[m_nLength])), 4096 - m_nLength, "%c%cw%04d%c", 0x02, __nChannel + 0x2f, __nValue, 0x03);
	//	else
	//		sprintf_s((char*)(&(m_pBuf[m_nLength])), 4096 - m_nLength, "%czw%04d%c", 0x02, __nValue, 0x03);
	//	m_nLength += (int)strlen((char *)(&(m_pBuf[m_nLength])));
	//}
	//void Send() {
	//	DWORD BytesWritten;
	//	WriteFile(m_hComm, m_pBuf, m_nLength, &BytesWritten, NULL);
	//	ZeroMemory(m_pBuf, 4096);
	//	m_nLength = 0;
	//}
	//void SendMulti(int __nValue, __int32 __nEnable) {
	//	if (0 > __nValue) __nValue = 0;
	//	if (1023 < __nValue) __nValue = 1023;

	//	DWORD BytesWritten;
	//	BYTE pBuf[1000];
	//	ZeroMemory(pBuf, 1000);
	//	
	//	int nOffset = 0;
	//	for(int nIndex = 1; nIndex <= 20; ++nIndex) {
	//		if (__nEnable & 0x01) {
	//			sprintf_s((char*)(&(pBuf[nOffset])), 1000 - nOffset, "%c%cw%04d%c", 0x02, nIndex + 0x2f, __nValue, 0x03);
	//			nOffset += (int)strlen((char *)(&(pBuf[nOffset])));
	//		}
	//		__nEnable >>= 1;
	//	}
	//	WriteFile(m_hComm, pBuf, nOffset, &BytesWritten, NULL);
	//}
	//static void SendOnOff(LPCTSTR __lpstrPort, DWORD __BaudRate, BYTE __ByteSize, BYTE __Parity, BYTE __StopBit, int __nChannel, bool __isOn) {
	//	CMNV_LFineControl Light;
	//	Light.Init(__lpstrPort, __BaudRate, __ByteSize, __Parity, __StopBit);
	//	Light.SendOnOff(__nChannel, __isOn);
	//}
	//static void SendValue(LPCTSTR __lpstrPort, DWORD __BaudRate, BYTE __ByteSize, BYTE __Parity, BYTE __StopBit, int __nChannel, int __nValue) {
	//	CMNV_LFineControl Light;
	//	Light.Init(__lpstrPort, __BaudRate, __ByteSize, __Parity, __StopBit);
	//	Light.SendValue(__nChannel, __nValue);
	//}
	//static void SendOnOff(LPCTSTR __strFile, int __nChannel, bool __isOn) {
	//	CMNV_LFineControl Light;
	//	int nChannel = Light.Init(__strFile, __nChannel);
	//	Light.SendOnOff(nChannel, __isOn);
	//}
	//static void SendValue(LPCTSTR __strFile, int __nChannel, int __nValue) {
	//	CMNV_LFineControl Light;
	//	int nChannel = Light.Init(__strFile, __nChannel);
	//	Light.SendValue(nChannel, __nValue);
	//}
};

//struct LFine_LightSetting {
//	int nChannel;
//	wchar_t strPort[10];
//	DWORD dwBaudRate;
//	BYTE bByteSize;
//	BYTE bParity;
//	BYTE bStopBit;
//	int nPhysical;
//
//	void SetChannel(int __nChannel) { nChannel = __nChannel; }
//	void Load(LPCTSTR __strPath, int __nChannel) {
//		CString strSection;
//		strSection.Format(_T("Channel%d"), __nChannel);
//
//		CMNVIni::GetValue(strSection, _T("Port"), strPort, _T("COM1"), __strPath);
//		dwBaudRate = CMNVIni::GetValue(strSection, _T("BaudRate"), CBR_9600, __strPath);
//		bByteSize = CMNVIni::GetValue(strSection, _T("ByteSize"), 8, __strPath);
//		bParity = CMNVIni::GetValue(strSection, _T("Parity"), NOPARITY, __strPath);
//		bStopBit = CMNVIni::GetValue(strSection, _T("StopBit"), ONESTOPBIT, __strPath);
//		nPhysical = CMNVIni::GetValue(strSection, _T("Channel"), 1, __strPath);
//	}
//	void Save(LPCTSTR __strPath) {
//		CString strSection;
//		strSection.Format(_T("Channel%d"), nChannel);
//
//		CMNVIni::GetValue(strSection, _T("Port"), strPort, _T("COM1"), __strPath);
//		dwBaudRate = CMNVIni::GetValue(strSection, _T("BaudRate"), CBR_9600, __strPath);
//		bByteSize = CMNVIni::GetValue(strSection, _T("ByteSize"), 8, __strPath);
//		bParity = CMNVIni::GetValue(strSection, _T("Parity"), NOPARITY, __strPath);
//		bStopBit = CMNVIni::GetValue(strSection, _T("StopBit"), ONESTOPBIT, __strPath);
//		nPhysical = CMNVIni::GetValue(strSection, _T("Channel"), 1, __strPath);
//	}
//
//	void SendOnOff(bool __isOn) {
//		CMNV_LFineControl Light;
//		Light.Init(strPort, dwBaudRate, bByteSize, bParity, bStopBit);
//		Light.SendOnOff(nPhysical, __isOn);
//	}
//	void SendValue(int __nValue) {
//		CMNV_LFineControl Light;
//		Light.Init(strPort, dwBaudRate, bByteSize, bParity, bStopBit);
//		Light.SendValue(nPhysical, __nValue);
//	}
//};
//
