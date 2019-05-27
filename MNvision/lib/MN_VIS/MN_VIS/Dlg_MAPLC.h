#pragma once

// CDlg_MAPLC 대화 상자입니다.
#include "Dlg_PADRS232Setting.h"
class CMNV_DevicePLC : public CMNVDevice {
	enum STATE { PLC_CONNECT, PLC_ASYNC, PLC_SYNC, PLC_CLOSE, PLC_STOP };
	enum FLOW { PLC_WAIT, PLC_READ, PLC_WRITE };
	STATE m_nState;
	FLOW m_nFlow;

	CMNV_RS232 m_RS232;
	CString m_strPort;
	DWORD m_dwBaudRate;
	BYTE m_bByteSize;
	BYTE m_bParity;
	BYTE m_bStopBit;
public:
	CMNV_DevicePLC() {
		m_nState = PLC_STOP;
		m_nFlow = PLC_WAIT;
		m_strPort = _T("COM1");
		m_dwBaudRate = CBR_9600;
		m_bByteSize = 8;
		m_bParity = NOPARITY;
		m_bStopBit = ONESTOPBIT;
	}
	void LoadIni(LPCTSTR __strFile, LPCTSTR __strSection) {
		CString strFile; {
			wchar_t strBuf[1024];
			GetCurrentDirectory(1024, strBuf);
			strFile.Format(_T("%s\\%s"), strBuf, __strFile);
		}
		CMNVIni::GetValue(__strSection, _T("Port"), m_strPort, _T("COM1"), __strFile);
		m_dwBaudRate = CMNVIni::GetValue(__strSection, _T("BaudRate"), CBR_9600, __strFile);
		m_bByteSize = CMNVIni::GetValue(__strSection, _T("ByteSize"), 8, __strFile);
		m_bParity = CMNVIni::GetValue(__strSection, _T("Parity"), NOPARITY, __strFile);
		m_bStopBit = CMNVIni::GetValue(__strSection, _T("StopBit"), ONESTOPBIT, __strFile);
	}
	void SaveIni(LPCTSTR __strFile, LPCTSTR __strSection) {
		CString strFile; {
			wchar_t strBuf[1024];
			GetCurrentDirectory(1024, strBuf);
			strFile.Format(_T("%s\\%s"), strBuf, __strFile);
		}
		CMNVIni::SetValue(__strSection, _T("Port"), m_strPort, __strFile);
		CMNVIni::SetValue(__strSection, _T("BaudRate"), (int)m_dwBaudRate, __strFile);
		CMNVIni::SetValue(__strSection, _T("ByteSize"), m_bByteSize, __strFile);
		CMNVIni::SetValue(__strSection, _T("Parity"), m_bParity, __strFile);
		CMNVIni::SetValue(__strSection, _T("StopBit"), m_bStopBit, __strFile);
	}

	void RunPLC() { m_nState = PLC_CONNECT; }
	void StopPLC() { m_nState = PLC_CLOSE; }
	virtual void Thread() {
		__int8 pBuf[2048];
		sprintf_s(pBuf, "메롱이다.");
		int BCC = 0;
		int nRSize = 0;
		int nTotal = 0;
		int nTimeLimit = 10;
		int nTimeOut = 0; 
		while(1) {
			switch(m_nState) {
			case PLC_CONNECT:
				if(m_RS232.Init(m_strPort, m_dwBaudRate, m_bByteSize, m_bParity, m_bStopBit)) {
					m_nState = PLC_ASYNC;
					m_nFlow = PLC_WRITE;
				}
				break;
			case PLC_ASYNC:
			case PLC_SYNC:
				switch(m_nFlow) {
				case PLC_WRITE:
					{	// Create Send Pack
						BCC = 0;
						pBuf[0] = 0x05; BCC += pBuf[0];
						pBuf[1] = '2'; BCC += pBuf[1];
						pBuf[2] = '0'; BCC += pBuf[2];
						pBuf[3] = 'R'; BCC += pBuf[3];
						pBuf[4] = 'S'; BCC += pBuf[4];
						pBuf[5] = 'S'; BCC += pBuf[5];
						pBuf[6] = '0'; BCC += pBuf[6];
						pBuf[7] = '1'; BCC += pBuf[7];
						pBuf[8] = '0'; BCC += pBuf[8];
						pBuf[9] = '8'; BCC += pBuf[9];
						pBuf[10] = '%'; BCC += pBuf[10];
						pBuf[11] = 'D'; BCC += pBuf[11];
						pBuf[12] = 'W'; BCC += pBuf[12];
						pBuf[13] = '0'; BCC += pBuf[13];
						pBuf[14] = '1'; BCC += pBuf[14];
						pBuf[15] = '0'; BCC += pBuf[15];
						pBuf[16] = '0'; BCC += pBuf[16];
						pBuf[17] = '0'; BCC += pBuf[17];
						pBuf[18] = 0x04; BCC += pBuf[18];
						pBuf[19] = (unsigned __int8)BCC;
						sprintf_s(&(pBuf[13]), 100, "%05d", nTotal);
					}
					if (m_RS232.WriteData(pBuf, 20)) {
						nTimeOut = nTimeLimit;
						m_nFlow = PLC_READ;
						nTotal = 0;
					}
					break;
				case PLC_WAIT:
					if (nTimeOut <= 0) {
						m_nFlow = PLC_READ;
					}
					--nTimeOut;
				case PLC_READ:
					nTotal = m_RS232.ReadData(pBuf, 1024);
					m_nFlow = PLC_WRITE;
					//nRSize = m_RS232.ReadData(&(pBuf[nTotal]), 100);
					//--nTimeOut;
					//if (nRSize > 0) {
					//	nTimeOut = nTimeLimit;
					//	for(int nIndex = 0; nIndex < nRSize; ++nIndex) {
					//		if (pBuf[nTotal + nIndex] == 0x0a) {
					//			m_nFlow = PLC_WRITE;
					//			break;
					//		}
					//	}
					//	nTotal += nRSize;
					//	if (nTotal >= 1024) m_nFlow = PLC_WRITE;
					//}
					//else {
					//	if (nTimeOut <= 0) {
					//		m_nState = PLC_ASYNC;
					//		m_nFlow = PLC_WRITE;
					//	}
					//}
					break;
				}
				break;
			case PLC_CLOSE:
				m_RS232.Release();
				m_nState = PLC_STOP;
				break;
			default:
				break;
			}
			Sleep(1);
		}
		AfxMessageBox(_T("오....!!!! 왔어!"));
	}
};

