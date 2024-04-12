from itertools import combinations

def solution(clothes):
    D = {}
    n = len(clothes)
    for name, tp in clothes:
        if tp not in D: D[tp] = [name]
        else: D[tp].append(name)
    
    ans = 1
    for k, v in D.items():
        ans *= (len(v) + 1)
    return ans - 1
