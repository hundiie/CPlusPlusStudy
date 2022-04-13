#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    /*
    콘솔용 탈출게임 10 * 10 크기의 맵을 구성한다.
    (2차원 배열) 플레이어가 존재한다.(0, 0)
    탈출구가 존재한다.(0, 0)을 제외한 랜덤 설정
    WASD 키입력을 통해 플레이어를 이동시킨다.
    플레이어가 탈출구에 도달하면 "탈출 성공" 출력 후 종료
    SYSTEM("cls"); 를 이용해 콘솔 초기화를 사용한다.
    */
    /*
    string map[10][10];
    int x, y;
    int px, py;
    int key2;
    px = 0; py = 0;

    srand(time(NULL));

    for (int i = 0; i < 10; i++)// 지형 배치
    {
        for (int j = 0; j < 10; j++)
        {
            map[i][j] = "#";
        }
    }

    do// 플레이어, 출구 배치
    {
        x = rand() % 10;
        y = rand() % 10;
    } while (x == 0 && y == 0);

    map[x][y] = "E";

    while (true)
    {
        map[px][py] = "O";//플레이어 위치를 #에서 O로 바꿈

        system("cls");
        for (int i = 0; i < 10; i++)// 이동마다 초기화 후 맵 다시 깔기
        {
            for (int j = 0; j < 10; j++)
            {
                cout << map[i][j];
            }
            cout << endl;
        }
        if (px == x && py == y)// 플레이어와 탈출구의 값이 같으면 탈출
        {
            cout << "탈출 성공!";
            break;
        }
        int key = _getch()//키를 입력받음 플레이어의 위치값을 #으로 미리 바꿔둠

        map[px][py] = "#";

        if (key < 96)//입력받은 키가 대문자 일때 소문자로 통일시킴
        {
            key += 32;
        }
        switch (key)//입력받은 키를 토대로 플레이어의 위치값을 변환함
        {
        case 97: //a
            if (py != 0)//IF조건을 걸고 맵을 넘어갈 수 없도록 제한
            {
                py -= 1;
            }
            break;
        case 115: //s
            if (px != 9)
            {
                px += 1;
            }
            break;
        case 100: //d
            if (py != 9)
            {
                py += 1;
            }
            break;
        case 119: //w
            if (px != 0)
            {
                px -= 1;
            }
            break;
        default://방향키 이외에 입력은 넘김
            break;
        }
    }
    */

    /*
    A ~ Z 키 중에 하나를 정답으로 설정한다.
    하나의 키를 입력해서 설정된 값을 맞춘다.
    입력한 키와 설정된 값이 맞으면 승리를 출력하고 프로그램 종료하고
    틀리면 남은 기회를 보여주고, 5번 틀리면 정답을 알려주고 게임오버를 출력한다.
    
    + 추가로 틀릴 때마다 정답 알파뱃이 입력된 알파뱃 앞에있는지 뒤에있는지 힌트를 준다.
    + 추가로 입력된 값이 대소문자 구분없이 처리될 수 있도록 수정 해보자.
    */
    /*
    int answer;
    int key2;
    int chance = 5;

    srand(time(NULL));
    answer = rand() % 26 + 65;//아스키 코드를 보며 영어 대문자의 랜덤 값을 구해 answer에 저장

    do
    {
        cout << "A ~ Z중 하나를 입력";
        int key = _getch();//키를 입력 받음
        key2 = key;//키  값을 다른 키값에 복사해 do 밖에서도 key값을 쓰게함

        if (key2 > 96)// 아스키표를 보고 소문자를 대문자로 바꿔줌
        {
            key2 -= 32;
        }
        cout << endl;
        if (key2 != answer)//정답이 아닐 때 메세지 출력
        {
            key2 > answer ? cout << "정답은 " << (char)key2 << "보다 낮습니다.\n" //삼항연산자를 이용해 위 아래를 판단하고 다른 메세지 출력
                          : cout << "정답은 " << (char)key2 << "보다 높습니다.\n";
            cout << chance - 1 << "번의 기회가 남았습니다.\n" << endl;
        }
        chance--;// 기회값을 5로 설정하고 1씩 줄이고 기회가 0이 되면 브레이크로 루프를 탈출
        if (chance == 0)
        {
            break;
        }
    } while (key2 != answer);//정답을 맞추지 못하면 다시 루프

    if (key2 != answer)//루프를 탈출한 후 결과를 출력 (삼항연산자를 써도 되지만 if를 써봄)
    {
        cout << "정답은 " << (char)answer << "\nGAME OVER" << endl;
    }
    else
    {
        cout << "정답" << endl;
    }
    */
}   