// Easy
#include <bits/stdc++.h>

using namespace std;

int board[22][22];
int b_cpy[22][22];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int n;

int go_left(int dir)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (board[i][j] == board[i][j + 1])
            {
                board[i][j] *= 2;
                board[i][j + 1] = 0;
                for (int k = j + 1; k < n; k++)
                {
                    board[i][k] = board[i][k + 1];
                    board[i][k + 1] = 0;
                }
                cnt++;
            }
        }
    }
    return cnt;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    }

    while (true)
    {
        copy(&board[0][0], &board[0][0] + 484, &b_cpy[0][0]);
    }
}