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


    제어문     데이터(타입)  / 연산자 / <제어구조>

    1.조건문 : 특정 조건에 따라서 실행문을 실행할지 안 할지 제어한다.(if, swith)
    2.반복문 : 특정 조건에 따라서 실행문을 일정 횟수만큼 반복 실행 제어(while, for)
    

    조건문
    
    1-1. if문

    if(조건식 1) = (조건식 1) 의 결과가 참일 때 (실행문 1) 이 실행 됨
    {
        (실행문 1)
    }
    else if(조건식 2) = (조건식 1)이 틀리고 (조건식 2)가 맞으면 (실행문 2)를 실행
    else = (조건식 1) 의 결과가 거짓일 때 (실행문 2)가 실행 됨
    {
        (실행문 2)
    }

    1-2. swith문

    swith(정수형 변수)
    
    {
        case 정수1 : 
            실행문1
            break;
        case 정수2 :
            실행문2
            break;

        case 정수3 :
            실행문3
            break;

        default : 해당하는 정수값이 없을 때
            break;
    }

    실습 1
    
    정수를 하나 입력 받아서 입력 받은 숫자가 10보다 크면 "입력된 숫자가 10보다 큽니다." 출력
    10 이하 9초과 라면 "9보다 큽니다." 출력
    9 이하 6초과 라면 "6보다 큽니다." 출력
    그 이외에는 "6보다 작거나 같습니다." 출력


    실습 2
    switch
    당신의 고향은 어디입니까?
    1. 서울 2. 양평 3. 광주 4.대전 5.제주도
    
    "안녕하세요 당신의 고향은 서울이군요." 답에 따라 지역만 바꿔서 출력
    

    디폴트 값 "5중에 선택해 주세요" 출력

    반복문
    2-1. while문
    조건식이 True(참)이면 반복으로 실행이 된다.

    while (조건식)
    {
        (실행문);
        반복을 끝내는 방법 :조건식을 바꾸는 실행문을 넣는다.
        if문 내에 break;를 넣는다.

        if(조건식)
        {
        break;
        }

    }

    do while 문

    do
    {
        실행문
    }
    while(조건식);

    while문을 써서 정답을 맞출 때까지 반복하는 프로그램으로 수정해보자.

    
    2-2 for문

    for(초기식; 조건식; 증감식;)
    {
        실행문;
    }
     int a = 0;   // 초기식
     a < 10   // 조건식
     a++   // 증감식

     for문 행동 순서

     (1)초기식
     (2)조건식 : 참 거짓 판단
     (4)실행문 : 조건식이 참일 때 실행
     (3)증감식 : 조건식 변경
     (2)조건식 .
     (4)실행문 .
     (3)증감식 .

     //for문

     실습 1. 10부터 1까지 차례대로 출력되는 코드를 작성해보자. 10, 9, 8, 7, 6, 5 ...
     실습 2. 100 미만의 3의 배수를 차례대로 출력되는 코드를 작성해보자. 3, 6, 9, 12, 15 ...
     실습 3. 1000 미만의 2의 승수를 차례대로 출력되는 코드를 작성해보자. 2, 4, 8, 16, 32 ....
     실습 4. 구구단을 출력해보자.
     실습 4-1. 구구단 2단을 차례대로 출력해보자.
     실습 4-2. 구구단 2단 ~ 9단을 차례대로 출력해보자.
     실습 4-3. 구구단을 3x3형태로 출력해보자.


    //별 그리기

   
   1)
    *
    **
    ***
    ****
    *****
    ******
    
   
   2)
         *
        **
       ***
      ****
     *****
    ******
  
  3)
    ******
    *****
    ****
    ***
    **
    *
   
   4)
    ******
     *****
      ****
       ***
        **
         *
   
   5)
         *
        ***
       *****
      *******
     *********
    ***********
  
  6)
    ***********
     *********
      *******
       *****
        ***
         *
  
  7)
         *
        ***
       *****
      *******
     *********
    ***********
     *********
      *******
       *****
        ***
         *

    */
#include <iostream>
#include <string>

using namespace std;

