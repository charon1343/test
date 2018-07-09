#pragma once

// 컴퓨터에서 Microsoft Visual C++를 사용하여 생성한 IDispatch 래퍼 클래스입니다.

// 참고: 이 파일의 내용을 수정하지 마십시오. Microsoft Visual C++에서
//  이 클래스를 다시 생성할 때 수정한 내용을 덮어씁니다.

/////////////////////////////////////////////////////////////////////////////
// CCogdisplay1 래퍼 클래스입니다.

class CCogdisplay1 : public CWnd
{
protected:
	DECLARE_DYNCREATE(CCogdisplay1)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0xC009349, 0x6EF1, 0x11D4, { 0x97, 0x51, 0x0, 0x60, 0x8, 0x95, 0x71, 0xFC } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID, 
						CCreateContext* pContext = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); 
	}

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, 
				UINT nID, CFile* pPersist = NULL, BOOL bStorage = FALSE,
				BSTR bstrLicKey = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); 
	}

// 특성입니다.
public:
enum
{
    e_CogDisplay_ZoomOutOfRange = -2147205120,
    e_CogDisplay_NoSlaveFifos = -2147205119,
    e_CogDisplay_NoAutoFifoSharing = -2147205118,
    e_CogDisplay_InvalidChildSpace = -2147205117,
    e_CogDisplay_StartStopNotReentrant = -2147205116,
    e_CogDisplay_UnknownGroupName = -2147205115,
    e_CogDisplay_InvalidColormap = -2147205114
}CogDisplayErrConstants;
enum
{
    cogDisplayMouseModePointer = 0,
    cogDisplayMouseModePan = 1,
    cogDisplayMouseModeZoomIn = 2,
    cogDisplayMouseModeZoomOut = 3,
    cogDisplayMouseModeUserDefined = 4
}CogDisplayMouseModeConstants;
enum
{
    cogDisplayMouseCursorPointer = 0,
    cogDisplayMouseCursorAttention = 1,
    cogDisplayMouseCursorPanUp = 2,
    cogDisplayMouseCursorPanDown = 3,
    cogDisplayMouseCursorZoomIn = 4,
    cogDisplayMouseCursorZoomOut = 5,
    cogDisplayMouseCursorUserDefined = 6
}CogDisplayMouseCursorConstants;
enum
{
    cogDisplayScalingMethodInteger = 0,
    cogDisplayScalingMethodContinuous = 1,
    cogDisplayScalingMethodContinuousBilinear = 2
}CogDisplayScalingMethodConstants;
enum
{
    cogDisplayPanAnchorAbsolute = 0,
    cogDisplayPanAnchorRelative = 1
}CogDisplayPanAnchorConstants;
enum
{
    cogDisplayContentBitmapImage = 0,
    cogDisplayContentBitmapDisplay = 1,
    cogDisplayContentBitmapCustom = 2
}CogDisplayContentBitmapConstants;
enum
{
    cogDisplayZOrderFront = 0,
    cogDisplayZOrderBack = 1
}CogDisplayZOrderConstants;
enum
{
    cogDisplayEventMouseMove = 0,
    cogDisplayEventLMouseDown = 1,
    cogDisplayEventLMouseUp = 2,
    cogDisplayEventLMouseDblClick = 3,
    cogDisplayEventMMouseDown = 4,
    cogDisplayEventMMouseUp = 5,
    cogDisplayEventMMouseDblClick = 6,
    cogDisplayEventRMouseDown = 7,
    cogDisplayEventRMouseUp = 8,
    cogDisplayEventRMouseDblClick = 9,
    cogDisplayEventKeyDown = 10,
    cogDisplayEventKeyUp = 11
}CogDisplayEventConstants;
enum
{
    cogDisplayGraphicsFrameStateDisabled = 0,
    cogDisplayGraphicsFrameStateReady = 1,
    cogDisplayGraphicsFrameStateAttention = 2,
    cogDisplayGraphicsFrameStateDragging = 3
}CogDisplayGraphicsFrameStateConstants;
enum
{
    cogDisplay_BackColor = -501,
    cogDisplay_Image = 16859140,
    cogDisplay_HorizontalScrollBar = 16859141,
    cogDisplay_VerticalScrollBar = 16859142,
    cogDisplay_PopupMenu = 16859143,
    cogDisplay_DrawingEnabled = 16859150,
    cogDisplay_PanX = 16859154,
    cogDisplay_PanY = 16859155,
    cogDisplay_Zoom = 16859156,
    cogDisplay_MouseMode = 16859165,
    cogDisplay_ScalingMethod = 16859168,
    cogDisplay_TouchDistance = 16859171,
    cogDisplay_MultiSelectionEnabled = 16859172,
    cogDisplay_RenderEngine = 16859174,
    cogDisplay_LiveDisplayRunning = 16859178,
    cogDisplay_GridColor = 16859181,
    cogDisplay_SubPixelGridColor = 16859182,
    cogDisplay_GridEnabled = 16859183,
    cogDisplay_SubPixelGridEnabled = 16859184,
    cogDisplay_ImagePanAnchor = 16859185,
    cogDisplay_ScreenPanAnchor = 16859186,
    cogDisplay_PanXMin = 16859187,
    cogDisplay_PanXMax = 16859189,
    cogDisplay_PanYMin = 16859190,
    cogDisplay_PanYMax = 16859191,
    cogDisplay_InteractiveGraphicTipsEnabled = 16859196,
    cogDisplay_MouseCursor = 16859198,
    cogDisplay_Selection = 16859214,
    cogDisplay_AttentionGraphic = 16859241,
    cogDisplay_Enabled = 16859267,
    cogDisplay_AutoFit = 16859268,
    cogDisplay_Image8GreyColorMap = 16859271,
    cogDisplay_Image16GreyColorMap = 16859277,
    cogDisplay_ClearImage16GreyColorMap = 16859278,
    cogDisplay_Image8GreyWholeColorMap = 16859279,
    cogDisplay_ClearImage8GreyColorMap = 16859280,
    cogDisplay_AutoFitWithGraphics = 16859281,
    cogDisplay_MaintainZoom = 16859282,
    cogDisplay_Image16RangeColorMap = 16859283,
    cogDisplay_ClearImage16RangeColorMap = 16859284,
    cogDisplay_VisiblePixelMaskEnable = 16859285,
    cogDisplay_VisiblePixelMaskColor = 16859286
}CogDisplayStateIDs;
enum
{
    cogDisplayEvents_Change = 7456,
    cogDisplayEvents_MouseMove = 5206,
    cogDisplayEvents_Click = 5207,
    cogDisplayEvents_DblClick = 5208,
    cogDisplayEvents_MouseDown = 5209,
    cogDisplayEvents_MouseUp = 5210,
    cogDisplayEvents_KeyPress = 5211,
    cogDisplayEvents_KeyUp = 5212,
    cogDisplayEvents_KeyDown = 5213,
    cogDisplayEvents_DraggingStopped = 5215
}CogDisplayEventIDs;
enum
{
    cogDisplayCoordinateSpaceData_Image = 16859250,
    cogDisplayCoordinateSpaceData_DisplayFromPixelTransform = 16859251,
    cogDisplayCoordinateSpaceData_UserDisplayTree = 16859252,
    cogDisplayCoordinateSpaceData_UserPixelTree = 16859253,
    cogDisplayCoordinateSpaceData_DisplayFromPercentTransform = 16859273,
    cogDisplayCoordinateSpaceData_SelectedSpaceName = 16859255,
    cogDisplayCoordinateSpaceData_CoordinateSpaceChange = 16859256,
    cogDisplayCoordinateSpaceData_CoordinateSpaceAdd = 16859176,
    cogDisplayCoordinateSpaceData_CoordinateSpaceDelete = 16859179,
    cogDisplayCoordinateSpaceData_CoordinateSpaceMove = 16859265
}CogDisplayCoordinateSpaceDataStateIDs;


