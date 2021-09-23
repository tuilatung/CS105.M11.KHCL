
// VeDuongTronView.cpp : implementation of the CVeDuongTronView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "VeDuongTron.h"
#endif

#include "VeDuongTronDoc.h"
#include "VeDuongTronView.h"
#include "CLine.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVeDuongTronView

IMPLEMENT_DYNCREATE(CVeDuongTronView, CView)

BEGIN_MESSAGE_MAP(CVeDuongTronView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CVeDuongTronView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CVeDuongTronView construction/destruction

CVeDuongTronView::CVeDuongTronView() noexcept
{
	// TODO: add construction code here

}

CVeDuongTronView::~CVeDuongTronView()
{
}

BOOL CVeDuongTronView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CVeDuongTronView drawing

void CVeDuongTronView::OnDraw(CDC* pDC)
{
	CVeDuongTronDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CLine::MidPoint(pDC, 500, 400, 300, RGB(255, 0, 0));
	// TODO: add draw code for native data here
}


// CVeDuongTronView printing


void CVeDuongTronView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CVeDuongTronView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CVeDuongTronView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CVeDuongTronView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CVeDuongTronView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CVeDuongTronView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CVeDuongTronView diagnostics

#ifdef _DEBUG
void CVeDuongTronView::AssertValid() const
{
	CView::AssertValid();
}

void CVeDuongTronView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CVeDuongTronDoc* CVeDuongTronView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVeDuongTronDoc)));
	return (CVeDuongTronDoc*)m_pDocument;
}
#endif //_DEBUG


// CVeDuongTronView message handlers
