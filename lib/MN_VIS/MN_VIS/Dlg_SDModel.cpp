// Dle_SDModel.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Dlg_SDModel.h"
#include "afxdialogex.h"


// CDle_SDModel ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlg_SDModel, CDialogEx)

CDlg_SDModel::CDlg_SDModel(CWnd* pParent /*=NULL*/)
	: CMNVDialogEx(CDlg_SDModel::IDD, pParent)
{
	m_pAlgorithm = NULL;
}

CDlg_SDModel::~CDlg_SDModel()
{
}

void CDlg_SDModel::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SDModel_Imaging, m_ctrlTab_Imaging);
	DDX_Control(pDX, IDC_SDModel_Algorithm, m_ctrlTab_Algorithm);
}


BEGIN_MESSAGE_MAP(CDlg_SDModel, CDialogEx)
	ON_WM_WINDOWPOSCHANGED()
	ON_BN_CLICKED(IDC_SDModel_Imaging, &CDlg_SDModel::OnBnClickedSdmodelImaging)
	ON_BN_CLICKED(IDC_SDModel_Algorithm, &CDlg_SDModel::OnBnClickedSdmodelAlgorithm)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// CDle_SDModel �޽��� ó�����Դϴ�.


BOOL CDlg_SDModel::OnInitDialog()
{
	CMNVDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_ctrlModel.Create(m_pAlgorithm, this, this);
	m_ctrlModel.ShowWindow(true);

	m_ctrlCamera.Create(m_pAlgorithm, this, this);
	m_ctrlCamera.ShowWindow(true);

	m_ctrlLight.Create(m_pAlgorithm, this, this);
	m_ctrlLight.ShowWindow(true);
	
	m_ctrlPattern.Create(m_ctrlPattern.IDD, this, this);
	m_ctrlPattern.ShowWindow(false);
	
	m_ctrlAlgorithm.Create(m_pAlgorithm, this, this);
	m_ctrlAlgorithm.ShowWindow(false);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CDlg_SDModel::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CMNVDialogEx::OnWindowPosChanged(lpwndpos);

	if ((lpwndpos->flags & SWP_NOSIZE) == 0) {
		CRect rect;
		GetClientRect(&rect);

		m_ctrlModel.SetWindowPos(rect.left, rect.top, rect.Width(), 200);
		{
			int left = rect.left;
			int top = rect.top + 205;
			int width = rect.Width();
			int height = 100;
			m_ctrlTab_Imaging.SetWindowPos(left + 5, top, 120, 40);
			m_ctrlTab_Algorithm.SetWindowPos(left + 126, top, 120, 40);
		}
		m_ctrlCamera.SetWindowPos(rect.left, rect.top + 245, rect.Width(), 100);
		m_ctrlLight.SetWindowPos(rect.left, rect.top + 345, rect.Width(), rect.Height() - 345);
		m_ctrlPattern.SetWindowPos(rect.left, rect.top + 345, rect.Width(), rect.Height() - 345);

		m_ctrlAlgorithm.SetWindowPos(rect.left, rect.top + 245, rect.Width(), rect.Height() - 245);
	}
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


void CDlg_SDModel::OnBnClickedSdmodelImaging()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ctrlTab_Imaging.SetCheck(true);
	m_ctrlTab_Algorithm.SetCheck(false);

	m_ctrlCamera.ShowWindow(true);
	m_ctrlLight.ShowWindow(true);
	
	m_ctrlAlgorithm.ShowWindow(false);
}


void CDlg_SDModel::OnBnClickedSdmodelAlgorithm()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ctrlTab_Imaging.SetCheck(false);
	m_ctrlTab_Algorithm.SetCheck(true);

	m_ctrlCamera.ShowWindow(false);
	m_ctrlLight.ShowWindow(false);
	
	m_ctrlAlgorithm.OnReflash();
	m_ctrlAlgorithm.ShowWindow(true);
}


void CDlg_SDModel::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CMNVDialogEx::OnShowWindow(bShow, nStatus);

	if (bShow == TRUE) {
		m_ctrlCamera.ShowWindow(true);
	}
	else {
		m_ctrlCamera.ShowWindow(false);
	}
}
