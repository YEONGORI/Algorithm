#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int, int>> DQ;
    for (int i=0; i<priorities.size(); i++) 
        DQ.push_back({priorities[i], i});

    while (!DQ.empty()) {
        int j1 = DQ.front().first;
        int j2 = DQ.front().second; 
        int cnt = 0;
        for (auto doc: DQ) {
            if (doc.first > j1) {
                DQ.push_back({j1, j2});
                DQ.pop_front();
                break;
            }
            cnt++;
        }
        if (cnt == DQ.size()) {
            answer++;
            if (DQ.front().second == location) break;
            DQ.pop_front();
        }
    }
    return answer;
}