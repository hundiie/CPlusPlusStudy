#include <stdio.h>


/*
97:  //a
115: //s
100: //d
119: //w
102: //f
*/
struct weapon
{
	int* w_name;// 무기이름?
	int w_atk;//무기 공격력
	int w_up;//업글 단계
};

struct monster// 몬스터 or 광물 제작?
{
	char *name;//이름?
	int hp;//체력?
	int atk;//공격력?
	int dfe;//방어력?
	int cri;//치명타?
	int eve;//회피율?
}M1, M2, M3;

struct monster M1 = { "lv1 몹", 100 ,10, 10, 10, 10 };//예시
struct monster M2 = { "lv2 몹", 200 ,20, 15, 10, 10 };//예시
struct monster M3 = { "lv3 몹", 300 ,30, 20, 10, 10 };//예시


char screen[15][20][2];

int main(void)
{
	printf("%d", M1.atk);

	int scene = 0;//씬으로 화면 전환
	int scene_save;//인벤토리 갔을 때 돌아오는 용도

	for (int i = 0; i < 15; i++)//대충 위에 판떼기 그리는거 무시해도 됨
	{
		for (int j = 0; j < 20; j++)
		{
			screen[i][j][0] = 2;
		}
	}
	for (int i = 1; i < 14; i++)
	{
		for (int j = 1; j < 19; j++)
		{
			screen[i][j][0] = 1;
		}
	}

	int key0 = 0;
	while (scene == 0)//시작화면
	{
		system("cls");

		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 20; j++) {

				switch (screen[i][j][0])// 위에 판때기
				{
				case 1: printf("  ");
					break;
				case 2: printf("■");
					break;
				default:
					break;

				}
			}printf("\n");
		}

		if (key0 == 0)//인터페이스
		{
			printf("\n\t▶ 게임 시작\n");
			printf("\t   게임 종료\n");
		}
		else if (key0 == 1)
		{
			printf("\n\t   게임 시작\n");
			printf("\t▶ 게임 종료\n");
		}

		int key = _getch();

		if (key < 96)//입력받은 키가 대문자 일때 소문자로 통일시킴
		{
			key += 32;
		}
		switch (key)//입력받은 키를 토대로 위치값을 변환함
		{
		case 119: //w
			if (key0 == 0) { key0 = 1; }
			else { key0 = 0; }
			break;
		case 115://s
			if (key0 == 1) { key0 = 0; }
			else { key0 = 1; }
			break;
		case 102://f
			if (key0 == 0) { scene = 1; }// scene1(마을) 로 화면 이동
			if (key0 == 1) { return 0; }
			break;
		default://방향키 이외에 입력은 넘김
			break;
		}
	}
	while (1)//화면 전환 반복
	{
		int key1 = 0;
		while (scene == 1)//마을
		{
			system("cls");

			for (int i = 0; i < 15; i++)// 위에 판때기
			{
				for (int j = 0; j < 20; j++) {

					switch (screen[i][j][0])
					{
					case 1: printf("  ");
						break;
					case 2: printf("■");
						break;
					default:
						break;

					}
				}printf("\n");
			}

			if (key1 == 0)//인터페이스
			{
				printf("\n\t▶ 대장간\t   상점\n");
				printf("\t   교회  \t   던전\n");
			}
			else if (key1 == 1)
			{
				printf("\n\t   대장간\t▶ 상점\n");
				printf("\t   교회  \t   던전\n");
			}
			else if (key1 == 2)
			{
				printf("\n\t   대장간\t   상점\n");
				printf("\t▶ 교회  \t   던전\n");
			}
			else if (key1 == 3)
			{
				printf("\n\t   대장간\t   상점\n");
				printf("\t   교회  \t▶ 던전\n");
			}

			int key = _getch(); //키 입력

			if (key < 96)//입력받은 키가 대문자 일때 소문자로 통일시킴
			{
				key += 32;
			}

			switch (key)//입력받은 키를 토대로 위치값을 변환함
			{
			case 97: //a
				if (key1 == 0) { key1 = 1; }
				else if (key1 == 1) { key1 = 0; }
				else if (key1 == 2) { key1 = 3; }
				else if (key1 == 3) { key1 = 2; }
				break;
			case 115: //s
				if (key1 == 0) { key1 = 2; }
				else if (key1 == 1) { key1 = 3; }
				else if (key1 == 2) { key1 = 0; }
				else if (key1 == 3) { key1 = 1; }
				break;
			case 100: //d
				if (key1 == 0) { key1 = 1; }
				else if (key1 == 1) { key1 = 0; }
				else if (key1 == 2) { key1 = 3; }
				else if (key1 == 3) { key1 = 2; }
				break;
			case 119: //w
				if (key1 == 0) { key1 = 2; }
				else if (key1 == 1) { key1 = 3; }
				else if (key1 == 2) { key1 = 0; }
				else if (key1 == 3) { key1 = 1; }
				break;
			case 102://f
				if (key1 == 0)
				{
					scene = 2;// scene2(대장간) 으로 화면 이동
				}
				else if (key1 == 1)
				{
					scene = 3;// scene3(상점) 으로 화면 이동
				}
				else if (key1 == 2)
				{
					scene = 4;// scene4(교회) 로 화면 이동
				}
				else if (key1 == 3)
				{
					scene = 5;// scene5(던전) 으로 화면 이동
				}
				break;
			case 113://q
				scene_save = scene;//인벤토리 갔다가 다시 돌아올 장면을 저장
				scene = 100;
				break;
			default://방향키 이외에 입력은 넘김
				break;
			}
		}
		while (scene == 2)//대장간
		{
			system("cls");

			for (int i = 0; i < 15; i++)// 위에 판때기
			{
				for (int j = 0; j < 20; j++) {

					switch (screen[i][j][0])
					{
					case 1: printf("  ");
						break;
					case 2: printf("■");
						break;
					default:
						break;

					}
				}printf("\n");
			}

			if (key1 == 0)//인터페이스
			{
				printf("\n\t▶ 강화\t   제작\n");
				printf("\t   마을\n");
			}
			else if (key1 == 1)
			{
				printf("\n\t   강화\t▶ 제작\n");
				printf("\t   마을\n");
			}
			else if (key1 == 2)
			{
				printf("\n\t   강화\t   제작\n");
				printf("\t▶ 마을\n");
			}

			int key = _getch(); //키 입력

			if (key < 96)//입력받은 키가 대문자 일때 소문자로 통일시킴
			{
				key += 32;
			}

			switch (key)//입력받은 키를 토대로 위치값을 변환함
			{
			case 97: //a
				if (key1 == 0) { key1 = 1; }
				else if (key1 == 1) { key1 = 0; }
				else if (key1 == 2) { key1 = 2; }
				break;
			case 115: //s
				if (key1 == 0) { key1 = 2; }
				else if (key1 == 1) { key1 = 1; }
				else if (key1 == 2) { key1 = 0; }
				break;
			case 100: //d
				if (key1 == 0) { key1 = 1; }
				else if (key1 == 1) { key1 = 0; }
				else if (key1 == 2) { key1 = 2; }
				break;
			case 119: //w
				if (key1 == 0) { key1 = 2; }
				else if (key1 == 1) { key1 = 1; }
				else if (key1 == 2) { key1 = 0; }
				break;
			case 102://f
				if (key1 == 0)
				{
					scene = 6;// scene6(강화) 로 화면 이동
				}
				else if (key1 == 1)
				{
					scene = 7;// scene7(제작) 으로 화면 이동
				}
				else if (key1 == 2)
				{
					scene = 1;// scene1(마을) 로 화면 이동
				}
				break;
			case 113://q
				scene_save = scene;//인벤토리 갔다가 다시 돌아올 장면을 저장
				scene = 100;
				break;
			default://방향키 이외에 입력은 넘김
				break;
			}
		}
		while (scene == 3)//상점
		{
		}
		while (scene == 4)//교회
		{
		}
		while (scene == 5)//던전
		{
		}
		while (scene == 6)//강화
		{
		}
		while (scene == 7)//제작
		{
		}


		while (scene == 100)//인벤토리
		{
			system("cls");

			for (int i = 0; i < 15; i++)// 위에 판때기
			{
				for (int j = 0; j < 20; j++) {

					switch (screen[i][j][0])
					{
					case 1: printf("  ");
						break;
					case 2: printf("■");
						break;
					default:
						break;

					}
				}printf("\n");
			}

			int key = _getch(); //키 입력

			if (key < 96)//입력받은 키가 대문자 일때 소문자로 통일시킴
			{
				key += 32;
			}
			switch (key)//입력받은 키를 토대로 위치값을 변환함
			{
			case 113://q
				scene = scene_save;//save 된 씬으로 다시 돌아감
				break;
			default://방향키 이외에 입력은 넘김
				break;
			}


		}
	}
}