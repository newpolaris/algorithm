from heapq import heappush, heappop

for case in range(int(input())):
    v, e, n, m = map(int, input().split())
    adj = {i: [] for i in range(0, v+1)}
    for _ in range(e):
        a, b, t = map(int, input().split())
        adj[a].append((b, t))
        adj[b].append((a, t))
    fires = map(int, input().split())
    stations = map(int, input().split())
    h = []
    for s in stations:
        heappush(h, (0, int(s)))

    dist = [1e10]*(v+1)
    while h:
        t, here = heappop(h)
        if dist[here] < t:
            continue
        for there, dt in adj[here]:
            newd = t+dt
            if dist[there] > newd:
                dist[there] = newd
                heappush(h, (newd, there))
    print(sum([dist[f] for f in fires]))
