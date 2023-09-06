def solution(storey):
    answer, num = 0, storey
    
    while num:
        storey, moves = divmod(storey, 10)
        if moves > 5 or (moves == 5 and storey % 10 > 5):
            moves = 10 - moves
            storey += 1
        answer += moves

    return answer