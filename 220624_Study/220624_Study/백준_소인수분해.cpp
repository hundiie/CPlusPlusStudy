#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    int inum = 2;
    
    if (N != 1)
    {
        while (N > 0)
        {
            if (N % inum == 0)
            {
                cout << inum << "\n";
                N /= inum;
            }
            else
            {
                inum++;
            }
        }
    }
}