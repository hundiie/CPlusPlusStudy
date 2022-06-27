#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


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
		int P;
		cin >> P;

		(binary_search(arr,arr + N, P)) ? cout << "1\n" : cout << "0\n";
	}
}