
// MN_VIS.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMN_VISApp:
// �� Ŭ������ ������ ���ؼ��� MN_VIS.cpp�� �����Ͻʽÿ�.
//

class CMN_VISApp : public CWinApp
{
public:
	CMN_VISApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CMN_VISApp theApp;