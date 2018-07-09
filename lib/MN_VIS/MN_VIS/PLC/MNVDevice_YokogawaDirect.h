#pragma once
#include "..\MNV\MNVEvent.h"
#include "..\MFC\MNVDevice.h"

#include "MNVSocket.h"
#include "MNVProtocol_Yokogawa.h"

#include <string.h>
#include <map>
using namespace std;
#pragma pack(push)
#pragma pack(1)

class CMNV_SeqMap {
	MNVLock m_Lock;
	int * m_pData;
	int m_nCount;
	int m_nSegment;
public:
	int * GetBuf() { return m_pData; }
	int GetStart() { return m_nSegment; }
	int GetLimit() { return m_nSegment + m_nCount; }
	int GetCount() { return m_nCount; }
	CMNV_SeqMap() {
		m_pData = NULL;
		m_nSegment = 0;
		m_nCount = 0;
	}
	bool Init(int __nAddress, int __nCount) {
		CMNVLock Lock(&m_Lock, MNVLM_Write);
		if (__nCount <= 64 && m_pData == NULL) {
			m_nSegment = __nAddress;
			m_nCount = __nCount;
			m_pData = new int[__nCount];
			ZeroMemory(m_pData, sizeof(int) * __nCount);
			return true;
		}
		else return false;
	}
	bool Relese() {
		CMNVLock Lock(&m_Lock, MNVLM_Write);
		if (m_pData == NULL) return false;
		delete m_pData;
		m_pData = NULL;
		m_nCount = 0;
		m_nSegment = 0;
		return true;
	}
	bool GetBit(int __nAddress, int __nBit) {
		CMNVLock Lock(&m_Lock, MNVLM_Write);
		if (0 <= __nAddress && __nAddress < m_nCount) {
			if (m_pData == NULL) return false;
			int nTemp = m_pData[__nAddress] >> __nBit;
			return (nTemp & 0x01) == 0x01;
		}
		return false;
	}
	bool Togglebit(int __nAddress, int __nBit) {
		CMNVLock Lock(&m_Lock, MNVLM_Write);
		if (0 <= __nAddress && __nAddress < m_nCount) {
			if (m_pData == NULL) return false;
			bool isSet = !GetBit(__nAddress, __nBit);
			SetBit(__nAddress, __nBit, isSet);
			return isSet;
		}
		return false;
	}
	bool SetBit(int __nAddress, int __nBit, bool __isSet) {
		CMNVLock Lock(&m_Lock, MNVLM_Write);
		if (0 <= __nAddress && __nAddress < m_nCount) {
			if (m_pData == NULL) return false;
			if (__isSet) {
				int nTemp = 0x01 << __nBit;
				m_pData[__nAddress] = m_pData[__nAddress] | nTemp;
			}
			else {
				int nTemp = ~(0x01 << __nBit);
				m_pData[__nAddress] = m_pData[__nAddress] & nTemp;
			}
			return true;
		}
		return false;
	}
	int GetWord(int __nAddress) {
		CMNVLock Lock(&m_Lock, MNVLM_Write);
		if (0 <= __nAddress && __nAddress < m_nCount) {
			if (m_pData == NULL) return 0;
			return m_pData[__nAddress];
		}
		return 0;
	}
	bool SetWord(int __nAddress, int __nValue) {
		CMNVLock Lock(&m_Lock, MNVLM_Write);
		if (0 <= __nAddress && __nAddress < m_nCount) {
			if (m_pData == NULL) return false;
			m_pData[__nAddress] = __nValue;
			return true;
		}
		return false;
	}
	int GetDWord(int __nAddress) {
		CMNVLock Lock(&m_Lock, MNVLM_Write);
		if (0 <= __nAddress && __nAddress < (m_nCount - 1)) {
			if (m_pData == NULL) return 0;
			int nHigh = m_pData[__nAddress];
			int nLow = m_pData[__nAddress + 1];
			return ((nHigh << 16) & 0xffff0000) | (nLow & 0x0ffff);
		}
		return 0;
	}
	bool SetDWord(int __nAddress, int __nValue) {
		CMNVLock Lock(&m_Lock, MNVLM_Write);
		if (0 <= __nAddress && __nAddress < (m_nCount - 1)) {
			if (m_pData == NULL) return false;
			int nHigh = (__nValue >> 16) & 0x0ffff;
			int nLow = __nValue & 0x0ffff;
			m_pData[__nAddress] = nHigh;
			m_pData[__nAddress + 1] = nLow;
			return true;
		}
		return false;
	}
};

enum MNVS_PLC {
		PLC_START = 0
	,	PLC_CONNECT
	,	PLC_SINK
	,	PLC_BREAK
};

