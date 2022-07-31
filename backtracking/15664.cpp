// N과 M (10)
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int lst[10], res[10];
bool pick[10];

void func(int k) {
	if (k == m + 1) {
		for (int i = 1; i <= m; i++)
			cout << res[i] << ' ';
		cout << '\n';
		return ;
	}
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		if (!pick[i] && tmp != lst[i] && lst[i] >= res[k - 1]) {
			res[k] = lst[i];
			pick[i] = 1;
			tmp = res[k];
			func(k + 1);
			pick[i] = 0;
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