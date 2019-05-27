#pragma once
class CMNV_RS232
{
	HANDLE m_hComm;
public:
	CMNV_RS232(void) { m_hComm = INVALID_HANDLE_VALUE; return; }
	~CMNV_RS232(void) { if (m_hComm != INVALID_HANDLE_VALUE) CloseHandle(m_hComm); }

	bool Init(LPCTSTR __strPort, DWORD __BaudRate, BYTE __ByteSize, BYTE __Parity, BYTE __StopBit) {
		m_hComm = CreateFile(__strPort, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
		if(m_hComm == INVALID_HANDLE_VALUE) return false;

		DCB dcb;
		if(!GetCommState(m_hComm, &dcb)) return false;

		dcb.BaudRate = __BaudRate;	// CBR_110 CBR_300 CBR_600
									// CBR_1200 CBR_2400 CBR_4800 CBR_9600
									// CBR_14400 CBR_19200 CBR_38400 CBR_56000 CBR_57600
									// CBR_115200 CBR_128000 CBR_256000
		dcb.fParity = FALSE;		// FALSE / TRUE
		dcb.fNull = FALSE;			// FALSE / TRUE
		dcb.ByteSize = __ByteSize;			// 
		dcb.Parity = __Parity; // NOPARITY / ODDPARITY / EVENPARITY
		dcb.StopBits = __StopBit;	// ONESTOPBIT ONE5STOPBITS TWOSTOPBITS

		if (!SetCommState(m_hComm, &dcb)) return false;

		COMMTIMEOUTS timeouts;
		timeouts.ReadIntervalTimeout = 100;
		timeouts.ReadTotalTimeoutMultiplier = 2;
		timeouts.ReadTotalTimeoutConstant = 0;
		timeouts.WriteTotalTimeoutMultiplier = 0;
		timeouts.WriteTotalTimeoutConstant = 0;
		if(!SetCommTimeouts(m_hComm, &timeouts)) {
			return false;
		}
		return true;
	}
	bool Init(LPCTSTR __strFileName, LPCTSTR __strSection) {
		CString strFilePath;
		{
			wchar_t Buf[1024];
			GetCurrentDirectory(1024, Buf);
			strFilePath.Format(_T("%s\\%s"), Buf, __strFileName);
		}

		CString strPort;
		DWORD dwBaudRate;
		BYTE bByteSize;
		BYTE bParity;
		BYTE bStopBit;

		CMNVIni::GetValue(__strSection, _T("Port"), strPort, _T("COM1"), __strFileName);
		dwBaudRate = CMNVIni::GetValue(__strSection, _T("BaudRate"), CBR_9600, __strFileName);
		bByteSize = CMNVIni::GetValue(__strSection, _T("ByteSize"), 8, __strFileName);
		bParity = CMNVIni::GetValue(__strSection, _T("Parity"), NOPARITY, __strFileName);
		bStopBit = CMNVIni::GetValue(__strSection, _T("StopBit"), ONESTOPBIT, __strFileName);

		return Init(strPort, dwBaudRate, bByteSize, bParity, bStopBit);
	}
	void Release() {
		HANDLE __hComm = m_hComm;
		m_hComm = INVALID_HANDLE_VALUE;
		if (__hComm != INVALID_HANDLE_VALUE)
			CloseHandle(__hComm);
	}
	int ReadData(__int8 * pBuf, int __nLength) {
		DWORD nLength;
		BOOL retval = ReadFile(m_hComm, pBuf, __nLength, &nLength, NULL);
		if (retval == FALSE) return -1;
		return (int)nLength;
	}
	bool WriteData(__int8 * pBuf, int __nLength) {
		DWORD nLength;
		BOOL retval = WriteFile(m_hComm, pBuf, __nLength, &nLength, NULL);
		if (retval == FALSE) return false;
		return ((int)nLength == __nLength);
	}

	static int ReadData(LPCTSTR __lpstrPort, DWORD __BaudRate, BYTE __ByteSize, BYTE __Parity, BYTE __StopBit, __int8 * pBuf, int __nLength) {
		CMNV_RS232 Com;
		if (Com.Init(__lpstrPort, __BaudRate, __ByteSize, __Parity, __StopBit))
			return Com.ReadData(pBuf, __nLength);
		return -1;
	}
	static int ReadData(LPCTSTR __strFile, LPCTSTR __strSection, __int8 * pBuf, int __nLength) {
		CMNV_RS232 Com;
		if (Com.Init(__strFile, __strSection) )
			return Com.ReadData(pBuf, __nLength);
		return -1;
	}
	static bool WriteData(LPCTSTR __lpstrPort, DWORD __BaudRate, BYTE __ByteSize, BYTE __Parity, BYTE __StopBit, __int8 * pBuf, int __nLength) {
		CMNV_RS232 Com;
		if ( Com.Init(__lpstrPort, __BaudRate, __ByteSize, __Parity, __StopBit) )
			return Com.WriteData(pBuf, __nLength);
		return false;
	}
	static bool WriteData(LPCTSTR __strFile, LPCTSTR __strSection, __int8 * pBuf, int __nLength) {
		CMNV_RS232 Com;
		if ( Com.Init(__strFile, __strSection) )
			return Com.WriteData(pBuf, __nLength);
		return false;
	}
};
// CDlg_PADRS232Setting 대화 상자입니다.

class CDlg_PADRS232Setting : public CMNVDialogEx
{
	DECLARE_DYNAMIC(CDlg_PADRS232Setting)

public:
	CDlg_PADRS232Setting(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_PADRS232Setting();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CTRL_RS232 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
