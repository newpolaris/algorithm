def bellman2(src, dest, op):
    inf = 1e10
    upper = [inf] * v
    upper[src] = 0
    for loop in range(v-1):
        for a in range(v):
            for b, d in adj[a]:
                upper[b] = min(upper[b], op(upper[a], d))
    for a in range(v):
        for b, d in adj[a]:
            if upper[b] > op(upper[a], d):
                if reachable[src][a] and reachable[b][dest]:
                    return -inf
    return upper[dest]


for case in range(int(input())):
    v, w = map(int, input().split())
    adj = {i: [] for i in range(v)}
    for _ in range(w):
        a, b, d = map(int, input().split())
        adj[a].append((b, d))
    reachable = [[False for _ in range(v)] for _ in range(v)]
    for i in range(v):
        reachable[i][i] = True
    for a in range(v):
        for b, d in adj[a]:
            reachable[a][b] = True
    for a in range(v):
        for i in range(v):
            for j in range(v):
                reachable[i][j] = reachable[i][j] or (reachable[i][a] and reachable[a][j])
    if not reachable[0][1]:
        print("UNREACHABLE")
    else:
        ans = [bellman2(0, 1, lambda a, b: a+b), -bellman2(0, 1, lambda a, b: a - b)]
        for n, i in enumerate(ans):
            if abs(i) > 1e5:
                ans[n] = "INFINITY"
        print(ans[0], ans[1])
