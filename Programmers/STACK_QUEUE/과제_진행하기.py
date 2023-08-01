def timer(time: str) -> int:
    h, m = map(int, time.split(':'))
    return h * 60 + m


def solution(plans):
    answer, stack = [], []
    for plan in plans:
        plan[1], plan[2] = timer(plan[1]), int(plan[2])

    plans.sort(key=lambda ls: ls[1])

    t, idx = plans[0][1], 0
    while idx < len(plans):
        stack.append(plans[idx])
        if t < stack[-1][1]:
            t = stack[-1][1]

        while stack and stack[-1][2]:
            t += 1
            stack[-1][2] -= 1
            if not stack[-1][2]:
                answer.append(stack.pop()[0])
            if idx + 1 < len(plans) and t == plans[idx+1][1]:
                stack.append(plans[idx+1])
                idx += 1
        idx += 1

    return answer
