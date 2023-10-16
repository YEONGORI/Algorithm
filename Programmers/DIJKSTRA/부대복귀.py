from heapq import heappush, heappop

def solution(n, roads, sources, destination):
    heap = []
    graph = [[0] * (n+1) for _ in range(n+1)]

    dist = [-1] * (n+1)
    
    for i, j in roads:
        graph[i][j] = graph[j][i] = 1

    dist[destination] = 0
    heappush(heap, (0, int(destination)))
    
    
    while heap:
        d, st = heappop(heap)
        if d > dist[st]: continue
        
        for i in range(1, n+1):
            if graph[st][i] == 1 and dist[i] == -1:
                heappush(heap, (d+1, i))
                dist[i] = d + 1

    
    result = []
    for s in sources:
        result.append(dist[s])
        
    

    return result