from collections import Counter

def solution(weights):
    answer, count = 0, Counter(weights)
    for k, v in count.items():
        if v > 1: answer += v * (v-1) // 2

    weights = set(weights)
    
    for w in weights:
        for check in (2/3, 2/4, 3/4):
            if w * check in weights:
                answer += count[w] * count[w * check]
    
    return answer