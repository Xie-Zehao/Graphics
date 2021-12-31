#include "Tool.h"

Line::Line()
{
	p0 = Vector3(0, 0, 0);
	p1 = Vector3(1, 1, 1);
}

Line::~Line()
{
}

Line::Line(Line& l)
{
	p0 = l.p0;
	p1 = l.p1;
}

void Line::MoveTo(HDC& hdc, Vector3 &v3)
{
	p0 = v3;
}

void Line::MoveTo(HDC& hdc, int x1, int y1)
{
	p0 = Vector3(x1, y1, 0);
}

void Line::LineTo(HDC& hdc, Vector3 &v3)
{
	p1 = v3;
	int dx = abs(p1.x - p0.x);
	int dy = abs(p1.y - p0.y);
	BOOL bInterChange = FALSE;
	int e, signX, signY, temp;
	signX = (p1.x > p0.x) ? 1 : ((p1.x < p0.x) ? -1 : 0);
	signY = (p1.y > p0.y) ? 1 : ((p1.y < p0.y) ? -1 : 0);
	if (dy > dx) {
		temp = dx;
		dx = dy;
		dy = temp;
		bInterChange = TRUE;
	}
	e = -dx;
	Vector3 p = p0; // 用来接收起点
	for (int i = 0; i < dx; i++) {
		SetPixel(hdc, p.x, p.y, RGB(0, 0, 0));
		if (bInterChange) {
			p.y += signY;
		}
		else {
			p.x += signX;
		}
		e += 2 * dy;
		if (e >= 0) {
			if (bInterChange) {
				p.x += signX;
			}
			else {
				p.y += signY;
			}
			e -= 2 * dx;
		}
	}
	p0 = p1;
}

void Line::LineTo(HDC& hdc, int x1,int y1)
{
	p1 = Vector3(x1,y1,0);
	int dx = abs(p1.x - p0.x);
	int dy = abs(p1.y - p0.y);
	BOOL bInterChange = FALSE;
	int e, signX, signY, temp;
	signX = (p1.x > p0.x) ? 1 : ((p1.x < p0.x) ? -1 : 0);
	signY = (p1.y > p0.y) ? 1 : ((p1.y < p0.y) ? -1 : 0);
	if (dy > dx) {
		temp = dx;
		dx = dy;
		dy = temp;
		bInterChange = TRUE;
	}
	e = -dx;
	Vector3 p = p0; // 用来接收起点
	for (int i = 0; i < dx; i++) {
		SetPixel(hdc, p.x, p.y, RGB(0, 0, 0));
		if (bInterChange) {
			p.y += signY;
		}
		else {
			p.x += signX;
		}
		e += 2 * dy;
		if (e >= 0) {
			if (bInterChange) {
				p.x += signX;
			}
			else {
				p.y += signY;
			}
			e -= 2 * dx;
		}
	}
	p0 = p1;
}
