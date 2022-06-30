#include <iostream>

using namespace std;

int arr[1000001];

int main()
{	
	int M, N;
	cin >> M >> N;
	
	for (int i = 0; i < 2; i++)
	{
		arr[i] = 1;
	}
	for (int i = 2; i < N + 1; i++)
	{
		for (int j = 2 * i; j < N + 1; j += i)
		{
			if (arr[j] == 0)
			{
				arr[j] = 1;
			}
		}
	}

	for (int i = M; i < N + 1; i++)
	{
		if (arr[i] == 0)
		{
			cout << i << "\n";
		}
	}
}