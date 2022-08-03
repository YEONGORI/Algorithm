// 치킨 배달
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

pair<int, int> town[60][60];
vector<int> V;

int c_town[60][60];
int chicken[20];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n, m;

int check(int nx, int ny)
{
    for (int i = 1; i <= m; i++)
    {
        if (nx * 5 + ny == chicken[i])
            return (1);
    }
    return (0);
}

int bfs(int i, int j)
{
    queue<pair<int, int>> Q;
    int dist[60][60];
    int res = 1000;

    for (int q = 0; q < n; q++)
        for (int w = 0; w < n; w++)
            dist[q][w] = -1;

    Q.push({i, j});
    dist[i][j] = 0;
    while (!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (dist[nx][ny] >= 0)
                continue;
            dist[nx][ny] = dist[x][y] + 1;
            Q.push({nx, ny});
            if (town[nx][ny].second == 2 && dist[nx][ny] < res && check(nx, ny))
                res = dist[nx][ny];
        }
    }
    return (res);
}

int get_distance(void)
{
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (town[i][j].second == 1)
                total += bfs(i, j);
        }
    }
    return (total);
}

void pick_chicken(int k)
{
    if (k == m + 1)
    {
        V.push_back(get_distance());
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (town[i][j].first > chicken[k - 1] && town[i][j].second == 2)
            {
                chicken[k] = town[i][j].first;
                pick_chicken(k + 1);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> town[i][j].second;
            town[i][j].first = i * 5 + j;
        }
    }
    memset(chicken, -1, sizeof(chicken));
    pick_chicken(1);

    V.push_back(10000);
    cout << *min_element(V.begin(), V.end());

    return (0);
}

/*

5 1
1 2 0 2 1
1 2 0 2 1
1 2 0 2 1
1 2 0 2 1
1 2 0 2 1
*/