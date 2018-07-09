#pragma once
#include "resource.h"

#include "Dlg_PADNumeric.h"
#include "MNVAlgorithm.h"

// CDlg_CtrlModel 대화 상자입니다.
struct STModel {
	int m_nModel;
	int m_nItem;
	int m_nVision;
};

class CDlg_CtrlModel : public CMNVDialogEx
{
	DECLARE_DYNAMIC(CDlg_CtrlModel)
	CMNVAlgorithm * m_pAlgorithm;
public:
	CDlg_CtrlModel(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_CtrlModel();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CTRL_MODEL };
	void Create(CMNVAlgorithm * __pAlgorithm, CWnd * __pWnd, CMNVDialogEx * __pParent) {
		m_pAlgorithm = __pAlgorithm;
		CMNVDialogEx::Create(IDD, __pWnd, __pParent);
	}

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	STModel m_stModel;
	virtual BOOL OnInitDialog();
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	afx_msg void OnBnClickedModelModelno() {
		int nTemp = 0;
		CString strTemp;
		if (InputInteger(nTemp)) {
			m_stModel.m_nModel = nTemp;
			strTemp.Format(_T("Model %02d"), m_stModel.m_nModel);
			SetItemData(IDC_MODEL_ModelNo, strTemp);
			m_pAlgorithm->Proc_LoadModel(m_stModel.m_nModel, m_stModel.m_nItem, m_stModel.m_nVision);
			m_pParent->OnCmd_Command(CMD_Reflash, 0, 0);
		}
		else {
		}
	}
	afx_msg void OnBnClickedModelItemno(){
		int nTemp = 0;
		CString strTemp;
		if (InputInteger(nTemp)) {
			m_stModel.m_nItem = nTemp;
			strTemp.Format(_T("Item %02d"), m_stModel.m_nItem);
			SetItemData(IDC_MODEL_ItemNo, strTemp);
			m_pAlgorithm->Proc_LoadModel(m_stModel.m_nModel, m_stModel.m_nItem, m_stModel.m_nVision);
			m_pParent->OnCmd_Command(CMD_Reflash, 0, 0);
		}
		else {
		}
	}
	afx_msg void OnBnClickedModelVisionno(){
		int nTemp = 0;
		CString strTemp;
		if (InputInteger(nTemp)) {
			m_stModel.m_nVision = nTemp;
			strTemp.Format(_T("Vision %02d"), m_stModel.m_nVision);
			SetItemData(IDC_MODEL_VisionNo, strTemp);
			m_pAlgorithm->Proc_LoadModel(m_stModel.m_nModel, m_stModel.m_nItem, m_stModel.m_nVision);
			m_pParent->OnCmd_Command(CMD_Reflash, 0, 0);
		}
		else {
		}
	}
	afx_msg void OnBnClickedModelLoad() {
		m_pAlgorithm->Proc_LoadModel(m_stModel.m_nModel, m_stModel.m_nItem, m_stModel.m_nVision);
		m_pParent->OnCmd_Command(CMD_Reflash, 0, 0);
	}
	afx_msg void OnBnClickedModelSave() {
		m_pAlgorithm->Proc_SaveModel();
		//m_pParent->OnCmd_Command(CMD_Model_Save, 0, (LPARAM)(&m_stModel));
	}

	bool InputInteger(int & __nValue) {
		CDlg_PADNumeric dlg(PAD_MDInteger);
		if(dlg.DoModal() == IDOK) {
			__nValue = (int)dlg.GetValue();
			return true;
		}
		return false;
	}

	void SetModel(int __nModel) {
		m_stModel.m_nModel = __nModel;
		CString strTemp;
		strTemp.Format(_T("Model %02d"), m_stModel.m_nModel);
		SetItemData(IDC_MODEL_ModelNo, strTemp);
	}
	void SetItem(int __nItem){
		m_stModel.m_nItem = __nItem;

		CString strTemp;
		strTemp.Format(_T("Item %02d"), m_stModel.m_nItem);
		SetItemData(IDC_MODEL_ItemNo, strTemp);
	}
	void SetVision(int __nVision){
		m_stModel.m_nVision = __nVision;
		CString strTemp;
		strTemp.Format(_T("Vision %02d"), m_stModel.m_nVision);
		SetItemData(IDC_MODEL_VisionNo, strTemp);
	}
	void InitControl(CMNVAlgorithm & __Algorithm) {
		SetModel(__Algorithm.m_PLC.GetCurrent_Model());
		SetItem(__Algorithm.m_PLC.GetCurrent_Item());
		SetVision(__Algorithm.m_PLC.GetCurrent_Vision());
	}

	void OnReflash() {
	}
};
