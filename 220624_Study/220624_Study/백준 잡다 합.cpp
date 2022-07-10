#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    string arr[100001];

    string name;

    unordered_map <string, int> pocketMon;

    for (int i = 1; i <= N; i++) 
    {
        cin >> name;

        pocketMon.insert(make_pair(name, i));
        arr[i] = name;
    }

    for (int i = 0; i < M; i++) 
    {
        string input;
        cin >> input;

        if (pocketMon.find(input) != pocketMon.end())
        {	
            cout << pocketMon.find(input)->second << "\n";
        }
        else {
            int num = stoi(input);
            cout << arr[num] << "\n";
        }
    }

    return 0;
}