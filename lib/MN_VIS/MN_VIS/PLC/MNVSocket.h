#pragma once
#include <afxwin.h>

enum MNV_SOCK_STATE { MNVSOCK_NONE = 0, MNVSOCK_CREATE = 1, MNVSOCK_CONNECT = 2 };
// CMNVSocket 명령 대상입니다.
class CMNV_Socket {
	WSADATA wsaData;
	bool isCreate;
	SOCKET m_nSocketNo;

	MNV_SOCK_STATE m_steScok;
public:
	static unsigned __int32 IPAddress(LPCWSTR __strIP) {
		unsigned __int32 dwIP = 0;
		unsigned __int32 dwTemp = 0;
		int nIndex = 0;
		while (__strIP[nIndex] != 0) {
			switch(__strIP[nIndex]) {
			case '0':	dwTemp = dwTemp * 10 + 0;	break;
			case '1':	dwTemp = dwTemp * 10 + 1;	break;
			case '2':	dwTemp = dwTemp * 10 + 2;	break;
			case '3':	dwTemp = dwTemp * 10 + 3;	break;
			case '4':	dwTemp = dwTemp * 10 + 4;	break;
			case '5':	dwTemp = dwTemp * 10 + 5;	break;
			case '6':	dwTemp = dwTemp * 10 + 6;	break;
			case '7':	dwTemp = dwTemp * 10 + 7;	break;
			case '8':	dwTemp = dwTemp * 10 + 8;	break;
			case '9':	dwTemp = dwTemp * 10 + 9;	break;
			case '.':	dwIP = (dwIP << 8) | dwTemp;	dwTemp = 0; break;
			default:	break;
			}
			++nIndex;
		}
		if (dwTemp != 0) dwIP = (dwIP << 8) | dwTemp;
		return htonl(dwIP);
	}

