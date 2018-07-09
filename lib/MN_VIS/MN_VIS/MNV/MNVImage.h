#pragma once
#include "Define_Cog.h"
#include "MNVLock.h"
#include "MNVFile.h"

class ImageProc {
public:
	static HRESULT LoadCogImage(LPCTSTR lpszFilePath, void **pImage) {
		HRESULT hr; 
		CComPtr<ICogImageFile> pImageFile;
		hr = pImageFile.CoCreateInstance(CLSID_CogImageFile);
		if (FAILED(hr))
			return hr;
		hr = pImageFile->Open(CComBSTR(lpszFilePath), cogImageFileModeRead);
		if (FAILED(hr))
			return hr;

		hr = pImageFile->get_Item(0, (ICogImage **)pImage);
		if (FAILED(hr))
			return hr;

		pImageFile->Close();
		return hr;
	}
	static HRESULT SaveCogImage(LPCTSTR lpszFilePath, void **pImage)
	{
		HRESULT hr;
		CComPtr<ICogImageFile> pImageFile;
		hr = pImageFile.CoCreateInstance(CLSID_CogImageFile);
		if (FAILED(hr))
			return hr;

		hr = pImageFile->Open(CComBSTR(CString(lpszFilePath)), cogImageFileModeWrite);
		if (FAILED(hr))
			return hr;

		pImageFile->Append((ICogImage *)pImage);
		pImageFile->Close();
		return hr;
	}
};

class CMNVImageConvert : public CComPtr<ICogImageConvert> {
public:
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogImageConvert>::Release();
	}
	CMNVImageConvert() {}
	~CMNVImageConvert() { Release(); }
	HRESULT Create() { return CoCreateInstance(CLSID_CogImageConvert); }
};

class CMNVImage8Grey : public CComPtr<ICogImage8Grey> {
	//CComPtr<ICogImage8Grey> m_pFrameBuffer;
public:
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogImage8Grey>::Release();
	}
	bool Create() {
		Release();
		return SUCCEEDED( CoCreateInstance(CLSID_CogImage8Grey) );
	}
	bool Create(long __nWidth, long __nHeight) {
		Release();
		if (FAILED( CoCreateInstance(CLSID_CogImage8Grey) )) {
			return false;
		}
		return SUCCEEDED( p->Allocate(__nWidth, __nHeight) );
	}
public:
	CMNVImage8Grey(bool __isCreate = true) : CComPtr<ICogImage8Grey>() { if ( __isCreate ) Create(); }
	~CMNVImage8Grey() { Release(); }
	bool IsAllocated() {
		if (p != NULL) {
			VARIANT_BOOL Val;
			return (SUCCEEDED( p->get_Allocated(&Val) ) && VARIANT_TRUE == Val);
		}
		return false;
	}
	long GetWidth() {
		long nWidth;
		if (SUCCEEDED( p->get_Width(&nWidth) )) return nWidth;
		else return -1;
	}
	long GetHeight() {
		long nHeight;
		if (SUCCEEDED( p->get_Height(&nHeight) )) return nHeight;
		else return -1;
	}
};

