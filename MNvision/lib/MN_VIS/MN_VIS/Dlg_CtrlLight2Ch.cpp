// Dlg_CtrlLight2Ch.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Dlg_CtrlLight2Ch.h"
#include "afxdialogex.h"


// CDlg_CtrlLight2Ch ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlg_CtrlLight2Ch, CDialogEx)

CDlg_CtrlLight2Ch::CDlg_CtrlLight2Ch(CWnd* pParent /*=NULL*/)
	: CMNVDialogEx(CDlg_CtrlLight2Ch::IDD, pParent)
{
	m_pAlgorithm = NULL;
}

CDlg_CtrlLight2Ch::~CDlg_CtrlLight2Ch()
{
}

void CDlg_CtrlLight2Ch::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIGHT2CH_Ch1Label, m_ctrlLabel[0]);
	DDX_Control(pDX, IDC_LIGHT2CH_Ch2Label, m_ctrlLabel[1]);
	DDX_Control(pDX, IDC_LIGHT2CH_Ch3Label, m_ctrlLabel[2]);
	DDX_Control(pDX, IDC_LIGHT2CH_Ch4Label, m_ctrlLabel[3]);

	DDX_Control(pDX, IDC_LIGHT2CH_Ch1Value, m_ctrlValue[0]);
	DDX_Control(pDX, IDC_LIGHT2CH_Ch2Value, m_ctrlValue[1]);
	DDX_Control(pDX, IDC_LIGHT2CH_Ch3Value, m_ctrlValue[2]);
	DDX_Control(pDX, IDC_LIGHT2CH_Ch4Value, m_ctrlValue[3]);

	DDX_Control(pDX, IDC_LIGHT2CH_Ch1Add, m_ctrlBtnAdd[0]);
	DDX_Control(pDX, IDC_LIGHT2CH_Ch2Add, m_ctrlBtnAdd[1]);
	DDX_Control(pDX, IDC_LIGHT2CH_Ch3Add, m_ctrlBtnAdd[2]);
	DDX_Control(pDX, IDC_LIGHT2CH_Ch4Add, m_ctrlBtnAdd[3]);

	DDX_Control(pDX, IDC_LIGHT2CH_Ch1Sub, m_ctrlBtnSub[0]);
	DDX_Control(pDX, IDC_LIGHT2CH_Ch2Sub, m_ctrlBtnSub[1]);
	DDX_Control(pDX, IDC_LIGHT2CH_Ch3Sub, m_ctrlBtnSub[2]);
	DDX_Control(pDX, IDC_LIGHT2CH_Ch4Sub, m_ctrlBtnSub[3]);


	DDX_Control(pDX, IDC_LIGHT2CH_Step, m_ctrlValue_Step);

	DDX_Control(pDX, IDC_LIGHT2CH_Label, m_ctrlLabel_Step);
	//  DDX_Control(pDX, IDC_LIGHT2CH_Ch3Add, m_ctrlBtnSub_Ch3);
}


BEGIN_MESSAGE_MAP(CDlg_CtrlLight2Ch, CDialogEx)
	ON_WM_WINDOWPOSCHANGED()
	ON_BN_CLICKED(IDC_LIGHT2CH_Step, &CDlg_CtrlLight2Ch::OnBnClickedLight2chStep)
	ON_BN_CLICKED(IDC_LIGHT2CH_Ch1Value, &CDlg_CtrlLight2Ch::OnBnClickedLight2chCh1value)
	ON_BN_CLICKED(IDC_LIGHT2CH_Ch2Value, &CDlg_CtrlLight2Ch::OnBnClickedLight2chCh2value)
	ON_BN_CLICKED(IDC_LIGHT2CH_Ch1Sub, &CDlg_CtrlLight2Ch::OnBnClickedLight2chCh1sub)
	ON_BN_CLICKED(IDC_LIGHT2CH_Ch2Sub, &CDlg_CtrlLight2Ch::OnBnClickedLight2chCh2sub)
	ON_BN_CLICKED(IDC_LIGHT2CH_Ch1Add, &CDlg_CtrlLight2Ch::OnBnClickedLight2chCh1add)
	ON_BN_CLICKED(IDC_LIGHT2CH_Ch2Add, &CDlg_CtrlLight2Ch::OnBnClickedLight2chCh2add)
	ON_BN_CLICKED(IDC_LIGHT2CH_Ch3Sub, &CDlg_CtrlLight2Ch::OnBnClickedLight2chCh3sub)
	ON_BN_CLICKED(IDC_LIGHT2CH_Ch3Value, &CDlg_CtrlLight2Ch::OnBnClickedLight2chCh3value)
	ON_BN_CLICKED(IDC_LIGHT2CH_Ch3Add, &CDlg_CtrlLight2Ch::OnBnClickedLight2chCh3add)
	ON_BN_CLICKED(IDC_LIGHT2CH_Ch4Sub, &CDlg_CtrlLight2Ch::OnBnClickedLight2chCh4sub)
	ON_BN_CLICKED(IDC_LIGHT2CH_Ch4Value, &CDlg_CtrlLight2Ch::OnBnClickedLight2chCh4value)
	ON_BN_CLICKED(IDC_LIGHT2CH_Ch4Add, &CDlg_CtrlLight2Ch::OnBnClickedLight2chCh4add)
