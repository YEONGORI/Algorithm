#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> num_time;
    map<string, int> num_fee;
    string time, number, status;
    int defTime = fees[0], defFee = fees[1], perTime = fees[2], perFee = fees[3], curTime;
    
    for (auto s: records) {
        time = s.substr(0, 2);
        curTime = stoi(time) * 60;
        time = s.substr(3, 2);
        curTime += stoi(time);
        number = s.substr(6, 4);
        status = s.substr(11, 4);
        if (status == "IN") {
            num_time.insert({number, curTime});
            num_fee.insert({number, 0});
        }
        else if (status == "OUT" && num_time.find(number) != num_time.end()){
            num_fee[number] += (curTime - num_time[number]);
            num_time.erase(number);
        }
    }

    for (auto m: num_time) { // 23:59 분에 출차
        num_fee[m.first] += (1439 - m.second);
    }

    for (auto m: num_fee) { // 주차요금 계산
        if (m.second - defTime < 0)
            answer.push_back(defFee);
        else {
            answer.push_back(defFee + (ceil((m.second - defTime) / (double)perTime) * perFee));
        }
    }
    
    return answer;
}