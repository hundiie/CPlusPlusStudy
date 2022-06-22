#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int input;
	cin >> input;

	for (int i = 0; i < input; i++)
	{
		string str;
		cin >> str;

		int check = 0;

		int count[2] = { 0 };
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != 0)
			{
				for (int j = i; j < str.size(); j++)
				{
					if (str[i] == '(')
					{
						if (str[j] == ')')
						{
							str[i] = 0;
							str[j] = 0;
						}
					}
				}
			}
		}

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != 0)
			{
				cout << "NO\n";
				check = 1;
				break;
			}
		}
		if (check != 1)
		{
			cout << "YES\n";
		}
	}
}