#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0, size = triangle.size();
    int dist[501][501] = {};
    
    dist[0][0] = triangle[0][0];
    
    for (int i=1; i<size; i++) {
        for (int j=0; j<triangle[i].size(); j++) {
            if (j == 0)
                dist[i][j] = dist[i-1][j] + triangle[i][j];
            else if (j == i)
                dist[i][j] = dist[i-1][j-1] + triangle[i][j];
            else
                dist[i][j] = max(dist[i-1][j-1], dist[i-1][j]) + triangle[i][j];
        }
    }
    for (int i=0; i<size; i++)
        answer = max(answer, dist[size-1][i]);
    return answer;
}