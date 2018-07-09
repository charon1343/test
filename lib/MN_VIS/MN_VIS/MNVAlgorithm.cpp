#include "StdAfx.h"
#include "MNVAlgorithm.h"

//// Resource ID
//// Model_ID, Item_ID, Vision_ID, Grab_ID
//// 0x0MIVGGGG

void STMNV_Model::Load_Pattern() {
	CMNVImageFile m_File;
	m_File.LoadCogImage(_T("D:\\Model\\Model01_01 Vision01\\Master.bmp"), m_imgMaster);
	m_File.LoadCogImage(_T("D:\\Model\\Model01_01 Vision01\\Pattern.bmp"), m_imgPattern);
	m_File.LoadCogImage(_T("D:\\Model\\Model01_01 Vision01\\Mask.bmp"), m_imgMask);

	LPCTSTR __lpstrFile = _T("D:\\Model\\Model01_01 Vision01\\PatternAlign.ini");
	m_dAcceptThreshold = CMNVIni::GetValue(_T("Pattern"), _T("Threshold"), 0.5, __lpstrFile);
	m_dOriginX = CMNVIni::GetValue(_T("Pattern"), _T("OriginX"), 100, __lpstrFile);
	m_dOriginY = CMNVIni::GetValue(_T("Pattern"), _T("OriginY"), 100, __lpstrFile);
	m_dAngleMin = CMNVIni::GetValue(_T("Pattern"), _T("AngleMin"), -3.14, __lpstrFile);
	m_dAngleMax = CMNVIni::GetValue(_T("Pattern"), _T("AngleMax"), 3.14, __lpstrFile);
	m_dScaleMin = CMNVIni::GetValue(_T("Pattern"), _T("ScaleMin"), 0.5, __lpstrFile);
	m_dScaleMax = CMNVIni::GetValue(_T("Pattern"), _T("ScaleMax"), 1.5, __lpstrFile);
}

bool STMNV_Model::GetRegion(CMNVStaticGraphicCollection & __sgcCollection) {
	switch(m_cdType) {
	case MNV_AT_CircularCaliper:	// PolarUnwrap Caliper
		__sgcCollection.Clear();
		if (m_Inspect_PolarUnwrapCaliper.m_ImageProcessing.m_Region != NULL)
			__sgcCollection.AddGraphic(m_Inspect_PolarUnwrapCaliper.m_ImageProcessing.m_Region, 1, cogColorBlue);
		break;
	case MNV_AT_RelativeHistogram: // [Drill Hole Inspect] Region Histogram
		__sgcCollection.Clear();
		m_RelativeHistogram.AddRegion(__sgcCollection);
		break;
	case MNV_AT_AffineCaliper:
		__sgcCollection.Clear();
		if (m_Inspect_AffineTransformCaliper.m_AlgProcessing.m_Region != NULL)
			__sgcCollection.AddGraphic(m_Inspect_AffineTransformCaliper.m_AlgProcessing.m_Region, 1, cogColorBlue);
		break;
	case MNV_AT_CircularBlob:
		break;
	case MNV_AT_RectBlob:
		break;
	}
	return true;
}

