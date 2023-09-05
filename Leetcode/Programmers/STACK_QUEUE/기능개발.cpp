#include <string>
#include <vector>
#include <list>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    list<pair<int, int>> L;
    
    for (int i=0; i<progresses.size(); i++) 
        L.push_back({progresses[i], speeds[i]});

    while (!L.empty()) { 
        for (list<pair<int, int>>::iterator iter = L.begin(); iter!= L.end(); iter++) {
            if (iter->first < 100)
                iter->first += iter->second;
            if (iter->first >= 100)
                iter->second = 0;
        }    
        
        int cnt = 0;
        while (!L.empty() && L.front().second == 0) {
            L.pop_front();
            cnt++;
        }
        if (cnt != 0)
            answer.push_back(cnt);
    }
    return answer;
}