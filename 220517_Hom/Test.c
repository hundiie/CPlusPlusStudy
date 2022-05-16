#include <stdio.h>
#include "test.h"



#define ad {"asd", "sdf", "dfg"};



struct MyStruct d = ad;

int main(void)
{
	char* a[128] = { "asd","sdf","dfg" };

	for (int i = 0; i < 3; i++)
	{
		printf("%s", d[i]);
	}
}