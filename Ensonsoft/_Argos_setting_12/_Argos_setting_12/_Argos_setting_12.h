
// _Argos_setting_12.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// C_Argos_setting_12App:
// �� Ŭ������ ������ ���ؼ��� _Argos_setting_12.cpp�� �����Ͻʽÿ�.
//

class C_Argos_setting_12App : public CWinApp
{
public:
	C_Argos_setting_12App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern C_Argos_setting_12App theApp;