#include <iostream>
#include <algorithm>

using namespace std;

int N, C;
int X[200003];
int main()
{
	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		cin >> X[i];
	}
	sort(X, X + N);

	int s = 1, e = X[N - 1] + 1;
	int answer = 0;
	while (s < e)
	{
		int m = (s + e) / 2;

		int count = 1;

		int k = 0;
		for (int i = 0; i < N; i++)
		{
			if (X[i] - X[k] >= m)
			{
				count++;
				k = i;
			}
		}
		
		if (count < C) //너무 멀리 설치함
		{
			e = m;
		}
		else
		{
			if (answer < m)
			{
				answer = m;
			}
			s = m + 1;
		}
	}
	cout << answer;
}