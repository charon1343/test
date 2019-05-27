#pragma once
#include "TcpIpNum.h"


// Signal 대화 상자입니다.

class Signal : public CDialogEx
{
	DECLARE_DYNAMIC(Signal)

public:
	Signal(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~Signal();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SIGNAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSignaldestination();
	afx_msg void OnBnClickedSignalsegment();
	afx_msg void OnBnClickedSignalsegmentvalue();
	afx_msg void OnBnClickedSignalsize();
	afx_msg void OnBnClickedSignalsizevalue();
	afx_msg void OnBnClickedSignaltitlename();
	afx_msg void OnBnClickedSignaltitleoffset();
	afx_msg void OnBnClickedSignaltitletype();
	afx_msg void OnBnClickedSignaltitlebit();
	afx_msg void OnBnClickedSignaltitlevalue();
	afx_msg void OnBnClickedSignalname1();
	afx_msg void OnBnClickedSignaloffset1();
	afx_msg void OnBnClickedSignaltype1();
	afx_msg void OnBnClickedSignalbit1();
	afx_msg void OnBnClickedSignalvalue1();
	afx_msg void OnBnClickedSignalname2();
	afx_msg void OnBnClickedSignaloffset2();
	afx_msg void OnBnClickedSignaltype2();
	afx_msg void OnBnClickedSignalbit2();
	afx_msg void OnBnClickedSignalvalue2();
	afx_msg void OnBnClickedSignalname3();
	afx_msg void OnBnClickedSignaloffset3();
	afx_msg void OnBnClickedSignaltype3();
	afx_msg void OnBnClickedSignalbit3();
	afx_msg void OnBnClickedSignalvalue3();
	afx_msg void OnBnClickedSignalname4();
	afx_msg void OnBnClickedSignaloffset4();
	afx_msg void OnBnClickedSignaltype4();
	afx_msg void OnBnClickedSignalbit4();
	afx_msg void OnBnClickedSignalvalue4();
	afx_msg void OnBnClickedSignalname5();
	afx_msg void OnBnClickedSignaloffset5();
	afx_msg void OnBnClickedSignaltype5();
	afx_msg void OnBnClickedSignalbit5();
	afx_msg void OnBnClickedSignalvalue5();
	afx_msg void OnBnClickedSignalname6();
	afx_msg void OnBnClickedSignaloffset6();
	afx_msg void OnBnClickedSignaltype6();
	afx_msg void OnBnClickedSignalbit6();
	afx_msg void OnBnClickedSignalvalue6();
	afx_msg void OnBnClickedSignalname7();
	afx_msg void OnBnClickedSignaloffset7();
	afx_msg void OnBnClickedSignaltype7();
	afx_msg void OnBnClickedSignalbit7();
	afx_msg void OnBnClickedSignalvalue7();
	afx_msg void OnBnClickedSignalname8();
	afx_msg void OnBnClickedSignaloffset8();
	afx_msg void OnBnClickedSignaltype8();
	afx_msg void OnBnClickedSignalbit8();
	afx_msg void OnBnClickedSignalvalue8();
	afx_msg void OnBnClickedSignalname9();
	afx_msg void OnBnClickedSignaloffset9();
	afx_msg void OnBnClickedSignaltype9();
	afx_msg void OnBnClickedSignalbit9();
	afx_msg void OnBnClickedSignalvalue9();
	afx_msg void OnBnClickedSignalname10();
	afx_msg void OnBnClickedSignaloffset10();
	afx_msg void OnBnClickedSignaltype10();
	afx_msg void OnBnClickedSignalbit10();
	afx_msg void OnBnClickedSignalvalue10();
	CMNVButton m_signalBit1;
	CMNVButton m_signalBit10;
	CMNVButton m_signalBit2;
	CMNVButton m_signalBit3;
	CMNVButton m_signalBit4;
	CMNVButton m_signalBit5;
	CMNVButton m_signalBit6;
	CMNVButton m_signalBit7;
	CMNVButton m_signalBit8;
	CMNVButton m_signalBit9;
	CMNVButton m_signalDestination;
	CMNVButton m_signalName1;
	CMNVButton m_signalName10;
	CMNVButton m_signalName2;
	CMNVButton m_signalName3;
	CMNVButton m_signalName4;
	CMNVButton m_signalName5;
	CMNVButton m_signalName6;
	CMNVButton m_signalName7;
	CMNVButton m_signalName8;
	CMNVButton m_signalName9;
	CMNVButton m_signalOffset1;
	CMNVButton m_signalOffset10;
	CMNVButton m_signalOffset2;
	CMNVButton m_signalOffset3;
	CMNVButton m_signalOffset4;
	CMNVButton m_signalOffset5;
	CMNVButton m_signalOffset6;
	CMNVButton m_signalOffset7;
	CMNVButton m_signalOffset8;
	CMNVButton m_signalOffset9;
	CMNVButton m_signalSegment;
	CMNVButton m_signalSegmentValue;
	CMNVButton m_signalSize;
	CMNVButton m_signalSizeValue;
	CMNVButton m_signalTitleBit;
	CMNVButton m_signalTitleName;
	CMNVButton m_signalTitleOffset;
	CMNVButton m_signalTitleType;
	CMNVButton m_signalTitleValue;
	CMNVButton m_signalType1;
	CMNVButton m_signalType10;
	CMNVButton m_signalType2;
	CMNVButton m_signalType3;
	CMNVButton m_signalType4;
	CMNVButton m_signalType5;
	CMNVButton m_signalType6;
	CMNVButton m_signalType7;
	CMNVButton m_signalType8;
	CMNVButton m_signalType9;
	CMNVButton m_signalValue1;
	CMNVButton m_signalValue10;
	CMNVButton m_signalValue2;
	CMNVButton m_signalValue3;
	CMNVButton m_signalValue4;
	CMNVButton m_signalValue5;
	CMNVButton m_signalValue6;
	CMNVButton m_signalValue7;
	CMNVButton m_signalValue8;
	CMNVButton m_signalValue9;
	void On_WindBottomPos(void);
	virtual BOOL OnInitDialog();
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
};
