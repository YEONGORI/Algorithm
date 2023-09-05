#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer, V;
    map<string, string> M;
    string tmp;

    for (auto r: record) {
        istringstream ss(r);
        while (getline(ss, tmp, ' '))
            V.push_back(tmp);

        if (V[0] == "Leave")
            answer.push_back(V[0] + " " + V[1]);
        else if (V[0] == "Change")
            M[V[1]] = V[2];
        else {
            M[V[1]] = V[2];
            answer.push_back(V[0] + " " + V[1]);
        }
        V.clear();
    }
    
    for (auto &a: answer) {
        if (a[0] == 'E')
            a = M[a.substr(6, a.length())] + "님이 들어왔습니다.";
        else if (a[0] == 'L')
            a = M[a.substr(6, a.length())] + "님이 나갔습니다.";
    }
    return answer;
}