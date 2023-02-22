#include <string>
#include <vector>

using namespace std;

int vis[200];

void dfs(int cur, int n, vector<vector<int>> computers) {
    vis[cur] = 1;
    for (int i=0; i<n; i++) {
        if (!vis[i] && computers[cur][i] == 1)
            dfs(i, n, computers);
    }

}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i=0; i<n; i++) {
        if (vis[i] == 0) {
            dfs(i, n, computers);
            answer++;
        }
    }
    return answer;
}