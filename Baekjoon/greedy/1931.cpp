// 회의실 배정
#include <iostream>
#include <algorithm>

using namespace std;

int n, ans;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    pair<int, int> mt[n + 1];
    for (int i = 0; i < n; i++)
        cin >> mt[i].second >> mt[i].first;
    sort(mt, mt + n);
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        if (t > mt[i].second)
            continue;
        ans++;
        t = mt[i].first;
    }
    cout << ans << '\n';
    // for (int i = 0; i < n; i++)
    //     cout << mt[i].first << ' ' << mt[i].second << '\n';
    return (0);
}