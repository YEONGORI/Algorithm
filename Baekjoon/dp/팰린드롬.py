from sys import stdin

n = int(stdin.readline())
nums = list(map(int, stdin.readline().split()))
m = int(stdin.readline())

dp = [[0] * n for _ in range(n)]

for i in range(n):
    for st in range(n - i):
        en = st + i
        if st == en:
            dp[st][en] = 1
        elif nums[st] == nums[en]:
            if st + 1 == en:
                dp[st][en] = 1
            elif dp[st + 1][en - 1] == 1:
                dp[st][en] = 1

for _ in range(m):
    s, e = map(int, stdin.readline().split())
    print(dp[s - 1][e - 1])
