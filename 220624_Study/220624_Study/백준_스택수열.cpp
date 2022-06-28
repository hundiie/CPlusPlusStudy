#include <iostream>
#include <stack>

using namespace std;

bool check[100000] = { false };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	stack<int> sta;
	string out;
	sta.push(0);
	int num;
	cin >> num;

	bool clear = true;
	for (int i = 0; i < num; i++)
	{
		int st;
		cin >> st;

		if (sta.top() < num)
		{
			for (int j = sta.top(); j < st; j++)
			{
				if (check[j] == false)
				{
					out += '+';
					cout << "+\n";
					sta.push(j + 1);
					check[j] = true;
				}
			}
		}

		if (sta.top() == 0)
		{
			cout << "NO";
			clear = false;
			break;
		}

		if (sta.top() != st)
		{
			out += '-';
			cout << "-\n";
			sta.pop();
		}
		out += '-';
		cout << "-\n";
		sta.pop();
	}

	if (clear)
	{
		for (int i = 0; out[i] !='\0'; i++)
		{
			cout << out[i] << "\n";
		}
	}

}