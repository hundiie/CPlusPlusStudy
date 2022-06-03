//#include "Text.h"
//
//void Text::TextCopy(TEXT* dest, const WCHAR* src, WORD attributes)
//{
//	while (*src)
//	{
//		dest->Char.UnicodeChar = *src;
//		dest->Attributes = attributes;
//
//		++dest;
//		++src;
//	}
//
//	dest->Char.UnicodeChar = L'\0';
//	dest->Attributes = 0;
//}
//
//int Text::TextLen(const TEXT* text)
//{
//	int result = 0;
//	while (text->Char.UnicodeChar)
//	{
//		++result;
//		++text;
//	}
//
//	return result;
//}