END_MESSAGE_MAP()


// CDlg_CtrlLight2Ch �޽��� ó�����Դϴ�.


BOOL CDlg_CtrlLight2Ch::OnInitDialog()
{
	CMNVDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	//m_ctrlLabel[0].SetItemData(_T("Pin Hole"));
	//m_ctrlLabel[1].SetItemData(_T("Drill Hole"));
	
	m_ctrlValue_Step.SetItemData(50);
	m_ctrlValue[0].SetItemData(0);
	m_ctrlValue[1].SetItemData(0);
	m_ctrlValue[2].SetItemData(0);
	m_ctrlValue[3].SetItemData(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CDlg_CtrlLight2Ch::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CMNVDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	int nMargin = 3;
	CRect rect;
	GetClientRect(&rect);
	rect.top += nMargin;
	rect.left += nMargin;
	//rect.bottom -= 5;
	//rect.right -= 5;
	
	int nHeight = rect.Height() / 6;
	int nTop[6];
	nTop[0] = rect.top;
	nTop[1] = nTop[0] + nHeight;
	nTop[2] = nTop[1] + nHeight;
	nTop[3] = nTop[2] + nHeight;
	nTop[4] = nTop[3] + nHeight;
	nHeight -= nMargin;
	nTop[5] = rect.bottom - nHeight;

	int nLeft[4];
	int nWidth = rect.Width() / 2;
	nLeft[0] = rect.left;
	nLeft[1] = rect.right - nWidth;
	nLeft[2] = nLeft[1] + 20;
	nLeft[3] = rect.right - 20;
	int nW[4];
	nW[0] = nLeft[1] - nLeft[0] - nMargin;
	nW[1] = nLeft[2] - nLeft[1] - nMargin;
	nW[2] = nLeft[3] - nLeft[2] - nMargin;
	nW[3] = 20 - nMargin;

	m_ctrlLabel_Step.SetWindowPos(nLeft[0], nTop[0], nW[0], nHeight);
	m_ctrlValue_Step.SetWindowPos(nLeft[2], nTop[0], nW[2], nHeight);

	m_ctrlLabel[0].SetWindowPos(nLeft[0], nTop[1], nW[0], nHeight);
	m_ctrlBtnSub[0].SetWindowPos(nLeft[1], nTop[1], nW[1], nHeight);
	m_ctrlValue[0].SetWindowPos(nLeft[2], nTop[1], nW[2], nHeight);
	m_ctrlBtnAdd[0].SetWindowPos(nLeft[3], nTop[1], nW[3], nHeight);

	m_ctrlLabel[1].SetWindowPos(nLeft[0], nTop[2], nW[0], nHeight);
	m_ctrlBtnSub[1].SetWindowPos(nLeft[1], nTop[2], nW[1], nHeight);
	m_ctrlValue[1].SetWindowPos(nLeft[2], nTop[2], nW[2], nHeight);
	m_ctrlBtnAdd[1].SetWindowPos(nLeft[3], nTop[2], nW[3], nHeight);

	m_ctrlLabel[2].SetWindowPos(nLeft[0], nTop[3], nW[0], nHeight);
	m_ctrlBtnSub[2].SetWindowPos(nLeft[1], nTop[3], nW[1], nHeight);
	m_ctrlValue[2].SetWindowPos(nLeft[2], nTop[3], nW[2], nHeight);
	m_ctrlBtnAdd[2].SetWindowPos(nLeft[3], nTop[3], nW[3], nHeight);

	m_ctrlLabel[3].SetWindowPos(nLeft[0], nTop[4], nW[0], nHeight);
	m_ctrlBtnSub[3].SetWindowPos(nLeft[1], nTop[4], nW[1], nHeight);
	m_ctrlValue[3].SetWindowPos(nLeft[2], nTop[4], nW[2], nHeight);
	m_ctrlBtnAdd[3].SetWindowPos(nLeft[3], nTop[4], nW[3], nHeight);

	//m_ctrlLabel_Ch3.SetWindowPos(nLeft[0], nTop[3], nW[0], nHeight);
	//m_ctrlBtnSub_Ch3.SetWindowPos(nLeft[1], nTop[3], nW[1], nHeight);
	//m_ctrlValue_Ch3.SetWindowPos(nLeft[2], nTop[3], nW[2], nHeight);
	//m_ctrlBtnAdd_Ch3.SetWindowPos(nLeft[3], nTop[3], nW[3], nHeight);

}


void CDlg_CtrlLight2Ch::OnBnClickedLight2chStep()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int nValue = 0;
	CDlg_PADNumeric Dlg(PAD_MDInteger);
	if (Dlg.DoModal() == IDOK) {
		nValue = (int)Dlg.GetValue();
		m_ctrlValue_Step.SetItemData(nValue);
	}

	//Reflash();
}

