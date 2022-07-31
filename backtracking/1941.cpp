// 소문난 칠공주
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int board[7][7];
int res[7][7];
bool pick[7][7];
int total, cnt;

void func(int k) {
	if (k == 7) {
		if (total >= 4) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++)
					cout <<  res[i][j] << ' ';
				cout << '\n';
			}
			cnt++;
		}
		total = 0;
		return ;
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (!board[i][j] && pick[i][j])	continue;
			
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string sit;

	for (int i = 0; i < 5; i++) {
		cin >> sit;
		for (int j = 0; j < 5; j++)
		{
			if (sit[j] == 'S')
				board[i][j] = 1;
		}
	}
	func(0);
	// for (int i = 0; i < 5; i++) {
	// 	for (int j = 0; j < 5; j++)
	// 		cout <<  board[i][j] << ' ';
	// 	cout << '\n';
	// }
}