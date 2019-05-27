# pragma once
#include "Define_Cog.h"
#include "MNVLineSegment.h"

////// 이미지에서 사각형을 표현 혹은 사각영역을 편집하기 위한 그래픽 객체 (회전 등 모든 편집이 가능)
class CMNVRectangleAffine : public CComPtr<ICogRectangleAffine> {
public:
	//CMNVRegion GetRegion() { return CMNVRegion(p); }
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogRectangleAffine>::Release();
	}
public:
	double GetCenterX() { double dValue; p->get_CenterX(&dValue); return dValue; }
	double GetCenterY() { double dValue; p->get_CenterY(&dValue); return dValue; }
	double GetWidth() { double dValue; p->get_SideXLength(&dValue); return dValue; }
	double GetHeight() { double dValue; p->get_SideYLength(&dValue); return dValue; }
	double GetRotation() { double dValue; p->get_Rotation(&dValue); return dValue; }
	double GetSkew() { double dValue; p->get_Skew(&dValue); return dValue; }
	bool GetCenter(CMNV_STPoint & __stCenter) {
		if (p == NULL) return false;
		__stCenter.m_dR = 0;
		if(FAILED( p->get_CenterX(&__stCenter.m_dX) )) return false;
		if(FAILED( p->get_CenterY(&__stCenter.m_dY) )) return false;
		return true;
	}

	CMNVRectangleAffine(CMNVRectangleAffine &__Base, double __dX, double __dY, double __dT) {
		Create();
		p->SetCenterLengthsRotationSkew(__Base.GetCenterX() + __dX, __Base.GetCenterY() + __dY, __Base.GetWidth(), __Base.GetHeight(), __Base.GetRotation() + __dT, __Base.GetSkew());
	}
	CMNVRectangleAffine(bool __isCreate = true) : CComPtr<ICogRectangleAffine>() { if (__isCreate) Create(); }
	CMNVRectangleAffine(double __dx, double __dy, double __dWidth, double __dHeight, double __dRotation) : CComPtr<ICogRectangleAffine>() {
		CoCreateInstance(CLSID_CogRectangleAffine);
		p->SetCenterLengthsRotationSkew(__dx, __dy, __dWidth, __dHeight, __dRotation, 0);
	}
	CMNVRectangleAffine(CMNVRectangleAffine & __RectA, CMNV_STPoint & __TPOffset) : CComPtr<ICogRectangleAffine>() {
		CoCreateInstance(CLSID_CogRectangleAffine);
		p->SetCenterLengthsRotationSkew(__RectA.GetCenterX() + __TPOffset.GetX(), __RectA.GetCenterY() + __TPOffset.GetY(), __RectA.GetWidth(), __RectA.GetHeight(), __RectA.GetRotation(), __RectA.GetSkew());
	}
	~CMNVRectangleAffine() { Release(); }
	bool CreateCliperEdit() {
		Release();
		if(FAILED( CoCreateInstance(CLSID_CogRectangleAffine) )) return false;
		if(FAILED( p->put_XDirectionAdornment(cogRectangleAffineDirectionAdornmentArrow) )) return false;
		if(FAILED( p->put_YDirectionAdornment(cogRectangleAffineDirectionAdornmentSolidArrow) )) return false;
		if(FAILED( p->put_GraphicDOFEnable(cogRectangleAffineDOFAll) )) return false;
		if(FAILED( p->put_Interactive(VARIANT_TRUE) )) return false;
		if(FAILED( p->put_SelectedSpaceName(CComBSTR("#")) )) return false;
		return true;
	}
	bool Create() { Release(); return SUCCEEDED(CoCreateInstance(CLSID_CogRectangleAffine)); }
	bool Create(CogRectangleAffineDOFConstants __DOFEnable, VARIANT_BOOL __isInteractive, BSTR __pSpaceName) {
		if (!Create()) return false;
		if (FAILED(p->put_GraphicDOFEnable(__DOFEnable))) return false;
		if (FAILED(p->put_Interactive(__isInteractive))) return false;
		if (FAILED(p->put_SelectedSpaceName(__pSpaceName))) return false;
		return true;
	}
	bool SetStyle(CogGraphicLineStyleConstants __LineStyle, CogColorConstants __Color, int __nLineWidth) {
		if (p == NULL) return false;
		if ( FAILED( p->put_LineStyle(__LineStyle) )) return false;
		if ( FAILED( p->put_Color(__Color) )) return false;
		return SUCCEEDED( p->put_LineWidthInScreenPixels(__nLineWidth) );
	}
	bool SetInterectiveRegion(bool __isEnable = true) {
		
		if (FAILED( p->put_GraphicDOFEnable((CogRectangleAffineDOFConstants)(cogRectangleAffineDOFAll ^ cogRectangleAffineDOFSkew)) )) return false;
		if (FAILED( p->put_XDirectionAdornment(cogRectangleAffineDirectionAdornmentSolidArrow) )) return false;
		if (FAILED( p->put_YDirectionAdornment(cogRectangleAffineDirectionAdornmentArrow) )) return false;
		if (FAILED( p->put_Interactive(__isEnable ? VARIANT_TRUE : VARIANT_FALSE) )) return false;
		return SUCCEEDED( p->put_SelectedSpaceName(CComBSTR("#")) );
	}
	bool SetStaticRegion() {
		if (FAILED( p->put_GraphicDOFEnable(cogRectangleAffineDOFNone) )) return false;
		if (FAILED( p->put_XDirectionAdornment(cogRectangleAffineDirectionAdornmentSolidArrow) )) return false;
		if (FAILED( p->put_YDirectionAdornment(cogRectangleAffineDirectionAdornmentArrow) )) return false;
		if (FAILED( p->put_Interactive(VARIANT_TRUE) )) return false;
		return SUCCEEDED( p->put_SelectedSpaceName(CComBSTR("#")) );
	}
	bool SetRect_OriginWH(double __dX, double __dY, double __dW, double __dH, double __dAngle, double __dSkew) { 
		if (p == NULL) { Create(); }
		SetInterectiveRegion();
		return SUCCEEDED( p->SetOriginLengthsRotationSkew(__dX, __dY, __dW, __dH, __dAngle, __dSkew) );
	}
	bool SetRect_CenterWH(double __dCX, double __dCY, double __dW, double __dH, double __dAngle, double __dSkew) { 
		if (p == NULL) { Create(); }
		SetInterectiveRegion();
		return SUCCEEDED( p->SetCenterLengthsRotationSkew(__dCX, __dCY, __dW, __dH, __dAngle, __dSkew) );
	}
	bool GetRect_CenterWH(double & __dCX, double & __dCY, double & __dW, double & __dH, double & __dAngle, double & __dSkew) { 
		bool ret = true;
		//// 서로간에 연관성이 없기 때문에 FAILED가 발생하면 ret값을 false로 변경한다.
		//// 즉 한개라도 오류가 나면 실패로 리턴을 하지만 모두 실행을 하도록 한다.
		if (FAILED( p->get_CenterX(&__dCX) )) ret = false;
		if (FAILED( p->get_CenterY(&__dCY) )) ret = false;
		if (FAILED( p->get_SideXLength(&__dW) )) ret = false;
		if (FAILED( p->get_SideYLength(&__dH) )) ret = false;
		if (FAILED( p->get_Rotation(&__dAngle) )) ret = false;
		if (FAILED( p->get_Skew(&__dSkew) )) ret = false;
		return ret;
	}
	HRESULT SetRectXY(MNV_STRectAffine & __stRectA) {
		return p->SetCenterLengthsRotationSkew(__stRectA.dCenterX, __stRectA.dCenterY, __stRectA.dWidth, __stRectA.dHeight, __stRectA.dRotate, 0);
	}

	bool GetFindLineParam(CMNVLineSegment &__Line, double &__dSearchLength) {
		double dX[4];
		double dY[4];
		p->get_CornerOriginX(&dX[0]);
		p->get_CornerOriginY(&dY[0]);
		p->get_CornerX_X(&dX[1]);
		p->get_CornerX_Y(&dY[1]);
		p->get_CornerY_X(&dX[2]);
		p->get_CornerY_Y(&dY[2]);
		p->get_CornerOppositeX(&dX[3]);
		p->get_CornerOppositeY(&dY[3]);
		double __dX = dX[0] - dX[1];
		double __dY = dY[0] - dY[1];
		__Line->SetStartEnd((dX[0] + dX[1]) / 2, (dY[0] + dY[1]) / 2, (dX[2] + dX[3]) / 2, (dY[2] + dY[3]) / 2);
		__dSearchLength = sqrt(__dX * __dX + __dY * __dY);
		return true;
	}

	bool LoadIni(LPCTSTR __strFile, LPCTSTR __strSection) { //m_strModel, _T("RectangleAffine"));
		Create();
		double dCenterX = CMNVIni::GetValue(__strSection, _T("CenterX"), (double) 0, __strFile);
		double dCenterY = CMNVIni::GetValue(__strSection, _T("CenterY"), (double) 0, __strFile);
		double dWidth = CMNVIni::GetValue(__strSection, _T("Width"), (double) 0, __strFile);
		double dHeight = CMNVIni::GetValue(__strSection, _T("Height"), (double) 0, __strFile);
		double dRotation = CMNVIni::GetValue(__strSection, _T("Rotation"), (double) 0, __strFile);
		double dSkew = CMNVIni::GetValue(__strSection, _T("Skew"), (double) 0, __strFile);
		return SUCCEEDED( p->SetCenterLengthsRotationSkew(dCenterX, dCenterY, dWidth, dHeight, dRotation, dSkew ));
	}
};

