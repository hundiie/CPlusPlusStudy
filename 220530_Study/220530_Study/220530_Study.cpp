#include <iostream>

class test
{
public://private: 사용 시 컴파일 에러

	test()//생성자
	{
		printf("hello ");
	}
	~test()//소멸자
	{
		printf("world!");
	}
};

int main()
{
	test a;
}