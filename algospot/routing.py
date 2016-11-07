import sys
from heapq import heappop, heappush

input = sys.stdin.readline

for c in range(int(input())):
    n, m = map(int, input().split())
    adj = {i: [] for i in range(n)}
    for _ in range(m):
        a, b, c = input().split()
        a, b = map(int, [a, b])
        c = float(c)
        adj[a].append((b, c))
        adj[b].append((a, c))
    inf = float("inf")
    noise = [inf] * n
    h = [(1.0, 0)]
    visited = [False] * n
    while h:
        cost, here = heappop(h)
        if noise[here] < cost:
            continue
        for there, cost2 in adj[here]:
            cost2 *= cost
            if noise[there] > cost2:
                noise[there] = cost2
                heappush(h, (cost2, there))
    print("%.10f" % noise[n-1])
