
// _tapcontrol.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// C_tapcontrolApp:
// �� Ŭ������ ������ ���ؼ��� _tapcontrol.cpp�� �����Ͻʽÿ�.
//

class C_tapcontrolApp : public CWinApp
{
public:
	C_tapcontrolApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern C_tapcontrolApp theApp;