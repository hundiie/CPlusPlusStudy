#include <iostream>

using namespace std;
bool NUM[1000000] = { false };
int save[1000000] = { 0 };
int main()
{
	int N, K;
	cin >> N >> K;

	NUM[1] = true;
	int count = 1;

	for (int i = 2; i <= N; i++)
	{
		int plus = i;
		if (!NUM[i])
		{
			while (plus <= N)
			{
				if (!NUM[plus])
				{
					NUM[plus] = true;
					
					save[count] = plus;
					count++;		
				}
					plus += i;
			}
		}
	}
	cout << save[K];
}