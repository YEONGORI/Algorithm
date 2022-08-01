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
int res[8];
int result;

int ch_adj(void) {
	int idx = 1;
	queue<pair<int, int> > Q;
	int vis[7][7] = {};
	int v_room[7][7] = {};

	for (int i = 0; i < 25; i++) {
		if (i == res[idx]) {
			if (idx == 1) {
				vis[i/5][i%5] = 1;
				Q.push(make_pair(i*5, i%5));
			}
			v_room[i/5][i%5] = 1;
			idx++;
		}
		else
			v_room[i/5][i%5] = 0;
		// for (int j = 0; j < 5; j++) {
		// 	if ((i * 5 + j) == res[idx]) {
		// 		if (idx == 1) {
		// 			vis[i][j] = 1;
		// 			Q.push(make_pair(i, j));
		// 		}
		// 		v_room[i][j] = 1;
		// 		idx++;
		// 	}
		// 	else {
		// 		v_room[i][j] = 0;
		// 	}
		// }
	}

	int cnt = 1;
	while (!Q.empty()) {
		int cur_x = Q.front().first;
		int cur_y = Q.front().second;
		Q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = cur_x + dx[d];
			int ny = cur_y + dy[d];
			if (nx < 0 || nx > 4 || ny < 0 || ny > 4)	continue;
			if (v_room[nx][ny] == 0 || vis[nx][ny])	continue;
			vis[nx][ny] = 1;
			Q.push(make_pair(nx, ny));
			cnt++;
		}
	}
	return (cnt);
}

int ch_dasom(void) {
	int cnt = 0;	

	for (int i = 1; i <= 7; i++)
		cnt += room[res[i] / 5][res[i] % 5].second;
	if (cnt >= 4)
		return (ch_adj());
	return (0);
}

void func(int k) {
	if (k == 8) {
		if (ch_dasom() == 7)
			result++;
		return ;
	}
	for (int i = 0; i < 25; i++) {
		if (room[i/5][i%5].X > res[k - 1]) {
			res[k] = room[i/5][i%5].X;
			func(k + 1);
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
	func(1);
	cout << result;
}

/*
YYYYY
SYSYS
YYYYY
YSYYS
YYYYY

00000
10101 5 7 9
00000
01010 16 18
00000
*/
