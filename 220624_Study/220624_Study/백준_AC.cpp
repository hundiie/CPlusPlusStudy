#include <iostream>
#include <deque>
#define gc getchar()

using namespace std;

string p;
int main(void)
{
    int tc;

    cin >> tc;
    while (tc--) {
        bool path = true;
        bool check = true;
        int num, in, length;
        deque<int> dq;

        cin >> p >> num;
       gc, gc;

        if (num != 0)
        {
            for (int i = 0; i < num - 1; i++) 
            {
                scanf("%d,", &in);
                dq.push_back(in);
            }
            scanf("%d]", &in);
            dq.push_back(in);
        }
      gc;

        length = p.size();

        for (int i = 0; i < length; i++) 
        {
            switch (p[i])
            {
            case 'R':
            {
                path ^= true;
            }
                break;
            case 'D':
                if (dq.empty())
                {
                    check = false;
                    break;
                }

                if (path) dq.pop_front();
                else dq.pop_back();
                break;
            }
        }

        if (!check) 
        {
            puts("error");
            continue;
        }

        putchar('[');
        while (!dq.empty())
        {
            int n2;

            if (path == true) 
            {
                n2 = dq.front();
                dq.pop_front();
            }
            else 
            {
                n2 = dq.back();
                dq.pop_back();
            }

            cout << n2;

            if (dq.empty()) break;
            else putchar(',');
        }
        cout << "]\n";
    }
    return 0;
}