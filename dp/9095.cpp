// 1,2,3 더하기
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int n, tmp;
int d[1000005];

void dp(int k) {
    memset(d, 0, sizeof(d));
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for (int i=4; i<=k; i++) {
        d[i] = d[i-3] + d[i-2] + d[i-1];
    }
    cout << d[k] << '\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> tmp;
        dp(tmp);
    }
    return (0);
}