#include <stdio.h>

//#define SPEED_OF_LIGHT 299792458
//#define MIN(a , b)((a) < (b) ? (a) : (b))
//#define PRINT(msg) puts(#msg);
//#define DECLEARE_MYTYPE(typename) struct MyType##typename
//#define SIMPLE_PRINT(...) puts(#__VA_ARGS__);
//#define FORMAT_PRINT(fat, ...) puts(fat, __VA_ARGS__);

int main(void)
{/*
	printf("숫자 매크로 %d\n", SPEED_OF_LIGHT);

	if(MIN(10, 20));
	{
		printf("10 20 중 작은 수는 10\n");
	}

	PRINT(안녕);

	DECLEARE_MYTYPE(student);
	{
		int a = 0;
	};

	return 0;*/

	printf("FILE : %s\n", __FILE__);
	printf("LINE : %d\n", __LINE__);
	printf("DATE : %s\n", __DATE__);
	printf("TIME : %s\n", __TIME__);

}