#pragma once
#include "resource.h"
#include "MNVAlgorithm.h"
// CDlg_CtrlAlgorithm 대화 상자입니다.

#include "Dlg_CtrlAlign_CircleLine.h"
#include "Dlg_CtrlRegion_FindCircular.h"
#include "Dlg_CtrlBlobSetting.h"
#include "Dlg_CtrlBlob_Ignore.h"
#include "Dlg_CtrlBlob_Check.h"

#include "Dlg_Popup_Selector.h"

class CDlg_CtrlAlgorithm : public CMNVDialogEx
{
	CString m_pstrSelectAlgorithm[6];// = { _T("Select Algorithm"), _T("Algorithm 1"), _T("Algorithm 2"), _T("Algorithm 3"), _T("Algorithm 4"), _T("Algorithm 5") };
	DECLARE_DYNAMIC(CDlg_CtrlAlgorithm)
	CMNVAlgorithm * m_pAlgorithm;

	CDlg_CtrlAlign_CircleLine m_CtrlAlign_CircleLine;
	CDlg_CtrlRegion_FindCircular m_CtrlRegion_FindCircular;
	CDlg_CtrlBlobSetting m_CtrlBlob_Setting;
	CDlg_CtrlBlob_Check m_CtrlBlob_Inspect;
	CDlg_CtrlBlob_Ignore m_CtrlBlob_Ignore;
public:
	CString m_strAlgorithm[6];// = { _T("Select Algorithm"), _T("Algorithm 1"), _T("Algorithm 2"), _T("Algorithm 3"), _T("Algorithm 4"), _T("Algorithm 5") };
	CString m_strStep[6];// = { _T("Select Step"), _T("Align and Find Region"), _T("Detect Algorithm"), _T("Allow"), _T(""), _T("") };

	CDlg_CtrlAlgorithm(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_CtrlAlgorithm();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CTRL_ALGORITHM };
	void Create(CMNVAlgorithm * __pAlgorithm, CWnd * __pWnd, CMNVDialogEx * __pParent) {
		m_pAlgorithm = __pAlgorithm;
		CMNVDialogEx::Create(IDD, __pWnd, __pParent);
	}

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	void OnReflash() {
		if (0 <= m_nAlgorithm && m_nAlgorithm < 6) m_ctrlSelectAlgorithm.SetItemData(m_strAlgorithm[m_nAlgorithm]);
		if (0 <= m_nTab && m_nTab < 6) m_ctrlSelectTab.SetItemData(m_strStep[m_nTab]);

		switch(m_pAlgorithm->m_Model.m_cdType) {
			case MNV_AT_CircularCaliper:
				///m_ctrlSelectAlgorithm.SetItemData(_T("Circular Caliper"));
				m_ctrlStep[0].SetItemData(_T("Unwrap"), true, true, true);
				m_ctrlStep[1].SetItemData(_T("Caliper"), true, false, true);
				m_ctrlStep[2].SetItemData(_T("Ignore"), true, false, true);
				m_ctrlStep[3].SetItemData(_T("Allow"), true, false, true);
				break;
			case MNV_AT_RelativeHistogram:
				//m_ctrlSelectAlgorithm.SetItemData(_T("Relative Histogram"));
				m_ctrlStep[0].SetItemData(_T("Align"), true, true, true);
				m_ctrlStep[1].SetItemData(_T("Histogram"), true, false, true);
				m_ctrlStep[2].SetItemData(_T("Inspect"), true, false, true);
				m_ctrlStep[3].SetItemData(_T("null"), true, false, false);
				break;
			case MNV_AT_AffineCaliper:
				//m_ctrlSelectAlgorithm.SetItemData(_T("Affine Transform Caliper"));
				m_ctrlStep[0].SetItemData(_T("Processing"), true, true, true);
				m_ctrlStep[1].SetItemData(_T("Caliper"), true, false, true);
				m_ctrlStep[2].SetItemData(_T("Ignore"), true, false, true);
				m_ctrlStep[3].SetItemData(_T("Allow"), true, false, true);
				break;
			case MNV_AT_CircularBlob:
				//m_ctrlSelectAlgorithm.SetItemData(_T("Circular blob"));
				m_ctrlStep[0].SetItemData(_T("Region"), true, true, true);
				m_ctrlStep[1].SetItemData(_T("Blob"), true, false, true);
				m_ctrlStep[2].SetItemData(_T("Ignore"), true, false, true);
				m_ctrlStep[3].SetItemData(_T("Allow"), true, false, true);
				break;
			case MNV_AT_RectBlob:
				//m_ctrlSelectAlgorithm.SetItemData(_T("Affine Blob"));
				m_ctrlStep[0].SetItemData(_T("Align"), true, true, true);
				m_ctrlStep[1].SetItemData(_T("Blob"), true, false, true);
				m_ctrlStep[2].SetItemData(_T("Ignore"), true, false, true);
				m_ctrlStep[3].SetItemData(_T("Allow"), true, false, true);
				break;
			default:
				//m_ctrlSelectAlgorithm.SetItemData(_T("PASS"));
				m_ctrlStep[0].SetItemData(_T("Step1"), true, false, false);
				m_ctrlStep[1].SetItemData(_T("Step2"), true, false, false);
				m_ctrlStep[2].SetItemData(_T("Step3"), true, false, false);
				m_ctrlStep[3].SetItemData(_T("Step4"), true, false, false);
				break;
		}
	}
	int m_nAlgorithm;
	int m_nTab;

