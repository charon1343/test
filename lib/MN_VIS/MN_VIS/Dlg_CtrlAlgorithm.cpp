// Dlg_CtrlAlgorithm.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Dlg_CtrlAlgorithm.h"
#include "afxdialogex.h"


// CDlg_CtrlAlgorithm 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_CtrlAlgorithm, CDialogEx)

CDlg_CtrlAlgorithm::CDlg_CtrlAlgorithm(CWnd* pParent /*=NULL*/)
	: CMNVDialogEx(CDlg_CtrlAlgorithm::IDD, pParent)
{
	m_strAlgorithm[0] = _T("Select Algorithm");
	m_strAlgorithm[1] = _T("Algorithm 1");
	m_strAlgorithm[2] = _T("Algorithm 2");
	m_strAlgorithm[3] = _T("Algorithm 3");
	m_strAlgorithm[4] = _T("Algorithm 4");
	m_strAlgorithm[5] = _T("Algorithm 5");

	m_strStep[0] = _T("Select Step");
	m_strStep[1] = _T("Align and Find Region");
	m_strStep[2] = _T("Detect Algorithm");
	m_strStep[3] = _T("Allow");
	m_strStep[4] = _T("");
	m_strStep[5] = _T("");
}

CDlg_CtrlAlgorithm::~CDlg_CtrlAlgorithm()
{
}

void CDlg_CtrlAlgorithm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ALG_SelectAlgorithm, m_ctrlSelectAlgorithm);
	DDX_Control(pDX, IDC_ALG_Step1, m_ctrlStep[0]);
	DDX_Control(pDX, IDC_ALG_Step2, m_ctrlStep[1]);
	DDX_Control(pDX, IDC_ALG_Step3, m_ctrlStep[2]);
	DDX_Control(pDX, IDC_ALG_Step4, m_ctrlStep[3]);
	DDX_Control(pDX, IDC_ALG_SelectTab, m_ctrlSelectTab);
}


BEGIN_MESSAGE_MAP(CDlg_CtrlAlgorithm, CDialogEx)
	ON_BN_CLICKED(IDC_ALG_SelectAlgorithm, &CDlg_CtrlAlgorithm::OnBnClickedAlgSelectalgorithm)
	ON_BN_CLICKED(IDC_ALG_Step1, &CDlg_CtrlAlgorithm::OnBnClickedAlgStep1)
	ON_BN_CLICKED(IDC_ALG_Step2, &CDlg_CtrlAlgorithm::OnBnClickedAlgStep2)
	ON_BN_CLICKED(IDC_ALG_Step3, &CDlg_CtrlAlgorithm::OnBnClickedAlgStep3)
	ON_BN_CLICKED(IDC_ALG_Step4, &CDlg_CtrlAlgorithm::OnBnClickedAlgStep4)
	ON_WM_WINDOWPOSCHANGED()
	ON_BN_CLICKED(IDC_ALG_SelectTab, &CDlg_CtrlAlgorithm::OnBnClickedAlgSelecttab)
END_MESSAGE_MAP()


// CDlg_CtrlAlgorithm 메시지 처리기입니다.


BOOL CDlg_CtrlAlgorithm::OnInitDialog()
{
	CMNVDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_CtrlAlign_CircleLine.Create(m_pAlgorithm, this, this);
	m_CtrlRegion_FindCircular.Create(m_pAlgorithm, this, this);
	m_CtrlBlob_Setting.Create(m_pAlgorithm, this, this);
	m_CtrlBlob_Inspect.Create(m_pAlgorithm, this, this);
	m_CtrlBlob_Ignore.Create(m_pAlgorithm, this, this);

	OnTab_CheckTab(4);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlg_CtrlAlgorithm::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CMNVDialogEx::OnWindowPosChanged(lpwndpos);

	if ((lpwndpos->flags & SWP_NOSIZE) == 0) {
		CRect rctCurrent;
		GetClientRect(&rctCurrent);
		rctCurrent.left += 5;
		rctCurrent.top += 5;
		rctCurrent.right -= 5;
		rctCurrent.bottom -= 5;

		{
			int nBtnHeight = 40;
			CRect rctSlectAlgorithm = rctCurrent;
			rctSlectAlgorithm.bottom = rctSlectAlgorithm.top + nBtnHeight;
			rctCurrent.top = rctSlectAlgorithm.bottom + 5;

			CRect rctSelectTab = rctCurrent;
			rctSelectTab.bottom = rctSelectTab.top + nBtnHeight;
			rctCurrent.top = rctSelectTab.bottom + 5;

			CRect rctSubControl = rctCurrent;

			m_ctrlSelectAlgorithm.SetWindowPos(rctSlectAlgorithm);
			{
				int nInterval = 2;
				int nWidth = (rctSelectTab.Width() + nInterval) / 4 - nInterval;
				rctSelectTab.right = rctSelectTab.left + nWidth;
				m_ctrlStep[0].SetWindowPos(rctSelectTab);

				rctSelectTab.left = rctSelectTab.right + nInterval;
				rctSelectTab.right = rctSelectTab.left + nWidth;
				m_ctrlStep[1].SetWindowPos(rctSelectTab);

				rctSelectTab.left = rctSelectTab.right + nInterval;
				rctSelectTab.right = rctSelectTab.left + nWidth;
				m_ctrlStep[2].SetWindowPos(rctSelectTab);

				rctSelectTab.left = rctSelectTab.right + nInterval;
				rctSelectTab.right = rctSelectTab.left + nWidth;
				m_ctrlStep[3].SetWindowPos(rctSelectTab);
			}
			m_CtrlAlign_CircleLine.SetWindowPos(rctCurrent);
			m_CtrlRegion_FindCircular.SetWindowPos(rctCurrent);
			m_CtrlBlob_Setting.SetWindowPos(rctCurrent);
			m_CtrlBlob_Inspect.SetWindowPos(rctCurrent);
			m_CtrlBlob_Ignore.SetWindowPos(rctCurrent);
		}
	}
}
