#pragma once
#include <time.h>


class Timer
{
public:
	Timer() = delete;
	~Timer() = delete;
	Timer(const Timer&) = delete;
	Timer& operator=(const Timer&) = delete;//타이머 지우기

	static void Init(int fps);
	static bool Update();
	static float GetDeltaTime();

private:
	static clock_t s_prevTick;
	static float s_deltaTime;
	static float s_fixedTime;

};

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