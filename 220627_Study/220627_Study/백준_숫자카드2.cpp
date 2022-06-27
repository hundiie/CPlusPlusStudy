#include <iostream>
#include <algorithm>

using namespace std;

int arr[500000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	bool ca = false;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];

	}
	sort(arr, arr + N);

	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int L;
		cin >> L;

		pair<int*, int*> range = std::equal_range(arr, arr + N, L);

		cout << range.second - range.first << " ";
	}
}