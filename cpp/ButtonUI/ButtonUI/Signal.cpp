// Signal.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ButtonUI.h"
#include "Signal.h"
#include "afxdialogex.h"


// Signal 대화 상자입니다.

IMPLEMENT_DYNAMIC(Signal, CDialogEx)

Signal::Signal(CWnd* pParent /*=NULL*/)
	: CDialogEx(Signal::IDD, pParent)
{

}

Signal::~Signal()
{
}

void Signal::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SignalBit1, m_signalBit1);
	DDX_Control(pDX, IDC_SignalBit10, m_signalBit10);
	DDX_Control(pDX, IDC_SignalBit2, m_signalBit2);
	DDX_Control(pDX, IDC_SignalBit3, m_signalBit3);
	DDX_Control(pDX, IDC_SignalBit4, m_signalBit4);
	DDX_Control(pDX, IDC_SignalBit5, m_signalBit5);
	DDX_Control(pDX, IDC_SignalBit6, m_signalBit6);
	DDX_Control(pDX, IDC_SignalBit7, m_signalBit7);
	DDX_Control(pDX, IDC_SignalBit8, m_signalBit8);
	DDX_Control(pDX, IDC_SignalBit9, m_signalBit9);
	DDX_Control(pDX, IDC_SignalDestination, m_signalDestination);
	DDX_Control(pDX, IDC_SignalName1, m_signalName1);
	DDX_Control(pDX, IDC_SignalName10, m_signalName10);
	DDX_Control(pDX, IDC_SignalName2, m_signalName2);
	DDX_Control(pDX, IDC_SignalName3, m_signalName3);
	DDX_Control(pDX, IDC_SignalName4, m_signalName4);
	DDX_Control(pDX, IDC_SignalName5, m_signalName5);
	DDX_Control(pDX, IDC_SignalName6, m_signalName6);
	DDX_Control(pDX, IDC_SignalName7, m_signalName7);
	DDX_Control(pDX, IDC_SignalName8, m_signalName8);
	DDX_Control(pDX, IDC_SignalName9, m_signalName9);
	DDX_Control(pDX, IDC_SignalOffset1, m_signalOffset1);
	DDX_Control(pDX, IDC_SignalOffset10, m_signalOffset10);
	DDX_Control(pDX, IDC_SignalOffset2, m_signalOffset2);
	DDX_Control(pDX, IDC_SignalOffset3, m_signalOffset3);
	DDX_Control(pDX, IDC_SignalOffset4, m_signalOffset4);
	DDX_Control(pDX, IDC_SignalOffset5, m_signalOffset5);
	DDX_Control(pDX, IDC_SignalOffset6, m_signalOffset6);
	DDX_Control(pDX, IDC_SignalOffset7, m_signalOffset7);
	DDX_Control(pDX, IDC_SignalOffset8, m_signalOffset8);
	DDX_Control(pDX, IDC_SignalOffset9, m_signalOffset9);
	DDX_Control(pDX, IDC_SignalSegment, m_signalSegment);
	DDX_Control(pDX, IDC_SignalSegmentValue, m_signalSegmentValue);
	DDX_Control(pDX, IDC_SignalSize, m_signalSize);
	DDX_Control(pDX, IDC_SignalSizeValue, m_signalSizeValue);
	DDX_Control(pDX, IDC_SignalTitleBit, m_signalTitleBit);
	DDX_Control(pDX, IDC_SignalTitleName, m_signalTitleName);
	DDX_Control(pDX, IDC_SignalTitleOffset, m_signalTitleOffset);
	DDX_Control(pDX, IDC_SignalTitleType, m_signalTitleType);
	DDX_Control(pDX, IDC_SignalTitleValue, m_signalTitleValue);
	DDX_Control(pDX, IDC_SignalType1, m_signalType1);
	//  DDX_Control(pDX, IDC_SignalType10, m_signalType2);
	//  DDX_Control(pDX, IDC_SignalType2, m_signalType3);
	DDX_Control(pDX, IDC_SignalType10, m_signalType10);
	DDX_Control(pDX, IDC_SignalType2, m_signalType2);
	DDX_Control(pDX, IDC_SignalType3, m_signalType3);
	DDX_Control(pDX, IDC_SignalType4, m_signalType4);
	DDX_Control(pDX, IDC_SignalType5, m_signalType5);
	DDX_Control(pDX, IDC_SignalType6, m_signalType6);
	DDX_Control(pDX, IDC_SignalType7, m_signalType7);
	DDX_Control(pDX, IDC_SignalType8, m_signalType8);
	DDX_Control(pDX, IDC_SignalType9, m_signalType9);
	DDX_Control(pDX, IDC_SignalValue1, m_signalValue1);
	DDX_Control(pDX, IDC_SignalValue10, m_signalValue10);
	DDX_Control(pDX, IDC_SignalValue2, m_signalValue2);
	DDX_Control(pDX, IDC_SignalValue3, m_signalValue3);
	DDX_Control(pDX, IDC_SignalValue4, m_signalValue4);
	DDX_Control(pDX, IDC_SignalValue5, m_signalValue5);
	DDX_Control(pDX, IDC_SignalValue6, m_signalValue6);
	DDX_Control(pDX, IDC_SignalValue7, m_signalValue7);
	DDX_Control(pDX, IDC_SignalValue8, m_signalValue8);
	DDX_Control(pDX, IDC_SignalValue9, m_signalValue9);
}


