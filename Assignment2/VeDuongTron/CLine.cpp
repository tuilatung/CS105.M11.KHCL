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
