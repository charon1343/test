
// MFC_TEST1.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMFC_TEST1App:
// �� Ŭ������ ������ ���ؼ��� MFC_TEST1.cpp�� �����Ͻʽÿ�.
//

class CMFC_TEST1App : public CWinApp
{
public:
	CMFC_TEST1App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMFC_TEST1App theApp;