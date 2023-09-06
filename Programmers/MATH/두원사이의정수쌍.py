def solution(r1, r2):
    ans1 = 0
    y = r1
    for x in range(1, r1):
        while (x * x + y * y) >= (r1 * r1):
            y = y - 1
        ans1 = ans1 + y
    ans1 = ans1 * 4 + (r1 - 1) * 4 + 1

    y = r2
    ans2 = 0
    for x in range(1, r2):
        while (x * x + y * y) > (r2 * r2):
            y = y - 1
        ans2 = ans2 + y
    ans2 = ans2 * 4 + r2 * 4 + 1

    return ans2 - ans1
