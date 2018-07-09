#pragma once
#include "MNV/CamInfo.h"
#include "MNV/MNVDisplay.h"

#include "MNVAlgorithm.h"

#include "MNV\MNVRegion.h"
#include "MNV\MNVCopyRegion.h"

enum MNVMD_Display { MNVMD_DisplayNon = 0, MNVMD_DisplayLive, MNVMD_DisplayRun };
			////// Display Mode
			// Mode Live
			// Mode Run
			// Mode Manual
			///    ManualMode의 경우 수동으로 Display 함수를 호출해야 한다.
			///    동작중인 경우도 이를 사용 Display 할 수 있으나... 호출 빈도가 높으면 오류가 발생할 수 있다.
			///    Display Function
			///    - Display Master (Model 설정에서 사용)
			///    - Display Image (Grab / Live에서 사용)
			///    - Display Test (모델 설정에서 설정 테스트에 사용)
			///    - Display Manual (모델 설정 등 수동 테스트 모드에서 사용)
			///    - Display Virtual (이미지 로딩 기능을 사용 / 카메라를 사용하지 않고 동작)
class CDlg_MAView : public CMNVDialogEx
{
	DECLARE_DYNAMIC(CDlg_MAView)
	CMNVAlgorithm * m_pAlgorithm;
	MNVMD_Display m_mdDisplay;
public:
	void MNVRelease() {
		EndThread();
	}
	CDlg_MAView(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_MAView();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MA_View };
	void Create(CMNVAlgorithm * __pAlgorithm, CWnd * __pWnd, CMNVDialogEx * __pParent) {
		m_pAlgorithm = __pAlgorithm;
		CMNVDialogEx::Create(IDD, __pWnd, __pParent);
		m_nDisplayItem = 0;
	}
	CWnd * pWnd;

	bool m_isPattern;
	bool m_isDisplay;
	int m_nModel;
	int m_nOption;
	int m_nVision;
	CMNVImage m_imgMaster;
	CMNVImage8Grey m_imgPattern;
	CMNVImage8Grey m_imgMask;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	CMNVDisplay m_cogDisplay;
	CCamInfo * m_pcogCamInfo;
	CMNVImage m_imgBuf;
	bool m_isCrossLine;
	//void SetCamInfo(CCamInfo * __pcogCamInfo) { m_pcogCamInfo = __pcogCamInfo; }
	//void SetImage(CMNVImage &__img) { __img.Copy(m_imgBuf); }

	void OnCmd_ShowMaster(CMNVAlgorithm & __Algorithm) {
		OnCmd_LoadPattern(1, 1, 1);
	}
	void OnCmd_SetPattern(CMNVAlgorithm & __Algorithm) {
		//m_imgPattern.Release();
		//CMNVImage8Grey img8Gray(false);
		//{
		//	m_imgMaster.Copy(img8Gray);
		//}

		//m_imgPattern.Create(m_rectPattern.GetWidth(), m_rectPattern.GetHeight());
		//m_imgMask.Create(m_rectPattern.GetWidth(), m_rectPattern.GetHeight());
		//{	/// Copy Pattern Image
		//	VARIANT_BOOL bSourceClipped, bDestinationClipped;
		//	CMNVRegion pDestRegion;
		//	CMNVImage pImg(false);
		//	CMNVCopyRegion pCopyRegion_C;
		//	pCopyRegion_C->put_RegionMode(cogRegionModeAffineTransform);
		//	pCopyRegion_C->Execute(img8Gray, CComQIPtr<ICogRegion>(m_rectPattern), CComQIPtr<ICogImage>(m_imgPattern),
		//		&bSourceClipped, &bDestinationClipped, &pDestRegion, &pImg);
		//}

		//{	/// Copy Mask Image
		//	CMNVCopyRegion pCopyRegion;
		//	pCopyRegion->put_RegionMode(cogRegionModePixelAlignedBoundingBoxAdjustMask);
		//	pCopyRegion->put_FillBoundingBox(VARIANT_FALSE);
		//	pCopyRegion->put_FillRegion(VARIANT_TRUE);
		//	pCopyRegion->put_FillRegionValue(255);
		//	CMNVImage8Grey pImg2(false);
		//	pCopyRegion->Execute(CComQIPtr<ICogImage>(m_imgMask), NULL, CComQIPtr<ICogImage>(m_imgMask), NULL, NULL, NULL, &CComQIPtr<ICogImage>(pImg2));
		//	//pPMA->m_mskGraphic.SetImage(pPMA->m_imgMask);
		//}

		//CMNVImageFile m_File;
		//CString strPath;
		//strPath.Format(_T("D:\\Model\\Model%02d_%02d Vision%02d"), m_nModel, m_nOption, m_nVision);
		//CMNVFile::CreateDir(strPath);
		//m_File.SaveCogImage(strPath + _T("\\Master.bmp"), m_imgMaster);
		//m_File.SaveCogImage(strPath + _T("\\Pattern.bmp"), m_imgPattern);
		//m_File.SaveCogImage(strPath + _T("\\Mask.bmp"), m_imgMask);

		////{	/// Display Pattern
		////	//m_pDisplay_Pattern->put_DrawingEnabled(VARIANT_FALSE);
		////	CMNVGraphicsContainer comptrGContainer(false);
		////	m_pDisplay_Pattern->get_StaticGraphics(&comptrGContainer);
		////	comptrGContainer->Remove(CComBSTR("Mask"));
		////	comptrGContainer->Add(CComQIPtr<ICogGraphic>(pPMA->m_mskGraphic), CComBSTR("Mask"));
		////	
		////	m_pDisplay_Pattern->putref_Image(pPMA->m_imgPattern);
		////	//m_pDisplay_Pattern->put_DrawingEnabled(VARIANT_TRUE);
		////}
	}

