// 단지번호붙이기
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

#define X first
#define Y second

int board[27][27];
bool vis[27][27];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n;

int dfs(int &i, int &j)
{
    int house = 0;
    stack<pair<int, int>> S;
    S.push({i, j});
    vis[i][j] = 1;

    while (!S.empty())
    {
        house++;
        auto cur = S.top();
        S.pop();
        for (int d = 0; d < 4; d++)
        {
            int nx = cur.X + dx[d];
            int ny = cur.Y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (vis[nx][ny] || board[nx][ny] == 0)
                continue;

            vis[nx][ny] = 1;
            S.push({nx, ny});
        }
    }
    return house;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> V;
    cin >> n;
    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < n; j++)
            board[i][j] = str[j] - '0';
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] || board[i][j] == 0)
                continue;
            V.push_back(dfs(i, j));
            cnt++;
        }
    }

    sort(V.begin(), V.end());
    cout << cnt << '\n';
    for (auto i : V)
        cout << i << '\n';
}