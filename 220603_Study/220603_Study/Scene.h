#pragma once
#include <iostream>
#include <string>

class Scene
{
public:
	virtual void Init() = 0;		// ���� �ʱ�ȭ �ϴ� �Լ�
	virtual void Update() = 0;	// ������Ʈ
	virtual void Render() = 0;	// ����
	virtual void Release() = 0;	// ������ ����� �ڿ��� ����
};

