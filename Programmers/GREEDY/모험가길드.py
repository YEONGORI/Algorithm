def solution(n) -> int:
    ans = cnt = 0
    s_list = input()
    n_list = [int(num) for num in s_list.split()]
    # n_list = list(map(int, input().split()))
    n_list.sort()

    for i in n_list:
        cnt += 1
        if cnt >= i:
            ans += 1
            cnt = 0
    return ans

print(solution(5))
