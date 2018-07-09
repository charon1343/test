#pragma once
#include "Define_Cog.h"
//#include "MNVLock.h"
#include "MNVEvent.h"
#include "MNVObject.h"
#include "MNVImage.h"
#include "MNVIni.h"

#include "MNVDisplay.h"

struct STCamSetting {
	double dContrast;
	double dExposure;
	double dBrightness;
	int		msDelay;

	bool isCheck() {
		if (dContrast < 0 || 1 < dContrast) return false;
		if (dBrightness < 0 || 1 < dBrightness) return false;
		if (dExposure <= 0 || 100 < dExposure) return false;
		return true;
	}
};

struct STCAMINFO {
	double dBrightness;
	double dContrast;
	double dExposureTime;

	int nSampleSize;
	double dResolutionX;
	double dResolutionY;
	double dRateX;
	double dRateY;

	void IniData() {
		dBrightness = 0;
		dContrast = 0;
		dExposureTime = 100;
		dRateX = 1;
		dRateY = 1;
		nSampleSize = 10000;
		dResolutionX = 1;
		dResolutionY = 1;
	}
	void LoadData(LPCTSTR __strDir, LPCTSTR __strFile, LPCTSTR __strSection) {
		CString strFilePath = _T("");
		strFilePath.Format(_T("%s\\%s"), __strDir, __strFile);
		dBrightness = CMNVIni::GetValue(__strSection, _T("dBrightness"), (double)0, strFilePath);
		dContrast = CMNVIni::GetValue(__strSection, _T("dContrast"), (double)0, strFilePath);
		dExposureTime = CMNVIni::GetValue(__strSection, _T("dExposureTime"), (double)50, strFilePath);
		dRateX = CMNVIni::GetValue(__strSection, _T("dRateX"), (double)1, strFilePath);
		dRateY = CMNVIni::GetValue(__strSection, _T("dRateY"), (double)1, strFilePath);
		dResolutionX = CMNVIni::GetValue(__strSection, _T("dResolutionX"), (double)1, strFilePath);
		dResolutionY = CMNVIni::GetValue(__strSection, _T("dResolutionY"), (double)1, strFilePath);
	}
	void SaveData(LPCTSTR __strDir, LPCTSTR __strFile, LPCTSTR __strSection) {
		CString strFilePath = _T("");
		//CMNVIni::GetCurrentDir
		strFilePath.Format(_T("%s\\%s"), __strDir, __strFile);
		CMNVIni::SetValue(__strSection, _T("dBrightness"), dBrightness, strFilePath);
		CMNVIni::SetValue(__strSection, _T("dContrast"), dContrast, strFilePath);
		CMNVIni::SetValue(__strSection, _T("dExposureTime"), dExposureTime, strFilePath);
		CMNVIni::SetValue(__strSection, _T("dRateX"), dRateX, strFilePath);
		CMNVIni::SetValue(__strSection, _T("dRateY"), dRateY, strFilePath);
		CMNVIni::SetValue(__strSection, _T("dResolutionX"), dResolutionX, strFilePath);
		CMNVIni::SetValue(__strSection, _T("dResolutionY"), dResolutionY, strFilePath);
	}
};

class CMNVFlipRotate : public CComPtr<ICogIPOneImageFlipRotate> {
public:
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogIPOneImageFlipRotate>::Release();
	}
	CMNVFlipRotate() : CComPtr<ICogIPOneImageFlipRotate>() {}
	~CMNVFlipRotate() { Release(); }
	void Create() { CoCreateInstance(CLSID_CogIPOneImageFlipRotate); }
};

typedef HRESULT (CALLBACK *CAM_GRAB_CALLBACK)(PVOID pContext, ICogImage *pImage);


class CCogDisplayEventHandler;
//class CMCarBodyInspectionAlgorithm;//PIJ 20160212
struct tagParameter;

class CCamInfo;
struct tagFindData
{
	tagParameter *m_pParameter;
	CCamInfo *m_pCamInfo;
};

#define MNVFRM_NONE				cogIPOneImageFlipRotateOperationNone
#define MNVFRM_ROTATE90			cogIPOneImageFlipRotateOperationRotate90Deg
#define MNVFRM_ROTATE180		cogIPOneImageFlipRotateOperationRotate180Deg
#define MNVFRM_ROTATE270		cogIPOneImageFlipRotateOperationRotate270Deg
#define MNVFRM_FLIP				cogIPOneImageFlipRotateOperationFlip
#define MNVFRM_FLIPnROTATE90	cogIPOneImageFlipRotateOperationFlipAndRotate90Deg
#define MNVFRM_FLIPnROTATE180	cogIPOneImageFlipRotateOperationFlipAndRotate180Deg
#define MNVFRM_FLIPnROTATE270	cogIPOneImageFlipRotateOperationFlipAndRotate270Deg

