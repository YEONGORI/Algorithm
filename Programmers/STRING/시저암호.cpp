#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (auto c: s) {
        if (c >= 'A' && c <= 'Z') {
            int tmp = (int)c + n;
            if (tmp > 90)
                c = (tmp - 91) + 'A';
            else
                c += n;
        }
        else if (c >= 'a' && c <= 'z') {
            int tmp = (int)c + n;
            if (tmp > 122)
                c = (tmp - 123) + 'a';
            else
                c += n;
        }
        answer += c;
    }
    return answer;
}
