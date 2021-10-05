#pragma once
class CLine
{
public:
	static void LineDDA(CDC* pDC, CPoint A, CPoint B, COLORREF color);
	static void LineBresenham(CDC* pDC, CPoint A, CPoint B, COLORREF color);

	static void LineDDA(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color);
	static void LineBresenham(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color);

	static void MidPoint(CDC* pDC, CPoint center, float r, COLORREF color);
	static void MidPoint(CDC* pDC, int x_center, int y_center, float r, COLORREF color);

private:
	static void _LineDDA1(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color);
	static void _LineBresenham1(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color);

	static void _LineDDA2(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color);
	static void _LineBresenham2(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color);

	static void _MidPoint(CDC* pDC, CPoint center, int r, COLORREF color);
	static void _MidPoint(CDC* pDC, int x_center, int y_center, float r, COLORREF color);
};