#define MNVTMS_MSEC	1000
#define MNVTMS_SEC	60000
#define MNVTMS_MIN	3600000
#define MNVTMS_HOUR	86400000

#define MNVTSEC_MSEC	1
#define MNVTSEC_SEC		60
#define MNVTSEC_MIN		3600
#define MNVTSEC_HOUR	86400

enum CAMSETTING_FILED { CAMS_Brightness = 1, CAMS_Contrast, CAMS_Exposure, CAMS_ExposureMul };

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class CMNVFrameGrabber : public CComPtr<ICogFrameGrabber> {
public:
	CMNVFrameGrabber() { }
	~CMNVFrameGrabber() { Release(); }
	void Release() {
		if (p != NULL) {
			p->Disconnect(VARIANT_TRUE);
			Detach()->Release();
		}
		CComPtr::Release();
	}
	bool Create() { return SUCCEEDED(CoCreateInstance(CLSID_CogFrameGrabber)); }
};
class CMNVFrameGrabbers : public CComPtr<ICogFrameGrabbers> {
public:
	CMNVFrameGrabbers(bool __isCreate = true) { if (__isCreate) Create(); }
	~CMNVFrameGrabbers() { Release(); }
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr::Release();
	}
	bool Create() { return SUCCEEDED(CoCreateInstance(CLSID_CogFrameGrabbers)); }
	long GetCount() {
		long Result = -1;
		if ( NULL != p && SUCCEEDED(p->get_Count(&Result)) )
			return Result;
		else return -1;
	}
	bool GetFrameGrabber(int __nIndex, CMNVFrameGrabber & __FrameGrabber) {
		__FrameGrabber.Release();
		if (p == NULL) return false;
		return SUCCEEDED(p->get_Item(__nIndex, &__FrameGrabber));
	}
};

class CMNVAcqFifo;
class CMNVAcqExposure : public CComQIPtr<ICogAcqExposure> {
public:
	CMNVAcqExposure() { }
	CMNVAcqExposure(ICogAcqFifo * __pPAcqFifo) : CComQIPtr<ICogAcqExposure>(__pPAcqFifo) {  }
	~CMNVAcqExposure() { } //Release(); }
	void Release() {
		if ( p != NULL ) Detach()->Release();
		CComPtr::Release();
	}
	bool Create() { return SUCCEEDED( CoCreateInstance(CLSID_CogAcqExposure) ); }
};
class CMNVAcqContrast : public CComQIPtr<ICogAcqContrast> {
public:
	CMNVAcqContrast() { }
	CMNVAcqContrast(ICogAcqFifo * __pPAcqFifo) : CComQIPtr<ICogAcqContrast>(__pPAcqFifo) { }
	~CMNVAcqContrast() { } //Release(); }
	void Release() {
		if ( p != NULL ) Detach()->Release();
		CComPtr::Release();
	}
	bool Create() { return SUCCEEDED( CoCreateInstance(CLSID_CogAcqContrast) ); }
};
class CMNVAcqBrightness : public CComQIPtr<ICogAcqBrightness> {
public:
	CMNVAcqBrightness() { }
	CMNVAcqBrightness(ICogAcqFifo * __pPAcqFifo) : CComQIPtr<ICogAcqBrightness> (__pPAcqFifo) { }
	~CMNVAcqBrightness() { } //Release(); }
	void Release() {
		if ( p != NULL ) Detach()->Release();
		CComPtr::Release();
	}
	bool Create() { return SUCCEEDED( CoCreateInstance(CLSID_CogAcqBrightness) ); }
};
class CMNVAcqROI : public CComQIPtr<ICogAcqROI> {
public:
	CMNVAcqROI() { }
	CMNVAcqROI(ICogAcqFifo * __pPAcqFifo) : CComQIPtr<ICogAcqROI>(__pPAcqFifo) { }
	~CMNVAcqROI() { Release(); }
	void Release() {
		if ( p != NULL ) Detach()->Release();
		CComPtr::Release();
	}
	bool Create() { return SUCCEEDED( CoCreateInstance(CLSID_CogAcqROI) ); }
};
class CMNVAcqFifo : public CComPtr<ICogAcqFifo> {
	MNVLock m_Lock;
public:
	CMNVAcqFifo() { p = NULL; }
	~CMNVAcqFifo() { Release(); }
	void Release() {
		if ( p != NULL ) Detach()->Release();
		CComPtr::Release();
	}
	bool Create() { return SUCCEEDED( CoCreateInstance(CLSID_CogAcqFifo) ); }

