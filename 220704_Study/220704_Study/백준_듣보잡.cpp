#include <iostream>
#include <algorithm>
#include <vector> //�� �� ���� �� �� �˾� �� �ʹ� ������

using namespace std;
#define MAX 500000

int N, M;
string save[MAX];
int COUNT = 0;
vector<string> str;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		str.push_back(input);
	}
	for (int i = 0; i < M; i++)
	{
		string input;
		cin >> input;

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == input)
			{
				save[COUNT] = input;
				COUNT++;
			}
		}
	}
	sort(save, save + COUNT);
	cout << COUNT << "\n";
	for (int i = 0; i < COUNT; i++)
	{
		cout << save[i] << " \n";
	}
}