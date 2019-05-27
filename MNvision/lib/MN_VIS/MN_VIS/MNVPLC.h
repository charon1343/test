#pragma once
#include "PLC\MNVDevice_YokogawaDirect.h"

enum MNVType_Memory {
		MNVT_MemErr = -1
	,	MNVT_MemBit = 0
	,	MNVT_MemWord = 2
	,	MNVT_MemDWord = 4
};
struct STPLCAddress {
	int nAddress;
	int nBit;
	MNVType_Memory nType;

	void Load(LPCTSTR __strSection, LPCTSTR __strFilePath) {
		nAddress = CMNVIni::GetValue(__strSection, _T("Address"), 0, __strFilePath);
		nBit	 = CMNVIni::GetValue(__strSection, _T("Bit"), 0, __strFilePath);
		nType	 = (MNVType_Memory)CMNVIni::GetValue(__strSection, _T("Type"), 2, __strFilePath);
	}
	void Save(LPCTSTR __strSection, LPCTSTR __strFilePath) {
		CMNVIni::SetValue(__strSection, _T("Address"), nAddress, __strFilePath);
		CMNVIni::SetValue(__strSection, _T("Bit"), nBit, __strFilePath);
		CMNVIni::SetValue(__strSection, _T("Type"), nType, __strFilePath);
	}
};

enum MNVMap_PLC { /// PLC => PC
	//// Common
	//// PLC Auto
		MNVMap_PLC_Prepare = 0
	,	MNVMap_PLC_Trigger
	,	MNVMap_PLC_Finish
	,	MNVMap_PLC_End

	//// Vision AreaScan Setting
	,	MNVMap_PLC_SelectOK
	,	MNVMap_PLC_SelectNG

	//// Vision LineScan Setting
	,	MNVMap_PLC_SettingOK
	,	MNVMap_PLC_SettingNG

	,	MNVMap_PLC_Model
	,	MNVMap_PLC_Item
	,	MNVMap_PLC_Speed
	,	MNVMap_PLC_Working

	,	MNVMap_PLC_Count
};
enum MNVMap_PC {
	//// PLC Auto
		MNVMap_Vision_Wait = 0
	,	MNVMap_Vision_Ready
	,	MNVMap_Vision_Grab
	,	MNVMap_Vision_Inspect

	,	MNVMap_Vision_Result
	,	MNVMap_Vision_OK
	,	MNVMap_Vision_NG
	,	MNVMap_Vision_Alarm

	,	MNVMap_Vision_SelectReq

	,	MNVMap_Vision_SettingReq

	,	MNVMap_Vision_Model
	,	MNVMap_Vision_Item
	,	MNVMap_Vision_Speed
	,	MNVMap_Vision_Working

	,	MNVMap_Vision_Count
};

#define REQUEST_MODEL PLC_GetValue(MNVMap_PLC_Model)
#define REQUEST_ITEM PLC_GetValue(MNVMap_PLC_Model)
#define CURRENT_MODEL Vision_GetValue(MNVMap_Vision_Model)
#define CURRENT_ITEM Vision_GetValue(MNVMap_Vision_Item)

enum MNV_PLC_SignalCode {
	MNVPLC_Signal_Ready = 1
	, MNVPLC_Signal_Trigger = 2
	, MNVPLC_Signal_Finish = 4
	, MNVPLC_Signal_End = 8
};

class CMNVPLC
{
private: 
	CMNVDevice_Yokogawa m_PLCYokogawa;
	STPLCAddress	m_Map_PLC[MNVMap_PLC_Count];
	STPLCAddress	m_Map_Vision[MNVMap_Vision_Count];

