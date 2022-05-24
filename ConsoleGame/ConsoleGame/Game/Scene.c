#include "Scene.h"
#include "Common.h"

#include "Framework/Text.h"
#include "Framework/Input.h"
#include "Framework/Renderer.h"
#include "Framework/Timer.h"

#include "Player.h"

Scene g_Scene;

static ESceneType s_nextScene = SCENE_NULL;

void setCoord(COORD* coord, int16 x, int16 y)
{
	coord->X = x;
	coord->Y = y;
}

#pragma region TitleScene
typedef struct tagTitleSceneData
{
	Text TitleText[3][128];
	COORD TitleCoords[3];
} TitleSceneData;



void reset_title(TitleSceneData* data)
{
	TextCopyWithWhite(data->TitleText[0], L"스페이스키를");
	TextCopyWithWhite(data->TitleText[1], L"누르면");
	TextCopyWithWhite(data->TitleText[2], L"다음으로 넘어갑니다.");

	setCoord(&data->TitleCoords[0], 10, 0);
	setCoord(&data->TitleCoords[1], 25, 10);
	setCoord(&data->TitleCoords[2], 35, 20);
}

void init_title(void)
{
	g_Scene.Data = malloc(sizeof(TitleSceneData));

	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	reset_title(data);
}

void update_title(void)
{
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	if (data->TitleCoords[0].Y < 10)
	{
		static float elapsedTime;

		elapsedTime += Timer_GetDeltaTime();
		if (elapsedTime >= 0.3f)
		{
			elapsedTime = 0.0f;
			
			++data->TitleCoords[0].Y;
		}
	}

	if (data->TitleCoords[2].Y > 10)
	{
		static float elapsedTime;

		elapsedTime += Timer_GetDeltaTime();
		if (elapsedTime >= 0.3f)
		{
			elapsedTime = 0.0f;

			--data->TitleCoords[2].Y;
		}
	}

	if (Input_GetKeyDown('R'))
	{
		reset_title(data);
	}

	if (Input_GetKeyDown(VK_SPACE))
	{
		Scene_SetNextScene(SCENE_MAIN);
	}
	if (Input_GetKeyDown('1'))
	{
		Scene_SetNextScene(SCENE_SCENE3);
	}
	if (Input_GetKeyDown('2'))
	{
		Scene_SetNextScene(SCENE_SCENE4);
	}
	if (Input_GetKeyDown('3'))
	{
		Scene_SetNextScene(SCENE_SCENE5);
	}
}

void render_title(void)
{
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	for (int32 i = 0; i < 3; ++i)
	{
		Text* text = data->TitleText[i];
 		int32 len = TextLen(text);
		COORD coord = data->TitleCoords[i];
		Renderer_DrawText(text, len, coord.X, coord.Y);
	}
}

void release_title(void)
{
	free(g_Scene.Data);
	g_Scene.Data = NULL;
}

#pragma endregion

#pragma region MainScene

typedef struct tagMainSceneData
{
	Player	Player;
} MainSceneData;

void init_main(void)
{
	g_Scene.Data = malloc(sizeof(MainSceneData));

	MainSceneData* data = (MainSceneData*)g_Scene.Data;

	Player_Init(&data->Player);
}

void update_main(void)
{
	MainSceneData* data = (MainSceneData*)g_Scene.Data;

	Player_Update(&data->Player);
}

void render_main(void)
{
	MainSceneData* data = (MainSceneData*)g_Scene.Data;

	Player_Render(&data->Player);
}

void release_main(void)
{
	MainSceneData* data = (MainSceneData*)g_Scene.Data;

	Player_Release(&data->Player);

	SafeFree(g_Scene.Data);
}

#pragma endregion
#pragma region Scene3

#define MAXTEXT 3
#define ASDF char* a[128] = {L"첫번째 텍스트를 출력",L"두번째 텍스트를 출력",L"세번째 텍스트를 출력" };
typedef struct tagScene3Data
{
	Text Scene3Text[MAXTEXT][128];
	COORD Scene3Coords;
} Scene3Data;
struct Scene3Data *Scene3Text = {
	L"첫번째 텍스트를 출력"
	L"두번째 텍스트를 출력"
	L"세번째 텍스트를 출력"
};


