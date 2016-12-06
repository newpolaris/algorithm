def dfs(aMatch, bMatch, visited, a):
    if visited[a]:
        return False
    visited[a] = True
    for b in range(M):
        if adj[a][b] == 0:
            continue
        if bMatch[b] == -1 or dfs(aMatch, bMatch, visited, bMatch[b]):
            aMatch[a] = b
            bMatch[b] = a
            return True
    return False


def bipartileMatch():
    aMatch = [-1] * N
    bMatch = [-1] * M
    for a in range(N):
        visited = [False] * N
        dfs(aMatch, bMatch, visited, a)
    return (aMatch, bMatch)


def calcMaxIndipendentSet():
    aMatch, bMatch = bipartileMatch()
    aChosen = [True] * N
    bChosen = [False] * M
    for i in range(M):
        if bMatch[i] == -1:
            bChosen[i] = True
    while True:
        changed = False
        for i in range(N):
            for j in range(M):
                if aChosen[i] and bChosen[j] and adj[i][j]:
                    aChosen[i] = False
                    bChosen[aMatch[i]] = True
                    changed = True
        if not changed:
            break
    return (aChosen, bChosen)

for case in range(int(input())):
    H, W = map(int, input().split())
    trapMap = [list(input()) for _ in range(H)]
    M = N = 0
    dt = [[-1]*W for _ in range(H)]
    coords = {}
    for h in range(H):
        for w in range(W):
            if trapMap[h][w] == '#':
                continue
            if (h+w) % 2 == 0:
                dt[h][w] = N
                coords[(N, 'a')] = (h, w)
                N += 1
            else:
                dt[h][w] = M
                coords[(M, 'b')] = (h, w)
                M += 1
    adj = [[0]*M for _ in range(N)]
    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]
    for h in range(H):
        for w in range(W):
            if (h+w) % 2 == 1 or dt[h][w] == -1:
                continue
            for x, y in zip(dx, dy):
                x += w
                y += h
                if 0 <= x < W and 0 <= y < H and dt[y][x] != -1:
                    adj[dt[h][w]][dt[y][x]] = 1
    aChosen, bChosen = calcMaxIndipendentSet()
    trap = [(i, 'a') for i, b in enumerate(aChosen) if b]
    trap += [(i, 'b') for i, b in enumerate(bChosen) if b]
    for t in trap:
        h, w = coords[t]
        trapMap[h][w] = '^'
    print(len(trap))
    for l in trapMap:
        print(''.join(l))