void CDlg_CtrlLight2Ch::OnBnClickedLight2chCh1value()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_pAlgorithm == NULL) return;
	int nValue = 0;
	CDlg_PADNumeric Dlg(PAD_MDInteger);
	if (Dlg.DoModal() == IDOK) {
		nValue = (int)Dlg.GetValue();
		m_pAlgorithm->m_DeviceLFine.SetValue(0, nValue);
		m_pAlgorithm->m_DeviceLFine.SendValue();
	}

	OnReflash();
}
void CDlg_CtrlLight2Ch::OnBnClickedLight2chCh2value()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_pAlgorithm == NULL) return;
	int nValue = 0;
	CDlg_PADNumeric Dlg(PAD_MDInteger);
	if (Dlg.DoModal() == IDOK) {
		nValue = (int)Dlg.GetValue();
		m_pAlgorithm->m_DeviceLFine.SetValue(1, nValue);
		m_pAlgorithm->m_DeviceLFine.SendValue();
	}

	OnReflash();
}
void CDlg_CtrlLight2Ch::OnBnClickedLight2chCh3value()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_pAlgorithm == NULL) return;
	int nValue = 0;
	CDlg_PADNumeric Dlg(PAD_MDInteger);
	if (Dlg.DoModal() == IDOK) {
		nValue = (int)Dlg.GetValue();
		m_pAlgorithm->m_DeviceLFine.SetValue(2, nValue);
		m_pAlgorithm->m_DeviceLFine.SendValue();
	}

	OnReflash();
}
void CDlg_CtrlLight2Ch::OnBnClickedLight2chCh4value()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_pAlgorithm == NULL) return;
	int nValue = 0;
	CDlg_PADNumeric Dlg(PAD_MDInteger);
	if (Dlg.DoModal() == IDOK) {
		nValue = (int)Dlg.GetValue();
		m_pAlgorithm->m_DeviceLFine.SetValue(3, nValue);
		m_pAlgorithm->m_DeviceLFine.SendValue();
	}

	OnReflash();
}

void CDlg_CtrlLight2Ch::OnBnClickedLight2chCh1sub()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_pAlgorithm == NULL) return;
	int nValue = m_ctrlValue_Step.GetItemData((int)0);
	m_pAlgorithm->m_DeviceLFine.SubValue(0, nValue);
	m_pAlgorithm->m_DeviceLFine.SendValue();

	OnReflash();
}
void CDlg_CtrlLight2Ch::OnBnClickedLight2chCh2sub()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_pAlgorithm == NULL) return;
	int nValue = m_ctrlValue_Step.GetItemData((int)0);
	m_pAlgorithm->m_DeviceLFine.SubValue(1, nValue);
	m_pAlgorithm->m_DeviceLFine.SendValue();

	OnReflash();
}
void CDlg_CtrlLight2Ch::OnBnClickedLight2chCh3sub()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_pAlgorithm == NULL) return;
	int nValue = m_ctrlValue_Step.GetItemData((int)0);
	m_pAlgorithm->m_DeviceLFine.SubValue(2, nValue);
	m_pAlgorithm->m_DeviceLFine.SendValue();

	OnReflash();
}
void CDlg_CtrlLight2Ch::OnBnClickedLight2chCh4sub()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_pAlgorithm == NULL) return;
	int nValue = m_ctrlValue_Step.GetItemData((int)0);
	m_pAlgorithm->m_DeviceLFine.SubValue(3, nValue);
	m_pAlgorithm->m_DeviceLFine.SendValue();

	OnReflash();
}

void CDlg_CtrlLight2Ch::OnBnClickedLight2chCh1add()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_pAlgorithm == NULL) return;
	int nValue = m_ctrlValue_Step.GetItemData((int)0);
	m_pAlgorithm->m_DeviceLFine.AddValue(0, nValue);
	m_pAlgorithm->m_DeviceLFine.SendValue();

	OnReflash();
}
void CDlg_CtrlLight2Ch::OnBnClickedLight2chCh2add()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_pAlgorithm == NULL) return;
	int nValue = m_ctrlValue_Step.GetItemData((int)0);
	m_pAlgorithm->m_DeviceLFine.AddValue(1, nValue);
	m_pAlgorithm->m_DeviceLFine.SendValue();

	OnReflash();
}
void CDlg_CtrlLight2Ch::OnBnClickedLight2chCh3add()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_pAlgorithm == NULL) return;
	int nValue = m_ctrlValue_Step.GetItemData((int)0);
	m_pAlgorithm->m_DeviceLFine.AddValue(2, nValue);
	m_pAlgorithm->m_DeviceLFine.SendValue();

	OnReflash();
}
void CDlg_CtrlLight2Ch::OnBnClickedLight2chCh4add()
{
	if (m_pAlgorithm == NULL) return;
	int nValue = m_ctrlValue_Step.GetItemData((int)0);
	m_pAlgorithm->m_DeviceLFine.AddValue(3, nValue);
	m_pAlgorithm->m_DeviceLFine.SendValue();

	OnReflash();
}
