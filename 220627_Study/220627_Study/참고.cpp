#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
string map[25];
bool isVisited[25][25];

// 반환 값의 의미는 단지 내 집의 개수
int dfs(int r, int c)
{
    isVisited[r][c] = true;

    static const int dr[] = { -1, 1, 0, 0 };
    static const int dc[] = { 0, 0, -1, 1 };

    int houseCount = 1;
    for (int i = 0; i < 4; ++i)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= N || nc < 0 || nc >= N)
            continue;

        if (isVisited[nr][nc] || map[nr][nc] == '0')
            continue;

        houseCount += dfs(nr, nc);
    }

    return houseCount;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 1. N을 입력 받는다.
    cin >> N;

    // 2. 단지의 모습을 입력 받는다.
    for (int r = 0; r < N; ++r)
        cin >> map[r];

    // 3. 단지 수와 단지 내 집의 개수를 구한다.
    int complexCount = 0;
    vector<int> houseCounts;
    for (int r = 0; r < N; ++r)
    {
        for (int c = 0; c < N; ++c)
        {
            // 집을 찾았고, 방문하지 않았다면?
            if (map[r][c] == '1' && isVisited[r][c] == false)
            {
                int houseCount = dfs(r, c);
                houseCounts.push_back(houseCount);
                ++complexCount;
            }
        }
    }
    sort(houseCounts.begin(), houseCounts.end());

    // 4. 출력한다.
    cout << complexCount << "\n";
    for (int houseCount : houseCounts)
        cout << houseCount << "\n";
}