
// SetLightController.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CSetLightControllerApp:
// �� Ŭ������ ������ ���ؼ��� SetLightController.cpp�� �����Ͻʽÿ�.
//

class CSetLightControllerApp : public CWinApp
{
public:
	CSetLightControllerApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CSetLightControllerApp theApp;