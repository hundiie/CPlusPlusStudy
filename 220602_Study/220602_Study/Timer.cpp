#include <iostream>
#include "Timer.h"

clock_t Timer::s_prevTick = 0;
float Timer::s_deltaTime = 0.0;
float Timer::s_fixedTime = 0.0;

void Timer::Init(int fps)
{
	s_fixedTime = 1.0 / fps;
	s_prevTick = clock();
}
bool Timer::Update()
{
	clock_t currentTick = clock();

	float deltaTime = (float)(currentTick - s_prevTick) / CLOCKS_PER_SEC;

	if (deltaTime < s_fixedTime)
	{
		return false;
	}

	s_deltaTime = deltaTime;
	s_prevTick = currentTick;

	return true;
}
float Timer::GetDeltaTime()
{
	return s_deltaTime;
}