#include <iostream>

using namespace std;

int main() 
{
	int N;
	int COUNT = 0;
	int c[123456 * 2] = { 0 };
	c[1] = 1;
	for (int i = 2; i <= 123456 * 2; i++)
		for (int j = 2; j * i <= 123456 * 2; j++)
			c[i * j] = 1;

	while (1) 
	{
		COUNT = 0;
		cin >>N;
		if (N == 0)
			break;
		for (int i = N + 1; i <= N * 2; i++) {
			if (!c[i])
				COUNT += 1;
		}
		cout << COUNT << "\n";
	}
}