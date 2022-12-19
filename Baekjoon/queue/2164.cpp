// 카드 2
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    queue<int> Q;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        Q.push(i);
    while (Q.size() != 1)
    {
        Q.pop();
        Q.push(Q.front());
        if (Q.size() != 1)
            Q.pop();
    }

    cout << Q.front() << '\n';
    return 0;
}