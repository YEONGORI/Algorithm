from itertools import product
from copy import deepcopy

directions = [(0, 0), (0, 1), (0, -1), (1, 0), (-1, 0)]

def rotate(board, x, y, n):
    length = len(board)
    
    for dx, dy in directions:
        if 0 <= x + dx < length and 0 <= y + dy < length:
            board[x+dx][y+dy] = (board[x+dx][y+dy] + n) % 4
            
def finished(board):
    for x in board[-1]:
        if x != 0: return False
    return True

def solution(clockHands):
    answer = 1e9
    length = len(clockHands)
    
    for ns in product(range(4), repeat=length):
        cnt = 0
        
        board = deepcopy(clockHands)
        for y, n in zip(range(length), ns):
            rotate(board, 0, y, n)
            cnt += n
            
        for x in range(1, length):
            for y in range(length):
                if (n := board[x-1][y]) != 0:
                    rotate(board, x, y, (4-n) % 4)
                    cnt += (4-n) % 4
        
        if finished(board):
            answer = min(answer, cnt)
    return answer