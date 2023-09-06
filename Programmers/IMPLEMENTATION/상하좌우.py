def solution(n):
    cmd_list = input()
    cmd_list = cmd_list.split()
    x = y = 0
    
    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]
    cmd_type = ['L', 'R', 'U', 'D']

    for cmd in cmd_list:
        for i in range(len(cmd_type)):
            if cmd == cmd_type[i]:
                nx = x + dx[i]
                ny = y + dy[i]
        if nx < 0 or ny < 0 or nx >= n or ny >= n:
            continue
        x, y = nx, ny

    print(x + 1, y + 1)

solution(5)
