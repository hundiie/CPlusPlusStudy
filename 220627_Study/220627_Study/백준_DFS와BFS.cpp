#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

vector<int> graph[1001];
int N, M, V;

void DFS()
{
	bool is[1001] = { false };
	
	stack<int> st;// 앞으로 방문할 정점을 저장
	st.push(V);
	is[V] = true;
	//더 이상 방문할 정점이 없을 때까지 방문
	while (false == st.empty())//스택이 비었을 때 모든 정점을 방문했다는 뜻
	{
		int node = st.top();
		st.pop();
		/*
		if (is[node])
		{
			continue;
		}
		is[node] = true;
		*/
		cout << node << ' ';

		for (int next: graph[node])
		{
			if (is[next] == false)
			{
				st.push(next);
				is[next] = true;
			}
		}
	}

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
		/*
		if (is[node])
		{
			continue;
		}
		is[node] = true;
		*/
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

	for (int i = 0; i < N; i++)
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

	DFS();
	cout << "\n";
	BFS();
}