bool STMNV_Model::Excute(int __nMode, CMNVImage & __imgSource, CMNVStaticGraphicCollection & __sgcResult) {
	CMNVLock __Lock(&Lock, MNVLM_Write);
	//__imgSource.Copy(m_imgSrc);
	if (__sgcResult == NULL) __sgcResult.Create();

	switch(m_cdType) {
	case MNV_AT_CircularCaliper:
		{
			//__sgcResult.Clear();
			if (m_Inspect_PolarUnwrapCaliper.m_ImageProcessing.m_Region != NULL)
				__sgcResult.AddGraphic(m_Inspect_PolarUnwrapCaliper.m_ImageProcessing.m_Region, 1, cogColorBlue);
			if (m_Inspect_PolarUnwrapCaliper.Excute(__imgSource, __sgcResult)) {
				m_Result = MNVIR_OK;
			}
			else {
				m_Result = MNVIR_PASS;
			}
			
			__sgcResult.AddLabel(10, 10, 2, 100, _T("PolarUnwrapCaliper"), cogColorMagenta, cogColorNone, cogGraphicLabelAlignmentTopLeft);
		}	break;
	case MNV_AT_RelativeHistogram:
		{
			//__sgcResult.Clear();
			__sgcResult.AddGraphic(m_RelativeHistogram.m_cirOpen[0], 1, cogColorBlue);
			__sgcResult.AddGraphic(m_RelativeHistogram.m_cirOpen[1], 1, cogColorBlue);
			__sgcResult.AddGraphic(m_RelativeHistogram.m_cirClose[0], 1, cogColorRed);
			__sgcResult.AddGraphic(m_RelativeHistogram.m_cirClose[1], 1, cogColorRed);

			m_RelativeHistogram.Excute(__imgSource);
			m_RelativeHistogram.GetResult(__sgcResult);
			__sgcResult.AddLabel(10, 10, 2, 100, _T("RelativeHistogram"), cogColorMagenta, cogColorNone, cogGraphicLabelAlignmentTopLeft);

			m_Result = MNVIR_PASS;
		}	break;
	case MNV_AT_AffineCaliper:
		{
			if (m_Inspect_AffineTransformCaliper.m_AlgProcessing.m_Region != NULL)
				__sgcResult.AddGraphic(m_Inspect_AffineTransformCaliper.m_AlgProcessing.m_Region, 1, cogColorYellow);
			m_Inspect_AffineTransformCaliper.Excute(__imgSource, __sgcResult);
			__sgcResult.AddLabel(10, 10, 2, 100, _T("AffineTransformCaliper"), cogColorMagenta, cogColorNone, cogGraphicLabelAlignmentTopLeft);
			m_Result = MNVIR_PASS;
		}	break;
	case MNV_AT_CircularBlob:
		{
			m_InspectCircularBlob.Excute(__imgSource, __sgcResult);
			__sgcResult.AddLabel(10, 10, 2, 100, _T("CircularBlob"), cogColorMagenta, cogColorNone, cogGraphicLabelAlignmentTopLeft);
			m_Result = MNVIR_PASS;
		}
		break;
	case MNV_AT_RectBlob:
		{
			m_InspectRectanbleBlob.Excute(__imgSource, __sgcResult);
			__sgcResult.AddLabel(10, 10, 2, 100, _T("AffineBlob"), cogColorMagenta, cogColorNone, cogGraphicLabelAlignmentTopLeft);
			m_Result = MNVIR_PASS;
		}
		break;
	default:
		{
			//__sgcResult.Clear();
			__sgcResult.AddLabel(10, 10, 2, 100, _T("Pass"), cogColorMagenta, cogColorNone, cogGraphicLabelAlignmentTopLeft);
			m_Result = MNVIR_PASS;
		}
	}
	//m_Inspect_Histogram.Execute(m_imgSrc, __Region, CogHistogramBinModeConstants::cogHistogramBinModeAuto, CogRegionModeConstants::cogRegionModeAffineTransform);

	//if( m_Algorithm.Train(m_imgPattern, m_imgMask, m_dAcceptThreshold, m_dOriginX, m_dOriginY, m_dAngleMin, m_dAngleMax, m_dScaleMin, m_dScaleMax)) {
	//	return m_Algorithm.Execute(imgRaw, CComQIPtr<ICogRegion>(m_retRegion), __sgcResult);
	//}
	return true;
}
void STMNV_Model::Save_Pattern() {
	LPCTSTR __lpstrFile = _T("D:\\Model\\Model01_01 Vision01\\PatternAlign.ini");
	CMNVFile::CreatePath(__lpstrFile);

	CMNVImageFile m_File;
	m_File.SaveCogImage(_T("D:\\Model\\Model01_01 Vision01\\Master.bmp"), m_imgMaster);
	m_File.SaveCogImage(_T("D:\\Model\\Model01_01 Vision01\\Pattern.bmp"), m_imgPattern);
	m_File.SaveCogImage(_T("D:\\Model\\Model01_01 Vision01\\Mask.bmp"), m_imgMask);

	CMNVIni::SetValue(_T("Pattern"), _T("Threshold"), m_dAcceptThreshold, __lpstrFile);
	CMNVIni::SetValue(_T("Pattern"), _T("OriginX"), m_dOriginX, __lpstrFile);
	CMNVIni::SetValue(_T("Pattern"), _T("OriginY"), m_dOriginY, __lpstrFile);
	CMNVIni::SetValue(_T("Pattern"), _T("AngleMin"), m_dAngleMin, __lpstrFile);
	CMNVIni::SetValue(_T("Pattern"), _T("AngleMax"), m_dAngleMax, __lpstrFile);
	CMNVIni::SetValue(_T("Pattern"), _T("ScaleMin"), m_dScaleMin, __lpstrFile);
	CMNVIni::SetValue(_T("Pattern"), _T("ScaleMax"), m_dScaleMax, __lpstrFile);
}

