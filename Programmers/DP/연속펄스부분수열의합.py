def solution(sequence):
    def get_max(arr):
        dp = [0] * len(arr)
        dp[0] = arr[0]
        for i in range(1, len(arr)):
            dp[i] = max(0, dp[i-1]) + arr[i]
        return max(dp)

    pulse = -1
    pulse_1, pulse_2 = [], []

    for s in sequence:
        pulse_1.append(s * pulse)
        pulse_2.append(s * -pulse)
        pulse *= -1

    return max(get_max(pulse_1), get_max(pulse_2))