
// listbox.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// ClistboxApp:
// �� Ŭ������ ������ ���ؼ��� listbox.cpp�� �����Ͻʽÿ�.
//

class ClistboxApp : public CWinApp
{
public:
	ClistboxApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern ClistboxApp theApp;