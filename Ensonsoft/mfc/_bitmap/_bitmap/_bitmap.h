
// _bitmap.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// C_bitmapApp:
// �� Ŭ������ ������ ���ؼ��� _bitmap.cpp�� �����Ͻʽÿ�.
//

class C_bitmapApp : public CWinApp
{
public:
	C_bitmapApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern C_bitmapApp theApp;