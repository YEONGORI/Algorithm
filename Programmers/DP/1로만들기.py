idx = 0
D = [0] * 10000


def solution(x):
    for i in range(2, x + 1):
        D[i] = D[i - 1] + 1
        if i % 2 == 0:
            D[i] = min(D[i], D[i // 2] + 1)
        if i % 3 == 0:
            D[i] = min(D[i], D[i // 3] + 1)
        if i % 5 == 0:
            D[i] = min(D[i], D[i // 5] + 1)
    return D[x]


print(solution(26))
