#pragma once
#include <Windows.h>
#include <string.h>

class Input
{
public:
	Input() = delete;
	~Input() = delete;
	Input(const Input&) = delete;
	Input& operator=(const Input&) = delete;
	static void Update(void);
	static bool GetKeyDown(int vkey);
	static bool GetKeyUp(int vkey);
	static bool GetKey(int vkey);
private:
	static bool isKeyDown(int vkey)
	{
		if (0x8000 & GetAsyncKeyState(vkey))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	static bool s_isKeyDownOnPrevFrame[256];
	static bool s_isKeyDownOnCurrentFrame[256];
};