BEGIN_MESSAGE_MAP(Signal, CDialogEx)
	ON_BN_CLICKED(IDC_SignalDestination, &Signal::OnBnClickedSignaldestination)
	ON_BN_CLICKED(IDC_SignalSegment, &Signal::OnBnClickedSignalsegment)
	ON_BN_CLICKED(IDC_SignalSegmentValue, &Signal::OnBnClickedSignalsegmentvalue)
	ON_BN_CLICKED(IDC_SignalSize, &Signal::OnBnClickedSignalsize)
	ON_BN_CLICKED(IDC_SignalSizeValue, &Signal::OnBnClickedSignalsizevalue)
	ON_BN_CLICKED(IDC_SignalTitleName, &Signal::OnBnClickedSignaltitlename)
	ON_BN_CLICKED(IDC_SignalTitleOffset, &Signal::OnBnClickedSignaltitleoffset)
	ON_BN_CLICKED(IDC_SignalTitleType, &Signal::OnBnClickedSignaltitletype)
	ON_BN_CLICKED(IDC_SignalTitleBit, &Signal::OnBnClickedSignaltitlebit)
	ON_BN_CLICKED(IDC_SignalTitleValue, &Signal::OnBnClickedSignaltitlevalue)
	ON_BN_CLICKED(IDC_SignalName1, &Signal::OnBnClickedSignalname1)
	ON_BN_CLICKED(IDC_SignalOffset1, &Signal::OnBnClickedSignaloffset1)
	ON_BN_CLICKED(IDC_SignalType1, &Signal::OnBnClickedSignaltype1)
	ON_BN_CLICKED(IDC_SignalBit1, &Signal::OnBnClickedSignalbit1)
	ON_BN_CLICKED(IDC_SignalValue1, &Signal::OnBnClickedSignalvalue1)
	ON_BN_CLICKED(IDC_SignalName2, &Signal::OnBnClickedSignalname2)
	ON_BN_CLICKED(IDC_SignalOffset2, &Signal::OnBnClickedSignaloffset2)
	ON_BN_CLICKED(IDC_SignalType2, &Signal::OnBnClickedSignaltype2)
	ON_BN_CLICKED(IDC_SignalBit2, &Signal::OnBnClickedSignalbit2)
	ON_BN_CLICKED(IDC_SignalValue2, &Signal::OnBnClickedSignalvalue2)
	ON_BN_CLICKED(IDC_SignalName3, &Signal::OnBnClickedSignalname3)
	ON_BN_CLICKED(IDC_SignalOffset3, &Signal::OnBnClickedSignaloffset3)
	ON_BN_CLICKED(IDC_SignalType3, &Signal::OnBnClickedSignaltype3)
	ON_BN_CLICKED(IDC_SignalBit3, &Signal::OnBnClickedSignalbit3)
	ON_BN_CLICKED(IDC_SignalValue3, &Signal::OnBnClickedSignalvalue3)
	ON_BN_CLICKED(IDC_SignalName4, &Signal::OnBnClickedSignalname4)
	ON_BN_CLICKED(IDC_SignalOffset4, &Signal::OnBnClickedSignaloffset4)
	ON_BN_CLICKED(IDC_SignalType4, &Signal::OnBnClickedSignaltype4)
	ON_BN_CLICKED(IDC_SignalBit4, &Signal::OnBnClickedSignalbit4)
	ON_BN_CLICKED(IDC_SignalValue4, &Signal::OnBnClickedSignalvalue4)
	ON_BN_CLICKED(IDC_SignalName5, &Signal::OnBnClickedSignalname5)
	ON_BN_CLICKED(IDC_SignalOffset5, &Signal::OnBnClickedSignaloffset5)
	ON_BN_CLICKED(IDC_SignalType5, &Signal::OnBnClickedSignaltype5)
	ON_BN_CLICKED(IDC_SignalBit5, &Signal::OnBnClickedSignalbit5)
	ON_BN_CLICKED(IDC_SignalValue5, &Signal::OnBnClickedSignalvalue5)
	ON_BN_CLICKED(IDC_SignalName6, &Signal::OnBnClickedSignalname6)
	ON_BN_CLICKED(IDC_SignalOffset6, &Signal::OnBnClickedSignaloffset6)
	ON_BN_CLICKED(IDC_SignalType6, &Signal::OnBnClickedSignaltype6)
	ON_BN_CLICKED(IDC_SignalBit6, &Signal::OnBnClickedSignalbit6)
	ON_BN_CLICKED(IDC_SignalValue6, &Signal::OnBnClickedSignalvalue6)
	ON_BN_CLICKED(IDC_SignalName7, &Signal::OnBnClickedSignalname7)
	ON_BN_CLICKED(IDC_SignalOffset7, &Signal::OnBnClickedSignaloffset7)
	ON_BN_CLICKED(IDC_SignalType7, &Signal::OnBnClickedSignaltype7)
	ON_BN_CLICKED(IDC_SignalBit7, &Signal::OnBnClickedSignalbit7)
	ON_BN_CLICKED(IDC_SignalValue7, &Signal::OnBnClickedSignalvalue7)
	ON_BN_CLICKED(IDC_SignalName8, &Signal::OnBnClickedSignalname8)
	ON_BN_CLICKED(IDC_SignalOffset8, &Signal::OnBnClickedSignaloffset8)
	ON_BN_CLICKED(IDC_SignalType8, &Signal::OnBnClickedSignaltype8)
	ON_BN_CLICKED(IDC_SignalBit8, &Signal::OnBnClickedSignalbit8)
	ON_BN_CLICKED(IDC_SignalValue8, &Signal::OnBnClickedSignalvalue8)
	ON_BN_CLICKED(IDC_SignalName9, &Signal::OnBnClickedSignalname9)
	ON_BN_CLICKED(IDC_SignalOffset9, &Signal::OnBnClickedSignaloffset9)
	ON_BN_CLICKED(IDC_SignalType9, &Signal::OnBnClickedSignaltype9)
	ON_BN_CLICKED(IDC_SignalBit9, &Signal::OnBnClickedSignalbit9)
	ON_BN_CLICKED(IDC_SignalValue9, &Signal::OnBnClickedSignalvalue9)
	ON_BN_CLICKED(IDC_SignalName10, &Signal::OnBnClickedSignalname10)
	ON_BN_CLICKED(IDC_SignalOffset10, &Signal::OnBnClickedSignaloffset10)
	ON_BN_CLICKED(IDC_SignalType10, &Signal::OnBnClickedSignaltype10)
	ON_BN_CLICKED(IDC_SignalBit10, &Signal::OnBnClickedSignalbit10)
	ON_BN_CLICKED(IDC_SignalValue10, &Signal::OnBnClickedSignalvalue10)
	ON_WM_WINDOWPOSCHANGED()
