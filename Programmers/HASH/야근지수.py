from heapq import heappush, heappop

def solution(n, works):
    answer = 0
    heap = []
    
    for v in works:
        heappush(heap, (-v, v))
        
    for _ in range(n):
        if heap:
            n = heappop(heap)[1]
            if n > 0:
                heappush(heap, (-n+1, n-1))
            
    for v1, v2 in heap:
        answer += v2 ** 2
    
    return answer