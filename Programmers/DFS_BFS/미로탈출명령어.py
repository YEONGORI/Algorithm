import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)
answer = "z"

def solution(n, m, x, y, r, c, k):
    d = [(1, 0), (0, -1), (0, 1), (-1, 0)]
    d_en = ('d', 'l', 'r', 'u')
    
    def is_valid(nx, ny):
        return 1 <= nx and nx <= n and 1 <= ny and ny <= m
    
    def dfs(x, y, prev_s, cnt):
        global answer
        if k < cnt + abs(x - r) + abs(y  - c):
            return
        if x == r and y == c and cnt == k:
            answer = prev_s
            return
        for i in range(4):
            nx, ny = x + d[i][0], y + d[i][1]
            if is_valid(nx, ny) and prev_s < answer:
                dfs(nx, ny, prev_s + d_en[i], cnt + 1)

    dist = abs(x - r) + abs(y - c)
    if dist > k or (k - dist) % 2 == 1:
        return "impossible"
    dfs(x, y, "", 0)
    return answer


''' 다른 풀이 '''
from collections import deque

def solution_sub(n, m, x, y, r, c, k):
    q = deque([x, y, "", 0])
    dt = [(1, 0, 'd'), (0, -1, 'l'), (0, 1, 'r'), (-1, 0, 'u')]
    
    while q:
        x, y, path, cnt = q.popleft()
        if (x, y) == (r, c) and (k - cnt) % 2 == 1:
            return "impossible"
        if (x, y) == (r, c) and cnt == k:
            return path
        for i in range(4):
            dx, dy, direction = dt[i]
            nx = x + dx
            ny = y + dy
            if nx <= 0 or nx > n or ny <= 0 or ny > m: continue
            if abs(nx - r) + abs(ny - c) + cnt + 1 > k: continue
            q.append([nx, ny, path + direction, cnt + 1])
            break
            
    return "impossible"