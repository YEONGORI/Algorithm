// 평범한 배낭
#include <iostream>
#include <algorithm>

using namespace std;

#define weight first
#define value second

int n, k;
pair<int, int> bag[102];
int DP[102][100002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k; // n: 가방 갯수, k: 최대 무게
    for (int i = 0; i < n; i++)
        cin >> bag[i].weight >> bag[i].value;
    sort(bag, bag + n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j - bag[i].weight >= 0)
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - bag[i].weight] + bag[i].value);
            else
                DP[i][j] = DP[i - 1][j];
        }
    }
    cout << DP[n][k];
}