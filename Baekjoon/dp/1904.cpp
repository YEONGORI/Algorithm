// 01타일
#include <iostream>

using namespace std;

int n, res;
int cnt[1000001];

int main(void) {
	cin >> n;
	cnt[1] = 1;
	cnt[2] = 2;
	cnt[3] = 3;
	for (int i=4; i<=n; i++)
		cnt[i] = (cnt[i-1] + cnt[i-2]) % 15746;
	cout << cnt[n]  << '\n';
}