	bool SetContrast(double __dContrast) {
		CMNVLock Lock(&m_Lock, MNVLM_Write);
		if (p == NULL) return false;
		CMNVAcqContrast AcqContrast(p);
		return SUCCEEDED( AcqContrast->put_Contrast(__dContrast) );
	}
	bool SetExposure(double __dExposure) {
		CMNVLock Lock(&m_Lock, MNVLM_Write);
		if (p == NULL) return false;
		CMNVAcqExposure AcqExposure(p);
		return SUCCEEDED( AcqExposure->put_Exposure(__dExposure) );
	}
	bool SetBrightness(double __dBrightness) {
		CMNVLock Lock(&m_Lock, MNVLM_Write);
		if (p == NULL) return false;
		CMNVAcqBrightness AcqBrightness(p);
		return SUCCEEDED( AcqBrightness->put_Brightness(__dBrightness) );
	}
	bool GetContrast(double & __dContrast) {
		CMNVLock Lock(&m_Lock, MNVLM_Read);
		if (p == NULL) return false;
		CMNVAcqContrast AcqContrast(p);
		return SUCCEEDED( AcqContrast->get_Contrast(&__dContrast) );
	}
	bool GetExposure(double & __dExposure) {
		CMNVLock Lock(&m_Lock, MNVLM_Read);
		if (p == NULL) return false;
		CMNVAcqExposure AcqExposure(p);
		return SUCCEEDED( AcqExposure->get_Exposure(&__dExposure) );
	}
	bool GetBrightness(double & __dBrightness) {
		CMNVLock Lock(&m_Lock, MNVLM_Read);
		if (p == NULL) return false;
		CMNVAcqBrightness AcqBrightness(p);
		return SUCCEEDED( AcqBrightness->get_Brightness(& __dBrightness) );
	}
	bool GetROI(long & __lWidth, long & __lHeight) {
		CMNVLock Lock(&m_Lock, MNVLM_Read);
		if (p == NULL) return false;
		CMNVAcqROI AcqROI(p);
		long x, y;
		return SUCCEEDED( AcqROI->GetROIXYWidthHeight(&x, &y, &__lWidth, &__lHeight) );
	}

	bool GrabImage(CMNVImage & __Image) {
		CMNVLock LockGrab(&m_Lock, MNVLM_Write);
		if (p == NULL) return false;

		long lTriggerNumber = 0;
		CMNVImage pLocalImage(false);
		HRESULT hResult = E_FAIL;

		if (SUCCEEDED(p->Acquire(&lTriggerNumber, &pLocalImage))) {
			CMNVLock LockBuffer((MNVLock *)__Image, MNVLM_Write);
			__Image.Release();
			while (FAILED(hResult)) 
				hResult = pLocalImage->CopyBase(cogImageCopyModeCopyPixels, &__Image);
			__Image->put_SelectedSpaceName(CComBSTR("#"));
			return true;
		}
		else {
			return false;
		}
	}
	bool GrabImage(CMNVImage8Grey & __Image) {
		CMNVLock LockGrab(&m_Lock, MNVLM_Write);
		if (p == NULL) return false;

		long lTriggerNumber = 0;
		CMNVImage pLocalImage(false);
		HRESULT hResult = E_FAIL;

		if (SUCCEEDED(p->Acquire(&lTriggerNumber, &pLocalImage))) {
			__Image.Release();
			return FAILED(pLocalImage.Copy(__Image));
		}
		else {
			return false;
		}
	}

};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "..\MFC\MNVDevice.h"
class CCamInfo : public CMNVDevice
{
	//friend class CMCarBodyInspectionAlgorithm;
public:
	bool isContinue;
	bool isThreadRun;
	CCamInfo();
	~CCamInfo();
protected:	// Image Grap
	MNVLock				m_LockGrap;
	CMNVFrameGrabber	m_FrameGrabber;
	CMNVAcqFifo			m_AcqFifo;
	//CString m_strName;
	long lRequestTicket;
	CMNV_STPoint	m_ImgSize;
	long m_nWidth, m_nHeight;
	int m_nInterval;

