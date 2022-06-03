#include "Random.h"

void  Random::Init()
{
	srand(time(NULL));
}
int  Random::GetNumberFromRange(int min, int max)
{
	float normalizedRandom = rand() / (float)(RAND_MAX - 1);
	int range = max - min;
	int result = min + normalizedRandom * range;

	return result;
}
float  Random::GetFNumberFromRange(float min, float max)
{
	float normalizedRandom = rand() / (float)RAND_MAX;
	float range = max - min;
	float result = min + normalizedRandom * range;

	return result;
}