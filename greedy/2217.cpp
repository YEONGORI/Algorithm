// 로프
#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int rp[n + 1];
    for (int i = 0; i < n; i++)
        cin >> rp[i];
    sort(rp, rp + n);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, rp[n - i] * i);
    cout << ans;
}