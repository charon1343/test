// Dlg_MAIOMap.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MN_VIS.h"
#include "Dlg_MAIOMap.h"
#include "afxdialogex.h"


// CDlg_MAIOMap 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_MAIOMap, CDialogEx)

CDlg_MAIOMap::CDlg_MAIOMap(CWnd* pParent /*=NULL*/)
	: CMNVDialogEx(CDlg_MAIOMap::IDD, pParent)
{

}

CDlg_MAIOMap::~CDlg_MAIOMap()
{
}

void CDlg_MAIOMap::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_MAIOMap, CDialogEx)
	ON_BN_CLICKED(IDC_IO_VisionModel, &CDlg_MAIOMap::OnBnClickedIoVisionmodel)
	ON_BN_CLICKED(IDC_CHECK18, &CDlg_MAIOMap::OnBnClickedCheck18)
END_MESSAGE_MAP()


// CDlg_MAIOMap 메시지 처리기입니다.


