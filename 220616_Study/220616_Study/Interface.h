#pragma once
#include "common.h"
#include "Player.h"



/// <summary>
/// 글자색 바꾸기
/// </summary>
/// <param name="a">배경색 0 ~ 15</param>
/// <param name="b">글자색 0 ~ 15</param>
void TextColer(int a, int b)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a * 16 + b);
}

/// <summary>
/// 선택지 출력
/// </summary>
/// <param name="choice">선택지 배열</param>
/// <param name="choiceN">선택지 수</param>
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
				cout << "선택지 " << i + 1 << "\t" << choice[i] << endl;
			}
			else
			{
				NomalColer;
				cout << "선택지 " << i + 1 << "\t" << choice[i] << endl;
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