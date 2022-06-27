#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

ll len[10000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll N, K;
	cin >> N >> K;

	ll max = 0;
	for (int i = 0; i < N; i++)
	{
		cin >>len[i];
		if (len[i] > max)
		{
			max = len[i];
		}
	}
	ll s = 1;
	ll e = max + 1;
	ll result = 0;
	while (s < e)
	{
		//해가 될 후보
		ll m = (s + e) / 2;
		
		ll count = 0;
		for (int i = 0; i < N; ++i)
		{
			count += len[i] / m;
		}

		if (count >= K)
		{
			if (result < m)
			{
				result = m;
			}
			s = m + 1;
		}
		else
		{
			e = m;
		}
	}

	cout << result;
}