from collections import defaultdict
from heapq import heappop, heappush

for case in range(int(input())):
    maxn = 200
    m = int(input())
    sports = [list(map(int, input().split())) for _ in range(m)]
    sports.sort(reverse=True)
    adj = defaultdict(dict)
    for i in range(-maxn+1, maxn):
        for a, b in sports:
            c = i + a - b
            if abs(c) >= maxn:
                continue
            adj[i][c] = a
    inf = 1e10
    dist = defaultdict(lambda: inf)
    h = []
    for a, b in sports:
        heappush(h, (a, a - b))
    while h:
        t, here = heappop(h)
        if dist[here] < t:
            continue
        for there, dt in adj[here].items():
            tnext = t + dt
            if dist[there] > tnext:
                dist[there] = tnext
                heappush(h, (tnext, there))
    print("IMPOSSIBLE" if dist[0] == inf else dist[0])
