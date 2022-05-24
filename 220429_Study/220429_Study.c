//함수를 사용하는 이유 = 코드를 재사용 하기 위해
#include <stdio.h>
#include "220429_Study.h"

//strlen() : 문자열의 길이를 구하는 함수
// 배열을 받으려면 포인터를 사용해야 한다.
// 배열을 매개변수로 받는 함수는 배열의 크기를 같이 받는다.
// 문자형의 끝은 널(NULL)이기에 배열의 크기를 알지 않아도 끝을 알 수 있다.
// 매개변수 1개 -> 문자열 저장을 위한 객체 - > POINTER TO CHAR
// const int* <- 간접 참조에는 const가 필요하다.(없으면 간접적으로 변할 수 있다.)
//int strlen(const char* str)
//{
//	int count = 0;
//	for (int i = 0; i < str[i] != '\0'; i++)
//	{
//		count++;
//	}
//	return count;
//}


//strchr() : 문자열에서 특정 문자의 위치를 찾는 것
// 1. 문자가 있는 경우 > 문자 위치 반환
// 2. 문자가 없는 경우 > null 반환

char*strchr(const char* str, const char point)
{
	for (int i = 0; i < str[i] != '\0'; i++)
	{
		if (str[i] == point)
		{
			return str[i];
		}
	}
	return NULL;
}

//포인터를 사용하는 이유
		// 다른 범위에 있는 메모리에 접근하기 위해 사용한다.
		// 
		// 메모리에 접근하는 방법은 2가지가 있다.
		// 1. 직접 참조 : 메모리 주소에 직접 접근하는 것 
		// ex) num = 10;
		// 2. 간접 참조 : 메모리 주소를 포인터를 통해서 접근하는 방법
		// ex) *T = 20;

		// Scope : 프로그램이 식별자를 찾을 수 있는 영역
		// block scope : 해당 블록에서만 찾을 수 있음 (지역 변수)
		//{int a } a; <- a를 참조하지 못함
		//file scope : 해당 파일 내에서만 찾을 수 있음(전역 변수)
		// int main 위에 쓰면 전부 참조 가능
/*
int num = 10;
int* T = &num;

printf("%d\n", T);
printf("%d\n", *T);

*T = 20;

printf("%d\n", &num);
printf("%d\n", num);
*/
/// <summary>
/// 배열의 모든 원소를 더함
/// </summary>
/// <param name="a">정수 N개가 저장된 배열</param>
/// <param name="n">배열의 크기</param>
/// <returns>배열의 모든 원소를 더한 값</returns>
//long long sum(int* a, int n)
//{
//	long long result = 0ll;
//	for (int i = 0; i < n; i++)
//	{
//		result += a[i];
//	}
//	return result;
//}
char islower(char a)
{
	if (a >= 'a' && 'z' >= a)
	{
		a = 'O';
	}
	else
	{
		a = 'X';
	}
	return a;
}
char isupper(char a)
{
	if (a >= 'A' && 'Z' >= a)
	{
		a = 'O';
	}
	else
	{
		a = 'X';
	}
	return a;
}

char tolower(char a)
{
	if (a >= 'a' && 'z' >= a)
	{
		a -= 'a' - 'A';
	}
	return a;
}
char toupper(char a)
{
	if (a >= 'A' && 'Z' >= a)
	{
		a += 'a' - 'A';
	}
	return a;
}




int sum3(int x, int y, int z)
{
	return x + y + z;
}
int main()
{
	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		int	loom = 0;
		int guest = 0;
		int floor = 0;

		scanf("%d %d %d", &floor, &loom, &guest);

		int x = guest % floor;
		int y = guest / floor;

		if (guest % floor == 0)
		{
			y = guest / floor+1;
		}
		printf("%d%02d\n", x, y);
	}
}
/*나도 못들어서 망함
	//int a = strlen("asdasdasdasdasdasdasdsadsadasdassd");
	//printf("%d\n", a);// 글자 수 세기
	
	printf("%s", strchr("asdasdadasdasdsadasdasdsadasdz", 'd'));
	
	printf("%c\n", toupper('C'));// 소 대문자 바꾸기
	printf("%c\n", toupper('c'));
	printf("%c\n", tolower('C'));
	printf("%c\n", tolower('c'));
	*/
