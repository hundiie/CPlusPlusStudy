#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int main()
{
	string Map[22][22][2];
	int Player[2];
	int Wall[2];
	srand(time(NULL));
	int TimeCount = 10;
	int WallCount[2];
	int num;
	WallCount[0] = TimeCount;

	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			Map[i][j][1] = 1;
		}
	}
	for (int i = 1; i < 21; i++)
	{
		for (int j = 1; j < 21; j++)
		{
			Map[i][j][1] = 0;
		}
	}
	
	//for (int i = 1; i < 2; i++)

	Wall[0] = 12;//rand() % 19 + 2;
	Wall[1] = 12;//rand() % 19 + 2;
	
	Player[0] = 10;//rand() % 20 + 2;
	Player[1] = 10;//rand() % 20 + 2;

	while (true)
	{
		TimeCount++;
		
		Map[Wall[0]][Wall[1]][1] = 1;
		Map[Player[0]][Player[1]][1] = 3;

		for (int i = 0; i < 22; i++)
		{
			for (int j = 0; j < 22; j++)
			{
				switch (Map[i][j][1])
				{
				case 1 : Map[i][j][0] == "■";
					break;
				default:
					break;
				{
					
				}
			}
		}



		system("cls");
		for (int i = 0; i < 22; i++)
		{
			for (int j = 0; j < 22; j++)
			{
				cout << Map[i][j][0];
			}
			cout << endl;
		}

		cout << "걸음 수 : " << TimeCount - 10;

#pragma region 키_인식
		int key = _getch();

		
		Map[Player[0]][Player[1]][0] = "  ";
		Map[Wall[0]][Wall[1]][0] = "  ";

		if (key < 96)//소, 대문자를 소문자로 통일화
		{
			key += 32;
		}
		switch (key)
		{
		case 97: //a
			if (Player[1] != 1)//플레이어 이동 제한
			{
				if (WallCount[0] > 5)
				{
					if (Player[0] == Wall[0] && Player[1] == Wall[1] + 1)//벽 이동
					{

						if (Wall[1] >= 2)//벽 이동 제한
						{
							Wall[1] -= 1;
						}
						else if (Player[0] == Wall[0] && Player[1] == Wall[1] + 1 && Wall[1] != 2)//벽에 끝에 막히면 안밀림
						{
							Player[1] += 1;
						}
					}
				}
				Player[1] -= 1;
			}
			break;
		case 115: //s
			if (Player[0] != 20)
			{
				if (WallCount[0] > 5)
				{
					if (Player[0] == Wall[0] - 1 && Player[1] == Wall[1])
					{
						if (Wall[0] <= 19)
						{
							Wall[0] += 1;
						}
						else if (Player[0] == Wall[0] - 1 && Player[1] == Wall[1] && Wall[0] != 19)
						{
							Player[0] -= 1;
						}
					}
				}
				Player[0] += 1;
			}
			break;
		case 100: //d
			if (Player[1] != 20)
			{
				if (WallCount[0] > 5)
				{
					if (Player[0] == Wall[0] && Player[1] == Wall[1] - 1)
					{
						if (Wall[1] <= 19)
						{
							Wall[1] += 1;
						}
						else if (Player[0] == Wall[0] && Player[1] == Wall[1] - 1 && Wall[1] != 19)
						{
							Player[1] -= 1;
						}
					}
				}
				Player[1] += 1;
			}
			break;
		case 119: //w
			if (Player[0] != 1)
			{
				if (WallCount[0] > 5)
				{
					if (Player[0] == Wall[0] + 1 && Player[1] == Wall[1])
					{
						if (Wall[0] >= 2)
						{
							Wall[0] -= 1;
						}
						else if (Player[0] == Wall[0] + 1 && Player[1] == Wall[1] && Wall[0] != 2)
						{
							Player[0] += 1;
						}
					}
				}
				Player[0] -= 1;
			}
			break;
		default: TimeCount--;
			break;
		}
#pragma endregion
	}
}