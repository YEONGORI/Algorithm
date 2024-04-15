import collections

def solution(tickets):
    graph = collections.defaultdict(list)
    
    for a, b in sorted(tickets, key=lambda x: x[1]):
        graph[a].append(b)
    
    route = []

    def dfs(start):
        while graph[start]:
            dfs(graph[start].pop(0))
        route.append(start)

    dfs("ICN")
    print(route)
    return route[::-1]