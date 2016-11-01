def dfs(here):
    if visited[here]:
        return 3
    visited[here] = True
    cnt = [0] * 4
    for c in adj[here]:
        cnt[dfs(c)] += 1
    if cnt[0]:
        global numCam
        numCam += 1
        return 2
    if cnt[2]:
        return 1
    return 0

for case in range(int(input())):
    g, h = map(int, input().split())
    adj = [[] for i in range(g)]
    visited = [False]*g
    numCam = 0
    for i in range(h):
        a, b = map(int, input().split())
        adj[a].append(b)
        adj[b].append(a)
    for i in range(g):
        if dfs(i) == 0:
            numCam += 1
    print(numCam)
