// 카드
#include <iostream>

using namespace std;

int n;
long long num[100001];

/* start sort */
long long tmp[100001];
void ms_process(int st, int en) {
    int mid = (st + en) / 2;

    int idx = st, i = st, j = mid;
    while(idx < en) {
        if (i == mid)
            tmp[idx++] = num[j++];
        else if (j == en)
            tmp[idx++] = num[i++];
        else if (num[i] < num[j])
            tmp[idx++] = num[i++];
        else
            tmp[idx++] = num[j++];
    }
    for (int ii=st; ii<en; ii++) num[ii] = tmp[ii];
}
void merge_sort(int st, int en) {
    if (en - st <= 1) return;
    int mid = (st + en) / 2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    ms_process(st, en);
}
/* end sort */

int cnt = 0;                        // 현재 보고 있는 수가 몇 번 등장했는지
long long mxval = -(4.611686e+18);      // 현재까지 가장 많이 등장한 수의 값
int mxcnt = 0;                          // 현재까지 가장 많이 등장한 수의 등장 횟수

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++)
        cin >> num[i];
    merge_sort(0, n);
    for (int i=0;i<n;i++) {
        if (i == 0 || num[i-1]==num[i])
            cnt++;
        else {
            if (mxcnt < cnt) {
                mxcnt = cnt;
                mxval = num[i-1];
            }
            cnt=1;
        }
    }
    if (mxcnt < cnt) mxval = num[n-1];
    cout << mxval;
    return (0);
}