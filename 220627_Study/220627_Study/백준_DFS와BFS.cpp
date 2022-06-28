#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

vector<int> graph[1001];
int N, M, V;

bool is[1001] = { false };

stack<int> st;// 앞으로 방문할 정점을 저장

int DFS(int num)
{
	if (st.empty())
	{
		return 0;
	}

	int now = num;
	is[num] = true;
	st.pop();
	cout << now << ' ';
	for (int next : graph[now])
	{
		if (is[next] == false)
		{
			st.push(next);
			DFS(next);
		}
	}
	return 1;
}

void BFS()
{
	bool is[1001] = { false };
	//DFS 와 BFS 차이는 큐를 쓰냐 스택의 쓰냐의 차이
	queue<int> Q;// 앞으로 방문할 정점을 저장
	Q.push(V);
	is[V] = true;
	//더 이상 방문할 정점이 없을 때까지 방문
	while (false == Q.empty())//스택이 비었을 때 모든 정점을 방문했다는 뜻
	{
		int node = Q.front();
		Q.pop();
		cout << node << ' ';

		for (int next : graph[node])
		{
			if (is[next] == false)
			{
				Q.push(next);
				is[next] = true;
			}
		}
	}
}

int main()
{
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;

		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	for (int i = 0; i <= N; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	st.push(V);
	DFS(V);
	cout << "\n";
	BFS();
}