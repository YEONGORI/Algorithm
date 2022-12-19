// 감시
#include <bits/stdc++.h>

using namespace std;

int room[10][10];
int vis[10][10];
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
int n, m, mini = 0;

void go_edge(int i, int j, int dir);
int ch_empty();

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int, int>> cctv;
    cin >> n >> m;

    /* 방, 벽, CCTV 위치 초기화 */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> room[i][j];
            if (room[i][j] != 0 && room[i][j] != 6)
                cctv.push_back({i, j});
            if (room[i][j] == 0)
                mini++;
        }
    }
    
    for (int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++)
    {
        copy(&room[0][0], &room[0][0] + 100, &vis[0][0]);
        int brute = tmp;
        for (int i = 0; i < (int)cctv.size(); i++)
        {
            int dir = brute % 4;
            brute /= 4;
            int x, y;
            tie(x, y) = cctv[i];
            if (room[x][y] == 1)
                go_edge(x, y, dir);
            else if (room[x][y] == 2)
            {
                go_edge(x, y, dir);
                go_edge(x, y, dir + 2);
            }
            else if (room[x][y] == 3)
            {
                go_edge(x, y, dir);
                go_edge(x, y, dir + 1);
            }
            else if (room[x][y] == 4)
            {
                go_edge(x, y, dir);
                go_edge(x, y, dir + 1);
                go_edge(x, y, dir + 2);
            }
            else
            {
                go_edge(x, y, dir);
                go_edge(x, y, dir + 1);
                go_edge(x, y, dir + 2);
                go_edge(x, y, dir + 3);
            }
        }
        int m = ch_empty();
        mini = min(mini, m);
    }

    cout << mini;
}

// dir(direction)변수는 방위(0:동, 1:서, 2:남, 3:북)을 가리킴
void go_edge(int i, int j, int dir)
{
    dir %= 4;
    for (int k = 1; true; k++)
    {
        int nx = k * dx[dir] + i;
        int ny = k * dy[dir] + j;

        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            return;
        if (room[nx][ny] == 6)
            return;
        if (vis[nx][ny] == 0)
            vis[nx][ny] = 7;
    }
}

int ch_empty()
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (vis[i][j] == 0)
                ans++;
    }

    return ans;
}