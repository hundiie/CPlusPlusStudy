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
	//Ŀ�� �����
	CONSOLE_CURSOR_INFO cursorInfo = { 0,};
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	clock_t prevTick = clock();

	SCENE(0)
	{
		//clock_t currentTick = clock();
		//float SecTime = (currentTick - prevTick) / CLOCKS_PER_SEC;//�ð��� ���ϱ�.

		char* Title[] = { "������", "�����Ϸ���", "�����̽���" };
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
			float SecTime = (currentTick - prevTick) / CLOCKS_PER_SEC;//�ð��� ���ϱ�.
			printf("%.0f\n", SecTime);//�ð��� ǥ���Ѵ�.
			//----------�Էº�

			//Ű�Է�
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
				shot.x = Player.x + 1;//�Ѿ��� �����ϴ� ��ġ�� ����
				shot.y = Player.y;//�Ѿ��� �����ϴ� ��ġ�� ����
				Time_Save = SecTime + 3;//Time_save�� ���� �ð��� + 3�ʸ� �����Ѵ�.
				first_shot = true;//ù �Ѿ��� �߻� �ߴ��� ���θ� üũ�Ѵ�.
			}

			//----------��º�

			CuserMove(Player.x, Player.y);
				printf("P");

			//�����̽��� ������ �� �ð�+3�ʸ� Time_save�� �����ؼ� 3�� ���� �Ѿ��� ���ư��� ��

			if (SecTime <= Time_Save && first_shot == true)
			{
				CuserMove(shot.x, shot.y);
					printf("O");
				shot.x += 0.8;//�Ѿ� �ӵ�
			}

			Sleep(10);
			system("cls");
		}
	}
}