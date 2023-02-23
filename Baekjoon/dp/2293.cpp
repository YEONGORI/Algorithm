// 동전
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, k;
int coin[102];
int dp[10002]; // 동전들 가치의 합이 x가 되게 하는 경우의 수

int main(void) {
	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> coin[i];
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++)
			dp[j] += dp[j - coin[i]];
	}
	cout << dp[k];
}