int main()
{
    /*
    //별찍기 실습 1
    int Star1= 1;
    int Pick;

    cout << "별 찍기 (1) 크기 : ";
    cin >> Pick;

    for (int Star2 = 1; Star2 > 0; Star2++)
    {
        for (int Star3 = 0; Star3 < Star1; Star3++)
        {
            cout << "*";
        }
        cout << endl;
        Star1++;
        if(Star1 == Pick)
        {
            break;
        }
    }
    */

    /*
    //별찍기 실습 2
    int Star1 = 1;
    int Pick;
    int k=1;

    cout << "별 찍기 (2) 크기 : ";
    cin >> Pick;


    for (int Star2 = 1; Star2 > 0; Star2++)
    {
        for (int Star3 = Pick; Star3 > Star1; Star3--)
        {
            cout << " ";
        }
        for (int Star3 = Pick-k; Star3 < Pick; Star3++)
        {
            cout << "*";
        }
        k++;
        cout << endl;
        Star1++;
        if (Star1 == Pick)
        {
            break;
        }
    }
    */

    /*
    //별찍기 실습 3
    int Star1 = 1;
    int Pick;

    cout << "별 찍기 (3) 크기 : ";
    cin >> Pick;

    for (int Star2 = 1; Star2 > 0; Star2++)
    {
        for (int Star3 = Pick; Star3 > Star1; Star3--)
        {
            cout << "*";
        }
        cout << endl;
        Star1++;
        if (Star1 == Pick)
        {
            break;
        }
    }
    */

    /*
    //별찍기 실습 4
    int Star1 = 1;
    int Star2;
    int Star4;
    int Pick;
    int k = 0;

    cout << "별 찍기 (4) 크기 : ";
    cin >> Pick;

    k = Pick;
    for (Star2 = 1; Star2 > 0; Star2++)
    {
        for (int Star3 = 0; Star3 < Star1; Star3++)
        {
            cout << " ";
        }
        Star1++;
        for (Star4 = k; Star4 > 1; Star4--)
        {
            cout << "*";
        }
        k--;
        cout << endl;
        if (Star1 == Pick)
        {
            break;
        }
    }
    */

    /*
       //별찍기 실습 5
    int Star1 = 1;
    int Pick;
    int k = 1;

    cout << "별 찍기 (5) 크기 : ";
    cin >> Pick;


    for (int Star2 = 1; Star2 > 0; Star2++)
    {
        for (int Star3 = Pick; Star3 > Star1; Star3--)
        {
            cout << " ";
        }
        for (int Star3 = Pick - k; Star3 < Pick; Star3++)
        {
            cout << "*";
        }
        k++;
        k++;
        cout << endl;
        Star1++;
        if (Star1 == Pick)
        {
            break;
        }

    }
    */

    /*
    //별찍기 실습 6
    int Star1 = 1;
    int Star2;
    int Star4;
    int Pick;
    int k = 0;

    cout << "별 찍기 (4) 크기 : ";
    cin >> Pick;

    k = Pick;
    for (Star2 = 1; Star2 > 0; Star2++)
    {
        for (int Star3 = 0; Star3 < Star1; Star3++)
        {
            cout << " ";
        }
        Star1++;
        for (Star4 = k; Star4 > 1; Star4--)
        {
            cout << "*";
        }
        k--;
        k--;
        cout << endl;
        if (k < 0)
        {
            break;
        }
    }
    */
    //별찍기 실습 7
    int Star1 = 1;
    int Star7 = 0;
    int Pick;
    int k = 1;

    cout << "별 찍기 (5) 크기 : ";
    cin >> Pick;


    for (int Star2 = 1; Star2 > 0; Star2++)
    {
        for (int Star3 = Pick; Star3 > Star1; Star3--)
        {
            cout << " ";
        }
        for (int Star3 = Pick - k; Star3 < Pick; Star3++)
        {
            cout << "*";
        }
        k++;
        k++;
        cout << endl;
        Star1++;
        if (Star1 == Pick)
        {
            break;
        }
    }
    for (int Star2 = 1; Star2 > 0; Star2++)
    {
        for (int Star3 = 0; Star3 < Star7; Star3++)
        {
            cout << " ";
        }
        Star7++;
        for (int Star4 = k; Star4 > 0; Star4--)
        {
            cout << "*";
        }
        k--;
        k--;
        cout << endl;
        if (k < 0)
        {
            break;
        }
    }






    /*
    int N1, N2;

    N1 = 2;

    for (N2 = 2; N2 < 10; N2++)//4-1 실습
    {
        cout << N1 << " * " << N2 << " = " << N1*N2 << "\n";
    }
    */
    /*
    int N1, N2;

    for (N1 = 2; N1 < 10; N1++)// 4-2 실습
    {
        for (N2 = 1; N2 < 10; N2++)
        {
            cout << N1 << " * " << N2 << " = " << N1 * N2 << endl;
        }
        cout << endl;
        N2 = 1;
    }
    */
    /*
    int N1, N2, N3, N4;

        N2 = 1;

    cout << endl;
    for (N3 = 2; N3 < 10; N3 += 3)
    {
        for (N4 = 1; N4 < 10; N4++)
        {
            for (N1 = N3; N1 < N3 + 3; N1++)
            {
                if (N1 == 10)
                {
                    break;
                }
                cout << N1 << " * " << N2 << " =" << N1 * N2 << "\t";
            }
            cout << endl;
            N2++;
        }
        N2 = 1;
        cout << endl;
    }
    */
    /*
        for (N4 = 1; N4 < 9; N4++)
        {
            for ( N1 = 2; N1 < 5; N1++)
            {
                cout << N1 << " * " << N2 << " = " << N1 * N2<< "\t";
            }
            cout << endl;
            N2++;
        }
        N2 = 1;
        cout << endl;

        for (N4 = 1; N4 < 9; N4++)
        {
            for (N1 = 5; N1 < 8; N1++)
            {
                cout << N1 << " * " << N2 << " = " << N1 * N2 << "\t";
            }
            cout << endl;
            N2++;
        }
        N2 = 1;
        cout << endl;
        for (N4 = 1; N4 < 9; N4++)
        {
            for (N1 = 8; N1 < 10; N1++)
            {
                cout << N1 << " * " << N2 << " = " << N1 * N2 << "\t";
            }
            cout << endl;
            N2++;
        }
        N2 = 1;
        */

        /*
        for (int Num1 = 10; Num1 >= 1; Num1--)
        {
            cout << Num1<< endl;
        }

        for (int Num2 = 3; Num2 <= 100; Num2 +=3)
        {
            cout << Num2 << endl;
        }


        for (int Num3 = 2; Num3 <= 1000; Num3 *= 2)
        {
            cout << Num3 << endl;
        }
        */
        //for (int Num3 = 0; Num3 >= 100; Num3 + 3)
        //{
        //    cout << Num3 << endl;
        //}
        /*
        for (int i = 0; i < 5; i++)
        {
            cout << "Hello World!" << endl;
        }
        */
        /*
        while (1)
        {
            cout << "Hello World!" << endl;
        }
        */
        /*
        int Num = 0;
        while (Num < 5)
        {
            cout << "Hello World!" << endl;
            Num++;
        }
        */
        /*
        int Num = 0;
        while (1)
        {
            cout << "Hello World!" << endl;
            Num++;

            if (Num > 4)
            {
                break;
            }
        }
        */
        /*
        int Num = 0;
        while (false)
        {
            cout << "Hello World! (1)" << endl;
            Num++;
        }
        do
        {
            cout << "Hello World! (2)" << endl;
            Num++;
        } while (true);
        */
        /*
        srand(time(NULL));

        int Num;
        int Answer = rand()% 9 + 1;
        do
        {
            cout << "정답 입력 : ";
            cin >> Num;
            if (Num != Answer)
            {
                cout << "오답" << endl;
            }
        } while (Num != Answer);
        cout << "정답";
        */

        /*
        int Num1,Num2,a;

        do
        {
            cout << "첫 번째 숫자 입력 01~200 : ";
            cin >> Num1;

        } while (!(Num1 >= 1 && Num1 <= 200));
        do
        {
            cout << "두 번째 숫자 입력 10~200 : ";
            cin >> Num2;

        } while (!(Num2 >= 10 && Num2 <= 200));
        while (Num1 < Num2)
        {
            cout << Num1 << endl;
            Num1++;
            a = Num1;
            a = a % 10;
            if (a == 7)
            {
                Num1++;
            }
        }
        */

        /*
        int SwitchTest;

        cout << "당신의 고향은 어디입니까?" << endl;
        cout << "1. 서울  2. 양평  3. 광주  4. 대전  5. 제주도" << endl;
        cin >> SwitchTest;

        if (SwitchTest == 1)
        {
            cout << "안녕하세요. 당신의 고향은 서울 이군요.\n";
        }
        else if (SwitchTest == 2)
        {
            cout << "안녕하세요. 당신의 고향은 양평 이군요.\n";
        }
        else if (SwitchTest == 3)
        {
            cout << "안녕하세요. 당신의 고향은 광주 군요.\n";
        }
        else if (SwitchTest == 4)
        {
            cout << "안녕하세요. 당신의 고향은 대전 이군요.\n";
        }
        else if (SwitchTest == 5)
        {
            cout << "안녕하세요. 당신의 고향은 제주도 군요.\n";
        }
        else
        {
            cout << "5개 중에 선택해주세요";
        }
        */
        /*
        int SwitchTest;

        cout << "당신의 고향은 어디입니까?" << endl;
        cout << "1. 서울  2. 양평  3. 광주  4. 대전  5. 제주도" << endl;
        cin >> SwitchTest;

        switch (SwitchTest)
        {
        case 1: cout << "안녕하세요. 당신의 고향은 서울 이군요.\n";
            break;
        case 2: cout << "안녕하세요. 당신의 고향은 양평 이군요.\n";
            break;
        case 3: cout << "안녕하세요. 당신의 고향은 광주 군요.\n";
            break;
        case 4: cout << "안녕하세요. 당신의 고향은 대전 이군요.\n";
            break;
        case 5: cout << "안녕하세요. 당신의 고향은 제주도 군요.\n";
            break;

        default:
            cout << "5개 중에 선택해주세요";
            break;
        }
        */
        /*
    #pragma region

        int a0,a1,a2,a3,a4,a5,a6,a7,a8,a9;
        int ran;
        a0 = 0; a1 = 0; a2 = 0; a3 = 0; a4 = 0; a5 = 0; a6 = 0; a7 = 0; a8 = 0; a9 = 0;

        srand(time(NULL));
        int k = 0;
        while (true)
        {
            ran = rand() % 10;

            switch (ran)
            {
            case 0:a0 += 1;
                break;
            case 1:a1 += 1;
                break;
            case 2:a2 += 1;
                break;
            case 3:a3 += 1;
                break;
            case 4:a4 += 1;
                break;
            case 5:a5 += 1;
                break;
            case 6:a6 += 1;
                break;
            case 7:a7 += 1;
                break;
            case 8:a8 += 1;
                break;
            case 9:a9 += 1;
                break;
            }
            k++;

            if (k > 100000)
            {
                cout << a0 << endl;
                cout << a1 << endl;
                cout << a2 << endl;
                cout << a3 << endl;
                cout << a4 << endl;
                cout << a5 << endl;
                cout << a6 << endl;
                cout << a7 << endl;
                cout << a8 << endl;
                cout << a9 << endl;
                break;
            }

        }
        */
#pragma endregion


        /*
            int Num;
            cout << "숫자 입력 : ";
            cin >> Num;

            if (10 < Num)
            {
                cout << "입력된 숫자가 10보다 큽니다.";
            }
            else if (10 >= Num && 9 < Num)
            {
                cout << "입력된 숫자가 9보다 큽니다.";
            }
            else if (9 >= Num && 6 < Num)
            {
                cout << "입력된 숫자가 6보다 큽니다.";
            }
            else
            {
                cout << "입력된 숫자가 6보다 작거나 같습니다.";
            }
            */
            /*
            int SNum;
            int PNum;
            int Ran;
            int RanIn;

            srand(time(NULL));

        #pragma region 실습
            cout << rand()% 5 + 3 << endl;//실습 1


            cout << "최소 수 입력 : ";cin >> SNum;
            cout << "최대 수 입력 : ";cin >> PNum;
            cout << rand() % (PNum - SNum - 1) + SNum << endl;//실습 2


            Ran = rand()% 9 + 1;
            cout << "정답입력" << endl;
            cin >> RanIn;
            cout << Ran << endl;
            (Ran == RanIn) ? cout << "정답" << endl : cout << "오답" << endl;//실습 3
        #pragma endregion
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