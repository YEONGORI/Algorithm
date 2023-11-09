def compare(beginning, target, row, col):
    for r in range(len(beginning)):
        for c in range(len(beginning[0])):
            diff = ((row >> r) % 2 + ((col >> c) % 2)) % 2
            if (beginning[r][c] + diff) % 2 != target[r][c]:
                return False
    return True

def solution(beginning, target):
    MAX = len(beginning) * len(beginning[0]) + 1
    answer = MAX
    for row in range(2 ** len(beginning)):
        for col in range(2 ** len(beginning[0])):
            cnt = bin(row)[2:].count('1') + bin(col)[2:].count('1')
            if cnt < answer and compare(beginning, target, row, col):
                answer = cnt

    return answer if answer < MAX else -1