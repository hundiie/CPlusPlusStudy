#pragma once
#include "common.h"

class player
{
public:
	player() = delete;
	~player() = delete;
	player(const player&) = delete;
	player& operator=(const player&) = delete;

	static void printStatus()
	{
		std::string Now[6] = { "����","ü��","�ٷ�","���","���� ����Ʈ","������ ��"};
		int now[9] = { LEVEL,MAX_HP,HP,STR,LUCK,POINT,money,WSTR,DHP};

		inte_CuserMove(60, 1);
		std::cout << Now[0] << "\t" << now[0] << "\n";
		
		inte_CuserMove(60, 3);
		std::cout << Now[1] << "\t" << now[1] + now[8] << "(" << now[1] <<" + " << now[8] << ") / " << now[2] << "\n";
		inte_CuserMove(60, 4);
		std::cout << Now[2] << "\t" << now[3] + now[7] << "(" << now[3] << " + " << now[7] << ")" << "\n";

		for (int i = 3; i < 5; i++)
		{
			inte_CuserMove(60, 2 + i);
			if (i == 4)
			{
				inte_TextColer(0, 3);
			}
			std::cout << Now[i] << "\t" << now[i + 1] << "\n";
		}
		inte_TextColer(0, 15);
		for (int i = 6; i < 7; i++)
		{
			inte_CuserMove(60, 3 + 6);
			std::cout << Now[5] << "\t" << now[6] << "\n";
		}
		inte_CuserMove(0,0);
	}
	static void talkPrint()
	{
		inte_CuserMove(20, 18);
		std::cout << TALK;
		inte_CuserMove(0,0);
	}
	static void talk(std::string tk){TALK = tk;}
	
	static int Money_CHECK(){return money;}
	static void Money_ADD(int num){money = num;}
	static void Money_PLUS(int num){money += num;}

	static int HP_CHECK() { return MAX_HP + DHP; }
	static void HP_ADD(int num)	{HP = num;}
	static void HP_PLUS(int num){HP += num;	}

private:
	static int LEVEL;
	static int MAX_HP;
	static int DHP;
	static int HP;
	static int STR;
	static int WSTR;
	static int LUCK;
	static int POINT;
	static int money;
	static std::string TALK;
};

int player::LEVEL = 1;
int player::MAX_HP = 100;
int player::DHP = 0;
int player::HP = 100;
int player::STR = 10;
int player::WSTR = 0;
int player::LUCK = 0;
int player::POINT = 0;
int player::money = 0;
std::string player::TALK = "";

