#include <iostream>
#include "Random.h"
#include "Timer.h"
#include "Input.h"

int main()
{
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

		if (b >= 1.0f)
		{
			c++;
			printf("%d\n", c);
			
			b = 0.0f;
		}
	}
	*/

	//텍스트 테스트
	
	while (true)
	{
		if (Input::GetKeyDown(VK_UP))
		{
			printf("k");
		}
	}

}