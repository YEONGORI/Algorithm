// N과 M (8)
#include <iostream>
#include <algorithm>

using namespace std;

int lst[10];
int res[10];
int n, m;

void func(int k) {
	if (k == m + 1) {
		for (int i = 1; i <= m; i++)
			cout << res[i] << ' ';
		cout << '\n';
		return ;
	}
	for (int i = 0; i < n; i++) {
		if (lst[i] >= res[k - 1]) {
			res[k] = lst[i];
			func(k + 1);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> lst[i];
	sort(lst, lst + n);
	func(1);
}