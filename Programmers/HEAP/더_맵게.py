from heapq import heappush, heappop


def solution(scoville, K):
    answer = 0
    heap = []
    for s in scoville:
        heappush(heap, s)

    while heap[0] < K and len(heap) >= 2:
        new = heappop(heap) + (heappop(heap) * 2)
        heappush(heap, new)
        answer += 1

    if heap[0] < K:
        return -1
    return answer
