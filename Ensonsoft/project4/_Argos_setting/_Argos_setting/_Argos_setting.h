
// _Argos_setting.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// C_Argos_settingApp:
// �� Ŭ������ ������ ���ؼ��� _Argos_setting.cpp�� �����Ͻʽÿ�.
//

class C_Argos_settingApp : public CWinApp
{
public:
	C_Argos_settingApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern C_Argos_settingApp theApp;