dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

n, m = map(int, input().split())

graph = []
for i in range(n):
    graph.append(list(map(int, input())))

def dfs(x, y) -> bool:
    if x < 0 or x >= n or y < 0 or y >= m:
        return False
    if graph[x][y] == 0:
        graph[x][y] = 1
        for i in range(4):
            dfs(x + dx[i], y + dy[i])
        return True
    return False      

def solution() -> int:
    ans = 0

    for i in range(n):
        for j in range(m):
            if dfs(i, j) == True:
                ans += 1
    return ans

print(solution())
