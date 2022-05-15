#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Timer.h"
#include <Windows.h>
int main(void)
{
	srand(time(NULL));
	clock_t start_Tick = clock(); 
	Timer_Init();
	int a=0;
	while (true)
	{
		clock_t end_Tick = clock();
		//system("cls");
		if (Timer_Check)
		{
			a++;
		}

		float k;
		

		k = (float)(rand() % 4500 - 1);
		k /= 7;
		k *= 6;
		int j = rand() % 256 - 1;
		clock_t ela = end_Tick - start_Tick;
		int b = (ela / CLOCKS_PER_SEC); 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), j);
		printf("현재 틱 : %d   플레이 시간 : %d   누른 키 %f\n",a,b,k);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 256);
	}

}