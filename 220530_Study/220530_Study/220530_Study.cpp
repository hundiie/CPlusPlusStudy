#include <iostream>
#include "vector.h"

using namespace std;

class test
{
public://private: 사용 시 컴파일 에러

	test()//생성자
	{
		printf("hello");
	}
	~test()//소멸자
	{
		printf("world!");
	}
};

class Student
{
	const char* _name;
	int			_age;
	
public:

	Student(const char* name, int age)
	{
		_name = name;
		_age = age;
	}
private:
};

class Copy
{
public:
	//일반 생성자
	Copy(int data) : data(data)
	{
	}
	//복사 생성자
	Copy(const Copy& other): data(other.data)
	{
	}

private:
	int data;
};

class sang
{
public:
	sang() { std::cout << "부모 생성자\n"; }
	~sang() { std::cout << "부모 소멸자\n"; }
};

class sog : public sang
{
public:
	sog() { std::cout << "자식 생성자\n"; }
	~sog() { std::cout << "자식 소멸자\n"; }
};

class A
{
	void A(int& a)
	{
		int _data;
	}
public:

	// 복사 후 교환 관용구를 사용하려면 매개변수의 타입은 레퍼런스가 아니어야 한다.
	A& operator=(A a)
	{
		// std::swap()을 이용해 멤버 별로 교체해준다.
		std::swap(_data, a._data);

		return *this;
	}
};


int main()
{
	//sang a;
	//sog b;

	A a;
	A b;
	b = a;

	printf("%d", a);
	printf("%d", b);

	


	//Vector vec1(2,4);
	//Vector vec2(3, 5);
	//std::cout << vec1 << std::endl;
	//std::cout << vec2 << std::endl;
	//std::cout << vec1 + vec2 << std::endl;
	//std::cout << vec1 - vec2 << std::endl;
	//std::cout << vec1 * 2 << std::endl;
	//std::cout << 2 * vec1 << std::endl;


	//Copy c(10);
	//Copy d = c;

	//test a;


	return 0;
}