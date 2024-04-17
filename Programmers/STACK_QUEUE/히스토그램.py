n = int(input())

stack = []
for _ in range(n):
    h = int(input())
    if len(stack) == 0:
        stack.append(h)
    else:
        if stack[-1] <= h:
            stack.append(h)
        else:
            