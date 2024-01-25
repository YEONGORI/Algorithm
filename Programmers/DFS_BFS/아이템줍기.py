from collections import deque

directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

def solution(rectangle, characterX, characterY, itemX, itemY):    
    board = [[9 for _ in range(102)] for _ in range(102)]
    vis = [[1 for _ in range(102)] for _ in range(102)]
    
    for x1,y1, x2,y2 in rectangle:
        x1,y1, x2,y2 = x1*2,y1*2, x2*2,y2*2
        for x in range(x1, x2 + 1):
            for y in range(y1, y2 + 1):
                if x1 < x < x2 and y1 < y < y2:
                    board[y][x] = 0
                elif board[y][x] != 0:
                    board[y][x] = 1

    characterX, characterY, itemX, itemY = characterX*2, characterY*2, itemX*2, itemY*2
    
    Q = deque()
    Q.append((characterY, characterX))
    while Q:
        y, x = Q.popleft()
        if y == itemY and x == itemX: break
        for dy, dx in directions:
            ny, nx = y + dy, x + dx
            if board[ny][nx] == 1 and vis[ny][nx] == 1:
                vis[ny][nx] += vis[y][x]
                Q.append((ny, nx))
    
    return vis[itemY][itemX] // 2