def solution(n, results):
    answer = 0
    board = [[0] * n for _ in range(n)]
    
    for a, b in results:
        board[a-1][b-1] = 1
        board[b-1][a-1] = -1
        
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if board[i][j] == 0:
                    if board[i][k] == 1 and board[k][j] == 1:
                        board[i][j] = 1
                    elif board[i][k] == -1 and board[k][j] == -1:
                        board[i][j] = -1
    
    for row in board:
        if row.count(0) == 1:
            answer += 1
    return answer

print(solution(5, [[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]))