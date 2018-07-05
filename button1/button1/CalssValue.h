#pragma once


// CalssValue

class CalssValue : public CWnd
{
	DECLARE_DYNAMIC(CalssValue)

public:
	CalssValue();
	virtual ~CalssValue();

protected:
	DECLARE_MESSAGE_MAP()
public:
	int calipers;
	int projection;
	int search;
	int threashold;
	int halfpixel;
	int ignore;
};


