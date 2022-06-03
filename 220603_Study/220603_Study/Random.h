#pragma once
#include <stdlib.h>
#include <time.h>

class Random
{
public:
	Random() = delete;
	~Random() = delete;
	Random(const Random&) = delete;
	Random& operator=(const Random&) = delete;//타이머 지우기

	static void Init();
	static int Get_Int_Random(int min, int max);
	static float Get_Float_Number(float min, float max);

private:
	static float normalizedRandom;

};

void  Random::Init()
{
	srand(time(NULL));
}
int  Random::Get_Int_Random(int min, int max)
{
	float normalizedRandom = rand() / (float)(RAND_MAX - 1);
	int range = max - min;
	int result = min + normalizedRandom * range;

	return result;
}
float  Random::Get_Float_Number(float min, float max)
{
	float normalizedRandom = rand() / (float)RAND_MAX;
	float range = max - min;
	float result = min + normalizedRandom * range;

	return result;
}