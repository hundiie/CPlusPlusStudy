#pragma once

#include "Common.h"



class Renderer
{
public:
	static bool Init(void);
	static void Cleanup(void);
	static void Flip(void);
	static void DrawTextw(char* text, int numberOfChar, int x, int y);


private:
	static HANDLE s_consoleHandle;
	static HANDLE s_screens[2];
	static int s_backIndex;
};

HANDLE Renderer::s_consoleHandle;
HANDLE Renderer::s_screens[2];
int Renderer::s_backIndex;

bool Renderer::Init(void)
{
	// 1. �ֿܼ� ���� �ڵ��� ��´�.
	s_consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (INVALID_HANDLE_VALUE == s_consoleHandle)
	{
		return false;
	}

	// 2. ��ũ���� �����.
	for (int i = 0; i < 2; ++i)
	{
		s_screens[i] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	}

	return true;
}

void Renderer::Cleanup(void)
{
	CloseHandle(s_consoleHandle);
	CloseHandle(s_screens[0]);
	CloseHandle(s_screens[1]);
}

void clear(HANDLE consoleHandle)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(consoleHandle, &csbi);

	SMALL_RECT scrollRect;
	scrollRect.Left = 0;
	scrollRect.Top = 0;
	scrollRect.Right = csbi.dwSize.X;
	scrollRect.Bottom = csbi.dwSize.Y;

	COORD scrollTarget;
	scrollTarget.X = 0;
	scrollTarget.Y = (SHORT)(0 - csbi.dwSize.Y);

	CHAR_INFO fill;
	fill.Char.UnicodeChar = TEXT(' ');
	fill.Attributes = csbi.wAttributes;

	ScrollConsoleScreenBuffer(consoleHandle, &scrollRect, NULL, scrollTarget, &fill);

	csbi.dwCursorPosition.X = 0;
	csbi.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(consoleHandle, csbi.dwCursorPosition);
}

void Renderer::Flip(void)
{
	// 1. �� ���۷� ȭ���� �����Ѵ�.
	SetConsoleActiveScreenBuffer(s_screens[s_backIndex]);

	// 2. �� ���۸� �ٲ��ش�.
	if (s_backIndex == 0)
	{
		s_backIndex = 1;
	}
	else
	{
		s_backIndex = 0;
	}

	// 3. �� ���ۿ� �ִ� ȭ���� �����ش�.
}
void Renderer::DrawTextw(char* text, int numberOfChar, int x, int y)
{
	// 1. �� ���ۿ� ���� �ڵ��� �����´�.
	HANDLE backBuffer = Renderer::s_screens[Renderer::s_backIndex];

	// 2. Ŀ�� ��ġ�� �Ű��ش�.
	COORD pos = { x, y };
	SetConsoleCursorPosition(backBuffer, pos);

	// 3. �� ���ۿ� �ؽ�Ʈ�� ����Ѵ�.
	for (int i = 0; i < numberOfChar; ++i)
	{
		SetConsoleTextAttribute(backBuffer, text[i]);
		WriteConsole(backBuffer, &text[i], 1, NULL, NULL);
	}
	SetConsoleTextAttribute(backBuffer, TEXT::TEXT_COLOR_WHITE);
}