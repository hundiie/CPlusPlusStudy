#pragma once
#include "common.h"

using namespace std;

template <typename T>
void Print(string name, T age)
{
	cout << "|" << setw(12) << left << name << "|" << setw(12) << right << age << "|" << "\n";
}

class Player
{
	struct status
	{
		std::string name;
		int HP;
		int ATK;
		bool Stat_C;
		int STR;
		int DEX;
		int INT;
		int LUC;
	}Object;

public:
	void Init()
	{
		Object.HP = 100;
		Object.ATK = 10;
		Object.Stat_C = false;
	}
	
	void name(std::string name)
	{
		Object.name = name;
	}

	void status_Seting()
	{
		while (Object.Stat_C == false)
		{
			system("cls");

			int random[4];
			
			for (int i = 0; i < 4; i++)
			{
				random[i] = rand() % 8 + 3;
			}
		
			Object.STR = random[0];
			cout << "힘   :"<<  setw(3) <<right << random[0] << endl;
			Object.DEX = random[1];
			cout << "민첩 :" << setw(3) << right << random[1] << endl;
			Object.INT = random[2];
			cout << "지능 :" << setw(3) << right << random[2] << endl;
			Object.LUC = random[3];
			cout <<"행운 :" << setw(3) << right << random[3] << endl;
			cout << "확인 : Z" << endl;
			int key = _getch();
			switch (key)
			{
			case'z':case'Z':Object.Stat_C = true;
				break;
			default:
				break;
			}
		}
	}
	void Print_stat()
	{
		Print(("선택지 " + 2), 3);
		Print("| 이름", Object.name);
		Print("| 체력", Object.HP);
		Print("| 공격력", Object.ATK);
		Print("| 힘", Object.STR);
		Print("| 민첩", Object.DEX);
		Print("| 지능", Object.INT);
		Print("| 행운", Object.LUC);
	}
private:
};

//Player MY;
//void Init()
//{

	//MY.Init();
	//
	//string NAME;
	//cout << "플레이어 이름 입력 : ";
	//cin >> NAME;
	//MY.name(NAME);
	//MY.status_Seting();

	//cls;
	//MY.Print_stat();
