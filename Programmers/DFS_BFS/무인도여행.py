import sys
from collections import deque

sys.setrecursionlimit(10000)

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def solution(maps):
    def dfs(x, y) -> int:
        ret = 0
        if x < 0 or y < 0 or x >= hei or y >= wid:
            return ret
        if maps[x][y] != 'X' and vis[x][y] is False:
            vis[x][y] = True
            for i in range(4):
                ret += dfs(x + dx[i], y + dy[i])
            return int(maps[x][y]) + ret
        return ret

    ans = []
    hei = len(maps)
    wid = len(maps[0])

    vis = [[False for i in range(wid)] for j in range(hei)]

    for i in range(hei):
        for j in range(wid):
            if maps[i][j] != 'X' and vis[i][j] is False:
                ans.append(dfs(i, j))
    if len(ans) == 0:
        return [-1]
    return sorted(ans)


print(solution(["X591X", "X1X5X", "X231X", "1XXX1"]))
