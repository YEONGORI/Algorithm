from heapq import heappush, heappop
from copy import copy


def cal_spend_time(mentorList, waitList, k):
    time = 0

    for _type in range(k):  # 타입 별로 대기 시간 계산
        endTime = []
        for _start, _spend, t in waitList:  # start_time, spend_time, type
            if t != _type + 1:
                continue
            if mentorList[_type] > 0:
                heappush(endTime, _start + _spend)
                mentorList[_type] -= 1
            else:
                if _start < endTime[0]:
                    time += endTime[0] - _start
                heappush(endTime, endTime[0] + _spend)
                heappop(endTime)
    return time


# 20, 40 = 60
# 50, 45 = 95
#          60 - 50

# 5, 55 = 60
# 10, 90 = 100
# 100, 50 = 150
#           100 - 60


def solution(k, n, reqs):
    mentors = [1] * k
    dp = [1e9] * (n)
    # for i in range(k):
    #     dp[i] = 0

    for i in range(k - 1, n):
        if sum(mentors) < n:
            idx = 0
            for j in range(k):
                mentors[j] += 1
                time = cal_spend_time(copy(mentors), reqs, k)
                if dp[i] > time:
                    idx = j
                    dp[i] = time
                mentors[j] -= 1
            mentors[idx] += 1
        else:
            dp[i] = cal_spend_time(copy(mentors), reqs, k)
    return dp[n-1]


print(solution(3, 5, [[10, 60, 1], [15, 100, 3], [20, 30, 1], [30, 50, 3], [50, 40, 1], [60, 30, 2], [65, 30, 1], [70, 100, 2]]
               ))
print(solution(2, 3, [[5, 55, 2], [10, 90, 2],
      [20, 40, 2], [50, 45, 2], [100, 50, 2]]))
print(solution(2, 3, [[5, 55, 2], [10, 90, 2], [
    20, 40, 1], [50, 45, 1], [100, 50, 2]]))
print(solution(1, 1, [[5, 55, 1], [55, 60, 1]]))
print(solution(3, 3, [[10, 60, 1], [15, 100, 3], [20, 30, 1], [30, 50, 3], [50, 40, 1], [60, 30, 2], [65, 30, 1], [70, 100, 2]]
               ))

70 
  50
100
  50
140
  75
115
  85
90
  20