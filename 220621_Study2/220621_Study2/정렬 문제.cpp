#include <iostream>

using namespace std;

	int num[100000000] = { 0 };
int main()
{
	int N;
	cin >>N;

	cin >> num[0];
	for (int i = 1; i < N; i++)
	{
		cin >> num[i];
		int a = i;
		while (num[a] < num[a - 1])
		{
			int change = num[a];
			num[a] = num[a - 1];
			num[a - 1] = change;
			if (a > 1)
			{
				a--;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << num[i]<< '\n';
	}
	
}