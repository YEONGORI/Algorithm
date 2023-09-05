from collections import deque


def solution(board):
    def move(d, y, x):
        while True:
            y += d[0]
            x += d[1]
            if x < 0 or y < 0 or x >= x_max or y >= y_max:
                break
            if board[y][x] == 'D':
                break
        return y - d[0], x - d[1]

    directions = ((-1, 0), (1, 0), (0, -1), (0, 1))
    q = deque()
    x_max = len(board[0])
    y_max = len(board)
    vis = [[-1 for _ in range(x_max)] for _ in range(y_max)]

    for y in range(y_max):
        for x in range(x_max):
            if board[y][x] == 'R':
                q.append((y, x))
                vis[y][x] = 0
            if board[y][x] == 'G':
                y_goal, x_goal = y, x

    while q:
        y, x = q.popleft()
        for d in directions:
            ny, nx = move(d, y, x)
            if vis[ny][nx] == -1:
                q.append((ny, nx))
                vis[ny][nx] = vis[y][x] + 1

    return vis[y_goal][x_goal]
