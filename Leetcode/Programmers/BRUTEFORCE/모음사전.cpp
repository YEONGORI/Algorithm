#include <string>
#include <map>

using namespace std;
int order = 1;
map<string, int> M;
char board[5] = {'A', 'E', 'I', 'O', 'U'};

void dfs(string cur) {
    if (cur.length() == 5)
        return;
    for (int i=0; i<5; i++) {
        string s(1, board[i]);
        string word = (cur + s);
        M[word] = order++;
        dfs(word);
    }
}

int solution(string word) {
    dfs("");
    int answer = M[word];
    return answer;
}