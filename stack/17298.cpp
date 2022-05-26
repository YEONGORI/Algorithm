// 오큰수
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    stack<int> s1, s2;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s1.push(x);
    }

    for (int i = 0; i < n; i++)
    {
        while (!s2.empty() && s2.top() <= s1.top())
            s2.pop();
        if (s2.empty())
            cout << -1 << ' ';
        else
            cout << s2.top() << ' ';

        s2.push(s1.top());
        s1.pop();
    }

    // cout << -1 << '\n';
    return 0;
}