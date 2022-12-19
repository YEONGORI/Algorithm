// 큐
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    int n;
    cin >> n;
    queue<int> Q;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str == "push")
        {
            int k;
            cin >> k;
            Q.push(k);
        }
        else if (str == "pop")
        {
            if (Q.empty())
                cout << "-1\n";
            else
            {
                cout << Q.front() << '\n';
                Q.pop();
            }
        }
        else if (str == "size")
        {
            cout << Q.size() << '\n';
        }
        else if (str == "empty")
        {
            if (Q.empty())
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if (str == "front")
        {
            if (Q.empty())
                cout << "-1\n";
            else
                cout << Q.front() << '\n';
        }
        else
        {
            if (Q.empty())
                cout << "-1\n";
            else
                cout << Q.back() << '\n';
        }
    }

    return 0;
}