class CMNVImage24Color : public CComPtr<ICogImage24PlanarColor> {
	//CComPtr<ICogImage8Grey> m_pFrameBuffer;
public:
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogImage24PlanarColor>::Release();
	}
	CMNVImage24Color() {}
	~CMNVImage24Color() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogImage24PlanarColor>::Release();
	}
	void Create() { CoCreateInstance(CLSID_CogImage24PlanarColor); }
	long GetWidth() {
		long nWidth;
		if (SUCCEEDED( p->get_Width(&nWidth) )) return nWidth;
		else return -1;
	}
	long GetHeight() {
		long nHeight;
		if (SUCCEEDED( p->get_Height(&nHeight) )) return nHeight;
		else return -1;
	}
	bool GetPixel(double __dCenterX, double __dCenterY, double & __dValue1, double & __dValue2, double & __dValue3) {
		double dRate[4];
		{
			double dRateX[2];
			double dRateY[2];
			dRateX[1] = __dCenterX - (int)__dCenterX;
			dRateX[0] = (double)1 - dRateX[1];

			dRateY[1] = __dCenterY - (int)__dCenterY;
			dRateY[0] = (double)1 - dRateY[1];

			dRate[0] = dRateX[0] * dRateY[0];
			dRate[1] = dRateX[1] * dRateY[0];
			dRate[2] = dRateX[0] * dRateY[1];
			dRate[3] = dRateX[1] * dRateY[1];
		}
		unsigned __int8 bVal[4][3];

		if (FAILED( p->GetPixel((int)__dCenterX, (int)__dCenterY, &(bVal[0][0]), &(bVal[0][1]), &(bVal[0][2])) )) return false;
		if (FAILED( p->GetPixel((int)__dCenterX + 1, (int)__dCenterY, &(bVal[1][0]), &(bVal[1][1]), &(bVal[1][2])) )) return false;
		if (FAILED( p->GetPixel((int)__dCenterX, (int)__dCenterY + 1, &(bVal[2][0]), &(bVal[2][1]), &(bVal[2][2])) )) return false;
		if (FAILED( p->GetPixel((int)__dCenterX + 1, (int)__dCenterY + 1, &(bVal[3][0]), &(bVal[3][1]), &(bVal[3][2])) )) return false;

		__dValue1 = dRate[0] * bVal[0][0] + dRate[1] * bVal[1][0] + dRate[2] * bVal[2][0] + dRate[3] * bVal[3][0];
		__dValue2 = dRate[0] * bVal[0][1] + dRate[1] * bVal[1][1] + dRate[2] * bVal[2][1] + dRate[3] * bVal[3][1];
		__dValue3 = dRate[0] * bVal[0][2] + dRate[1] * bVal[1][2] + dRate[2] * bVal[2][2] + dRate[3] * bVal[3][2];
		return true;
	}
	bool GetPixel(double __dCenterX, double __dCenterY, double __dWidth, double & __dValue1, double & __dValue2, double & __dValue3) {
		int Inter = (int)((__dWidth < 5) ? 1 : (__dWidth / 5));
		double Dis = (__dWidth / 2) * (__dWidth / 2);
		int nX = (int)(__dCenterX - __dWidth / 2 + 0.5);
		int nY = (int)(__dCenterY - __dWidth / 2 + 0.5);

		unsigned __int8 V1, V2, V3;
		int nCount = 0;
		__dValue1 = 0;
		__dValue2 = 0;
		__dValue3 = 0;
		for(int iY = 0; iY < (int)__dWidth; iY += Inter) {
			for(int iX = 0; iX < (int)__dWidth; iX += Inter) {
				if ( (((double)iX - (__dWidth / 2)) * ((double)iX - (__dWidth / 2)) + ((double)iY - (__dWidth / 2)) * ((double)iY - (__dWidth / 2))) <= Dis ) {
					p->GetPixel((int)(nX + iX), (int)(nY + iY), &V1, &V2, &V3);
					__dValue1 += (double)V1;
					__dValue2 += (double)V2;
					__dValue3 += (double)V3;
					++nCount;
				}
			}
		}
		if (nCount > 0) {
			__dValue1 /= nCount;
			__dValue2 /= nCount;
			__dValue3 /= nCount;
		}
		return true;
	}
};

