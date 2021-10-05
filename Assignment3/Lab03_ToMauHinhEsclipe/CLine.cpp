#include "pch.h"
#include "CLine.h"
int Round(double x) {
	return (int)(x + 0.5);
}

void CLine::LineDDA(CDC* pDC, CPoint A, CPoint B, COLORREF color) {

	LineDDA(pDC, A.x, A.y, B.x, B.y, color);

}

void CLine::LineBresenham(CDC* pDC, CPoint A, CPoint B, COLORREF color) {
	LineBresenham(pDC, A.x, A.y, B.x, B.y, color);
}

void CLine::LineDDA(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color) {
	// neu 2 diem trung nhau
	if ((x1 == x2) && (y1 == y2))
	{
		pDC->SetPixel(x1, y1, color);
		return;
	}

	if (abs(x2 - x1) >= abs(y2 - y1)) // lap theo x
	{
		if (x1 <= x2)
			_LineDDA1(pDC, x1, y1, x2, y2, color);
		else
			_LineDDA1(pDC, x2, y2, x1, y1, color);
	}
	else // lap theo y
	{
		if (y1 <= y2)
			_LineDDA2(pDC, x1, y1, x2, y2, color);
		else
			_LineDDA2(pDC, x2, y2, x1, y1, color);
	}
}

void CLine::LineBresenham(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color) {
	// neu 2 diem trung nhau
	if ((x1 == x2) && (y1 == y2))
	{
		pDC->SetPixel(x1, y1, color);
		return;
	}

	if (abs(x2 - x1) >= abs(y2 - y1)) // lap theo x
	{
		if (x1 <= x2)
			_LineBresenham1(pDC, x1, y1, x2, y2, color);
		else
			_LineBresenham1(pDC, x2, y2, x1, y1, color);
	}
	else // lap theo y
	{
		if (y1 <= y2)
			_LineBresenham2(pDC, x1, y1, x2, y2, color);
		else
			_LineBresenham2(pDC, x2, y2, x1, y1, color);
	}
}

void CLine::_LineDDA1(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color) { // Doan thang tang cham, giam cham

	pDC->SetPixel(x1, y1, color);
	float m = (float)(y2 - y1) / (x2 - x1);
	float y = y1;
	while (x1 < x2)
	{
		x1++;
		y += m;
		pDC->SetPixel(x1, Round(y), color);
	}
}
void CLine::_LineDDA2(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color) { // Doan thang tang nhanh, giam nhanh

	pDC->SetPixel(x1, y1, color);
	float k = (float)(x2 - x1) / (y2 - y1);
	float x = x1;
	while (y1 < y2)
	{
		y1++;
		x += k;
		pDC->SetPixel(Round(x), y1, color);
	}
}
void CLine::_LineBresenham1(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color) {

	int Dx = abs(x2 - x1);
	int Dy = abs(y2 - y1);
	int yStep = Dy >= 0 ? 1 : -1;

	// Giai thuat chinh
	int const1 = Dx << 1; // const1 = 2 * Dx
	int const2 = (Dy - Dx) << 1; // const2 = 2 * (Dy - Dx)
	int const3 = Dy << 1; // const3 = 2 * Dy
	int p = const1 - Dx;

	pDC->SetPixel(x1, y1, color);
	while (x1 < x2)
	{
		x1++;
		p = p < 0 ? p += const3 : p += const2;
		if (p < 0)
			pDC->SetPixel(x1, y1, color);
		else
			pDC->SetPixel(x1, ++y1, color);
	}
}
void CLine::_LineBresenham2(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color) {

	int Dx = abs(x2 - x1);
	int Dy = abs(y2 - y1);
	int yStep = Dy >= 0 ? 1 : -1;

	// Giai thuat chinh
	int const1 = Dy << 1; // const1 = 2 * Dy
	int const2 = (Dx - Dy) << 1; // const2 = 2 * (Dx - Dy)
	int const3 = Dx << 1; // const3 = 2 * Dx
	int p = const1 - Dx;

	pDC->SetPixel(x1, y1, color);
	while (y1 < y2)
	{
		y1++;
		p = p < 0 ? p += const3 : p += const2;
		if (p < 0)
			pDC->SetPixel(x1, y1, color);
		else
			pDC->SetPixel(x1++, y1, color);
	}
}