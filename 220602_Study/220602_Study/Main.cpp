#include <iostream>
#include "Random.h"
#include "Timer.h"
#include "Input.h"

int main()
{
	//���� �׽�Ʈ
	/*
	Random::Init();
	
	while (true)
	{
		int a = Random::GetNumberFromRange(-100, 100);

		printf("%d\n", a);
	}
	*/

	//Ÿ�̸� �׽�Ʈ
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

	//�ؽ�Ʈ �׽�Ʈ
	
	while (true)
	{
		if (Input::GetKeyDown(VK_UP))
		{
			printf("k");
		}
	}

}