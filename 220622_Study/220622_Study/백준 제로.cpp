#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int input;
	cin >> input;

	stack<int> s;

	for (int i = 0; i < input; i++)
	{
		int num;
		cin >> num;

		if (num == 0)
		{
			if (s.empty() != true)
			{
				s.pop();
			}
		}
		else
		{
			s.push(num);
		}
	}

	int answer = 0;

	while (s.empty() != true)
	{
		answer += s.top();
		s.pop();
	}
	cout << answer;
	
}