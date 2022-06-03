#pragma once
#include <stdlib.h>
#include <time.h>

class Random
{
public:
	Random() = delete;
	~Random() = delete;
	Random(const Random&) = delete;
	Random& operator=(const Random&) = delete;//Ÿ�̸� �����

	static void Init();
	static int GetNumberFromRange(int min, int max);
	static float GetFNumberFromRange(float min, float max);

private:
	static float normalizedRandom;

};