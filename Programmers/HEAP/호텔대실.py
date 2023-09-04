from heapq import heappush, heappop

def solution(book_time):
    answer = 0
    new_bt = []
    room = []
    
    for bt in book_time:
        st = int(bt[0][:2]) * 60 + int(bt[0][3:])
        en = int(bt[1][:2]) * 60 + int(bt[1][3:]) + 10
        new_bt.append([st, en])
    new_bt.sort()
    
    heappush(room, 0)
    for st, en in new_bt:
        if room[0] <= st:
            heappop(room)
        heappush(room, en)
        answer = max(answer, len(room))

    return answer