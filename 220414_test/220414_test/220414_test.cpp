// 220414_test.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int main()
{
    int beskin_p = 0;
    int beskin_m;
    int beskin_num = 0;

    while(1)
    {
        if (beskin_num < 31)
        {
            if (beskin_num <= 15)
            {
                beskin_m = rand() % 3;
            }
            switch (beskin_num)
            {
            case 15: beskin_m = 2;
                break;
            case 16: beskin_m = 1;
                break;
            case 17: beskin_m = 0;
                break;
            case 19: beskin_m = 2;
                break;
            case 20: beskin_m = 1;
                break;
            case 21: beskin_m = 0;
                break;
            case 23: beskin_m = 2;
                break;
            case 24: beskin_m = 1;
                break;
            case 25: beskin_m = 0;
                break;
            case 27: beskin_m = 2;
                break;
            case 28: beskin_m = 1;
                break;
            case 29: beskin_m = 0;
                break;
            }
            cout << "컴퓨터 : " << "\t";
            switch (beskin_m)
            {
            case 0: cout << (beskin_num += 1) << endl;
                break;
            case 1: cout << (beskin_num += 1) << ", ";
                cout << (beskin_num += 1) << endl;
                break;
            case 2: cout << (beskin_num += 1) << ", ";
                cout << (beskin_num += 1) << ", ";
                cout << (beskin_num += 1) << endl;
                break;
            }
        }
        else
        {
            cout << "플레이어 패배";
            break;
        }
        if (beskin_num < 31)
        {
            while (1)
            {
                cout << "1 ~ 3 숫자 입력" << endl;
                cin >> beskin_p;
                system("cls");
                cout << "플레이어 : " << "\t";
                switch (beskin_p)
                {
                case 1: cout << (beskin_num += 1) << endl;
                    break;
                case 2: cout << (beskin_num += 1) << ", ";
                    cout << (beskin_num += 1) << endl;
                    break;
                case 3: cout << (beskin_num += 1) << ", ";
                    cout << (beskin_num += 1) << ", ";
                    cout << (beskin_num += 1) << endl;
                    break;
                }
                if (beskin_p >= 1 && beskin_p <= 3)
                {
                    break;
                }
            }
            
        }
        else
        {
            cout << "컴퓨터 패배";
            break;
        }
        
    }

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