	bool m_isDummy;
public:
	bool Proc_OpenFile(LPCTSTR __strDir, LPCTSTR __strFile) {
		wchar_t Path[1024];
		wsprintf(Path, _T("%s\\%s"), __strDir, __strFile);
		GrabStop();
		CMNVImageFile ImgFile;
		return ImgFile.LoadCogImage(Path, m_FrameBuffer);
	}
	bool Proc_OpenFile(LPCTSTR __strFile) {
		GrabStop();
		CMNVImageFile ImgFile;
		return ImgFile.LoadCogImage(__strFile, m_FrameBuffer);
	}
	bool Proc_OpenFile() {
		CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
			_T("Image File (*.bmp;*.jpg;*.gif;*.png)|*.bmp;*.jpg;*.gif;*.png;|"));
		if (dlg.DoModal() == IDOK) {
			return Proc_OpenFile(dlg.GetPathName());
		}
		return false;
	}
	void Proc_SaveFile() {
		CFileDialog dlg(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
			_T("Bitmap Image (*.bmp)|*.bmp;|JPG Image(*.jpg)|*.jpg;|"));
		if (dlg.DoModal() == IDOK) {
		}
	}
			
	//void SetName(LPCTSTR __lpName) { m_strName = __lpName; }
	STCAMINFO m_stCamInfo;
	void LoadCamInfo(LPCTSTR __strDir, LPCTSTR __strFile, LPCTSTR __strSection) {
		m_stCamInfo.LoadData(__strDir, __strFile, __strSection);
		SetExposure();
		SetBrightness();
		SetContrast();
	}
	void SaveCamInfo(LPCTSTR __strDir, LPCTSTR __strFile, LPCTSTR __strSection) {
		m_stCamInfo.SaveData(__strDir, __strFile, __strSection);
	}
protected:	// Camera Setting
	//struct {	// 카메라 설정 값
	//	double dVersion;			// version
	//	CString strFrameGrabber;	// Frame Grabber Name
	//	CString strVideoFormat;		// Video Format Name
	//	double dExposure;			// 노출 시간
	//	double dBrightness;			// 이미지 밝기
	//	double dContrast;			// 대비
	//	double dExposureMul;		// exposure 상수(노출 시간 환산 상수)

	//	CMNV_STPoint	Resolution;	// 카메라 분해능 (픽셀당 거리)
	//	CogIPOneImageFlipRotateOperationConstants cdFlipRotate;
	//} m_stSetting;
public:
	//void SetLockGrap(MNVLock * __pLock) { m_pLockGrap = __pLock; }
	void LoadIni(LPCTSTR __strDir, LPCTSTR __strFile, LPCTSTR __strSection);
	void SaveIni(LPCTSTR __strDir, LPCTSTR __strFile, LPCTSTR __strSection);

	//double GetVersion() { return m_stSetting.dVersion; }
	//CString &GetFrameGrabber() { return m_stSetting.strFrameGrabber; }
	//CString &GetVideoFormat() { return m_stSetting.strVideoFormat; }

	double GetResolutionX() { return m_stCamInfo.dResolutionX; }
	double GetResolutionY() { return m_stCamInfo.dResolutionX; }
	void GetResolution(CMNV_STPoint & __STPoint) { __STPoint.Set(m_stCamInfo.dResolutionX, m_stCamInfo.dResolutionY); }
	//int GetRotation() { return m_stSetting.cdFlipRotate & 0x0003; }
	//int GetFlip() { return (m_stSetting.cdFlipRotate >> 2) & 0x0001; }
	//CogIPOneImageFlipRotateOperationConstants GetFlipRotate() { return m_stSetting.cdFlipRotate; }

	//bool SetVersion(double __dVersion) { m_stSetting.dVersion = __dVersion; return true;}
	//bool SetFrameGrabber(CString __strFrameGrabber) { m_stSetting.strFrameGrabber = __strFrameGrabber; return true;}
	//bool SetVideoFormat(CString __strVideoFormat) { m_stSetting.strVideoFormat = __strVideoFormat; return true; }

	bool SetCamSetting(const STCamSetting & __stCamSetting);
	bool SetExposure(double dExposure = -1);
	bool SetBrightness(double dBrightness = -1);
	bool SetContrast(double dContrast = -1);

	bool GetCamSetting(STCamSetting & __stCamSetting);
	double GetExposure();
	double GetBrightness();
	double GetContrast();

	bool SetResolution(CMNV_STPoint __Val)
	{
		m_stCamInfo.dResolutionX = __Val.m_dX;
		m_stCamInfo.dResolutionY = __Val.m_dY;
		return true;
	}
	bool SetResolution(double __dResolutionX, double __dResolutionY)
	{
		m_stCamInfo.dResolutionX = __dResolutionX;
		m_stCamInfo.dResolutionY = __dResolutionY;
		return true;
	}
	//bool SetFlipRotate(int nFlip, int nRotation);
	//bool SetFlipRotate(int __cdFlipRotate);
	//bool SetFlipRotate(CogIPOneImageFlipRotateOperationConstants __cdFlipRotate);
	//bool SetFlipRotate();

