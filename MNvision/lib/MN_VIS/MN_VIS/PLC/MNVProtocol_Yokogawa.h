#pragma once
#include <afxwin.h>
#pragma pack(push)
#pragma pack(1)

enum YOKOGAWA_DeviceType {
	YOKOGAWA_DataRegister = 0x0004
,	YOKOGAWA_FileRegister = 0x0002
,	YOKOGAWA_SharedRegister = 0x0012
,	YOKOGAWA_IndexRegister = 0x0016
,	YOKOGAWA_SpecialRegister = 0x001A
,	YOKOGAWA_Linkregister = 0x0017
};
enum YOKOGAWA_CommandCode {
	YOKOGAWA_CMD_SequenceWordRead	= 0x11
,	YOKOGAWA_CMD_SequenceWordWrite	= 0x12
,	YOKOGAWA_CMD_WFL	= 0x13
,	YOKOGAWA_CMD_RandomWordRead		= 0x14
,	YOKOGAWA_CMD_RandomWordWrite	= 0x15
,	YOKOGAWA_CMD_WRS	= 0x16
,	YOKOGAWA_CMD_WRM	= 0x17
,	YOKOGAWA_ACK_SequenceWordRead	= 0x91
,	YOKOGAWA_ACK_SequenceWordWrite	= 0x92
,	YOKOGAWA_ACK_WFL	= 0x93
,	YOKOGAWA_ACK_RandomWordRead		= 0x94
,	YOKOGAWA_ACK_RandomWordWrite	= 0x95
,	YOKOGAWA_ACK_WRS	= 0x96
,	YOKOGAWA_ACK_WRM	= 0x97
};
class MNVD_int8 {
	unsigned __int8 nValue;
public:
	void SetValue(int __nData) { nValue = __nData; }
	int GetValue() { return nValue; }
};
class MNVD_int16 {
	unsigned __int16 nValue;
public:
	unsigned __int16 Convert(unsigned __int16 __Src) { return ((__Src >> 8) & 0x00ff) | ((__Src << 8) & 0xff00); }
	void SetValue(int __nData) { nValue = Convert(__nData); }
	int GetValue() { return (short)Convert(nValue); }
};
class MNVD_int32 {
	unsigned __int32 nValue;
public:
	unsigned __int32 Convert(unsigned __int32 __Src) {
		return ((__Src << 24) & 0xff000000) | ((__Src << 8) & 0x00ff0000) | ((__Src >> 8) & 0x0000ff00) | ((__Src >> 24) & 0x000000ff);
	}
	void SetValue(__int32 __nData) { nValue = Convert(__nData); }
	__int32 GetValue() { return Convert(nValue); }
};


struct YOKOGAWA_Header {
	MNVD_int8	Command;
	union {
		MNVD_int8 CPUNumber;
		MNVD_int8 TerminationCode;
	} HInfo;
	MNVD_int16	Size;
	
	void SetHeader(int __nCmd, int __nCPU, int __nSize) {
		Command.SetValue(__nCmd);
		HInfo.CPUNumber.SetValue(__nCPU);
		Size.SetValue(__nSize);
	}
};

union YOKOGAWA_Command {
	struct CMD_SEQREAD{
		MNVD_int16	DeviceType;
		MNVD_int32	DeviceAddress;
		MNVD_int16	WordCount;
		int SetCount(int __cntBlock) {
			WordCount.SetValue(__cntBlock);
			return sizeof(CMD_SEQREAD); 
		}
		void SetData(int __nDType, int __nDAddr) {
			DeviceType.SetValue(__nDType);
			DeviceAddress.SetValue(__nDAddr);
		}
	} CmdSeqRead;
	struct ACK_SEQREAD{
		MNVD_int16	Value[64];
		int nCount;
		int SetCount(int __CntBlock) {
			nCount = __CntBlock;
			return sizeof(MNVD_int16) * __CntBlock;
		}
		bool SetData(int __nIndex, int __nValue) {
			if (__nIndex < nCount) {
				Value[__nIndex].SetValue(__nValue);
				return true;
			}
			return false;
		}
	} AckSeqRead;
	struct CMD_SEQWRITE{
		struct DEVICE {
			MNVD_int16	DeviceType;
			MNVD_int32	DeviceAddress;
			MNVD_int16	WordCount;
		} Device;
		MNVD_int16	Value[64];
		int SetCount(int __cntWord, int __nDevice, int __nAddress) {
			Device.DeviceType.SetValue(__nDevice);
			Device.DeviceAddress.SetValue(__nAddress);
			Device.WordCount.SetValue(__cntWord);
			return sizeof(DEVICE) + sizeof(MNVD_int16) * __cntWord;
		}
		bool SetData(int __nIndex, int __nValue) {
			Value[__nIndex].SetValue(__nValue);
			return true;
		}
	} CmdSeqWrite;
	struct CMD_RANREAD{
		MNVD_int16	WordCount;
		struct DATA{
			MNVD_int16	DeviceType;
			MNVD_int32	DeviceAddress;
		} Data[32];
		int SetCount(int __cntWord) {
			WordCount.SetValue(__cntWord);
			return sizeof(WordCount);
		}
		int SetData(int __nIndex, int __nDType, int __nDAddress) {
			Data[__nIndex].DeviceType.SetValue(__nDType);
			Data[__nIndex].DeviceAddress.SetValue(__nDAddress);
			return sizeof(DATA);
		}
	} CmdRanRead;
	struct ACK_RANREAD{
		MNVD_int16	Value[32];
		int SetValue(int __nIndex, int __nValue) {
			Value[__nIndex].SetValue(__nValue);
			return sizeof(MNVD_int16);
		}
	} AckRanRead;
	struct CMD_RANWRITE{
		MNVD_int16	WordCount;
		struct DEVICE {
		MNVD_int16	DeviceType;
		MNVD_int32	DeviceAddress;
		MNVD_int16	Value;
		} Device[32];
		int SetCount(int __cntWord) {
			WordCount.SetValue(__cntWord);
			return sizeof(MNVD_int16) + __cntWord * sizeof(DEVICE);
		}
		bool SetValue(int __nIndex, int __nDevice, int __nAddress, int __nValue) {
			if (__nIndex < WordCount.GetValue()) {
				Device[__nIndex].DeviceType.SetValue(__nDevice);
				Device[__nIndex].DeviceAddress.SetValue(__nAddress);
				Device[__nIndex].Value.SetValue(__nValue);
				return true;
			}
			return false;
		}
	} CmdRanWrite;
};

