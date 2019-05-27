#pragma once
#include "resource.h"
#include "MNVAlgorithm.h"
// CDlg_CtrlRegion_FindCircular 대화 상자입니다.

class CDlg_CtrlRegion_FindCircular : public CMNVDialogEx
{
	DECLARE_DYNAMIC(CDlg_CtrlRegion_FindCircular)
	CMNVAlgorithm * m_pAlgorithm;

public:
	CDlg_CtrlRegion_FindCircular(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_CtrlRegion_FindCircular();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CTRL_FindRegion_Circular };
	void Create(CMNVAlgorithm * __pAlgorithm, CWnd * __pWnd, CMNVDialogEx * __pParent) {
		m_pAlgorithm = __pAlgorithm;
		CMNVDialogEx::Create(IDD, __pWnd, __pParent);
	}

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
};
