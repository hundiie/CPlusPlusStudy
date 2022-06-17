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
		Object.STR = 0; 
		Object.DEX = 0;
		Object.INT = 0;
		Object.LUC = 0;
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
			cout << "��   :"<<  setw(3) <<right << random[0] << endl;
			Object.DEX = random[1];
			cout << "��ø :" << setw(3) << right << random[1] << endl;
			Object.INT = random[2];
			cout << "���� :" << setw(3) << right << random[2] << endl;
			Object.LUC = random[3];
			cout <<"��� :" << setw(3) << right << random[3] << endl;
			cout << "Ȯ�� : Z" << endl;
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
		Print("| �̸�", Object.name);
		Print("| ü��", Object.HP);
		Print("| ���ݷ�", Object.ATK);
		Print("| ��", Object.STR);
		Print("| ��ø", Object.DEX);
		Print("| ����", Object.INT);
		Print("| ���", Object.LUC);
	}
private:
};

