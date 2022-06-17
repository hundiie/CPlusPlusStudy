#include <iostream>

using namespace std;
void swap(int *a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int main()
{
	int a;
	cin >> a;

	int* N = new int[a];
	//입력
	for (int i = 0; i < a; i++)
	{
		cin >> N[i];
	}
	int count = 0;
	for (int i = count; i < a - count; i++)
	{
		int	min = a;
		for (int j = count; j < a - 1 - i - count; j++)
		{
			if (N[j] > N[j + 1])
			{
				if (N[j + 1] <= min)
				{
					min = j + 1;
				}
				swap(N[j], N[j + 1]);
				cout << "swap!"<<endl;
			}
		}
		if(N[i] > N[min - 1])
		{
			swap(N[i], N[min - 1]);
			cout << "swap!" << endl;
		}
		count++;
	}
	//출력
	for (int i = 0; i < a; i++)
	{
		cout << N[i]<<"\n";
	}
	delete[] N;
}