	bool IsConnect() { return m_steScok == MNVSOCK_CONNECT; }
	CMNV_Socket() { m_steScok = MNVSOCK_CREATE; }
	CMNV_Socket(int __nPort) {
		m_steScok = MNVSOCK_NONE;
		Create();
		Bind(__nPort);
		Listen();
	}
	CMNV_Socket(LPCSTR __strAddress, int __nPort) {
		m_steScok = MNVSOCK_NONE;
		Create();
		//Bind(0);
		Connect(__strAddress, __nPort);
	}
	CMNV_Socket(LPCWSTR __strAddress, int __nPort) {
		m_steScok = MNVSOCK_NONE;
		Create();
		//Bind(0);
		Connect(__strAddress, __nPort);
	}
	CMNV_Socket(unsigned __int32 __dwIP, unsigned __int16 __wdPort) {
		m_steScok = MNVSOCK_NONE;
		Create();
		//Bind(0);
		Connect(__dwIP, __wdPort);
	}
	CMNV_Socket(sockaddr_in * __Addr) {
		m_steScok = MNVSOCK_NONE;
		Create();
		//Bind(0);
		Connect(__Addr);
	}
	CMNV_Socket(SOCKET __nSocket) {
		m_steScok = MNVSOCK_CONNECT; 
		isCreate = false;
		int nErrorStatus = WSAStartup(MAKEWORD(1,2), &wsaData);	
		m_nSocketNo = __nSocket;
	}
	bool Create() {
		isCreate = false;
		int nErrorStatus = WSAStartup(MAKEWORD(1,2), &wsaData);	
		m_nSocketNo = socket(AF_INET, SOCK_STREAM, 0);		// 소켓 생성
		if (m_nSocketNo != INVALID_SOCKET)					// TCP/IP의 소켓 작성 
		{
			m_steScok = MNVSOCK_CREATE;
			isCreate = true;
		}
		return isCreate;
	}
	bool Bind(int __nPort) {
		sockaddr_in hostdata;
		hostdata.sin_family = AF_INET;					// PC 쪽 Socket 구조체 정의 
		hostdata.sin_port = htons(__nPort);					// PC 쪽 Port No, IP Address	
		hostdata.sin_addr.s_addr = htonl(INADDR_ANY);

		return bind(m_nSocketNo, (LPSOCKADDR)&hostdata, sizeof(hostdata)) == 0;
	}
	bool Listen() { return listen(m_nSocketNo, 5) != SOCKET_ERROR; }
	bool Connect(LPCSTR __strAddress, int __nPort) {
		if (m_steScok == MNVSOCK_NONE) {
			Create();
		}
		if (m_steScok == MNVSOCK_CREATE) {
			sockaddr_in addrPLC;						// Ethernet 모듈측 데이터 
			addrPLC.sin_family = AF_INET;					// PLC 쪽 Socket 구조체 정의 
			addrPLC.sin_port = htons(__nPort);					// PLC 쪽 Port No, IP Address	
			addrPLC.sin_addr.s_addr = inet_addr(__strAddress);
			if (connect(m_nSocketNo, (LPSOCKADDR)&addrPLC, sizeof(addrPLC)) == 0 ) {
				m_steScok = MNVSOCK_CONNECT;
				
				return true;
			}
		}
		return false;
	}
	bool Connect(LPCWSTR __strAddress, int __nPort) {
		if (m_steScok == MNVSOCK_NONE) {
			Create();
		}
		if (m_steScok == MNVSOCK_CREATE) {
			sockaddr_in addrPLC;						// Ethernet 모듈측 데이터 
			addrPLC.sin_family = AF_INET;					// PLC 쪽 Socket 구조체 정의 
			addrPLC.sin_port = htons(__nPort);					// PLC 쪽 Port No, IP Address	
			addrPLC.sin_addr.s_addr = IPAddress(__strAddress);
			if (connect(m_nSocketNo, (LPSOCKADDR)&addrPLC, sizeof(addrPLC)) == 0 ) {
				m_steScok = MNVSOCK_CONNECT;
				
				return true;
			}
		}
		return false;
	}
	bool Connect(unsigned __int32 __dwIP, unsigned __int16 __wdPort) {
		if (m_steScok == MNVSOCK_NONE) {
			Create();
		}
		if (m_steScok == MNVSOCK_CREATE) {
			sockaddr_in addrPLC;						// Ethernet 모듈측 데이터 
			addrPLC.sin_family = AF_INET;					// PLC 쪽 Socket 구조체 정의 
			addrPLC.sin_port = __wdPort;					// PLC 쪽 Port No, IP Address	
			addrPLC.sin_addr.s_addr = __dwIP;
			if (connect(m_nSocketNo, (LPSOCKADDR)&addrPLC, sizeof(addrPLC)) == 0 ) {
				m_steScok = MNVSOCK_CONNECT;
				
				return true;
			}
		}
		return false;
	}
	bool Connect(sockaddr_in * paddrPLC) {
		if (m_steScok == MNVSOCK_NONE) {
			Create();
		}
		if (m_steScok == MNVSOCK_CREATE) {
			if (connect(m_nSocketNo, (LPSOCKADDR)paddrPLC, sizeof(sockaddr_in)) == 0 ) {
				m_steScok = MNVSOCK_CONNECT;
				return true;
			}
		}
		return false;
	}
	bool Close() { 
		m_steScok = MNVSOCK_NONE;
		SOCKET Temp = m_nSocketNo;
		m_nSocketNo = INVALID_SOCKET;
		if (Temp != INVALID_SOCKET)
			return closesocket(m_nSocketNo) != SOCKET_ERROR; 
		return true;
	}
	SOCKET Accept() {
		SOCKADDR_IN addr;
		int addrlen = sizeof(addr);
		return WSAAccept(m_nSocketNo, (sockaddr *) &addr, &addrlen, NULL, NULL);
	}

	int GetMajorVersion() { return HIBYTE(wsaData.wVersion); }
	int GetMinorVersion() { return LOBYTE(wsaData.wVersion); }
	bool IsCreated() { return isCreate; }

	bool Receive(void * __pPacket, int __nSize) {
		memset(__pPacket, 0, sizeof(__nSize));

		int __nLength = __nSize;
		char * pBuf = (char *)__pPacket;
		while (__nLength > 0) {
			int length = recv(m_nSocketNo, pBuf, __nLength, 0);	// 응답 데이터 수신
			if (length < 0) {	// Disconnect
				Close();
				return false;
			}
			__nLength -= length;
			pBuf += length;
			Sleep(1);
		}
		return true;
	}
	bool Send(void * __pPacket, int __nSize) {
		if (send(m_nSocketNo, (char *)__pPacket, __nSize, 0) == SOCKET_ERROR) {
			Close();
			return false;
		}
		else{
			return true;
		}
	}
};
