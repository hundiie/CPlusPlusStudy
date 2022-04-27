#include <stdio.h>

int N[1000000];
int main()
{
		
		int num = 0, low = 1000000, high = -1000000;

		scanf("%d", &num);
		for (int i = 0; i < num; i++)
		{
			scanf("%d", &N[i]);
			if (N[i] <= low)
			{
				low = N[i];
			}
			if (N[i] >= high)
			{
				high = N[i];
			}
		}
		printf("%d %d", low, high);
	
}
	/*
	int c[10000] = { 0 };
	int first, sec;
	sec = 0;
	
	for (int i = 0; i < 10000; i++)
	{
		c[i] = i;
	}
	for (int i = 1; i < 10000; i += 1)
	{
		sec = 0;
		first = i;
		while (sec <= 10000)
		{
			sec = 0;
			sec += first;
			while (first >= 10)
			{
				sec += first % 10;
				first /= 10;
			}
			sec += first;
			c[sec] = 0;
			first = sec;
		}
	}
	for (int i = 0; i < 10000; i++)
	{
		if (c[i] != 0)
		{
			printf("%d\n", c[i]);
		}
	}
	return 0;
}

	/*
	long long sum(int* a, int n);
	{
		long long ans = 0;
		for (int i = 0; i < n; i++)
		{
			ans += a[i];
		}

		return ans;
	}
}
	/*
	float c, n;
	float score[1000], mean, answer;

	scanf("%f", &c);
	for (int i = 0; i < c; i++)
	{
		scanf("%f", &n);

		mean = 0;
		for (int j = 0; j < n; j++)
		{
			scanf("%f", &score[j]);
			mean += score[j];

		}
		mean /= n;
		answer = 0;
		for (int j = 0; j < n; j++)
		{
			if (mean < score[j])
			{
				answer++;
			}
		}
		mean = 0;
		printf("%.3f%%\n", 100 - ((100 / n)*(n - answer)));
	}
	return 0;
}
/*
	int ch;
	char n[80];
	int score;
	int plus;
	int a;
	int b;
	
	scanf("%d", &ch);
	for (int i = 0; i < ch; i++)
	{
		score = 0;
		scanf("%s", n);

		a = 0;
		while (1)
		{
			
			if (n[a] != 'O')
			{
				b = 1;
				plus = 0;
				while (n[a - b]== 'O')
				{
					plus += 1;
					score += plus;
					b++;
				}
			}
			a++;
			if (n[a - 1] != 'O' && n[a - 1] != 'X')
			{
				break;
			}
		}
		printf("%d\n", score);
	}
	return 0;
}
	/*
	float study[1000];
	float N;
	int high = 0;
	float mean = 0;
	
	scanf("%f", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%f", &study[i]);
		if (study[i] >= high)
		{
			high = study[i];
		}
	}
	for (int i = 0; i < N; i++)
	{
		study[i] = (study[i] / high) * 100;
		mean += study[i];
	}
	printf("%f\n", (double)mean/N);
	return 0;
}

	/*
	int num[10];
	int numcount[42] = { 0 };
	int count = 0;

	for (int i = 0; i < 10; i++) {
		scanf("%d", &num[i]);
		num[i] %= 42;
	}

	for (int i = 0; i < 10; i++) {
		if (numcount[num[i]] != 1) {
			count++;
			numcount[num[i]] = 1;
		}
	}

	printf("%d", count);

	return 0;
}
	/*
	int A, B, C;
	int D[10]={0,0,0,0,0,0,0,0,0,0};
	int k;
	int d = 1;

	scanf("%d %d %d", &A, &B, &C);
	
	C = A * B * C;
	
	if (C >= 1000000 && C < 10000000)
	{
		for (int i = 0; i < 7; i++)
		{
			k = C / d % 10;
			
			D[k]++;

			d *= 10;
		}
	}
	if (C >= 10000000 && C < 100000000)
	{
		for (int i = 0; i < 8; i++)
		{
			k = C / d % 10;

			D[k]++;

			d *= 10;
		}
	}
	if (C >= 100000000)
	{
		for (int i = 0; i < 9; i++)
		{
			k = C / d % 10;

			D[k]++;

			d *= 10;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", D[i]);
	}
}
	/*
	int N[9];
	int high = 0;
	int num;
	
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &N[i]);
		if (N[i] >= high)
		{
			high = N[i];
			num = i + 1;
		}
	}
	printf("%d\n%d",high , num);
}
	/*
	int N[100000];
	int num = 0, low = 1000000, high = -1000000;

	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &N[i]);
		if (N[i] <= low)
		{
			low = N[i];
		}
		if (N[i] >= high)
		{
			high = N[i];
		}
	}
	printf("%d %d", low, high);
}*/