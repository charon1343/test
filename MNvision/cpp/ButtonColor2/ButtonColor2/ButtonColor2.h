
// ButtonColor2.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CButtonColor2App:
// �� Ŭ������ ������ ���ؼ��� ButtonColor2.cpp�� �����Ͻʽÿ�.
//

class CButtonColor2App : public CWinApp
{
public:
	CButtonColor2App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CButtonColor2App theApp;