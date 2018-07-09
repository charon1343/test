// ControllerList.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "SetLightController.h"
#include "ControllerList.h"
#include "afxdialogex.h"


// ControllerList 대화 상자입니다.

IMPLEMENT_DYNAMIC(ControllerList, CDialogEx)

ControllerList::ControllerList(CWnd* pParent /*=NULL*/)
	: CDialogEx(ControllerList::IDD, pParent)
{

}

ControllerList::~ControllerList()
{
}

void ControllerList::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LightChannel1, m_lightChannel1);
	DDX_Control(pDX, IDC_LightChannel10, m_lightChannel10);
	DDX_Control(pDX, IDC_LightChannel11, m_lightChannel11);
	DDX_Control(pDX, IDC_LightChannel12, m_lightChannel12);
	DDX_Control(pDX, IDC_LightChannel13, m_lightChannel13);
	DDX_Control(pDX, IDC_LightChannel14, m_lightChannel14);
	DDX_Control(pDX, IDC_LightChannel15, m_lightChannel15);
	DDX_Control(pDX, IDC_LightChannel16, m_lightChannel16);
	DDX_Control(pDX, IDC_LightChannel17, m_lightChannel17);
	DDX_Control(pDX, IDC_LightChannel18, m_lightChannel18);
	DDX_Control(pDX, IDC_LightChannel19, m_lightChannel19);
	DDX_Control(pDX, IDC_LightChannel2, m_lightChannel2);
	DDX_Control(pDX, IDC_LightChannel20, m_lightChannel20);
	DDX_Control(pDX, IDC_LightChannel3, m_lightChannel3);
	DDX_Control(pDX, IDC_LightChannel4, m_lightChannel4);
	DDX_Control(pDX, IDC_LightChannel5, m_lightChannel5);
	DDX_Control(pDX, IDC_LightChannel6, m_lightChannel6);
	DDX_Control(pDX, IDC_LightChannel7, m_lightChannel7);
	DDX_Control(pDX, IDC_LightChannel8, m_lightChannel8);
	DDX_Control(pDX, IDC_LightChannel9, m_lightChannel9);
	DDX_Control(pDX, IDC_LightMax1, m_lightMax1);
	DDX_Control(pDX, IDC_LightMax10, m_lightMax10);
	DDX_Control(pDX, IDC_LightMax11, m_lightMax11);
	DDX_Control(pDX, IDC_LightMax12, m_lightMax12);
	DDX_Control(pDX, IDC_LightMax13, m_lightMax13);
	DDX_Control(pDX, IDC_LightMax14, m_lightMax14);
	DDX_Control(pDX, IDC_LightMax15, m_lightMax15);
	DDX_Control(pDX, IDC_LightMax16, m_lightMax16);
	DDX_Control(pDX, IDC_LightMax17, m_lightMax17);
	DDX_Control(pDX, IDC_LightMax18, m_lightMax18);
	DDX_Control(pDX, IDC_LightMax19, m_lightMax19);
	DDX_Control(pDX, IDC_LightMax2, m_lightMax2);
	DDX_Control(pDX, IDC_LightMax20, m_lightMax20);
	DDX_Control(pDX, IDC_LightMax3, m_lightMax3);
	DDX_Control(pDX, IDC_LightMax4, m_lightMax4);
	DDX_Control(pDX, IDC_LightMax5, m_lightMax5);
	DDX_Control(pDX, IDC_LightMax6, m_lightMax6);
	DDX_Control(pDX, IDC_LightMax7, m_lightMax7);
	DDX_Control(pDX, IDC_LightMax8, m_lightMax8);
	DDX_Control(pDX, IDC_LightMax9, m_lightMax9);
	DDX_Control(pDX, IDC_LightName1, m_lightName1);
	DDX_Control(pDX, IDC_LightName10, m_lightName10);
	DDX_Control(pDX, IDC_LightName11, m_lightName11);
	DDX_Control(pDX, IDC_LightName12, m_lightName12);
	DDX_Control(pDX, IDC_LightName13, m_lightName13);
	DDX_Control(pDX, IDC_LightName14, m_lightName14);
	DDX_Control(pDX, IDC_LightName15, m_lightName15);
	DDX_Control(pDX, IDC_LightName16, m_lightName16);
	DDX_Control(pDX, IDC_LightName17, m_lightName17);
	DDX_Control(pDX, IDC_LightName18, m_lightName18);
	DDX_Control(pDX, IDC_LightName19, m_lightName19);
	DDX_Control(pDX, IDC_LightName2, m_lightName2);
	DDX_Control(pDX, IDC_LightName20, m_lightName20);
	DDX_Control(pDX, IDC_LightName3, m_lightName3);
	DDX_Control(pDX, IDC_LightName4, m_lightName4);
	DDX_Control(pDX, IDC_LightName5, m_lightName5);
	DDX_Control(pDX, IDC_LightName6, m_lightName6);
	DDX_Control(pDX, IDC_LightName7, m_lightName7);
	DDX_Control(pDX, IDC_LightName8, m_lightName8);
	DDX_Control(pDX, IDC_LightName9, m_lightName9);
	DDX_Control(pDX, IDC_LightNo1, m_lightNo1);
	DDX_Control(pDX, IDC_LightNo10, m_lightNo10);
	DDX_Control(pDX, IDC_LightNo11, m_lightNo11);
	DDX_Control(pDX, IDC_LightNo12, m_lightNo12);
	DDX_Control(pDX, IDC_LightNo13, m_lightNo13);
	DDX_Control(pDX, IDC_LightNo14, m_lightNo14);
	DDX_Control(pDX, IDC_LightNo15, m_lightNo15);
	DDX_Control(pDX, IDC_LightNo16, m_lightNo16);
	DDX_Control(pDX, IDC_LightNo17, m_lightNo17);
	DDX_Control(pDX, IDC_LightNo18, m_lightNo18);
	DDX_Control(pDX, IDC_LightNo19, m_lightNo19);
	DDX_Control(pDX, IDC_LightNo2, m_lightNo2);
	DDX_Control(pDX, IDC_LightNo20, m_lightNo20);
	DDX_Control(pDX, IDC_LightNo3, m_lightNo3);
	DDX_Control(pDX, IDC_LightNo4, m_lightNo4);
	DDX_Control(pDX, IDC_LightNo5, m_lightNo5);
	DDX_Control(pDX, IDC_LightNo6, m_lightNo6);
	DDX_Control(pDX, IDC_LightNo7, m_lightNo7);
	DDX_Control(pDX, IDC_LightNo8, m_lightNo8);
	DDX_Control(pDX, IDC_LightNo9, m_lightNo9);
	DDX_Control(pDX, IDC_LightTest1, m_lightTest1);
	DDX_Control(pDX, IDC_LightTest10, m_lightTest10);
	DDX_Control(pDX, IDC_LightTest11, m_lightTest11);
	DDX_Control(pDX, IDC_LightTest12, m_lightTest12);
	DDX_Control(pDX, IDC_LightTest13, m_lightTest13);
	DDX_Control(pDX, IDC_LightTest14, m_lightTest14);
	DDX_Control(pDX, IDC_LightTest15, m_lightTest15);
	DDX_Control(pDX, IDC_LightTest16, m_lightTest16);
	DDX_Control(pDX, IDC_LightTest17, m_lightTest17);
	DDX_Control(pDX, IDC_LightTest18, m_lightTest18);
	DDX_Control(pDX, IDC_LightTest19, m_lightTest19);
	DDX_Control(pDX, IDC_LightTest2, m_lightTest2);
	DDX_Control(pDX, IDC_LightTest20, m_lightTest20);
	DDX_Control(pDX, IDC_LightTest3, m_lightTest3);
	DDX_Control(pDX, IDC_LightTest4, m_lightTest4);
	DDX_Control(pDX, IDC_LightTest5, m_lightTest5);
	DDX_Control(pDX, IDC_LightTest6, m_lightTest6);
	DDX_Control(pDX, IDC_LightTest7, m_lightTest7);
	DDX_Control(pDX, IDC_LightTest8, m_lightTest8);
	DDX_Control(pDX, IDC_LightTest9, m_lightTest9);
	DDX_Control(pDX, IDC_LightTitleChannel, m_lightTitleChannel);
	DDX_Control(pDX, IDC_LightTitleMax, m_lightTitleMax);
	DDX_Control(pDX, IDC_LightTitleName, m_lightTitleName);
	DDX_Control(pDX, IDC_LightTitleNo, m_lightTitleNo);
	DDX_Control(pDX, IDC_LightTitleTest, m_lightTitleTest);
}


