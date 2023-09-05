def solution(n):
    storage = list(map(int, input().split()))
    D = [0] * n

    D[0] = storage[0]
    D[1] = storage[1]
    for i in range(2, n):
        D[i] = max(D[i - 2] + storage[i], D[i - 1])
    return D[n - 1]


print(solution(4))
