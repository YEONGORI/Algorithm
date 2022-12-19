#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        list<char> pw;
        string str;

        cin >> str;
        auto cur = pw.begin();
        for (auto c : str)
        {
            if (c == '<' && cur != pw.begin())
                cur--;
            else if (c == '>' && cur != pw.end())
                cur++;
            else if (c == '-' && cur != pw.begin())
                cur = pw.erase(--cur);
            else
                pw.insert(cur, c);
        }
        for (auto c : pw)
            cout << c;
        cout << '\n';
    }
}