#include <iostream>
#include <algorithm>

using namespace std;

int price[7];
int weight[7];
int profit[7][7];
int n, W;

void knapsack(void)
{ // Bottom up dynamic programming algorith을 사용해 item이 n개, 배낭의 최대 무게가 W일 때 최대 이익을 알 수 있다.
    for (int i = 1; i <= n; i++)
    { // item을 i번째 까지 집을 수 있다.
        for (int j = 1; j <= W; j++)
        {                       // 가방 무게가 최대 j다.
            if (weight[i] <= j) // 새로운 item을 집을 수 있을 때
                profit[i][j] = max(price[i] + profit[i - 1][j - weight[i]], profit[i - 1][j]);
            else // 현재 최대 무게로는 새로운 item을 집을 수 없을 때
                profit[i][j] = profit[i - 1][j];
        }
    }
}

void init(void)
{ // 알고리즘에 필요한 item 개수와, 각 item의 가격, 무게 그리고 배낭 무게 한계를 설정한다.
    cout << "insert maximum item: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "insert [" << i << "] item's price (space) weight: ";
        cin >> price[i] >> weight[i];
    }
    cout << "insert maximum weigth: ";
    cin >> W;
    cout << '\n';
}

int main(void)
{
    init();
    knapsack();
    cout << "maximum profit: " << profit[n][W] << '\n';
}