def solution(str) -> int:
    ans = 0

    for c in str:
        if int(c) == 1:
            ans += int(c)
        elif int(c) > 1:
            if ans == 0:
                ans = 1
            ans *= int(c)
    return ans

print(solution("01984"))