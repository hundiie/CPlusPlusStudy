#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int N, M;
vector<int> graph[10000];
bool check[10000];
int ground[10000] = { 0 };

stack<int> st;

int COUNT = 0;

void BFS(int V)
{
	queue<int> Q;
	Q.push(V);
	check[V] = true;
	while (false == Q.empty())
	{
		int node = Q.front();
		Q.pop();

		COUNT++;

		for (int next : graph[node])
		{
			if (check[next] == false)
			{
				cout << next << "\n";
				Q.push(next);
				check[next] = true;
				break;
			}
		}
	}
}

int main()
{
	cin >> M >> N;

	for (int i = 0; i < M; i++)
	{
		string MG;
		cin >> MG;
		for (int j = 0; j < N; j++)
		{
			if (MG[j] == '1')
			{
				ground[i * N + j] = 1;
			}
		}
	}

	/*
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << ground[i * N + j] << " ";
		}
		cout << "\n";
	}
	*/

	for (int i = 0; i < M * N; i++)
	{
		if (ground[i] == 1)
		{
			if (ground[i + 1] == 1)
			{
				if (i % N != N - 1)
				{
					graph[i].push_back(i + 1);
					cout << i<< "오른쪽 연결\n";
				}
			}
			if (i != 0)
			{
				if (ground[i - 1] == 1)
				{
					if (i % N != 0)
					{
						graph[i].push_back(i - 1);
						cout << i << "왼쪽 연결\n";
					}
				}
			}
			if (ground[i + N] == 1)
			{
				graph[i].push_back(i + N);
				cout << i << "아래쪽 연결\n";
			}
			if (i - N >= 0)
			{
				if (ground[i - N] == 1)
				{
					graph[i].push_back(i - N);
					cout << i << "위쪽 연결\n";
				}
			}
		}
	}

	BFS(0);

	cout << COUNT;
}