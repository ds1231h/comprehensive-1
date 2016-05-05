#pragma once
#include <windows.h>
#include <windowsx.h>
#include "resource.h"

extern int giCount;
extern BOOL gLoad;

typedef struct Myline
{
	POINT		ptS;		// ��ʼ����
	POINT		ptE;		// ��ֹ����
	COLORREF	color;		// ����LOGPEN
	int			penWidth;
	int			penStyle;
}MYLINE, *PMYLINE;

typedef struct MyEllipse
{
	RECT		rect;		// ��Ӿ���
	COLORREF	lineColor;	// ��ɫ
	COLORREF	brushColor;	// ˢɫ
	int			brushWidth;
	int			brushStyle;	// ���Ρ�ˢ��
}MYELLIPSE, *PELLIPSE;

typedef struct MyRectangle
{
	RECT		rect;		// ��Ӿ���
	COLORREF	lineColor;	// ��ɫ
	COLORREF	brushColor;	// ˢɫ
	int			brushWidth;
	int			brushStyle;	// ���Ρ�ˢ��
}MYRECTANGLE, *PRECTANGLE;

// ��Ҫ�����������롢�ͷţ����Ҵ洢���ļ�ʱ��Ҫ�ֱ���ṹ�еĸ���������
// �������ַ�ʽ������Ӧ������ı��������
typedef struct MyText
{
	RECT		rect;
	COLORREF	MyTextColor;
	char*		pBuffer;	// ָ�뷽ʽ�ı������������������ı����������ڴ�
}MYTEXT, *PMYTEXT;

