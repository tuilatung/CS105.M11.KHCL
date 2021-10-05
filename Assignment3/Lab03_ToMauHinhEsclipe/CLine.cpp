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

	//int Dx = abs(x2 - x1);
	//int Dy = abs(y2 - y1);
	//int yStep = Dy >= 0 ? 1 : -1;

	//// Giai thuat chinh
	//int const1 = Dx << 1; // const1 = 2 * Dx
	//int const2 = (Dy - Dx) << 1; // const2 = 2 * (Dy - Dx)
	//int const3 = Dy << 1; // const3 = 2 * Dy
	//int p = const1 - Dx;

	//pDC->SetPixel(x1, y1, color);
	//while (x1 < x2)
	//{
	//	p = p < 0 ? p += const3 : p += const2;
	//	if (p < 0)
	//		pDC->SetPixel(x1, y1, color);
	//	else
	//		pDC->SetPixel(x1, ++y1, color);
	//	x1++;
	//}

	int Delta_x = abs(x2 - x1);
	int Delta_y = abs(y2 - y1);
	int p = 2 * Delta_y - Delta_x;
	int c1 = 2 * Delta_y;
	int c2 = 2 * (Delta_y - Delta_x);
	int x = x1;
	int y = y1;
	int k = 0;
	if (y1 < y2)
		k = 1;
	if (y2 < y1)
		k = -1;
	pDC->SetPixel(x1, y1, color);
	while (x <= x2)
	{
		if (p < 0)
			p += c1;
		else
		{
			p += c2;
			y += k;
		}
		x++;
		pDC->SetPixel(x, y, color);
	}
}
void CLine::_LineBresenham2(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color) {

	//int Dx = abs(x2 - x1);
	//int Dy = abs(y2 - y1);
	//int yStep = Dy >= 0 ? 1 : -1;

	//// Giai thuat chinh
	//int const1 = Dy << 1; // const1 = 2 * Dy
	//int const2 = (Dx - Dy) << 1; // const2 = 2 * (Dx - Dy)
	//int const3 = Dx << 1; // const3 = 2 * Dx
	//int p = const1 - Dx;

	//pDC->SetPixel(x1, y1, color);
	//while (y1 < y2)
	//{
	//	y1++;
	//	p = p < 0 ? p += const3 : p += const2;
	//	if (p < 0)
	//		pDC->SetPixel(x1, y1, color);
	//	else
	//		pDC->SetPixel(x1++, y1, color);
	//}
	int Delta_x = abs(x2 - x1);
	int Delta_y = abs(y2 - y1);
	int p = 2 * Delta_x - Delta_y;
	int c1 = 2 * Delta_x;
	int c2 = 2 * (Delta_x - Delta_y);
	int x = x1;
	int y = y1;
	int k = 0;
	if (x1 < x2)
		k = 1;
	if (x2 < x1)
		k = -1;
	pDC->SetPixel(x1, y1, color);
	while (y <= y2)
	{
		if (p < 0)
			p += c1;
		else
		{
			p += c2;
			x += k;
		}
		y++;
		pDC->SetPixel(x, y, color);
	}
}

void CLine::MidPoint(CDC* pDC, int x_center, int y_center, float r, COLORREF color)
{
	if (r <= 0.0)
		return;
	_MidPoint(pDC, x_center, y_center, r, color);
}

void CLine::MidPoint(CDC* pDC, CPoint center, float r, COLORREF color)
{
	MidPoint(pDC, center.x, center.y, r, color);
}

void CLine::_MidPoint(CDC* pDC, int x_center, int y_center, float r, COLORREF color)
{
	int x = 0, y = r;
	// ve 4 diem ban dau la 4 goc phan tu 
	pDC->SetPixel(x + x_center, y + y_center, color);
	pDC->SetPixel(x + x_center, -y + y_center, color);
	pDC->SetPixel(y + x_center, x + y_center, color);
	pDC->SetPixel(-y + x_center, x + y_center, color);
	int f = 1 - r;
	while (x <= (r / sqrt(2)))
	{
		x++;
		if (f < 0)
			f = f + (x << 1) + 1;
		else
		{
			y--;
			f = f + (x << 1) - (y << 1) + 5;
		}
		pDC->SetPixel(x + x_center, y + y_center, color);
		pDC->SetPixel(-x + x_center, y + y_center, color);
		pDC->SetPixel(x + x_center, -y + y_center, color);
		pDC->SetPixel(-x + x_center, -y + y_center, color);
		pDC->SetPixel(y + x_center, x + y_center, color);
		pDC->SetPixel(-y + x_center, x + y_center, color);
		pDC->SetPixel(y + x_center, -x + y_center, color);
		pDC->SetPixel(-y + x_center, -x + y_center, color);
	}
}