class CMNVImage : public CComPtr<ICogImage> {
	MNVLock			m_LockBuffer;
public:
	operator MNVLock *() { return &m_LockBuffer; }
	//MNVLock * GetLock() { return &m_LockBuffer; }
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogImage>::Release();
	}
	CMNVImage(bool __isCreate = true) { if(__isCreate) Create(); }
	~CMNVImage() { Release(); }
	void Create() {
		Release();
		CoCreateInstance(CLSID_CogImage);
	}
	long GetWidth() {
		long nWidth;
		if (p == NULL) return 0;
		if (SUCCEEDED( p->get_Width(&nWidth) ))
		{
			return nWidth;
		}
		else return -1;
	}
	long GetHeight() {
		long nHeight;
		if (p == NULL) return 0;
		if (SUCCEEDED( p->get_Height(&nHeight) )) return nHeight;
		else return -1;
	}
	bool Copy(CMNVImage & __pImage) {
		CMNVLock Lock_Sour(&m_LockBuffer, MNVLM_Read);
		CMNVLock Lock_Dest((MNVLock*)__pImage, MNVLM_Write);
		__pImage.Release();
		if (p != NULL) {
			if (SUCCEEDED(p->CopyBase(cogImageCopyModeCopyPixels, &__pImage))) {
				__pImage->put_SelectedSpaceName(CComBSTR("#"));
				return true;	// 성공하면 바로 리턴을 한다.
			}
			else { }
		}
		else { }
		return false;
	}
	bool Copy(CMNVImage8Grey & __pImage, int __nRetry = 1, int __nInterval = 100) { 
		CMNVImageConvert pImgConvert;
		pImgConvert.Create();
		for(int nCnt = 0; nCnt < __nRetry; ++ nCnt) {
			CMNVLock Lock_Sour(&m_LockBuffer, MNVLM_Read);
			// CMNVLock Lock_Dest((MNVLock*)__pImage, MNVLM_Write);
			__pImage.Release();
			long nWidth = 0;
			long nHeight = 0;
			if (p != NULL) {
				p->get_Width(&nWidth);
				p->get_Height(&nHeight);
				if (SUCCEEDED( pImgConvert->GetIntensityImage(p, 0, 0, nWidth, nHeight, &__pImage) )) {  // <<====
					__pImage->put_SelectedSpaceName(CComBSTR("#"));
					return true;
				}
				else { }
			}
			else { }
			Sleep(__nInterval);
		}
		return false;
	}
	bool Copy(CMNVImage24Color & __pImage, int __nRetry = 1, int __nInterval = 100) { 
		for(int nCnt = 0; nCnt < __nRetry; ++ nCnt) {
			CMNVLock Lock(&m_LockBuffer, MNVLM_Read);
			__pImage.Release();
			if (p != NULL) {
				if (SUCCEEDED( p->QueryInterface(&__pImage) )) {
					__pImage->put_SelectedSpaceName(CComBSTR("#"));
					return true;
				}
				else { }
			}
			else { }
			Sleep(__nInterval);
		}
		return false;
	}

	bool GetPlane(CogImagePlaneConstants __conImagePlane, CMNVImage8Grey & __pImage, int __nRetry = 1, int __nInterval = 100)
	{ 
		CMNVImage24Color Img24Color;
		//Img24Color.Create();

		for(int nCnt = 0; nCnt < __nRetry; ++ nCnt) {
			CMNVLock Lock(&m_LockBuffer, MNVLM_Read);
			__pImage.Release();
			if (p != NULL) {
				if (SUCCEEDED( p->QueryInterface(&Img24Color) )) {
					if (SUCCEEDED( Img24Color->GetPlane(__conImagePlane, &__pImage) )) {
						__pImage->put_SelectedSpaceName(CComBSTR("#"));
						return true;
					}
					else { }
				}
				else { }
			}
			else { }
			Sleep(__nInterval);
		}
		return false;
	}
};

