#include <stdio.h>
#include "struct.h"

MYLINE glines[8] = 
{
	{{25, 25}, {75, 75}},
	{{75, 25}, {25, 75}},
};

// ����һ��ͼԪ:��
void DrawLineWM(HDC hdc, char* pBuff, int numLineWM)
{
	HDC	hdcMem = CreateCompatibleDC(hdc);
	int i = 0;
	do
	{
		BYTE pNewBuff[36] = { NULL };//�����������������µĻ���������ԭ���������������»�����
		memmove(pNewBuff, pBuff, 37);
		i++;
	} while (pBuff[36] != 0);
}

BOOL MySaveData(void)
{
	FILE* fp = fopen("E:\VSworksapce\comprehensive\comprehensive\a.bin", "w+b");

	if (fp != NULL)
	{
		fwrite(&giCount, sizeof(int), 1, fp);
		fwrite(glines, sizeof(MYLINE), giCount, fp);
		fclose(fp);
		return TRUE;
	}

	return FALSE;
}

BOOL MyLoadData(void)
{
	FILE* fp = fopen("E:\VSworksapce\comprehensive\comprehensive\a.bin", "rb");

	if (fp != NULL)
	{
		fread_s(&giCount, sizeof(fp), sizeof(int), 1, fp);
		fread_s(glines, sizeof(fp), sizeof(MYLINE), giCount, fp);
		fclose(fp);
		gLoad = TRUE;
		return TRUE;
	}

	return FALSE;
}