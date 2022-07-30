// N과 M (4)
#include <iostream>

using namespace std;

int lst[10];
int n, m;

void func(int k) {
	if (k == m + 1) {
		for (int i = 1; i <= m; i++)
			cout << lst[i] << ' ';
		cout << '\n';
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (lst[k - 1] <= i)
		{
			lst[k] = i;
			func(k + 1);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func(1);
}