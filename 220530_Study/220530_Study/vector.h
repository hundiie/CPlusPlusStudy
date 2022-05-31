#include <iostream>
#pragma once


class Vector
{
public:
	//생성자 : 필드 초기화
	Vector()// 기본 생성자
		: Vector(0, 0){}
	Vector(int x, int y)
		: _x(x), _y(y){}

	//접근자
	int getx() const
	{ 
		return _x; 
	}
	int gety() const 
	{
		return _y;
	}

	//설정자
	void setx(int x) { _x = x; }
	void sety(int y) { _y = y; }

	//벡터끼리 더하기
	Vector operator+(const Vector& data)
	{
		return Vector(_x + data._x, _y + data._y);
	}
	//벡터끼리 빼기
	Vector operator-(const Vector& data)
	{
		return Vector(_x - data._x, _y - data._y);
	}
	//스칼라 곱
	//왼쪽 피연산자 : 본인(Vector)
	//오른쪽 피연산자 : 정수 값(int)
	Vector operator*(int data) const
	{
		return Vector(_x * data, _y * data);
	}

private:
	int _x;
	int _y;
};

Vector operator*(int a, const Vector& data)
{
	return data * a;
}

std::ostream& operator<<(std::ostream& oss, const Vector& vec)
{
	oss << "Vec(" << vec.getx() << ", " << vec.gety() << ")";
	return oss;
}