// 그림
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y first

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    queue<pair<int, int>> Q;
    int vis[n][m] = {};
    vis[0][0] = 1;
    Q.push({0, 0});

    /*  make board  */
    int board[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    /* find painting*/
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        cout << "HI" << '\n';
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (vis[nx][ny] == 1 || board[nx][ny] == 0)
                continue;

            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
}