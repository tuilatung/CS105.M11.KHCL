#include "pch.h"
#include "CShape.h"
#include "CLine.h"

#define PI 3.14

void CShape::Pentagon(CDC* pDC, int xc, int yc, int r, COLORREF color)
{
	int x[5];
	int y[5];

	float alpha = -PI / 2;
	float const1 = 2 * PI / 5;
	int i;

	for (i = 0; i < 5; ++i)
	{
		x[i] = r * cos(alpha) + xc;
		y[i] = r * sin(alpha) + yc;
		alpha += const1;
	}

	for (i = 0; i < 4; i++)
		CLine::LineDDA(pDC, x[i], y[i], x[i + 1], y[i + 1], color);
	CLine::LineDDA(pDC, x[4], y[4], x[0], y[0], color);
}
//***********************************************************************************

void CShape::Hexagon(CDC* pDC, int xc, int yc, int r, COLORREF color)
{
	int x[6];
	int y[6];

	float alpha = 0;
	float const1 = PI / 3;

	int i;
	for (i = 0; i < 6; ++i)
	{
		x[i] = r * cos(alpha) + xc;
		y[i] = r * sin(alpha) + yc;
		alpha += const1;
	}

	for (i = 0; i < 5; i++)
		CLine::LineDDA(pDC, x[i], y[i], x[i + 1], y[i + 1], color);
	CLine::LineDDA(pDC, x[5], y[5], x[0], y[0], color);
}
//***********************************************************************************


void CShape::Star(CDC* pDC, CPoint I, int R, COLORREF color, int n)
{
	Star(pDC, I.x, I.y, R, color, n);
}

void CShape::Star(CDC* pDC, int xc, int yc, int R, COLORREF color, int n)
{
	float r = R * sin(PI / (2 * n)) / sin(PI - 3 * PI / (2 * n));
	int* x = new int[2 * n];
	int* y = new int[2 * n];

	float alpha = -PI / 2;
	float const1 = PI / n;
	float const2 = 2 * PI / n;

	int i;
	for (i = 0; i < 2 * n; i += 2)
	{
		x[i] = R * cos(alpha) + xc;
		y[i] = R * sin(alpha) + yc;
		//x[i+1] = r * cos(alpha) + xc; // Dùng hai dòng này để vẽ phi tiêu
		//y[i+1] = r * sin(alpha) + yc;
		x[i + 1] = r * cos(alpha + const1) + xc; //Dùng hai dòng này để vẽ sao như bình thường
		y[i + 1] = r * sin(alpha + const1) + yc;

		alpha += const2;
	}

	for (i = 0; i < 2 * n - 1; ++i)
		CLine::LineDDA(pDC, x[i], y[i], x[i + 1], y[i + 1], color);
	CLine::LineDDA(pDC, x[2 * n - 1], y[2 * n - 1], x[0], y[0], color);
}

void CShape::Ellipse(CDC* pDC, int rx, int ry, int xc, int yc, COLORREF color)
{
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;

    // Initial decision parameter of region 1
    d1 = (ry * ry) - (rx * rx * ry) +
        (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    // For region 1
    while (dx < dy)
    {

        // Print points based on 4-way symmetry
        pDC->SetPixel(x + xc, y + yc, color);
        pDC->SetPixel(-x + xc, y + yc, color);
        pDC->SetPixel(x + xc, -y + yc, color);
        pDC->SetPixel(-x + xc, -y + yc, color);
        
        // Checking and updating value of
        // decision parameter based on algorithm
        if (d1 < 0)
        {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }

    // Decision parameter of region 2
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);

    // Plotting points of region 2
    while (y >= 0)
    {

        // Print points based on 4-way symmetry
        pDC->SetPixel(x + xc, y + yc, color);
        pDC->SetPixel(-x + xc, y + yc, color);
        pDC->SetPixel(x + xc, -y + yc, color);
        pDC->SetPixel(-x + xc, -y + yc, color);

        // Checking and updating parameter
        // value based on algorithm
        if (d2 > 0)
        {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }
}