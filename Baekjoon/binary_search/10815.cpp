// 숫자 카드
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, tmp;
int arr[500001];

int bst()
{
    int st = 0, en = n;
    while (st < en)
    {
        int mid = (st + en) / 2;
        if (arr[mid] == tmp)
            return 1;
        else if (arr[mid] < tmp)
            st = mid + 1;
        else
            en = mid;
    }
    return 0;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    cin >> m;
    while (m--)
    {
        cin >> tmp;
        cout << bst() << ' ';
    }
    return 0;
}