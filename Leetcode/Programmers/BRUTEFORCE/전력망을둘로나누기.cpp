#include <string>
#include <vector>
#include <queue>

using namespace std;
int wire_cnt;
bool board[101][101];

int bfs(int st, int block) {
    int cnt = 1;
    bool vis[101] = {};
    queue<int> Q;
    Q.push(st);
    vis[st] = 1;
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (int i=1; i<=wire_cnt; i++) {
            if (!board[cur][i] || vis[i] || i == block)
                continue;
            Q.push(i);
            vis[i] = 1;
            cnt++;
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 999999;
    wire_cnt = n;
    for (auto w: wires) {
        board[w[0]][w[1]] = 1;
        board[w[1]][w[0]] = 1;
    }
    
    for (auto w: wires) {
        int diff = bfs(w[0], w[1]) - bfs(w[1], w[0]);
        if (diff < 0)
            diff *= -1;
        answer = min(answer, diff);
    }
    return answer;
}