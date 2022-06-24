#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> Q;

	int k;
	cin >>k;
	for (int i = 0; i < k; i++)
	{
		Q.push(i + 1);
	}

	while (Q.size() != 1)
	{
		Q.pop();
		Q.push(Q.front());
		Q.pop();
	}
	cout << Q.front();
}