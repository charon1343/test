
// _Argos_tap.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// C_Argos_tapApp:
// �� Ŭ������ ������ ���ؼ��� _Argos_tap.cpp�� �����Ͻʽÿ�.
//

class C_Argos_tapApp : public CWinApp
{
public:
	C_Argos_tapApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern C_Argos_tapApp theApp;