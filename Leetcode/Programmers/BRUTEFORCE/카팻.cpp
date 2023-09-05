#include <string>
#include <vector>

using namespace std;
int width;
int height;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    width = brown / 2 + 1;
    height = 1;
    
    while (--width >= ++height) {
        if ((width - 2) * (height - 2) == yellow)
            break;
    }
    answer.push_back(width);
    answer.push_back(height);    
    return answer;
}