char TEXTDAT(int g)
{
	ASDF
	return a[g];
}

void reset_scene3(Scene3Data* data)
{
	ASDF
	for (int i = 0; i < MAXTEXT; i++)
	{
		TextCopy(data->Scene3Text[i],a[i], 15);
	}
	setCoord(&data->Scene3Coords , 3, 20);
}

void init_scene3(void)
{
	g_Scene.Data = malloc(sizeof(Scene3Data));
	Scene3Data* data = (Scene3Data*)g_Scene.Data;
	
	reset_scene3(data);
}

int count = 0;

void update_scene3(void)
{
	ASDF

	Scene3Data* data = (Scene3Data*)g_Scene.Data;

	if (count > 0)
	{
		if (Input_GetKeyDown('W'))
		{
			count--;
		}
	}
	if (count < MAXTEXT - 1)
	{
		if (Input_GetKeyDown('S'))
		{
			count++;
		}
	}
	
	if (Input_GetKeyDown('F'))
	{
		switch (count)
		{
		case 0:Scene_SetNextScene(SCENE_SCENE4);
			break;
		case 1:Scene_SetNextScene(SCENE_SCENE5);
			break;
		case 2:Scene_SetNextScene(SCENE_SCENE5);
			break;
		default:
			break;
		}
	}
	
	reset_scene3(data);
	TextCopy(data->Scene3Text[count],a[count], 1);
}
void render_scene3(void)
{
	Scene3Data* data = (Scene3Data*)g_Scene.Data;

	for (int i = 0; i < MAXTEXT; i++)
	{
		Renderer_DrawText(data->Scene3Text[i], TextLen(data->Scene3Text[i]), data->Scene3Coords.X, data->Scene3Coords.Y+i);
	}
	
}

void release_scene3(void)
{
	free(g_Scene.Data);
	g_Scene.Data = NULL;
}

#pragma endregion
#pragma region Scene4
void init_scene4 (void)
{
}
void update_scene4 (void)
{
}
void render_scene4 (void)
{
}
void release_scene4(void)
{
}


#pragma endregion

#pragma region Scene5
void init_scene5(void)
{
}
void update_scene5(void)
{
}
void render_scene5(void)
{
}
void release_scene5(void)
{
}


#pragma endregion
bool Scene_IsSetNextScene(void)
{
	if (SCENE_NULL == s_nextScene)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Scene_SetNextScene(ESceneType scene)
{
	assert(s_nextScene == SCENE_NULL);
	assert(SCENE_NULL < scene && scene < SCENE_MAX);

	s_nextScene = scene;
}

void Scene_Change(void)
{
	assert(s_nextScene != SCENE_NULL);

	if (g_Scene.Release)
	{
		g_Scene.Release();
	}

	switch (s_nextScene)
	{
	case SCENE_TITLE:
		g_Scene.Init = init_title;
		g_Scene.Update = update_title;
		g_Scene.Render = render_title;
		g_Scene.Release = release_title;
		break;
	case SCENE_MAIN:
		g_Scene.Init = init_main;
		g_Scene.Update = update_main;
		g_Scene.Render = render_main;
		g_Scene.Release = release_main;
		break;
	case SCENE_SCENE3:
		g_Scene.Init = init_scene3;
		g_Scene.Update = update_scene3;
		g_Scene.Render = render_scene3;
		g_Scene.Release = release_scene3;
		break;
	case SCENE_SCENE4:
		g_Scene.Init = init_scene4;
		g_Scene.Update = update_scene4;
		g_Scene.Render = render_scene4;
		g_Scene.Release = release_scene4;
		break;
	case SCENE_SCENE5:
		g_Scene.Init = init_scene5;
		g_Scene.Update = update_scene5;
		g_Scene.Render = render_scene5;
		g_Scene.Release = release_scene5;
		break;
	}

	g_Scene.Init();

	s_nextScene = SCENE_NULL;
}