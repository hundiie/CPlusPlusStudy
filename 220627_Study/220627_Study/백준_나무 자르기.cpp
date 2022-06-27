#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

ll p[1000000];
int main()
{
	ll N, M;
	cin >> N >> M;

	ll max = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> p[i];

		if (p[i] > max)
		{
			max = p[i];
		}
	}

	ll s = 0;
	ll result = 0;

	while (s < max)
	{
		ll m = (s + max) / 2;
		ll count = 0;

		for (int i = 0; i < N; i++)
		{
			if (p[i] > m)
			{
				count += (p[i] - m);
			}
		}

		if (count >= M)
		{
			if (result < m)
			{
				result = m;
			}
			s = m + 1;
		}
		else if (count < M)
		{
			max = m;
		}
	}
		cout << result;
}