void CMNVAlgorithm::Thread_Auto()
{
	ProcPreProcess(); 
	switch(m_steAlgorithm) {
		case Algorithm_START:
			for(int nIndex = 0; nIndex < 10; ++nIndex) {
				//m_stResult[nIndex].m_nResult = MNVIR_NOR;
				if(nIndex < m_cntFrameGrabber) m_pCamInfo[nIndex].GrabStop();
			}
			State_SetINIT();
			break;
		case Algorithm_INIT:
			if (m_PLC.PLC_GetSignalCode() != MNVPLC_Signal_End)
				State_SetWAIT();
			break;
		case Algorithm_WAIT: ProcWait(); break;
		case Algorithm_PREPARE:	ProcPrepare(); break;
		case Algorithm_READY: ProcReady(); break;
		case Algorithm_TRIGGER: ProcTrigger(); break;
		case Algorithm_RUN:	ProcRun(); break;
		case Algorithm_RESULT: ProcResult(); break;
		case Algorithm_FINISH: ProcFinish(); break;
		case Algorithm_END: State_SetSTART(); break;
		case Algorithm_ALARM: ProcAlarm(); break;
		default: State_SetSTART(); break;
	}
}

void CMNVAlgorithm::Thread_Model()
{
	if(0 < m_nChannel && m_nChannel <= m_cntFrameGrabber)
		m_pCamInfo[m_nChannel - 1].GetBuffer(m_imgGrabber);
}
void CMNVAlgorithm::Thread_Vision()
{
	if(0 < m_nChannel && m_nChannel <= m_cntFrameGrabber)
		m_pCamInfo[m_nChannel - 1].GetBuffer(m_imgGrabber);
}
void CMNVAlgorithm::Thread_System()
{
}

void CMNVAlgorithm::Frame_Grab() {
	if (0 < m_nChannel && m_nChannel <= m_cntFrameGrabber)
		m_IDGrabber = (m_IDGrabber + (m_pCamInfo[m_nChannel - 1].GetBuffer(m_imgGrabber) ? 1 : 0)) & 0x0fffffff;
}

void CMNVAlgorithm::Thread()
{
	//m_nLiveChannel = 0;
	while (true) {
		switch(m_steAlgorithm) {
			case Setting_Model: Thread_Model(); break;
			case Setting_Vision: Thread_Vision(); break;
			case Setting_System: Thread_System(); break;
			default:
				Thread_Auto();
				break;
		}
		if (m_isLive) {
			Frame_Grab();
		}
		else if(m_isGrab) {
			Frame_Grab();
			m_isGrab = false;
		}
		Sleep(10);
	}
}

CMNVAlgorithm::CMNVAlgorithm(void)
{
	m_mdAlgorithm = MNVAlgorithm_MDRun;
	m_steAlgorithm = Algorithm_START;
	m_isChangeProd = true;
}

CMNVAlgorithm::~CMNVAlgorithm(void)
{
}

bool CMNVAlgorithm::Proc_LoadModel(int __nModel, int __nItem, int __nVision) {
	CMNVLogFile Log(_T("CMNVAlgorithm"), _T("Proc_LoadModel"), _T("D:\\Log"), _T("MNVision.txt"));
	if (m_PLC.SetCurrentModel(__nModel, __nItem, __nVision)) {

		CString strSection; { strSection.Format(_T("Grab_%02d"), __nVision); }
		CString strFile; {
			strFile.Format(_T("d:\\Model\\Model%02d_%02d.ini"), __nModel, __nItem);
			CMNVFile::CreatePath(strFile);
		}

		Cmd_LoadCamSetting(strFile, strSection);
		Cmd_LoadLight(strFile, strSection);
	}
	else return false;

	//m_nChannel = 0;
	CurrentCamInfo()->GrabStop();
	//m_stResult[m_PLC.GetCurrent_Item() - 1].m_nState = 0;
	m_Model.Prepare(m_PLC.GetCurrent_Model(), m_PLC.GetCurrent_Item(), m_PLC.GetCurrent_Vision());
	return true;
}
void CMNVAlgorithm::Proc_SaveModel() {
	CString strSection;
	strSection.Format(_T("Grab_%02d"), m_PLC.GetCurrent_Vision());

	CString strFile;
	strFile.Format(_T("d:\\Model\\Model%02d_%02d.ini"), m_PLC.GetCurrent_Model(), m_PLC.GetCurrent_Item());
	CMNVFile::CreatePath(strFile);

	Cmd_SaveCamSetting(strFile, strSection);

	Cmd_SaveLight(strFile, strSection);
}

