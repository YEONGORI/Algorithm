from itertools import combinations

def word_to_bit(word):
    bit = 0
    for c in word:
        bit |= (1 << (ord(c) - ord('a')))
    return bit

n, k =map(int, input().split())
words = [input().rstrip() for _ in range(n)]
bits = list(map(word_to_bit, words))
base_bit = word_to_bit('antic')

if k < 5:
    print(0)
else:
    alpa = [1 << i for i in range(26) if not (base_bit & 1 << i)]
    answer = 0
    for comb in combinations(alpa, k-5):
        cur_bit = sum(comb) | base_bit
        cnt = 0
        for bit in bits:
            if bit & cur_bit == bit:
                cnt += 1
        answer = max(answer, cnt)
    print(answer)

'''
n, k = map(int, input().split())
max_cnt = 0

strings = []
alpa = ['a', 'n', 't', 'i', 'c']
for _ in range(n):
    str = input()
    strings.append(str)
    for i in range(4, len(str) - 4):
        if str[i] not in alpa:
            alpa.append(str[i])

vis = [False for _ in range(len(alpa))]
for i in range(6):
    vis[i] = True

def cal(cur):
    cnt = 0
    for str in strings:
        read = True
        for c in str:
            if c not in cur:
                read = False
        if read:
            cnt += 1
    return cnt

def bt(depth, vis, cur:list):
    if depth == k:
        global max_cnt
        max_cnt = max(max_cnt, cal(cur))
        return 
    
    for i in range(5, len(alpa)):
        if not vis[i]:
            vis[i] = True
            cur.append(alpa[i])
            bt(depth + 1, vis, cur)
            vis[i] = False
            cur.pop()

if k < 5:
    print(0)
else:
    bt(5, vis, ['a', 'n', 't', 'r', 'i', 'c'])
    print(max_cnt)
'''

'''
from itertools import combinations

n, k = map(int, input().split())

strings = []
alpa = ['a', 'n', 't', 'r', 'i', 'c']
for _ in range(n):
    str = input()
    strings.append(str)
    for i in range(4, len(str) - 4):
        if str[i] not in alpa:
            alpa.append(str[i])

max_answer = 0
for lst in combinations(alpa, k):
    answer = n
    for str in strings:
        for c in str:
            if c not in lst:
                answer -=1
                break

    max_answer = max(answer, max_answer)

print(max_answer)
'''