#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	stack<char> str;

	if (str.empty())
	{
		if (str.top() == 4)
		{
			str.pop();
		}
	}
}