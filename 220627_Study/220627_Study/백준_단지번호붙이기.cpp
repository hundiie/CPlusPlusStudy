#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int N;
vector<int> graph[10000];
bool check[10000];
int gr[10000] = { 0 };

stack<int> st;

int coun = 0;

int DFS(int num)
{
	gr[num] = 0;
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
				gr[i* N + j] = 1;
			}
		}
	}
	for (int i = 0; i < N * N; i++)
	{
		if (gr[i] == 1)
		{
			if (gr[i + 1] == 1)
			{
				if (i % N != N - 1)
				{
					graph[i].push_back(i + 1);
					//cout << i<< "오른쪽 연결\n";
				}
				
			}
			if (i != 0)
			{
				if (gr[i - 1] == 1)
				{
					if (i % N != 0)
					{
						graph[i].push_back(i - 1);
						//cout << i << "왼쪽 연결\n";
					}
				}
			}
			if (gr[i + N] == 1)
			{
				graph[i].push_back(i + N);
				//cout << i << "아래쪽 연결\n";
			}
			if (i - N > 0)
			{
				if (gr[i - N] == 1)
				{
					graph[i].push_back(i - N);
					//cout << i << "위쪽 연결\n";
				}
			}
			
		}
	}
	int ccc = 0;
	int ppp[10000];
	int kkk = 0;
	for (int i = 0; i < N * N; i++)
	{
		coun = 0;
		if (gr[i] == 1)
		{
			ccc++;
			st.push(i);
			DFS(i);

			ppp[kkk] = coun;
			kkk++;
		}
	}
	sort(ppp,ppp + ccc);
	cout << ccc << "\n";
	for (int i = 0; i < ccc; i++)
	{
		cout << ppp[i] << "\n";
	}
}