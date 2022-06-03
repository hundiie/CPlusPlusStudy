#include "Input.h"

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