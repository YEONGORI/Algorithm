from heapq import heappush, heappop

N = 10 ** 9

class Node:
    live = True
    
    def __init__(self, p, n):
        self.prev = p if p >= 0 else None
        self.next = n if n < N else None

def solution(n, k, cmd):
    global N
    N = n
    
    table = {i: Node(i-1, i+1) for i in range(n)}
    cur = k
    del_val = []
    
    for c in cmd:
        if c[0] == 'C':
            table[cur].live = False
            del_val.append(cur)
            
            prev, next = table[cur].prev, table[cur].next
            if prev is not None:
                table[prev].next = next
            if next is not None:
                table[next].prev = prev
            
            if table[cur].next is None:
                cur = table[cur].prev
            else:
                cur = table[cur].next
        elif c[0] == 'Z':
            activate = del_val.pop()
            table[activate].live = True

            prev, next = table[activate].prev, table[activate].next

            if prev is not None:
                table[prev].next = activate
            if next is not None:
                table[next].prev = activate
        else:
            if c[0] == 'U':
                for _ in range(int(c[2:])):
                    cur = table[cur].prev
            else:
                for _ in range(int(c[2:])):
                    cur = table[cur].next
                
    
    return ''.join('O' if table[i].live else 'X' for i in range(n))