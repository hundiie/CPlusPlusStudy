#include <iostream>
#include <stdbool.h>    // bool, true, false가 정의된 헤더 파일 
using namespace std;

int main()
{
    /*
        연산자
        데이터를 가공(연산)하는 모든 명령에 필요한 것들
        1) 어떤 종류의 연산자들이 있는가?
        2) 우선 순위 : 어떤 순서로 연산이 진행되는가?
        3) 결합 순서 : 좌측부터 연산하는 연산자, 우측부터 연산하는 연산자

        1. 사칙연산 : 산술연산자

        + : 더하기
        - : 빼기
        * : 곱하기
        / : 나누기     11 / 3 = 3
        % : 나머지     11 % 3 = 2(나머지만 표시)

        *,/,%  >  +,-

        2. 대입연산자

        = : 왼쪽 항에 오른쪽 항의 값을 대입한다.(복사한다)

        3. 복합대입연산자

        += : a += b; -> a = a + b;
        -= : a -= b; -> a = a - b;
        *= : a *= b; -> a = a * b;
        /= : a /= b; -> a = a / b;
        %= : a %= b; -> a = a % b;(a와 b는 정수형 타입이어야 한다)

        4. 증감연산자
        특정 변수의 값을 1씩 증가시키거나 감소시킬 때 사용한다.
        변수의 앞이나 뒤에 ++ , -- 를 붙여서 사용한다.

        5. 관계연산자
        두 값을 비교한 결과가 참(1, true)인지 거짓(0, false)인지 반환하는 연산자

        < : a < b : 왼쪽 항의 값이 오른쪽 항의 값보다 작으면 참을 반환한다.
        > : a > b : 왼쪽 항의 값이 오른쪽 항의 값보다 크면 참을 반환한다.
        <= : a <= b : 왼쪽 항의 값이 오른쪽 항의 값보다 작거나 같으면 참을 반환한다.
        >= : a >= b : 왼쪽 항의 값이 오른쪽 항의 값보다 크거나 같으면 참을 반환한다.
        == : a == b : 왼쪽 항의 값과 오른쪽 항의 값이 같을 때 참을 반환한다.
        != : a != b : 왼쪽 항의 값과 오른쪽 항의 값이 다를 때 참을 반환한다.

        /*
        실습
        1.고객의 나이를 입력받아서 미성년자(19세 이하)이면 FALSE를 출력 성인이면 TRUE를 출력
        2.아까 입력 받은 나이를 기준으로, 주민 등록증 발급 대상이면(20세 만) TRUE를 아니면 FALSE를 출력

        +아홉수 (1의 자리가 9인 수)인지 확인해서 TRUE, FALSE를 출력
        */

        /*
        //사칙연산 예시
        int left_value = 11;
        int right_value = 3;
        //0으로 나눌때 런타임 에러 발생

        cout << "Left_value = " << left_value << "\n" << "Right_value = " << right_value << "\n\n";

        cout << " + : " << left_value + right_value << endl;
        cout << " - : " << left_value - right_value << endl;
        cout << " * : " << left_value * right_value << endl;
        cout << " / : " << left_value / right_value << endl;
        cout << " % : " << left_value % right_value << endl;
        */

        /*
        //복합대입연산자 예시
        int left_value = 11;
        int right_value = 3;
        int a;
        a = left_value;

        cout << "Left_value = " << left_value << "\n" << "Right_value = " << right_value << "\n\n";

        cout << " + : " << " A = " << (left_value += right_value) << endl;
        left_value = a;
        cout << " - : " << " A = " << (left_value -= right_value) << endl;
        left_value = a;
        cout << " * : " << " A = " << (left_value *= right_value) << endl;
        left_value = a;
        cout << " / : " << " A = " << (left_value /= right_value) << endl;
        left_value = a;
        cout << " % : " << " A = " << (left_value %= right_value) << endl;
        */
        /*
            //증감연산자 예시
            int left_value = 14;
            int a;
            a = left_value;

            cout << " Left_value = " << left_value << "\n" << "\n\n";

            cout << " 앞++ 출력 " << ++left_value << " 메모리" << left_value << endl; //출력 : 15 메모리 : 15
            left_value = a;
            cout << " 뒤++ 출력 " << left_value++ << " 메모리" << left_value << endl; //출력 : 14 메모리 : 15
            left_value = a;
            cout << " 앞-- 출력 " << --left_value << " 메모리" << left_value << endl; //출력 : 13 메모리 : 13
            left_value = a;
            cout << " 뒤-- 출력 " << left_value-- << " 메모리" << left_value << endl; //출력 : 14 메모리 : 13
            */
            //앞 뒤 붙이는 위치에 따라 결과가 달라짐

            /*
            실습
            1.고객의 나이를 입력받아서 미성년자(19세 이하)이면 FALSE를 출력 성인이면 TRUE를 출력
            2.아까 입력 받은 나이를 기준으로, 주민 등록증 발급 대상이면(20세 만) TRUE를 아니면 FALSE를 출력
            +아홉수 (1의 자리가 9인 수)인지 확인해서 TRUE, FALSE를 출력


        int Age;

        cout << "나이 입력 : ";
        cin >> Age;
        cout << boolalpha; //1,0을 true,false로 바꿈
        cout << "미성년자?\n" << (Age >= 19) << endl;
        cout << "발급대상?\n" << (Age == 20) << endl;
        cout << "아홉수?\n" << ((Age % 10) == 9) << endl;
        cout << noboolalpha; //true,false를 1,0으로 바꿈
        */

}