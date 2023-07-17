def solution_my(n) -> int:
    hour = n
    answer = second = minute = 0
    for i in range(60):
        if str(i).find('3') != -1:
            second += 1

    for i in range(60):
        if str(i).find('3') != -1:
            minute += 60
        else:
            minute += second

    for i in range(hour + 1):
        if str(i).find('3') != -1:
            answer += 3600
        else:
            answer += minute
    return answer

def solution_main(n) -> int:
    answer = 0
    for i in range(n + 1):
        for j in range(60):
            for k in range(60):
                if '3' in str(i) + str(j) + str(k):
                    answer += 1

    return answer