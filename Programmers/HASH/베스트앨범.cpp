#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> M;

bool cmp(pair<string,int> a, pair<string,int> b){
    return a.second > b.second;    
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int len = genres.size();

    for (int i=0; i<len; i++)
        M[genres[i]] += plays[i];
    
    vector<pair<string,int>> V(M.begin(), M.end()); 
    sort(V.begin(), V.end(), cmp);
    
    for (int i=0; i<V.size(); i++) {
        int max1 = 0, max2 = 0, i1 = -1, i2 = -1;
        for (int j=0; j<len; j++) {
            if (genres[j] == V[i].first) {
                if (plays[j] > max1) {
                    max2 = max1;
                    i2 = i1;
                    max1 = plays[j];
                    i1 = j;
                }
                else if (plays[j] > max2) {
                    max2 = plays[j];
                    i2 = j;
                }
            }
        }
        answer.push_back(i1);
        if (i2 != -1)
            answer.push_back(i2);
    }
    return answer;
}