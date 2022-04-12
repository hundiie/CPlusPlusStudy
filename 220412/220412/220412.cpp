#include <iostream>
using namespace std;

int main()
{
	double a[89];
	double b;
	double e = 1;
	int ran;
	double f = 0;
	int g = 0;

	srand(time(NULL));

	

	for (int c = 0; c < 6; c++)
	{
		for (int d = 0; d < 6; d++)
		{
			b = rand() % 10;
			
			e = e * 10;

			f = (b / e) + f;

			a[g] = f;

			cout << a[g] << endl;
			g++;

		}
	}

	
	
	/*
	srand(time(NULL));

	cin >> d;
		for (int c = 0; c < 10; c++)
		{
			for (int b = 0; b < 10; b++)
			{
				a = rand() % d;

				if (a == 1)
				{
					cout << "■";
				}
				else
				{
					cout << "□";
				}
			}
			cout << "\n";
		}
		*/
}