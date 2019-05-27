#pragma once
#include "resource.h"
#include "MNVAlgorithm.h"

// CDlg_CtrlBlobSetting 대화 상자입니다.

class CDlg_CtrlBlobSetting : public CMNVDialogEx
{
	DECLARE_DYNAMIC(CDlg_CtrlBlobSetting)
	CMNVAlgorithm * m_pAlgorithm;
public:
	CDlg_CtrlBlobSetting(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_CtrlBlobSetting();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CTRL_BlobSetting };
	void Create(CMNVAlgorithm * __pAlgorithm, CWnd * __pWnd, CMNVDialogEx * __pParent) {
		m_pAlgorithm = __pAlgorithm;
		CMNVDialogEx::Create(IDD, __pWnd, __pParent);
	}
	CMNVStatic m_ctrlLabel_Mode;
	CMNVStatic m_ctrlLabel_Polarity;
	CMNVStatic m_ctrlLabel_Softness;
	CMNVStatic m_ctrlLabel_TailHigh;
	CMNVStatic m_ctrlLabel_TailLow;
	CMNVStatic m_ctrlLabel_ThresholdHigh;
	CMNVStatic m_ctrlLabel_ThresholdLow;
	CMNVButton m_ctrlSet_Mode;
	CMNVButton m_ctrlSet_Polarity;
	CMNVButton m_ctrlSet_Softness;
	CMNVButton m_ctrlSet_TailHigh;
	CMNVButton m_ctrlSet_TailLow;
	CMNVButton m_ctrlSet_ThresholdHigh;
	CMNVButton m_ctrlSet_ThresholdLow;

