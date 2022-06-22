#include <iostream>
#include <stack>

using namespace std;
#define sin(a) if(str == a)

int main()
{
	int input;
	cin >> input;

	stack<int> s;

	for (int i = 0; i < input; i++)
	{
		string str;
		cin >> str;

		sin("push")
		{
			int num;
			cin >> num;
			
			s.push(num);
		}
		sin("pop")
		{
			if (s.empty() != true)
			{
				cout << s.top() << "\n";
				s.pop();
			}
			else
			{
				cout << "-1" << "\n";
			}
		}
		sin("size")
		{
			cout << s.size() << "\n";
		}
		sin("empty")
		{
			if (s.empty() == true)
			{
				cout << "1";
			}
			else
			{
				cout << "0";
			}
			cout << "\n";
		}
		sin("top")
		{
			if (s.empty() != true)
			{
				cout << s.top() << "\n";
			}
			else
			{
				cout << "-1" << "\n";
			}
		}
	}
}