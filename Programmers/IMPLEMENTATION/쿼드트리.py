n = int(input())
board = []
for _ in range(n):
    board.append(list(map(int, input())))

answer = ""

def compress(board):
    init = board[0][0]
    l = len(board)

    for i in range(l):
        for j in range(l):
            if board[i][j] != init: return -1
    return init

def slice_left(board):
    half = len(board[0]) // 2
    new = []

    for i in range(half): new.append(board[i][:half])
    return new

def slice_right(board):
    half = len(board[0]) //2
    new = []

    for i in range(half): new.append(board[i][half:])
    return new
    

def divid_conquer(board):
    global answer
    if len(board) == 0: return
    half = len(board) // 2

    possible = compress(board)

    if possible != -1:
        answer += str(possible)
    else:
        answer += "("
        divid_conquer(slice_left(board[:half]))
        divid_conquer(slice_right(board[:half]))
        divid_conquer(slice_left(board[half:]))
        divid_conquer(slice_right(board[half:]))
        answer += ")"


divid_conquer(board)
print(answer)
