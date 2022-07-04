#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<long long> arr;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	long long N;
	cin >> N;
	long long max = -2000000000;

	for (long long i = 0; i < N; i++)
	{
		long long a;
		cin >> a;
		arr.push_back(a);
		if (a > max)
		{
			max = a;
		}
	}
	if (max < 0)
	{
		sort(arr.begin(), arr.end());

		long long answer = arr.back();
		arr.pop_back();
		answer += arr.back();

		cout << answer;
	}
	
}