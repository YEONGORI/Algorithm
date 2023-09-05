def solution():
    n = input()
    k = input()
    A = list(map(int, input()))
    B = list(map(int, input()))

    A.sort()
    B.sort(reverse=True)

    for i in range(k):
        if (A[i] < B[i]):
            A[i], B[i] = B[i], A[i]
        else:
            break
    print(sum(A))
