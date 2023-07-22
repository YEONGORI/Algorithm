n = input()
line = list(map(int, input().split()))
line.reverse()

D = [1] * n
for i in range(1, n):
    for j in range(0, i):
        if line[j] < line[i]:
            D[i] = max(D[i], D[j] + 1)

print(n - max(D))
