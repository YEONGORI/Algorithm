r, c, t = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(r)]
directions = [(-1, 0), (1, 0), (0, 1), (0, -1)]
dir_up = [(0, 1), (-1, 0), (0, -1), (1, 0)]
dir_down = [(0, 1), (1, 0),(0, -1), (-1, 0)]
cleaner = [i for i in range(r) if board[i][0] == -1]

def spread(pos):
    global board

    for x, y, val in pos:
        cnt = 0
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if nx < 0 or ny < 0 or nx == r or ny == c: continue
            if board[nx][ny] == -1: continue
            board[nx][ny] += (val // 5)
            cnt += 1

        board[x][y] -= (cnt * (val // 5))


def clean():
    global board
    for idx, pos in enumerate(cleaner):
        if idx == 0:
            tmp, x, y = 0, pos, 1
            # dir = 0
            # while True:
            #     nx, ny = x + dir_up[dir][0], y + dir_up[dir][1]
            #     if nx == r or ny == c or nx < 0 or ny < 0:
            #         dir += 1
            #         continue
            #     if x == pos and y == 0:
            #         break
            #     board[x][y], tmp = tmp, board[x][y]
            #     x, y = nx, ny

            for dx, dy in dir_up:
                while True:
                    nx, ny = x + dx, y + dy
                    if nx == r or ny == c or nx < 0 or ny < 0:
                        break
                    if x == pos and y == 0:
                        break
                    board[x][y], tmp = tmp, board[x][y]
                    x, y = nx, ny
                
            # tmp, out = 0, board[x][c-1]
            # for i in range(1, c):
            #     tmp2 = board[x][i]
            #     board[x][i] = tmp
            #     tmp = tmp2
            # tmp = out
            # out = board[0][c-1]
            # for i in range(r//2 - 2, -1, -1):
            #     tmp2 = board[i][c-1]
            #     board[i][c-1] = tmp
            #     tmp = tmp2
            # tmp = out
            # out = board[0][0]
            # for i in range(c-2, -1, -1):
            #     tmp2 = board[0][i]
            #     board[0][i] = tmp
            #     tmp = tmp2
            # tmp = out
            # for i in range(1, r//2 - 1):
            #     tmp2 = board[i][0]
            #     board[i][0] = tmp
            #     tmp = tmp2
        else:
            tmp, x, y = 0, pos, 1
            # dir = 0
            # while True:
            #     nx, ny = x + dir_down[dir][0], y + dir_down[dir][1]
            #     if nx == r or ny == c or nx < 0 or ny < 0:
            #         dir += 1
            #         continue
            #     if x == pos and y == 0:
            #         break

            #     board[x][y], tmp = tmp, board[x][y]
            #     x, y = nx, ny

            for dx, dy in dir_down:
                while True:
                    nx, ny = x + dx, y + dy
                    if nx == r or ny == c or nx < 0 or ny < 0:
                        break
                    if x == pos and y == 0:
                        break
                    board[x][y], tmp = tmp, board[x][y]
                    x, y = nx, ny
                
            # tmp, out = 0, board[x][c-1]
            # for i in range(1, c):
            #     tmp2 = board[x][i]
            #     board[x][i] = tmp
            #     tmp = tmp2
            # tmp = out
            # out = board[r-1][c-1]
            # for i in range(r//2 + 1, r):
            #     tmp2 = board[i][c-1]
            #     board[i][c-1] = tmp
            #     tmp = tmp2
            # tmp = out
            # out = board[r-1][0]
            # for i in range(c-2, -1, -1):
            #     tmp2 = board[r-1][i]
            #     board[r-1][i] = tmp
            #     tmp = tmp2
            # tmp = out
            # for i in range(r-2, r//2, -1):
            #     tmp2 = board[i][0]
            #     board[i][0] = tmp
            #     tmp = tmp2
            
for sec in range(t):
    pos = []
    for i in range(r):
        for j in range(c):
            if board[i][j] >= 5: pos.append((i, j, board[i][j]))

    spread(pos)
    clean()

# for i in range(r):
#     print(board[i])
answer = 0
for i in range(r):
    for j in range(c):
        if board[i][j] != -1: answer += board[i][j]
print(answer)

