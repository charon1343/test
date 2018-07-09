// Dlg_MALight.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MN_VIS.h"
#include "Dlg_MALight.h"
#include "afxdialogex.h"


// CDlg_MALight 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_MALight, CDialogEx)

CDlg_MALight::CDlg_MALight(CWnd* pParent /*=NULL*/)
	: CMNVDialogEx(CDlg_MALight::IDD, pParent)
{

}

CDlg_MALight::~CDlg_MALight()
{
}

void CDlg_MALight::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_LightChannel, m_ctrlLightList);
}


BEGIN_MESSAGE_MAP(CDlg_MALight, CDialogEx)
	ON_BN_CLICKED(IDC_LIGHT_Test, &CDlg_MALight::OnBnClickedLightTest)
	ON_BN_CLICKED(IDC_LIGHT_Setting, &CDlg_MALight::OnBnClickedLightSetting)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_LightChannel, &CDlg_MALight::OnLvnItemchangedListLightchannel)
	ON_NOTIFY(NM_CLICK, IDC_LIST_LightChannel, &CDlg_MALight::OnNMClickListLightchannel)
END_MESSAGE_MAP()


// CDlg_MALight 메시지 처리기입니다.


void CDlg_MALight::OnBnClickedLightTest()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//LFine_LightSetting stLightCtrl;
	//GetSelectData(IDC_LIGHT_Port, stLightCtrl.strPort, 10);
	//stLightCtrl.dwBaudRate = GetSelectData(IDC_LIGHT_BaudRate, 19200);
	//stLightCtrl.bByteSize = GetSelectData(IDC_LIGHT_DataBits, 8);
	//stLightCtrl.bParity = GetSelectIndex(IDC_LIGHT_Parity);
	//stLightCtrl.bStopBit = GetSelectIndex(IDC_LIGHT_StopBits);
	//stLightCtrl.nPhysical = GetSelectIndex(IDC_LIGHT_Channel) + 1;

	//CMNV_LFineControl Light;
	//int nValue = GetItemData(IDC_LIGHT_Value, 100);
	//int nSleep = GetItemData(IDC_LIGHT_Sleep, 100);
	//Light.Init(stLightCtrl.strPort, stLightCtrl.dwBaudRate, stLightCtrl.bByteSize, stLightCtrl.bParity, stLightCtrl.bStopBit);
	//Light.AddSend(-1, 0);	Light.AddSend(1, nValue);	Light.Send();	Sleep(nSleep);
	//Light.AddSend(-1, 0);	Light.AddSend(2, nValue);	Light.Send();	Sleep(nSleep);
	//Light.AddSend(-1, 0);	Light.AddSend(3, nValue);	Light.Send();	Sleep(nSleep);
	//Light.AddSend(-1, 0);	Light.AddSend(4, nValue);	Light.Send();	Sleep(nSleep);
	//Light.AddSend(-1, 0);	Light.AddSend(5, nValue);	Light.Send();	Sleep(nSleep);
	//Light.AddSend(-1, 0);	Light.AddSend(6, nValue);	Light.Send();	Sleep(nSleep);
	//Light.AddSend(-1, 0);	Light.AddSend(7, nValue);	Light.Send();	Sleep(nSleep);
	//Light.AddSend(-1, 0);	Light.AddSend(8, nValue);	Light.Send();	Sleep(nSleep);
	//Light.AddSend(-1, 0);	Light.AddSend(9, nValue);	Light.Send();	Sleep(nSleep);
	//Light.AddSend(-1, 0);	Light.AddSend(10, nValue);	Light.Send();	Sleep(nSleep);
	//Light.AddSend(-1, 0);	Light.AddSend(11, nValue);	Light.Send();	Sleep(nSleep);
	//Light.AddSend(-1, 0);	Light.AddSend(12, nValue);	Light.Send();	Sleep(nSleep);
	//Light.AddSend(-1, 0);	Light.AddSend(13, nValue);	Light.Send();	Sleep(nSleep);
	//Light.AddSend(-1, 0);	Light.AddSend(14, nValue);	Light.Send();	Sleep(nSleep);
	//Light.AddSend(-1, 0);	Light.AddSend(15, nValue);	Light.Send();	Sleep(nSleep);
	//Light.AddSend(-1, 0);	Light.AddSend(16, nValue);	Light.Send();	Sleep(nSleep);
	//Light.AddSend(-1, 0);	Light.AddSend(17, nValue);	Light.Send();	Sleep(nSleep);
	//Light.AddSend(-1, 0);	Light.AddSend(18, nValue);	Light.Send();	Sleep(nSleep);
	//Light.AddSend(-1, 0);	Light.AddSend(19, nValue);	Light.Send();	Sleep(nSleep);
	//Light.AddSend(-1, 0);	Light.AddSend(20, nValue);	Light.Send();	Sleep(nSleep);

	//Light.AddSend(-1, 0);	Light.Send();	Sleep(nSleep);

	//Light.AddSend(-1, 0);	Light.AddSend(1, nValue);	Light.AddSend(2, nValue);	Light.AddSend(3, nValue);	Light.AddSend(4, nValue);	Light.Send();	Sleep(nSleep);
	//Light.AddSend(-1, 0);	Light.AddSend(5, nValue);	Light.AddSend(6, nValue);	Light.AddSend(7, nValue);	Light.AddSend(8, nValue);	Light.Send();	Sleep(nSleep);
	//Light.AddSend(-1, 0);	Light.AddSend(9, nValue);	Light.AddSend(10, nValue);	Light.AddSend(11, nValue);	Light.AddSend(12, nValue);	Light.Send();	Sleep(nSleep);
	//Light.AddSend(-1, 0);	Light.AddSend(13, nValue);	Light.AddSend(14, nValue);	Light.AddSend(15, nValue);	Light.AddSend(16, nValue);	Light.Send();	Sleep(nSleep);
	//Light.AddSend(-1, 0);	Light.AddSend(17, nValue);	Light.AddSend(18, nValue);	Light.AddSend(19, nValue);	Light.AddSend(20, nValue);	Light.Send();	Sleep(nSleep);

	//Light.AddSend(-1, 0);	Light.Send();	Sleep(nSleep);

	//Light.AddSend(-1, 0);	Light.AddSend(1, nValue);	Light.AddSend(5, nValue);	Light.AddSend(9, nValue);	Light.AddSend(13, nValue);	Light.AddSend(17, nValue);	Light.Send();	Sleep(nSleep);
	//Light.AddSend(-1, 0);	Light.AddSend(2, nValue);	Light.AddSend(6, nValue);	Light.AddSend(10, nValue);	Light.AddSend(14, nValue);	Light.AddSend(18, nValue);	Light.Send();	Sleep(nSleep);
	//Light.AddSend(-1, 0);	Light.AddSend(3, nValue);	Light.AddSend(7, nValue);	Light.AddSend(11, nValue);	Light.AddSend(15, nValue);	Light.AddSend(19, nValue);	Light.Send();	Sleep(nSleep);
	//Light.AddSend(-1, 0);	Light.AddSend(4, nValue);	Light.AddSend(8, nValue);	Light.AddSend(12, nValue);	Light.AddSend(16, nValue);	Light.AddSend(20, nValue);	Light.Send();	Sleep(nSleep);
	//Light.SendValue(-1, 0);
}


