#pragma once
#include "MNVObject.h"
#include "MNVGraphic.h"
#include "MNVLogFile.h"
#include "CamInfo.h"

class CMNVPolygon : public CComPtr<ICogPolygon> {
public:
	bool Create() { Release(); return SUCCEEDED( CoCreateInstance(CLSID_CogPolygon) ); }
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogPolygon>::Release();
	}
public:
	CMNVPolygon(bool __isCreate = true) : CComPtr<ICogPolygon>() { if (__isCreate) Create(); }
	~CMNVPolygon() { Release(); }
};


struct MNVST_LabelPosition {
	double dX;
	double dY;
	CogGraphicLabelAlignmentConstants	Alignment;
	void Set(double __dX, double __dY, CogGraphicLabelAlignmentConstants __Alignment) {
		dX = __dX;
		dY = __dY;
		Alignment = __Alignment;
	}
};

class CMNVStaticGraphicCollection : public CComPtr<ICogGraphicCollection> {
public:
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogGraphicCollection>::Release();
	}
	CMNVStaticGraphicCollection(bool __isCreate = true) : CComPtr<ICogGraphicCollection>() { if (__isCreate) Create(); }
	~CMNVStaticGraphicCollection() { Release(); }
	bool Create() { Release(); return SUCCEEDED( CoCreateInstance(CLSID_CogGraphicCollection) ); }
	void Clear() {
		if (p == NULL) Create();
		p->Clear();
	}
	bool AddPoint(CMNV_STPoint __stPoint, int __nWidth, int __nSizeInScreen, CogColorConstants __cogColor) {
		CMNVPointMarker pPoint;
		if (FAILED( pPoint->put_Rotation(__stPoint.m_dR) )) return false;
		if (FAILED( pPoint->put_LineWidthInScreenPixels(__nWidth) )) return false;
		if (FAILED( pPoint->put_Color(__cogColor) )) return false;
		if (! pPoint.SetPointMarker(__stPoint.GetX(), __stPoint.GetY(), 0, __nSizeInScreen) ) return false;
		if (FAILED( p->Add(CMNVGraphic(pPoint), -1) )) return false;
		return true;
	}
	bool AddPoint(double __dX, double __dY, double __dAngle, int __nWidth, int __nSizeInScreen, CogColorConstants __cogColor) {
		CMNVPointMarker pPoint;
		if (FAILED(pPoint->put_Rotation(__dAngle))) return false;
		if (FAILED(pPoint->put_LineWidthInScreenPixels(__nWidth))) return false;
		if (FAILED(pPoint->put_Color(__cogColor))) return false;
		if (!pPoint.SetPointMarker(__dX, __dY, 0, __nSizeInScreen)) return false;
		if (FAILED(p->Add(CMNVGraphic(pPoint), -1))) return false;
		return true;
	}
	bool AddGraphic(CMNVRectangleAffine &__RectA, long __nWidth, CogColorConstants __Color) {
		if (__RectA == NULL) { return false; }
		if (FAILED(__RectA->put_Color(__Color))) { return false; }
		if (FAILED(__RectA->put_LineWidthInScreenPixels(__nWidth))) { return false; }
		return SUCCEEDED(p->Add(CMNVGraphic(__RectA), -1));
	}
	bool AddGraphic(CMNVLine &__pLine, long __nWidth, CogColorConstants __Color) {
		if (__pLine == NULL) { return false; }
		if (FAILED(__pLine->put_Color(__Color))) { return false; }
		if (FAILED(__pLine->put_LineWidthInScreenPixels(__nWidth))) { return false; }
		return SUCCEEDED(p->Add(CMNVGraphic(__pLine), -1));
	}
	bool AddGraphic(CMNVLineSegment &__pLine, long __nWidth, CogColorConstants __Color) {
		if (__pLine == NULL) { return false; }
		if (FAILED(__pLine->put_Color(__Color))) { return false; }
		if (FAILED(__pLine->put_LineWidthInScreenPixels(__nWidth))) { return false; }
		return SUCCEEDED(p->Add(CMNVGraphic(__pLine), -1));
	}
	bool AddGraphic(CMNVCircle &__pCircle, long __nWidth, CogColorConstants __Color) {
		if (__pCircle == NULL) { return false; }
		if (FAILED(__pCircle->put_Color(__Color))) { return false; }
		if (FAILED(__pCircle->put_LineWidthInScreenPixels(__nWidth))) { return false; }
		return SUCCEEDED(p->Add(CMNVGraphic(__pCircle), -1));
	}
	bool AddGraphic(CMNVPolygon &__pPolygon, long __nWidth, CogColorConstants __Color) {
		if (__pPolygon == NULL) { return false; }
		if (FAILED(__pPolygon->put_Color(__Color))) { return false; }
		if (FAILED(__pPolygon->put_LineWidthInScreenPixels(__nWidth))) { return false; }
		return SUCCEEDED(p->Add(CMNVGraphic(__pPolygon), -1));
	}
	bool AddGraphic(CMNVCircularArc &__pCircle, long __nWidth, CogColorConstants __Color) {
		if (__pCircle == NULL) { return false; }
		if (FAILED(__pCircle->put_Color(__Color))) { return false; }
		if (FAILED(__pCircle->put_LineWidthInScreenPixels(__nWidth))) { return false; }
		return SUCCEEDED(p->Add(CMNVGraphic(__pCircle), -1));
	}
	bool AddGraphic(CMNVPointMarker & __PointMarker, int __nWidth, CogColorConstants __cogColor) {
		if (FAILED(__PointMarker->put_LineWidthInScreenPixels(__nWidth))) return false;
		if (FAILED(__PointMarker->put_Color(__cogColor))) return false;
		if (FAILED(p->Add(CMNVGraphic(__PointMarker), -1))) return false;
		return true;
	}
	bool AddGraphic(MNVCircularAnnulusSection & __AnnulusSection, int __nWidth, CogColorConstants __cogColor) {
		//__AnnulusSection->put_GraphicDOFEnable(cogCircularAnnulusSectionDOFAll);
		//__AnnulusSection->put_Interactive(VARIANT_TRUE);
		__AnnulusSection->put_ArcDirectionAdornment(cogCircularAnnulusSectionDirectionAdornmentSolidArrow);
		__AnnulusSection->put_CenterArcAdornment(cogCircularAnnulusSectionCenterArcAdornmentDottedArc);
		__AnnulusSection->put_RadialDirectionAdornment(cogCircularAnnulusSectionDirectionAdornmentArrow);
		if (FAILED(__AnnulusSection->put_LineWidthInScreenPixels(__nWidth))) return false;
		if (FAILED(__AnnulusSection->put_Color(__cogColor))) return false;
		if (FAILED(p->Add(CMNVGraphic(__AnnulusSection), -1))) return false;
		return true;
	}

	bool AddCrossLine(long __nWidth, CogColorConstants __Color, double __dCenterX, double __dCenterY) {
		CMNVLine Line1(false);
		CMNVLine Line2(false);
		if ( FAILED(Line1.Create(__nWidth, __Color, __dCenterX, __dCenterY, 0)) ) return false;
		if ( FAILED(Line2.Create(__nWidth, __Color, __dCenterX, __dCenterY, (double)PI / 2)) ) return false;
		CMNVGraphic pGraphic1(Line1);
		CMNVGraphic pGraphic2(Line2);
		if ( FAILED(p->Add(pGraphic1, -1)) ) return false;
		if ( FAILED(p->Add(pGraphic2, -1)) ) return false;
		return true;
	}
	HRESULT AddLine(long __nWidth, CogColorConstants __Color, double __dCenterX, double __dCenterY, double __dAngel) {
		CMNVLine pLine;
		HRESULT Result = pLine.Create(__nWidth, __Color, __dCenterX, __dCenterY, __dAngel);
		if (SUCCEEDED(Result)) {
			CMNVGraphic pGraphic(pLine);
			Result = p->Add(pGraphic, -1);
		}
		return Result;
	}
	bool AddLineSegment(long __nWidth, CogColorConstants __Color, CMNVLineSegment __LineSegment) {
		if ( FAILED(__LineSegment->put_LineWidthInScreenPixels(__nWidth)) ) return false;
		if ( FAILED(__LineSegment->put_Color(__Color)) ) return false;
		CMNVGraphic pGraphic(__LineSegment);
		return SUCCEEDED(p->Add(pGraphic, -1));
	}
	HRESULT AddLineSegment(long __nWidth, CogColorConstants __Color, double __dStartX, double __dStartY, double __dEndX, double __dEndY) {
		CMNVLineSegment pLineSegment;
		HRESULT Result = pLineSegment.Create(__nWidth, __Color, __dStartX, __dStartY, __dEndX, __dEndY);
		if (SUCCEEDED(Result)) {
			CMNVGraphic pGraphic(pLineSegment);
			Result = p->Add(pGraphic, -1);
		}
		return Result;
	}
	HRESULT AddRectSegment(long __nWidth, CogColorConstants __Color, double __dCenterX, double __dCenterY, double __dWidth, double __dHeight) {
		CComPtr<ICogRectangle> pSegment;
		pSegment.CoCreateInstance(CLSID_CogRectangle);
		pSegment->SetCenterWidthHeight(__dCenterX, __dCenterY, __dWidth, __dHeight);
		pSegment->put_Color(__Color);
		pSegment->put_LineWidthInScreenPixels(__nWidth);

		CMNVGraphic pGraphic(pSegment);
		HRESULT Result = p->Add(pGraphic, -1);
		//pSegment.Detach()->Release();
		//pSegment.Release();
		return Result;
	}
	HRESULT AddRectSegment(long __nWidth, CogColorConstants __Color, double __dCenterX, double __dCenterY, double __dWidth, double __dHeight, double __dRotation, double __dSkew) {
		CComPtr<ICogRectangleAffine> pSegment;
		HRESULT Result = pSegment.CoCreateInstance(CLSID_CogRectangleAffine);
		if (SUCCEEDED(Result)) {
			pSegment->SetCenterLengthsRotationSkew(__dCenterX, __dCenterY, __dWidth, __dHeight, __dRotation, __dSkew);
			pSegment->put_Color(__Color);
			pSegment->put_LineWidthInScreenPixels(__nWidth);

			CMNVGraphic pGraphic(pSegment);
			Result = p->Add(pGraphic, -1);
			pSegment.Detach()->Release();
			pSegment.Release();
		}
		return Result;
	}
	HRESULT AddRectSegment(long __nWidth, CogColorConstants __Color, MNV_STRectAffine & __RectA) {
		CComPtr<ICogRectangleAffine> pSegment;
		HRESULT Result = pSegment.CoCreateInstance(CLSID_CogRectangleAffine);
		if (SUCCEEDED(Result)) {
			pSegment->SetCenterLengthsRotationSkew(__RectA.dCenterX, __RectA.dCenterY, __RectA.dWidth, __RectA.dHeight, __RectA.dRotate, 0);
			pSegment->put_Color(__Color);
			pSegment->put_LineWidthInScreenPixels(__nWidth);

			CMNVGraphic pGraphic(pSegment);
			Result = p->Add(pGraphic, -1);
			pSegment.Detach()->Release();
			pSegment.Release();
		}
		return Result;
	}
	HRESULT AddRectSegment(long __nWidth, CogColorConstants __Color, CMNVRectangleAffine & __cogRectA) {
		__cogRectA->put_Color(__Color);
		__cogRectA->put_LineWidthInScreenPixels(__nWidth);
		__cogRectA->put_XDirectionAdornment(cogRectangleAffineDirectionAdornmentArrow);
		__cogRectA->put_YDirectionAdornment(cogRectangleAffineDirectionAdornmentSolidArrow);
		CMNVGraphic pGraphic(__cogRectA);
		return p->Add(pGraphic, -1);
	}
	HRESULT AddCircleSegment(long __nWidth, CogColorConstants __Color, CMNVCircle & __cogCircle) {
		__cogCircle->put_Color(__Color);
		__cogCircle->put_LineWidthInScreenPixels(__nWidth);
		CMNVGraphic pGraphic(__cogCircle);
		return p->Add(pGraphic, -1);
	}
	HRESULT AddCircleSegment(long __nWidth, CogColorConstants __Color, double __dCenterX, double __dCenterY, double __dRadius) {
		CComPtr<ICogCircle> pSegment;
		HRESULT Result = pSegment.CoCreateInstance(CLSID_CogCircle);
		if (SUCCEEDED(Result)) {
			pSegment->SetCenterRadius(__dCenterX, __dCenterY, __dRadius);
			pSegment->put_Color(__Color);
			pSegment->put_LineWidthInScreenPixels(__nWidth);

			CMNVGraphic pGraphic(pSegment);
			Result = p->Add(pGraphic, -1);
			pSegment.Detach()->Release();
			pSegment.Release();
		}
		return Result;
	}
	
	bool AddLabel(MNVST_LabelPosition & __stPosition, double __dFontSize, int __nWeight, LPCTSTR __lpText, CogColorConstants __Color = cogColorWhite, CogColorConstants __BGColor = cogColorNone) {
		return AddLabel(__stPosition.dX, __stPosition.dY, __dFontSize, __nWeight, __lpText, __Color, __BGColor, __stPosition.Alignment);
	}
	bool AddLabel(double __dX, double __dY, double __dFontSize, int __nWeight, LPCTSTR __lpText, CogColorConstants __Color = cogColorWhite, CogColorConstants __BGColor = cogColorNone, CogGraphicLabelAlignmentConstants __Alignment = cogGraphicLabelAlignmentBaselineLeft ) {
		CMNVLabel pLabel;
		if (p == NULL) return false;
		if (FAILED( pLabel.Create(__dX, __dY, __lpText) )) return false;
		if (FAILED( pLabel->put_Color(__Color) )) return false;
		if (FAILED( pLabel->put_BackgroundColor(__BGColor) )) return false;
		if (FAILED( pLabel->put_Alignment(__Alignment) )) return false;
		if ( !pLabel.SetFont(__dFontSize, __nWeight) ) return false;

		CMNVGraphic pGraphic(pLabel);
		if (FAILED( p->Add(pGraphic, -1) )) return false;
		return true;
	}
};
class CMNVStaticGraphicContainer : public CComPtr<ICogStaticGraphicsContainer>
{
public:
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogStaticGraphicsContainer>::Release();
	}
	bool Create() {
		Release();
		return SUCCEEDED(CoCreateInstance(CLSID_CogStaticGraphicsContainer));
	}
