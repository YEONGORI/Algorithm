def solution(edges):
    answer = [0, 0, 0, 0]
    
    _dict = {}
    for s, e in edges:
        if not _dict.get(s):
            _dict[s] = [0, 0]
        if not _dict.get(e):
            _dict[e] = [0, 0]
        _dict[s][0] += 1
        _dict[e][1] += 1
        
    for key, value in _dict.items():
        if value[0] >= 2 and value[1] == 0:
            answer[0] = key
        elif value[0] == 0 and value[1] > 0:
            answer[2] += 1
        elif value[0] >= 2 and value[1] >= 2:
            answer[3] += 1
    
    answer[1] = _dict[answer[0]][0] - (answer[2] + answer[3])
    
    return answer