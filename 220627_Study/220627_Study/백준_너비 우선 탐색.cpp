#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

vector<int> graph[1000000];
bool check[1000000] = { false };
int ground[1000000] = { 0 };
int countt = 1;
queue<int> Q;


void BFS(int V)
{
	queue<int> Q;
	Q.push(V);
	check[V] = true;
	while (false == Q.empty())
	{
		int node = Q.front();
		Q.pop();
		ground[node] = countt;
		countt++;

		for (int next : graph[node])
		{
			if (check[next] == false)
			{
				Q.push(next);
				check[next] = true;
			}
		}
	}
}

int N, M, R;
int main()
{
	cin >> N >> M >> R;
	for (int i = 0; i < M; i++)
	{
		int S, E;
		cin >> S >> E;

		graph[S].push_back(E);
		graph[E].push_back(S);
	}
	for (int i = 0; i < N; i++)
	{
		sort(graph[i].begin(), graph[i].end());
		//reverse(graph[i].rbegin(), graph[i].rend());
	}
	BFS(R);

	for (int i = 1; i <= N; i++)
	{
		cout << ground[i] << "\n";
	}
}