BEGIN_MESSAGE_MAP(ControllerList, CDialogEx)
	ON_BN_CLICKED(IDC_LightTitleNo, &ControllerList::OnBnClickedLighttitleno)
	ON_BN_CLICKED(IDC_LightTitleName, &ControllerList::OnBnClickedLighttitlename)
	ON_BN_CLICKED(IDC_LightTitleChannel, &ControllerList::OnBnClickedLighttitlechannel)
	ON_BN_CLICKED(IDC_LightTitleMax, &ControllerList::OnBnClickedLighttitlemax)
	ON_BN_CLICKED(IDC_LightTitleTest, &ControllerList::OnBnClickedLighttitletest)
	ON_BN_CLICKED(IDC_LightNo1, &ControllerList::OnBnClickedLightno1)
	ON_BN_CLICKED(IDC_LightName1, &ControllerList::OnBnClickedLightname1)
	ON_BN_CLICKED(IDC_LightChannel1, &ControllerList::OnBnClickedLightchannel1)
	ON_BN_CLICKED(IDC_LightMax1, &ControllerList::OnBnClickedLightmax1)
	ON_BN_CLICKED(IDC_LightTest1, &ControllerList::OnBnClickedLighttest1)
	ON_BN_CLICKED(IDC_LightNo2, &ControllerList::OnBnClickedLightno2)
	ON_BN_CLICKED(IDC_LightName2, &ControllerList::OnBnClickedLightname2)
	ON_BN_CLICKED(IDC_LightChannel2, &ControllerList::OnBnClickedLightchannel2)
	ON_BN_CLICKED(IDC_LightMax2, &ControllerList::OnBnClickedLightmax2)
	ON_BN_CLICKED(IDC_LightTest2, &ControllerList::OnBnClickedLighttest2)
	ON_BN_CLICKED(IDC_LightNo3, &ControllerList::OnBnClickedLightno3)
	ON_BN_CLICKED(IDC_LightName3, &ControllerList::OnBnClickedLightname3)
	ON_BN_CLICKED(IDC_LightChannel3, &ControllerList::OnBnClickedLightchannel3)
	ON_BN_CLICKED(IDC_LightMax3, &ControllerList::OnBnClickedLightmax3)
	ON_BN_CLICKED(IDC_LightTest3, &ControllerList::OnBnClickedLighttest3)
	ON_BN_CLICKED(IDC_LightNo4, &ControllerList::OnBnClickedLightno4)
	ON_BN_CLICKED(IDC_LightName4, &ControllerList::OnBnClickedLightname4)
	ON_BN_CLICKED(IDC_LightChannel4, &ControllerList::OnBnClickedLightchannel4)
	ON_BN_CLICKED(IDC_LightMax4, &ControllerList::OnBnClickedLightmax4)
	ON_BN_CLICKED(IDC_LightTest4, &ControllerList::OnBnClickedLighttest4)
	ON_BN_CLICKED(IDC_LightNo5, &ControllerList::OnBnClickedLightno5)
	ON_BN_CLICKED(IDC_LightName5, &ControllerList::OnBnClickedLightname5)
	ON_BN_CLICKED(IDC_LightChannel5, &ControllerList::OnBnClickedLightchannel5)
	ON_BN_CLICKED(IDC_LightMax5, &ControllerList::OnBnClickedLightmax5)
	ON_BN_CLICKED(IDC_LightTest5, &ControllerList::OnBnClickedLighttest5)
	ON_BN_CLICKED(IDC_LightNo6, &ControllerList::OnBnClickedLightno6)
	ON_BN_CLICKED(IDC_LightName6, &ControllerList::OnBnClickedLightname6)
	ON_BN_CLICKED(IDC_LightChannel6, &ControllerList::OnBnClickedLightchannel6)
	ON_BN_CLICKED(IDC_LightMax6, &ControllerList::OnBnClickedLightmax6)
	ON_BN_CLICKED(IDC_LightTest6, &ControllerList::OnBnClickedLighttest6)
	ON_BN_CLICKED(IDC_LightNo7, &ControllerList::OnBnClickedLightno7)
	ON_BN_CLICKED(IDC_LightName7, &ControllerList::OnBnClickedLightname7)
	ON_BN_CLICKED(IDC_LightChannel7, &ControllerList::OnBnClickedLightchannel7)
	ON_BN_CLICKED(IDC_LightMax7, &ControllerList::OnBnClickedLightmax7)
	ON_BN_CLICKED(IDC_LightTest7, &ControllerList::OnBnClickedLighttest7)
	ON_BN_CLICKED(IDC_LightNo8, &ControllerList::OnBnClickedLightno8)
	ON_BN_CLICKED(IDC_LightName8, &ControllerList::OnBnClickedLightname8)
	ON_BN_CLICKED(IDC_LightChannel8, &ControllerList::OnBnClickedLightchannel8)
	ON_BN_CLICKED(IDC_LightMax8, &ControllerList::OnBnClickedLightmax8)
	ON_BN_CLICKED(IDC_LightTest8, &ControllerList::OnBnClickedLighttest8)
	ON_BN_CLICKED(IDC_LightNo9, &ControllerList::OnBnClickedLightno9)
	ON_BN_CLICKED(IDC_LightName9, &ControllerList::OnBnClickedLightname9)
	ON_BN_CLICKED(IDC_LightChannel9, &ControllerList::OnBnClickedLightchannel9)
	ON_BN_CLICKED(IDC_LightMax9, &ControllerList::OnBnClickedLightmax9)
	ON_BN_CLICKED(IDC_LightTest9, &ControllerList::OnBnClickedLighttest9)
	ON_BN_CLICKED(IDC_LightNo10, &ControllerList::OnBnClickedLightno10)
	ON_BN_CLICKED(IDC_LightName10, &ControllerList::OnBnClickedLightname10)
	ON_BN_CLICKED(IDC_LightChannel10, &ControllerList::OnBnClickedLightchannel10)
	ON_BN_CLICKED(IDC_LightMax10, &ControllerList::OnBnClickedLightmax10)
	ON_BN_CLICKED(IDC_LightTest10, &ControllerList::OnBnClickedLighttest10)
	ON_BN_CLICKED(IDC_LightNo11, &ControllerList::OnBnClickedLightno11)
	ON_BN_CLICKED(IDC_LightName11, &ControllerList::OnBnClickedLightname11)
	ON_BN_CLICKED(IDC_LightChannel11, &ControllerList::OnBnClickedLightchannel11)
	ON_BN_CLICKED(IDC_LightMax11, &ControllerList::OnBnClickedLightmax11)
	ON_BN_CLICKED(IDC_LightTest11, &ControllerList::OnBnClickedLighttest11)
	ON_BN_CLICKED(IDC_LightNo12, &ControllerList::OnBnClickedLightno12)
	ON_BN_CLICKED(IDC_LightName12, &ControllerList::OnBnClickedLightname12)
	ON_BN_CLICKED(IDC_LightChannel12, &ControllerList::OnBnClickedLightchannel12)
	ON_BN_CLICKED(IDC_LightMax12, &ControllerList::OnBnClickedLightmax12)
	ON_BN_CLICKED(IDC_LightTest12, &ControllerList::OnBnClickedLighttest12)
	ON_BN_CLICKED(IDC_LightNo13, &ControllerList::OnBnClickedLightno13)
	ON_BN_CLICKED(IDC_LightName13, &ControllerList::OnBnClickedLightname13)
	ON_BN_CLICKED(IDC_LightChannel13, &ControllerList::OnBnClickedLightchannel13)
	ON_BN_CLICKED(IDC_LightMax13, &ControllerList::OnBnClickedLightmax13)
	ON_BN_CLICKED(IDC_LightTest13, &ControllerList::OnBnClickedLighttest13)
	ON_BN_CLICKED(IDC_LightNo14, &ControllerList::OnBnClickedLightno14)
	ON_BN_CLICKED(IDC_LightName14, &ControllerList::OnBnClickedLightname14)
	ON_BN_CLICKED(IDC_LightChannel14, &ControllerList::OnBnClickedLightchannel14)
	ON_BN_CLICKED(IDC_LightMax14, &ControllerList::OnBnClickedLightmax14)
	ON_BN_CLICKED(IDC_LightTest14, &ControllerList::OnBnClickedLighttest14)
	ON_BN_CLICKED(IDC_LightNo15, &ControllerList::OnBnClickedLightno15)
	ON_BN_CLICKED(IDC_LightName15, &ControllerList::OnBnClickedLightname15)
	ON_BN_CLICKED(IDC_LightChannel15, &ControllerList::OnBnClickedLightchannel15)
	ON_BN_CLICKED(IDC_LightMax15, &ControllerList::OnBnClickedLightmax15)
	ON_BN_CLICKED(IDC_LightTest15, &ControllerList::OnBnClickedLighttest15)
	ON_BN_CLICKED(IDC_LightNo16, &ControllerList::OnBnClickedLightno16)
	ON_BN_CLICKED(IDC_LightName16, &ControllerList::OnBnClickedLightname16)
	ON_BN_CLICKED(IDC_LightChannel16, &ControllerList::OnBnClickedLightchannel16)
	ON_BN_CLICKED(IDC_LightMax16, &ControllerList::OnBnClickedLightmax16)
	ON_BN_CLICKED(IDC_LightTest16, &ControllerList::OnBnClickedLighttest16)
	ON_BN_CLICKED(IDC_LightNo17, &ControllerList::OnBnClickedLightno17)
	ON_BN_CLICKED(IDC_LightName17, &ControllerList::OnBnClickedLightname17)
	ON_BN_CLICKED(IDC_LightChannel17, &ControllerList::OnBnClickedLightchannel17)
	ON_BN_CLICKED(IDC_LightMax17, &ControllerList::OnBnClickedLightmax17)
	ON_BN_CLICKED(IDC_LightTest17, &ControllerList::OnBnClickedLighttest17)
	ON_BN_CLICKED(IDC_LightNo18, &ControllerList::OnBnClickedLightno18)
	ON_BN_CLICKED(IDC_LightName18, &ControllerList::OnBnClickedLightname18)
	ON_BN_CLICKED(IDC_LightChannel18, &ControllerList::OnBnClickedLightchannel18)
	ON_BN_CLICKED(IDC_LightMax18, &ControllerList::OnBnClickedLightmax18)
	ON_BN_CLICKED(IDC_LightTest18, &ControllerList::OnBnClickedLighttest18)
	ON_BN_CLICKED(IDC_LightNo19, &ControllerList::OnBnClickedLightno19)
	ON_BN_CLICKED(IDC_LightName19, &ControllerList::OnBnClickedLightname19)
	ON_BN_CLICKED(IDC_LightChannel19, &ControllerList::OnBnClickedLightchannel19)
	ON_BN_CLICKED(IDC_LightMax19, &ControllerList::OnBnClickedLightmax19)
	ON_BN_CLICKED(IDC_LightTest19, &ControllerList::OnBnClickedLighttest19)
	ON_BN_CLICKED(IDC_LightNo20, &ControllerList::OnBnClickedLightno20)
	ON_BN_CLICKED(IDC_LightName20, &ControllerList::OnBnClickedLightname20)
	ON_BN_CLICKED(IDC_LightChannel20, &ControllerList::OnBnClickedLightchannel20)
	ON_BN_CLICKED(IDC_LightMax20, &ControllerList::OnBnClickedLightmax20)
	ON_BN_CLICKED(IDC_LightTest20, &ControllerList::OnBnClickedLighttest20)
	ON_WM_WINDOWPOSCHANGED()
	END_MESSAGE_MAP()


