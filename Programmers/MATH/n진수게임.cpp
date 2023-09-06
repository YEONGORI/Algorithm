#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "", arith = "0123456789ABCDEF", conv = "";
    int order = 0;

    for (int origin=0; answer.size() != t; origin++) {
        int temp = origin;
        conv = "";
        while (origin) {
            conv = arith[origin % n] + conv;
            origin = origin / n;
        }
        if (order == 0)
            conv = "0";
        for (int i=0; i<conv.size() && answer.size() != t; i++) {
            if (order++ % m == p - 1) {
                answer += conv[i];
            }
        }
        origin = temp;
    }
    return answer;
}