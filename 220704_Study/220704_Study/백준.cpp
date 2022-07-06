#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, N, M;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	cin >> T;

	while (T--)
	{
		cin >> N >> M;

		int max = ((N - 1) * (N - 2)) / 2;

		bool answer = true;
		int arr[25001] = { 0 };
		
		cout << "max값 : " << max << "\n";

		for (int i = 0; i < M; i++)
		{
			int i1, i2, i3;
			cin >> i1 >> i2 >> i3;
			arr[i1]++;
			arr[i2]++;
			arr[i3]++;
			if (arr[i1] >= max || arr[i2] >= max || arr[i3] >= max)
			{
				answer = false;
				break;
			}
		}
		//누가 세나 괴롭혀  

		if (answer)
		{
			cout << "TAK\n";
		}
		else
		{
			cout << "NIE\n";
		}
		
	}
}