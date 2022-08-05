// 배열 합치기
#include <iostream>

using namespace std;

int n, m;
int narr[1000001];
int marr[1000001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int arr[n + m + 1];

    for (int i=0; i<n; i++) cin >> narr[i];
    for (int i=0; i<m; i++) cin >> marr[i];

    int i = 0, j = 0, k = 0;
    while (k != n+m) {
        if (i == n)
            arr[k++] = marr[j++];
        else if (j == m)
            arr[k++] = narr[i++];
        else if (narr[i] < marr[j])
            arr[k++] = narr[i++];
        else if (narr[i] > marr[j])
            arr[k++] = marr[j++];
        else if (narr[i] == marr[j]) {
            arr[k++] = narr[i++];
            arr[k++] = marr[j++];
        }
    }
    for (int a=0; a<k; a++)
        cout << arr[a] << ' ';
    return (0);
}