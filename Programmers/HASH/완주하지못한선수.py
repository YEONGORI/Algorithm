def solution(participant, completion):
    D = {}

    for co in completion:
        if co not in D:
            D[co] = 1
        else:
            D[co] += 1
            
    for pa in participant:
        if pa not in D:
            return pa
        elif D[pa] == 0:
            return pa
        else:
            D[pa] -= 1