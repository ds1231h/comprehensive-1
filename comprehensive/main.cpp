#include "struct.h"

BOOL InitWindow(HINSTANCE hInstance, int nCmdShow);
LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void DrawMyline(HDC hdc, PMYLINE pLine);
void DrawMyLines(HDC hdc, PMYLINE pLines, int iCount);
void DrawMyEllipse(HDC hdc, PELLIPSE pEllipse);
void DrawMyRectangle(HDC hdc, PRECTANGLE pRectangle);
void DrawLineWM(HDC hdc, char* pBuff, int numLineWM);
int giCount;
int goCount;
BOOL gLoad;

int WINAPI WinMain(HINSTANCE hInstance,         //当前实例句柄
	HINSTANCE hPrevInstance,
	PSTR szCmdLine,
	int iCmdShow)
{
	MSG msg;

	if (!InitWindow(hInstance, iCmdShow))
		return FALSE;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

BOOL InitWindow(HINSTANCE hInstance, int iCmdShow)
{
	TCHAR szAppName[] = TEXT("EasyWin");
	HWND hwnd;
	WNDCLASS wcMainWnd;
	ATOM a;

	wcMainWnd.style = CS_VREDRAW | CS_HREDRAW;
	wcMainWnd.lpfnWndProc = WinProc;
	wcMainWnd.cbClsExtra = 0;
	wcMainWnd.cbWndExtra = 0;
	wcMainWnd.hInstance = hInstance;
	wcMainWnd.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wcMainWnd.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcMainWnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcMainWnd.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wcMainWnd.lpszClassName = szAppName;

	a = RegisterClass(&wcMainWnd);

	if (!a)
	{
		MessageBox(NULL, TEXT("注册窗口类失败！"), szAppName,
			MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(szAppName,
		TEXT("简易绘图——作者：穆沛"),
		WS_OVERLAPPEDWINDOW | WS_EX_LEFT,
		100,
		100,
		400,
		300,
		NULL,
		NULL,
		hInstance,
		NULL);

	if (!hwnd) return FALSE;

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);
	return TRUE;
}

LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC         hdc;
	PAINTSTRUCT ps;
	RECT        rect;
	extern MYLINE glines[1024];
	extern MYELLIPSE gellipse[1024];
	extern MYRECTANGLE grectangle[1024];
	static int drawFct = ID_DRAW_DRAWMYLINE;
	int		gDrawMode;
	HMENU hMenu;

	switch (message)
	{
	case WM_CREATE:
		goCount = 2;
		gLoad =FALSE;
		return 0;

	case WM_COMMAND:
		hMenu = GetMenu(hWnd);

		if (lParam == 0)
		{
			switch(LOWORD(wParam))
			{
			case ID_FILE_mySAVE:
				if (!MySaveData())
				{
					MessageBox(hWnd, TEXT("save data error!"), TEXT("error"), TRUE);
				}
				return 0;

			case ID_FILE_myLOAD:
				if (!MyLoadData())
				{
					MessageBox(hWnd, TEXT("load data error!"), TEXT("error"), TRUE);
				}
				return 0;

			case ID_DRAW_DRAWMYLINE:
			case ID_DRAW_DRAWMYLINES:
				gDrawMode = 1;
			case ID_DRAW_DRAWMYELLIPSE:
				gDrawMode = 3;
			case ID_DRAW_DRAWMYRECTANGLE:
				gDrawMode = 2;
				CheckMenuItem(hMenu, drawFct, MF_UNCHECKED);
				drawFct = LOWORD(wParam);
				CheckMenuItem(hMenu, drawFct, MF_UNCHECKED);
				InvalidateRect(hWnd, NULL, TRUE);
				return 0;

			case ID_SETTING_PEN:
				
				return 0;
			}
		}

		// 取得开始位置与终止位置坐标
	case WM_LBUTTONDOWN:
		if(gDrawMode == DRAW_LINE)
		{
			glines->ptS.x = GET_X_LPARAM(lParam);
			glines->ptS.y = GET_Y_LPARAM(lParam);
		}
		else if (gDrawMode == DRAW_RECT)
		{
			grectangle->rect.left = GET_X_LPARAM(lParam);
			grectangle->rect.top = GET_Y_LPARAM(lParam);
		}
		else if (gDrawMode == DRAW_ELIP)
		{
			gellipse->rect.left = GET_X_LPARAM(lParam);
			gellipse->rect.top = GET_Y_LPARAM(lParam);
		}
		return 0;

	case WM_LBUTTONUP:
		if(gDrawMode == DRAW_LINE)
		{
			glines->ptE.x = GET_X_LPARAM(lParam);
			glines->ptE.y = GET_Y_LPARAM(lParam);
		}
		else if (gDrawMode == DRAW_RECT)
		{
			grectangle->rect.right = GET_X_LPARAM(lParam);
			grectangle->rect.bottom = GET_Y_LPARAM(lParam);
		}
		else if (gDrawMode == DRAW_ELIP)
		{
			gellipse->rect.right = GET_X_LPARAM(lParam);
			gellipse->rect.bottom = GET_Y_LPARAM(lParam);
		}
		return 0;

	case WM_PAINT:
		hdc=BeginPaint (hWnd, &ps);
		GetClientRect (hWnd, &rect);
		
		switch(drawFct)
		{
		case ID_DRAW_DRAWMYLINE:
			
			DrawMyline(hdc, glines);

		case ID_DRAW_DRAWMYLINES:
			
			DrawMyLines(hdc, glines, goCount);

		case ID_DRAW_DRAWMYELLIPSE:
			
			DrawMyEllipse(hdc, gellipse);

		case ID_DRAW_DRAWMYRECTANGLE:
			
			DrawMyRectangle(hdc, grectangle);
		}
		EndPaint ( hWnd, &ps ); 
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);

}

