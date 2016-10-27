from string import ascii_uppercase
from heapq import heappop, heappush

for c in range(int(input())):
    n, m = map(int, input().split())
    d = {}
    child = {}
    for i in ascii_uppercase[:n]:
        d[i] = 0
        child[i] = set()
    for i in range(m):
        a, b = input().strip()
        child[a].add(b)
        d[b] += 1
    h = []
    ans = ''
    [heappush(h, i) for i in d if d[i] == 0]
    while h:
        k = heappop(h)
        ans += k
        for i in child[k]:
            d[i] -= 1
            if d[i] == 0:
                heappush(h, i)
    print(ans)
