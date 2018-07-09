#pragma once
#include <afx.h>

class CMNVFile : public CFile {
public:
	static void CreateDir(LPCTSTR __strDir) {
		CString strPath = _T("");
		strPath.Format(_T("%s\\"), __strDir);

		int nLength = strPath.Find(':', 0);
		nLength = (nLength < 0) ? 0 : (nLength + 2);
		CString strDir;
		while (nLength >= 0) {
			nLength = strPath.Find('\\', nLength + 1);
			strDir = strPath.Left(nLength);
			if (nLength > 0) CreateDirectory(strDir, NULL);
		}
	}
	static void CreatePath(LPCTSTR __strFilePath) {
		CString strPath = __strFilePath;

		int nLength = strPath.Find(':', 0);
		nLength = (nLength < 0) ? 0 : (nLength + 2);
		CString strDir;
		while (nLength >= 0) {
			nLength = strPath.Find('\\', nLength + 1);
			strDir = strPath.Left(nLength);
			if (nLength > 0) CreateDirectory(strDir, NULL);
		}
	}
	static int GetDirve(LPCTSTR __strPath) {
		CString strPath = __strPath;
		if (strPath[1] == ':') {
			int nDrive = strPath.MakeUpper()[0];
			if ('A' <= nDrive && nDrive <= 'Z') {
				return nDrive - 'A' + 1;
			}
			else 0;
		}
		return 0;
	}
	static void Convert(LPCSTR __lpcstr, wchar_t Buf[], int __nLength) {
		ZeroMemory(Buf, __nLength * sizeof(wchar_t));
		MultiByteToWideChar(CP_ACP, 0, __lpcstr, (int)strlen(__lpcstr), Buf, __nLength);
	}
	static void Convert(LPCWSTR __lpcwstr, char Buf[], int __nLength) {
		ZeroMemory(Buf, __nLength);
		WideCharToMultiByte(CP_ACP, 0, __lpcwstr, (int)wcslen(__lpcwstr), Buf, __nLength, NULL, NULL);
	}

	static void DeleteDir(CString strPath) {
		CFileFind clsFFind;
		bool isFinded = clsFFind.FindFile(strPath + "\\*.*") == TRUE;

		while (isFinded) {
			isFinded = clsFFind.FindNextFile() == TRUE;
			if (clsFFind.IsDots() == TRUE) {
			}
			else if (clsFFind.IsDirectory() == TRUE) {
				DeleteDir(clsFFind.GetFilePath());
			}
			else {
				DeleteFile(clsFFind.GetFilePath());
				Sleep(10);
				//Delete File
			}
		}
		clsFFind.Close();
		RemoveDirectory(strPath);
	}

	bool OpenFile(LPCTSTR __strDir, LPCTSTR __strFile) {
		bool isFile = false;
		CMNVFile::CreateDir(__strDir);

		CString strFilePath;
		strFilePath.Format(_T("%s\\%s"), __strDir, __strFile);
		if (CFile::Open(strFilePath, CFile::modeReadWrite) == TRUE) {
			SeekToEnd();
			return true;
		}
		if (CFile::Open(strFilePath, CFile::modeReadWrite | CFile::modeCreate) == TRUE) {
			return true;
		}
		return false;
	}
	bool OpenFile(LPCTSTR __strDir, LPCTSTR __strFile, LPCWSTR __strHeader) {
		bool isFile = false;
		CMNVFile::CreateDir(__strDir);

		CString strFilePath;
		strFilePath.Format(_T("%s\\%s"), __strDir, __strFile);
		if (CFile::Open(strFilePath, CFile::modeReadWrite) == TRUE) {
			SeekToEnd();
			return true;
		}
		if (CFile::Open(strFilePath, CFile::modeReadWrite | CFile::modeCreate) == TRUE) {
			Write(__strHeader);
			SeekToEnd();
			return true;
		}
		return false;
	}
	bool WriteFile(LPCTSTR __strDir, LPCTSTR __strFile, LPCWSTR __strHeader, LPCWSTR __strContents) {
		if (OpenFile(__strDir, __strFile, __strHeader)) {
			Write(__strContents);
			Close();
			return true;
		}
		return false;
	}
	bool WriteFile(LPCTSTR __strDir, LPCTSTR __strFile, LPCWSTR __strContents) {
		if ( OpenFile(__strDir, __strFile) ) {
			Write(__strContents);
			Close();
			return true;
		}
		return false;
	}
	bool Write(LPCWSTR __strContents) {
		char Buf[1024];
		Convert(__strContents, Buf, 1024);
		CFile::Write(Buf, (UINT)strlen(Buf));
		return true;
	}
};
