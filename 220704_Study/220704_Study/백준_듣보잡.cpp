#include <iostream>
#include <algorithm>
#include <vector> //�� �� ���� �� �� �˾� �� �ʹ� ������

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
			//�̴��� ���� ����� ����. ����? �� ������� ���� ���� �ٶ��� �������?
			//�ϱ� ��߰ڴ�. 20220704) ������ ���� ���.
		}
	}

}