	int m_nVision;
public:
	void Release() {
		m_PLCYokogawa.EndThread();
		m_PLCYokogawa.Release();
	}
	bool IsPLCEnable() { return (m_PLCYokogawa.m_ThreadEvent.Wait(0) == MNVWR_Event); }
	void PLCEnable(bool __isEnable) { 
		if (__isEnable) m_PLCYokogawa.m_ThreadEvent.SetEvent();
		else m_PLCYokogawa.m_ThreadEvent.ResetEvent();
	}
	void PLC_Start(LPCTSTR __strFilePath) {
		PLCSetting_Load(__strFilePath);
		PLCSetting_Save(__strFilePath);
		m_PLCYokogawa.m_ThreadEvent.SetEvent();
	}
	void PLC_ReStart(LPCTSTR __strFilePath) {
		m_PLCYokogawa.Release();
		PLCSetting_Load(__strFilePath);
	}
	void PLCSetting_Load(LPCTSTR __strFilePath) {
		int nPLC_Start = CMNVIni::GetValue(__T("PLC"), _T("Start"), 10100, __strFilePath);
		int nPLC_Count = CMNVIni::GetValue(__T("PLC"), _T("Count"), 64, __strFilePath);
		int nPC_Start = CMNVIni::GetValue(__T("PC"), _T("Start"), 10000, __strFilePath);
		int nPC_Count = CMNVIni::GetValue(__T("PC"), _T("Count"), 64, __strFilePath);
		CString strIP;
		CMNVIni::GetValue(__T("ENet"), _T("IP"), strIP, _T("192.168.0.10"), __strFilePath);
		int nPort = CMNVIni::GetValue(_T("ENet"), _T("Port"), 12289, __strFilePath);
		m_PLCYokogawa.InitMap_PLC(nPLC_Start, nPLC_Count);
		m_PLCYokogawa.InitMap_Vision(nPC_Start, nPC_Count);
		m_PLCYokogawa.Init(strIP, nPort);

		m_Map_PLC[MNVMap_PLC_Prepare].Load(__T("PLC_isPrepare"), __strFilePath);
		m_Map_PLC[MNVMap_PLC_Trigger].Load(__T("PLC_isTrigger"), __strFilePath);
		m_Map_PLC[MNVMap_PLC_Finish].Load(__T("PLC_isFinish"), __strFilePath);
		m_Map_PLC[MNVMap_PLC_End].Load(__T("PLC_isEnd"), __strFilePath);

		m_Map_PLC[MNVMap_PLC_SelectOK].Load(__T("PLC_isSelectOK"), __strFilePath);
		m_Map_PLC[MNVMap_PLC_SelectNG].Load(__T("PLC_isSelectNG"), __strFilePath);

		m_Map_PLC[MNVMap_PLC_SettingOK].Load(__T("PLC_isSettingOK"), __strFilePath);
		m_Map_PLC[MNVMap_PLC_SettingNG].Load(__T("PLC_isSettingNG"), __strFilePath);

		m_Map_PLC[MNVMap_PLC_Model].Load(__T("PLC_Model"), __strFilePath);
		m_Map_PLC[MNVMap_PLC_Item].Load(__T("PLC_Item"), __strFilePath);
		m_Map_PLC[MNVMap_PLC_Speed].Load(__T("PLC_Speed"), __strFilePath);
		m_Map_PLC[MNVMap_PLC_Working].Load(__T("PLC_Working"), __strFilePath);


		m_Map_Vision[MNVMap_Vision_Wait].Load(_T("Vision_isWait"), __strFilePath);
		m_Map_Vision[MNVMap_Vision_Ready].Load(_T("Vision_isReady"), __strFilePath);
		m_Map_Vision[MNVMap_Vision_Grab].Load(_T("Vision_isGrab"), __strFilePath);
		m_Map_Vision[MNVMap_Vision_Inspect].Load(_T("Vision_isInspect"), __strFilePath);

		m_Map_Vision[MNVMap_Vision_Result].Load(_T("Vision_isResult"), __strFilePath);
		m_Map_Vision[MNVMap_Vision_OK].Load(_T("Vision_isOK"), __strFilePath);
		m_Map_Vision[MNVMap_Vision_NG].Load(_T("Vision_isNG"), __strFilePath);
		m_Map_Vision[MNVMap_Vision_Alarm].Load(_T("Vision_isAlarm"), __strFilePath);

		m_Map_Vision[MNVMap_Vision_SelectReq].Load(_T("Vision_isSelect"), __strFilePath);

		m_Map_Vision[MNVMap_Vision_SettingReq].Load(_T("Vision_isSetting"), __strFilePath);

		m_Map_Vision[MNVMap_Vision_Model].Load(_T("Vision_Model"), __strFilePath);
		m_Map_Vision[MNVMap_Vision_Item].Load(_T("Vision_Item"), __strFilePath);
		m_Map_Vision[MNVMap_Vision_Speed].Load(_T("Vision_Speed"), __strFilePath);
		m_Map_Vision[MNVMap_Vision_Working].Load(_T("Vision_Working"), __strFilePath);
	}
	void PLCSetting_Save(LPCTSTR __strFilePath) {
		CMNVFile::CreatePath(__strFilePath);
		CMNVIni::SetValue(__T("PLC"), _T("Start"), m_PLCYokogawa.m_PLCData.GetStart(), __strFilePath);
		CMNVIni::SetValue(__T("PLC"), _T("Count"), m_PLCYokogawa.m_PLCData.GetCount(), __strFilePath);
		CMNVIni::SetValue(__T("PC"), _T("Start"), m_PLCYokogawa.m_VisionData.GetStart(), __strFilePath);
		CMNVIni::SetValue(__T("PC"), _T("Count"), m_PLCYokogawa.m_VisionData.GetCount(), __strFilePath);
		CMNVIni::SetValue(__T("ENet"), _T("IP"), m_PLCYokogawa.GetIP(), __strFilePath);
		CMNVIni::SetValue(_T("ENet"), _T("Port"), m_PLCYokogawa.GetPort(), __strFilePath);

		m_Map_PLC[MNVMap_PLC_Prepare].Save(__T("PLC_isPrepare"), __strFilePath);
		m_Map_PLC[MNVMap_PLC_Trigger].Save(__T("PLC_isTrigger"), __strFilePath);
		m_Map_PLC[MNVMap_PLC_Finish].Save(__T("PLC_isFinish"), __strFilePath);
		m_Map_PLC[MNVMap_PLC_End].Save(__T("PLC_isEnd"), __strFilePath);

		m_Map_PLC[MNVMap_PLC_SelectOK].Save(__T("PLC_isSelectOK"), __strFilePath);
		m_Map_PLC[MNVMap_PLC_SelectNG].Save(__T("PLC_isSelectNG"), __strFilePath);

		m_Map_PLC[MNVMap_PLC_SettingOK].Save(__T("PLC_isSettingOK"), __strFilePath);
		m_Map_PLC[MNVMap_PLC_SettingNG].Save(__T("PLC_isSettingNG"), __strFilePath);

		m_Map_PLC[MNVMap_PLC_Model].Save(__T("PLC_Model"), __strFilePath);
		m_Map_PLC[MNVMap_PLC_Item].Save(__T("PLC_Item"), __strFilePath);
		m_Map_PLC[MNVMap_PLC_Speed].Save(__T("PLC_Speed"), __strFilePath);
		m_Map_PLC[MNVMap_PLC_Working].Save(__T("PLC_Working"), __strFilePath);


		m_Map_Vision[MNVMap_Vision_Wait].Save(_T("Vision_isWait"), __strFilePath);
		m_Map_Vision[MNVMap_Vision_Ready].Save(_T("Vision_isReady"), __strFilePath);
		m_Map_Vision[MNVMap_Vision_Inspect].Save(_T("Vision_isInspect"), __strFilePath);
		m_Map_Vision[MNVMap_Vision_Result].Save(_T("Vision_isResult"), __strFilePath);
		
		m_Map_Vision[MNVMap_Vision_OK].Save(_T("Vision_isOK"), __strFilePath);
		m_Map_Vision[MNVMap_Vision_NG].Save(_T("Vision_isNG"), __strFilePath);
		m_Map_Vision[MNVMap_Vision_Alarm].Save(_T("Vision_isAlarm"), __strFilePath);

		m_Map_Vision[MNVMap_Vision_SelectReq].Save(_T("Vision_isSelect"), __strFilePath);

		m_Map_Vision[MNVMap_Vision_SettingReq].Save(_T("Vision_isSetting"), __strFilePath);

		m_Map_Vision[MNVMap_Vision_Model].Save(_T("Vision_Model"), __strFilePath);
		m_Map_Vision[MNVMap_Vision_Item].Save(_T("Vision_Item"), __strFilePath);
		m_Map_Vision[MNVMap_Vision_Speed].Save(_T("Vision_Speed"), __strFilePath);
		m_Map_Vision[MNVMap_Vision_Working].Save(_T("Vision_Working"), __strFilePath);
	}

	MNVType_Memory PLC_GetType(int __nIndex) {
		if (__nIndex >= MNVMap_PLC_Count) return MNVT_MemErr;
		return m_Map_PLC[__nIndex].nType;
	} 
	bool PLC_ToggleBit(int __nIndex) {
		if (__nIndex >= MNVMap_PLC_Count) return false;
		switch(m_Map_PLC[__nIndex].nType) {
		case MNVT_MemBit:
			m_PLCYokogawa.m_PLCData.Togglebit(m_Map_PLC[__nIndex].nAddress, m_Map_PLC[__nIndex].nBit);
			return true;
		case MNVT_MemWord:
			//m_PLCYokogawa.m_PLCData.Togglebit(m_Map_PLC[__nIndex].nAddress, m_Map_PLC[__nIndex].nBit);
			return false;
		case MNVT_MemDWord:
			//m_PLCYokogawa.m_PLCData.Togglebit(m_Map_PLC[__nIndex].nAddress, m_Map_PLC[__nIndex].nBit);
			return false;
		default:
			return false;
		}
	}
	bool PLC_SetValue(int __nIndex, int __nValue) {
		if (__nIndex >= MNVMap_PLC_Count) return false;
		switch(m_Map_PLC[__nIndex].nType) {
		case MNVT_MemBit:
			m_PLCYokogawa.m_PLCData.SetBit(m_Map_PLC[__nIndex].nAddress, m_Map_PLC[__nIndex].nBit, __nValue != 0);
			return true;
		case MNVT_MemWord:
			m_PLCYokogawa.m_PLCData.SetWord(m_Map_PLC[__nIndex].nAddress, __nValue);
			return false;
		case MNVT_MemDWord:
			m_PLCYokogawa.m_PLCData.SetDWord(m_Map_PLC[__nIndex].nAddress, __nValue);
			return false;
		default:
			return false;
		}		
	}
	int PLC_GetValue(int __nIndex) {
		if (__nIndex >= MNVMap_PLC_Count) return false;
		switch(m_Map_PLC[__nIndex].nType) {
		case MNVT_MemBit:
			return m_PLCYokogawa.m_PLCData.GetBit(m_Map_PLC[__nIndex].nAddress, m_Map_PLC[__nIndex].nBit) ? 1 : 0;
		case MNVT_MemWord:
			return m_PLCYokogawa.m_PLCData.GetWord(m_Map_PLC[__nIndex].nAddress);
		case MNVT_MemDWord:
			return m_PLCYokogawa.m_PLCData.GetDWord(m_Map_PLC[__nIndex].nAddress);
		default:
			return 0;
		}		
	}

