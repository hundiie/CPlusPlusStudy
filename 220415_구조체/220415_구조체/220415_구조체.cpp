/*프로그래밍 기초(메모리, cpu, 디스크)
getch()

구조체
1. 절차적
2. 구조적
3. 객체지향적

---추상화
c언어에서 코드를 추상화하는 데 사용되는 삼총사 : 배열, 구조체, 함수
추상화? 실제 세계(현상)를 간략화, 기호화, 보편화 해서 표현한 것

코드에 추상화가 필요한 이유

결국 코드는 사람이 짜는 것이기 때문에 다른 사람이 코드를 해석하기 편해야하고
다른 사람이 인수인계받아서 유지보수하기 편해야하고
다른 사람들과 함께 공동으로 코드를 만들기 편해야하고

배열 : 속성이 동일한 여러 데이터를 같은 이름과 순서를 지정한 연속된 번호로 서로 연관되어 있음을 표시함으로서 추상화 -변수명[숫자]

구조체 : 데이터(자료형)을 실제로 쓰이는 데이터끼리 묶어서 추상화

함수 : 프로세스(코드)를 특정 기능 단위로 묶어서 추상화한다.


최악의 추상화 -> 추상화 단계를 상승시키는 과정

		string a, b, c  <- 최악의 추상화(변수를 만든 의도도 묶지도 않았다.)
		string a[3]  <- 위의 것 보다는 좀 나음
		string name1, name1, name1 <- 아니면 이런 식으로
		string StudentName[3] <- 의도가 명료하게 드러나기 때문에 좋은 추상화


	구조체
	-변수를 모아놓은 집합체
	-특정 변수들이 무언가의 하위 개념으로 묶일 수 있을 때
	-StudentName[10] StudentAge[10] StudentScore[10] ....
	'학생'의 '~~' 이름, 나이, 점수, 석차 등등을 '학생' 이라는 구조체로 묶어서 사용

	구조체를 정의하는 위치 : 구조체가 사용되는 함수의 앞에 정의한다.
	int main() 우리가 현재 쓰고있는 유일한 함수
	해당 함수의 바깥쪽 앞(위) 에 정의한다.

	2. 구조체 정의의 방법

	struct 구조체 변수명
	{
		구조체 안에 들어갈 변수들
	};  //세미콜론을 해줌
	(위의 예시로 치면 이름 나이 점수 석차 등등이 하위변수이다.

	구조체를 일종의 우리가 새롭게 만든 데이터형

	구조체 안에 들어갈 수 있는 하위변수는 무엇이 있을까?
	당연히 int, bool, float 같은 기본 자료형은 모두 사용가능
	string <- 클래스도 쓸수있다.
	student[10] 배열도 쓸수있다.
	앞에서 정의한 구조체도 넣을 수 있다.
	
	 중괄호 끝과 세미콜론 사이에 Student의 변수를 미리 선언 해둘 수 있다.
	 
	 구조체의 선언과 초기화
	 기본적으로 구조체 변수의 개념은 배열 변수의 개념과 동일하다.
	 int a[3] = {10,20,30}
	 a[0] = 10; a[1] = 20; a[3] = 30;
	 구조체 변수도 다음과 같이 초기화 할 수 있다.

	player.HP = player.HP - monster[n].dmg;
	주석없이 코드를 배우지 않은 사람에게도 어느 정도의 가독성이 확보된다.
	
	/*과제 : 미궁 탈출 게임을 업데이트
	
	사용할 수 있는 모든 요소에 구조체를 활용해서 소스 코드를 개선해 봅시다.

	tile : 지형 정보를 넣고 (숲, 늪, 평지)
	player : 피로도를 넣고
	플레이어가 어느 지형에 있는지. 플레이어의 피로도가 얼마인지(숲 -1 늪 -3 평지 0)
	표시되도록 수정해 봅시다.

	100 짝수 5의 배수

	5. 1~100 사이의 임의의 숫자를 맞추는 게임
	오답을 입력하면 컴퓨터가 정답이 오답보다 큰지 작은지 알려주고 다섯번 안에 못맞추면 게임 오버

	6.숫자 대신 알파뱃 중 하나를 입력 받고 컴퓨터가 생각하는 알파뱃과 같은 값을 찾는 게임만들기. 기본 규칙은 5와 비슷
	(틀렸을 때 입력한 문자보다 앞에 있는지, 뒤에 있는지 알려주고 5번 까지 기회를 줌)

	7. 몬스터라는 구조체를 만들고 5개를 선언하시오. 5개의 이름은 cin으로 입력받게 하고 몬스터의 공격력 방어력은 랜덤으로 설정되도록 하시오.
	그 후 사이의 숫자를 입력하면 번호에 해당하는 몬스터의 이름, 공격력, 방어력을 출력하시오.

*/
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

struct player
{
	int x;
	int y;
	string icon;
};
struct tile
{
	string name;
	int heavy;
	string icon;
};
struct map
{
	string size[20][20][4];
	tile filed;
};

