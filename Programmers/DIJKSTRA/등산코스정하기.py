from heapq import heappush, heappop


def solution(n, paths, gates, summits):
    def dijstra(start):
        q = []
        heappush(q, (0, start))
        distance[start] = 0
        while q:
            dist, now = heappop(q)
            if distance[now] < dist:
                continue
            if now in summits:
                continue
            for i in graph[now]:
                if i[0] in gates:
                    continue
                cost = max(distance[now], i[1])
                if cost < distance[i[0]]:
                    distance[i[0]] = cost
                    heappush(q, (cost, i[0]))
        return distance

    summits.sort()
    summits = set(summits)
    gates = set(gates)

    answer = [0, 1e9]
    graph = [[] for _ in range(n + 1)]

    for i, j, w in paths:
        graph[i].append((j, w))
        graph[j].append((i, w))

    distance = [1e9] * (n + 1)

    for start in gates:
        dist = dijstra(start)

    for end in summits:
        if dist[end] < answer[1]:
            answer = [end, dist[end]]
        elif dist[end] == answer[1]:
            answer[0] = min(end, answer[0])
    return answer


solution(
    6,
    [[1, 2, 3], [2, 3, 5], [2, 4, 2], [2, 5, 4], [
        3, 4, 4], [4, 5, 3], [4, 6, 1], [5, 6, 1]],
    [1, 3],
    [5]
)

solution(
    7,
    [[1, 4, 4], [1, 6, 1], [1, 7, 3], [2, 5, 2], [3, 7, 4], [5, 6, 6]],
    [1],
    [2, 3, 4]
)

solution(
    7,
    [[1, 2, 5], [1, 4, 1], [2, 3, 1], [2, 6, 7], [4, 5, 1], [5, 6, 1], [6, 7, 1]],
    [3, 7],
    [1, 5]
)

solution(
    5,
    [[1, 3, 10], [1, 4, 20], [2, 3, 4], [2, 4, 6], [3, 5, 20], [4, 5, 6]],
    [1, 2],
    [5]
)
