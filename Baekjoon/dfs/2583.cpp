// 영역 구하기
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define X first
#define Y second
int board[102][102];
int vis[102][102];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int m, n, k;

void fill_board(int x1, int y1, int x2, int y2) {
  for (int i = y2; i < y1; i++) {
    for (int j = x1; j < x2; j++) {
      board[i][j] = 1;
      vis[i][j] = 1;
    }
  }
}

int start_dfs(stack<pair<int, int>> S, int i, int j) {
  int cnt = 1;

  S.push({i, j});
  vis[i][j] = 1;
  while (!S.empty()) {
    pair<int, int> cur = S.top();
    S.pop();
    for (int d = 0; d < 4; d++) {
      int nx = cur.X + dx[d];
      int ny = cur.Y + dy[d];
      if (nx < 0 || nx >= m || ny < 0 || ny >= n)
        continue;
      if (vis[nx][ny] || board[nx][ny])
        continue;
      vis[nx][ny] = 1;
      S.push({nx, ny});
      cnt++;
    }
  }
  return (cnt);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x1, y1, x2, y2, cnt = 0;
  cin >> m >> n >> k;

  vector<int> V;
  stack<pair<int, int>> S;

  for (int i = 0; i < k; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    fill_board(x1, m - y1, x2, m - y2);
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (vis[i][j] || board[i][j])
        continue;
      V.push_back(start_dfs(S, i, j));
      cnt++;
    }
  }
  sort(V.begin(), V.end());
  cout << cnt << '\n';
  for (int a : V)
    cout << a << ' ';
  return (0);
}