	afx_msg void OnBnClickedAlgSelectalgorithm() {
		CDlg_Popup_Selector Dlg;
		Dlg.m_strData = m_strAlgorithm;
		Dlg.m_nSelect = m_nAlgorithm;
		if (IDOK == Dlg.DoModal()) {
			m_nAlgorithm = Dlg.m_nSelect;
		}
		OnReflash();
		m_CtrlBlob_Setting.OnReflash();
		m_CtrlBlob_Ignore.OnReflash();
		m_CtrlBlob_Inspect.OnReflash();
	}
	afx_msg void OnBnClickedAlgSelecttab() {
		CDlg_Popup_Selector Dlg;
		Dlg.m_strData = m_strStep;
		Dlg.m_nSelect = m_nTab;
		if (IDOK == Dlg.DoModal()) {
			m_nTab = Dlg.m_nSelect;
		}
		OnReflash();
	}
	// 1: PolarUnwrap Caliper
	// 2: Relative Histogram
	// 3: Affine Transform Caliper 
	// 4: Circular blob
	// 5: Affine Blob
	// default: Pass
	CMNVButton m_ctrlSelectAlgorithm;
	CMNVButton m_ctrlSelectTab;
	CMNVButton m_ctrlStep[4];
	void OnTab_CheckTab(int __nIndex) {
		// 0 : No slelect;
		// 1 ~4;
		m_ctrlStep[0].SetItemCheck(__nIndex == 1);
		m_ctrlStep[1].SetItemCheck(__nIndex == 2);
		m_ctrlStep[2].SetItemCheck(__nIndex == 3);
		m_ctrlStep[3].SetItemCheck(__nIndex == 4);

		if (__nIndex == 1) {
			switch(m_pAlgorithm->m_Model.m_cdType) {
				case MNV_AT_CircularCaliper: break;
				case MNV_AT_RelativeHistogram: break;
				case MNV_AT_AffineCaliper: break;
				case MNV_AT_CircularBlob: m_CtrlRegion_FindCircular.ShowWindow(true); break;
				case MNV_AT_RectBlob: m_CtrlAlign_CircleLine.ShowWindow(true); break;
				default: break;
			}
		}
		else {
			m_CtrlAlign_CircleLine.ShowWindow(false);
			m_CtrlRegion_FindCircular.ShowWindow(false);
		}
		m_CtrlBlob_Setting.ShowWindow(__nIndex == 2);
		m_CtrlBlob_Ignore.ShowWindow(__nIndex == 3);
		m_CtrlBlob_Inspect.ShowWindow(__nIndex == 4);
	}
	afx_msg void OnBnClickedAlgStep1() { OnTab_CheckTab(1); }
	afx_msg void OnBnClickedAlgStep2() { OnTab_CheckTab(2); }
	afx_msg void OnBnClickedAlgStep3() { OnTab_CheckTab(3); }
	afx_msg void OnBnClickedAlgStep4() { OnTab_CheckTab(4); }
	virtual BOOL OnInitDialog();
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
};
