// 적록색약
#include <bits/stdc++.h>

using namespace std;

#define X first;
#define Y second;

string board[102];
int vis[102][102];
int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> board[i];

    int cnt = 0;
    char c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] == 1 || board[i][j] == c)
                continue;
            cnt++;
            queue<pair<int, int>> Q;
            vis[i][j] = 1;
            Q.push({i, j});
            c = board[i][j];
            while (!Q.empty())
            {
                auto cur = Q.front();
                Q.pop();
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;
                    if (vis[nx][ny] || board[nx][ny] != c)
                        continue;

                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
    }
    cout << cnt << '\n';
}
