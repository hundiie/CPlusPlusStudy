#include <iostream>
#include <queue>

using namespace std;

bool s[1001] = { false };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	queue<int> q;

	int c = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{

			c++;
			if (c > N)
			{
				c -= N;
			}
			while (s[c] == true)
			{
				c++;
				if (c > N)
				{
					c -= N;
				}
			}
			if (c > N)
			{
				c -= N;
			}

		}
		q.push(c);
		s[c] = true;
	}
	cout << "<";
	while (!q.empty())
	{
		cout << q.front();
		if (q.size() != 1)
		{
			cout << ", ";
		}
		q.pop();
	}
	cout << ">";
}