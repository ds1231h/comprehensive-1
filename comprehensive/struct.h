#pragma once
#include <windows.h>
#include <windowsx.h>
#include "resource.h"

extern int giCount;
extern BOOL gLoad;

typedef struct Myline
{
	POINT		ptS;		// 起始坐标
	POINT		ptE;		// 终止坐标
	COLORREF	color;		// 或用LOGPEN
	int			penWidth;
	int			penStyle;
}MYLINE, *PMYLINE;

typedef struct MyEllipse
{
	RECT		rect;		// 外接矩形
	COLORREF	lineColor;	// 线色
	COLORREF	brushColor;	// 刷色
	int			brushWidth;
	int			brushStyle;	// 线形、刷形
}MYELLIPSE, *PELLIPSE;

typedef struct MyRectangle
{
	RECT		rect;		// 外接矩形
	COLORREF	lineColor;	// 线色
	COLORREF	brushColor;	// 刷色
	int			brushWidth;
	int			brushStyle;	// 线形、刷形
}MYRECTANGLE, *PRECTANGLE;

// 需要处理缓冲区申请、释放，并且存储到文件时需要分别处理结构中的各个变量，
// 但是这种方式可以适应任意的文本输入情况
typedef struct MyText
{
	RECT		rect;
	COLORREF	MyTextColor;
	char*		pBuffer;	// 指针方式文本缓冲区，根据输入文本长度申请内存
}MYTEXT, *PMYTEXT;

