// AC
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string funcs, str;
    deque<int> DQ;
    int t, n, R;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        R = 0;
        cin >> funcs >> n >> str;
        for (auto j : str)
            if (j >= '0' && j <= '9')
                DQ.push_back(j);
        for (auto j : funcs)
        {
            if (j == 'R')
                R += 1;
            else
            {
                if (DQ.empty())
                {
                    cout << "error\n";
                    break;
                }
                else if (R / 2 == 0)
                    DQ.pop_front();
                else
                    DQ.pop_back();
            }
        }
    }
}