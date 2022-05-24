#include <stdio.h>

int main()
{
    int N;
    int n;
    int a = 0;
    int A;
    int B;
    int C;

    scanf("%d", &N);
    n = N;
    while (1)
    {
        B = N / 10 % 10;
        A = N % 10;
        C = (A + B) % 10;
        N = (A * 10) + C;
        a++;
        if (N == n)
        {
            break;
        }
    }
    printf("%d\n", a);
}
    
    /*
    int A;
    int B;

    while (scanf("%d %d", &A, &B) != EOF)
    {
        printf("%d\n", A + B);
    }
}
    
    /*
    int N;
    int X;
    int A;

    scanf("%d %d", &N, &X);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A);
        if (A < X)
        {
            printf("%d ", A);
        }
    }
    return 0;
}

    
    /*
    int A;
    int B;
    int C;

    scanf("%d", &A);

    for (int i = 1; i < A + 1; i++)
    {
        scanf("%d %d", &B, &C);
        printf("Case #%d: %d + %d = %d\n",i ,B , C, B + C);

    }
}/*
    int N;

    scanf("%d", &N);
    for (int i = N; i > 0; i--)
    {
        printf("%d\n", i);
    }
}
    /*
    int n;
    int c = 0;

    scanf("%d", &n);

    for (int i = 1; i < n + 1; i++)
    {
        c += i;
    }
    printf("%d", c);
}
 /*   
    int A;
    int B;
    int C;

    scanf("%d", &A);

    for (int i = 0; i < A; i++)
    {
        scanf("%d %d", &B, &C);
        printf("%d\n", B + C);

    }
}
    /*
    int A;
    int B;
    int C;
    int D;

    scanf("%d %d %d", &A, &B, &C);

    if (A == B && A == C)
    {
        D = 10000 + A * 1000;
    }
    else if (B == C || C == A)
    {
        D = 1000 + C * 100;
    }
    else if (A == B)
    {
        D = 1000 + A * 100;
    }
    else if (A != B || A != C || B != C)
    {
        if (A > B && A > C)
        {
            D = A * 100;
        }
        else if (B > A && B > C)
        {
            D = B * 100;
        }
        else
        {
            D = C * 100;
        }
    }
    printf("%d", D);
}

    /*
    int H;
    int M;
    int C;

    scanf("%d %d", &H, &M);
    scanf("%d", &C);

    while (C >= 60)
    {
        C -= 60;
        H += 1;
    }
    
    if (M + C >= 60)
    {
        H += 1;
        M = M + C - 60;
    }
    else
    {
        M = M + C;
    }
    if (H >= 24)
    {
        H -= 24;
    }
    printf("%d %d", H, M);
    
    return 0;
}

    /*
    int A;
    int B;
    int B1;
    int B2;
    int B3;

    scanf("%d", &A);
    scanf("%d", &B);

    B1 = ((B / 100) % 10);
    B2 = ((B / 10) % 10);
    B3 = B % 10;

    printf("%d\n", B3 * A);
    printf("%d\n", B2 * A);
    printf("%d\n", B1 * A);
    printf("%d\n", A * B);

    return 0;
}




/*
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int Star1 = 1;
    int Star7 = 0;
    int N;
    int k = 1;

    cin >> N;


    for (int Star2 = 1; Star2 > 0; Star2++)
    {
        for (int Star3 = N; Star3 > Star1; Star3--)
        {
            printf(" ");
        }
        for (int Star3 = N - k; Star3 < N; Star3++)
        {
            printf("*");
        }
        k += 2;
        printf("\n");
        Star1++;
        if (Star1 == N)
        {
            break;
        }
    }
    for (int Star2 = 1; Star2 > 0; Star2++)
    {
        for (int Star3 = 0; Star3 < Star7; Star3++)
        {
            printf(" ");
        }
        Star7++;
        for (int Star4 = k; Star4 > 0; Star4--)
        {
            printf("*");
        }
        k -= 2;
        printf("\n");
        if (k < 0)
        {
            break;
        }
    }
}*/