
// VeDuongThangView.cpp : implementation of the CVeDuongThangView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "VeDuongThang.h"
#endif

#include "VeDuongThangDoc.h"
#include "VeDuongThangView.h"
#include "CLine.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVeDuongThangView

IMPLEMENT_DYNCREATE(CVeDuongThangView, CView)

BEGIN_MESSAGE_MAP(CVeDuongThangView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CVeDuongThangView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CVeDuongThangView construction/destruction

CVeDuongThangView::CVeDuongThangView() noexcept
{
	// TODO: add construction code here

}

CVeDuongThangView::~CVeDuongThangView()
{
}

BOOL CVeDuongThangView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CVeDuongThangView drawing

void CVeDuongThangView::OnDraw(CDC* pDC)
{
	CVeDuongThangDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CLine::LineDDA(pDC, 100, 100, 300, 300, RGB(255, 0, 0));
	CLine::LineDDA(pDC, 300, 100, 100, 300, RGB(0, 0, 0));
	CLine::LineBresenham(pDC, 300, 500, 600, 600, RGB(255, 255, 0));
	CLine::LineBresenham(pDC, 600, 600, 300, 400, RGB(255, 0, 0));
	// TODO: add draw code for native data here
}


// CVeDuongThangView printing


void CVeDuongThangView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CVeDuongThangView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CVeDuongThangView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CVeDuongThangView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CVeDuongThangView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CVeDuongThangView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CVeDuongThangView diagnostics

#ifdef _DEBUG
void CVeDuongThangView::AssertValid() const
{
	CView::AssertValid();
}

void CVeDuongThangView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CVeDuongThangDoc* CVeDuongThangView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVeDuongThangDoc)));
	return (CVeDuongThangDoc*)m_pDocument;
}
#endif //_DEBUG


// CVeDuongThangView message handlers