	int PLC_GetSignalCode() {
		return ((PLC_GetValue(MNVMap_PLC_End) & 0x01) << 3)
			| ((PLC_GetValue(MNVMap_PLC_Finish) & 0x01) << 2)
			| ((PLC_GetValue(MNVMap_PLC_Trigger) & 0x01) << 1)
			| (PLC_GetValue(MNVMap_PLC_Prepare) & 0x01);
	}
	bool PLC_isPrepare() { return PLC_GetSignalCode() == 0x08; }
	bool PLC_isTrigger() { return PLC_GetSignalCode() == 0x04; }
	bool PLC_isFinish() { return PLC_GetSignalCode() == 0x02; }
	bool PLC_isEnd() { return PLC_GetSignalCode() == 0x01; }

	MNVType_Memory Vision_GetType(int __nIndex) {
		if (__nIndex >= MNVMap_Vision_Count) return MNVT_MemErr;
		return m_Map_Vision[__nIndex].nType;
	} 
	bool Vision_ToggleBit(int __nIndex) {
		if (__nIndex >= MNVMap_Vision_Count) return false;
		switch(m_Map_Vision[__nIndex].nType) {
		case MNVT_MemBit:
			m_PLCYokogawa.m_VisionData.Togglebit(m_Map_Vision[__nIndex].nAddress, m_Map_Vision[__nIndex].nBit);
			return true;
		case MNVT_MemWord:
			//m_PLCYokogawa.m_VisionData.Togglebit(m_Map_Vision[__nIndex].nAddress, m_Map_Vision[__nIndex].nBit);
			return false;
		case MNVT_MemDWord:
			//m_PLCYokogawa.m_VisionData.Togglebit(m_Map_Vision[__nIndex].nAddress, m_Map_Vision[__nIndex].nBit);
			return false;
		default:
			return false;
		}
	}
	bool Vision_SetValue(int __nIndex, int __nValue) {
		if (__nIndex >= MNVMap_Vision_Count) return false;
		switch(m_Map_Vision[__nIndex].nType) {
		case MNVT_MemBit:
			m_PLCYokogawa.m_VisionData.SetBit(m_Map_Vision[__nIndex].nAddress, m_Map_Vision[__nIndex].nBit, __nValue != 0);
			return true;
		case MNVT_MemWord:
			m_PLCYokogawa.m_VisionData.SetWord(m_Map_Vision[__nIndex].nAddress, __nValue);
			return false;
		case MNVT_MemDWord:
			m_PLCYokogawa.m_VisionData.SetDWord(m_Map_Vision[__nIndex].nAddress, __nValue);
			return false;
		default:
			return false;
		}		
	}
	int Vision_GetValue(int __nIndex) {
		if (__nIndex >= MNVMap_Vision_Count) return false;
		switch(m_Map_Vision[__nIndex].nType) {
		case MNVT_MemBit:
			return m_PLCYokogawa.m_VisionData.GetBit(m_Map_Vision[__nIndex].nAddress, m_Map_Vision[__nIndex].nBit) ? 1 : 0;
		case MNVT_MemWord:
			return m_PLCYokogawa.m_VisionData.GetWord(m_Map_Vision[__nIndex].nAddress);
		case MNVT_MemDWord:
			return m_PLCYokogawa.m_VisionData.GetDWord(m_Map_Vision[__nIndex].nAddress);
		default:
			return 0;
		}		
	}

