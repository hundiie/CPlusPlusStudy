#include <iostream>
#include "Temp.h"
int main()
{
	//A<int> a;
	//A<float>b;
	////컴파일 오류 x
	////링크 오류 : 코드랑 메모리랑 연결 실패
	////a.SetData(10);
	//return 0;


	int n;

	//case 1
	int A = n * n;

	//case 2
	int B = 0;
	for (int i = 0; i < n; i++)
	{
		B += n;
	}

	//case 3
	int C;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			C += 1;
		}
	}


	

}