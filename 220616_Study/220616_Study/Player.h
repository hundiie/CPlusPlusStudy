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
			cout << "Èû   :"<<  setw(3) <<right << random[0] << endl;
			Object.DEX = random[1];
			cout << "¹ÎÃ¸ :" << setw(3) << right << random[1] << endl;
			Object.INT = random[2];
			cout << "Áö´É :" << setw(3) << right << random[2] << endl;
			Object.LUC = random[3];
			cout <<"Çà¿î :" << setw(3) << right << random[3] << endl;
			cout << "È®ÀÎ : Z" << endl;
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
		Print("| ÀÌ¸§", Object.name);
		Print("| Ã¼·Â", Object.HP);
		Print("| °ø°Ý·Â", Object.ATK);
		Print("| Èû", Object.STR);
		Print("| ¹ÎÃ¸", Object.DEX);
		Print("| Áö´É", Object.INT);
		Print("| Çà¿î", Object.LUC);
	}
private:
};

