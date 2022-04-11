/*


    데이터 타입
    1. 정수형 (-2, -1, 0, 1, 2)
    int
    short
    long
    longlong
    __int8  __int 16  __int 32  __int 64

    2. 실수형
    float
    double
    long double

    3. 문자형
    char
    
    4. 문자열
    string

    변수명 이름짓지 규칙 (표시법)
    
    1. 헝가리안 표기법

    2. 카멜 표기법

    3. 파스칼 표기법

    4가지 속성
    1) 이름 2) 크기 3) 값 4) 메모리 주소


    연산자
    데이터를 가능하는 모든 명령에 필요한 것
    1) 어떤 종류의 연산자인가.
    2) 어떤 순서로 연산이 되는가.
    3) 결합 순서 : 좌측부터 연산하는가, 오른쪽부터 연산하는가.

    1. 사칙연산
    +(더하기) -(빼기) *(곱하기) /(나누기) %(나머지)

    2.대입연산자
    =

    3.복합대입연산자
    +=, -=, *=, /=(0으로 나눌 때 런타임 에러 발생), %=(데이터 타입이 정수형이 아닐 때 에러발생)

    4.증감연산자
    특정 변수값을 1씩 증가 혹은 감소시키는 연산자
    a++, ++a, a--, --a 

    5.관계연산자
    < , >, 

    6.논리연산자
    왼쪽 항과 오르쪽 항의 값을 각각 참과 거짓으로 연산해서 두 값을 비교해서 참과 거짓을 반환하는 연산자
    
    && :논리곱(AND) a && b  a의 결과값이 참이고 b의 결과값이 참이면 1을 반환
    || :논리합(OR)  a || b  a의 결과값이 참이거나 b의 결과값이 참이면 1을 반환
    ! : 논리부정(NOT)  !a  a의 결과값이 참이면 0(False) 거짓이면 1을 반환

    7.삼항연산자
    a ? b : c; a가 참이면 b가 동작 거짓이면 c가 동작

    난수

    함수 내부에 seed값이 있어서 이 값에 의해서 리턴값이 바뀐다.
    기본적으로 seed는 1로 세팅되어 있다.

    srand(time(NULL));


    과제 1. rand값의 데이터 타입은? short
    
    실습 1. 3 ~ 7사이의 랜덤한 숫자를 출력하는 프로그램을 작성하자.
    실습 2. 가장 작은 값과 큰 값을 입력 받아서 그 사이의 임의의 값을 출력하는 프로그램을 작성
    실습 3. 프로그램을 실행하면 내부적으로 1~10 사이의 숫자가 정답으로 정해진다.
    1~10 사이의 숫자를 입력하면 맞으면 True 틀리면 False를 출력한다.


*/

#include <iostream>
#include <string>

using namespace std;

int main()
{   
    srand(time(NULL));
    cout << rand() % 5 + 3 << endl;

    /*
    int SNum;
    int PNum;
    int Ran;
    int RanIn;

    srand(time(NULL));
    cout << rand()% 5 + 3 << endl;//실습 1

    cout << "\n실습 2\n";

    cout << "최소 수 입력 : ";cin >> SNum;
    cout << "최대 수 입력 : ";cin >> PNum;
    cout << rand() % (PNum - SNum - 1) + SNum << endl;//실습 2

    Ran = rand()% 10 + 1;
    cout << "정답입력" << endl;
    cin >> RanIn;
    cout << Ran << endl;
    (Ran == RanIn) ? cout << "정답" << endl : cout << "오답" << endl;//실습 3
    */


    /*
    int input_key = 10;
    float Test_F1 = 5.3f;
    float Test_F2 = 5.3;//f를 붙이지 않으면 double로 처리한다.(마우스 올리면 보임)
    char Test_C = 'a';
    string Test_S = "Hello";

    cout << "Hello World!\n";
    cin >> input_key;
    */

    /*
    int Num[89];//행렬

    srand((unsigned int)time(NULL));
    cout << "로또 번호 출력\n" << endl;

    for (int a = 0; a < 6; a++)
    {
        Num[a] = rand() % 44 + 1;
        cout << Num[a] << "   ";
    }
 */
    /*
    double a[89];//개발 카드 변수
    int c = 0;
    double d;
    int b;//계산용

    
    a[0] = 0.110240311;
    
    srand((unsigned int)time(NULL));

    while (true)
    {        
        a[c] = 0 / 10000000;

        d = rand() % 9999998+1;

        a[c] =(d / 1000000) + a[c];
        cout << "a" << "[" << a[c] << "]" <<a[c] << endl;
        c++;

        if (c == 89)
        {
            break;
        }
    }

    cin >> c;

    b = a[c] * 10;//녹색 토큰
    b = b % 10;
    cout << "녹색 토큰 " << b << endl;
    b = a[c] * 100;//청색 토큰
    b = b % 10;
    cout << "청색 토큰 " << b << endl;
    b = a[c] * 1000;//백색 토큰
    b = b % 10;
    cout << "백색 토큰 " << b << endl;
    b = a[c] * 10000;//흑색 토큰
    b = b % 10;
    cout << "흑색 토큰 " << b << endl;
    b = a[c] * 100000;// 적색 토큰
    b = b % 10;
    cout << "적색 토큰 " << b << endl;
    b = a[c] * 1000000;//황금 토큰
    b = b % 10;
    cout << "황금 토큰 " << b << endl;
    b = a[c] * 10000000;//점수
    b = b % 10;
    cout << "점수 " << b << endl;
    b = a[c] * 100000000;//트루 확인
    b = b % 10;
    cout << "트루 확인 " << b << " (1: 필드 위에 존재하지 않음 2: 필드 위에 존재함)" << endl;
    b = a[c] * 1000000000;//예약 확인
    b = b % 10;
    cout << "예약 확인 " << b << " (1, (예약 없음) 2(1P), 3(2P), 4(3P), 5(4P) 숫자로 플레이어 예약 표시)" << endl;
    /*
    int a; //행동 변수 
    
    while (true)
    {
        cin >> a;// 숫자로 행동을 정함 (0. 다른 토큰 3개+  1. 같은 토큰 2개+  2. 카드 구매  3. 예약  4. 귀족 타일 구매(턴 소모 없음))
    // 그외 에러(예외 처리)
        if (a == 4)
        {
            //귀족 타일 구매 조건 충족 시 구매
            // 하나만 구매 가능
        }

        if (a == 0)
        {
            // 1. 다른 토큰 3개 뽑기
            break;
        }
        else if (a == 1)
        {
            // 2. 같은 토큰 2개 뽑기
            break;
        }
        else if (a == 2)
        {
            // 3. 카드 구매
            break;
        }
        else if (a == 3)
        {
            // 4. 예약
            break;
        }
    }
    */


//변수의 이름 표시 #define 이름 값

}