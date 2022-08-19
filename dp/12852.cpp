// 1로 만들기 2
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int D[1000002];
int P[1000002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    D[1] = 0;
    for (int i=2; i<=n; i++) {
        D[i] = D[i-1] + 1;
        P[i] = i-1;
        if (i%3==0 && min(D[i/3] + 1, D[i]) == D[i/3] + 1) {
            D[i] = D[i/3] + 1;
            P[i] = i/3;
        }
        if (i%2==0 && min(D[i/2] + 1, D[i]) == D[i/2] + 1) {
            D[i] = D[i/2] + 1;
            P[i] = i/2;
        }
    }
    cout << D[n] << '\n';
    int cur = n;
    while (true) {
        cout << cur << ' ';
        if (cur == 1) break;
        cur = P[cur];
    }
    return (0);
}