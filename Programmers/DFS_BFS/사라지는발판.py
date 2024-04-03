from itertools import permutations

def solution(board, aloc, bloc):
    l = len(board)
    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    vis = [[False] * 5 for _ in range(5)]
            
    def dfs(a, b, board, cnt):
        if a[0] < 0 or a[0] >= l or a[1] < 0 or a[1] >= l: return
        if b[0] < 0 or b[0] >= l or b[1] < 0 or b[1] >= l: return
        if board[a[0]][a[1]] != 1 or board[b[0]][b[1]] != 1: return
    
        for d1, d2 in permutations(directions, 2):
            na_0, na_1 = a[0] + d1[0], a[1] + d1[1]
            nb_0, nb_1 = b[0] + d2[0], b[1] + d2[1]
            if not vis[na_0][na_1] and not vis[nb_0][nb_1]:
                vis[na_0][na_1] = True
                vis[nb_0][nb_1] = True
                board[a[0]][a[1]] = 0
                board[b[0]][b[1]] = 0
                dfs([na_0, na_1], [nb_0, nb_1], board, cnt + 1)
                vis[na_0][na_1] = False
                vis[nb_0][nb_1] = False
                board[a[0]][a[1]] = 1
                board[b[0]][b[1]] = 1
            
        
    vis[aloc[0]][aloc[1]] = True
    vis[bloc[0]][bloc[1]] = True   
    dfs(aloc, bloc, board, 0)
    return 1

solution([[1, 1, 1], [1, 1, 1], [1, 1, 1]], [1, 0], [1, 2])