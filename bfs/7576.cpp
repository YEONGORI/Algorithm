// 토마토
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int ripe[1002][1002];
int board[1002][1002];
int n, m;

int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    queue<pair<int, int>> Q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 1)
            {
            }
        }
    }
}