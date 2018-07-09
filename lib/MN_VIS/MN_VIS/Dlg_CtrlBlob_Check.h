#pragma once
#include "resource.h"
#include "MNVAlgorithm.h"
// CDlg_CtrlBlob_Check 대화 상자입니다.

class CDlg_CtrlBlob_Check : public CMNVDialogEx
{
	DECLARE_DYNAMIC(CDlg_CtrlBlob_Check)
	CMNVAlgorithm * m_pAlgorithm;

public:
	CDlg_CtrlBlob_Check(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_CtrlBlob_Check();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CTRL_BlobCheck };
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
	CMNVStatic m_ctrlLabel_CenterX;
	CMNVStatic m_ctrlLabel_CenterY;
	CMNVStatic m_ctrlLabel_Distance;
	CMNVStatic m_ctrlLabel_Width;
	CMNVButton m_ctrlSet_CenterX;
	CMNVButton m_ctrlSet_CenterY;
	CMNVButton m_ctrlSet_Distance;
	CMNVButton m_ctrlSet_Width;
	CMNVButton m_ctrlSet_CenterX2;
	CMNVButton m_ctrlSet_CenterY2;
	CMNVButton m_ctrlSet_Distance2;
	CMNVButton m_ctrlSet_Width2;

	void OnReflash() {
		switch( m_pAlgorithm->m_Model.m_cdType ) {
		case MNV_AT_CircularBlob:
			m_ctrlSet_CenterX.SetItemData(m_pAlgorithm->m_Model.m_InspectCircularBlob.m_stAllow[0].dCenterX);
			m_ctrlSet_CenterY.SetItemData(m_pAlgorithm->m_Model.m_InspectCircularBlob.m_stAllow[0].dCenterY);
			m_ctrlSet_Distance.SetItemData(m_pAlgorithm->m_Model.m_InspectCircularBlob.m_stAllow[0].dDistance);
			m_ctrlSet_Width.SetItemData(m_pAlgorithm->m_Model.m_InspectCircularBlob.m_stAllow[0].dWidth);

			m_ctrlSet_CenterX2.SetItemData(m_pAlgorithm->m_Model.m_InspectCircularBlob.m_stAllow[1].dCenterX);
			m_ctrlSet_CenterY2.SetItemData(m_pAlgorithm->m_Model.m_InspectCircularBlob.m_stAllow[1].dCenterY);
			m_ctrlSet_Distance2.SetItemData(m_pAlgorithm->m_Model.m_InspectCircularBlob.m_stAllow[1].dDistance);
			m_ctrlSet_Width2.SetItemData(m_pAlgorithm->m_Model.m_InspectCircularBlob.m_stAllow[1].dWidth);
			break;
		case MNV_AT_RectBlob:
			//m_ctrlSet_AreaMax.SetItemData(m_pAlgorithm->m_Model.m_InspectRectanbleBlob.m_dAreaMax);
			//m_ctrlSet_AreaMin.SetItemData(m_pAlgorithm->m_Model.m_InspectRectanbleBlob.m_dAreaMin);
			//m_ctrlSet_AreaRate.SetItemData(m_pAlgorithm->m_Model.m_InspectRectanbleBlob.m_dAreaRate);
		default:
			break;
		}
	}
};
