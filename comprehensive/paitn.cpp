#include "struct.h"

void DrawMyline(HDC hdc, PMYLINE pLine)// ����һ����
{
	HPEN hPen = CreatePen(pLine->penStyle, pLine->penWidth, pLine->color);
	HPEN hPenOld = (HPEN)SelectObject(hdc, hPen);
	MoveToEx(hdc, pLine->ptS.x, pLine->ptS.y, NULL);
	LineTo(hdc, pLine->ptE.x, pLine->ptE.y);
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
}

void DrawMyLines(HDC hdc, PMYLINE pLines, int iCount)// ����һ����
{
	for (int i = 0; i < iCount; i++)
	{
		DrawMyline(hdc, &pLines[i]);
	}
}

void DrawMyEllipse(HDC hdc, PELLIPSE pEllipse)
{
	HPEN hPen = CreatePen(pEllipse->brushStyle, pEllipse->brushWidth, pEllipse->lineColor);
	HPEN hPenOld = (HPEN)SelectObject(hdc, hPen);
	HBRUSH hBrush = CreateSolidBrush(pEllipse->brushColor);
	HBRUSH hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);
	RECT rect = pEllipse->rect;
	Ellipse(hdc, rect.left, rect.top, rect.right, rect.bottom);
	SelectObject(hdc, hPenOld);
	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}

void DrawMyRectangle(HDC hdc, PRECTANGLE pRectangle)
{
	HPEN hPen = CreatePen(pRectangle->brushStyle, pRectangle->brushWidth, pRectangle->lineColor);
	HPEN hPenOld = (HPEN)SelectObject(hdc, hPen);
	HBRUSH hBrush = CreateSolidBrush(pRectangle->brushColor);
	HBRUSH hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);
	RECT rect = pRectangle->rect;
	Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}
