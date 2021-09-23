#include "pch.h"
#include "CLine.h"

void CLine::MidPoint(CDC* pDC, int x_center, int y_center, float r, COLORREF color)
{
	if (r <= 0.0)
		return;
	_MidPoint(pDC, x_center, y_center, r, color);
}

void CLine::_MidPoint(CDC* pDC, int x_center, int y_center, float r, COLORREF color)
{
	float f = 1 - r;
	int x = 20;
	int y = r;
	int x_new, y_new;
	pDC->SetPixel(500, 400, color);
	/*pDC->SetPixel(x + x_center, y + y_center, color);
	pDC->SetPixel(x + x_center, -y + y_center, color);
	pDC->SetPixel(y + x_center, x + y_center, color);
	pDC->SetPixel(-y + x_center, x + y_center, color);*/
	while (x <= (r/sqrt(2)))
	{
		x++;
		f = (f < 0) ? (f + (x << 1) + 3) : (f + (x << 1) - (y << 1) + 5);
		if (f < 0)
		{
			x_new = x + 1;
			y_new = y;
		}
		else
		{
			x_new = x + 1;
			y_new = --y;
		}		
		pDC->SetPixel(x_new + x_center, y_new + y_center, color);
		pDC->SetPixel(-x_new + x_center, y_new + y_center, color);
		pDC->SetPixel(x_new + x_center, -y_new + y_center, color);
		pDC->SetPixel(-x_new + x_center, -y_new + y_center, color);
		pDC->SetPixel(y_new + x_center, x_new + y_center, color);
		pDC->SetPixel(-y_new + x_center, x_new + y_center, color);
		pDC->SetPixel(y_new + x_center, -x_new + y_center, color);
		pDC->SetPixel(-y_new + x_center, -x_new + y_center, color);
	}
}
