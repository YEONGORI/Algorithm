def solution() -> int:
    ans = 0
    dx = [-1, -1, -2, -2, 1, 1, 2, 2]
    dy = [2, -2, 1, -1, -2, 2, -1, 1]

    pos = input()
    x = int(pos[1]) - 1
    y = int(chr(ord(pos[0]) - 49))
    print(x, y)
    for i in range(8):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or ny < 0 or nx > 8 or ny > 8:
            continue
        ans += 1

    return ans

print(solution())