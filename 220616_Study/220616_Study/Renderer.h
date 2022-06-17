#pragma once
#include "common.h"

class Renderer
{
public:

void ScreenInit()
{
	CONSOLE_CURSOR_INFO cci;

	g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	// 커서를 숨긴다.
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(g_hScreen[0], &cci);
	SetConsoleCursorInfo(g_hScreen[1], &cci);
}
void ScreenFlipping()
{
	SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
	if (g_nScreenIndex == 0)
	{
		g_nScreenIndex = 1;
	}
	else
	{
		g_nScreenIndex = 0;
	}
}
void ScreenClear()
{
	COORD Coor = { 0, 0 };
	DWORD dw;
	FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', 80 * 40, Coor, &dw);
}
void ScreenPrint(int x, int y, char* string)
{
	DWORD dw;
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
	WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);
}
private:
	static int g_nScreenIndex;//콘솔 접근 인덱스
	static HANDLE g_hScreen[2];//콘솔2개
	int g_numOfFrame;//누적 프레임
	int g_numOfFPS;//분당 프레임

	char* FPSTextInfo;//콘솔에 출력할 char 포인터

};
int Renderer::g_nScreenIndex = 0;
HANDLE Renderer::g_hScreen[2] = {0};