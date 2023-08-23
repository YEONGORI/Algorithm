def solution(board):
    o, x = sum([arr.count('O') for arr in board]), sum(
        [arr.count('X') for arr in board])
    if 0 <= o-x <= 1:
        rb = [board[0][i]+board[1][i]+board[2][i] for i in range(3)]
        winO, winX = 0, 0
        for i, j in zip(board, rb):
            if 'OOO' in [i, j]:
                winO += 1
            if 'XXX' in [i, j]:
                winX += 1

        diagonal = [board[0][0] + board[1][1] + board[2]
                    [2], board[0][2] + board[1][1] + board[2][0]]
        winO += diagonal.count('OOO')
        winX += diagonal.count('XXX')

        if winX and winO:
            return 0
        if winO and winX == 0 and o == x:
            return 0
        if winX and winO == 0 and o != x:
            return 0

        return 1
    return 0
