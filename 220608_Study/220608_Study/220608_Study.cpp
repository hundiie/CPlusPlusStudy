#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers)
{
	int player[3][10] = { { 1,2,3,4,5 }, { 2, 1, 2, 3, 2, 4, 2, 5 }, { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 } };

	vector<int> answer;

	vector<int> _player[3];

	int count[3] = { 0 };
	
	for (size_t i = 0; i < answers.size(); i++)
	{
		if (player[0][i % 5] == answers[i]) count[0]++;
		
		if (player[1][i % 8] == answers[i]) count[1]++;
		
		if (player[2][i % 10] == answers[i])count[2]++;
		
	}
	cout << count[0] << endl;
	cout << count[1] << endl;
	cout << count[2] << endl;
	if (count[0] >= count[1] && count[0] >= count[2])
	{
		answer.push_back(1);
	}
	if (count[1] >= count[0] && count[1] >= count[2])
	{
		answer.push_back(2);
	}
	if (count[2] >= count[0] && count[2] >= count[1])
	{
		answer.push_back(3);
	}

	return answer;
}



int main()
{
	//vector<int> _pl = { 1,2,1,1,1,1,1,4,2,5};

	int a[9];
	int b[7];

	for (int i = 0; i < 9; i++)
	{
		cin >> a[i];
	}


}


/*
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//벡터 생성
	vector<int> vec;
	cout << boolalpha << vec.empty() << endl;
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;

	//읽기 검색 삽입 삭제

	//삽입
	//push_back 백터 끝에 삽입
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	// 2, 3, 4

	//insert : pos 이전에 데이터를 가져온다.
	// iterator
	vector<int>::iterator iter = vec.begin();
	++iter;// 두번째 원소

	iter = vec.insert(iter, 11); //2 11 3 4
	iter = vec.insert(iter, 3, 5);// 2 5 5 5 11 3 4
	iter = vec.insert(iter, vec.begin() + 3, vec.end() - 1);// 2 5 11 3 5 5 5 11 3 4
	
	//삭제
	//pop_back 맨끝 데이터 삭제
	//2 5 11 3 5 5 5 11 3 4
	vec.pop_back();//4
	vec.pop_back();//3
	vec.pop_back();//11
	//2 5 11 3 5 5 5
	//erase pos에 있는 데이터를 삭제
	vec.erase(vec.begin());//앞에 2삭제

	// 5 11 3 5 5 5
	vec.erase(vec.begin() + 1, vec.end() - 3);//앞에서 첫번째 부터 뒤에서 세번째 삭제
	//5 5 5 5

	//읽기
	cout << vec.front() << endl;
	cout << vec.back() << endl;
	cout << vec[2] << endl;

	//검색은 메소드가 아니고 알고리즘으로 존재

	//반복자.
	//begin() 컨테이너의 첫 원소를 가리키는 반복자.
	//end() 컨테이너의 마지막 원소의 다음을 가리키는 반복자.
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter)//후위 연산자는 데이터를 증가시키고 이전 값을 증가시키기 때문에 연산이 무거움
	{
		cout << *iter << ",";
	}
	cout << endl;
	//rbegin() 컨테이너의 마지막 원소를 가리키는 반복자.
	//rend() 컨테이너의 첫 원소의 이전을 가리키는 반복자.
	for (vector<int>::reverse_iterator iter = vec.rbegin(); iter != vec.rend(); ++iter)
	{
		cout << *iter << ",";
	}
	cout << endl;
	cout << vec.size() << endl;

	return 0;
}
*/