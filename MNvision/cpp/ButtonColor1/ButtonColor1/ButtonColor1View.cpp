
// ButtonColor1View.cpp : CButtonColor1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ButtonColor1.h"
#endif

#include "ButtonColor1Doc.h"
#include "ButtonColor1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CButtonColor1View

IMPLEMENT_DYNCREATE(CButtonColor1View, CView)

BEGIN_MESSAGE_MAP(CButtonColor1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CButtonColor1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CButtonColor1View 생성/소멸

CButtonColor1View::CButtonColor1View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CButtonColor1View::~CButtonColor1View()
{
}

BOOL CButtonColor1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CButtonColor1View 그리기

void CButtonColor1View::OnDraw(CDC* /*pDC*/)
{
	CButtonColor1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CButtonColor1View 인쇄


void CButtonColor1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CButtonColor1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CButtonColor1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CButtonColor1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CButtonColor1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CButtonColor1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CButtonColor1View 진단

#ifdef _DEBUG
void CButtonColor1View::AssertValid() const
{
	CView::AssertValid();
}

void CButtonColor1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CButtonColor1Doc* CButtonColor1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CButtonColor1Doc)));
	return (CButtonColor1Doc*)m_pDocument;
}
#endif //_DEBUG


// CButtonColor1View 메시지 처리기
