#include <vector>
#include <queue>

using namespace std;

int dist[110][110] = {0};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

int solution(vector<vector<int>> maps)
{
    queue<pair<int, int>> Q;

    n = maps[0].size();
    m = maps.size();

    Q.push({0, 0});
    dist[0][0] = 1;
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            if (x < 0 || y < 0 || x >= m || y >= n)
                continue;
            if (dist[x][y] > 0 || maps[x][y] == 0)
                continue;
            Q.push({x, y});
            dist[x][y] = dist[cur.first][cur.second] + 1;
        }
    }
    if (dist[m - 1][n - 1] == 0)
        return (-1);
    return dist[m - 1][n - 1];
}
