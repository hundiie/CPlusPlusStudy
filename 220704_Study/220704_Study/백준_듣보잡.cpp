#include <iostream>
#include <algorithm>
#include <vector> //너 왜 벡터 쓸 줄 알아 나 너무 서운해

using namespace std;
#define MAX 500000

int N, M;

vector<string> str;
int main()
{
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
			//이다훈 오늘 컨디션 좋네. 왜지? 내 마리모는 오늘 무슨 바람이 들었을까?
			//일기 써야겠다. 20220704) 마리모 물에 띄다.
		}
	}

}