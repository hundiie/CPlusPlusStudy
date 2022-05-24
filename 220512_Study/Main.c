#include <stdbool.h>
#include <stdio.h>
#include <Windows.h>
#include <time.h>

#define SCENE(x) while (scene == x)
#define Key_Input 0x8000 & GetAsyncKeyState
#define C(x) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),x)
#define CuserMove(x,y) COORD i = {x ,y }; C(i)

struct Position
{
	float x;
	float y;
}Player,shot,mapLimit;

struct Position Player = { 1,1 };
struct Position shot = { 0,0 };
struct Position mapLimit = { 1,40 };

int scene = 0;

int main(void)
{
	//커서 숨기기
	CONSOLE_CURSOR_INFO cursorInfo = { 0,};
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	clock_t prevTick = clock();

	SCENE(0)
	{
		//clock_t currentTick = clock();
		//float SecTime = (currentTick - prevTick) / CLOCKS_PER_SEC;//시간값 구하기.

		char* Title[] = { "게임을", "시작하려면", "스페이스바" };
		CuserMove(10, 10);
		printf("%s ", Title[0]);

		printf("%s ", Title[1]);

		printf("%s ", Title[2]);
		if (Key_Input(VK_SPACE))
		{
			scene = 1;
		}
		Sleep(10);
		system("cls");
	}
	SCENE(1)
	{
		clock_t prevTick = clock();

		int Time_Save = 0;
		bool first_shot = false;

		while (1)
		{
			clock_t currentTick = clock();
			float SecTime = (currentTick - prevTick) / CLOCKS_PER_SEC;//시간값 구하기.
			printf("%.0f\n", SecTime);//시간을 표시한다.
			//----------입력부

			//키입력
			if (Key_Input(VK_UP))
			{
				if (Player.y > mapLimit.x)
				{
					Player.y--;
				}
			}
			if (Key_Input(VK_DOWN))
			{
				if (Player.y < mapLimit.y)
				{
					Player.y++;
				}
			}
			if (Key_Input(VK_LEFT))
			{
				if (Player.x > mapLimit.x)
				{
					Player.x--;
				}
			}
			if (Key_Input(VK_RIGHT))
			{
				if (Player.x < mapLimit.y)
				{
					Player.x++;
				}
			}

			if (SecTime >= Time_Save && Key_Input(VK_SPACE))
			{
				shot.x = Player.x + 1;//총알이 시작하는 위치를 정함
				shot.y = Player.y;//총알이 시작하는 위치를 정함
				Time_Save = SecTime + 3;//Time_save에 현재 시간초 + 3초를 저장한다.
				first_shot = true;//첫 총알을 발사 했는지 여부를 체크한다.
			}

			//----------출력부

			CuserMove(Player.x, Player.y);
				printf("P");

			//스페이스를 눌렀을 때 시간+3초를 Time_save에 저장해서 3초 동안 총알이 날아가게 함

			if (SecTime <= Time_Save && first_shot == true)
			{
				CuserMove(shot.x, shot.y);
					printf("O");
				shot.x += 0.8;//총알 속도
			}

			Sleep(10);
			system("cls");
		}
	}
}