
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

from itertools import combinations

n, k = map(int, input().split())
words = [input().rstrip() for _ in range(n)]

antic = {'a', 'n', 't', 'i', 'c'}
alpha = [chr(i + 97) for i in range(26) if chr(i + 97) not in antic]

if k < 5:
    print(0)
else:
    max_answer = 0
    for lst in combinations(alpha, k-5):
        answer = n
        d = dict.fromkeys(lst)
        for word in words:
            word = word[4:-4]
            for c in word:
                if (c not in d) and (c not in antic):
                    answer -=1
                    break

        max_answer = max(answer, max_answer)

    print(max_answer)
'''