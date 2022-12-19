// 구간 합 구하기 4
#include <iostream>

using namespace std;

int n, m, i, j, tmp;
long long num[100002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    num[0] = 0;
    for (int i=1; i<=n; i++) {
        cin >> tmp;
        num[i] += (num[i-1] + tmp);
    }
    for (int k=1; k<=m; k++) {
        cin >> i >> j;
        cout << num[j] - num[i-1] << '\n';
    }

    return (0);
}