enum Map_Data { DATA_Signal = 0, DATA_Model = 1, DATA_AxisU = 2, DATA_AxisV = 4, DATA_AxisW = 6, DATA_AxisX = 8, DATA_AxisY = 10, DATA_AxisZ = 12 };
enum Map_Signal { SIGNAL_Response = 0, SIGNAL_OK = 1, SIGNAL_NG = 2, SIGNAL_Alarm = 3, SIGNAL_Request = 4 };

struct DataMap {
	int nBeginAddr;
	int nSize;
};

struct DataAddr {
	int m_nOffset;
	int m_nBit;
	int m_nSize;
	void SetAddress(int __nOffset, int __nBit, int __cntBit) {
		m_nOffset = __nOffset;
		m_nBit = __nBit;
		m_nSize = __cntBit;
	}
	void GetString_Addr(CString & __strAddr) {
		wchar_t Bit[17] = _T("0123456789ABCDEF");
		switch (m_nSize) {
		case 1:
			__strAddr.Format(_T("D%06d:%c"), m_nOffset, Bit[m_nBit]);
			break;
		case 16:
			__strAddr.Format(_T("D%06d"), m_nOffset);
			break;
		default:
			__strAddr.Format(_T("D%06d∼D%06d"), m_nOffset, m_nOffset + (m_nSize / 16 - 1));
			break;
		}
	}
};

class CDlg_MAPLC : public CMNVDialogEx
{
	void GetDataName_PC(int __nBeginAddr, DataAddr & __Addr, CString & __strName) {
		if (__Addr.m_nSize == 1) {
			switch(__Addr.m_nBit) {
			case SIGNAL_Response: __strName = _T("Vision Complete"); break;
			case SIGNAL_OK: __strName = _T("Vision OK"); break;
			case SIGNAL_NG: __strName = _T("Vision NG"); break;
			case SIGNAL_Alarm: __strName = _T("Vision Alarm"); break;
			case SIGNAL_Request: __strName = _T("Move Request"); break;
			default: __strName = _T("<No Used>"); break;
			}
		}
		else {
			switch(__Addr.m_nOffset - __nBeginAddr) {
			case DATA_Signal: __strName = _T("Signal"); break;
			case DATA_Model: __strName = _T("Current Model No."); break;
			case DATA_AxisU: __strName = _T("Request Axis-U"); break;
			case DATA_AxisV: __strName = _T("Request Axis-V"); break;
			case DATA_AxisW: __strName = _T("Request Axis-W"); break;
			case DATA_AxisX: __strName = _T("Request Axis-X"); break;
			case DATA_AxisY: __strName = _T("Request Axis-Y"); break;
			case DATA_AxisZ: __strName = _T("Request Axis-Z"); break;
			default: __strName = _T("<No Used>"); break;
			}
		}
	}
	void GetDataName_PLC(int __nBeginAddr, DataAddr & __Addr, CString & __strName) {
		if (__Addr.m_nSize == 1) {
			switch(__Addr.m_nBit) {
			case SIGNAL_Response: __strName = _T("Move Complete"); break;
			case SIGNAL_OK: __strName = _T("Move OK"); break;
			case SIGNAL_NG: __strName = _T("Move NG"); break;
			case SIGNAL_Alarm: __strName = _T("Move Alarm"); break;
			case SIGNAL_Request: __strName = _T("Vision Trigger"); break;
			default: __strName = _T("<No Used>"); break;
			}
		}
		else {
			switch(__Addr.m_nOffset - __nBeginAddr) {
			case DATA_Signal: __strName = _T("Signal"); break;
			case DATA_Model: __strName = _T("Current Model No."); break;
			case DATA_AxisU: __strName = _T("Current Axis-U"); break;
			case DATA_AxisV: __strName = _T("Current Axis-V"); break;
			case DATA_AxisW: __strName = _T("Current Axis-W"); break;
			case DATA_AxisX: __strName = _T("Current Axis-X"); break;
			case DATA_AxisY: __strName = _T("Current Axis-Y"); break;
			case DATA_AxisZ: __strName = _T("Current Axis-Z"); break;
			default: __strName = _T("<No Used>");
			}
		}
	}
	// PC Data
	
	// PLC Data
	DataAddr	m_DataMap_PLC[64];
	DataAddr	m_DataMap_PC[64];
	DECLARE_DYNAMIC(CDlg_MAPLC)

public:
	void MNVRelease() { EndThread(); }
	CDlg_MAPLC(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_MAPLC();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MA_PLC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedPlcSend();

	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();

	virtual void Thread() {

	}
	CMNVListCtrl m_ctrlDataPLC;
	CMNVListCtrl m_ctrlDataPC;
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	CButton m_ctrlSetPC;
	CButton m_ctrlSetPLC;
};
