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