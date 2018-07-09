#pragma once
#include "MNVButton.h"

// ControllerList 대화 상자입니다.

class ControllerList : public CDialogEx
{
	DECLARE_DYNAMIC(ControllerList)

public:
	ControllerList(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~ControllerList();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ControllerList };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedLighttitleno();
	afx_msg void OnBnClickedLighttitlename();
	afx_msg void OnBnClickedLighttitlechannel();
	afx_msg void OnBnClickedLighttitlemax();
	afx_msg void OnBnClickedLighttitletest();
	afx_msg void OnBnClickedLightno1();
	afx_msg void OnBnClickedLightname1();
	afx_msg void OnBnClickedLightchannel1();
	afx_msg void OnBnClickedLightmax1();
	afx_msg void OnBnClickedLighttest1();
	afx_msg void OnBnClickedLightno2();
	afx_msg void OnBnClickedLightname2();
	afx_msg void OnBnClickedLightchannel2();
	afx_msg void OnBnClickedLightmax2();
	afx_msg void OnBnClickedLighttest2();
	afx_msg void OnBnClickedLightno3();
	afx_msg void OnBnClickedLightname3();
	afx_msg void OnBnClickedLightchannel3();
	afx_msg void OnBnClickedLightmax3();
	afx_msg void OnBnClickedLighttest3();
	afx_msg void OnBnClickedLightno4();
	afx_msg void OnBnClickedLightname4();
	afx_msg void OnBnClickedLightchannel4();
	afx_msg void OnBnClickedLightmax4();
	afx_msg void OnBnClickedLighttest4();
	afx_msg void OnBnClickedLightno5();
	afx_msg void OnBnClickedLightname5();
	afx_msg void OnBnClickedLightchannel5();
	afx_msg void OnBnClickedLightmax5();
	afx_msg void OnBnClickedLighttest5();
	afx_msg void OnBnClickedLightno6();
	afx_msg void OnBnClickedLightname6();
	afx_msg void OnBnClickedLightchannel6();
	afx_msg void OnBnClickedLightmax6();
	afx_msg void OnBnClickedLighttest6();
	afx_msg void OnBnClickedLightno7();
	afx_msg void OnBnClickedLightname7();
	afx_msg void OnBnClickedLightchannel7();
	afx_msg void OnBnClickedLightmax7();
	afx_msg void OnBnClickedLighttest7();
	afx_msg void OnBnClickedLightno8();
	afx_msg void OnBnClickedLightname8();
	afx_msg void OnBnClickedLightchannel8();
	afx_msg void OnBnClickedLightmax8();
	afx_msg void OnBnClickedLighttest8();
	afx_msg void OnBnClickedLightno9();
	afx_msg void OnBnClickedLightname9();
	afx_msg void OnBnClickedLightchannel9();
	afx_msg void OnBnClickedLightmax9();
	afx_msg void OnBnClickedLighttest9();
	afx_msg void OnBnClickedLightno10();
	afx_msg void OnBnClickedLightname10();
	afx_msg void OnBnClickedLightchannel10();
	afx_msg void OnBnClickedLightmax10();
	afx_msg void OnBnClickedLighttest10();
	afx_msg void OnBnClickedLightno11();
	afx_msg void OnBnClickedLightname11();
	afx_msg void OnBnClickedLightchannel11();
	afx_msg void OnBnClickedLightmax11();
	afx_msg void OnBnClickedLighttest11();
	afx_msg void OnBnClickedLightno12();
	afx_msg void OnBnClickedLightname12();
	afx_msg void OnBnClickedLightchannel12();
	afx_msg void OnBnClickedLightmax12();
	afx_msg void OnBnClickedLighttest12();
	afx_msg void OnBnClickedLightno13();
	afx_msg void OnBnClickedLightname13();
	afx_msg void OnBnClickedLightchannel13();
	afx_msg void OnBnClickedLightmax13();
	afx_msg void OnBnClickedLighttest13();
	afx_msg void OnBnClickedLightno14();
	afx_msg void OnBnClickedLightname14();
	afx_msg void OnBnClickedLightchannel14();
	afx_msg void OnBnClickedLightmax14();
	afx_msg void OnBnClickedLighttest14();
	afx_msg void OnBnClickedLightno15();
	afx_msg void OnBnClickedLightname15();
	afx_msg void OnBnClickedLightchannel15();
	afx_msg void OnBnClickedLightmax15();
	afx_msg void OnBnClickedLighttest15();
	afx_msg void OnBnClickedLightno16();
	afx_msg void OnBnClickedLightname16();
	afx_msg void OnBnClickedLightchannel16();
	afx_msg void OnBnClickedLightmax16();
	afx_msg void OnBnClickedLighttest16();
	afx_msg void OnBnClickedLightno17();
	afx_msg void OnBnClickedLightname17();
	afx_msg void OnBnClickedLightchannel17();
	afx_msg void OnBnClickedLightmax17();
	afx_msg void OnBnClickedLighttest17();
	afx_msg void OnBnClickedLightno18();
	afx_msg void OnBnClickedLightname18();
	afx_msg void OnBnClickedLightchannel18();
	afx_msg void OnBnClickedLightmax18();
	afx_msg void OnBnClickedLighttest18();
	afx_msg void OnBnClickedLightno19();
	afx_msg void OnBnClickedLightname19();
	afx_msg void OnBnClickedLightchannel19();
	afx_msg void OnBnClickedLightmax19();
	afx_msg void OnBnClickedLighttest19();
	afx_msg void OnBnClickedLightno20();
	afx_msg void OnBnClickedLightname20();
	afx_msg void OnBnClickedLightchannel20();
	afx_msg void OnBnClickedLightmax20();
	afx_msg void OnBnClickedLighttest20();
	CMNVButton m_lightChannel1;
	CMNVButton m_lightChannel10;
	CMNVButton m_lightChannel11;
	CMNVButton m_lightChannel12;
	CMNVButton m_lightChannel13;
	CMNVButton m_lightChannel14;
	CMNVButton m_lightChannel15;
	CMNVButton m_lightChannel16;
	CMNVButton m_lightChannel17;
	CMNVButton m_lightChannel18;
	CMNVButton m_lightChannel19;
	CMNVButton m_lightChannel2;
	CMNVButton m_lightChannel20;
	CMNVButton m_lightChannel3;
	CMNVButton m_lightChannel4;
	CMNVButton m_lightChannel5;
	CMNVButton m_lightChannel6;
	CMNVButton m_lightChannel7;
	CMNVButton m_lightChannel8;
	CMNVButton m_lightChannel9;
	CMNVButton m_lightMax1;
	CMNVButton m_lightMax10;
	CMNVButton m_lightMax11;
	CMNVButton m_lightMax12;
	CMNVButton m_lightMax13;
	CMNVButton m_lightMax14;
	CMNVButton m_lightMax15;
	CMNVButton m_lightMax16;
	CMNVButton m_lightMax17;
	CMNVButton m_lightMax18;
	CMNVButton m_lightMax19;
	CMNVButton m_lightMax2;
	CMNVButton m_lightMax20;
	CMNVButton m_lightMax3;
	CMNVButton m_lightMax4;
	CMNVButton m_lightMax5;
	CMNVButton m_lightMax6;
	CMNVButton m_lightMax7;
	CMNVButton m_lightMax8;
	CMNVButton m_lightMax9;
	CMNVButton m_lightName1;
	CMNVButton m_lightName10;
	CMNVButton m_lightName11;
	CMNVButton m_lightName12;
	CMNVButton m_lightName13;
	CMNVButton m_lightName14;
	CMNVButton m_lightName15;
	CMNVButton m_lightName16;
	CMNVButton m_lightName17;
	CMNVButton m_lightName18;
	CMNVButton m_lightName19;
	CMNVButton m_lightName2;
	CMNVButton m_lightName20;
	CMNVButton m_lightName3;
	CMNVButton m_lightName4;
	CMNVButton m_lightName5;
	CMNVButton m_lightName6;
	CMNVButton m_lightName7;
	CMNVButton m_lightName8;
	CMNVButton m_lightName9;
	CMNVButton m_lightNo1;
	CMNVButton m_lightNo10;
	CMNVButton m_lightNo11;
	CMNVButton m_lightNo12;
	CMNVButton m_lightNo13;
	CMNVButton m_lightNo14;
	CMNVButton m_lightNo15;
	CMNVButton m_lightNo16;
	CMNVButton m_lightNo17;
	CMNVButton m_lightNo18;
	CMNVButton m_lightNo19;
	CMNVButton m_lightNo2;
	CMNVButton m_lightNo20;
	CMNVButton m_lightNo3;
	CMNVButton m_lightNo4;
	CMNVButton m_lightNo5;
	CMNVButton m_lightNo6;
	CMNVButton m_lightNo7;
	CMNVButton m_lightNo8;
	CMNVButton m_lightNo9;
	CMNVButton m_lightTest1;
	CMNVButton m_lightTest10;
	CMNVButton m_lightTest11;
	CMNVButton m_lightTest12;
	CMNVButton m_lightTest13;
	CMNVButton m_lightTest14;
	CMNVButton m_lightTest15;
	CMNVButton m_lightTest16;
	CMNVButton m_lightTest17;
	CMNVButton m_lightTest18;
	CMNVButton m_lightTest19;
	CMNVButton m_lightTest2;
	CMNVButton m_lightTest20;
	CMNVButton m_lightTest3;
	CMNVButton m_lightTest4;
	CMNVButton m_lightTest5;
	CMNVButton m_lightTest6;
	CMNVButton m_lightTest7;
	CMNVButton m_lightTest8;
	CMNVButton m_lightTest9;
	CMNVButton m_lightTitleChannel;
	CMNVButton m_lightTitleMax;
	CMNVButton m_lightTitleName;
	CMNVButton m_lightTitleNo;
	CMNVButton m_lightTitleTest;
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	void On_WindBottomPos(void);
	virtual BOOL OnInitDialog();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
protected:
	int m_nCurHeight;
	int m_nScrollPos;
	CRect m_rect;
};
