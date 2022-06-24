#include <iostream>
#include <stack>

using namespace std;
int STACK[1000000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int top = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> STACK[i];
		
	}
	for (int i = 0; i < N; i++)
	{
		bool check = true;
		int num = 0;
		for (int j = i + 1; j < N; j++)
		{
			if (STACK[j] < num)
			{
				check = false;
				break;
			}
			if (STACK[j] > STACK[i])
			{
				num = STACK[j];
				check = false;
				break;
			}
		}
		if (!check)
		{
			cout << num << " ";
		}
		else
		{
			cout << -1 << " ";
		}
	}
}