	//CMNVButton m_ctrlSet_Mode2;
	CMNVButton m_ctrlSet_Polarity2;
	CMNVButton m_ctrlSet_Softness2;
	CMNVButton m_ctrlSet_TailHigh2;
	CMNVButton m_ctrlSet_TailLow2;
	CMNVButton m_ctrlSet_ThresholdHigh2;
	CMNVButton m_ctrlSet_ThresholdLow2;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);

	void Reflash_HardFixed(CMNVBlob_Algorithm & __Blob, CMNVBlob_Algorithm & __Blob2) {
		m_ctrlLabel_Mode.InitStatic(_T("Mode"), true);
		m_ctrlSet_Mode.SetItemData(_T("Hard Fixed"), true, false, true);

		m_ctrlLabel_Polarity.InitStatic(_T("Polarity"), true);
		m_ctrlSet_Polarity.SetItemData(__Blob.GetHardFixed_Polarity() == cogBlobSegmentationPolarityLightBlobs ? _T("Light Blob") : _T("Dark Blob"), true, false, true);
		m_ctrlSet_Polarity2.SetItemData(__Blob2.GetHardFixed_Polarity() == cogBlobSegmentationPolarityLightBlobs ? _T("Light Blob") : _T("Dark Blob"), true, false, true);

		m_ctrlLabel_Softness.InitStatic(_T("Softness"), false);
		m_ctrlSet_Softness.SetItemData(_T(""), false, false, false);
		m_ctrlSet_Softness2.SetItemData(_T(""), false, false, false);

		m_ctrlLabel_TailHigh.InitStatic(_T("Tail High"), false);
		m_ctrlSet_TailHigh.SetItemData(_T(""), false, false, false);
		m_ctrlSet_TailHigh2.SetItemData(_T(""), false, false, false);

		m_ctrlLabel_TailLow.InitStatic(_T("Tail Low"), false);
		m_ctrlSet_TailLow.SetItemData(_T(""), false, false, false);
		m_ctrlSet_TailLow2.SetItemData(_T(""), false, false, false);

		m_ctrlLabel_ThresholdLow.InitStatic(_T("Threshold"), true);
		m_ctrlSet_ThresholdLow.SetItemData(__Blob.GetHardFixed_Threshold(), true, false, true);
		m_ctrlSet_ThresholdLow2.SetItemData(__Blob2.GetHardFixed_Threshold(), true, false, true);

		m_ctrlLabel_ThresholdHigh.InitStatic(_T("Threshold"), false);
		m_ctrlSet_ThresholdHigh.SetItemData(_T(""), false, false, false);
		m_ctrlSet_ThresholdHigh2.SetItemData(_T(""), false, false, false);
	}
	void Reflash_HardRelative(CMNVBlob_Algorithm & __Blob, CMNVBlob_Algorithm & __Blob2) {
		m_ctrlLabel_Mode.InitStatic(_T("Mode"), true);
		m_ctrlSet_Mode.SetItemData(_T("Hard Relative"), true, false, true);

		m_ctrlLabel_Polarity.InitStatic(_T("Polarity"), true);
		m_ctrlSet_Polarity.SetItemData(__Blob.GetHardRelative_Polarity() == cogBlobSegmentationPolarityLightBlobs ? _T("Light Blob") : _T("Dark Blob"), true, false, true);
		m_ctrlSet_Polarity2.SetItemData(__Blob2.GetHardRelative_Polarity() == cogBlobSegmentationPolarityLightBlobs ? _T("Light Blob") : _T("Dark Blob"), true, false, true);

		m_ctrlLabel_Softness.InitStatic(_T("Softness"), false);
		m_ctrlSet_Softness.SetItemData(_T(""), false, false, false);
		m_ctrlSet_Softness2.SetItemData(_T(""), false, false, false);

		m_ctrlLabel_TailHigh.InitStatic(_T("Tail High"), true);
		m_ctrlSet_TailHigh.SetItemData(__Blob.GetHardRelative_TailHigh(), true, false, true);
		m_ctrlSet_TailHigh2.SetItemData(__Blob2.GetHardRelative_TailHigh(), true, false, true);

		m_ctrlLabel_TailLow.InitStatic(_T("Tail Low"), true);
		m_ctrlSet_TailLow.SetItemData(__Blob.GetHardRelative_TailLow(), true, false, true);
		m_ctrlSet_TailLow2.SetItemData(__Blob2.GetHardRelative_TailLow(), true, false, true);

		m_ctrlLabel_ThresholdLow.InitStatic(_T("Threshold"), true);
		m_ctrlSet_ThresholdLow.SetItemData(__Blob.GetHardRelative_Threshold(), true, false, true);
		m_ctrlSet_ThresholdLow2.SetItemData(__Blob2.GetHardRelative_Threshold(), true, false, true);

		m_ctrlLabel_ThresholdHigh.InitStatic(_T("Threshold"), false);
		m_ctrlSet_ThresholdHigh.SetItemData(_T(""), false, false, false);
		m_ctrlSet_ThresholdHigh2.SetItemData(_T(""), false, false, false);
	}
	void Reflash_HardDynamic(CMNVBlob_Algorithm & __Blob, CMNVBlob_Algorithm & __Blob2) {
		m_ctrlLabel_Mode.InitStatic(_T("Mode"), true);
		m_ctrlSet_Mode.SetItemData(_T("Hard Dynamic"), true, false, true);

		m_ctrlLabel_Polarity.InitStatic(_T("Polarity"), true);
		m_ctrlSet_Polarity.SetItemData(__Blob.GetHardDynamic_Polarity() == cogBlobSegmentationPolarityLightBlobs ? _T("Light Blob") : _T("Dark Blob"), true, false, true);
		m_ctrlSet_Polarity2.SetItemData(__Blob2.GetHardDynamic_Polarity() == cogBlobSegmentationPolarityLightBlobs ? _T("Light Blob") : _T("Dark Blob"), true, false, true);

		m_ctrlLabel_Softness.InitStatic(_T("Softness"), false);
		m_ctrlSet_Softness.SetItemData(_T(""), false, false, false);
		m_ctrlSet_Softness2.SetItemData(_T(""), false, false, false);

		m_ctrlLabel_TailHigh.InitStatic(_T("Tail High"), true);
		m_ctrlSet_TailHigh.SetItemData(__Blob.GetHardDynamic_TailHigh(), true, false, true);
		m_ctrlSet_TailHigh2.SetItemData(__Blob2.GetHardDynamic_TailHigh(), true, false, true);

		m_ctrlLabel_TailLow.InitStatic(_T("Tail Low"), true);
		m_ctrlSet_TailLow.SetItemData(__Blob.GetHardDynamic_TailLow(), true, false, true);
		m_ctrlSet_TailLow2.SetItemData(__Blob2.GetHardDynamic_TailLow(), true, false, true);

		m_ctrlLabel_ThresholdLow.InitStatic(_T("Threshold"), false);
		m_ctrlSet_ThresholdLow.SetItemData(_T(""), false, false, false);
		m_ctrlSet_ThresholdLow2.SetItemData(_T(""), false, false, false);

		m_ctrlLabel_ThresholdHigh.InitStatic(_T("Threshold"), false);
		m_ctrlSet_ThresholdHigh.SetItemData(_T(""), false, false, false);
		m_ctrlSet_ThresholdHigh2.SetItemData(_T(""), false, false, false);
	}
	void Reflash_SoftFixed(CMNVBlob_Algorithm & __Blob, CMNVBlob_Algorithm & __Blob2) {
		m_ctrlLabel_Mode.InitStatic(_T("Mode"), true);
		m_ctrlSet_Mode.SetItemData(_T("Soft Fixed"), true, false, true);

		m_ctrlLabel_Polarity.InitStatic(_T("Polarity"), true);
		m_ctrlSet_Polarity.SetItemData(__Blob.GetSoftFixed_Polarity() == cogBlobSegmentationPolarityLightBlobs ? _T("Light Blob") : _T("Dark Blob"), true, false, true);
		m_ctrlSet_Polarity2.SetItemData(__Blob2.GetSoftFixed_Polarity() == cogBlobSegmentationPolarityLightBlobs ? _T("Light Blob") : _T("Dark Blob"), true, false, true);

		m_ctrlLabel_Softness.InitStatic(_T("Softness"), true);
		m_ctrlSet_Softness.SetItemData(__Blob.GetSoftFixed_Softness(), true, false, true);
		m_ctrlSet_Softness2.SetItemData(__Blob2.GetSoftFixed_Softness(), true, false, true);

		m_ctrlLabel_TailHigh.InitStatic(_T("Tail High"), false);
		m_ctrlSet_TailHigh.SetItemData(_T(""), false, false, false);
		m_ctrlSet_TailHigh2.SetItemData(_T(""), false, false, false);

		m_ctrlLabel_TailLow.InitStatic(_T("Tail Low"), false);
		m_ctrlSet_TailLow.SetItemData(_T(""), false, false, false);
		m_ctrlSet_TailLow2.SetItemData(_T(""), false, false, false);

		m_ctrlLabel_ThresholdLow.InitStatic(_T("Threshold"), true);
		m_ctrlSet_ThresholdLow.SetItemData(__Blob.GetSoftFixed_ThresholdLow(), true, false, true);
		m_ctrlSet_ThresholdLow2.SetItemData(__Blob2.GetSoftFixed_ThresholdLow(), true, false, true);

		m_ctrlLabel_ThresholdHigh.InitStatic(_T("Threshold"), true);
		m_ctrlSet_ThresholdHigh.SetItemData(__Blob.GetSoftFixed_ThresholdHigh(), true, false, true);
		m_ctrlSet_ThresholdHigh2.SetItemData(__Blob2.GetSoftFixed_ThresholdHigh(), true, false, true);
	}
	void Reflash_SoftRelative(CMNVBlob_Algorithm & __Blob, CMNVBlob_Algorithm & __Blob2) {
		m_ctrlLabel_Mode.InitStatic(_T("Mode"), true);
		m_ctrlSet_Mode.SetItemData(_T("Soft Relative"), true, false, true);

		m_ctrlLabel_Polarity.InitStatic(_T("Polarity"), true);
		m_ctrlSet_Polarity.SetItemData(__Blob.GetSoftRelative_Polarity() == cogBlobSegmentationPolarityLightBlobs ? _T("Light Blob") : _T("Dark Blob"), true, false, true);
		m_ctrlSet_Polarity2.SetItemData(__Blob2.GetSoftRelative_Polarity() == cogBlobSegmentationPolarityLightBlobs ? _T("Light Blob") : _T("Dark Blob"), true, false, true);

		m_ctrlLabel_Softness.InitStatic(_T("Softness"), true);
		m_ctrlSet_Softness.SetItemData(__Blob.GetSoftRelative_Softness(), true, false, true);
		m_ctrlSet_Softness2.SetItemData(__Blob2.GetSoftRelative_Softness(), true, false, true);

		m_ctrlLabel_TailHigh.InitStatic(_T("Tail High"), true);
		m_ctrlSet_TailHigh.SetItemData(__Blob.GetSoftRelative_TailHigh(), true, false, true);
		m_ctrlSet_TailHigh2.SetItemData(__Blob2.GetSoftRelative_TailHigh(), true, false, true);

		m_ctrlLabel_TailLow.InitStatic(_T("Tail Low"), true);
		m_ctrlSet_TailLow.SetItemData(__Blob.GetSoftRelative_TailLow(), true, false, true);
		m_ctrlSet_TailLow2.SetItemData(__Blob2.GetSoftRelative_TailLow(), true, false, true);

		m_ctrlLabel_ThresholdLow.InitStatic(_T("Threshold"), true);
		m_ctrlSet_ThresholdLow.SetItemData(__Blob.GetSoftRelative_ThresholdLow(), true, false, true);
		m_ctrlSet_ThresholdLow2.SetItemData(__Blob2.GetSoftRelative_ThresholdLow(), true, false, true);

		m_ctrlLabel_ThresholdHigh.InitStatic(_T("Threshold"), true);
		m_ctrlSet_ThresholdHigh.SetItemData(__Blob.GetSoftRelative_ThresholdHigh(), true, false, true);
		m_ctrlSet_ThresholdHigh2.SetItemData(__Blob2.GetSoftRelative_ThresholdHigh(), true, false, true);
	}
	void OnReflash() {
		switch( m_pAlgorithm->m_Model.m_cdType ) {
		case MNV_AT_CircularCaliper:
			break;
		case MNV_AT_AffineCaliper:
			break;
		case MNV_AT_RelativeHistogram:
			break;
		case MNV_AT_CircularBlob:
			break;
		case MNV_AT_RectBlob:
			switch(m_pAlgorithm->m_Model.m_InspectRectanbleBlob.m_AlgorithmBlob.GetMode()) {
			case cogBlobSegmentationModeHardFixedThreshold:
				Reflash_HardFixed(m_pAlgorithm->m_Model.m_InspectRectanbleBlob.m_AlgorithmBlob, m_pAlgorithm->m_Model.m_InspectRectanbleBlob.m_AlgorithmBlob2);
				break;
			case cogBlobSegmentationModeHardRelativeThreshold:
				Reflash_HardRelative(m_pAlgorithm->m_Model.m_InspectRectanbleBlob.m_AlgorithmBlob, m_pAlgorithm->m_Model.m_InspectRectanbleBlob.m_AlgorithmBlob2);
				break;
			case cogBlobSegmentationModeHardDynamicThreshold:
				Reflash_HardDynamic(m_pAlgorithm->m_Model.m_InspectRectanbleBlob.m_AlgorithmBlob, m_pAlgorithm->m_Model.m_InspectRectanbleBlob.m_AlgorithmBlob2);
				break;
			case cogBlobSegmentationModeSoftFixedThreshold:
				Reflash_SoftFixed(m_pAlgorithm->m_Model.m_InspectRectanbleBlob.m_AlgorithmBlob, m_pAlgorithm->m_Model.m_InspectRectanbleBlob.m_AlgorithmBlob2);
				break;
			case cogBlobSegmentationModeSoftRelativeThreshold:
				Reflash_SoftRelative(m_pAlgorithm->m_Model.m_InspectRectanbleBlob.m_AlgorithmBlob, m_pAlgorithm->m_Model.m_InspectRectanbleBlob.m_AlgorithmBlob2);
				break;
			default:
				break;
			}
			break;
		}
	}
};
