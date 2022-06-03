#include <iostream>
#include "Random.h"
#include "Timer.h"
#include "Input.h"
#include "Text.h"
#include "Renderer.h"
#include "Scene.h"
#include "TitleScene.h"


void render()
{
	Renderer::Flip();
}

int main()
{
	Scene* scene = new TitleScene();

	bool isInitialized = false;

	while (true)
	{
		if (false == isInitialized)
		{
			isInitialized = true;
			scene->Init();
		}
	}

	//랜덤 테스트
	/*
	Random::Init();

	while (true)
	{
		int a = Random::GetNumberFromRange(-100, 100);

		printf("%d\n", a);
	}
	*/

	//타이머 테스트
	/*
	float b = 0.0f;
	int c = 0;
	while (true)
	{
		Timer::Update();
		b += Timer::GetDeltaTime();

		if (b >= 0.2f)
		{
			c++;
			printf("%d\n", c);

			b = 0.0f;
		}
	}
	*/

	//텍스트 테스트
	/*
	Text text[16];
	Text::Copy(text, L"Hello World");
	printf("%d",Text::GetLength(text));
	*/

	//인풋 테스트

	Renderer::Init();
	Timer::Init(60);
	atexit(Renderer::Cleanup);

	while (true)
	{
		if (Timer::Update())
		{
			Input::Update();
			Renderer::Flip;
		}

		
		printf("UP\n");

		system("cls");
		if (Input::GetKey(VK_UP))
		{
			printf("UP\n");
		}
		if (Input::GetKey(VK_DOWN))
		{
			printf("DOWN\n");
		}
		if (Input::GetKey(VK_LEFT))
		{
			printf("LEFT\n");
		}
		if (Input::GetKey(VK_RIGHT))
		{
			printf("RIGHT\n");
		}
		

	}
	

}