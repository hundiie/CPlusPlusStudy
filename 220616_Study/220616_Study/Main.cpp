#include "common.h"

using namespace std;

struct status
{
	int HP;
	int ATK;
	int DEF;
	int STR;
	int DEX;
	int INT;

};


int main()
{
	NomalColer;
	srand(time(NULL));

	Init();
	while (true)
	{
		Play();
		Renderer();
		Input::Update();
		
	}
}