def solution(info, edges):
    answer = []
    
    D = {}
    for st, en in edges:
        if st in D: D[st].append(en)
        else: D[st] = [en]

    vis = [False] * 20
    def dfs(sheep, wolf):
        if sheep <= wolf:
            return
        answer.append(sheep)
        
        for p, c in edges:
            if vis[p] and not vis[c]:
                vis[c] = True
                if info[c] == 0:
                    dfs(sheep+1, wolf)
                else:
                    dfs(sheep, wolf+1)
                vis[c] = False

    vis[0] = True
    dfs(1, 0)
    return max(answer)