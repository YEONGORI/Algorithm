#include <string>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

int solution(int n, vector<vector<int>> costs)
{
    int answer, cur, dist;
    int graph[101][101] = {};
    vector<int> MST(n, 2147483647);
    priority_queue<pair<int, int>> PQ;
    PQ.push({0, 0});

    for (int i = 0; i < costs.size(); i++)
    {
        graph[costs[i][0]][costs[i][1]] = costs[i][2];
        graph[costs[i][1]][costs[i][0]] = costs[i][2];
    }

    while (!PQ.empty())
    {
        dist = -PQ.top().first;
        cur = PQ.top().second;
        PQ.pop();
        if (MST[cur] <= dist)
            continue;
        MST[cur] = dist;
        for (int next = 0; next < n; next++)
            if (graph[cur][next] && MST[next] == 2147483647)
                PQ.push({-graph[cur][next], next});
    }
    answer = accumulate(MST.begin(), MST.end(), 0);
    return answer;
}