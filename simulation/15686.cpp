// 치킨 배달
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

pair<int, int> town[52][52];
vector<int> V;

int c_town[52][52];
int chicken[15];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int n, m;

int bfs(int i, int j, int board[52][52]) {
    queue<pair<int, int> > Q;
    int dist[52][52];
    for (int q = 0; q < 52 ; q++) {
        for (int w = 0; w < 52; w++)
            dist[q][w] = -1;
    }
    int res = 100;
    Q.push(make_pair(i, j));
    dist[i][j] = 0;
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int d=0; d<4; d++) {
            int nx = x +dx[d];
            int ny = y +dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (dist[nx][ny] >= 0 || board[nx][ny] == 1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            Q.push(make_pair(nx, ny));
            if (board[nx][ny] == 2 && board[nx][ny] < res) 
                res = board[nx][ny];
        }
    }
    cout << "res: " << res << '\n';
    return (res);
}

int get_distance(void) {
    int n_town[52][52] = {};
    int v_town[52][52] = {};
    int total = 0;

    copy(&c_town[0][0], &c_town[0][0] + 52 * 52, &n_town[0][0]);
    for (int i=1; i<=m; i++)
        n_town[chicken[i]/5][chicken[i]%5] = 2;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (town[i][j].second == 1) {
                copy(&n_town[0][0], &n_town[0][0] + 52 * 52, &v_town[0][0]);
                total = bfs(i, j, v_town);
            }
        }
    }
    return (total);
}

void pick_chicken(int k) {
    if (k == m + 1) {
        V.push_back(get_distance());
        return ;
    }
    for (int i=0; i<n*n; i++) {
        if (i > chicken[k - 1] && town[i/5][i%5].second == 2) {
            chicken[k] = town[i/5][i%5].first;
            pick_chicken(k + 1);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n; j++) {
            cin >> town[i][j].second;
            if (town[i][j].second == 1)
                c_town[i][j] = 1;
            town[i][j].first = i*5 + j;
        }
    }
    memset(chicken, -1, 15);
    pick_chicken(1);
}

    // for (int i = 0; i < n ; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << v_town[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }