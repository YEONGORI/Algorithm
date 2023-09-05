#include <string>
#include <vector>
#include <cmath>

using namespace std;

int result;
bool vis[8];

void adventure(int pick, int remains, vector<vector<int>> &dungeons) {
    for (int i=0; i<dungeons.size(); i++) {
        if (vis[i] || dungeons[i][0] > remains)
            continue;
        vis[i] = 1;
        adventure(pick + 1, remains - dungeons[i][1], dungeons);
        vis[i] = 0;
    }
    result = max(result, pick);
}

int solution(int k, vector<vector<int>> dungeons) {
    adventure(0, k, dungeons);
    return result;
}