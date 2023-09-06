def 집에가져가는떡(rice_cakes, h) -> int:
    amount = 0
    for rice_cake in rice_cakes:
        if rice_cake >= h:
            amount += rice_cake - h
    return amount


def solution():
    n, m = map(int, input().split(' '))
    rice_cakes = list(map(int, input().split()))

    start = 0
    ans = end = max(rice_cakes)
    while start <= end:
        mid = (start + end) // 2
        amount = 집에가져가는떡(rice_cakes, mid)
        if (amount < m):
            end = mid - 1
        else:
            start = mid + 1
            ans = min(ans, amount)
    return ans


print(solution())
