#include <stdio.h>




int main()
{

}
	/*
	//큰 수 A+B
	// 문자열로 숫자를 입력받아서 계산하기
	char A[10001];
	char B[10001];
	int A2[10001];
	int B2[10001];
	int answer[10001];

	scanf("%s %s", A, B);

	int a_long = 0;
	
	for (int i = 0; A[i] != '\0'; i++)
	{
		a_long++;
	}
	for (int i = 0; i < a_long; i++)
	{
		A2[i] = A[a_long - i - 1] - 48;
	}

	int b_long = 0;
	
	for (int i = 0; B[i] != '\0'; i++)
	{
		b_long++;
	}
	for (int i = 0; i < b_long; i++)
	{
		B2[i] = B[b_long - i - 1] - 48;
	}

	int count = 0;
	int j = 0;
	
	while (a_long - 1 >= 0 || b_long - 1 >= 0)
	{
		j = 0;
		
		answer[count] += A2[count] + B2[count];
	
		if (answer[count] >= 10)
		{
			j = 1;
			answer[count + 1] += 1;
			answer[count] -= 10;
		}
		
		count++;
		a_long--;
		b_long--;
	}
	
	if (j == 0)
	{
		count--;
	}
	for (int i = count+1; i > 0; i--)
	{
		printf("%d", answer[i - 1]);
	}
}
/*
//설탕 배달
//3 5 6 8 9 10 11 12 13 14 15 16 17 18 19 ... 4, 7 이외엔 전부 가능
	int KG;
	int sugar;
	int answer;

	scanf("%d", &KG);

	int count = 0;

	while (KG % 5 != 0 && count <= 4)
	{
		KG -= 3;
		count++;
	}
	if (KG < 0)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", (KG / 5) + count);
	}

}

/*
//부녀회장이 될테야
// 0  01 02 03 04 05 06 07
// 1  01 03 06 10 15 21 28
// 2  01 04 10 20 35 56 84
// 3  01 05 15 35 70
// 4  01 06 21 56
// 5  01 07 28 84
// 6  01 08 36
// 7  01 09 45

	int T;
	int floor;
	int room;
	
	int answer = 0;

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &floor, &room);
		
		int down[14];
		int up[14] = { 0 };
		
		for (int i = 0; i < 14; i++)
		{
			down[i] = i + 1;
		}

		

		for (int j = 0; j < floor; j++)
		{
			int z = 0;

			for (int k = 0; k < room; k++)
			{
				int x = 0;
				for (int l = 0; l < z + 1; l++)
				{
					x += down[l];
				}
				up[z] = x;
				answer = x;
				z++;
			}
			for (int k = 0; k < room; k++)
			{
				down[k] = up[k];
			}
		}
		if (floor == 0)
		{
			answer = room;
		}
		printf("%d\n", answer);
	}
	return 0;
}*/