	int Vision_GetSignalCode() {
		return ((Vision_GetValue(MNVMap_Vision_Result) & 0x01) << 4)
			| ((Vision_GetValue(MNVMap_Vision_Inspect) & 0x01) << 3)
			| ((Vision_GetValue(MNVMap_Vision_Grab) & 0x01) << 2)
			| ((Vision_GetValue(MNVMap_Vision_Ready) & 0x01) << 1)
			| (Vision_GetValue(MNVMap_Vision_Wait) & 0x01);
	}

	void Vision_SetAlarm(bool __isAlarm) { Vision_SetValue(MNVMap_Vision_Alarm, __isAlarm ? 1 : 0); }


	int GetRequest_Model() { return PLC_GetValue(MNVMap_PLC_Model); }
	int GetRequest_Item() { return PLC_GetValue(MNVMap_PLC_Item); }
	int GetCurrent_Model() { return Vision_GetValue(MNVMap_Vision_Model); }
	int GetCurrent_Item() { return Vision_GetValue(MNVMap_Vision_Item); }
	int GetCurrent_Vision() { return m_nVision; }
	void SetCurrent_Model(int __nModel) { Vision_SetValue(MNVMap_Vision_Model, __nModel); }
	void SetCurrent_Item(int __nItem) { Vision_SetValue(MNVMap_Vision_Item, __nItem); }
	void SetCurrent_Vision(int __nVision) { m_nVision = __nVision; }
	bool SetCurrentModel(int __nModel, int __nItem, int __nVision = 1) {
		if (0 >= __nModel || __nModel >= 99) return false;
		if (0 >= __nItem || __nItem >= 99) return false;
		if (0 >= __nVision || __nVision >= 99) return false;

		Vision_SetValue(MNVMap_Vision_Model, __nModel);
		Vision_SetValue(MNVMap_Vision_Item, __nItem);
		m_nVision = __nVision;
		return true;
	}

