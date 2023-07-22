n, m = map(int, input().split(' '))
arr = list(map(int, input().split(' ')))
board = list([])
D = list([])

for i in range(n):
    board.append(arr[(i * m): (i + 1) * m])
    D.append([0] * m)

for i in range(n):
    D[i][0] = board[i][0]

for j in range(1, m):
    for i in range(n):
        if i == 0:
            D[i][j] = max(D[i][j - 1], D[i + 1][j - 1]) + board[i][j]
        elif i == n - 1:
            D[i][j] = max(D[i - 1][j - 1], D[i][j - 1]) + board[i][j]
        else:
            D[i][j] = max(D[i - 1][j - 1], D[i][j - 1],
                          D[i + 1][j - 1]) + board[i][j]
print(max(D))
