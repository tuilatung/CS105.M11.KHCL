
// VeDuongThangView.h : interface of the CVeDuongThangView class
//

#pragma once


class CVeDuongThangView : public CView
{
protected: // create from serialization only
	CVeDuongThangView() noexcept;
	DECLARE_DYNCREATE(CVeDuongThangView)

// Attributes
public:
	CVeDuongThangDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CVeDuongThangView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in VeDuongThangView.cpp
inline CVeDuongThangDoc* CVeDuongThangView::GetDocument() const
   { return reinterpret_cast<CVeDuongThangDoc*>(m_pDocument); }
#endif