struct YOKOGAWA_Protocol {
	enum Const { Size_Value = 2, Size_Address = 6, Size_Count = 2 , Size_Data = 8 };
	YOKOGAWA_Header stHeader;
	YOKOGAWA_Command stCommand;

	void SetReq_SequenceRead(int __nCPU, int __cntWord, int __nAddress) {
		const YOKOGAWA_CommandCode CMD_CODE = YOKOGAWA_CMD_SequenceWordRead;

		int nSize = stCommand.CmdSeqRead.SetCount(__cntWord);
		stCommand.CmdSeqRead.SetData(YOKOGAWA_DataRegister, __nAddress);

		stHeader.SetHeader(CMD_CODE, __nCPU, nSize);
	}
	void SetAck_SequenceRead(int __nCPU, int __cntWord, int * __pData) {
		const YOKOGAWA_CommandCode CMD_CODE = YOKOGAWA_ACK_SequenceWordRead;

		int nSize = stCommand.AckSeqRead.SetCount(__cntWord);
		for(int nIndex = 0; nIndex < __cntWord; ++nIndex) {
			stCommand.AckSeqRead.SetData(nIndex, __pData[nIndex]);
		}

		stHeader.SetHeader(CMD_CODE, __nCPU, nSize);
	}

	void SetReq_SequenceWrite(int __nCPU, int __cntWord, int __nAddress, int * __pData) {
		const YOKOGAWA_CommandCode CMD_CODE = YOKOGAWA_CMD_SequenceWordWrite;

		int nSize = stCommand.CmdSeqWrite.SetCount(__cntWord, YOKOGAWA_DataRegister, __nAddress);
		for(int nIndex = 0; nIndex < __cntWord; ++nIndex) {
			stCommand.CmdSeqWrite.SetData(nIndex, __pData[nIndex]);
		}
		stHeader.SetHeader(CMD_CODE, __nCPU, nSize);
	}
	void SetAck_SequenceWrite(int __nCPU) {
		const YOKOGAWA_CommandCode CMD_CODE = YOKOGAWA_ACK_SequenceWordWrite;
		int nSize = 0;
		
		stHeader.SetHeader(CMD_CODE, __nCPU, nSize);
	}

	void SetReq_RandomRead(int __nCPU, int __cntWord, int * __pAddress) {
		const YOKOGAWA_CommandCode CMD_CODE = YOKOGAWA_CMD_RandomWordRead;

		int nSize = stCommand.CmdRanRead.SetCount(__cntWord);
		for(int nIndex = 0; nIndex < __cntWord; ++nIndex) {
			stCommand.CmdRanRead.SetData(nIndex, YOKOGAWA_DataRegister, __pAddress[nIndex]);
		}
		stHeader.SetHeader(CMD_CODE, __nCPU, nSize);
	}
	void SetAck_RandomRead(int __nCPU, int __cntWord, int * __pData) {
		const YOKOGAWA_CommandCode CMD_CODE = YOKOGAWA_ACK_RandomWordRead;

		int nSize = 0;
		for(int nIndex = 0; nIndex < __cntWord; ++nIndex) {
			nSize += stCommand.AckRanRead.SetValue(nIndex, __pData[nIndex]);
		}
		stHeader.SetHeader(CMD_CODE, __nCPU, nSize);
	}

	void SetReq_RandomWrite(int __nCPU, int __cntWord, int * __pAddress, int * __pData) {
		const YOKOGAWA_CommandCode CMD_CODE = YOKOGAWA_CMD_RandomWordWrite;

		int nSize = stCommand.CmdRanWrite.SetCount(__cntWord);
		for(int nIndex = 0; nIndex < __cntWord; ++nIndex) {
			stCommand.CmdRanWrite.SetValue(nIndex, YOKOGAWA_DataRegister, __pAddress[nIndex], __pData[nIndex]);
		}

		stHeader.SetHeader(CMD_CODE, __nCPU, nSize);
	}
	void SetAck_RandomWirte(int __nCPU) {
		const YOKOGAWA_CommandCode CMD_CODE = YOKOGAWA_ACK_RandomWordWrite;
		//#define COMMAND stProtocol.stCommand.AckRanWrite

		int nSize = 0;

		stHeader.SetHeader(CMD_CODE, __nCPU, nSize);
	}

	int GetPacketLength() { return sizeof(stHeader) + stHeader.Size.GetValue(); }
	int GetHeaderLength() { return sizeof(stHeader); }
	int GetDataLength() { return stHeader.Size.GetValue(); }
};

#pragma pack(pop)
