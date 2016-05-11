#include "struct.h"

void DrawMyline(HDC hdc, PMYLINE pLine)// 传递一条线
{
	HPEN hPen = CreatePen(pLine->penStyle, pLine->penWidth, pLine->color);
	HPEN hPenOld = (HPEN)SelectObject(hdc, hPen);
	MoveToEx(hdc, pLine->ptS.x, pLine->ptS.y, NULL);
	LineTo(hdc, pLine->ptE.x, pLine->ptE.y);
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
}

void DrawMyLines(HDC hdc, PMYLINE pLines, int iCount)// 传递一组线
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

void DrawMyRectangle(HDC hdc, PRECTANGLE grectangle)
{
	HPEN hPen = CreatePen(grectangle->brushStyle, grectangle->brushWidth, grectangle->lineColor);
	HPEN hPenOld = (HPEN)SelectObject(hdc, hPen);
	HBRUSH hBrush = CreateSolidBrush(grectangle->brushColor);
	HBRUSH hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);
	RECT rect = grectangle->rect;
	Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}

COLORREF GetMyColor(HWND hWnd)
{
	CHOOSECOLOR  cc;
	COLORREF     crCustomColors[16];
	COLORREF     crText = RGB (0, 0, 0);

	cc.lStructSize    = sizeof (CHOOSECOLOR);
	cc.hwndOwner      = hWnd;
	cc.hInstance      = NULL;
	cc.rgbResult      = RGB (0, 0, 0);
	cc.lpCustColors   = crCustomColors;
	cc.Flags          = CC_RGBINIT | CC_FULLOPEN;
	cc.lCustData      = 0;
	cc.lpfnHook       = NULL;
	cc.lpTemplateName = NULL;

	if (ChooseColor (&cc))
	{
		crText = crCustomColors[0];
		InvalidateRect (hWnd, NULL, TRUE);

		return crText;
	}
	return FALSE;
}