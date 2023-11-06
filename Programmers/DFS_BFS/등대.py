import sys
sys.setrecursionlimit(10 ** 6)

def solution(n, lighthouse):
    board = [[] for _ in range(n+1)]
    light = [False] * (n+1)
    for x, y in lighthouse:
        board[x].append(y)
        board[y].append(x)
        
    def dfs(node, parent):
        for child in board[node]:
            if child == parent: continue
            dfs(child, node)
            
            if light[child] == False and light[node] == False:
                light[node] = True
    dfs(1, 1)
        
    return light.count(True)
