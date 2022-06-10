#pragma once
#include "Common.h"

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

bool Input::s_isKeyDownOnPrevFrame[256] = { false };
bool Input::s_isKeyDownOnCurrentFrame[256] = { false };

void Input::Update(void)
{
	memcpy(Input::s_isKeyDownOnPrevFrame, Input::s_isKeyDownOnCurrentFrame, sizeof(Input::s_isKeyDownOnCurrentFrame));

	for (int vkey = 0; vkey < 256; ++vkey)
	{
		if (isKeyDown(vkey))
		{
			Input::s_isKeyDownOnCurrentFrame[vkey] = true;
		}
		else
		{
			Input::s_isKeyDownOnCurrentFrame[vkey] = false;
		}
	}
}

bool Input::GetKeyDown(int vkey)
{
	if (false == Input::s_isKeyDownOnPrevFrame[vkey] && true == Input::s_isKeyDownOnCurrentFrame[vkey])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Input::GetKeyUp(int vkey)
{
	if (true == Input::s_isKeyDownOnPrevFrame[vkey] && false == Input::s_isKeyDownOnCurrentFrame[vkey])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Input::GetKey(int vkey)
{
	if (true == Input::s_isKeyDownOnPrevFrame[vkey] && true == Input::s_isKeyDownOnCurrentFrame[vkey])
	{
		return true;
	}
	else
	{
		return false;
	}
}