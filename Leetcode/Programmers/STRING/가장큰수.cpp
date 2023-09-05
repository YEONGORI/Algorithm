#include <vector>
#include <string>
#include <algorithm>
using namespace std;
 
bool cmp(string a, string b) {
    return a + b > b + a;
}
 
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str;
    for (auto num : numbers)
        str.push_back(to_string(num));

    sort(str.begin(), str.end(), cmp);
    
    if (str.at(0) == "0")
        return "0";
    for (auto num : str)
        answer += num;
    return answer;
}