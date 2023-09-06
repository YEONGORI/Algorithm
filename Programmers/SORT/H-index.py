def solution_my(citations):
    def check(h) -> bool:
        for i, v in enumerate(citations):
            if h <= v and M - i >= h:
                if i <= h:
                    return True
        return False

    citations.sort()
    h = M = len(citations)

    while h >= 0:
        if check(h):
            return h
        h -= 1


def solution_best(citations):
    answer = 0
    citations.sort(reverse=True)
    for i in citations:
        if i > answer:
            answer += 1
    return answer
