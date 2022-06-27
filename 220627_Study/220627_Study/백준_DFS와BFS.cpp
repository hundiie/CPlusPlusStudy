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
	
	stack<int> st;// ������ �湮�� ������ ����
	st.push(V);
	is[V] = true;
	//�� �̻� �湮�� ������ ���� ������ �湮
	while (false == st.empty())//������ ����� �� ��� ������ �湮�ߴٴ� ��
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
	//DFS �� BFS ���̴� ť�� ���� ������ ������ ����
	queue<int> Q;// ������ �湮�� ������ ����
	Q.push(V);
	is[V] = true;
	//�� �̻� �湮�� ������ ���� ������ �湮
	while (false == Q.empty())//������ ����� �� ��� ������ �湮�ߴٴ� ��
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