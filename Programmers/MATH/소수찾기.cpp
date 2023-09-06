#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
int len, pNumCnt;
int aNumbers[10];
bool pick[10];
set<int> S;

bool isPrime(int number) {
    if (number == 2) return true;
    if (number < 2 || number % 2 == 0) return false;

    int sn = (int)sqrt(number);
    for (int i=2; i<=sn; i++) {
        if (number % i == 0) return false;
    }
    return true;
}

void attachNum(int depth, int number) {
    if (depth == len + 1)
        return;
    if (isPrime(number / 10))
        S.insert(number);
    for (int i=0; i<len; i++) {
        if (pick[i]) continue;
        pick[i] = true;
        attachNum(depth + 1, (number + aNumbers[i]) * 10);
        pick[i] = false;
    }
}

int solution(string numbers) {
    for (auto c: numbers)
        aNumbers[len++] = c - '0';
    attachNum(0, 0);

    int answer = S.size();
    return answer;
}