	CMNVRectangleAffine m_rectPattern;
	CMNVInteractiveGraphicCollection m_igcPattern;

	void OnCmd_LoadPattern(int __nModel, int __nOption, int __nVision) {
		m_nModel = __nModel;
		m_nOption = __nOption;
		m_nVision = __nVision;
		m_imgMaster;
		m_imgPattern;
		m_imgMask;
		CMNVImageFile m_File;
		CString strPath;
		strPath.Format(_T("D:\\Model\\Model%02d_%02d Vision%02d"), m_nModel, m_nOption, m_nVision);
		CMNVFile::CreateDir(strPath);

		m_File.LoadCogImage(strPath + _T("\\Master.bmp"), m_imgMaster);
		m_File.LoadCogImage(strPath + _T("\\Pattern.bmp"), m_imgPattern);
		m_File.LoadCogImage(strPath + _T("\\Mask.bmp"), m_imgMask);

		{	// Load Pattern Area
			double dx, dy, dw, dh;
			dx = CMNVIni::GetValue(_T("Pattern"), _T("CenterX"), (double)100, strPath + _T("\\PatternAlign.ini"));
			dy = CMNVIni::GetValue(_T("Pattern"), _T("CenterY"), (double)100, strPath + _T("\\PatternAlign.ini"));
			dw = CMNVIni::GetValue(_T("Pattern"), _T("Width"), (double)100, strPath + _T("\\PatternAlign.ini"));
			dh = CMNVIni::GetValue(_T("Pattern"), _T("Height"), (double)100, strPath + _T("\\PatternAlign.ini"));
			m_rectPattern.SetRect_CenterWH(dx, dy, dw, dh, 0, 0);
			m_rectPattern.SetInterectiveRegion();
			m_igcPattern.Create();
			m_igcPattern.AddGraphic(m_rectPattern, cogColorYellow, 1);
		}
		m_isPattern = true;
		m_isDisplay = true;
	}
	int m_nLast;
	CMNVStaticGraphicCollection m_sgcResult;

	bool OnCmd_Live() {
		if (isLive()) {
			LiveOff();
			return false;
		}
		else {
			LiveOn();
			return true;
		}
	}
	int OnCmd_Capture() {
		LiveOff();
		CMNVImage imgBuffer;

		if(m_pAlgorithm->Grabber_Grab(m_imgBuf)) {
			m_pAlgorithm->GetRegion(m_sgcResult);
			m_cogDisplay.SetDrawingEnabled(false);
			m_cogDisplay.RemoveCrossLine();
					
			m_cogDisplay.Display(m_imgBuf, m_sgcResult);
			m_cogDisplay.SetDrawingEnabled(true);
			m_isDisplay = false;
		}

		return 0;
	}
	void LiveOn() {
		m_pAlgorithm->OnLive();
		m_mdDisplay = MNVMD_DisplayLive;
	}
	void LiveOff() {
		int nTemp = m_nThreadStamp;
		m_mdDisplay = MNVMD_DisplayRun;
		m_pAlgorithm->OnLive(false);
		//while (nTemp == m_nThreadStamp) {
		//	Sleep(0);
		//}
	}

