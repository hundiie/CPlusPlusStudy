#include <stdio.h>
int map[3163][3163];
int main()
{
	

	for (int i = 0; i < 3163; i++)
	{
		for (int j = 0; j < 3163; j++)
		{
			map[j][i] = j;
			printf("%d ", map[j][i]);
		}
		printf("\n");
	}
	

}
	/*
	int bee;
	int home = 1;
	int walk = 1;
	
	scanf("%d", &bee);

	for (int i = 6; bee > home; i+= 6)
	{
		if (bee == 1)
		{
			break;
		}
		home += i;
		walk++;
	}
	printf("%d", walk);
}
/*
	int A, B, C;
	int count = 0;
	int win = 0;

	scanf("%d %d %d", &A, &B, &C);

	int son = C - B;
	if (son <= 0)
	{
		printf("-1");
	}
	else
	{
		count = A / son;
		printf("%d", count + 1);
	}
}
	
	/*
	while (son >= 0)
	{
		A -= son;
		count++;
		if (A < 0)
		{
			win = 1;
			break;
		}
	}
	if (win == 0)
	{
		count-=2;
	}
	printf("%d", count);
}
/*
	char str[1000000];
	int play = 0;
	
	int add;
	int d = 0;
	int score = 0;

	scanf("%d", &play);
	
	for (int i = 0; i < play; i++)
	{
		d = 0;
		int word[26] = { 0 };
		scanf("%s", str);
		
		for (int j = 0; str[j] != '\0'; j++)
		{
			int save = str[j] - 'a';
			if (word[save] == 0)
			{
				word[save] += 1; 
				add = j;
				while (str[add] == str[add + 1])
				{
					word[save] += 1;
						add++;
						j++;
				}
			}
			else
			{
				d = 1;
			}
		}
		if (d != 1)
		{
			score++;
		}
	}
	printf("%d", score);
}
	/*asdaaaaaaaaaaaaaaaaaaaaaaaa
sdgggggggggggggggggggffffff
aaaaaaaaaaaaaaaaaaaaaaasdwa
	char str[100];
	int count = 0;

	scanf("%s", str);

	for (int i = 0; str[i] != '\0'; i++)
	{
		count++;
		if (str[i] == 'c'&& str[i + 1] == '=')
		{
			count -= 1;
		}
		else if (str[i] == 'c' && str[i + 1] == '-')
		{
			count -= 1;
		}
		else if (str[i] == 'd' && str[i + 1] == 'z' && str[i + 2] == '=')
		{
			count -= 2;
			str[i + 1] = 'q';
		}
		else if (str[i] == 'd' && str[i + 1] == '-')
		{
			count -= 1;
		}
		else if (str[i] == 'l' && str[i + 1] == 'j')
		{
			count -= 1;
		}
		else if (str[i] == 'n' && str[i + 1] == 'j')
		{
			count -= 1;
		}
		else if (str[i] == 's' && str[i + 1] == '=')
		{
			count -= 1;
		}
		else if (str[i] == 'z' && str[i + 1] == '=')
		{
			count -= 1;
		}
	}
	printf("%d", count);
}	
	/*
	char str[15];
	int count = 0;

	scanf("%s", str);

	for (int i = 0; str[i] !='\0'; i++)
	{
		if (str[i] == 'A' || str[i] == 'B'|| str[i] == 'C')
		{
			count += 3;
		}
		if (str[i] == 'D' || str[i] == 'E' || str[i] == 'F')
		{
			count += 4;
		}
		if (str[i] == 'G' || str[i] == 'H' || str[i] == 'I')
		{
			count += 5;
		}
		if (str[i] == 'J' || str[i] == 'K' || str[i] == 'L')
		{
			count += 6;
		}
		if (str[i] == 'M' || str[i] == 'N' || str[i] == 'O')
		{
			count += 7;
		}
		if (str[i] == 'P' || str[i] == 'Q' || str[i] == 'R' || str[i] == 'S')
		{
			count += 8;
		}
		if (str[i] == 'T' || str[i] == 'U' || str[i] == 'V')
		{
			count += 9;
		}
		if (str[i] == 'W' || str[i] == 'X' || str[i] == 'Y' || str[i] == 'Z')
		{
			count += 10;
		}
	}
	printf("%d", count);
}
	/*
	char num[8];
	
	scanf("%[^\n]d", num);

	int right = ((num[2] - 48) * 100) + ((num[1] - 48) * 10) + (num[1] - 48);
	int left = ((num[6] - 48) * 100) + ((num[5] - 48) * 10) + (num[4] - 48);
	if (right > left)
	{
		printf("%d", right);
	}
	else
	{
		printf("%d", left);
	}
}
	/*
	char as[1000000];
	int count = 1;
	
	scanf("%[^\n]s",as);
	if (as[0] == ' ')
	{
		count--;
	}
	for (int i = 0; as[i] !='\0'; i++)
	{
		
		if (as[i] == ' ')
		{
			count++;
			if (as[i + 1] == '\0')
			{
				count--;
			}
		}
	}
	printf("%d", count);
	return 0;
}
	/*
	%[^\n]s -< 공백 포함 문자 입력
	fgets
	int key = _getch();
	system("cls");
	printf("%d", key);
	아스키 넘버 알아내기*/