	void SetSTART() {
		Vision_SetValue(MNVMap_Vision_Wait, 0);
		Vision_SetValue(MNVMap_Vision_Ready, 0);
		Vision_SetValue(MNVMap_Vision_Grab, 0);
		Vision_SetValue(MNVMap_Vision_Inspect, 0);
		Vision_SetValue(MNVMap_Vision_Result, 0);

		Vision_SetValue(MNVMap_Vision_OK, 0);
		Vision_SetValue(MNVMap_Vision_NG, 0);
		Vision_SetValue(MNVMap_Vision_Alarm, 0);
	}
	void SetWAIT() {
		Vision_SetValue(MNVMap_Vision_Ready, 0);
		Vision_SetValue(MNVMap_Vision_Grab, 0);
		Vision_SetValue(MNVMap_Vision_Inspect, 0);
		Vision_SetValue(MNVMap_Vision_Result, 0);

		Vision_SetValue(MNVMap_Vision_OK, 0);
		Vision_SetValue(MNVMap_Vision_NG, 0);
		Vision_SetValue(MNVMap_Vision_Wait, 1);
	}
	void SetPREPARE() {
		Vision_SetValue(MNVMap_Vision_Wait, 0);
		Vision_SetValue(MNVMap_Vision_Ready, 0);
		Vision_SetValue(MNVMap_Vision_Grab, 0);
		Vision_SetValue(MNVMap_Vision_Inspect, 0);
		Vision_SetValue(MNVMap_Vision_Result, 0);
	}
	void SetREADY() {
		Vision_SetValue(MNVMap_Vision_Wait, 0);
		Vision_SetValue(MNVMap_Vision_Grab, 0);
		Vision_SetValue(MNVMap_Vision_Inspect, 0);
		Vision_SetValue(MNVMap_Vision_Result, 0);

		Vision_SetValue(MNVMap_Vision_Ready, 1);
	}
	void SetTRIGGER() {
		Vision_SetValue(MNVMap_Vision_Wait, 0);
		Vision_SetValue(MNVMap_Vision_Ready, 0);
		Vision_SetValue(MNVMap_Vision_Inspect, 0);
		Vision_SetValue(MNVMap_Vision_Result, 0);

		Vision_SetValue(MNVMap_Vision_Grab, 1);
	}
	void SetINSPECT() {
		Vision_SetValue(MNVMap_Vision_Wait, 0);
		Vision_SetValue(MNVMap_Vision_Ready, 0);
		Vision_SetValue(MNVMap_Vision_Grab, 0);
		Vision_SetValue(MNVMap_Vision_Result, 0);

		Vision_SetValue(MNVMap_Vision_Inspect, 1);
	}
	void SetRESULT() {
	}
	void SetFINISH(bool __isOK) {
		Vision_SetValue(MNVMap_Vision_Wait, 0);
		Vision_SetValue(MNVMap_Vision_Ready, 0);
		Vision_SetValue(MNVMap_Vision_Grab, 0);
		Vision_SetValue(MNVMap_Vision_Inspect, 0);

		Vision_SetValue(MNVMap_Vision_Result, 1);
		Vision_SetValue(MNVMap_Vision_OK, __isOK ? 1: 0);
		Vision_SetValue(MNVMap_Vision_NG, __isOK ? 0: 1);
	}
	void SetEND() {
	}
	void SetALARM() {
		Vision_SetValue(MNVMap_Vision_Wait, 0);
		Vision_SetValue(MNVMap_Vision_Ready, 0);
		Vision_SetValue(MNVMap_Vision_Grab, 0);
		Vision_SetValue(MNVMap_Vision_Inspect, 0);
		Vision_SetValue(MNVMap_Vision_Result, 0);

		Vision_SetValue(MNVMap_Vision_OK, 0);
		Vision_SetValue(MNVMap_Vision_NG, 0);
		Vision_SetValue(MNVMap_Vision_Alarm, 1);
	}
	void SetNONE() {
		Vision_SetValue(MNVMap_Vision_Wait, 0);
		Vision_SetValue(MNVMap_Vision_Ready, 0);
		Vision_SetValue(MNVMap_Vision_Grab, 0);
		Vision_SetValue(MNVMap_Vision_Inspect, 0);
		Vision_SetValue(MNVMap_Vision_Result, 0);

		Vision_SetValue(MNVMap_Vision_OK, 0);
		Vision_SetValue(MNVMap_Vision_NG, 0);
		Vision_SetValue(MNVMap_Vision_Alarm, 0);
	}
};