void CDlg_MALight::OnBnClickedLightSetting()
{
	//LFine_LightSetting Setting;
	//Setting.nChannel = GetItemData(IDC_LIGHT_Num, 0);
	//GetSelectData(IDC_LIGHT_Port, Setting.strPort, 10);
	//Setting.dwBaudRate = GetSelectData(IDC_LIGHT_BaudRate, 19200);
	//Setting.bByteSize = GetSelectData(IDC_LIGHT_DataBits, 8);
	//Setting.bParity = GetSelectIndex(IDC_LIGHT_Parity);
	//Setting.bStopBit = GetSelectIndex(IDC_LIGHT_StopBits);
	//Setting.nPhysical = GetSelectIndex(IDC_LIGHT_Channel) + 1;

	//m_ctrlLightList.SetItem(Setting.nChannel - 1, 0, Setting.nChannel);
	//m_ctrlLightList.SetItem(Setting.nChannel - 1, 1, Setting.strPort);
	//m_ctrlLightList.SetItem(Setting.nChannel - 1, 2, (int)Setting.dwBaudRate);
	//m_ctrlLightList.SetItem(Setting.nChannel - 1, 3, (int)Setting.bByteSize);
	//m_ctrlLightList.SetItem(Setting.nChannel - 1, 4, (int)Setting.bParity);
	//m_ctrlLightList.SetItem(Setting.nChannel - 1, 5, (int)Setting.bStopBit);
	//m_ctrlLightList.SetItem(Setting.nChannel - 1, 6, (int)Setting.nPhysical);
}