protected:	// ImageBuffer
	CMNVImage m_FrameBuffer;
public:	
	bool GetBuffer(CMNVImage & __pImage, int __nRetry = 1, int __nInterval = 0) {
		//if (m_isDummy) return false;
		if (m_AcqFifo == NULL) {
			if (m_FrameBuffer != NULL && m_FrameBuffer.Copy(__pImage)) return true;
			return false;
		}
		else {
			for(int nIndex = 0; nIndex < __nRetry; ++nIndex) {
				if (m_FrameBuffer != NULL && m_FrameBuffer.Copy(__pImage)) return true;
				Sleep(__nInterval);
			}
			return false;
		}
	}

	bool GetBuffer(CMNVImage8Grey & __pImage, int __nRetry = 1, int __nInterval = 0) {
		if (m_FrameBuffer == NULL) return false;
		return m_FrameBuffer.Copy(__pImage, __nRetry, __nInterval); 
	}
	bool GetBuffer(CogImagePlaneConstants __nImagePlane, CMNVImage8Grey & __pImage, int __nRetry = 1, int __nInterval = 0) {
		if (m_FrameBuffer == NULL) return false;
		return m_FrameBuffer.GetPlane(__nImagePlane, __pImage, __nRetry, __nInterval);
	}

	bool GetBuffer(CMNVImage24Color & __pImage, int __nRetry = 1, int __nInterval = 0) {
		if (m_FrameBuffer == NULL) return false;
		return m_FrameBuffer.Copy(__pImage, __nRetry, __nInterval);
	}

protected:	// Live Grab Thread
	CMNVEvent m_EventGrab;
public:	
	UINT ProcFrameLive();
	void Grab() { m_AcqFifo.GrabImage(m_FrameBuffer); }
	bool Grab(CMNVImage & __ImgGrap) {
		bool isResult = false;
		if (m_isDummy) {
			ImageLoad(__ImgGrap);
			isResult = true;
		}
		else if (m_AcqFifo == NULL)  {
			m_FrameBuffer.Copy(__ImgGrap);
			isResult = false;
		}
		else {
			//GrabStop();
			isResult = m_AcqFifo.GrabImage(__ImgGrap);
			//GrabStart();
		}
		return isResult;
	}
	bool Grab(CMNVImage8Grey & __ImgGrap) {
		bool isResult = false;
		if (m_AcqFifo == NULL) {
			m_FrameBuffer.Copy(__ImgGrap);
			isResult = false;
		}
		else {
			//GrabStop();
			isResult = m_AcqFifo.GrabImage(__ImgGrap);
			//GrabStart();
		}
		return isResult;
	}
	//void CreateThread() { 
	//	unsigned int threadid;
	//	_beginthreadex(NULL, 0, CCamInfo::BeginThread, this, 0, &threadid);
	//	//AfxBeginThread(CCamInfo::Thread, this);
	//}
	//void EndThread() {
	//	//while (isThreadRun) {
	//		isContinue = false;
	//		m_EventGrab.SetBreak();
	//		m_AcqFifo.Release();
	//		//m_EventGrab.SetEvent();
	//	//}
	//}

	//unsigned long WINAPI Thread_Sync(void * __pParm)
	virtual void Thread() {
	//static UINT __cdecl BeginThread(LPVOID __pParm)
	//{
		HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);// COINIT_APARTMENTTHREADED);
		ProcFrameLive();
		//CCamInfo *pParam = reinterpret_cast<CCamInfo *>(__pParm);
		//pParam->ProcFrameLive();
		//if (hr != RPC_E_CHANGED_MODE) CoUninitialize();
		//_endthreadex(0);
		//return 0;
	}
