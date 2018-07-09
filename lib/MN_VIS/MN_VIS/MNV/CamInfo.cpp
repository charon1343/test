//#include "stdafx.h"
#include "Define_Cog.h"
#include "CamInfo.h"
//#include "CogDisplayEventHandler.h"
//#include "MCarBodyInspectionAlgorithm.h"
#include <eh.h>	//for exception handling

class SE_Exception
{
private:
	unsigned int nSE;
	PEXCEPTION_POINTERS m_pExceptionPointers;

public:
	SE_Exception() {}
	SE_Exception(unsigned int n, PEXCEPTION_POINTERS pExceptionPointers) : nSE(n), m_pExceptionPointers(pExceptionPointers) {}
	~SE_Exception() {}
	unsigned int getSeNumber() { return nSE; }
	PEXCEPTION_POINTERS getExceptionPointers()
	{
		return m_pExceptionPointers;
	}
};
void trans_func(unsigned int u, EXCEPTION_POINTERS *pExp)
{
	CString str;
	str.Format(_T("in trans_func : Exception is detedted!!! (code = %x)"), u);
	OutputDebugString(str);

	throw SE_Exception(u, pExp);
}
int filter(unsigned int code, struct _EXCEPTION_POINTERS *ep)
{
	OutputDebugString(_T("in filter."));

	if (code == EXCEPTION_ACCESS_VIOLATION)
	{
		OutputDebugString(_T("caught AV as expected."));
		return EXCEPTION_EXECUTE_HANDLER;
	}
	else
	{
		OutputDebugString(_T("didn't catch AV, unexpected."));
		return EXCEPTION_CONTINUE_SEARCH;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
CCamInfo::CCamInfo()
{
	//if (__lpName == NULL) {
	//	m_strName.Format(_T("CamInfo[0x%08x]"), this);
	//}
	//else {
	//	m_strName = __lpName;
	//}
	
	m_nInterval = 100;
	m_EventGrab.Create(TRUE, FALSE);

	m_stCamInfo.IniData();
	//m_stSetting.strFrameGrabber = _T("");
	//m_stSetting.strVideoFormat = _T("");
	//m_stSetting.dVersion = 1.0;		/* version */
	//m_stSetting.dExposure = 10;		/* 노출 시간 ms */
	//m_stSetting.dBrightness = 1;	/* 밝기 rate(0~1) */
	//m_stSetting.Resolution = CMNV_STPoint(1.5, 1.5);	/* 카메라 분해능 */
	//m_stSetting.dExposureMul = 1;	// 쎈텍 카메라일 경우 s / ms / us / ns ... ????
	//m_stSetting.cdFlipRotate = MNVFRM_NONE;

	m_nWidth = 0;			/* 카메라 해상도(가로) */
	m_nHeight = 0;			/* 카메라 해상도(세도) */

	m_pGrabCallback = NULL;	/* Grap Call back Function Point */
	m_pContext = NULL;		/* Call Back Context Point */

//	m_bGrabbing = false;	/* Grap 동작 상태 Frag */
//	m_pGrabThread = NULL;	/* Grap Thread Point - 사용안함 */
		//m_pwmdDisplay = new CMCogDisplay;	/* Grap Image Display (Wnd) */
	//	m_pDisplayEventHandler = new CCogDisplayEventHandler;	/* Event Handler (Mouse, Keyboard...) */

	m_bFinding = false;		/* 검출 동작 상태 Frag */
	m_bFindingResult = false;	/* 검출 결과 Frag */
	m_bWindowClear = false;		//CamInfo.h에 선언된 bool값
}
CCamInfo::~CCamInfo()
{
	m_EventGrab.SetBreak();
	m_EventGrab.SetEvent();
	m_AcqFifo.Release();
}

//bool CCamInfo::SetFlipRotate(int nFlip, int nRotation)
//{ 
//	m_stSetting.cdFlipRotate = (CogIPOneImageFlipRotateOperationConstants)((nFlip << 2) & 0x0004 | (nRotation) & 0x0003);
//
//	if (m_pImageFlipRotate == NULL) m_pImageFlipRotate.Create();
//
//	if ( SUCCEEDED(m_pImageFlipRotate->put_OperationInPixelSpace(m_stSetting.cdFlipRotate)) ) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//bool CCamInfo::SetFlipRotate(int __cdFlipRotate)
//{
//	m_stSetting.cdFlipRotate = (CogIPOneImageFlipRotateOperationConstants)__cdFlipRotate;
//
//	if (m_pImageFlipRotate == NULL) m_pImageFlipRotate.Create();
//
//	if ( SUCCEEDED(m_pImageFlipRotate->put_OperationInPixelSpace(m_stSetting.cdFlipRotate)) ) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//bool CCamInfo::SetFlipRotate(CogIPOneImageFlipRotateOperationConstants __cdFlipRotate)
//{
//	m_stSetting.cdFlipRotate = __cdFlipRotate;
//
//	if (m_pImageFlipRotate == NULL) m_pImageFlipRotate.Create();
//
//	if ( SUCCEEDED(m_pImageFlipRotate->put_OperationInPixelSpace(m_stSetting.cdFlipRotate)) ) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//bool CCamInfo::SetFlipRotate()
//{
//	if (m_pImageFlipRotate == NULL) m_pImageFlipRotate.Create();
//
//	if ( SUCCEEDED(m_pImageFlipRotate->put_OperationInPixelSpace(m_stSetting.cdFlipRotate)) ) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}

bool CCamInfo::SetCamSetting(const STCamSetting & __stCamSetting) {
	if (m_isDummy) {
		return false;
	}
	bool Result = true;
	if (! SetExposure(__stCamSetting.dExposure)) Result = false;
	if (! SetContrast(__stCamSetting.dContrast)) Result = false;
	if (! SetBrightness(__stCamSetting.dBrightness)) Result = false;
	return Result;
}
bool CCamInfo::GetCamSetting(STCamSetting & __stCamSetting) {
	if (m_isDummy) {
		__stCamSetting.dBrightness = 0;
		__stCamSetting.dContrast = 0;
		__stCamSetting.dExposure = 0;
		return true;
	}
	bool Result = true;
	__stCamSetting.dExposure = GetExposure();
	__stCamSetting.dContrast = GetContrast();
	__stCamSetting.dBrightness = GetBrightness();
	return Result;
}

bool CCamInfo::SetExposure(double __dExposure /*= -1*/)
{	// 노출
	if (m_isDummy) {
		return false;
	}
	m_stCamInfo.dExposureTime = (__dExposure < 0) ? m_stCamInfo.dExposureTime : __dExposure;
	return m_AcqFifo.SetExposure(m_stCamInfo.dExposureTime);
}
bool CCamInfo::SetContrast(double __dContrast)
{
	if (m_isDummy) {
		return false;
	}
	m_stCamInfo.dContrast = (__dContrast < 0) ? m_stCamInfo.dContrast : __dContrast;
	return m_AcqFifo.SetContrast(m_stCamInfo.dContrast);
}
bool CCamInfo::SetBrightness(double __dBrightness /*= -1*/)
{	// 밝기
	if (m_isDummy) {
		return false;
	}
	m_stCamInfo.dBrightness = (__dBrightness < 0) ? m_stCamInfo.dBrightness : __dBrightness;
	return m_AcqFifo.SetBrightness(m_stCamInfo.dBrightness);
}
double CCamInfo::GetExposure()
{
	if (m_isDummy) return 0;
	double dValue = 0;
	if (m_AcqFifo != NULL) m_AcqFifo.GetExposure(dValue);
	return dValue;
}
double CCamInfo::GetBrightness()
{
	if (m_isDummy) return 0;
	double dValue = 0;
	if (m_AcqFifo != NULL) m_AcqFifo.GetBrightness(dValue);
	return dValue;
}
double CCamInfo::GetContrast()
{
	if (m_isDummy) return 0;
	double dValue = 0;
	if (m_AcqFifo != NULL) m_AcqFifo.GetContrast(dValue);
	return dValue;
}

bool CCamInfo::Init(LPCTSTR __lpstrName, ICogFrameGrabber *__pFrameGrabber, bool __isLive)
{
	//m_strName = __lpstrName;
	if (__pFrameGrabber == NULL) { // Dummy Channel
		//m_FrameBuffer.Create();
		m_isDummy = true;
		return true;
	}
	m_isDummy = false;
	m_AcqFifo.Release();
	//	CreateAcqFifo(
	//			BSTR VideoFormat
	//		,	CogAcqFifoPixelFormatConstants FifoType
	//		,	VARIANT_BOOL AutoPrepare
	//		,	ICogAcqFifo **pVal
	//	)AfxBeginThread(CCamInfo::BeginThread, &(m_CamInfo[nIndex]));
	if (FAILED( __pFrameGrabber->CreateAcqFifo(//CComBSTR("Cognex NullFormat")
		CComBSTR("Generic GigEVision (Mono)"), cogAcqFifoPixelFormat8Grey, 0, VARIANT_FALSE, &m_AcqFifo) ) ) {
		return false;
	}
	GrabStop();
	m_AcqFifo.SetBrightness(m_stCamInfo.dBrightness);
	m_AcqFifo.SetContrast(m_stCamInfo.dContrast);
	m_AcqFifo.SetExposure(m_stCamInfo.dExposureTime);

	BeginThread();
	return true;
}
void CCamInfo::Release()
 {
	EndThread();
	//CMNVLock LockGrab(m_pLockGrap, MNVLM_Write);
	if (m_AcqFifo != NULL) {
		CMNVFrameGrabber pGraber;
		pGraber.Release();
		m_AcqFifo->get_FrameGrabber(&pGraber);
		m_AcqFifo.Release();
		pGraber.Release();
	}
}

void CCamInfo::LoadIni(LPCTSTR __strDir, LPCTSTR __strFile, LPCTSTR __strSection)
{
	m_stCamInfo.LoadData(__strDir, __strFile, __strSection);
	//m_stSetting.dVersion = 1.0;		/* version */
	//CMNVIni::GetValue(__lpSection, _T("Channel"), m_stSetting.strFrameGrabber, _T(""), __lpFilepath);
	//CMNVIni::GetValue(__lpSection, _T("Format"), m_stSetting.strVideoFormat, _T(""), __lpFilepath);
	//SetResolution( CMNVIni::GetValue(__lpSection, _T("ResolutionX"), 1.5, __lpFilepath) , CMNVIni::GetValue(__lpSection, _T("ResolutionY"), 1.5, __lpFilepath) );
	//SetFlipRotate( CMNVIni::GetValue(__lpSection, _T("Flip"), 0, __lpFilepath) , CMNVIni::GetValue(__lpSection, _T("Rotate"), 0, __lpFilepath) );
}
void CCamInfo::SaveIni(LPCTSTR __strDir, LPCTSTR __strFile, LPCTSTR __strSection)
{
	m_stCamInfo.SaveData(__strDir, __strFile, __strSection);
	//m_stSetting.dVersion = 1.0;		/* version */
	//CMNVIni::SetValue(__lpSection, _T("Channel"), m_stSetting.strFrameGrabber, __lpFilepath);
	//CMNVIni::SetValue(__lpSection, _T("Format"), m_stSetting.strVideoFormat, __lpFilepath);
	//CMNVIni::SetValue(__lpSection, _T("Exposure"), m_stSetting.dExposure, __lpFilepath);
	//CMNVIni::SetValue(__lpSection, _T("Brightness"), m_stSetting.dBrightness, __lpFilepath);
	//CMNVIni::SetValue(__lpSection, _T("Contrast"), m_stSetting.dContrast, __lpFilepath);
	//CMNVIni::SetValue(__lpSection, _T("ExposureMul"), m_stSetting.dExposureMul, __lpFilepath);
	//CMNVIni::SetValue(__lpSection, _T("ResolutionX"), m_stSetting.Resolution.GetX(), __lpFilepath);
	//CMNVIni::SetValue(__lpSection, _T("ResolutionY"), m_stSetting.Resolution.GetY(), __lpFilepath);
	//CMNVIni::SetValue(__lpSection, _T("Flip"), GetFlip(), __lpFilepath);
	//CMNVIni::SetValue(__lpSection, _T("Rotate"), GetRotation(), __lpFilepath);
}

//void CCamInfo::WindowClear()
//{
//	//CallStack Msg(_T("void CCamInfo::WindowClear()"));
//	//CComPtr<ICogStaticGraphicsContainer> pStaticGraphicContainer;
//	//m_pCogDisplay->get_StaticGraphics(&pStaticGraphicContainer);
//	//pStaticGraphicContainer->Clear();
//}

UINT CCamInfo::ProcFrameLive()
{
	//CMNVLogFile m_LogFile(m_strName, _T("LiveGrab"), _T("C:"), m_strName);
	int m_nFPS = 5;
	int nCurrentTime;
	SYSTEMTIME stTime;
	GetLocalTime(&stTime);
	nCurrentTime = stTime.wSecond * 1000 + stTime.wMilliseconds;
	// 지속적으로 Frame을 취득한다. : Thread를 생성해서 호출할것...... : Return을 않함.
	//isContinue = true;
	//isThreadRun = true;

	//m_AcqFifo.SetBrightness(m_stCamInfo.dBrightness);
	//m_AcqFifo.SetContrast(m_stCamInfo.dContrast);
	//m_AcqFifo.SetExposure(m_stCamInfo.dExposureTime);
	//m_AcqFifo.GetROI(m_nWidth, m_nHeight);
	while(true) {
		switch( m_EventGrab.Wait() ) {
			case MNVWR_Event:
				if (SUCCEEDED(m_AcqFifo.GrabImage(m_FrameBuffer))) {
					//m_LogFile.OutputMessage(_T("Grab Succeeded"));
				}
				else {
					//m_LogFile.OutputMessage(_T("Grab Failed"));
				}
				break;
			case MNVWR_TimeOut:
				break;
			case MNVWR_Break:
				m_EventGrab.ResetEvent();
				return 0;
			default:
				break;
		}/*
		GetLocalTime(&stTime);
		nLastTime = nCurrentTime;
		nCurrentTime = stTime.wSecond * 1000 + stTime.wMilliseconds;
		nTackTime = (nCurrentTime > nLastTime) ? (nCurrentTime - nLastTime) : (nCurrentTime + 60000 - nLastTime);
		nTackTime = 1000 / m_nFPS - nTackTime;
		m_LogFile.OutputData(_T("Delay"), nTackTime);
		Sleep(nTackTime > 0 ? nTackTime : 0);
		*/
		Sleep(30);
	}
	isThreadRun = false;
	return 0;
}

