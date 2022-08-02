// 소문난 칠공주
#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

#define X first
#define Y second

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

pair<int, int> room[7][7];
int v_room[7][7];
int res[8];
int result;

int ch_adj(void) {
	int idx = 1;
	queue<pair<int, int> > Q;
	int vis[7][7] = {};

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if ((i * 5 + j) != res[idx])
				v_room[i][j] = 0;
			else {
				if (idx == 1)
					Q.push(make_pair(i, j));
				v_room[i][j] = 1;
				idx++;
			}
		}
	}

	int cnt = 0;
	while (!Q.empty()) {
		int cur_x = Q.front().first;
		int cur_y = Q.front().second;
		Q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = cur_x + dx[d];
			int ny = cur_y + dy[d];
			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)	continue;
			if (v_room[nx][ny] == 0 || vis[nx][ny])	continue;
			vis[nx][ny] = 1;
			cnt++;
			Q.push(make_pair(nx, ny));
		}
	}
	return (cnt);
}

int ch_dasom(void) {
	int cnt = 0;	

	for (int i = 1; i <= 7; i++)
		cnt += room[res[i] / 5][res[i] % 5].second;
	if (cnt < 4)
		return (0);
	return (ch_adj());
}

void func(int k) {
	if (k == 8) {
		int n = ch_dasom();
		if (n == 7)
			result++;
		return ;
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (room[i][j].X > res[k - 1]) {
				res[k] = room[i][j].X;
				func(k + 1);
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string sit;
	int idx = 0;
	for (int i = 0; i < 5; i++) {
		cin >> sit;
		for (int j = 0; j < 5; j++)
		{
			if (sit[j] == 'S')
				room[i][j].Y = 1;
			room[i][j].X = idx++;
		}
	}
	memset(res, -1, 8);
	func(1);
	cout << result;
}
