// 배열 합치기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;
    int arr1[n];
    int arr2[m];

    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    vector<int> V;
    for (int i = 0; i < n; i++)
        V.push_back(arr1[i]);
    for (int i = 0; i < m; i++)
        V.push_back(arr2[i]);

    sort(V.begin(), V.end());

    for (int i : V)
    {
        cout << i << ' ';
    }
}