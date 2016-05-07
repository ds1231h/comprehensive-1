#include <stdio.h>
#include "struct.h"

MYLINE glines[1024] = 
{
	{{25, 25}, {75, 75}, RGB(125, 64, 35), 0, PS_SOLID},
	{{75, 25}, {25, 75}, RGB(125, 64, 35), 0, PS_DASH},
};

MYELLIPSE gellipse[1024] = 
{
	{{25, 25}, RGB(125, 64, 35), RGB(125, 64, 35), 0, PS_SOLID},
	{{75, 75}, RGB(125, 64, 35), RGB(125, 64, 35), 0, PS_SOLID},
};

MYRECTANGLE grectangle[1024] = 
{
	{{25, 25}, RGB(125, 64, 35), RGB(125, 64, 35), 0, PS_SOLID},
	{{75, 75}, RGB(125, 64, 35), RGB(125, 64, 35), 0, PS_SOLID},
};

MYLINE gNewlines[1024] = {NULL};

// 管理一类图元:线
void DrawLineWM(HDC hdc, char* pBuff, int numLineWM)
{
	HDC	hdcMem = CreateCompatibleDC(hdc);
	int i = 0;
	do
	{
		BYTE pNewBuff[36] = { NULL };//缓冲区已满，开辟新的缓冲区并将原缓冲区数据移入新缓冲区
		memmove(pNewBuff, pBuff, 37);
		i++;
	} while (pBuff[36] != 0);
}


BOOL MySaveData(void)
{
	FILE* fp = fopen("E:\\VSworksapce\\comprehensive 1\\comprehensive\\a.bin", "ab");

	if (fp != NULL)
	{
		fwrite(&goCount, sizeof(int), 1, fp);
		fwrite(glines, sizeof(MYLINE), goCount, fp);
		fclose(fp);
		return TRUE;
	}

	return FALSE;
}

BOOL MyLoadData(void)
{
	FILE* fp = fopen("E:\\VSworksapce\\comprehensive 1\\comprehensive\\a.bin", "rb");

	if (fp != NULL)
	{
		fread_s(&giCount, sizeof(giCount), sizeof(int), 1, fp);
		fread_s(gNewlines, sizeof(gNewlines), sizeof(MYLINE), giCount, fp);
		fclose(fp);
		gLoad = TRUE;
		return TRUE;
	}

	return FALSE;
}