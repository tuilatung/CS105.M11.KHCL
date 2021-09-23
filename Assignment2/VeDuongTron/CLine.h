#pragma once
class CLine
{
public:
	static void MidPoint(CDC* pDC, int x_center, int y_center, float r, COLORREF color);
	static void MidPoint(CDC* pDC, CPoint center, float r, COLORREF color);
private:
	static void _MidPoint(CDC* pDC, int x_center, int y_center, float r, COLORREF color);
};

