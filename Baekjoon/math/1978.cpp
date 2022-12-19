// 소수 찾기
#include <iostream>

using namespace std;

int n, cnt, number;

int func(int n) {
	for (int i=2;i*i<=n;i++) {
		if (number % i == 0) return (0);
	}
	return (1);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0;i<n;i++) {
		cin >> number;
		if (number == 1) continue;
		cnt += func(number);
	}
	cout << cnt << '\n';
	return (0);
}