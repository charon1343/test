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
	double calipers;
	double projection;
	double search;
	double threashold;
	double halfpixel;
	double ignore;
};


