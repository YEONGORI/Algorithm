def solution(nums):
    D = {}
    N = len(nums)
    for num in nums:
        if num not in D:
            D[num] = 0
    if len(D) > N//2: return N//2
    else: return len(D)
