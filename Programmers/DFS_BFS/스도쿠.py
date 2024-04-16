board = [list(map(int, input().split())) for _ in range(9)]
pos = []
for i in range(9):
    for j in range(9):
        if board[i][j] == 0:
            pos.append([i, j])

def ch_rect(x, y, n):
    global board

    x, y = x//3 * 3, y//3 * 3
    for i in range(3):
        for j in range(3):
            if board[x + i][y + j] == n:
                return False
    return True

def ch_row(n, x):
    global board

    for i in range(9):
        if board[x][i] == n:
            return False
    return True

def ch_col(n, y):
    global board

    for i in range(9):
        if board[i][y] == n:
            return False
    return True

def backtracking(count):
    global board
    global pos
    if count == len(pos):
        for i in range(9):
            for j in range(9):
                print(board[i][j], end = ' ')
            print()
        exit()
    
    x, y = pos[count][0], pos[count][1]
    for num in range(1, 10):
        if ch_rect(x, y, num) and ch_col(num, y) and ch_row(num, x):
            board[x][y] = num
            backtracking(count + 1)
            board[x][y] = 0

backtracking(0)

'''
from itertools import permutations

board = []
possible = []
pos = []
for _ in range(9):
    lst = list(map(int, input().split()))
    op_lst = [i for i in range(10) if i not in lst]

    tmp = []
    for i in range(9):
        if lst[i] == 0: tmp.append(i)

    pos.append(tmp)
    possible.append(op_lst)
    board.append(lst)


def print_board(board):
    for i in range(9):
        for j in range(9):
            print(board[i][j], end=' ')
        print()

def check_rect(board, x, y):
    _sum = 0
    for i in range(x, x + 3):
        for j in range(y, y + 3):
            _sum += board[i][j]

    if _sum != 45: return False
    return True
def check_row(board):
    for i in range(9):
        sum1, sum2 = 0, 0
        for j in range(9):
            sum1 += board[i][j]
            sum2 += board[j][i]
        if sum1 != 45: return False
        if sum2 != 45: return False

    return True

finish = False
def backtracking(board, row):
    global finish
    if finish: return
    
    if row == 9:
        if not check_row(board):
            return
        if not check_rect(board, 0, 0):
            return
        elif not check_rect(board, 3, 0):
            return
        elif not check_rect(board, 6, 0):
            return
        elif not check_rect(board, 0, 3):
            return
        elif not check_rect(board, 0, 6):
            return
        elif not check_rect(board, 3, 3):
            return
        elif not check_rect(board, 3, 6):
            return
        elif not check_rect(board, 6, 3):
            return
        elif not check_rect(board, 6, 6):
            return
        print_board(board)
        finish = True
        return

    for some in permutations(possible[row], len(possible[row])):
        for idx in range(len(some)):
            board[row][pos[row][idx]] = some[idx]
        backtracking(board, row + 1)


backtracking(board, 0)
'''