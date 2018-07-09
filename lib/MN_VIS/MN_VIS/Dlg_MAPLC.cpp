// Dlg_MAPLC.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MN_VIS.h"
#include "Dlg_MAPLC.h"
#include "afxdialogex.h"


// CDlg_MAPLC 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_MAPLC, CDialogEx)

CDlg_MAPLC::CDlg_MAPLC(CWnd* pParent /*=NULL*/)
	: CMNVDialogEx(CDlg_MAPLC::IDD, pParent)
{

}

CDlg_MAPLC::~CDlg_MAPLC()
{
}

void CDlg_MAPLC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PLC_DataPLC, m_ctrlDataPLC);
	DDX_Control(pDX, IDC_PLC_DataPC, m_ctrlDataPC);
	DDX_Control(pDX, IDC_PLC_SetPC, m_ctrlSetPC);
	DDX_Control(pDX, IDC_PLC_SetPLC, m_ctrlSetPLC);
}


BEGIN_MESSAGE_MAP(CDlg_MAPLC, CDialogEx)
	ON_BN_CLICKED(IDC_PLC_Send, &CDlg_MAPLC::OnBnClickedPlcSend)
	ON_WM_DESTROY()
	ON_WM_WINDOWPOSCHANGED()
END_MESSAGE_MAP()


// CDlg_MAPLC 메시지 처리기입니다.


void CDlg_MAPLC::OnBnClickedPlcSend()
{

}


BOOL CDlg_MAPLC::OnInitDialog()
{
	CMNVDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	//CreateThread();
	m_DataMap_PC[0].SetAddress(10601, 0, 16);
	m_DataMap_PC[1].SetAddress(10601, 0, 1);
	m_DataMap_PC[2].SetAddress(10601, 1, 1);
	m_DataMap_PC[3].SetAddress(10601, 2, 1);
	m_DataMap_PC[4].SetAddress(10601, 3, 1);
	m_DataMap_PC[5].SetAddress(10601, 4, 1);
	m_DataMap_PC[6].SetAddress(10602, 0, 16);
	m_DataMap_PC[7].SetAddress(10603, 0, 32);
	m_DataMap_PC[8].SetAddress(10605, 0, 32);
	m_DataMap_PC[9].SetAddress(10607, 0, 32);
	m_DataMap_PC[10].SetAddress(10609, 0, 32);
	m_DataMap_PC[11].SetAddress(10611, 0, 32);
	m_DataMap_PC[12].SetAddress(10613, 0, 32);

	m_DataMap_PLC[0].SetAddress(10701, 0, 16);
	m_DataMap_PLC[1].SetAddress(10701, 0, 1);
	m_DataMap_PLC[2].SetAddress(10701, 1, 1);
	m_DataMap_PLC[3].SetAddress(10701, 2, 1);
	m_DataMap_PLC[4].SetAddress(10701, 3, 1);
	m_DataMap_PLC[5].SetAddress(10701, 4, 1);
	m_DataMap_PLC[6].SetAddress(10702, 0, 16);
	m_DataMap_PLC[7].SetAddress(10703, 0, 32);
	m_DataMap_PLC[8].SetAddress(10705, 0, 32);
	m_DataMap_PLC[9].SetAddress(10707, 0, 32);
	m_DataMap_PLC[10].SetAddress(10709, 0, 32);
	m_DataMap_PLC[11].SetAddress(10711, 0, 32);
	m_DataMap_PLC[12].SetAddress(10713, 0, 32);

	m_DataMap_PC[0];

	//CreateThread();
	m_ctrlDataPC.InsertColumn(0, _T("ADD"), 0, 150);
	m_ctrlDataPC.InsertColumn(1, _T("Name"), 0, 100);
	m_ctrlDataPC.InsertColumn(2, _T("Value"), 0, 100);

	CString strAddr;
	CString strName;
	for(int nIndex = 0; nIndex < 12; ++nIndex) {
		m_DataMap_PC[nIndex].GetString_Addr(strAddr);
		GetDataName_PC(m_DataMap_PC[0].m_nOffset, m_DataMap_PC[nIndex], strName);

		//;
		//m_ctrlDataPC.SetItem(nIndex, 0, strAddr);
		m_ctrlDataPC.SetItem(m_ctrlDataPC.InsertEnd(strAddr, 100), 1, strName);
	}


	m_ctrlDataPLC.InsertColumn(0, _T("ADD"), 0, 150);
	m_ctrlDataPLC.InsertColumn(1, _T("Name"), 0, 100);
	m_ctrlDataPLC.InsertColumn(2, _T("Value"), 0, 100);

	for(int nIndex = 0; nIndex < 12; ++nIndex) {
		m_DataMap_PLC[nIndex].GetString_Addr(strAddr);
		GetDataName_PLC(m_DataMap_PLC[0].m_nOffset, m_DataMap_PLC[nIndex], strName);
		
		//m_ctrlDataPLC.SetItem(nIndex, 0, strAddr);
		m_ctrlDataPLC.SetItem(m_ctrlDataPLC.InsertEnd(strAddr, 100), 1, strName);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlg_MAPLC::OnDestroy()
{
	CMNVDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	//EndThread();
}


void CDlg_MAPLC::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CMNVDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CRect rect;
	GetClientRect(&rect);

	CRect SubRect[2];
	SubRect[0] = rect;
	SubRect[1] = rect;

	SubRect[0].bottom = SubRect[0].top + SubRect[0].Height() / 2;
	SubRect[1].top = SubRect[0].bottom;

	PCMNVWnd pBtn[2];
	pBtn[0] = (PCMNVWnd)(&m_ctrlSetPC);
	pBtn[1] = (PCMNVWnd)(&m_ctrlSetPLC);
	PCMNVWnd pList[2];
	pList[0] = (PCMNVWnd)(&m_ctrlDataPC);
	pList[1] = (PCMNVWnd)(&m_ctrlDataPLC);

	for(int nIndex = 0; nIndex < 2; ++nIndex) {
		CRect rectButton = SubRect[nIndex];
		CRect rectList = SubRect[nIndex];
		rectButton.bottom = rectButton.top + 30;
		rectList.top = rectButton.bottom;
		pBtn[nIndex]->SetWindowPos(rectButton);
		pList[nIndex]->SetWindowPos(rectList);
	}
}