int main()
{
	int random_x, random_y;
	map Position;
	tile land = { "길",0,"  " };
	tile forest = { "숲",1,"▲" };
	tile swamp = { "늪",2,"▣" };
	tile exit= { "문",3,"★" };
	player my = {0, 0, "○" };
	int sleep= 30;
	srand(time(NULL));

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			Position.size[i][j][0] = land.icon;
		}
	}

	for (int i = 0; i < 80; i++)
	{
		random_x = rand() % 19 + 1;
		random_y = rand() % 19 + 1;
		Position.size[random_x][random_y][1] = forest.icon;
		Position.size[random_x][random_y][0] = forest.icon;
	}
	for (int i = 0; i < 80; i++)
	{
		random_x = rand() % 19 + 1;
		random_y = rand() % 19 + 1;
		Position.size[random_x][random_y][2] = swamp.icon;
		Position.size[random_x][random_y][0] = swamp.icon;
	}
	my.x = rand() % 19 + 1;
	my.y = rand() % 19 + 1;

	random_x = rand() % 19 + 1;
	random_y = rand() % 19 + 1;
	Position.size[random_x][random_y][0] = exit.icon;

	while (true)
	{
		
		Position.size[my.x][my.y][0] = my.icon;
		
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				cout << Position.size[i][j][0];
			}
			cout << endl;
		}
		cout << "플레이어 좌표" << my.x << " : " << my.y << endl;
		cout << "피로도 : " << sleep <<endl;
		
		int key = _getch();
		system("cls");
		
		if (Position.size[my.x][my.y][1] != forest.icon && Position.size[my.x][my.y][2] != swamp.icon)
		{
			cout << "통과한 장소 : " << land.name << endl;
			Position.size[my.x][my.y][0] = land.icon;
		}
		if (Position.size[my.x][my.y][1] == forest.icon)
		{
			cout << "통과한 장소 : " << forest.name << endl;
			Position.size[my.x][my.y][0] = forest.icon;
			sleep -= 1;
		}
		if (Position.size[my.x][my.y][2] == swamp.icon)
		{
			cout << "통과한 장소 : " << swamp.name << endl;
			Position.size[my.x][my.y][0] = swamp.icon;
			sleep -= 2;
		}
		
		sleep -= 1;

		if (sleep <= 0)
		{
			cout << "피로도 0" << endl;
			break;
		}
		
		cout << endl;
		if (key < 96)//소, 대문자를 소문자로 통일화
		{
			key += 32;
		}
		switch (key)
		{
		case 97: //a
			if (my.y != 0)//플레이어 이동 제한
			{
				my.y -= 1;
			}
			break;
		case 115: //s
			if (my.x != 19)
			{
				my.x += 1;
			}
			break;
		case 100: //d
			if (my.y != 19)
			{
				my.y += 1;
			}
			break;
		case 119: //w
			if (my.x != 0)
			{
				my.x -= 1;
			}
			break;
		default:
			break;
		}
		if (Position.size[my.x][my.y][0] == exit.icon)
		{
			cout << "탈출!" << endl;
			break;
		}
	}

}


// 구조체를 정의하는 장소

/*
struct Score
{
	int kor;
	int eng;
	int math;
};

struct student
{
	string name;
	int age;
	string homeTown;
	int pride;
	Score score;// 구조체 안에 구조체를 넣을 수 있다.

}SEO, HUN, EE;  //중괄호 끝과 세미콜론 사이에 변수를 넣어 Student의 변수를 미리 선언 해둘 수 있다.
//name, age, score, rank라는 하위 변수를 가지고 있는 student라는 구조체를 정의한다.

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int main()
{
	student minseop;
	minseop.name = "심민섭"; //minseop의 name은 심민섭이다.
	minseop.age = 24; //minseop의 age는 24이다.
	minseop.homeTown = "인천";
	minseop.pride = 100;
	minseop.score.eng = 50;
	minseop.score.kor = 70;
	minseop.score.math = 90;


	cout << minseop.name << endl;
	cout << minseop.age << endl;
	cout << minseop.homeTown << endl;
	cout << minseop.pride << endl;
	cout << minseop.score.eng << endl;
	cout << minseop.score.kor << endl;
	cout << minseop.score.math << endl;

	student daHun;
	daHun.name = "이다훈";
	daHun.age = 28;
	daHun.homeTown = "진주";
	daHun.pride = 50;
	Score myscore = { 50,80,90 };//배열을 초기화하듯 구조체 변수도 초기화 할 수 있다.
	//ex) monster a = {"고블린",79,55.12f, true, 100};
	cout << myscore.kor << myscore.eng << myscore.math << endl;
	//실습 : student구조체를 사용 자신의 정보를 입력하자.

	cout << daHun.name << endl;
	cout << daHun.age << endl;
	cout << daHun.homeTown << endl;
	cout << daHun.pride << endl;
}*/

	