class CMNVDevice_Yokogawa : public CMNVDevice {
	CString strIP;
	unsigned __int32 m_dwIP;
	unsigned __int16 m_wdPort;
	CMNV_Socket * m_pSocket;
	bool m_isSync;
	MNVS_PLC m_stePLC;
public:
	CString GetIP() {
		unsigned __int8 * pIP = (unsigned __int8 *)(&m_dwIP);
		strIP.Format(_T("%d.%d.%d.%d"), pIP[0], pIP[1], pIP[2], pIP[3]);
		return strIP;
	}
	int GetPort() { return (int)htons(m_wdPort); }
	MNVS_PLC GetState() { return m_stePLC; }
	CMNV_SeqMap m_VisionData;
	CMNV_SeqMap m_PLCData;
public:
	bool IsSync() { return m_isSync; }
	void InitMap_PLC(int __nAddr, int __nCount) {
		m_PLCData.Init(__nAddr, __nCount);
	}
	void InitMap_Vision(int __nAddr, int __nCount) {
		m_VisionData.Init(__nAddr, __nCount);
	}
	void Init(LPCTSTR __strIP, int __nPort) {
		m_dwIP = CMNV_Socket::IPAddress(__strIP);
		m_wdPort = htons(__nPort);
		m_isSync = false;
		m_pSocket = new CMNV_Socket(__strIP, __nPort);

		m_stePLC = PLC_START;
		m_ThreadEvent.Create(TRUE, FALSE);
		m_isDisconnect = false;
		BeginThread();
	}
	void Release() {
		m_VisionData.Relese();
		m_PLCData.Relese();
		m_pSocket->Close();
	}
	void End() {
	}

	void Proc_WriteData() {
		YOKOGAWA_Protocol stProtocol;
		ZeroMemory(&stProtocol, sizeof(YOKOGAWA_Protocol));
		
		int nValue[64];

		int nCount = m_VisionData.GetCount();
		int * pBuf = m_VisionData.GetBuf();
		int nAddress = m_VisionData.GetStart();
		int nLimit = (nCount < 64) ? nCount : 64;
		for(int nIndex = 0; nIndex < nLimit; ++nIndex) {
			nValue[nIndex] = pBuf[nIndex];
		}

		stProtocol.SetReq_SequenceWrite(1, nLimit, nAddress, nValue);

		if (m_pSocket->Send(&stProtocol, stProtocol.GetPacketLength())) {
			if (m_pSocket->Receive(&stProtocol, stProtocol.GetHeaderLength())) {
				if (m_pSocket->Receive(&stProtocol.stCommand, stProtocol.GetDataLength())) {
					if ( stProtocol.stHeader.Command.GetValue() == YOKOGAWA_ACK_SequenceWordWrite) {
						m_stePLC = PLC_SINK;
						return;
					}
				}
			}
		}
		m_stePLC = PLC_CONNECT;
		return;
	}
	void Proc_ReadData() {
		YOKOGAWA_Protocol stProtocol;
		ZeroMemory(&stProtocol, sizeof(YOKOGAWA_Protocol));
		int nAddress = m_PLCData.GetStart();
		int nCount = m_PLCData.GetCount();

		stProtocol.SetReq_SequenceRead(1, nCount, nAddress);
		
		if (m_pSocket->Send(&stProtocol, stProtocol.GetPacketLength())) {
			if (m_pSocket->Receive(&stProtocol, stProtocol.GetHeaderLength())) {
				if (m_pSocket->Receive(&stProtocol.stCommand, stProtocol.GetDataLength())) {
					if ( stProtocol.stHeader.Command.GetValue() == YOKOGAWA_ACK_SequenceWordRead) {
						//if (stProtocol.stHeader.Size.GetValue() >= nCount * 2) {
							for(int nIndex = 0; nIndex < nCount; ++nIndex) {
								m_PLCData.SetWord(nIndex, stProtocol.stCommand.AckSeqRead.Value[nIndex].GetValue());
							}
							m_stePLC = PLC_SINK;
							return;
						//}
					}
				}
			}
		}
		m_stePLC = PLC_CONNECT;
		return;
	}

	CMNVEvent m_ThreadEvent;
	bool m_isDisconnect;
	virtual void Thread() {
		while(true) {
			if (m_isDisconnect) {
				m_stePLC = PLC_BREAK;
				m_ThreadEvent.ResetEvent();
				m_pSocket->Close();
			}
			if (m_ThreadEvent.Wait() != MNVWR_Event) continue;
			if (!m_pSocket->IsConnect()) {
				m_stePLC = PLC_CONNECT;
				m_pSocket->Connect(m_dwIP, m_wdPort);
			}
			if (m_pSocket->IsConnect()) Proc_WriteData();
			if (m_pSocket->IsConnect()) Proc_ReadData();
		}
	}
};
#pragma pack(pop)