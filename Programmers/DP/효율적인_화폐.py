n, m = map(int, input().split())
money = []
D = [111111] * (m + 1)  # i원을 만드는데 필요한 화페의 갯수
for i in range(n):
    money.append(int(input()))

D[0] = 0
for bill in money:
    for j in range(bill, m + 1):
        if D[j - bill] != 111111:
            D[j] = min(D[j], D[j - bill] + 1)

if D[m] == 111111:
    print(-1)
else:
    print(D[m])
