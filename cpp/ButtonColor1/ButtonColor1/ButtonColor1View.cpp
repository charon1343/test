
// ButtonColor1View.cpp : CButtonColor1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CButtonColor1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CButtonColor1View ����/�Ҹ�

CButtonColor1View::CButtonColor1View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CButtonColor1View::~CButtonColor1View()
{
}

BOOL CButtonColor1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CButtonColor1View �׸���

void CButtonColor1View::OnDraw(CDC* /*pDC*/)
{
	CButtonColor1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CButtonColor1View �μ�


void CButtonColor1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CButtonColor1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CButtonColor1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CButtonColor1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
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


// CButtonColor1View ����

#ifdef _DEBUG
void CButtonColor1View::AssertValid() const
{
	CView::AssertValid();
}

void CButtonColor1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CButtonColor1Doc* CButtonColor1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CButtonColor1Doc)));
	return (CButtonColor1Doc*)m_pDocument;
}
#endif //_DEBUG


// CButtonColor1View �޽��� ó����
