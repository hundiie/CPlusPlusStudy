/*#include <stdio.h>

int fac(int n)
{
	//기저 조건
	if (n <= 1)
	{
		return 1;
	}

	//재귀 조건
	return n * fac(n - 1);
}

int fib(int n)
{
	if (n <= 1)
	{
		return n;
	}

	return fib(n - 1) + fib(n - 2);
}
int tj(int n)
{
	int a = n / 2;
	int b = n % 2;
	if (n <= 1)
	{
		printf("%d", n);
		return;
	}
	tj(a);
	printf("%d", b);
}
void under(int n)
{
	int k = n;
	while (k ==0)
	{
		printf("____");
		k--;
	}
}
void whyjg(int n)
{
	int count;
	printf("\"재귀 함수가 뭔가요?\"\n");

	if (n == 0)
	{
		printf("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n");
		printf("라고 답변하였지.\n");
		return;
	}
	
	printf("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n");
	
	printf("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n");
	
	printf("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n");
	count++;
	whyjg(n - 1);
	printf("라고 답변하였지.\n");
}
void hanoi(int n, int start, int via, int get)
{
	if (n == 1)
	{
		printf("%d %d\n", start, get);
		return;
	}

	hanoi(n - 1, start, get, via);
	hanoi(1, start, via, get);
	hanoi(n - 1, via, start, get);
}
void star10(int n)
{

}
int main(void)
{
	int N;
	scanf("%d", &N);
	star10(N);
}*/
#include <stdio.h>
#include <math.h>

char arr[2500][2500];

//모든 칸을 *로 채워주기
void AllStar(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			arr[i][j] = '*';
	}
}

//지정된 점(x,y)부터 가로새로로 3^cnt만큼 공백으로 채우기
void Blank(int x, int y, int cnt) {
	for (int i = x; i < x + (int)pow(3, cnt); i++) {
		for (int j = y; j < y + (int)pow(3, cnt); j++) {
			arr[i][j] = ' ';
		}
	}
}

//공백으로 지정할 점(x,y) 찾기
void Pivot(int n, int cnt) {
	if (n > 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				//해당 기준점을 공백으로
				Blank((int)pow(3, cnt) + i * (int)pow(3, cnt + 1),
					(int)pow(3, cnt) + j * (int)pow(3, cnt + 1), cnt);
			}
		}
		//기준점 이동하기
		Pivot(n / 3, cnt + 1);
	}
}

int main() {
	int N;
	scanf("%d", &N);
	AllStar(N);

	Pivot(N / 3, 0);

	//결과출력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%c", arr[i][j]);
		printf("\n");
	}
	return 0;
}

	/*
	int N;
	scanf("%d", &N);
	int a = 2;
	for (int i = 1; i < N; i++)
	{
		a *= 2;
	}
	printf("%d\n",a - 1);
	hanoi(N, 1 ,2 ,3);
}
	/*
	int N;
	scanf("%d", &N);
	printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
	whyjg(N);
}


	/*
	int N;
	scanf("%d", &N);
	tj(N);
}
	/*
	int N;
	scanf("%d", &N);
	printf("%d", fib(N));
}
/*
	int N;
	scanf("%d", &N);
	printf("%d", fac(N));
}*/