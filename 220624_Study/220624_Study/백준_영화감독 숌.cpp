#include<iostream>

using namespace std;

int answer, count1, save;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	answer = 0;
	count1 = 0;

	while (count1 != N)
	{
		answer++;
		save = answer;

		while (save != 0)
		{
			if (save % 1000 == 666)
			{
				count1++;
				break;
			}
			else save /= 10;
		}
	}
	cout << answer;
}