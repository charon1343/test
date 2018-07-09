#pragma once
#pragma pack(push)
#pragma pack(1)

#include "MNVSocket.h"

struct STAdam_Header {
	unsigned __int8 Header[6];
	unsigned __int8 Device;
	unsigned __int8 Command;
};
struct STAdam_Command {
	unsigned __int16 Address;
	unsigned __int16 Count;
};
union UNIData {
	unsigned __int8 Byte[100];
	unsigned __int32 DWord[25];
};
struct STAdam_Responce {
	unsigned __int8	Count;
	UNIData		Data;
};
union UNIAdam_Data{
	STAdam_Command	stCmd;
	STAdam_Responce stRes;
};
enum MNV_DIO { DI0 = 0, DI1, DI2, DI3, DI4, DI5, DI6, DI7, DI8, DI9, DI10, DI11, DO0 = 16, DO1, DO2, DO3, DO4, DO5 };

struct STAdam_Protocol {
	STAdam_Header		stH;
	UNIAdam_Data		stD;

	// 00000000000001010000000C
	void SetRequestRead(__int16 __Address, __int16 __Count) {
		memset(this, 0, sizeof(STAdam_Protocol));
		stH.Device = 0x01;
		stH.Command = 0x01;
		stD.stCmd.Address = htons(__Address);
		stD.stCmd.Count = htons(__Count);
	}
	//00000000000001050010FF00
	void SetRequestWrite(__int16 __Address, bool __isSet) {
		memset(this, 0, sizeof(STAdam_Protocol));
		stH.Device = 0x01;
		stH.Command = 0x05;
		stD.stCmd.Address = htons(__Address);
		stD.stCmd.Count = __isSet ? 0x00FF : 0x0000;
	}
	// 000000000005 0101 020000
};
#pragma pack(pop)

extern unsigned long WINAPI Thread_AdamSync(void * __pParm);

class CMNV_Adam6050 {
	bool m_isConnected;
	sockaddr_in m_stAdamAddr;						// Ethernet 모듈측 데이터 
	unsigned __int32	m_dwData;

	CMNV_Socket * m_pSocket;
public:
	bool IsConnected() { return m_isConnected; }
	CMNV_Adam6050() { memset(this, 0, sizeof(CMNV_Adam6050)); }
	void Init(LPCSTR __lpstrIP, int __nPort) {
		m_stAdamAddr.sin_family = AF_INET;
		m_stAdamAddr.sin_addr.s_addr = inet_addr(__lpstrIP);
		m_stAdamAddr.sin_port = htons(__nPort);
		DWORD threadid;
		CreateThread(NULL, 0, Thread_AdamSync, this, 0, &threadid);
	}

	bool operator [] (int __nIndex) {
		unsigned __int32 dwMark = (0x00000001 << __nIndex);
		return (m_dwData & dwMark) == dwMark;
	}

protected:
	STAdam_Protocol m_stBuffer;
	bool m_isValue[6];
	bool m_isUpdate[6];
	void SendWrite(int __nIndex) {
		if (m_isConnected && m_isUpdate[__nIndex]) {
			if (m_isConnected) m_isUpdate[__nIndex] = false;
			if (m_isConnected) m_stBuffer.SetRequestWrite(16 + __nIndex, m_isValue[__nIndex]);
			if (m_isConnected) m_isConnected = m_pSocket->Send(&m_stBuffer, sizeof(m_stBuffer.stH) + sizeof(m_stBuffer.stD.stCmd));
			if (m_isConnected) m_isConnected = m_isConnected = m_pSocket->Receive(&m_stBuffer, 6);
		}
	}
	void SendRead() {
		if (m_isConnected) m_stBuffer.SetRequestRead(0, 32);
		if (m_isConnected) m_isConnected = m_pSocket->Send(&m_stBuffer, sizeof(m_stBuffer.stH) + sizeof(m_stBuffer.stD.stCmd));
		if (m_isConnected) m_isConnected = m_pSocket->Receive(&m_stBuffer, sizeof(m_stBuffer.stH) + 1);
		if (m_isConnected) m_isConnected = m_pSocket->Receive(&(m_stBuffer.stD.stRes.Data), m_stBuffer.stD.stRes.Count);
		if (m_isConnected) m_dwData = m_stBuffer.stD.stRes.Data.DWord[0];
	}

public:
	void Proc_SetOut(int __nIndex) {
		unsigned __int32 dwMark = (0x00000001 << (DO0 + __nIndex));
		bool isValue = (m_dwData & dwMark) != dwMark;
		m_isValue[__nIndex] = isValue;
		m_isUpdate[__nIndex] = true;
	}
	void Proc_SetOut(int __nIndex, bool __isValue) {
		unsigned __int32 dwMark = (0x00000001 << (DO0 + __nIndex));
		bool isValue = (m_dwData & dwMark) == dwMark;

		if (isValue != __isValue) {
			m_isValue[__nIndex] = __isValue;
			m_isUpdate[__nIndex] = true;
		}
	}
 	void AdamThread() {
		bool isConnect = true;
		m_pSocket = new CMNV_Socket(&m_stAdamAddr);//("200.100.100.50", 502);
		m_isConnected = true;

		while (isConnect) {
			if (m_isConnected) {
				SendWrite(0);
				SendWrite(1);
				SendWrite(2);
				SendWrite(3);
				SendWrite(4);
				SendWrite(5);
				SendRead();
			}
			else {
				m_isConnected = m_pSocket->Connect(&m_stAdamAddr);//"200.100.100.50", 502);
			}
			Sleep(10);
		}
	}
};
