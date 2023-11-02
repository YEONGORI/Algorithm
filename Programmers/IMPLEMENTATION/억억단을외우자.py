def solution(e, starts):

    div = [1] * (e + 1)
    for i in range(2, e + 1):
        for j in range(i, e + 1, i):
            div[j] += 1
    
    numcntans = [0] * (e + 1)
    _max_addr = _max = 0
    for i in range(e, -1, -1):
        if _max <= div[i]:
            _max_addr = i
            _max = div[i]
        numcntans[i] = _max_addr

    answer = []
    for st in starts:
        answer.append(numcntans[st])

    return answer