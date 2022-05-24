#include <string.h>
#include <stdio.h>

	

//함수를 사용하는 이유 = 코드를 재사용 하기 위해

/// <summary>
/// 배열의 모든 원소를 더함
/// </summary>
/// <param name="a">정수 N개가 저장된 배열</param>
/// <param name="n">배열의 크기</param>
/// <returns>배열의 모든 원소를 더한 값</returns>
//long long sum(int* a, int n)
//{
//	long long result = 0ll;
//	for (int i = 0; i < n; i++)
//	{
//		result += a[i];
//	}
//	return result;
//}
char islower(char a)
{
	if (a >= 'a' && 'z' >= a)
	{
		a = 'O';
	}
	else
	{
		a = 'X';
	}
	return a;
}
char isupper(char a)
{
	if (a >= 'A' && 'Z' >= a)
	{
		a = 'O';
	}
	else
	{
		a = 'X';
	}
	return a;
}

char tolower(char a)
{
	if (a >= 'a' && 'z' >= a)
	{
		a -= 'a' - 'A';
	}
	return a;
}
char toupper(char a)
{
	if (a >= 'A' && 'Z' >= a)
	{
		a += 'a' - 'A';
	}
	return a;
}

int swap(int *A, int *B)
{
	int C;

	C = *A;
	*A = *B;
	*B = C;
	
	return A, B;
}



int sum3(int x, int y, int z)
{
	return x + y + z;
}
int main()
{ 
	int T;

	scanf("%d",&T);

	for (int i = 0; i < T; i++)
	{
		int H, W, N; 
	
		scanf("%d %d %d", &H, &W, &N);
		
		int floor;
		int room;
		
		floor = (N % H); 
		room = (N / H) + 1; 

		if ((N % H) == 0)
		{
			floor = H;
			room = (N / H);
		}
		printf("%d%.2d\n", floor, room);
	} return 0;
}

	/*
	 

	printf("%c", toupper('C'));
	printf("%c", toupper('c'));
	printf("%c", tolower('C'));
	printf("%c", tolower('c'));

	/*
	int A = 10;
	int B = 20;

	swap(&A, &B);
	printf("%d %d", A, B);
	*/

	/*
	int T;
	
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		int	loom = 0;
		int guest = 0;
		int floor = 0;

		scanf("%d %d %d", &floor, &loom, &guest);
		
		int x = guest % floor;
		int y = (guest / floor) ;
		
		if (x == 0)
		{
			guest % floor+1;
		}
			printf("%d%.2d\n", x, y);
	}
}
	
	/*
	char word[128] = "hello string!";

	strcpy(word, "denglish");

		puts(word);

		int num = 10;
		int* T = &num;

		printf("%d\n", T);
		printf("%d\n", *T);

		*T = 20;

		printf("%d\n", &num);
		printf("%d\n", num);

		//포인터를 사용하는 이유
		// 다른 범위에 있는 메모리에 접근하기 위해 사용한다.
		// 
		// 메모리에 접근하는 방법은 2가지가 있다.
		// 1. 직접 참조 : 메모리 주소에 직접 접근하는 것 
		// ex) num = 10;
		// 2. 간접 참조 : 메모리 주소를 포인터를 통해서 접근하는 방법
		// ex) *T = 20;

		// Scope : 프로그램이 식별자를 찾을 수 있는 영역
		// block scope : 해당 블록에서만 찾을 수 있음 (지역 변수)
		//{int a } a; <- a를 참조하지 못함
		//file scope : 해당 파일 내에서만 찾을 수 있음(전역 변수)
		// int main 위에 쓰면 전부 참조 가능

}

/*
	int sun, moon, miter;

	scanf("%d %d %d", &sun, &moon, &miter);

	int answer;
	if ((miter - sun) % (sun - moon) == 0)
	{
		answer = (miter - sun) / (sun - moon) + 1;
	}
	else
	{
		answer = (miter - sun) / (sun - moon) + 2;
	}
	printf("%d", answer);
}
/*
	int up;
	int down;
	int T;
	int answer;

	scanf("%d %d %d", &up, &down, &T);
	
	answer = (T - up) / (up - down);
	if (answer == 0)
	{
		answer = 1;
	}
	if (T <= up)
	{
		answer = 0;
	}
	if (answer > 0)
	{
	printf("%d", answer + 1);
	}
}
	/*분수 찾기
	int input = 0;
	int count = 1;
	int x = 1;
	int y = 1;

	scanf("%d", &input);
	
	while (count != input)
	{
		if (x <= 1)
		{
			while (y != 1)
			{
				y -= 1;
				x += 1;
				count++;
				if (count == input)
				{
					break;
				}
			}
			if (count == input)
			{
				break;
			}
			x += 1; count++;
		}
		if (count == input)
		{
			break;
		}
		if (y <= 1)
		{
			while (x != 1)
			{
				x -= 1;
				y += 1;
				count++;
				if (count == input)
				{
					break;
				}
			}
			if (count == input)
			{
				break;
				
			}
			y += 1; count++;
		}
		if (count == input)
		{
			break;
		}
	}
	printf("%d/%d", y, x);
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