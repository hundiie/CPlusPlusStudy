#pragma once
#include "Scene.h"
#include <stdlib.h>
#include "Timer.h"
#include "Random.h"

class TitleScene : public Scene
{
public:
	virtual void Init() override
	{
		std::cout << "�ʱ�ȭ" << std::endl;
		Random::Init();
	}
	virtual void Update() override
	{
		int num = Random::Get_Int_Random(1, 5);
		switch (switch_on)
		{
		default:
			break;
		}
	}
	virtual void Render() override
	{
		std::cout << "����" << std::endl;
	}
	virtual void Release() override
	{
		std::cout << "������" << std::endl;
	}
private:

};