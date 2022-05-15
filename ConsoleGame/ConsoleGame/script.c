#include "script.h"
#include "Framework/Renderer.h"

void Script_Init(Script* Script)
{
	SetCoord(Script->Coord,0, 0);
	TextCopy(Script->Text, L"A", TEXT_COLOR_MAGENTA);
}
void Script_Update(Script* Script)
{
	if (Input_GetKey(VK_DOWN))
	{
		++Script->Coord.Y;
	}

	if (Input_GetKey(VK_UP))
	{
		--Script->Coord.Y;
	}

	if (Input_GetKey(VK_LEFT))
	{
		--Script->Coord.X;
	}

	if (Input_GetKey(VK_RIGHT))
	{
		++Script->Coord.X;
	}
}
void Script_Render(Script* Script) 
{
	Text* text = &Script->Text;
	Renderer_DrawText(text, TextLen(text), Script->Coord.X, Script->Coord.Y);
}
void Script_Release(Script* Script)
{
}