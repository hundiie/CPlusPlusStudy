#include <iostream>
#include <queue>
#include <deque>

using namespace std;
int p[10000] = { 0 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<int> d;
	
	int c;
	cin >> c;
	
	for (int i = 0; i < c; i++)
	{
		bool flag = true;
		string str;
		cin >> str;

		int p;
		cin >> p;

		string num;
		cin >> num;

		for (int i = 1; i < num.size(); i += 2)
		{
			string cou;
			if (num[i] == '[')
			{
				continue;
			}
			if (num[i] == ']')
			{
				break;
			}
			if (num[i] ==',')
			{
				int dd = 0;
				int ten = 1;
				for (int i = cou.size(); i >= 0 ; i--)
				{
					dd += (cou[i] - 48) * ten;
					ten * 10;
				}
				d.push_back(dd);
			}
			cou += num[i];
		}

		int re = 0;
		for (int i = 0; i < str.size(); i++)
		{
			switch (str[i])
			{
			case'R':
			{
				re++;
			}
				break;
			case'D':
			{
				if (re % 2 == 0)
				{
					if (d.empty())
					{
						flag = false;
						break;
					}
					else
					{
						d.pop_front();
					}
				}
				else
				{
					if (d.empty())
					{
						flag = false;
						break;
					}
					else
					{
						d.pop_back();
					}
				}
			}
				break;
			default:
				break;
			}
		}
		if (flag == false)
		{
			cout << "error";
		}
		else if (flag == true && re % 2 == 0)
		{
			cout << "[";
			while (!d.empty())
			{
				if (d.size() > 1)
				{
					cout << d.front() << ",";
				}
				else
				{
					cout << d.front();
				}
				d.pop_front();
			}
			cout << "]";
		}
		else
		{
			cout << "[";
			while (!d.empty())
			{
				if (d.size() > 1)
				{
					cout << d.back() << ",";
				}
				else
				{
					cout << d.back();
				}
				d.pop_back();
			}
			cout << "]";
		}

		cout << "\0" << "\n";
		
	}
}