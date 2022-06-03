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
public:
	// const로 수식된 인스턴스 메소드
	void Boo() const
	{
		//_data += 10; // 컴파일 오류! 데이터 수정 불가능
	}
	
	// 오버로딩이 가능하다.
	void Foo() const {}
	void Foo() { _data += 10; }
	
	void Boo() { _data += 20; }

private:
	int _data;
};

class B
{
public:
	B() : _p(malloc(sizeof(int) * 3)) { }

	B(const B& other)
		: _p(malloc(sizeof(int) * 3))
	{
		for (int i = 0; i < 3; ++i)
		{
			_p[i] = other._p[i];
		}
	}

	~B() { free(_p); _p = nullptr; }

	void Foo(int index, int value)
	{
		_p[index] = value;
	}
private:
	int* _p;
};

//선언 :식별자를 컴파일러에게 알리는 것
//정의 :식별자에 관련된 정보 제공
//할당 :메모리에 값을 저장하는 것
//초기화 :정의하면서 값을 넣어주는 것

int main()
{
	B a;
	B a2 = a; // 이제는 서로 다른 영역을 가리킨다.
	a2.Foo(2, 10); // 이제는 a에게 영향을 주지 않는다.

	/*const A a;
	a.Foo(); 
	a.Boo(); */

	//sang a;
	//sog b;
	
	/*A a;
	A b;
	b = a;

	printf("%d", a);
	printf("%d", b);*/

	


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