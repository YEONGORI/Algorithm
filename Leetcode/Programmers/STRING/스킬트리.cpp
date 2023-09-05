#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (auto s_t: skill_trees) {
        int tmp = 0, flag = 0;
        for (auto s: skill) {
            if (tmp > s_t.find(s)) {
                flag = 1;
                break;
            }
            tmp = s_t.find(s);
        }
        if (flag == 0)
            answer++;
    }
    
    return answer;
}