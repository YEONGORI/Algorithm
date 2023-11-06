def solution(numbers):
    wei = ((1,7,6,7,5,4,5,3,2,3),
          (7,1,2,4,2,3,5,4,5,6),
          (6,2,1,2,3,2,3,5,4,5),
          (7,4,2,1,5,3,2,6,5,4),
          (5,2,3,5,1,2,4,2,3,5),
          (4,3,2,3,2,1,2,3,2,3),
          (5,5,3,2,4,2,1,5,3,2),
          (3,4,5,6,2,3,5,1,2,4),
          (2,5,4,5,3,2,3,2,1,2),
          (3,6,5,4,5,3,2,4,2,1))
    
    dp = {(4, 6): 0, (6, 4): 0}
    for n in numbers:
        n = int(n)
        new_dp = {}
        for (i1, i2), tot in dp.items():
            if i1 == n or i2 == n:
                result = min(new_dp.get((i1, i2), float('inf')), tot + 1)
                new_dp[(i1, i2)] = new_dp[(i2, i1)] = result
            else:
                result1 = min(new_dp.get((i1, n), float('inf')), tot + wei[i2][n])
                result2 = min(new_dp.get((i2, n), float('inf')), tot + wei[i1][n])
                
                new_dp[(i1, n)] = new_dp[(n, i1)] = result1
                new_dp[(i2, n)] = new_dp[(n, i2)] = result2
        dp = new_dp
    return min(dp.values())
                
                

            
        
        