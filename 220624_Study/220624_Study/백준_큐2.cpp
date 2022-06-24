#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> Q;

	int num;
	cin >> num;
	
	for (int i = 0; i < num; i++)
	{
		string K;
		cin >>K;

		if (K == "push")
		{
			int PUSH;
			cin >> PUSH;
			Q.push(PUSH);
			continue;
		}
		if (K == "pop")
		{
			if (Q.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << Q.front() << "\n";
				Q.pop();
			}
			continue;
		}
		if (K == "size")
		{
			cout << Q.size() << "\n";
			continue;
		}
		if (K == "empty")
		{
			if (Q.empty())
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
			continue;
		}
		if (K == "front")
		{
			if (Q.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << Q.front() << "\n";
			}
			continue;
		}
		if (K == "back")
		{
			if (Q.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << Q.back() << "\n";
			}
			continue;
		}
	}
}