// ControllerList 메시지 처리기입니다.


void ControllerList::OnBnClickedLighttitleno()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLighttitlename()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLighttitlechannel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLighttitlemax()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLighttitletest()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightno1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightname1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightchannel1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightmax1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLighttest1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightno2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightname2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightchannel2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightmax2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLighttest2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightno3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightname3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightchannel3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightmax3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLighttest3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightno4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightname4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightchannel4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightmax4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLighttest4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightno5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightname5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightchannel5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightmax5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLighttest5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightno6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightname6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightchannel6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightmax6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLighttest6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightno7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightname7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightchannel7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightmax7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLighttest7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightno8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightname8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightchannel8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightmax8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLighttest8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightno9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightname9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightchannel9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightmax9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLighttest9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightno10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightname10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightchannel10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightmax10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLighttest10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightno11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightname11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightchannel11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightmax11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLighttest11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightno12()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightname12()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightchannel12()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightmax12()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLighttest12()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightno13()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightname13()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightchannel13()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightmax13()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLighttest13()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightno14()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightname14()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightchannel14()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightmax14()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLighttest14()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightno15()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightname15()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightchannel15()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightmax15()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLighttest15()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightno16()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightname16()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightchannel16()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightmax16()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLighttest16()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightno17()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightname17()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightchannel17()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightmax17()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLighttest17()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightno18()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightname18()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightchannel18()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightmax18()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLighttest18()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightno19()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightname19()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightchannel19()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightmax19()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLighttest19()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightno20()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightname20()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightchannel20()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLightmax20()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnBnClickedLighttest20()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ControllerList::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if ((lpwndpos->flags & SWP_NOSIZE) == 0) { On_WindBottomPos();}
}

