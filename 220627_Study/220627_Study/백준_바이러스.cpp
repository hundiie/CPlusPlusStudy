#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;
int N, M;
int cot = 0;
vector<int> graph[101];
stack<int> st;
bool check[101] = { false };

int dfs(int num)
{
	if (st.empty())
	{
		return 0;
	}
	
	int now = num;
	check[num] = true;
	st.pop();
	cot++;
	for (int next : graph[now])
	{
		if (check[next] == false)
		{
			st.push(next);
			dfs(next);
		}
	}
	return 1;
}
int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	st.push(1);
	dfs(1);
	cout << cot - 1;
}