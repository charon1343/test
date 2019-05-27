#pragma once
#include "resource.h"
#include "MNVAlgorithm.h"
// CDlg_CtrlBlob_Ignore ��ȭ �����Դϴ�.

class CDlg_CtrlBlob_Ignore : public CMNVDialogEx
{
	DECLARE_DYNAMIC(CDlg_CtrlBlob_Ignore)
	CMNVAlgorithm * m_pAlgorithm;

public:
	CDlg_CtrlBlob_Ignore(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlg_CtrlBlob_Ignore();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CTRL_BlobIgnore };
	void Create(CMNVAlgorithm * __pAlgorithm, CWnd * __pWnd, CMNVDialogEx * __pParent) {
		m_pAlgorithm = __pAlgorithm;
		CMNVDialogEx::Create(IDD, __pWnd, __pParent);
	}

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	CMNVStatic m_ctrlLabel_AreaMax;
	CMNVStatic m_ctrlLabel_AreaMin;
	CMNVStatic m_ctrlLabel_AreaRate;
	CMNVButton m_ctrlSet_AreaMax;
	CMNVButton m_ctrlSet_AreaMin;
	CMNVButton m_ctrlSet_AreaRate;

	void OnReflash() {
		switch( m_pAlgorithm->m_Model.m_cdType ) {
		case MNV_AT_CircularBlob:
			m_ctrlSet_AreaMax.SetItemData(m_pAlgorithm->m_Model.m_InspectCircularBlob.m_dAreaMax);
			m_ctrlSet_AreaMin.SetItemData(m_pAlgorithm->m_Model.m_InspectCircularBlob.m_dAreaMin);
			m_ctrlSet_AreaRate.SetItemData(m_pAlgorithm->m_Model.m_InspectCircularBlob.m_dAreaRate);
			break;
		case MNV_AT_RectBlob:
			m_ctrlSet_AreaMax.SetItemData(m_pAlgorithm->m_Model.m_InspectRectanbleBlob.m_dAreaMax);
			m_ctrlSet_AreaMin.SetItemData(m_pAlgorithm->m_Model.m_InspectRectanbleBlob.m_dAreaMin);
			m_ctrlSet_AreaRate.SetItemData(m_pAlgorithm->m_Model.m_InspectRectanbleBlob.m_dAreaRate);
		default:
			break;
		}
	}
};
