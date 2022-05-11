#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>

void TextColer(int a, int b)
{
	a %= 16;
	b %= 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (a + (b * 16)));
}
	int main(void)
{
		srand(time(NULL));
		//for (int i = 0; i < 255; i++)
		//{
		//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
		//	printf(" 글자색 %d\n", i);
		//}
	while (1)
	{
		int a;
		int b;

		
		printf("글자색 : ");
		scanf_s("%d", &a);
		printf("배경색 : ");
		scanf_s("%d", &b);




		TextColer(a, b);

		printf("글자색 %d  배경색 %d\n", a, b);
	}
}
