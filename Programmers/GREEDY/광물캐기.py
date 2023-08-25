from collections import deque

def solution(picks, minerals):
    pm_table = [
        [1, 1, 1],
        [5, 1, 1],
        [25, 5, 1]
    ]
    
    dia, iron, stone = picks
    fatigue, works = 0, deque()

    ps = deque([0] * dia + [1] * iron + [2] * stone)
    pl, ml = len(ps), len(minerals)
        
    if ml > sum(picks) * 5:
        minerals = minerals[:sum(picks) * 5]

    for i, m in enumerate(minerals):
        idx, pi = i % 5, i // 5

        if idx == 0:
            works.append([0, 0, 0])
        works[pi][0] += 1 if m == "diamond" else 0
        works[pi][1] += 1 if m == "iron" else 0
        works[pi][2] += 1 if m == "stone" else 0
    
    works = list(
        reversed(sorted(list(works), key=lambda x: (x[0], x[1], x[2]))))
        
    for p, work in zip(ps, works):
        for m, w in enumerate(work):
            fatigue += (pm_table[p][m] * w)
    
    return fatigue