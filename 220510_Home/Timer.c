#include <time.h>
#include "Timer.h"

clock_t s_Tick;
float deltaTime;
float fixTime;

void Timer_Init(void)
{
	fixTime = 0.0f;
	s_Tick = clock();
}
void Timer_Check(void)
{
	clock_t start_Tick = clock();

}
int Timer_Update(a)
{
	
}
float Time_GetDelta(void)
{
	return deltaTime;
}


