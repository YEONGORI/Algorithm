// 스타트링크
#include <algorithm>
#include <queue>
#include <iostream>
#include <string.h>

using namespace std;
int F, S, G, U, D;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> F >> S >> G >> U >> D;
	int dx[2] = {U, D * -1};
	int dist[F + 1];
	memset(dist, -1, sizeof(dist));

	queue<int> QU;
	QU.push(S);
	dist[S] = 0;

	while (!QU.empty()) {
		int pos = QU.front();
		QU.pop();
		for (int i = 0; i < 2; i++) {
			int nx = pos + dx[i];
			if (nx <= 0 || nx > F)
				continue;
			if (dist[nx] >= 0)
				continue;
			dist[nx] = dist[pos] + 1;
			QU.push(nx);
		}
	}
	if (dist[G] == -1)
		cout << "use the stairs";
	else
		cout << dist[G];
	return (0);
}