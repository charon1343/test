
// _mfc.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// C_mfcApp:
// �� Ŭ������ ������ ���ؼ��� _mfc.cpp�� �����Ͻʽÿ�.
//

class C_mfcApp : public CWinApp
{
public:
	C_mfcApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern C_mfcApp theApp;