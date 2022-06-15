// 곱셈
#include <bits/stdc++.h>

using namespace std;

int recur(long long a, long long b, long long c)
{
    if (b == 1)
        return a % c;
    long long tmp = recur(a, b / 2, c);
    tmp = tmp * tmp % c;
    if (b % 2 == 0)
        return tmp;
    return tmp * a * c;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a, b, c;
    cin >> a >> b >> c;

    cout << recur(a, b, c);
}