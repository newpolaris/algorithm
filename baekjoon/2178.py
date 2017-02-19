# pq를 쓸표가 없다. BFS 잖아
n, m = map(int, input().split())
maze = [input() for i in range(n)]
visit = [[1]*m for i in range(n)]
h = [(1, 0, 0)]
while len(h):
    l, x, y = h.pop(0)
    if not visit[y][x]:
        continue
    visit[y][x] = 0
    if y == n-1 and x == m-1:
        print(l)
        break
    ds = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    for d in ds:
        nx = x + d[0]
        ny = y + d[1]
        if nx < 0 or nx >= m or ny < 0 or ny >= n:
            continue
        if maze[ny][nx] == '0' or visit[ny][nx] == 0:
            continue
        h.append((l+1, nx, ny))
