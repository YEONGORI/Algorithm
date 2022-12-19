// 수 찾기
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, tmp;
int A[100005];

int f_check(int target)
{
    int st = 0;
    int en = n - 1;
    while (st <= en)
    {
        int mid = (st + en) / 2;
        if (A[mid] < target)
            st = mid + 1;
        else if (A[mid] > target)
            en = mid - 1;
        else
            return 1;
    }
    return 0;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    sort(A, A + n);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        cout << f_check(tmp) << '\n';
    }
}

// int main(void)
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n;
//     for (int i = 0; i < n; i++)
//         cin >> A[i];
//     sort(A, A + n);
//     cin >> m;
//     while (m--)
//     {
//         int t;
//         cin >> t;
//         cout << binary_search(A, A + n, t) << '\n';
//     }
// }