#include <stdio.h>

int main()
{
	char* a[10][10] = { { "asdasd" ,"sdfsdf" }, { "ㅁㄴㅇ","ㄴㅇㄹ" } };

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%s ", a[i][j]);//= 0,0 asd  0,1 sdf
		}
		printf("\n");
	}
}