public:
	CMNVStaticGraphicContainer(bool __isCreate = true) : CComPtr<ICogStaticGraphicsContainer>() { if (__isCreate) Create(); }
	~CMNVStaticGraphicContainer() { Release(); }

	//bool AddCrossLine(double __dCenterX, double __dCenterY, long __nThickness, CogColorConstants __Color, LPCTSTR __strGroupName) {
	//	CMNVLine pLine;
	//	if (FAILED( pLine->put_Color(__Color) )) return false;
	//	if (FAILED( pLine->put_Interactive(VARIANT_FALSE) )) return false;
	//	if (FAILED( pLine->put_GraphicDOFEnable(cogLineDOFPosition) )) return false;
	//	if (FAILED( pLine->put_LineWidthInScreenPixels(__nThickness) )) return false;
	//	if (FAILED( pLine->SetXYRotation(__dCenterX, __dCenterY, 0) )) return false;
	//	if (FAILED( p->Add(CMNVGraphic(pLine), CComBSTR(__strGroupName)) )) return false;
	//	if (FAILED( pLine->SetXYRotation(__dCenterX, __dCenterY, PI / 2 ) )) return false;
	//	if (FAILED( p->Add(CMNVGraphic(pLine), CComBSTR(__strGroupName)) )) return false;
	//	return true;
	//}
	//bool AddCrossLine(double __dCenterX, double __dCenterY, double __dSize, long __nThickness, CogColorConstants __Color, LPCTSTR __strGroupName) {
	//	CMNVLineSegment pLine;
	//	//if (FAILED( pLine->put_Color(__Color) )) return false;
	//	//if (FAILED( pLine->put_Interactive(VARIANT_FALSE) )) return false;
	//	//if (FAILED( pLine->put_GraphicDOFEnable(cogLineDOFPosition) )) return false;
	//	//if (FAILED( pLine->put_LineWidthInScreenPixels(__nThickness) )) return false;
	//	//if (FAILED( pLine->SetStartLengthRotation __dCenterX, __dCenterY, 0) )) return false;
	//	//if (FAILED( p->Add(CMNVGraphic(pLine), CComBSTR(__strGroupName)) )) return false;
	//	//if (FAILED( pLine->SetXYRotation(__dCenterX, __dCenterY, PI / 2 ) )) return false;
	//	//if (FAILED( p->Add(CMNVGraphic(pLine), CComBSTR(__strGroupName)) )) return false;
	//	return true;
	//}
	//bool AddRectangleAffine(double __dCenterX, double __dCenterY, double __dWidth, double __dHeight, double __dTheta, long __nThickness, CogColorConstants __Color, LPCTSTR __strGroupName) {
	//	CMNVRectangleAffine pRect;
	//	if (FAILED( pRect->SetCenterLengthsRotationSkew(__dCenterX, __dCenterY, __dWidth, __dHeight, __dTheta, 0) )) return false;
	//	if (FAILED( pRect->put_Color(__Color) )) return false;
	//	if (FAILED( pRect->put_LineWidthInScreenPixels(__nThickness) )) return false;
	//	if (FAILED( p->Add(CMNVGraphic(pRect), CComBSTR(__strGroupName)) )) return false;
	//	return true;
	//}
};

