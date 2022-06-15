// 벽 부수고 이동하기
#include <bits/stdc++.h>

using namespace std;

int board[1002][1002];
int dist[1002][1002];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m;

int bfs(int &is_jump)
{
    queue<tuple<int, int, int>> Q;

    Q.push(make_tuple(0, 0, 0));
    dist[0][0] = 1;

    while (!Q.empty())
    {
        int x, y, z;
        tie(x, y, z) = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (dist[nx][ny] >= 0)
                continue;
            if (board[nx][ny] && is_jump == 0)
            { 
                int nx2 = x + dx[dir] * 2;
                int ny2 = y + dy[dir] * 2;

                if (board[nx2][ny2] || dist[nx2][ny2] >= 0)
                    continue;
                else
                {
                    // 마지막 벽을 부숴야만 이동할 수 있는 경우는
                    // 점프로는 해결이 안됨
                    // 
                    is_jump = 1;
                    nx = nx2;
                    ny = ny2;
                    dist[nx2][ny2] += 1;
                    // 여기까지
                }
            }
            if (board[nx][ny])
                continue;

            Q.push(make_tuple(nx, ny, is_jump));
            dist[nx][ny] = dist[x][y] + 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            ans = max(dist[i][j], ans);
    }

    if (dist[m - 1][n - 1] < 0)
        return -1;
    else
        return ans + 1;
}

int main(void)
{
    cin >> n >> m;
    string str;
    /* board 초기화 */
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < m; j++)
            board[i][j] = str[j] - '0';
    }

    /* dist 초기화 */
    for (int i = 0; i < n; i++)
        fill(dist[i], dist[i] + m, -1);

    /* bfs */
    int max = -1, is_jump = 1;
    while (is_jump != 0)
    {
        is_jump = 0;
        max = bfs(is_jump);
    }
    cout << max;
}

// for (int i = 0; i < n; i++)
// {
//     for (int j = 0; j < m; j++)
//     {
//         cout << dist[i][j] << ' ';
//     }
//     cout << '\n';
// }