
#include "common.h"

#define GA_N 0x8000 & GetAsyncKeyState
#define CuserMove SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord)
int main(void)
{
	int x = 1;// 플레이어 좌표
	int y = 1;
	
	int shot_x=0;//총알 시작 좌표
	int shot_y=0;

	int Time_Save = 0;
	int page= 0;
	int in = 0;
	clock_t Time1 = clock();
	while (1)
	{
		clock_t Time2 = clock();
		int SecTime = (Time2 - Time1) / CLOCKS_PER_SEC;//시간 초를 구한다.

		printf("%d", SecTime);//시간을 표시한다.
	
		COORD coord = { x,y };
		CuserMove;
		printf("P");

		if (SecTime <= Time_Save&& in == 1)//스페이스를 눌렀을 때 시간+3초를 INTIME에 저장해서 3초 동안 총알이 날아가게 함
		{
			COORD coord = { shot_x,shot_y };
			CuserMove;
			printf("O");
			shot_x += 2;//총알 속도
		}
		if (GA_N(VK_UP))
		{
			y--;
		}
		if (GA_N(VK_DOWN))
		{
			y++;
		}
		if (GA_N(VK_LEFT))
		{
			x--;
		}
		if (GA_N(VK_RIGHT))
		{
			x++;
		}
		if (SecTime >= Time_Save && GA_N(VK_SPACE))
		{
			shot_x = x + 1;//총알이 시작하는 위치를 정함
			shot_y = y;//총알이 시작하는 위치를 정함
			Time_Save = SecTime + 3;//INTIME에 현재 초+3초를 저장한다.
			in = 1;//첫 총알을 발사 했는지 여부를 체크한다.
		}
		Sleep(10);
		system("cls");
	}
}