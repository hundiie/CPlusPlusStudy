#pragma once

#include <Windows.h>

class Text
{
public:
	enum Color
	{
		TEXT_COLOR_BLACK,
		TEXT_COLOR_BLUE = FOREGROUND_BLUE,
		TEXT_COLOR_RED = FOREGROUND_RED,
		TEXT_COLOR_GREEN = FOREGROUND_GREEN,
		TEXT_COLOR_CYAN = TEXT_COLOR_BLUE | TEXT_COLOR_GREEN,
		TEXT_COLOR_MAGENTA = TEXT_COLOR_RED | TEXT_COLOR_BLUE,
		TEXT_COLOR_YELLOW = TEXT_COLOR_RED | TEXT_COLOR_GREEN,
		TEXT_COLOR_WHITE = TEXT_COLOR_RED | TEXT_COLOR_BLUE | TEXT_COLOR_GREEN,
		TEXT_COLOR_STRONG = FOREGROUND_INTENSITY
	};
	enum BackgroundColor
	{
		BACK_COLOR_BLACK,
		BACK_COLOR_BLUE = BACKGROUND_BLUE,
		BACK_COLOR_RED = BACKGROUND_RED,
		BACK_COLOR_GREEN = BACKGROUND_GREEN,
		BACK_COLOR_CYAN = BACK_COLOR_BLUE | BACK_COLOR_GREEN,
		BACK_COLOR_MAGENTA = BACK_COLOR_RED | BACK_COLOR_BLUE,
		BACK_COLOR_YELLOW = BACK_COLOR_RED | BACK_COLOR_GREEN,
		BACK_COLOR_WHITE = BACK_COLOR_RED | BACK_COLOR_BLUE | BACK_COLOR_GREEN,
		BACK_COLOR_STRONG = BACKGROUND_INTENSITY
	};
public:
	static void Copy(Text* dest, const WCHAR* src, WORD attributes)
	{
		while (*src)
		{
			dest->_info.Char.UnicodeChar = *src;
			dest->_info.Attributes = attributes;
			
			++dest;
			++src;
		}
		dest->_info.Char.UnicodeChar = L'\0';
		dest->_info.Attributes = 0;
	}
	static void Copy(Text* dest, const WCHAR* src)
	{
		Copy(dest, src, TEXT_COLOR_WHITE);
	}
	static int GetLength(const Text* text)
		{
			int result = 0;
			while (text->_info.Char.UnicodeChar)
			{
				++result;
				++text;
			}
			return result;
		}

private:
	CHAR_INFO	_info = { 0 };
};