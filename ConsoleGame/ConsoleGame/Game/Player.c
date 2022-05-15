#include "Player.h"

#include "Framework/Input.h"
#include "Framework/Renderer.h"

void Player_Init(Player* player)
{
	TextCopyWithWhite(&player->Text, L"P");
	SetCoord(player->Coord, 0, 0);
	Gun_Init(&player->Gun);
	Gun_Init1(&player->Gun1);
}

void Player_Update(Player* player)
{
	if (Input_GetKey(VK_DOWN))
	{
		++player->Coord.Y;
	}

	if (Input_GetKey(VK_UP))
	{
		--player->Coord.Y;
	}

	if (Input_GetKey(VK_LEFT))
	{
		--player->Coord.X;
	}

	if (Input_GetKey(VK_RIGHT))
	{
		++player->Coord.X;
	}

	if (Input_GetKeyDown('1'))
	{
		Gun_Shoot(&player->Gun, player->Coord.X + 1, player->Coord.Y);
	}
	
	if (Input_GetKeyDown('2'))
	{
		Gun_Shoot(&player->Gun1, player->Coord.X + 1, player->Coord.Y);
	}

	Gun_Update(&player->Gun);
	Gun_Update(&player->Gun1);
}

void Player_Render(Player* player)
{
	Text* text = &player->Text;
	Renderer_DrawText(text, 1, player->Coord.X, player->Coord.Y);

	Gun_Render(&player->Gun);
	Gun_Render(&player->Gun1);
}

void Player_Release(Player* player)
{
	Gun_Release(&player->Gun);
	Gun_Release(&player->Gun1);
}