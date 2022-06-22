#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	while (true)
	{
		string str;
		getline(cin, str);
		stack<char>chr;
		if (str[0] == '.') break;

		for (int i = 0; i < str.size() - 1; i++)
		{
			if (str[i] == '(')
			{
				chr.push('(');
			}
			if (str[i] == '[')
			{
				chr.push('[');
			}
			if (str[i] == ')')
			{
				if (!chr.empty() && chr.top() == '(')
				{
					chr.pop();
				}
				else
				{
					cout <<"no\n";
					break;
				}
			}
			if (str[i] == ']')
			{
				if (!chr.empty() && chr.top() == '[')
				{
					chr.pop();
				}
				else
				{
					cout << "no\n";
					break;
				}
			}

			if (chr.empty() && i == str.size() - 2)
			{
				cout << "yes\n";
			}
			else if (!chr.empty() && i == str.size() - 2)
			{
				cout << "no\n";
			}
		}
	}
}