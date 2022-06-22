#include <iostream>

using namespace std;

int N[500000];
int check[8000]={ 0 };
int main()
{
	int A;
	cin >> A;

	int Average =0;
	int MAX = 0;
	int MIN = INT_MAX;
	int MIN2 = INT_MAX;

	for (int i = 0; i < A; i++)
	{
		cin >> N[i];
		Average += N[i];

		if (N[i] >= 0)
		{
			check[N[i]]++;
		}
		else
		{
			check[(N[i] * -1) + 4000];
		}

		if (N[i] > MAX)
		{
			MAX = N[i];
		}
		
		if (N[i] < MIN)
		{
			MIN = N[i];
			if (MIN2 > 4000)
			{
				MIN2 = N[i];
			}
		}

		if (N[i] < MIN2 && N[i] != MIN)
		{
			MIN2 = N[i];
		}

		if (i > 1)
		{
			int ant = i;
			while (N[ant] < N[ant - 1])
			{
				int change = N[ant];
				N[ant] = N[ant - 1];
				N[ant - 1] = change;
				if (ant > 1)
				{
					ant--;
				}
			}
		}
	}
	Average /= A;

	{
		cout << Average << "\n";
		if (A % 2  ==0)
		{
			cout << N[A / 2 + 1] << "\n";
		}
		else
		{
			cout << N[A / 2] << "\n";
		}
		cout << MIN << "\n";
		cout << MIN2 << "\n";
		cout << MAX - MIN << "\n";
	}
	//필요 값
	// 평균값
	// 중앙값
	// 가장 많이 나타나는 값
	//최소값, 최대값


}