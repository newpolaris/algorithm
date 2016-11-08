from heapq import heappop, heappush
from math import log, e

for case in range(int(input())):
    n, m = map(int, input().split())
    adj = {i: [] for i in range(n)}
    for _ in range(m):
        a, b, c = input().split()
        a, b = map(int, [a, b])
        c = log(float(c))
        adj[a].append((b, c))
        adj[b].append((a, c))
    noise = [1e200] * n
    noise[0] = 0
    h = [(0.0, 0)]
    while h:
        cost, here = heappop(h)
        if noise[here] < cost:
            continue
        for there, cost2 in adj[here]:
            cost3 = cost2 + cost
            if noise[there] > cost3:
                noise[there] = cost3
                heappush(h, (cost3, there))
    print("%.10f" % e**noise[-1])