void CMNVAlgorithm::ProcWait() {
	// 준비 신호 대기
	// 준비 신호가 오면 모델 번호등을 확인 한다.
	static int nItem = 0;
	switch(m_PLC.PLC_GetSignalCode()) {
	case MNVPLC_Signal_Ready:
		{	/// Model 및 검사항목 확인}
			//Sleep(100);
			nItem = (nItem >= 3) ? 1 : (nItem + 1);
			if (!m_PLC.SetCurrentModel(m_PLC.GetRequest_Model(), m_PLC.GetRequest_Item())) {
				//AfxMessageBox(_T("검사항목 코드 오류"));
				State_SetALARM();
				//Vision_SetAlarm();
				return;
			}
			CString strFile;
			strFile.Format(_T("d:\\Model\\Model%02d_%02d.ini"), m_PLC.GetCurrent_Model(), m_PLC.GetCurrent_Item());
			CMNVFile::CreatePath(strFile);
			m_maxVision = CMNVIni::GetValue(_T("Grab"), _T("Count"), 1, strFile);
			m_msDelay = CMNVIni::GetValue(_T("Grab"), _T("Delay"), 0, strFile);
		}

		if (m_maxVision < 1) {
			State_SetALARM();
			//Vision_SetAlarm();
		}
		else State_SetPREPARE();
		break;
	case MNVPLC_Signal_Finish:
		{
			m_isChangeProd = true;
			int nCount = 0;
			for(int nIndex = 0; nIndex < 10; ++nIndex) {
				nCount += ((m_stResult[nIndex].m_nResult == MNVIR_NG) ? 1 : 0);
			}
			State_SetFINISH(nCount == 0);
		}
		break;
	case MNVPLC_Signal_End:
		State_SetSTART();
		break;
	}
}
void CMNVAlgorithm::ProcPrepare() {
	// 모델 / 검사항목의 설정값 불러오기
	CMNVLogFile Log(_T("CMNVAlgorithm"), _T("ProcPrepare"), _T("D:\\Log"), _T("MNVision.txt"));
	if (m_isChangeProd) {
		for(int nIndex = 0; nIndex < 10; ++nIndex)
			m_stResult[nIndex].m_nResult = MNVIR_NOR;
		m_isChangeProd = false;
	}
	if(Proc_LoadModel(m_PLC.GetCurrent_Model(), m_PLC.GetCurrent_Item(), 1)) {

		State_SetREADY();
	}
	else {
		AfxMessageBox(_T("Error!! : Load Model"));
		State_SetALARM();
	}
}
void CMNVAlgorithm::ProcReady()
{
	switch(m_PLC.PLC_GetSignalCode()) {
	case MNVPLC_Signal_Trigger:
		if (m_msDelay > 0) Sleep(m_msDelay);
		State_SetTRIGGER();
		break;
	case MNVPLC_Signal_End:
		State_SetSTART();
		break;
	}
	//m_pCamInfo[m_nChannel - 1].GetBuffer(m_Result[m_PLC.GetCurrent_Vision() - 1].m_imgSource);
	//m_Result[m_PLC.GetCurrent_Vision() - 1].m_nState = 1;
}
void CMNVAlgorithm::ProcTrigger()
{
	if (m_PLC.GetCurrent_Vision() <= m_maxVision) {
		Proc_LoadModel(m_PLC.GetCurrent_Model(), m_PLC.GetCurrent_Item(), m_PLC.GetCurrent_Vision());
		//Sleep(50);
		if (m_stSetting.msDelay > 0) Sleep(m_stSetting.msDelay);
		m_pCamInfo[m_nChannel - 1].Grab(m_imgRaw[m_PLC.GetCurrent_Vision()]);
		//m_imgRaw[m_PLC.GetCurrent_Vision() - 1].m_nState = 1;
		m_PLC.SetCurrent_Vision(m_PLC.GetCurrent_Vision() + 1);
		//m_Result[m_PLC.GetCurrent_Vision() - 1].m_nState = 0;
	}
	else {
		m_PLC.SetCurrent_Vision(m_PLC.GetCurrent_Vision() - 1);
		Light_Off();
		State_SetINSPECT();
	}
}
void CMNVAlgorithm::ProcRun() {
	static int __nID = 0;
	__nID = (__nID + 1) & 0xfff;
	CMNVLogFile Log(_T("CMNVAlgorithm"), _T("ProcRun"), _T("D:\\Log"), _T("MNVision.txt"));
	int nItem = m_PLC.GetCurrent_Item();
	CString strTemp;
	strTemp.Format(_T("Insepct %02d"), nItem);
		
	m_stResult[nItem - 1].m_sgcResult.Create();

	m_imgRaw[0].Release();
	switch(m_Model.m_cdType) {
	case MNV_AT_AffineCaliper:
		{
			MNVIP_TwoImageMinMax ImageProc;
			ImageProc.Excute(m_imgRaw[1], m_imgRaw[2], m_imgRaw[0], false, 0, 0);
			m_imgRaw[0].Copy(m_stResult[nItem - 1].m_imgSource);
		}	break;
	default:
		m_imgRaw[1].Copy(m_stResult[nItem - 1].m_imgSource);
		break;
	}


	
	m_stResult[nItem - 1].m_sgcResult.AddLabel(
		m_stResult[nItem - 1].m_imgSource.GetWidth() -  10, 10, 2, 100
		, strTemp, cogColorCyan, cogColorNone, cogGraphicLabelAlignmentTopRight);
	
	if (m_Model.Excute(nItem, m_stResult[nItem - 1].m_imgSource, m_stResult[nItem - 1].m_sgcResult)) {
		m_stResult[nItem - 1].m_nResult = m_Model.m_Result;
		//AfxMessageBox(_T("Pattern OK"));
	}
	else {
		m_stResult[nItem - 1].m_nResult = MNVIR_NG;
		//AfxMessageBox(_T("Pattern NG"));
	}
	m_stResult[nItem - 1].m_ID.SetID(m_PLC.GetCurrent_Model(), m_PLC.GetCurrent_Item(), m_PLC.GetCurrent_Vision(), m_nChannel, __nID);
	//m_stResult[nItem - 1].m_sgcResult.AddLabel(
	//	m_stResult[nItem - 1].m_imgSource.GetWidth() -  10, 10, 2, 100
	//	, strTemp, cogColorCyan, cogColorNone, cogGraphicLabelAlignmentTopRight);
	State_SetRESULT();
}
void CMNVAlgorithm::ProcResult()
{
	SYSTEMTIME stSysTime;
	CString strFilePath;
	CMNVImageFile ImgFile;
	GetLocalTime(&stSysTime);
	int nIndex = (m_Model.m_cdType == 3 || m_Model.m_cdType == 5) ? 0 : 1;
	for(; nIndex <= m_maxVision; ++ nIndex) {
		if (m_imgRaw[nIndex] != NULL) {
			strFilePath.Format(_T("D:\\ImageFile\\Raw\\%04d.%02d.%02d\\%02d%02d%02d.%03d_Model%02d-%02d(%02d).jpg")
				, stSysTime.wYear, stSysTime.wMonth, stSysTime.wDay
				, stSysTime.wHour, stSysTime.wMinute, stSysTime.wSecond,stSysTime.wMilliseconds
				, m_PLC.GetCurrent_Model(), m_PLC.GetCurrent_Item(), nIndex);
			ImgFile.SaveCogImage(strFilePath, m_imgRaw[nIndex]);
		}
	}
	State_SetWAIT();
	//State_SetFINISH(true);
}
void CMNVAlgorithm::ProcFinish()
{
	switch(m_PLC.PLC_GetSignalCode()) {
	case MNVPLC_Signal_End:
		State_SetEND();
		break;
	}
}
void CMNVAlgorithm::ProcAlarm() {
	if (m_PLC.PLC_GetSignalCode() == MNVPLC_Signal_End) {
		State_SetSTART();
	}
}
int CMNVAlgorithm::Algorithm_Result(int __nIndex, CMNVImage & __imgBuffer, CMNVStaticGraphicCollection &__sgcResult, int __nID)
{
	if (m_stResult[__nIndex].m_ID == __nID) return 0;
	if (0 <= __nIndex && __nIndex <=10) {
		switch(m_stResult[__nIndex].m_nResult) {
		case MNVIR_OK:	// NG
			m_stResult[__nIndex].m_imgSource.Copy(__imgBuffer);
			//__sgcResult.Release();
			__sgcResult.Release();
			m_stResult[__nIndex].m_sgcResult.CopyTo(&__sgcResult);
			__sgcResult.AddLabel(10, __imgBuffer.GetHeight() - 50, 2, 100, _T("OK"), cogColorGreen, cogColorNone, cogGraphicLabelAlignmentTopLeft);
			return m_stResult[__nIndex].m_ID;
		case MNVIR_NG:		// OK
			m_stResult[__nIndex].m_imgSource.Copy(__imgBuffer);
			//m_Model.GetResult(__sgcResult);
			__sgcResult.Release();
			m_stResult[__nIndex].m_sgcResult.CopyTo(&__sgcResult);
			__sgcResult.AddLabel(10, __imgBuffer.GetHeight() - 50, 2, 100, _T("NG"), cogColorRed, cogColorNone, cogGraphicLabelAlignmentTopLeft);
			return m_stResult[__nIndex].m_ID;
		case MNVIR_PASS:		// OK
			m_stResult[__nIndex].m_imgSource.Copy(__imgBuffer);
			//m_Model.GetResult(__sgcResult);
			__sgcResult.Release();
			m_stResult[__nIndex].m_sgcResult.CopyTo(&__sgcResult);
			__sgcResult.AddLabel(10, __imgBuffer.GetHeight() - 50, 2, 100, _T("PASS"), cogColorYellow, cogColorNone, cogGraphicLabelAlignmentTopLeft);
			return m_stResult[__nIndex].m_ID;
		default:
			return 0;
		}
	}
	else return 0;
}
int CMNVAlgorithm::Algorithm_Result(CMNVImage & __imgBuffer, CMNVStaticGraphicCollection &__sgcResult, int __nID)
{
	// SourceID
	int __nIndex = m_PLC.GetCurrent_Item() - 1;
	bool isGrab = false;
	while (!isGrab) {
		if (0 <= __nIndex && __nIndex <=10) {
			switch(m_stResult[__nIndex].m_nResult) {
			case MNVIR_OK:	// NG
				if (m_stResult[__nIndex].m_ID == __nID) return 0;
				m_stResult[__nIndex].m_imgSource.Copy(__imgBuffer);
				//__sgcResult.Release();
				__sgcResult.Release();
				m_stResult[__nIndex].m_sgcResult.CopyTo(&__sgcResult);
				__sgcResult.AddLabel(10, __imgBuffer.GetHeight() - 50, 2, 100, _T("OK"), cogColorGreen, cogColorNone, cogGraphicLabelAlignmentTopLeft);
				return m_stResult[__nIndex].m_ID;
			case MNVIR_NG:		// OK
				if (m_stResult[__nIndex].m_ID == __nID) return 0;
				m_stResult[__nIndex].m_imgSource.Copy(__imgBuffer);
				//m_Model.GetResult(__sgcResult);
				__sgcResult.Release();
				m_stResult[__nIndex].m_sgcResult.CopyTo(&__sgcResult);
				if (__sgcResult != NULL) __sgcResult.AddLabel(10, __imgBuffer.GetHeight() - 50, 2, 100, _T("NG"), cogColorRed, cogColorNone, cogGraphicLabelAlignmentTopLeft);
				return m_stResult[__nIndex].m_ID;
			case MNVIR_PASS:		// OK
				if (m_stResult[__nIndex].m_ID == __nID) return 0;
				m_stResult[__nIndex].m_imgSource.Copy(__imgBuffer);
				//m_Model.GetResult(__sgcResult);
				__sgcResult.Release();
				m_stResult[__nIndex].m_sgcResult.CopyTo(&__sgcResult);
				__sgcResult.AddLabel(10, __imgBuffer.GetHeight() - 50, 2, 100, _T("PASS"), cogColorYellow, cogColorNone, cogGraphicLabelAlignmentTopLeft);
				return m_stResult[__nIndex].m_ID;
			default:
				break;
			}
		}
		else return 0;
		__nIndex -= 1;
	}
	return 0;
}
