
// ButtonColor.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CButtonColorApp:
// �� Ŭ������ ������ ���ؼ��� ButtonColor.cpp�� �����Ͻʽÿ�.
//

class CButtonColorApp : public CWinApp
{
public:
	CButtonColorApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CButtonColorApp theApp;