BOOL CDlg_MALight::OnInitDialog()
{
	CMNVDialogEx::OnInitDialog();

	//// TODO:  여기에 추가 초기화 작업을 추가합니다.
	//m_ctrlLightList.InsertColumn(0, _T("No"), 0, 50);
	//m_ctrlLightList.InsertColumn(1, _T("Port"), 0, 50);
	//m_ctrlLightList.InsertColumn(2, _T("Rate"), 0, 50);
	//m_ctrlLightList.InsertColumn(3, _T("Byte"), 0, 50);
	//m_ctrlLightList.InsertColumn(4, _T("Parity"), 0, 50);
	//m_ctrlLightList.InsertColumn(5, _T("Stop"), 0, 50);
	//m_ctrlLightList.InsertColumn(6, _T("Ch"), 0, 50);
	////LFine_LightSetting Setting;
	//CString strLightIni;
	//{
	//	wchar_t strBuf[1024];
	//	GetCurrentDirectory(1024, strBuf);
	//	strLightIni.Format(_T("%s\\Light.ini"), strBuf);
	//}
	//for(int nIndex = 0; nIndex < 20; ++nIndex) {
	//	Setting.SetChannel(nIndex + 1);
	//	Setting.Load(strLightIni, nIndex + 1);
	//	m_ctrlLightList.InsertEnd(100);
	//	m_ctrlLightList.SetItem(nIndex, 0, Setting.nChannel);
	//	m_ctrlLightList.SetItem(nIndex, 1, Setting.strPort);
	//	m_ctrlLightList.SetItem(nIndex, 2, (int)Setting.dwBaudRate);
	//	m_ctrlLightList.SetItem(nIndex, 3, (int)Setting.bByteSize);
	//	m_ctrlLightList.SetItem(nIndex, 4, (int)Setting.bParity);
	//	m_ctrlLightList.SetItem(nIndex, 5, (int)Setting.bStopBit);
	//	m_ctrlLightList.SetItem(nIndex, 6, (int)Setting.nPhysical);
	//}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlg_MALight::OnLvnItemchangedListLightchannel(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CDlg_MALight::OnNMClickListLightchannel(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//LFine_LightSetting Setting;
	//Setting.nChannel = m_ctrlLightList.GetItem(pNMItemActivate->iItem, 0, 0);
	//m_ctrlLightList.GetItem(pNMItemActivate->iItem, 1, Setting.strPort, 10);
	//Setting.dwBaudRate = m_ctrlLightList.GetItem(pNMItemActivate->iItem, 2, 0);
	//Setting.bByteSize = m_ctrlLightList.GetItem(pNMItemActivate->iItem, 3, 0);
	//Setting.bParity = m_ctrlLightList.GetItem(pNMItemActivate->iItem, 4, 0);
	//Setting.bStopBit = m_ctrlLightList.GetItem(pNMItemActivate->iItem, 5, 0);
	//Setting.nPhysical = m_ctrlLightList.GetItem(pNMItemActivate->iItem, 6, 0);

	////LFine_LightSetting stLightCtrl;
	//SetItemData(IDC_LIGHT_Num, Setting.nChannel);
	//SetSelectValue(IDC_LIGHT_Port, Setting.strPort);
	//SetSelectValue(IDC_LIGHT_BaudRate, Setting.dwBaudRate);
	//SetSelectValue(IDC_LIGHT_DataBits, Setting.bByteSize);
	//SetSelectIndex(IDC_LIGHT_Parity, Setting.bParity);
	//SetSelectIndex(IDC_LIGHT_StopBits, Setting.bStopBit);
	//SetSelectIndex(IDC_LIGHT_Channel, Setting.nPhysical - 1);
	*pResult = 0;
}
