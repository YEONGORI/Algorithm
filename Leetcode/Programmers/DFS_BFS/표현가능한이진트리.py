import sys
sys.setrecursionlimit(10**7)


def solution(numbers):
    def dfs(binary):
        b_len = len(binary)
        if b_len == 1 or '1' not in binary or '0' not in binary:
            return True

        mid = b_len // 2
        if binary[mid] == '0':
            return False
        return dfs(binary[:mid]) and dfs(binary[mid+1:])

    answer = []

    for d in numbers:
        binary = bin(d).replace("0b", "")
        b_len = len(binary)

        i = req_nodes = 0
        while b_len > req_nodes:
            req_nodes = (1 << i) - 1
            i += 1
        binary = ((req_nodes - b_len) * '0') + binary
        answer.append(1 if dfs(binary) else 0)

    return answer
