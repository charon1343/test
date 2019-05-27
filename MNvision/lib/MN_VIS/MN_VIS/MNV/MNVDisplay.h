#pragma once
#include "Define_Cog.h"
#include "MNVLock.h"
#include "MNVImage.h"
#include "MNVGraphicsCollection.h"

///// Cognex Display 객체를 다루는 클래스
class CMNVDisplay : protected CComPtr<ICogDisplay> {
	MNVLock m_hLock;	/// Lock객체 : 현 클래스에 대한 Critical Section을 위해 추가 
	CString m_strName;	/// Display 이름 : 설정시 화면에 Label을 추가한다.

	CogGraphicLabelAlignmentConstants m_GLAlign;
	double m_dPosX;
	double m_dPosY;
public:
	bool SetDrawingEnabled(bool __isEnable) {
		if (p == NULL) return false;
		return SUCCEEDED( p->put_DrawingEnabled(__isEnable ? VARIANT_TRUE : VARIANT_FALSE) );
	}
	CMNVDisplay(bool __isCreate = false) { if (__isCreate) Create(); }
	~CMNVDisplay() { Release(); }

protected:
	bool Add_StaticGraphic(LPCSTR __pstrGroup, CMNVStaticGraphicCollection __SGCollection) {
		if (p != NULL) {
			CMNVStaticGraphicContainer SGContainer(false);
			if (FAILED(p->get_StaticGraphics(&SGContainer))) return false;
			if (FAILED(SGContainer->AddList(__SGCollection, CComBSTR(__pstrGroup)))) return false;
		}
		return false;
	}
	bool Remove_StaticGraphc(LPCSTR __pstrGroup) {
		if (p != NULL) {
			CMNVStaticGraphicContainer SGContainer(false);
			if (FAILED(p->get_StaticGraphics(&SGContainer))) return false;
			if (FAILED(SGContainer->Remove(CComBSTR(__pstrGroup)))) return false;
			return true;
		}
		return false;
	}
	bool Clear_StaticGraphic() {
		if (p == NULL) return false;
		CMNVStaticGraphicContainer SGContainer(false);
		if (FAILED(p->get_StaticGraphics(&SGContainer))) return false;
		if (FAILED(SGContainer->Clear())) return false;
		return true;
	}

	bool Add_InteractiveGraphic(LPCSTR __pstrGroup, CMNVInteractiveGraphicCollection __IGCollection) {
		if ( p != NULL) {
			CMNVInteractiveGraphicContainer IGContainer(false);
			if (FAILED(p->get_InteractiveGraphics(&IGContainer))) return false;
			return SUCCEEDED(IGContainer->AddList(__IGCollection, CComBSTR(__pstrGroup), VARIANT_TRUE));
		}
		return false;
	}
	bool Remove_Interactive(LPCSTR __pstrGroup) {
		if ( p != NULL) {
			CMNVInteractiveGraphicContainer IGContainer(false);
			if (FAILED(p->get_InteractiveGraphics(&IGContainer))) return false;
			if (FAILED(IGContainer->Remove(CComVariant(__pstrGroup)))) return false;
			return true;
		}
		return false;
	}
	bool Clear_InteractiveGraphic() {
		if (p == NULL) return false;
		CMNVInteractiveGraphicContainer IGContainer(false);
		if (FAILED(p->get_InteractiveGraphics(&IGContainer))) return false;
		return  SUCCEEDED(IGContainer->Clear());
	}
public:
	bool SetDisplay(bool __isHorizontalScroll, bool __isVertixalScroll, bool __isAutoFit) {
		if (p != NULL) {	// Display  창 속성 설정
			if (FAILED(p->put_HorizontalScrollBar(__isHorizontalScroll ? VARIANT_TRUE : VARIANT_FALSE))) return false;
			if (FAILED(p->put_VerticalScrollBar(__isVertixalScroll ? VARIANT_TRUE : VARIANT_FALSE))) return false;
			return SUCCEEDED(p->put_AutoFit(__isAutoFit ? VARIANT_TRUE : VARIANT_FALSE));
		}
		else return false;
	}
	bool SetTitle(LPCTSTR __strName, CogGraphicLabelAlignmentConstants __GLAlign, double __dPosX, double __dPosY) {
		if (p == NULL) return false;
		m_strName = __strName;
		m_GLAlign = __GLAlign;
		m_dPosX = __dPosX;
		m_dPosY = __dPosY;
		return true;
	}
	bool AddTitle() {
		CMNVStaticGraphicCollection SGCollection;
		CMNVImage img(false);
		p->get_Image(&img);
		switch(m_GLAlign) {
			case cogGraphicLabelAlignmentTopLeft:
				m_dPosX = 0;
				m_dPosY = 0;
				break;
			case cogGraphicLabelAlignmentTopRight:
				m_dPosX = img.GetWidth();
				m_dPosY = 0;
				break;
			case cogGraphicLabelAlignmentBottomLeft:
				m_dPosX = 0;
				m_dPosY = img.GetHeight();
				break;
			case cogGraphicLabelAlignmentBottomRight:
				m_dPosX = img.GetWidth();
				m_dPosY = img.GetHeight();
				break;
		}
		if (! SGCollection.AddLabel(m_dPosX, m_dPosY, 1, 500, m_strName, cogColorBlack, cogColorYellow, m_GLAlign) ) return false;
		if (! Add_StaticGraphic("Title", SGCollection) ) return false;
		return true;
	}
	bool RemoveTitle() { return Remove_StaticGraphc("Title"); }
	

