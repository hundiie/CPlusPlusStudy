#pragma once
#include "common.h"
#include "Player.h"



/// <summary>
/// ���ڻ� �ٲٱ�
/// </summary>
/// <param name="a">���� 0 ~ 15</param>
/// <param name="b">���ڻ� 0 ~ 15</param>
void TextColer(int a, int b)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a * 16 + b);
}

/// <summary>
/// ������ ���
/// </summary>
/// <param name="choice">������ �迭</param>
/// <param name="choiceN">������ ��</param>
void choice(std::string *choice, int choiceN)
{
	int count = 0;

	while (true)
	{
		system("cls");
		for (int i = 0; i < choiceN; i++)
		{
			if (i != count)
			{
				TextColer(0, 8);
				cout << "������ " << i + 1 << "\t" << choice[i] << endl;
			}
			else
			{
				NomalColer;
				cout << "������ " << i + 1 << "\t" << choice[i] << endl;
			}
			NomalColer;
		}
		cout<< count;

		int key = _getch();
		if (Input::GetKeyDown(VK_DOWN))
		{
			count++;
		}
		if (Input::GetKeyDown(VK_UP))
		{
			count--;
		}

		

		Input::Update();
	}
}