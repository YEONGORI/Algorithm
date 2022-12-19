// 범위 내에서의 소수 판정법
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// vector<int> primelist_1(int n) {
// 	vector<int> primes;
// 	for (int i=2; i<=n; i++) {
// 		bool isprime = 1;
// 		for (int j=2; j*j<=i; j++) {
// 			if (i%j == 0) {
// 				isprime = 0;
// 				break;
// 			}
// 		}
// 		if (isprime) primes.push_back(i);
// 	}
// 	return primes;
// }

// vector<int> primelist_2(int n) {
// 	vector<int> primes;
// 	for (int i=2; i<=n; i++) {
// 		bool isprime = 1;
// 		for (int p: primes) {
// 			if (p*p == 0) {
// 				isprime = 0;
// 				break;
// 			}
// 		}
// 		if (isprime) primes.push_back(i);
// 	}
// 	return primes;
// }

// vector<int> sieve_1(int n) { // 에라토스테네스의 체 (1)
// 	vector<int> primes;
// 	vector<bool> state(n+1, true);
// 	state[1] = false;
// 	for (int i=2; i<=n; i++) {
// 		if (!state[i]) continue;
// 		for (int j=2*i; j <= n; j += i)
// 			state[j] = false;
// 	}
// 	for (int i=2; i<=n; i++) {
// 		if (state[i]) primes.push_back(i);
// 	}
// 	return primes;
// }
vector<bool> state(1000001, true);
void sieve_2(int n) { // 에라토스테네스의 체 (2)
	state[1] = false;
	for (int i=2; i*i<=n; i++) {
		if (!state[i]) continue;
		for (int j=i*i; j <= n; j += i)
			state[j] = false;
	}
}

// vector<int> sieve_custome(int m, int n) { // 에라토스테네스의 체 (2)
// 	vector<int> primes;
// 	vector<bool> state(n+1, true);
// 	state[m] = false;
// 	for (int i=m; i*i<=n; i++) {
// 		if (!state[i]) continue;
// 		for (int j=i*i; j <= n; j += i)
// 			state[j] = false;
// 	}
// 	for (int i=m; i<=n; i++)
// 		if (state[i]) primes.push_back(i);
// 	return primes;
// }

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, n;
	
	cin >> m >> n;
	sieve_2(n);
	for (int i=m; i<=n; i++) {
		if (state[i]) cout << i << '\n';
	}
	return (0);
}