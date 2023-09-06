from collections import deque


def solution(maps):
    answer = 0
    hei = len(maps)
    wid = len(maps[0])
    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]
    vis = [[0 for i in range(wid)] for j in range(hei)]

    for i in range(hei):
        for j in range(wid):
            if maps[i][j] == 'S':
                start = (i, j)
            elif maps[i][j] == 'L':
                lever = (i, j)
            elif maps[i][j] == 'E':
                end = (i, j)

    queue = deque()
    queue.append(start)
    vis[start[0]][start[1]] = 1
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= hei or ny >= wid:
                continue
            if maps[nx][ny] == 'X' or vis[nx][ny] != 0:
                continue
            vis[nx][ny] = vis[x][y] + 1
            queue.append((nx, ny))

    print(vis)

    return answer
