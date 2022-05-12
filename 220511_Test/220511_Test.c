#include "Test.h"

char FF_C[3][128];

#define SRAND srand(time(NULL));
#define FGR_Defolt FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN
#define FF_R FOREGROUND_RED
#define FF_G FOREGROUND_GREEN
#define FF_B FOREGROUND_BLUE
#define FF_I FOREGROUND_INTENSITY

#define FB_R BACKGROUND_RED
#define FB_G BACKGROUND_GREEN
#define FB_B BACKGROUND_BLUE
#define FB_I BACKGROUND_INTENSITY


void TC(int a, int b)
{
	a %= 16;
	b %= 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (a + (b * 16)));
}

void CM(int a ,int b)
{
	COORD coord = { a,b };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
static int m = 10;
void AAA(void)
{
	extern int m;
}


int main(void)
{
	AAA();
	printf("%d", m);
}

	/*char* L[] = { "■","■","■■" };
	   
	int x = 0;
	int y = 3;
	while (1)
	{
		while (x <= 15)
		{
			TC(4, 0);
			int key = _getch();
			switch (key)
			{
			case 'a':y--;
				break;

			case 'd':y++;
				break;
			default:
				break;
			}

			system("cls");

			for (int i = 0; i < 3; i++)
			{
				CM(y, x + i);
				printf("%s\n", L[i]);
			}
			x++;
		}
	}
}*/


		//SetConsoleTextAttribute(h, FF_G | FF_B |FF_I );
		//GetStdHandle(STD_INPUT_HANDLE);
		//puts("Text\n");
		//GetStdHandle(STD_INPUT_HANDLE);

		//커서 위치 옮기기
		

		//for (int i = 0; i < 255; i++)
		//{
		//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
		//	printf(" 글자색 %d\n", i);
		//}
	/*while (1)
	{
		int a;
		int b;

		
		printf("글자색 : ");
		scanf_s("%d", &a);
		printf("배경색 : ");
		scanf_s("%d", &b);




		TextColer(a, b);

		printf("글자색 %d  배경색 %d\n", a, b);
	}*/