protected:
	CMNVFlipRotate m_pImageFlipRotate;

public:
	void operator = (double __dValue) {}
	bool Init(LPCTSTR __lpstrName, ICogFrameGrabber *pFrameGrabber = NULL, bool __isLive = false);
	void Release();

	bool GrabStart(bool __isReset = false) {
		if (m_isDummy) return true;
		return m_EventGrab.SetEvent(__isReset) == TRUE; 
	}
	bool GrabStop() {
		if (m_isDummy) return true;
		return m_EventGrab.ResetEvent();
	}
	bool GrabEnd() { m_EventGrab.SetBreak(); return m_EventGrab.SetEvent(); }
	int GetWidth() { return m_nWidth; }
	int GetHeight() { return m_nHeight; }
	bool GetFrameSize(long & __nWidth, long & __nHeight) {
		if (m_AcqFifo != NULL) {
			return m_AcqFifo.GetROI(__nWidth, __nHeight);
		}
		return false;
	}
protected:
	CAM_GRAB_CALLBACK m_pGrabCallback;
	PVOID m_pContext;

	bool m_bFinding, m_bFindingResult,m_bWindowClear;
	tagFindData m_FindData;

public:
	void ImageLoad(CMNVImage & __Image, LPCTSTR __lpFilePath = NULL) { 
		if (__lpFilePath == NULL) {
			CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,_T("Image File (*.bmp;*.jpg;*.gif;*.png)|*.bmp;*.jpg;*.gif;*.png;|"));
			if(dlg.DoModal()==IDOK)
			{
				__Image.Release();
				CMNVImageFile ImgFile;
				ImgFile.LoadCogImage(dlg.GetPathName(), __Image);
			}
		}
		else {
			__Image.Release();
			CMNVImageFile ImgFile;
			ImgFile.LoadCogImage(__lpFilePath, __Image);
		}
	}
	void ImageLoad(LPCTSTR __lpFilePath = NULL) { 
		CMNVImage __Image;
		if (__lpFilePath == NULL) {
			CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,_T("Image File (*.bmp;*.jpg;*.gif;*.png)|*.bmp;*.jpg;*.gif;*.png;|"));
			if(dlg.DoModal()==IDOK)
			{
				__Image.Release();
				CMNVImageFile ImgFile;
				if (ImgFile.LoadCogImage(dlg.GetPathName(), __Image)) {
					m_FrameBuffer.Release();
					__Image.Copy(m_FrameBuffer);
				}
			}
		}
		else {
			__Image.Release();
			CMNVImageFile ImgFile;
			if ( ImgFile.LoadCogImage(__lpFilePath, __Image) ) {
				m_FrameBuffer.Release();
				__Image.Copy(m_FrameBuffer);
			}
		}

//	CMNVLock Lock((MNVLock*)m_FrameBuffer, MNVLM_Write);

	}
	void ImageSave(LPCTSTR __lpFilePath) {
		CMNVLock Lock((MNVLock*)m_FrameBuffer, MNVLM_Read);
		CMNVImageFile ImgFile;
		ImgFile.SaveCogImage(__lpFilePath, m_FrameBuffer);
	}
	//bool LiveOn(CMNVDisplay & __cogDisplay) {
	//	return __cogDisplay.LiveOn(m_AcqFifo);
	//}
	//bool LiveOff(CMNVDisplay & __cogDisplay) {
	//	return __cogDisplay.LiveOff();
	//}
};

class CMNVCamManager {
	CCamInfo * m_pCamInfo;
	int m_cntCamInfo;
	int * m_pnChannel;
public:
	CMNVCamManager(int __nCnt) {
		m_cntCamInfo = __nCnt;
		m_pCamInfo = new CCamInfo[__nCnt];
		m_pnChannel = new int[__nCnt];
		for(int nIndex = 0; nIndex < __nCnt; ++nIndex)
			m_pnChannel[nIndex] = nIndex;
	}
	void InitCamInfo(int __nIndex, ICogFrameGrabber * __pFrameGrabber = NULL, bool __isLive = true) {
		m_pCamInfo[__nIndex].Init(_T(""), __pFrameGrabber, __isLive);
	}
	CCamInfo * operator[] (int __nIndex) {
		return (m_cntCamInfo > __nIndex) ? &(m_pCamInfo[m_pnChannel[__nIndex]]) : NULL;
	}
};