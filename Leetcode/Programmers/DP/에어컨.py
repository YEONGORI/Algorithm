# https://doraeul19.tistory.com/245

def solution(temperature, t1, t2, a, b, onboard):
    # 0으로 정규화
    diff = temperature - t2 if temperature > t2 else t1 - temperature

    # 시간0에 대해 초기 비용으로 초기화
    result = [[1000000 for i in range(diff+1)]+[0]]
    last_passenger = 0

    for i in range(1, len(onboard)):
        arr = []
        for j in range(diff+2):
            temp = [result[i-1][j]+b]

            if j == diff + 1:  # 온도 유지
                temp.append(result[i-1][j])
            if j <= diff:  # 온도 내리기
                temp.append(result[i-1][j+1] + a)
            if j > 0:  # 온도 올리기
                temp.append(result[i-1][j-1])
            min_cost = min(temp)

            # 시간i에 대해 승객에 탑승 중이고, 적정온도 범위 밖이라면.
            if onboard[i] == 1:
                last_passenger = i
                if j > 1:
                    min_cost = 100000  # 100 * 1000
            arr.append(min_cost)
        result.append(arr)
    return min(result[last_passenger])


solution(28, 18, 26, 10, 8, [0, 0, 1, 1, 1, 1, 1])
