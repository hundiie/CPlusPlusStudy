#pragma once
#include "Type.h"
#include "common.h"
#include "Framework/Text.h"

/*
필요한것

플레이어 모양
플레이어 좌표

*/



typedef struct tagScript
{
	Text*	Text;
	COORD	Coord;

} Script;

void Script_Init(Script* Script);
void Script_Update(Script* Script);
void Script_Render(Script* Script);
void Script_Release(Script* Script);

