#pragma once
#include "resource.h"
#include "MNVAlgorithm.h"
// CDlg_CtrlAlign_CircleLine ��ȭ �����Դϴ�.

class CDlg_CtrlAlign_CircleLine : public CMNVDialogEx
{
	DECLARE_DYNAMIC(CDlg_CtrlAlign_CircleLine)
	CMNVAlgorithm * m_pAlgorithm;

public:
	CDlg_CtrlAlign_CircleLine(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlg_CtrlAlign_CircleLine();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CTRL_AlignCircleLine };
	void Create(CMNVAlgorithm * __pAlgorithm, CWnd * __pWnd, CMNVDialogEx * __pParent) {
		m_pAlgorithm = __pAlgorithm;
		CMNVDialogEx::Create(IDD, __pWnd, __pParent);
	}

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
