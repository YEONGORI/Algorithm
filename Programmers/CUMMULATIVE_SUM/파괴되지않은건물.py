def solution(board, skill):
    answer = 0
    
    n, m = len(board), len(board[0])
    cum = [[0] * (m+1) for _ in range(n+1)]
    
    for tp, r1, c1, r2, c2, degree in skill: # 변화량 배열 만들고
        if tp == 1:
            cum[r1][c1] += -degree
            cum[r2+1][c2+1] += -degree
            cum[r1][c2+1] += degree
            cum[r2+1][c1] += degree
        else:
            cum[r1][c1] += degree
            cum[r2+1][c2+1] += degree
            cum[r1][c2+1] += -degree
            cum[r2+1][c1] += -degree
            
    for i in range(1, n+1): # 누적합 배열 만들고
        for j in range(m+1):
            cum[i][j] += cum[i-1][j]
    for j in range(1, m+1):
        for i in range(n+1):
            cum[i][j] += cum[i][j-1]
            
    for i in range(n): # 기존 배열에 합치기
        for j in range(m):
            board[i][j] += cum[i][j]
            if board[i][j] > 0: answer += 1

    
    return answer