d = [0] * 100


def fibo_topdown(x):
    if x == 1 or x == 2:
        return 1
    if d[x] != 0:
        return d[x]
    d[x] = fibo_topdown(x - 1) + fibo_topdown(x - 2)
    return d[x]


def fibo_bottomup(n):
    d[1] = 1
    d[2] = 1

    for i in range(3, n + 1):
        d[i] = d[i - 1] + d[i - 2]
    return d[n]


print(fibo_topdown(99))
