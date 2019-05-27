//#include "StdAfx.h"
#include "CMNV_LFineControl.h"

void err_quit(LPCTSTR __lpStr)
{
	LPVOID lpMsgBuf;
	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpMsgBuf, 0, NULL);
	MessageBox(NULL, (LPCTSTR)lpMsgBuf, __lpStr, MB_ICONERROR);
	LocalFree(lpMsgBuf);
	//exit(-1);
}

//CMNV_LFineControl::CMNV_LFineControl(void)
//{
//	return;
//	m_hComm = CreateFile(_T("COM1"), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
//	if(m_hComm == INVALID_HANDLE_VALUE) err_quit(_T("CreateFile()"));
//	else {
//		DCB dcb;
//		if(!GetCommState(m_hComm, &dcb)) err_quit(_T("GetCommState()"));
//		else {
//			dcb.BaudRate = CBR_19200;	// CBR_110 CBR_300 CBR_600
//										// CBR_1200 CBR_2400 CBR_4800 CBR_9600
//										// CBR_14400 CBR_19200 CBR_38400 CBR_56000 CBR_57600
//										// CBR_115200 CBR_128000 CBR_256000
//			dcb.fParity = FALSE;		// FALSE / TRUE
//			dcb.fNull = FALSE;			// FALSE / TRUE
//			dcb.ByteSize = 8;			// 
//			dcb.Parity = NOPARITY; // NOPARITY / ODDPARITY / EVENPARITY
//			dcb.StopBits = ONESTOPBIT;	// ONESTOPBIT ONE5STOPBITS TWOSTOPBITS
//
//			if (!SetCommState(m_hComm, &dcb)) err_quit(_T("SetCommState()"));
//			else {
//				COMMTIMEOUTS timeouts;
//				timeouts.ReadIntervalTimeout = 0;
//				timeouts.ReadTotalTimeoutMultiplier = 1;
//				timeouts.ReadTotalTimeoutConstant = 0;
//				timeouts.WriteTotalTimeoutMultiplier = 0;
//				timeouts.WriteTotalTimeoutConstant = 0;
//				if(!SetCommTimeouts(m_hComm, &timeouts)) err_quit(_T("SetCommTimeouts()"));
//			}
//		}
//	}
//				//char buf[BUFSIZE + 1];
//				//int len;
//				//DWORD BytesRead, BytesWritten;
//				//int retval;
//
//				//while(1) {
//				//	retval = WriteFile(m_hComm, buf, BUFSIZE, &BytesWritten, NULL);
//				//	if(retval == 0) err_quit(_T("WriteFile()"));
//
//				//	retval = ReadFile(m_hComm, buf, BUFSIZE, &BytesRead, NULL);
//				//	if(retval == 0) err_quit(_T("ReadFile()"));
//				//	if(BytesRead == 0) {	// 응답 없음 : 수신 데이터 없음
//				//		continue;
//				//	}
//				//}
//}
//CMNV_LFineControl::~CMNV_LFineControl(void)
//{
//	CloseHandle(m_hComm);
//}