	bool isLive() { return m_mdDisplay == MNVMD_DisplayLive; }

	int m_nThreadStamp; /// Thread가 반복될 때 마다 1씩 증가된다. 최대가 이후 다시 0이된다.
		/// 상태값 변경이 되더라도 Cycle이 진행 중일 때는 바로 적용되지 않기 때문에 이 값을 이용 상태값 변경 및 적용 여부를 확인 할 때 사용한다.

	void OnDisplay_Result() {
		// 검사 결과를 Display 한다.
	}
	void OnDisplay_Grab() {
		// 이미지를 Grab해서 화면에 도시한다.
	}
	void OnDisplay_Align() {
		// Master 이미지와 찾기 영역을 도시한다. (Interactive Graphic Collection)
	}
	void OnDisplay_Detect() {
		// Master 이미지와 검사 영역 및 허용 영역을 도시한다. (Interactive Graphic Collection)
	}
	void OnDisplay_Test(int __nTestCode) {
		// Vision 설정에서 설정 테스트 결과를 도시한다. (Static Graphic Collection)
	}
	virtual void Thread() {
		m_nThreadStamp = 0;
		m_mdDisplay = MNVMD_DisplayRun;
		m_nLast = 0;
		int nLast = -1;
		int nCurrent = 0;
		m_isPattern = false;
		m_isCrossLine = false;
		m_cogDisplay.SetTitle(_T("Camera 01"), cogGraphicLabelAlignmentTopLeft, 2, 2);
		CRect Last(0, 0, 0, 0);
		while(1) {
			// Check View Size
			{
				CWnd * pWnd = GetDlgItem(IDC_COGDISPLAY1);
				CRect rect;
				GetClientRect(&rect);
				//int Header = 50;
				//int Footer = 50;
				if (rect.left != Last.left || rect.top != Last.top || rect.right != Last.right || rect.bottom != Last.bottom) {
					pWnd->SetWindowPos(NULL, rect.left + 2, rect.top + 2, rect.Width() - 4, rect.Height() - 4, SWP_NOZORDER);
					RedrawWindow();
				}
				Last = rect;
			}
			
			switch(m_mdDisplay) {
			case MNVMD_DisplayNon:
				break;
			case MNVMD_DisplayLive:
				if(m_pAlgorithm->Grabber_GetBuffer(m_imgBuf)) {
					m_pAlgorithm->GetRegion(m_sgcResult);
					m_cogDisplay.SetDrawingEnabled(false);
					m_cogDisplay.RemoveCrossLine();
					
					m_cogDisplay.Display(m_imgBuf, m_sgcResult);
					m_cogDisplay.AddCrossLine();
					m_cogDisplay.SetDrawingEnabled(true);
					m_isDisplay = false;
				}
				break;
			case MNVMD_DisplayRun:
				{
					CMNVImage Img(false);
					CMNVStaticGraphicCollection sgc;
					int nCurrent = (m_nDisplayItem > 0)
						? m_pAlgorithm->Algorithm_Result(m_nDisplayItem - 1, Img, sgc, nLast)
						: m_pAlgorithm->Algorithm_Result(Img, sgc, nLast);

					if ( nLast != nCurrent && nCurrent != 0) {
						nLast = nCurrent;
						m_cogDisplay.SetDrawingEnabled(false);
						m_cogDisplay.RemoveCrossLine();
						m_cogDisplay.Display(Img, sgc);
						if (m_isCrossLine) {
							m_cogDisplay.AddCrossLine();
						}
						m_cogDisplay.SetDrawingEnabled(true);
					}
				}
				break;
			}
			m_nThreadStamp = (m_nThreadStamp + 1) & 0x0fffffff;
			Sleep(50);
		}
	}
	int m_cdDisplayMode;
	int m_nDisplayItem;
	int OnReflash(int __nItem) {
		m_nDisplayItem = (m_nDisplayItem == __nItem) ? 0 : __nItem;
		return m_nDisplayItem;
	}
	//virtual BOOL DestroyWindow();
	//afx_msg void OnDestroy();
};
