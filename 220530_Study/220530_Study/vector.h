#include <iostream>
#pragma once


class Vector
{
public:
	//������ : �ʵ� �ʱ�ȭ
	Vector()// �⺻ ������
		: Vector(0, 0){}
	Vector(int x, int y)
		: _x(x), _y(y){}

	//������
	int getx() const
	{ 
		return _x; 
	}
	int gety() const 
	{
		return _y;
	}

	//������
	void setx(int x) { _x = x; }
	void sety(int y) { _y = y; }

	//���ͳ��� ���ϱ�
	Vector operator+(const Vector& data)
	{
		return Vector(_x + data._x, _y + data._y);
	}
	//���ͳ��� ����
	Vector operator-(const Vector& data)
	{
		return Vector(_x - data._x, _y - data._y);
	}
	//��Į�� ��
	//���� �ǿ����� : ����(Vector)
	//������ �ǿ����� : ���� ��(int)
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