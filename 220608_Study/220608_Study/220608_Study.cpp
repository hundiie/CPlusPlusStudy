#include <string>
#include <vector>

using namespace std;

#define pat1 5//반복 수를 매크로로 저장
#define pat2 8
#define pat3 10

vector<int> solution(vector<int> answers)
{//반복 패턴 저장
	int player1[pat1] = { 1,2,3,4,5 };
	int player2[pat2] = { 2,1,2,3,2,4,2,5 };
	int player3[pat3] = { 3,3,1,1,2,2,4,4,5,5 };

	vector<int> answer;

	vector<int> _player1;
	vector<int> _player2;
	vector<int> _player3;

	int count1[2] = { 0 };//[0]은 반복 패턴 수 카운터 [1]은 정답 수 카운터
	int count2[2] = { 0 };
	int count3[2] = { 0 };

	for (size_t i = 0; i < answers.size(); i++)
	{
		_player1.push_back(player1[count1[0]]);	//수포자가 찍은 정답 대입
		if (_player1[i] == answers[i])			// 수포자가 찍은 정답과 정답을 비교
		{count1[1]++;}	// 정답일 때 카운터[1] + 1
		count1[0]++;	//반복 패턴 +1
		if (count1[0] > pat1 - 1)	// 반복 패턴 끝나면 처음부터 반복 패턴 시작
		{count1[0] = 0;}

		_player2.push_back(player2[count2[0]]);//수포자2 반복
		if (_player2[i] == answers[i])
		{count2[1]++;}
		count2[0]++;
		if (count2[0] > pat2 - 1)
		{count2[0] = 0;}

		_player3.push_back(player3[count3[0]]);//수포자3 반복
		if (_player3[i] == answers[i])
		{count3[1]++;}
		count3[0]++;
		if (count3[0] > pat3 - 1)
		{count3[0] = 0;}
	}

	//정답 수를 각각 count1[1], count2[1], count3[1] 에 저장 후 각 정답수를 비교
	if (count1[1] == count2[1] && count1[1] == count3[1]) { answer = { 1,2,3 }; }//셋 다 같을 때
	//여길 넘기면 셋 다 같은 수가 아님
	else if (count2[1] < count1[1] && count3[1] < count1[1]) { answer = { 1 }; }// 1이 제일 클때
	else if (count1[1] < count2[1] && count3[1] < count2[1]) { answer = { 2 }; }// 2가 제일 클때
	else if (count1[1] < count3[1] && count2[1] < count3[1]) { answer = { 3 }; }// 3이 제일 클때
	// 여길 넘기면 제일 큰 수가 두개
	else if (count1[1] == count2[1]) { answer = { 1,2 }; }// 1, 2 체크
	else if (count2[1] == count3[1]) { answer = { 2,3 }; }// 2, 3 체크
	else if (count1[1] == count3[1]) { answer = { 1,3 }; }// 1, 3 체크

	return answer;
}



int main()
{
	vector<int> _pl = {1,3,2,4,2};
	solution(_pl);
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