END_MESSAGE_MAP()


// Signal 메시지 처리기입니다.


void Signal::OnBnClickedSignaldestination()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalsegment()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalsegmentvalue()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalsize()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalsizevalue()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignaltitlename()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignaltitleoffset()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignaltitletype()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignaltitlebit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignaltitlevalue()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalname1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignaloffset1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignaltype1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalbit1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalvalue1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalname2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignaloffset2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignaltype2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalbit2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalvalue2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalname3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignaloffset3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignaltype3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalbit3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalvalue3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalname4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignaloffset4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignaltype4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalbit4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalvalue4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalname5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignaloffset5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignaltype5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalbit5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalvalue5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalname6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignaloffset6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignaltype6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalbit6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalvalue6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalname7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignaloffset7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignaltype7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalbit7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalvalue7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalname8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignaloffset8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignaltype8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalbit8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalvalue8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalname9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignaloffset9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignaltype9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalbit9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalvalue9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalname10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignaloffset10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignaltype10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalbit10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::OnBnClickedSignalvalue10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Signal::On_WindBottomPos(void)
{
	CRect rctBottom;
	GetClientRect(&rctBottom);

	rctBottom.top += 5;
	rctBottom.left += 5;
	rctBottom.bottom -= 5;
	rctBottom.right -= 5;

	CRect rctTab = rctBottom;

	int nWidth = (rctBottom.Width() + 1) / 5;
	int nHeight = (rctBottom.Height() + 1) / 15;

	rctTab.bottom = rctBottom.top+nHeight;
	rctTab.right = rctBottom.left+nWidth*5+4;
	m_signalDestination.SetWindowPos(rctTab);

	rctTab.top = rctTab.bottom + 1;
	rctTab.bottom = rctTab.top + nHeight;
	rctTab.right = rctTab.left+nWidth*2+1;
	m_signalSegment.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth*3+1;
	m_signalSegmentValue.SetWindowPos(rctTab);

	rctTab.top = rctTab.bottom + 1;
	rctTab.bottom = rctTab.top + nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth*2+1;
	m_signalSize.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth*3+1;
	m_signalSizeValue.SetWindowPos(rctTab);



	rctTab.top = rctTab.bottom + 10;
	rctTab.bottom = rctTab.top + nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_signalTitleName.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalTitleOffset.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalTitleType.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalTitleBit.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalTitleValue.SetWindowPos(rctTab);


	rctTab.top = rctTab.bottom + 1;
	rctTab.bottom = rctTab.top + nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_signalName1.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalOffset1.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalType1.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalBit1.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalValue1.SetWindowPos(rctTab);

	rctTab.top = rctTab.bottom + 1;
	rctTab.bottom = rctTab.top + nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_signalName2.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalOffset2.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalType2.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalBit2.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalValue2.SetWindowPos(rctTab);

	rctTab.top = rctTab.bottom + 1;
	rctTab.bottom = rctTab.top + nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_signalName3.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalOffset3.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalType3.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalBit3.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalValue3.SetWindowPos(rctTab);

	rctTab.top = rctTab.bottom + 1;
	rctTab.bottom = rctTab.top + nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_signalName4.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalOffset4.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalType4.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalBit4.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalValue4.SetWindowPos(rctTab);

	rctTab.top = rctTab.bottom + 1;
	rctTab.bottom = rctTab.top + nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_signalName5.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalOffset5.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalType5.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalBit5.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalValue5.SetWindowPos(rctTab);

	rctTab.top = rctTab.bottom + 1;
	rctTab.bottom = rctTab.top + nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_signalName6.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalOffset6.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalType6.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalBit6.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalValue6.SetWindowPos(rctTab);

	rctTab.top = rctTab.bottom + 1;
	rctTab.bottom = rctTab.top + nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_signalName7.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalOffset7.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalType7.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalBit7.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalValue7.SetWindowPos(rctTab);

	rctTab.top = rctTab.bottom + 1;
	rctTab.bottom = rctTab.top + nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_signalName8.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalOffset8.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalType8.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalBit8.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalValue8.SetWindowPos(rctTab);

	rctTab.top = rctTab.bottom + 1;
	rctTab.bottom = rctTab.top + nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_signalName9.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalOffset9.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalType9.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalBit9.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalValue9.SetWindowPos(rctTab);

	rctTab.top = rctTab.bottom + 1;
	rctTab.bottom = rctTab.top + nHeight;
	rctTab.left = rctBottom.left;
	rctTab.right = rctTab.left+nWidth;
	m_signalName10.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalOffset10.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalType10.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalBit10.SetWindowPos(rctTab);

	rctTab.left = rctTab.right+1;
	rctTab.right = rctTab.left+nWidth;
	m_signalValue10.SetWindowPos(rctTab);
}



BOOL Signal::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	On_WindBottomPos();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void Signal::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if ((lpwndpos->flags & SWP_NOSIZE) == 0) { On_WindBottomPos();}

}

