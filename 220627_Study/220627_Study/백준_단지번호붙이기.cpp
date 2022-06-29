#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int N , M;
vector<int> graph[10000];
bool check[10000];
int ground[10000] = { 0 };

stack<int> st;

int coun = 0;

int DFS(int num)
{
	ground[num] = 0;
	if (st.empty())
	{
		return 0;
	}

	int now = num;
	check[num] = true;
	st.pop();
	coun++;
	for (int next : graph[now])
	{
		if (check[next] == false)
		{
			st.push(next);
			
			DFS(next);
		}
	}
	return 1;
}

int main()
{
	cin >>N;
	

	for (int i = 0; i < N; i++)
	{
		string M;
		cin >> M;
		for (int j = 0; j < N; j++)
		{
			if (M[j] == '1')
			{
				ground[i* N + j] = 1;
			}
		}
	}
	for (int i = 0; i < N * N; i++)
	{
		if (ground[i] == 1)
		{
			if (ground[i + 1] == 1)
			{
				if (i % N != N - 1)
				{
					graph[i].push_back(i + 1);
					//cout << i<< "오른쪽 연결\n";
				}
				
			}
			if (i != 0)
			{
				if (ground[i - 1] == 1)
				{
					if (i % N != 0)
					{
						graph[i].push_back(i - 1);
						//cout << i << "왼쪽 연결\n";
					}
				}
			}
			if (ground[i + N] == 1)
			{
				graph[i].push_back(i + N);
				//cout << i << "아래쪽 연결\n";
			}
			if (i - N > 0)
			{
				if (ground[i - N] == 1)
				{
					graph[i].push_back(i - N);
					//cout << i << "위쪽 연결\n";
				}
			}
			
		}
	}
	int Lcount = 0;
	int Lsave[10000];
	int Lk = 0;
	for (int i = 0; i < N * N; i++)
	{
		coun = 0;
		if (ground[i] == 1)
		{
			Lcount++;
			st.push(i);
			DFS(i);

			Lsave[Lk] = coun;
			Lk++;
		}
	}
	sort(Lsave,Lsave + Lcount);
	cout << Lcount << "\n";
	for (int i = 0; i < Lcount; i++)
	{
		cout << Lsave[i] << "\n";
	}
}