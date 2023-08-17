def solution(temperature, t1, t2, a, b, onboard):
    last_passenger = 0
    temperature += 10
    t1 += 10
    t2 += 10
    if temperature > t2:
        temperature = t1 - (temperature - t2)  # 모든 경우에 히터만을 사용
    print(t1, t2, temperature)
    diff = t1 - temperature

    # i분이 경과했을 때 j 도를 만들어 낼 수 있는 히터의 최소 소비 전력
    dp = [[1e9 for _ in range(t1 + 1)] + [0]]
    dp[0][temperature] = 0

    for i in range(1, len(onboard)):
        arr = []  # i분 기준 0 ~ t1 도를 만들 수 있는 히터의 최소 소비 전력
        for j in range(t1 - diff, t1 + diff):
            tmp = [dp[i - 1][j] + b]
            if j == diff + 1:  # 온도 유지하기
                tmp.append(dp[i - 1][j])
            if j <= diff:     # 온도 올리기
                tmp.append(dp[i - 1][j - 1] + a)
            if j > t1:       # 온도 내리기
                tmp.append(dp[i - 1][j + 1])
            min_cost = min(tmp)
            # print(tmp)

            if onboard[i]:
                last_passenger = i
                if j < t1:
                    min_cost = 1e9
            arr.append(min_cost)
        print(arr)

        dp.append(arr)

    return min(dp[last_passenger])


def solution2(temperature, t1, t2, a, b, onboard):
    # 0으로 정규화
    diff = temperature - t2 if temperature > t2 else t1 - temperature
    # 시간0에 대해 초기 비용으로 초기화
    result = [[1000000 for i in range(diff+1)]+[0]]
    last_passenger_index = 0
    for i in range(1, len(onboard)):
        arr = []
        for j in range(diff+2):
            temp = [result[i-1][j]+b]
            # 할수있는 행동(비용)은 온도유지(b), 온도 내리기(a), 온도올리기(0)
            if j == diff + 1:
                temp.append(result[i-1][j])
            if j <= diff:
                temp.append(result[i-1][j+1] + a)
            if j > 0:
                temp.append(result[i-1][j-1])
            min_cost = min(temp)
            # print(temp)
            # 시간i에 대해 승객에 탑승 중이고, 적정온도 범위 밖이라면.
            if onboard[i] == 1:
                last_passenger_index = i
                if j > 1:
                    min_cost = 100000  # 100 * 1000
            arr.append(min_cost)
            print(arr)
        result.append(arr)
    return min(result[last_passenger_index])


solution(28, 18, 26, 10, 8, [0, 0, 1, 1, 1, 1, 1])
print()
# solution2(28, 18, 26, 10, 8, [0, 0, 1, 1, 1, 1, 1])
