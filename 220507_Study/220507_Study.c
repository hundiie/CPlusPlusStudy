#include <stdio.h>

int num[1000000] = { 0 };

int main()
{
	int min;
	int max;
	int root_max =0;
	
	scanf("%d %d", &min, &max);

	int count = 1;
	while (root_max < max)
	{
		root_max = count;
		root_max *= root_max;
		count++;
	}
	printf("%d\n\n", count - 1);
	if (max <= 1000000 && min > 0)
	{
		for (int i = min; i < max; i++)
		{
			num[i] = i;
		}
		if (num[0] == 1)
		{
			num[0] = 0;
		}
		for (int j = min - 1; j < max; j++)
		{
			
		}
	}
	
}
/*
	int min;
	int max;

	scanf("%d %d", &min, &max);
	
	while (min <= 1 && max > 1)
	{
		min++;
	}
	for (int i = min; i <= max; i++)
	{
		if (min == 1)
		{
			break;
		}

		int count = 0;

		for (int j = 2; j < i; j++)
		{
			if (i % j == 0 && i != j)
			{
				count = 1;
				break;
			}
		}
		if (count == 0)
		{
			printf("%d\n", i);
		}

	}
}*/