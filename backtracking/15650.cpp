// N과 M (2)
#include <iostream>

using namespace std;

int board[10];
bool pick[10];
int n, m;

int  check(int k, int idx)
{
	for (int i = 0; i < k; i++) {
		if (board[i] > idx)
			return (0);
	}
	return (1);
}

void func(int k)
{
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << board[i] << ' ';
		cout << '\n';
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (!pick[i] && check(k, i)) {
			board[k] = i;
			pick[i] = 1;
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
	func(0);
}