BOOL ControllerList::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	On_WindBottomPos();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void ControllerList::On_WindBottomPos(void)
{
	CRect rctBottom;
	GetClientRect(&rctBottom);

	rctBottom.top += 5;
	rctBottom.left += 5;
	rctBottom.bottom -= 5;
	rctBottom.right -= 5;

	CRect rctTab = rctBottom;

	int nWidth = (rctBottom.Width()) / 5;
	int nHeight = 40;
	
	rctTab.bottom = rctBottom.top+nHeight;
	rctTab.right = rctBottom.left+nWidth;
	m_lightTitleNo.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightTitleName.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightTitleChannel.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightTitleMax.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightTitleTest.SetWindowPos(rctTab);

	
	rctTab.top = rctTab.bottom;
	rctTab.bottom = rctTab.top+nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_lightNo1.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightName1.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightChannel1.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightMax1.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightTest1.SetWindowPos(rctTab);


	rctTab.top = rctTab.bottom;
	rctTab.bottom = rctTab.top+nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_lightNo2.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightName2.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightChannel2.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightMax2.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightTest2.SetWindowPos(rctTab);
	

	rctTab.top = rctTab.bottom;
	rctTab.bottom = rctTab.top+nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_lightNo3.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightName3.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightChannel3.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightMax3.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightTest3.SetWindowPos(rctTab);
	

	rctTab.top = rctTab.bottom;
	rctTab.bottom = rctTab.top+nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_lightNo4.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightName4.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightChannel4.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightMax4.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightTest4.SetWindowPos(rctTab);
	

	rctTab.top = rctTab.bottom;
	rctTab.bottom = rctTab.top+nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_lightNo5.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightName5.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightChannel5.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightMax5.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightTest5.SetWindowPos(rctTab);
	

	rctTab.top = rctTab.bottom;
	rctTab.bottom = rctTab.top+nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_lightNo6.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightName6.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightChannel6.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightMax6.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightTest6.SetWindowPos(rctTab);
	

	rctTab.top = rctTab.bottom;
	rctTab.bottom = rctTab.top+nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_lightNo7.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightName7.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightChannel7.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightMax7.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightTest7.SetWindowPos(rctTab);
	

	rctTab.top = rctTab.bottom;
	rctTab.bottom = rctTab.top+nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_lightNo8.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightName8.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightChannel8.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightMax8.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightTest8.SetWindowPos(rctTab);
	

	rctTab.top = rctTab.bottom;
	rctTab.bottom = rctTab.top+nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_lightNo9.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightName9.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightChannel9.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightMax9.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightTest9.SetWindowPos(rctTab);
	

	rctTab.top = rctTab.bottom;
	rctTab.bottom = rctTab.top+nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_lightNo10.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightName10.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightChannel10.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightMax10.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightTest10.SetWindowPos(rctTab);
	

	rctTab.top = rctTab.bottom;
	rctTab.bottom = rctTab.top+nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_lightNo11.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightName11.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightChannel11.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightMax11.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightTest11.SetWindowPos(rctTab);
	

	rctTab.top = rctTab.bottom;
	rctTab.bottom = rctTab.top+nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_lightNo12.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightName12.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightChannel12.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightMax12.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightTest12.SetWindowPos(rctTab);

	
	rctTab.top = rctTab.bottom;
	rctTab.bottom = rctTab.top+nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_lightNo13.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightName13.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightChannel13.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightMax13.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightTest13.SetWindowPos(rctTab);

	
	rctTab.top = rctTab.bottom;
	rctTab.bottom = rctTab.top+nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_lightNo14.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightName14.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightChannel14.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightMax14.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightTest14.SetWindowPos(rctTab);

	
	rctTab.top = rctTab.bottom;
	rctTab.bottom = rctTab.top+nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_lightNo15.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightName15.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightChannel15.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightMax15.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightTest15.SetWindowPos(rctTab);

	
	rctTab.top = rctTab.bottom;
	rctTab.bottom = rctTab.top+nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_lightNo16.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightName16.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightChannel16.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightMax16.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightTest16.SetWindowPos(rctTab);

	
	rctTab.top = rctTab.bottom;
	rctTab.bottom = rctTab.top+nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_lightNo17.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightName17.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightChannel17.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightMax17.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightTest17.SetWindowPos(rctTab);

	
	rctTab.top = rctTab.bottom;
	rctTab.bottom = rctTab.top+nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_lightNo18.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightName18.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightChannel18.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightMax18.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightTest18.SetWindowPos(rctTab);

	
	rctTab.top = rctTab.bottom;
	rctTab.bottom = rctTab.top+nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_lightNo19.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightName19.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightChannel19.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightMax19.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightTest19.SetWindowPos(rctTab);


	rctTab.top = rctTab.bottom;
	rctTab.bottom = rctTab.top+nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_lightNo20.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightName20.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightChannel20.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightMax20.SetWindowPos(rctTab);

	rctTab.left = rctTab.right;
	rctTab.right = rctTab.left + nWidth;
	m_lightTest20.SetWindowPos(rctTab);
}