class CMNVInteractiveGraphicCollection : public CComPtr<ICogGraphicInteractiveCollection> {
public:
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogGraphicInteractiveCollection>::Release();
	}
	bool Create() {
		Release();
		return SUCCEEDED(CoCreateInstance(CLSID_CogGraphicInteractiveCollection));
	}
	CMNVInteractiveGraphicCollection(bool __isCreate = true) : CComPtr<ICogGraphicInteractiveCollection>() { if (__isCreate) Create(); }
	~CMNVInteractiveGraphicCollection() { Release(); }

	bool AddGraphic(CMNVPointMarker & __Point, CogColorConstants __color, int __nLWidth) {
		if (__Point == NULL) return false;
		if (p == NULL) return false;

		if (FAILED(__Point->put_Color(__color))) return false;
		if (FAILED(__Point->put_LineWidthInScreenPixels(__nLWidth))) return false;
		return SUCCEEDED(p->Add(CComQIPtr<ICogGraphicInteractive>(__Point), 0));
	}
	bool AddGraphic(CMNVRectangleAffine& __RectA, CogColorConstants __color, int __nLWidth) {
		if (__RectA == NULL) return false;
		if (p == NULL) return false;

		if (FAILED(__RectA->put_Color(__color))) return false;
		if (FAILED(__RectA->put_LineWidthInScreenPixels(__nLWidth))) return false;
		return SUCCEEDED(p->Add(CComQIPtr<ICogGraphicInteractive>(__RectA), 0));
	}
	bool AddGraphic(CMNVRectangle& __Rect, CogColorConstants __color, int __nLWidth) {
		if (__Rect == NULL) return false;
		if (p == NULL) return false;

		if (FAILED(__Rect->put_Color(__color))) return false;
		if (FAILED(__Rect->put_LineWidthInScreenPixels(__nLWidth))) return false;
		return SUCCEEDED(p->Add(CComQIPtr<ICogGraphicInteractive>(__Rect), 0));
	}
};
class CMNVInteractiveGraphicContainer : public CComPtr<ICogInteractiveGraphicsContainer> {
public:
	void Release() {
		if(p != NULL) Detach()->Release();
		CComPtr<ICogInteractiveGraphicsContainer>::Release();
	}
	bool Create() {
		Release();
		return SUCCEEDED( CoCreateInstance(CLSID_CogInteractiveGraphicsContainer) );
	}
public:
	CMNVInteractiveGraphicContainer(bool __isCreate = true) : CComPtr<ICogInteractiveGraphicsContainer>() { if(__isCreate) Create(); }
	~CMNVInteractiveGraphicContainer() { Release(); }
};

