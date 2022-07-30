// N과 M (5)
#include <iostream>
#include <algorithm>

using namespace std;

int lst[10];
int res[10];
bool pick[10];
int n, m;

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << res[i] << ' ';
		cout << '\n';
		return ;
	}
	for (int i = 0; i < n; i++) {
		if (lst[i] != -1) {
			res[k] = lst[i];
			int tmp = lst[i];
			lst[i] = -1;
			func(k + 1);
			lst[i] = tmp;
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
	func(0);
}