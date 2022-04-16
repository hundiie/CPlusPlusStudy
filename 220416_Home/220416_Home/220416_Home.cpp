#include <iostream>
#include <string>
#include <conio.h>

using namespace std;
struct field
{
	string name;
	int field_num;
	string icon;

}walls,land,player_;
int main()
{
	string map[12][12];
	int mapData[12][12];
	int player[2];
	int random[2];
	int timer[2] = { 10,0 };
	int wall_num;
	int wall_timer = 0;
	int win = 0;
	int score = 0;

	player_ = { "플레이어",0, "○" };
	walls = { "벽",2, "■"};
	land = { "땅",1, "  "};
	
	srand(time(NULL));

	for (int i = 0; i < 12; i++)// 필드 생성
	{
		for (int j = 0; j < 12; j++)
		{
			mapData[i][j] = walls.field_num;
		}
	}
	for (int i = 1; i < 11; i++)// 필드에 랜덤 오브젝트 생성 평지 = 1 벽 = 2
	{
		for (int j = 1; j < 11; j++)
		{
			random[0] = rand() % 2;

			switch (random[0])
			{
			default:mapData[i][j] = land.field_num;//평지 : 1
				break;
			}
		}
	}
	player[0] = rand() % 10 + 1;
	player[1] = rand() % 10 + 1;
	mapData[player[0]][player[1]] = 0; //플레이어 : 0
	
	while (true)
	{
		if (win == 1)//게임오버 텍스트
		{
			system("cls");
			cout << "    ■■        ■      ■      ■  ■■■■" << endl;
			cout << "  ■    ■    ■  ■    ■■  ■■  ■" << endl;
			cout << "  ■         ■    ■   ■ ■■ ■  ■" << endl;
			cout << "  ■  ■■  ■■■■■  ■  ■  ■  ■■■■" << endl;
			cout << "  ■    ■  ■      ■  ■      ■  ■" << endl;
			cout << "    ■■    ■      ■  ■      ■  ■■■■" << endl;
			cout << "          ■■    ■      ■  ■■■■  ■■■" << endl;
			cout << "        ■    ■  ■      ■  ■        ■   ■" << endl;
			cout << "        ■    ■   ■    ■   ■        ■■■" << endl;
			cout << "        ■    ■    ■  ■    ■■■■  ■  ■" << endl;
			cout << "        ■    ■     ■■     ■        ■   ■" << endl;
			cout << "          ■■        ■      ■■■■  ■    ■" << endl << endl;
			cout << "                score : " << ((wall_num - 44) * 100) + score << endl;
			break;
		}
		
		system("cls");

		wall_timer++;
		
		wall_num = 0;
		wall_timer = 0;

		for (int i = 0; i < 12; i++)//맵 구현
		{
			for (int j = 0; j < 12; j++)
			{
				switch (mapData[i][j])
				{
				case 0: map[i][j] = player_.icon;
					break;
				case 1: map[i][j] = land.icon;
					break;
				case 2: map[i][j] = walls.icon;
					wall_num++;
					break;
				case 3: map[i][j] = "□";//
					wall_timer++;
					break;
				default:
					break;
				}
				cout << map[i][j];
			}
			cout << endl;
		}

		cout << "플레이어 좌표 : Y : " << 10 - player[0] << " | X : " << player[1] - 1 << endl;
		cout << "걸음 수 : " << timer[0] - 10 << endl;
		cout << "점수 : " << ((wall_num - 44) * 100) + score << endl << endl;
		cout << " 벽 하나당 점수 + 100" << endl;
		cout << " 검은 벽을 지우면 점수 + 300" << endl << endl;
		cout << " 일정 시간마다 '하얀 벽'이 생기며 시간이 지나면 '검은 벽'이 됩니다." << endl;
		cout << " '검은 벽'을 '하얀 벽'으로 밀면 '검은 벽'을 제거할 수 있습니다." << endl;
		cout << " '하얀 벽'을 밟거나 사방이 '검은 벽'으로 둘러쌓이면 패배합니다." << endl;
		
		if (timer[0] % 10 == 1 && wall_timer == 0)// 벽 생성
		{
			while (true)
			{
				random[0] = rand() % 10 + 1;
				random[1] = rand() % 10 + 1;
				if (mapData[random[0]][random[1]] == 1)
				{
					mapData[random[0]][random[1]] = 3;
					break;
				}
			}
			timer[1] = 0;
		}

		if (mapData[player[0] + 1][player[1]] == 2 && mapData[player[0] - 1][player[1]] == 2 && mapData[player[0]][player[1] + 1] == 2 && mapData[player[0]][player[1] - 1] == 2)
		{
			win++;
		}
		if (wall_timer >= 1)
		{
			if (timer[1] == 5)
			{
				for (int i = 0; i < 12; i++)
				{
					for (int j = 0; j < 12; j++)
					{
						if (mapData[i][j] == 3)
						{
							mapData[i][j] = 2;
						}
					}
				}
			}
			timer[1] ++;
		}
		int key = _getch();//키를 입력받음 플레이어의 위치값을 #으로 미리 바꿔둠;
		timer[0]++;
		mapData[player[0]][player[1]] = 1;

		if (key < 96)//입력받은 키가 대문자 일때 소문자로 통일시킴
		{
			key += 32;
		}
		switch (key)//입력받은 키를 토대로 플레이어의 위치값을 변환함
		{
		case 97: //a
			if (mapData[player[0]][player[1] - 1] == 3)//가짜 벽을 밟았을 때
			{
				win++;
			}
			if (player[1] == 1)
			{
				timer[0]--;
			}
			if (player[1] != 1)//IF조건을 걸고 맵을 넘어갈 수 없도록 제한
			{
				if (mapData[player[0]][player[1] - 1] == walls.field_num)//플레이어 앞에 벽이 있을 때
				{
					switch (mapData[player[0]][player[1] - 2])
					{
					case 1://벽 앞이 비어 있을 때 
						mapData[player[0]][player[1] - 2] = walls.field_num;
						break;
					case 2://벽 앞에 벽이 있을 때
						timer[0]--;
						player[1] += 1;
						break;
					case 3://벽 앞에 하얀 벽이 있을 때
						score += 400;
						break;
					default:
						break;
					}
				}
				player[1] -= 1;
			}
			break;
		case 115: //s
			if (mapData[player[0] + 1][player[1]] == 3)//가짜 벽을 밟았을 때
			{
				win++;
			}
			if (player[0] == 10)
			{
				timer[0]--;
				player[0] -= 1;
			}
			if (player[0] != 10)
			{
				if (mapData[player[0] + 1][player[1]] == walls.field_num)
				{
					switch (mapData[player[0] + 2][player[1]])
					{
					case 1://벽 앞이 비어 있을 때 
						mapData[player[0] + 2][player[1]] = walls.field_num;
						break;
					case 2://벽 앞에 벽이 있을 때
						timer[0]--;
						player[0] -= 1;
						break;
					case 3://벽 앞에 하얀 벽이 있을 때
						score += 400;
						break;
					default:
						break;
					}
				}
				player[0] += 1;
			}
			break;
		case 100: //d
			if (mapData[player[0]][player[1] + 1] == 3)//가짜 벽을 밟았을 때
			{
				win++;
			}
			if (player[1] == 10)
			{
				timer[0]--;
				player[1] -= 1;
			}
			if (player[1] != 10)
			{
				if (mapData[player[0]][player[1] + 1] == walls.field_num)
				{
					switch (mapData[player[0]][player[1] + 2])
					{
					case 1://벽 앞이 비어 있을 때 
						mapData[player[0]][player[1] + 2] = walls.field_num;
						break;
					case 2://벽 앞에 벽이 있을 때
						timer[0]--;
						player[1] -= 1;
						break;
					case 3://벽 앞에 하얀 벽이 있을 때
						score += 400;
						break;
					default:
						break;
					}
				}
				player[1] += 1;
			}
			break;
		case 119: //w
			if (mapData[player[0] - 1][player[1]] == 3)//가짜 벽을 밟았을 때
			{
				win++;
			}
			if (player[0] == 1)
			{
				timer[0]--;
			}
			if (player[0] != 1)
			{
				if (mapData[player[0] - 1][player[1]] == walls.field_num)
				{
					switch (mapData[player[0] - 2][player[1]])
					{
					case 1://벽 앞이 비어 있을 때 
						mapData[player[0] - 2][player[1]] = walls.field_num;
						break;
					case 2://벽 앞에 벽이 있을 때
						timer[0]--;
						player[0] += 1;
						break;
					case 3://벽 앞에 하얀 벽이 있을 때
						score += 400;
						break;
					default:
						break;
					}
				}
				player[0] -= 1;
			}
			break;
		default: timer[0]--; //방향키 이외에 입력은 넘김
			break;
		}
		mapData[player[0]][player[1]] = 0;
	}
}
