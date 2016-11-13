from collections import defaultdict
from heapq import heappop, heappush

for case in range(int(input())):
    m = int(input())
    sports = [list(map(int, input().split())) for _ in range(m)]
    inf = 1e10
    adj = defaultdict(lambda: inf)
    for a, b in sports:
        adj[a-b] = min(adj[a-b], a)
    dist = defaultdict(lambda: inf)
    visit = set()
    h = [(0, 0)]
    while h:
        t, here = heappop(h)
        if here in visit:
            continue
        visit.add(here)
        for dh, dt in adj.items():
            there = here + dh
            if abs(there) >= 200:
                continue
            dist[there] = min(dist[there], t+dt)
            heappush(h, (t+dt, there))
    print("IMPOSSIBLE" if dist[0] == inf else dist[0])
