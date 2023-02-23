// DFS와 BFS
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
bool board[1002][1002];
int a, b;
int n, m, v;

vector<int> B;
vector<int> D;

void bfs() {
	queue<int> Q;
	bool vis[1002] = {};
	Q.push(v);
	B.push_back(v);
	vis[v] = 1;
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (int i=1; i<=n; i++) {
			if (board[cur][i] && !vis[i]) {
				Q.push(i);
				B.push_back(i);
				vis[i] = 1;
			}
		}
	}	
}

void dfs(int cur, bool *vis) {
	D.push_back(cur);
	vis[cur] = 1;
	for (int i=1; i<=n; i++) {
		if (board[cur][i] && !vis[i]) {
			vis[i] = 1;
			dfs(i, vis);
		}
	}
}

int main(void) {
	cin >> n >> m >> v;
	for (int i=0; i<m; i++) {
		cin >> a >> b;
		board[a][b] = 1;
		board[b][a] = 1;		
	}
	bfs();
	bool vis[1002] = {};
	dfs(v, vis);
	for (int i=0; i<D.size(); i++)
		cout << D[i] << ' ';
	cout << '\n';
	for (int i=0; i<B.size(); i++)
		cout << B[i] << ' ';
}