class MNVCircularAnnulusSection : public CComPtr<ICogCircularAnnulusSection> {
public:
	bool Create() { 
		Release();
		return SUCCEEDED( CoCreateInstance(CLSID_CogCircularAnnulusSection) );
	}
	void Release() {
		if (p != NULL) Detach()->Release();
		CComPtr<ICogCircularAnnulusSection>::Release();
	}

	MNVCircularAnnulusSection(): CComPtr<ICogCircularAnnulusSection>() { Create(); }
	~MNVCircularAnnulusSection() { Release(); }
	bool SetCenter(double __dCenterX, double __dCenterY) {
		if (p == NULL && !Create()) return false;
		if (FAILED( p->put_CenterX(__dCenterX) )) return false;
		if (FAILED( p->put_CenterY(__dCenterY) )) return false;
		return true;
	}
	bool SetSection(double __dCenterX, double __dCenterY, double __dRadius, double __dRadiusScale, double __dAngleStart, double __dAngleSpan) {
		if (p == NULL && !Create()) return false;
		return SUCCEEDED( p->SetCenterRadiusAngleStartAngleSpanRadialScale(__dCenterX, __dCenterY, __dRadius, __dAngleStart, __dAngleSpan, __dRadiusScale) );
	}
	bool SetInteractive(bool __isEnable) {
		if (p == NULL) return false;
		if ( FAILED( p->put_GraphicDOFEnable(cogCircularAnnulusSectionDOFAll) ) ) return false;
		return SUCCEEDED( p->put_Interactive(__isEnable ? VARIANT_TRUE : VARIANT_FALSE) );
	}
	bool SetStyle(CogGraphicLineStyleConstants __LineStyle, CogColorConstants __Color, int __nLineWidth) {
		if (p == NULL) return false;
		if ( FAILED( p->put_LineStyle(__LineStyle) )) return false;
		if ( FAILED( p->put_Color(__Color) )) return false;
		return SUCCEEDED( p->put_LineWidthInScreenPixels(__nLineWidth) );
	}
	bool GetCircle(double & __dCenterX, double & __dCenterY, double & __dOut, double & __dIn) {
		if (p == NULL) return false;
		double dCenterX, dCenterY, dRadius, dScale;
		if (FAILED( p->get_CenterX(&dCenterX) )) return false;
		if (FAILED( p->get_CenterY(&dCenterY) )) return false;
		if (FAILED( p->get_Radius(&dRadius) )) return false;
		if (FAILED( p->get_RadialScale(&dScale) )) return false;
		__dCenterX = dCenterX;
		__dCenterY = dCenterY;
		__dOut = dRadius;
		__dIn = __dOut * dScale;
		return true;
	}

	double GetCenterX() {
		double dValue;
		if (SUCCEEDED( p->get_CenterX(&dValue) )) return dValue;
		return 0;
	}
	double GetCenterY() {
		double dValue;
		if (SUCCEEDED( p->get_CenterY(&dValue) )) return dValue;
		return 0;
	}
	bool SetFromCircle(CMNVCircle & __Outer, CMNVCircle & __Inner, double __dSpan) {
		double dRadius = __Outer.GetRadius() - __dSpan;
		double dScale = (__Inner.GetRadius() + __dSpan) / dRadius;
		return SetSection(__Outer.GetCenterX(), __Outer.GetCenterY(), dRadius, dScale, 0, PI * 2);
	}
};
