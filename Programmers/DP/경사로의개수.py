def solution(grid, d, k):
    mod = 1000000007
    def custom_matmul(a, b):
        n = len(a)
        result = [[0 for _ in range(n)] for _ in range(n)]
        
        for i in range(n):
            for j in range(n):
                for k in range(n):
                    result[i][j] += ((a[i][k] % mod) * (b[k][j] % mod)) % mod
        return result
    
    cnt = answer = 0
    dr = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    n, m, dl = len(grid), len(grid[0]), len(d)

    p_cnt = [[[0 for _ in range(n*m)] for _ in range(n*m)] for _ in range(dl+1)]

    for i in range(n*m):
        p_cnt[0][i][i] = 1

    for l in range(1, dl + 1):
        for i in range(0, n * m):
            x, y = i % m, i // m

            for dx, dy in dr:
                nx, ny = x + dx, y + dy
                if nx < 0 or ny < 0 or nx >= m or ny >= n:
                    continue
                if grid[ny][nx] - grid[y][x] != d[l-1]:
                    continue
                    
                for j in range(n * m):
                    p_cnt[l][j][ny*m + nx] += p_cnt[l-1][j][i] % mod
                    p_cnt[l][j][ny*m + nx] %= mod
                    
    while 2**cnt < k: cnt += 1

    arr_cnt = [[[0 for _ in range(n*m)] for _ in range(n*m)] for _ in range(cnt + 1)]
    arr_cnt[0] = p_cnt[dl]
    for i in range(1, cnt + 1):
        arr_cnt[i] = custom_matmul(arr_cnt[i-1], arr_cnt[i-1])
        
    mat = [[0 for _ in range(n*m)] for _ in range(n*m)]
    for i in range(n*m):
        mat[i][i] = 1

    while k > 0:
        if k >= 2**cnt:
            mat = custom_matmul(mat, arr_cnt[cnt])
            k -= 2**cnt
        cnt -= 1

    for i in range(n*m):
        for j in range(n*m):
            answer += mat[i][j]
            answer %= mod
    
    return answer
    
    
print(solution([[1,4,0], [4,2,7], [2,7,0]], [3,-2,5], 1)) # answer is 5