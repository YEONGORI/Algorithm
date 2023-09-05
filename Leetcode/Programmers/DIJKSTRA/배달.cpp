#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> iPair;

int solution(int N, vector<vector<int>> road, int K)
{
    int answer = 0;
    int dist[N + 2];

    fill_n(dist, N + 2, 555555);
    sort(road.begin(), road.end());
    dist[1] = 0;

    priority_queue<iPair, vector<iPair>, greater<iPair>> PQ;
    PQ.push({1, 0});

    while (!PQ.empty())
    {
        int pos = PQ.top().first;
        int cost = PQ.top().second;
        PQ.pop();

        for (int i = 0; i < road.size(); i++)
        {
            if (road[i][0] == pos)
            {
                int nPos = road[i][1];
                int nCost = road[i][2];
                if (dist[nPos] > cost + nCost)
                {
                    dist[nPos] = cost + nCost;
                    PQ.push({nPos, dist[nPos]});
                }
            }
            else if (road[i][1] == pos)
            {
                int nPos = road[i][0];
                int nCost = road[i][2];
                if (dist[nPos] > cost + nCost)
                {
                    dist[nPos] = cost + nCost;
                    PQ.push({nPos, dist[nPos]});
                }
            }
        }
    }

    for (auto len : dist)
    {
        if (len <= K)
            answer++;
    }
    return answer;
}