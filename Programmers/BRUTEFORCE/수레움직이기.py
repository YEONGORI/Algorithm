directions = ((1, 0), (-1, 0), (0, 1), (0, -1), (0, 0))
ans = 1e9
def solution(maze):
    R_GOAL, B_GOAL, WALL = 3, 4, 5
    r_cur = b_cur = R_GOLE_POS = B_GOLE_POS = 0
    lx, ly = len(maze), len(maze[0])

    for x in range(lx):
        for y in range(ly):
            if maze[x][y] == 1: r_cur = (x, y)
            if maze[x][y] == 2: b_cur = (x, y)
            if maze[x][y] == 3: r_goal = (x, y)
            if maze[x][y] == 4: b_goal = (x, y)
    r_vis, b_vis = [[False] * ly for _ in range(lx)], [[False] * ly for _ in range(lx)]
    r_vis[r_cur[0]][r_cur[1]], b_vis[b_cur[0]][b_cur[1]] = True, True
    
    def out_of_index(x, y):
        return x < 0 or y < 0 or x >= lx or y >= ly
    def visited(vis, goal, x, y):
        return maze[x][y] != goal and vis[x][y]
    def duplicated(x1, x2, y1, y2):
        return x1 == x2 and y1 == y2
    def crossed(cur1, cur2, next1, next2):
        return cur1 == next2 and cur2 == next1
    def dfs(r_cur, b_cur, r_vis, b_vis, cnt):
        global ans
        if r_cur == r_goal and b_cur == b_goal:
            ans = min(ans, cnt)
            return
        for d_rx, d_ry in directions:
            rx_next, ry_next = r_cur[0] + d_rx, r_cur[1] + d_ry

            if out_of_index(rx_next, ry_next) \
            or visited(r_vis, R_GOAL, rx_next, ry_next) \
            or maze[rx_next][ry_next] == WALL:
                continue

            r_vis[rx_next][ry_next] = True
            for d_bx, d_by in directions:
                if (d_rx, d_ry) == (0, 0) and (d_bx, d_by) == (0, 0): break
                bx_next, by_next = b_cur[0] + d_bx, b_cur[1] + d_by
                
                if out_of_index(bx_next, by_next) \
                or visited(b_vis, B_GOAL, bx_next, by_next) \
                or maze[bx_next][by_next] == WALL \
                or duplicated(bx_next, rx_next, ry_next, by_next) \
                or crossed(r_cur, b_cur, (rx_next,ry_next), (bx_next,by_next)):
                    continue
                b_vis[bx_next][by_next] = True
                dfs((rx_next, ry_next), (bx_next, by_next), r_vis, b_vis, cnt + 1)
                b_vis[bx_next][by_next] = False
            r_vis[rx_next][ry_next] = False
    dfs(r_cur, b_cur, r_vis, b_vis, 0)
    return 0 if ans == 1e9 else ans