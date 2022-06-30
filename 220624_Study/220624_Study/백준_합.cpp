#include <iostream>

using namespace std;

long PLUS(long num)
{
    if (num <= 0)
    {
        return 0;
    }

    long C[10] = { 0 }, S = 1;
    long sum = 0, K, L;
    while (num > 0)
    {
        K = num / (S * 10);
        L = num % (S * 10);

        for (int i = 0; i < 10; i++)
        {
            C[i] += K * S;
        }
        for (int i = 1; i <= L / S; i++)
        {
            C[i] += S;
        }
        
        C[(L / S + 1) % 10] += L % S;
        
        num -= 9 * S;
        S *= 10;
    }
    for (int i = 1; i < 10; i++) sum += i * C[i];
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long S, E;
    cin >> S >> E;
    cout << PLUS(E) - PLUS(S - 1);
}