#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

vector<int> graph[1000000];
bool check[1000000];
int ground[1000000] = { 0 };
int countt = 1;
stack<int> st;

int DFSM(int num)
{
	if (st.empty())
	{
		return 0;
	}

	int now = num;
	check[num] = true;
	st.pop();

	ground[now] = countt;
	countt++;

	for (int next : graph[now])
	{
		if (check[next] == false)
		{
			st.push(next);

			DFSM(next);
		}
	}
	return 1;
}
void DFS(int start)
{
	st.push(start);
	DFSM(start);
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
	for (int i = 0; i <= N; i++)
	{
		sort(graph[i].begin(), graph[i].end());
		reverse(graph[i].rbegin(), graph[i].rend());
	}
	DFS(R);

	for (int i = 1; i <= N; i++)
	{
		cout << ground[i] << "\n";
	}
}