// 작업입니다.
public:

// ICogDisplay

// Functions
//

	void put_BackColor(unsigned long newValue)
	{
		static BYTE parms[] = VTS_UI4 ;
		InvokeHelper(DISPID_BACKCOLOR, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	unsigned long get_BackColor()
	{
		unsigned long result;
		InvokeHelper(DISPID_BACKCOLOR, DISPATCH_PROPERTYGET, VT_UI4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Image()
	{
		LPDISPATCH result;
		InvokeHelper(0x1014004, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void putref_Image(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x1014004, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_HorizontalScrollBar()
	{
		BOOL result;
		InvokeHelper(0x1014005, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_HorizontalScrollBar(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x1014005, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_VerticalScrollBar()
	{
		BOOL result;
		InvokeHelper(0x1014006, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_VerticalScrollBar(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x1014006, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_PopupMenu()
	{
		BOOL result;
		InvokeHelper(0x1014007, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_PopupMenu(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x1014007, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	double get_PanX()
	{
		double result;
		InvokeHelper(0x1014012, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_PanX(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0x1014012, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	double get_PanY()
	{
		double result;
		InvokeHelper(0x1014013, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_PanY(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0x1014013, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	double get_Zoom()
	{
		double result;
		InvokeHelper(0x1014014, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_Zoom(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0x1014014, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_ScalingMethod()
	{
		long result;
		InvokeHelper(0x1014020, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_ScalingMethod(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1014020, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_DrawingEnabled()
	{
		BOOL result;
		InvokeHelper(0x101400e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_DrawingEnabled(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x101400e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_MouseMode()
	{
		long result;
		InvokeHelper(0x101401d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_MouseMode(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x101401d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_MouseCursor(long Cursor)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x101403e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms, Cursor);
		return result;
	}
	void putref_MouseCursor(long Cursor, LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_I4 VTS_DISPATCH ;
		InvokeHelper(0x101403e, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms, Cursor, newValue);
	}
	BOOL get_LiveDisplayRunning()
	{
		BOOL result;
		InvokeHelper(0x101402a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void Fit(BOOL GraphicsToo)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x1014022, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GraphicsToo);
	}
	void StartLiveDisplay(LPDISPATCH AcqFifo, BOOL Own)
	{
		static BYTE parms[] = VTS_DISPATCH VTS_BOOL ;
		InvokeHelper(0x101401e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, AcqFifo, Own);
	}
	void StopLiveDisplay()
	{
		InvokeHelper(0x101401f, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void GetScreenPanAnchor(double * X, double * Y, long * Method)
	{
		static BYTE parms[] = VTS_PR8 VTS_PR8 VTS_PI4 ;
		InvokeHelper(0x1014032, DISPATCH_METHOD, VT_EMPTY, NULL, parms, X, Y, Method);
	}
	void SetScreenPanAnchor(double X, double Y, long Method)
	{
		static BYTE parms[] = VTS_R8 VTS_R8 VTS_I4 ;
		InvokeHelper(0x1014029, DISPATCH_METHOD, VT_EMPTY, NULL, parms, X, Y, Method);
	}
	void GetImagePanAnchor(double * X, double * Y, long * Method)
	{
		static BYTE parms[] = VTS_PR8 VTS_PR8 VTS_PI4 ;
		InvokeHelper(0x1014031, DISPATCH_METHOD, VT_EMPTY, NULL, parms, X, Y, Method);
	}
	void SetImagePanAnchor(double X, double Y, long Method)
	{
		static BYTE parms[] = VTS_R8 VTS_R8 VTS_I4 ;
		InvokeHelper(0x101402c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, X, Y, Method);
	}
	double get_PanXMin()
	{
		double result;
		InvokeHelper(0x1014033, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	double get_PanXMax()
	{
		double result;
		InvokeHelper(0x1014035, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	double get_PanYMin()
	{
		double result;
		InvokeHelper(0x1014036, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	double get_PanYMax()
	{
		double result;
		InvokeHelper(0x1014037, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_RenderEngine(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x1014026, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_RenderEngine()
	{
		CString result;
		InvokeHelper(0x1014026, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH QueryRenderCaps(LPCTSTR RenderCapability)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x101400d, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, RenderCapability);
		return result;
	}
	LPDISPATCH GetTransform(LPCTSTR ToSpace, LPCTSTR FromSpace)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x1014025, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, ToSpace, FromSpace);
		return result;
	}
	LPDISPATCH get_UserDisplayTree()
	{
		LPDISPATCH result;
		InvokeHelper(0x101407a, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_UserPixelTree()
	{
		LPDISPATCH result;
		InvokeHelper(0x101407b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	BOOL get_GridEnabled()
	{
		BOOL result;
		InvokeHelper(0x101402f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_GridEnabled(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x101402f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	unsigned long get_GridColor()
	{
		unsigned long result;
		InvokeHelper(0x101402d, DISPATCH_PROPERTYGET, VT_UI4, (void*)&result, NULL);
		return result;
	}
	void put_GridColor(unsigned long newValue)
	{
		static BYTE parms[] = VTS_UI4 ;
		InvokeHelper(0x101402d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_SubPixelGridEnabled()
	{
		BOOL result;
		InvokeHelper(0x1014030, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_SubPixelGridEnabled(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x1014030, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	unsigned long get_SubPixelGridColor()
	{
		unsigned long result;
		InvokeHelper(0x101402e, DISPATCH_PROPERTYGET, VT_UI4, (void*)&result, NULL);
		return result;
	}
	void put_SubPixelGridColor(unsigned long newValue)
	{
		static BYTE parms[] = VTS_UI4 ;
		InvokeHelper(0x101402e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_StaticGraphics()
	{
		LPDISPATCH result;
		InvokeHelper(0x1014039, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_InteractiveGraphics()
	{
		LPDISPATCH result;
		InvokeHelper(0x1014038, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	long get_TouchDistance()
	{
		long result;
		InvokeHelper(0x1014023, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_TouchDistance(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1014023, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_InteractiveGraphicTipsEnabled()
	{
		BOOL result;
		InvokeHelper(0x101403c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_InteractiveGraphicTipsEnabled(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x101403c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_MultiSelectionEnabled()
	{
		BOOL result;
		InvokeHelper(0x1014024, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_MultiSelectionEnabled(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x1014024, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_LostAndFound()
	{
		LPDISPATCH result;
		InvokeHelper(0x101403b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Selection()
	{
		LPDISPATCH result;
		InvokeHelper(0x101404e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_AttentionGraphic()
	{
		LPDISPATCH result;
		InvokeHelper(0x1014069, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void put_Enabled(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x1014083, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_Enabled()
	{
		BOOL result;
		InvokeHelper(0x1014083, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_AutoFit(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x1014084, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_AutoFit()
	{
		BOOL result;
		InvokeHelper(0x1014084, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_AutoFitWithGraphics(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x1014091, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_AutoFitWithGraphics()
	{
		BOOL result;
		InvokeHelper(0x1014091, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_MaintainZoom(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x1014092, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_MaintainZoom()
	{
		BOOL result;
		InvokeHelper(0x1014092, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_Image8GreyColorMap(unsigned char GreyValue, long newValue)
	{
		static BYTE parms[] = VTS_UI1 VTS_I4 ;
		InvokeHelper(0x1014087, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, GreyValue, newValue);
	}
	long get_Image8GreyColorMap(unsigned char GreyValue)
	{
		long result;
		static BYTE parms[] = VTS_UI1 ;
		InvokeHelper(0x1014087, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms, GreyValue);
		return result;
	}
	void put_Image16GreyColorMap(SAFEARRAY * * newValue)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x101408d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void ClearImage16GreyColorMap()
	{
		InvokeHelper(0x101408e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void put_Image16RangeColorMap(SAFEARRAY * * newValue)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x1014093, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void ClearImage16RangeColorMap()
	{
		InvokeHelper(0x1014094, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void put_VisiblePixelMaskEnable(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x1014095, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_VisiblePixelMaskEnable()
	{
		BOOL result;
		InvokeHelper(0x1014095, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_VisiblePixelMaskColor(unsigned long newValue)
	{
		static BYTE parms[] = VTS_UI4 ;
		InvokeHelper(0x1014096, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	unsigned long get_VisiblePixelMaskColor()
	{
		unsigned long result;
		InvokeHelper(0x1014096, DISPATCH_PROPERTYGET, VT_UI4, (void*)&result, NULL);
		return result;
	}
	void put_Image8GreyWholeColorMap(SAFEARRAY * * newValue)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x101408f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void ClearImage8GreyColorMap()
	{
		InvokeHelper(0x1014090, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	LPDISPATCH CreateMapInfo()
	{
		LPDISPATCH result;
		InvokeHelper(0x1014088, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH CreateContentBitmap(long Content, LPDISPATCH ContentRect, long BitmapSize)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 VTS_DISPATCH VTS_I4 ;
		InvokeHelper(0x101408a, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Content, ContentRect, BitmapSize);
		return result;
	}

// Properties
//



};
