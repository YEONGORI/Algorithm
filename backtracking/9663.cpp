// N-Queen
#include <iostream>

using namespace std;

int n, res;
int board[20];

void func(int q) {
	if (q == n + 1)
	{
		res++;
		return ;
	}
	for (int i = 1; i <= n; i++) {
		board[q] = i;
		int j;
		for (j = 1; j < q; j++)
			if (board[q] == board[q - j] || board[q] == board[q - j] - j || board[q] == board[q - j] + j)
				break;;
		if (j != q) continue;
		func(q + 1);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	func(1);
	cout << res;
}