// N과 M (3)
#include <iostream>

using namespace std;

int n, m;
int lst[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << lst[i] << ' ';
		cout << '\n';
		return ;
	}
	for (int i = 1; i <= n; i++) {
		lst[k] = i;
		func(k + 1);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func(0);
}