#pragma once

enum MNV_SOCK_STATE { MNVSOCK_NONE = 0, MNVSOCK_CREATE = 1, MNVSOCK_CONNECT = 2 };
// CMNVSocket 명령 대상입니다.
class CMNV_Socket {
	WSADATA wsaData;
	bool isCreate;
	int m_nSocketNo;

	MNV_SOCK_STATE m_steScok;
public:
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
	CMNV_Socket(sockaddr_in * __Addr) {
		m_steScok = MNVSOCK_NONE;
		Create();
		//Bind(0);
		Connect(__Addr);
	}
	CMNV_Socket(SOCKET __nSocket) {
		m_steScok = MNVSOCK_NONE; 
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
		return closesocket(m_nSocketNo) != SOCKET_ERROR; 
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
			Sleep(50);
		}
		return true;
		//{	//Receive_Header()
		//	int __nLength = __Recv.GetLength_Header();
		//	char * pBuf = __Recv.GetPoint_Header();
		//	while (__nLength > 0) {
		//		int length = recv(m_nSocketNo, pBuf, __nLength, 0);	// 응답 데이터 수신
		//		__nLength -= length;
		//		pBuf += length;
		//	}
		//}
		//{	// Receive Data()
		//	int __nLength = __Recv.GetLength_Data();
		//	char * pBuf = __Recv.GetPoint_Data();
		//	while (__nLength > 0) {
		//		int length = recv(m_nSocketNo, pBuf, __nLength, 0);	// 응답 데이터 수신
		//		__nLength -= length;
		//		pBuf += length;
		//	}
		//}

		//char * pBuf = (char *) &__Recv;
		//	
		//return true;
	}
	bool Send(void * __pPacket, int __nSize) {
		if (send(m_nSocketNo, (char *)__pPacket, __nSize, 0) == SOCKET_ERROR) {
			return false;
		}
		else{
			return true;
		}
	}
};
