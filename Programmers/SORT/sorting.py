array = [7, 3, 9, 0, 3, 1, 6, 2, 4, 8]


def 선택정렬():
    for i in range(len(array)):
        min_index = i
        for j in range(i + 1, len(array)):
            if array[min_index] > array[j]:
                min_index = j
        array[i], array[min_index] = array[min_index], array[i]

    print(array)


def 삽입정렬():
    for i in range(len(array)):
        for j in range(i, 0, -1):
            if array[j] < array[j - 1]:
                array[j], array[j - 1] = array[j - 1], array[j]
            else:
                break

    print(array)


def 퀵정렬(start, end):
    if start >= end:
        return
    pivot = start
    left = start + 1
    right = end
    while (left <= right):
        while (left <= end and array[left] <= array[pivot]):
            left += 1
        while (right > start and array[right] >= array[pivot]):
            right -= 1
        if (left > right):
            array[right], array[pivot] = array[pivot], array[right]
        else:
            array[left], array[right] = array[right], array[left]

    퀵정렬(start, right - 1)
    퀵정렬(right + 1, end)


def 퀵정렬_파이썬(array):
    if len(array) <= 1:
        return array
    pivot = array[0]
    tail = array[1:]

    left_side = [x for x in tail if x <= pivot]
    right_side = [x for x in tail if x > pivot]

    return 퀵정렬_파이썬(left_side) + [pivot] + 퀵정렬_파이썬(right_side)


def 계수정렬():
    count = [0] * (max(array) + 1)

    for i in range(len(array)):
        count[array[i]] += 1

    for i in range(len(count)):
        for j in range(count[i]):
            print(i, end=' ')
