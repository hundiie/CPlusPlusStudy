#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int T, M, N, K;
vector<int> graph[2500];
bool check[2500] = { false };
int ground[2500] = { 0 };
int Lsave[2500];
stack<int> st;

int coun = 0;
void reset(int set)
{
	for (int i = 0; i < set; i++)
	{
		if (check[i] == true)
		{
			check[i] = false;
		}
		graph[i].clear();
	}
}

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

int answer[2500];
int answer_count = 0;

int main()
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> K;

		for (int i = 0; i < K; i++)
		{
			int X, Y;
			cin >> X >> Y;
			ground[M * Y + X] = 1;
		}

		/*for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cout << grund[i * M + j];
			}
			cout << "\n";
		}
		cout << "\n";*/

		for (int i = 0; i < M * N; i++)
		{
			if (ground[i] == 1)
			{
				if (ground[i + 1] == 1)
				{
					if (i % M != M - 1)
					{
						graph[i].push_back(i + 1);
						//cout << i<< "오른쪽 연결\n";
					}
				}
				if (i != 0)
				{
					if (ground[i - 1] == 1)
					{
						if (i % M != 0)
						{
							graph[i].push_back(i - 1);
							//cout << i << "왼쪽 연결\n";
						}
					}
				}
				if (ground[i + M] == 1)
				{
					graph[i].push_back(i + M);
					//cout << i << "아래쪽 연결\n";
				}
				if (i - M >= 0)
				{
					if (ground[i - M] == 1)
					{
						graph[i].push_back(i - M);
						//cout << i << "위쪽 연결\n";
					}
				}
			}
		}

		int Lcount = 0;
		int Lk = 0;
		for (int i = 0; i < M * N; i++)
		{
			coun = 0;
			if (ground[i] == 1)
			{
				Lcount++;
				st.push(i);
				DFS(i);

				//for (int i = 0; i < N; i++)
				//{
				//	for (int j = 0; j < M; j++)
				//	{
				//		cout << grund[i * M + j];
				//	}
				//	cout << "\n";
				//}
				//cout << "\n";

				Lsave[Lk] = coun;
				Lk++;
			}
		}
		answer[answer_count] = Lcount;
		//cout << "답 : " << answer[answer_count] << "\n";
		answer_count++;
		reset(N * M);
	}
	
	for (int i = 0; i < T; i++)
	{
		cout << answer[i] << "\n";
	}
	
}