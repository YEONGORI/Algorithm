// 계단 오르기
#include <iostream>
#include <algorithm>

using namespace std;

int n, tmp, cnt;
int d[333][3];
int s[333];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++) cin >> s[i];
    d[1][1] = s[1];
    d[1][2] = 0;
    d[2][1] = s[2];
    d[2][2] = s[1] + s[2];

    for (int i=3; i<=n; i++) {
        d[i][1] = max(d[i-2][1], d[i-2][2])+s[i];
        d[i][2] = d[i-1][1]+s[i];
    }
    cout << max(d[n][1], d[n][2]);
    return (0);
}