// 평범한 배낭
#include <iostream>
#include <algorithm>

using namespace std;

int n, k, maxi;
pair<int, int> bag[102];
int mxv[100002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> bag[i].first >> bag[i].second;
        if (bag[i].first > maxi)
            maxi = bag[i].first;
    }
    sort(bag, bag + n);
    // D[i] 최대 무게가 i일때 가방 가치의 최대값
    /*
    D[0]
    무게 가치
    3    6
    4    8
    5    12
    6    2

    가치 무게
    2    6
    6    3
    8    4
    12   5


    D[1] = D[0]
    D[2] = D[1]
    D[3] = 6
    D[4] = 8
    D[5] = 12
    D[6] = 12
    D[7] = D[3] + D[4]  == 14
    D[8] = D[3] + D[5]  == 18
    D[9] = D[3] + D[6]  == 19
    D[10] = D[4] + D[6] == 21
    D[11] = D[5] + D[6] == 25
    D[12] =
    */
    mxv[0] = 0;
    int idx = 0;
    for (int i = 1; i < maxi; i++)
    {
        mxv[i] = mxv[i - 1];
        if (bag[idx].first == i && bag[idx].second > mxv[i])
        {
            idx = bag[idx].first;
            mxv[i] = bag[i].second;
        }
    }
}