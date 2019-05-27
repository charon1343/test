// CalssValue.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "button1.h"
#include "CalssValue.h"


// CalssValue

IMPLEMENT_DYNAMIC(CalssValue, CWnd)

CalssValue::CalssValue()
{

	calipers=0;
	projection=0;
	search=0;
	threashold=0;
	halfpixel=0;
	ignore=0;
}

CalssValue::~CalssValue()
{
}


BEGIN_MESSAGE_MAP(CalssValue, CWnd)
END_MESSAGE_MAP()



// CalssValue 메시지 처리기입니다.