	void Create() {
		Release();	// 중복 생성을 방지하기 위해서 사용 : 기 생성된 객체의 경우 Release를 한 이후에 다시 생성을 하도록 추가
		CoCreateInstance(CLSID_CogDisplay);
	}
	void Create(CComQIPtr<ICogDisplay> __pDisplay) {
		Release();
		(CComPtr<ICogDisplay>)(*this) =  __pDisplay;
	}
	void Create(CWnd * pWnd) {
		Release();
		CComQIPtr<ICogDisplay>(pWnd->GetControlUnknown())->QueryInterface(&p);
	}
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogDisplay>::Release();
	}

	bool Clear_Graphic() { 
		if (!Clear_StaticGraphic()) return false;
		if (!Clear_InteractiveGraphic()) return false;
		return true;
	}
	bool Clear_Image(bool __isLock = true) {
		if (__isLock) {
			CMNVLock Lock(&m_hLock, MNVLM_Write);
			return SUCCEEDED(p->putref_Image(NULL));
		}
		else {
			return SUCCEEDED(p->putref_Image(NULL));
		}
	}
	bool AddResult(CMNVStaticGraphicCollection __GCollection) {
		if (p != NULL) {
			CMNVStaticGraphicContainer SGContainer(false);
			if (FAILED(p->get_StaticGraphics(&SGContainer))) return false;
			SGContainer->Remove(CComBSTR("Result"));

			if (FAILED( SGContainer->AddList(__GCollection, CComBSTR("Result")) )) return false;
			return true;
		}
		return false;
	}
	bool RemoveResult() {
		if (p != NULL) {
			CMNVStaticGraphicContainer SGContainer(false);
			if (FAILED(p->get_StaticGraphics(&SGContainer))) return false;
			if (FAILED(SGContainer->Remove(CComBSTR("Result")))) return false;
			return true;
		}
		return false;
	}

	bool AddInteractive(CMNVInteractiveGraphicCollection __GCollection) {
		if ( p != NULL) {
			CMNVInteractiveGraphicContainer IGContainer(false);
			if (FAILED(p->get_InteractiveGraphics(&IGContainer))) return false;
			IGContainer->Remove(CComVariant("Interactive"));
			return SUCCEEDED(IGContainer->AddList(__GCollection, CComBSTR("Interactive"), VARIANT_TRUE));
		}
		return false;
	}
	bool RemoveInteractive() {
		if ( p != NULL) {
			CMNVInteractiveGraphicContainer IGContainer(false);
			if (FAILED(p->get_InteractiveGraphics(&IGContainer))) return false;
			if (FAILED(IGContainer->Remove(CComVariant("Interactive")))) return false;
			return true;
		}
		return false;
	}

	bool AddGraphic(CMNVStaticGraphicCollection __GCollection, bool __isGClear = true, bool __isLock = true) {
		if (__isLock) {
			CMNVLock Lock(&m_hLock, MNVLM_Write);
			CMNVStaticGraphicContainer SGContainer(false);
			if (FAILED(p->get_StaticGraphics(&SGContainer))) return false;
			if (__isGClear && FAILED(SGContainer->Clear())) return false;
			return SUCCEEDED(SGContainer->AddList(__GCollection, CComBSTR("Static")));
		}
		else {
			CMNVStaticGraphicContainer SGContainer(false);
			if (FAILED(p->get_StaticGraphics(&SGContainer))) return false;
			if (__isGClear && FAILED(SGContainer->Clear())) return false;
			return SUCCEEDED(SGContainer->AddList(__GCollection, CComBSTR("Static")));
		}
	}
	bool AddGraphic(CMNVInteractiveGraphicCollection __GCollection, bool __isGClear = true, bool __isLock = true) {
		if (__isLock) {
			CMNVInteractiveGraphicContainer IGContainer(false);
			if (FAILED(p->get_InteractiveGraphics(&IGContainer))) return false;
			if (__isGClear && FAILED(IGContainer->Clear())) return false;
			return SUCCEEDED(IGContainer->AddList(__GCollection, CComBSTR("Interactive"), VARIANT_TRUE));
		}
		else {
			CMNVInteractiveGraphicContainer IGContainer(false);
			if (FAILED(p->get_InteractiveGraphics(&IGContainer))) return false;
			if (__isGClear && FAILED(IGContainer->Clear())) return false;
			return SUCCEEDED(IGContainer->AddList(__GCollection, CComBSTR("Interactive"), VARIANT_TRUE));
		}
	}
	bool AddCrossLine() {
		if (p != NULL) {
			CMNVImage img(false);
			p->get_Image(&img);
			if (img != NULL) {
				CMNVStaticGraphicCollection SGCollection;
				SGCollection.Clear();
				SGCollection.AddCrossLine(1, cogColorYellow, (double)img.GetWidth() / 2, (double)img.GetHeight() / 2);

				CMNVStaticGraphicContainer SGContainer(false);
				if (FAILED(p->get_StaticGraphics(&SGContainer))) return false;
				SGContainer->Remove(CComBSTR("CrossLine"));
				SGContainer->AddList(SGCollection, CComBSTR("CrossLine"));
			}
			return true;
		}
		return false;
	}
	bool RemoveCrossLine() {
		if (p != NULL) {
			CMNVStaticGraphicContainer SGContainer(false);
			if (FAILED(p->get_StaticGraphics(&SGContainer))) return false;
			SGContainer->Remove(CComBSTR("CrossLine"));

			return true;
		}
		return false;
	}

	bool Display(CMNVImage &__imgSource) {
		CMNVImage Img;
		__imgSource.Copy(Img);
		//SetDrawingEnabled(false);
		RemoveTitle();
		bool Result = FAILED(p->putref_Image(Img));
		AddTitle();

		//RemoveTitle();
		//AddTitle();
		//SetDrawingEnabled(true);
		return Result;
	}
	bool Display(CMNVImage &__imgSource, CMNVStaticGraphicCollection & __sgc) {
		CMNVImage Img;
		__imgSource.Copy(Img);
		//SetDrawingEnabled(false);
		RemoveTitle();
		bool Result = FAILED(p->putref_Image(__imgSource));
		//AddTitle();

		CMNVStaticGraphicContainer SGContainer(false);
		if (FAILED(p->get_StaticGraphics(&SGContainer))) return false;
		SGContainer->Clear();
		SGContainer->AddList(__sgc, CComBSTR("Result"));
		//RemoveTitle();
		//AddTitle();
		//SetDrawingEnabled(true);
		return Result;
	}
	bool Display(CMNVImage &__imgSource, CMNVInteractiveGraphicCollection & __igc) {
		CMNVImage Img;
		__imgSource.Copy(Img);
		SetDrawingEnabled(false);
		RemoveTitle();
		bool Result = FAILED(p->putref_Image(Img));
		//AddTitle();

		CMNVInteractiveGraphicContainer IGContainer(false);
		if (FAILED(p->get_InteractiveGraphics(&IGContainer))) return false;
		IGContainer->Clear();
		IGContainer->AddList(__igc, CComBSTR("Pattern"), VARIANT_TRUE);
		//RemoveTitle();
		//AddTitle();
		SetDrawingEnabled(true);
		return Result;
	}
	CMNVImage Img;
	bool Display(CMNVImage &__imgSource, bool __isGClear, bool __isLock) {
		__imgSource.Copy(Img);
		if (FAILED( p->putref_Image(Img) )) return false;
		RemoveTitle();
		AddTitle();
	}
	bool Display(CMNVImage8Grey &__imgSource, bool __isGClear = true, bool __isLock = true) {
		RemoveTitle();
		AddTitle();
		return SUCCEEDED(p->putref_Image(__imgSource));
	}
	bool Display(CMNVImage24Color &__imgSource, bool __isGClear = true, bool __isLock = true) {
		RemoveTitle();
		AddTitle();
		return SUCCEEDED(p->putref_Image(__imgSource));
	}
	//bool LiveOn(CMNVAcqFifo & __AcqFifo) {
	//	if (p == NULL) return false;
	//	return SUCCEEDED( p->StartLiveDisplay((IDispatch *)(__AcqFifo.p), VARIANT_TRUE) );
	//}
	//bool LiveOff() {
	//	if (p == NULL) return false;
	//	return SUCCEEDED( p->StopLiveDisplay() );
	//}
	//bool IsLive() {
	//	if (p == NULL) return false;
	//	VARIANT_BOOL isLive;
	//	if (FAILED( p->get_LiveDisplayRunning(&isLive) )) return false;
	//	return isLive == VARIANT_TRUE;
	//}
};
