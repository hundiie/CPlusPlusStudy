#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A[5];
    int answer = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> A[i];
        if (A[i] < 40)
        {
            A[i] = 40;
        }
        answer += A[i];
    }
    cout << answer / 5;
}