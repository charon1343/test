
// ButtonUI.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CButtonUIApp:
// �� Ŭ������ ������ ���ؼ��� ButtonUI.cpp�� �����Ͻʽÿ�.
//

class CButtonUIApp : public CWinApp
{
public:
	CButtonUIApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CButtonUIApp theApp;