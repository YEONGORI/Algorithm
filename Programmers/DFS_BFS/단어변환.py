from collections import deque


def solution(begin, target, words):
    def changable(s1, s2):
        cnt = 0
        for i in range(len(s1)):
            if s1[i] == s2[i]:
                cnt += 1
        if cnt == len(s1) - 1:
            return True
        else:
            return False

    size = len(words)
    visited = [1e9] * size
    Q = deque()
    Q.append((begin, 0))

    while Q:
        word, dist = Q.popleft()
        for i in range(size):
            if changable(word, words[i]) and visited[i] == 1e9:
                Q.append((words[i], dist + 1))
                visited[i] = min(visited[i], dist + 1)

    for i in range(size):
        if words[i] == target:
            return visited[i]
    return 0


print(solution("hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]))
