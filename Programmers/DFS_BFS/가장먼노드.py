from collections import deque

def solution(n, edge):
    q, dist = deque(), [1e9] * (n + 1)
    m = [set() for _ in range(n + 1)]
    
    for st, en in edge:
        m[st].add(en)
        m[en].add(st)
        
    dist[0] = dist[1] = 0
    q.append(1)
    while q:
        cur = q.popleft()
        for n in m[cur]:
            if dist[n] != 1e9: continue
            q.append(n)
            dist[n] = min(dist[n], dist[cur] + 1)
    return dist.count(max(dist))
            

print(solution(6, [[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]))