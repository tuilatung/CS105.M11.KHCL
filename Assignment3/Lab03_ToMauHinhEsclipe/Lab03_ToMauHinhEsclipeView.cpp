
// Lab03_ToMauHinhEsclipeView.cpp : implementation of the CLab03ToMauHinhEsclipeView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Lab03_ToMauHinhEsclipe.h"
#endif

#include "Lab03_ToMauHinhEsclipeDoc.h"
#include "Lab03_ToMauHinhEsclipeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLab03ToMauHinhEsclipeView

IMPLEMENT_DYNCREATE(CLab03ToMauHinhEsclipeView, CView)

BEGIN_MESSAGE_MAP(CLab03ToMauHinhEsclipeView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CLab03ToMauHinhEsclipeView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CLab03ToMauHinhEsclipeView construction/destruction

CLab03ToMauHinhEsclipeView::CLab03ToMauHinhEsclipeView() noexcept
{
	// TODO: add construction code here

}

CLab03ToMauHinhEsclipeView::~CLab03ToMauHinhEsclipeView()
{
}

BOOL CLab03ToMauHinhEsclipeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CLab03ToMauHinhEsclipeView drawing

void CLab03ToMauHinhEsclipeView::OnDraw(CDC* pDC)
{
	CLab03ToMauHinhEsclipeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CLab03ToMauHinhEsclipeView printing


void CLab03ToMauHinhEsclipeView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CLab03ToMauHinhEsclipeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLab03ToMauHinhEsclipeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLab03ToMauHinhEsclipeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CLab03ToMauHinhEsclipeView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CLab03ToMauHinhEsclipeView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CLab03ToMauHinhEsclipeView diagnostics

#ifdef _DEBUG
void CLab03ToMauHinhEsclipeView::AssertValid() const
{
	CView::AssertValid();
}

void CLab03ToMauHinhEsclipeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLab03ToMauHinhEsclipeDoc* CLab03ToMauHinhEsclipeView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLab03ToMauHinhEsclipeDoc)));
	return (CLab03ToMauHinhEsclipeDoc*)m_pDocument;
}
#endif //_DEBUG


// CLab03ToMauHinhEsclipeView message handlers
