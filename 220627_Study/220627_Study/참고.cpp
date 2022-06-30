#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
string map[25];
bool isVisited[25][25];

// ��ȯ ���� �ǹ̴� ���� �� ���� ����
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

    // 1. N�� �Է� �޴´�.
    cin >> N;

    // 2. ������ ����� �Է� �޴´�.
    for (int r = 0; r < N; ++r)
        cin >> map[r];

    // 3. ���� ���� ���� �� ���� ������ ���Ѵ�.
    int complexCount = 0;
    vector<int> houseCounts;
    for (int r = 0; r < N; ++r)
    {
        for (int c = 0; c < N; ++c)
        {
            // ���� ã�Ұ�, �湮���� �ʾҴٸ�?
            if (map[r][c] == '1' && isVisited[r][c] == false)
            {
                int houseCount = dfs(r, c);
                houseCounts.push_back(houseCount);
                ++complexCount;
            }
        }
    }
    sort(houseCounts.begin(), houseCounts.end());

    // 4. ����Ѵ�.
    cout << complexCount << "\n";
    for (int houseCount : houseCounts)
        cout << houseCount << "\n";
}