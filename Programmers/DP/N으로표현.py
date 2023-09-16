def solution(N, number):
    if number == 1:
        return 1
    dp = []
    for cnt in range(1, 9):
        pset = set()
        pset.add(int(str(N) * cnt))
        
        for i in range(cnt - 1):
            for op1 in dp[i]:
                for op2 in dp[-i-1]:
                    pset.add(op1 + op2)
                    pset.add(op1 - op2)
                    pset.add(op1 * op2)
                    if op2 != 0:
                        pset.add(op1 // op2)
        if number in pset:
            return cnt
        dp.append(pset)
    return -1


print(solution(5, 12))