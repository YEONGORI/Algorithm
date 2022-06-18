// Z
#include <bits/stdc++.h>

using namespace std;

int func(int n, int row, int col)
{
    if (n == 0)
        return 0;
    int half = 1 << (n - 1);
    if (row < half && col < half)
        return func(n - 1, row, col);
    if (row < half && col >= half)
        return half * half + func(n - 1, row, col - half);
    if (row >= half && col < half)
        return 2 * half * half + func(n - 1, row - half, col);
    return 3 * half * half + func(n - 1, row - half, col - half);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, r, c;
    cin >> N >> r >> c;

    cout << func(N, r, c);
}