class CMNVImageFile : public CComPtr<ICogImageFile> {
public:
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogImageFile>::Release();
	}
	CMNVImageFile() {
		CComPtr<ICogImageFile>();
		CoCreateInstance(CLSID_CogImageFile);
	}
	~CMNVImageFile() { Release(); }

	bool LoadCogImage(LPCTSTR lpszFilePath, CMNVImage & __rMNVImage) {
		if (p == NULL) return false;
		if (FAILED( p->Open(CComBSTR(lpszFilePath), cogImageFileModeRead) )) return false;
		__rMNVImage.Release();
		if (FAILED( p->get_Item(0, (ICogImage **)&__rMNVImage) )) {
			p->Close();
			return false;
		}
		p->Close();
		return true;
	}
	bool LoadCogImage(LPCTSTR lpszFilePath, CMNVImage8Grey & __rMNVImage) {
		if (p == NULL) return false;
		if (FAILED( p->Open(CComBSTR(lpszFilePath), cogImageFileModeRead) )) return false;
		__rMNVImage.Release();
		if (FAILED( p->get_Item(0, (ICogImage **)&__rMNVImage) )) {
			p->Close();
			return false;
		}
		p->Close();
		return true;
	}
	bool LoadCogImage(LPCTSTR lpszFilePath, CMNVImage24Color & __rMNVImage) {
		if (p == NULL) return false;
		if (FAILED( p->Open(CComBSTR(lpszFilePath), cogImageFileModeRead) )) return false;
		if (FAILED( p->get_Item(0, (ICogImage **)&__rMNVImage) )) {
			p->Close();
			return false;
		}
		p->Close();
		return true;
	}

	bool SaveCogImage(LPCTSTR lpszFilePath, CMNVImage & __rMNVImage)
	{
		CMNVFile::CreatePath(lpszFilePath);
		if (p == NULL) return false;
		if (FAILED( p->Open(CComBSTR(lpszFilePath), cogImageFileModeWrite) )) return false;
		if (FAILED( p->Append((ICogImage *)__rMNVImage) )) {
			p->Close();
			return false;
		}
		p->Close();
		return true;
	}
	bool SaveCogImage(LPCTSTR lpszDir, LPCTSTR lpszFile, CMNVImage & __rMNVImage)
	{
		CString strFilePath = lpszDir;
		CreateDir(strFilePath);
		strFilePath += "\\";
		strFilePath += lpszFile;
		if (p == NULL) return false;
		if (FAILED( p->Open(CComBSTR(strFilePath), cogImageFileModeWrite) )) return false;
		if (FAILED( p->Append((ICogImage *)__rMNVImage) )) {
			p->Close();
			return false;
		}
		p->Close();
		return true;
	}

	bool SaveCogImage(LPCTSTR lpszFilePath, CMNVImage8Grey & __rMNVImage)
	{
		if (p == NULL) return false;
		if (FAILED( p->Open(CComBSTR(lpszFilePath), cogImageFileModeWrite) )) return false;
		if (FAILED( p->Append((ICogImage *)__rMNVImage) )) {
			p->Close();
			return false;
		}
		p->Close();
		return true;
	}
	bool SaveCogImage(LPCTSTR lpszFilePath, CMNVImage24Color & __rMNVImage)
	{
		if (p == NULL) return false;
		if (FAILED( p->Open(CComBSTR(lpszFilePath), cogImageFileModeWrite) )) return false;
		if (FAILED( p->Append((ICogImage *)__rMNVImage) )) {
			p->Close();
			return false;
		}
		p->Close();
		return true;
	}

	void FilePath(CString & __strPath, LPCTSTR __lpszFilePath, LPCTSTR __lpszChannelName, SYSTEMTIME & __sysTime, LPCTSTR __Keyword, LPCTSTR __Result, bool __isDateDir) {
		if (__isDateDir) __strPath.Format(__Keyword, __lpszFilePath, __sysTime.wYear, __sysTime.wMonth, __sysTime.wDay);
		else __strPath.Format(_T("%s"), __lpszFilePath);
		CreateDir(__strPath);
		__strPath.AppendFormat(_T("\\%04d%02d%02d_%02d%02d%02d.%03d_%s_%s.jpg")
			, __sysTime.wYear, __sysTime.wMonth, __sysTime.wDay, __sysTime.wHour, __sysTime.wMinute, __sysTime.wSecond, __sysTime.wMilliseconds, __lpszChannelName, __Result);
		return;
	}
	bool SaveImage(LPCTSTR __lpszFilePath, LPCTSTR __lpszChannelName, SYSTEMTIME & __sysTime, LPCTSTR __Keyword, LPCTSTR __Result, CMNVImage & __rMNVImage, bool __isDateDir = true) {
		CString strPath;
		FilePath(strPath, __lpszFilePath, __lpszChannelName, __sysTime, __Keyword, __Result, __isDateDir);
		return SaveCogImage(strPath, __rMNVImage);
	}
	bool SaveImage(LPCTSTR __lpszFilePath, LPCTSTR __lpszChannelName, SYSTEMTIME & __sysTime, LPCTSTR __Keyword, LPCTSTR __Result, CMNVImage8Grey & __rMNVImage, bool __isDateDir = true) {
		CString strPath;
		FilePath(strPath, __lpszFilePath, __lpszChannelName, __sysTime, __Keyword, __Result, __isDateDir);
		return SaveCogImage(strPath, __rMNVImage);
	}
	bool SaveImage(LPCTSTR __lpszFilePath, LPCTSTR __lpszChannelName, SYSTEMTIME & __sysTime, LPCTSTR __Keyword, LPCTSTR __Result, CMNVImage24Color & __rMNVImage, bool __isDateDir = true) {
		CString strPath;
		FilePath(strPath, __lpszFilePath, __lpszChannelName, __sysTime, __Keyword, __Result, __isDateDir);
		return SaveCogImage(strPath, __rMNVImage);
	}
	static void CreateDir(CString __strPath) {
		__strPath+= _T("\\");
		int nLength = __strPath.Find(':', 0);
		nLength = (nLength < 0) ? 0 : (nLength + 2);
		CString strDir;
		while (nLength >= 0) {
			nLength = __strPath.Find('\\', nLength + 1);
			strDir = __strPath.Left(nLength);
			if (nLength > 0) CreateDirectory(strDir, NULL);
		}
	}
};
