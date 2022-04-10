#include <iostream>
#include<cstdlib> //rand(), srand()
#include<ctime> //time()

using namespace std;

int main()
{
    float Ahp = 0;
    float Bhp = 0;
    float Aat = 0;
    float Bat = 0;
    int As = 0;
    int Bs = 0;
    int Ap = 0;
    int Bp = 0;
    int S;


    cout << "\nA의 체력 입력 :";
    cin >> Ahp;
    cout << "\nA의 공격력 입력 :";
    cin >> Aat;

    cout << "\nB의 체력 입력 :";
    cin >> Bhp;

    cout << "\nB의 공격력 입력 :";
    cin >> Bat;

    cout << "\n최소, 최대 공격력 비율 % :";
    cin >> S;

    As = (Aat * (100 - S)) / 100;// A의 최소 공격력 계산
    Ap = (Aat * (100 + S)) / 100;// A의 최대 공격력 계산

    Bs = (Bat * (100 - S)) / 100;// B의 최소 공격력 계산
    Bp = (Bat * (100 + S)) / 100;// B의 최대 공격력 계산

    cout << "A의 최소 공격력 : " << As << endl;
    cout << "A의 최대 공격력 : " << Ap << endl;

    cout << "B의 최소 공격력 : " << Bs << endl;
    cout << "B의 최대 공격력 : " << Bp << endl;
    cout << "\n";

    srand((unsigned int)time(NULL));

    int Turn = 1;
    int Time = 0;
    float Adm = 0;
    float Bdm = 0;
    
    //--------------------

    while (true) // 단순히 공격만 주고 받을 때
    {
        cout << Turn << "번째 턴" << endl;
        Turn++;//턴 표시

        cout << "\n";

        Adm = rand() % (Ap - As - 1) + As; //A의 데미지 랜덤 함수
        cout << " A의 공격!(데미지 : " << Adm << " )" << endl;

        cout << " B의 남은 체력 : " << "[" << Bhp << " - " << Adm << "] = ";
        Bhp -= Adm;
        cout << Bhp;
        cout << "\n";

        Bdm = rand() % (Bp - Bs - 1) + Bs; //B의 데미지 랜덤 함수
        cout << " B의 공격!(데미지 : " << Bdm << " )" << endl;

        cout << " A의 남은 체력 : " << "[" << Ahp << " - " << Bdm << "] = ";
        Ahp -= Bdm;
        cout << Ahp;
        cout << "\n\n";

        cout << "한 턴씩 넘기기(아무 숫자 입력) 스킵하기(숫자 외 아무거나 입력)" << endl;
        cin >> Time;
        cout << "\n\n";

        if (Ahp <= 0)// A의 체력이 없을 때
        {
            if (Bhp <= 0)// B의 체력도 없을 때
            {
                cout << "무승부!" << endl;
                break;
            }
            else
            {
                if (Ahp <= 0)//A만 체력이 없을 때
                {
                    cout << "B의 승리!" << endl;
                    break;
                }
            }
        }
        else
        {
            if (Bhp <= 0)// B의 체력이 없을 때
            {
                if (Ahp <= 0)// A의 체력도 없을 때
                {
                    cout << "무승부!" << endl;
                    break;
                }
                else
                {
                    if (Bhp <= 0)//B만 체력이 없을 때
                    {
                        cout << "A의 승리!" << endl;
                        break;
                    }
                }
            }
        }
    }

    //--------------------

}

    //rand() % 96 + 5이면 5~100까지의 수가 생성됨. (5 ~(96 + 5 - 1))
    //srand(time(NULL));
<<<<<<< Updated upstream
    //cout << "Random Num : " << rand() %100 << "\n";
    
=======
    //cout << "Random Num : " << rand() %100 << "\n";
>>>>>>> Stashed changes
