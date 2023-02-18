#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<pair<int, int>> S;
    
    for (int i=0; i<numbers.size(); i++) {
        while (!S.empty()) {
            pair<int, int> top = S.top();
            
            if (top.first >= numbers[i])
                break;
            answer[top.second] = numbers[i];
            S.pop();
        }
        S.push({numbers[i], i});
    }
    return answer;
}