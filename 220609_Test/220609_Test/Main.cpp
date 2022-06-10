#include "Common.h"
#include <stdlib.h>

using namespace std;

bool App_Init()
{
	if (false == Renderer::Init())
	{
		return false;
	}
	return true;
}

void Input()
{
	Input::Update();
}
void Update()
{
	std::cout << "12345";
}
void Render()
{
	Renderer::Flip();
}
void App_Run()
{
	atexit(Renderer::Cleanup);

	while (true)
	{
		Input();
		Update();
		Render();
	}
}



int main()
{
	
	if (false == App_Init())
	{
		return 1;
	}
	App_Run();
	return 0;
}


