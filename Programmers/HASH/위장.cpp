#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> M;

    for (auto &c: clothes) 
        ++M[c[1]];

    for (auto &m: M)
        answer *= (m.second + 1);

    return --answer;
}