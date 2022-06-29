#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int arr[1000001];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;

	stack<int> st;
	vector<int> Vec(n + 1, -1);

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		while (!st.empty() && arr[st.top()] < arr[i])
		{
			Vec[st.top()] = arr[i];
			st.pop();
		}
		st.push(i);
	}

	for (int i = 1; i <= n; i++)
	{
		cout << Vec[i] << ' ';
	}
}