#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<char> str;

	while (true)
	{
		

		bool check[2] = { false };
		char i;
		
		cin >> i;
		str.push(i);
		
		if (i == '.')
		{
			int count[2] = { 0 };
			while (str.empty() != true)
			{
				if (str.top() == '(' && count[0] > 0)
				{
					count[0]--;
					check[0] = false;
				}
				if (str.top() == ')')					
				{
					count[0]++;
					check[0] = true;
				}
				if (str.top() == '[' && count[1] > 0)
				{
					count[1]--;
					check[1] = false;
				}
				if (str.top() == ']')					
				{
					count[1]++;
					check[1] = true;
				}
				str.pop();
			}

			if (count[0] == 0 && count[1] == 0)
			{
				cout << count[0] << " " << count[1];
				cout << "\nYES\n";
			}
			else
			{
				cout << count[0] << " " << count[1];
				cout << "\nNO\n";
			}

		}
	}

	
}