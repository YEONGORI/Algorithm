// 숫자 카드 2
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[500001];

int lower_idx(int t)
{
    int st = 0, en = n;
    while (st < en)
    {
        int mid = (st + en) / 2;
        if (a[mid] >= t)
            en = mid;
        else if (a[mid] < t)
            st = mid + 1;
    }
    return st;
}

int higher_idx(int t)
{
    int st = 0, en = n;
    while (st < en)
    {
        int mid = (st + en) / 2;
        if (a[mid] > t)
            en = mid;
        else if (a[mid] <= t)
            st = mid + 1;
    }
    return st;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        cout << higher_idx(t) - lower_idx(t) << '\n';
    }
    return 0;
}

// int main(void)
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> n;
//     for (int i = 0; i < n; i++)
//         cin >> a[i];
//     sort(a, a + n);
//     cin >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int t;
//         cin >> t;
//         cout << upper_bound(a, a + n, t) - lower_bound(a, a + n, t) << '\n';
//     }
//     return 0;
// }