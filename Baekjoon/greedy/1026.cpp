// 보물
#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int A[n + 1];
    int B[n + 1];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];

    sort(A, A + n);
    sort(B, B + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += A[i] * B[n - 1 - i];
    cout << ans;
}