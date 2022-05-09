#include <stdio.h>

//#define SPEED_OF_LIGHT 299792458
//#define MIN(a , b)((a) < (b) ? (a) : (b))
//#define PRINT(msg) puts(#msg);
//#define DECLEARE_MYTYPE(typename) struct MyType##typename
//#define SIMPLE_PRINT(...) puts(#__VA_ARGS__);
//#define FORMAT_PRINT(fat, ...) puts(fat, __VA_ARGS__);

//int main(void)
//{
//	printf("숫자 매크로 %d\n", SPEED_OF_LIGHT);
//
//	in(MIN(10, 20));
//	{
//		printf("10 20 중 작은 수는 10");
//	}
//
//	PRINT(안녕);
//
//	DECLEARE_MYTYPE(student);
//	{
//		int a = 0;
//	};
//
//
//
//
//
//	return 0;
//}
//함수의 식별자는 유일해야 한다. < 함수 재정의 불가능
/*
stack :정적 할당 영역 >> 함수 >> 메모리 사용량 알음
heap : 동적 할당 영역
Data : 정적 데이터
code : 프로그램 명령어

*/
//void __cdecl f1(int a, int b)
//{
//	a + b;
//}
//void __stdcall f2(int a, int b)
//{
//	a - b;
//}
//void __fastcall f3(int a, int b)
//{
//	a* b;
//}
//
//
int main()
{
	int min = 1;
	long long max;
	int K;
	int count2 = 0;
	scanf("%lld %d", &max, &K);
	while (min <= 1 && max > 1)
	{
		min++;
	}
	for (int i = min; i <= max; i++)
	{
		if (min == 1)
		{
			break;
		}
		
		int count = 0;

		for (int j = 2; j < i; j++)
		{
			if (i % j == 0 && i != j)
			{
				count2++;
				count = 1;
				break;
			}
		}
		if (count2 == K + 1)
		{	
			count2 = i;
			break;
		}
		if (max <= 1)
		{
			break;
		}
	}
	printf("%d", count2);
}

/*int main()
{
	int min;
	int max;
	int answer2 = 0;
	int answer = 0;
	int count2 = 0;

	scanf("%d", &min);
	scanf("%d", &max);
	
	if (min <= 1 && max > 1)
	{
		min++;
	}
	
	for (int i = min; i <= max; i++)
	{
		if (min == 1 && max == 1)
		{
			break;
		}
		int count = 0;
		
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0 && i != j)
			{
				
				count = 1;
				break;
			}
		}
		if (count == 0)
		{
			count2++;
			answer += i;
		}
		if (count2 == 1)
		{
			count2 = 2;
			answer2 = i;
		}
	}
	if (answer2 == 0)
	{
		printf("-1");
	}
	else
	{
		printf("%d\n", answer);
		printf("%d\n", answer2);
	}
}*/