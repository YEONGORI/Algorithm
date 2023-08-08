def solution(temperature, t1, t2, a, b, onboard):
    timeLimit = len(onboard)
    # time에 goalTemperature를 유지할 수 있는 최소 전력량
    dp = [[-1] * 50 for _ in range(timeLimit)]
    dp[0][temperature] = 0

    if temperature > t2:
        temperature = t1 - (temperature - t2)  # 이제 모든 에어컨은 가동하면 실내 온도가 올라간다.
    temperature += 10
    t1 += 10
    t2 += 10

    for time in range(1, timeLimit):
        for goalTemperature in range(t1, t2 + 1):
            if dp[time - 1][goalTemperature - 1] + a != -1 and dp[time - 1][goalTemperature] + b != -1 and dp[time - 1][goalTemperature + 1] != -1:
                dp[time][goalTemperature] = min(
                    dp[time - 1][goalTemperature - 1] + a, dp[time - 1][goalTemperature] + b, dp[time - 1][goalTemperature + 1])
            elif dp[time - 1][goalTemperature - 1] != -1 and dp[time - 1][goalTemperature] != -1:
                dp[time][goalTemperature] = min(
                    dp[time - 1][goalTemperature - 1] + a, dp[time - 1][goalTemperature])
            elif dp[time - 1][goalTemperature] != -1 and dp[time - 1][goalTemperature + 1] != -1:
                dp[time][goalTemperature] = min(
                    dp[time - 1][goalTemperature] + b != -1, dp[time - 1][goalTemperature + 1] != -1)
            elif dp[time - 1][goalTemperature - 1] != -1 and dp[time - 1][goalTemperature + 1] != -1:
                dp[time][goalTemperature] = min(
                    dp[time - 1][goalTemperature - 1] + a != -1, dp[time - 1][goalTemperature + 1] != -1)
            elif dp[time - 1][goalTemperature - 1] != -1:
                dp[time][goalTemperature] = dp[time - 1][goalTemperature - 1]
            elif dp[time - 1][goalTemperature] != -1:
                dp[time - 1][goalTemperature] = dp[time - 1][goalTemperature] + b
            elif dp[time - 1][goalTemperature + 1] != -1:
                dp[time - 1][goalTemperature] = dp[time - 1][goalTemperature + 1]

    print(dp)


solution(28, 18, 26, 10, 8, [0, 0, 1, 1, 1, 1, 1])  # 40
print()
solution(-10, -5, 5, 5, 1, [0, 0, 0, 0, 0, 1, 0])  # 24

'''
dp[time][goalTemperature] = dp[time - 1][goalTemperature] # 목표 온도와 현재 기온이 같을 때

dp[time][goalTemperature] = dp[time - 1][goalTemperature] + b # 에어컨을 켜서 온도를 유지하고 싶을 때 

dp[time][goalTemperature] = dp[time - 1][goalTemperature - 1] # 가만히 놔둬도 기온이 올라갈 때 (cool)

dp[time][goalTemperature] = dp[time - 1][goalTemperature + 1] # 가만히 놔둬도 기온이 내려갈 때 (warm)

dp[time][goalTemperature] = dp[time - 1][goalTemperature - 1] + a # 에어컨을 켜서 기온을 높일 때 (warm)

dp[time][goalTemperature] = dp[time - 1][goalTemperature + 1] + a # 에어컨을 켜서 기온을 낮출 때 (cool)
'''
