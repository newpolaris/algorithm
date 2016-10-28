# fleo0917's
from itertools import combinations
from string import ascii_lowercase as ascii


def dfs(now):
    if visit[now]:
        return
    visit[now] = 1
    for nxt in inv.get(now, []):
        dfs(nxt)
    order.append(now)

for case in range(int(input())):
    n = int(input())
    words = [input().strip() for _ in range(n)]
    inv = {}
    for i in range(0, n-1):
        for j, k in zip(words[i], words[i+1]):
            x, y = ord(j)-ord('a'), ord(k)-ord('a')
            if x != y:
                inv.setdefault(k, set()).add(j)
                break
    visit = {c: 0 for c in ascii}
    order = []
    for c in ascii:
        dfs(c)
    if any(a in inv and b in inv[a] for a, b in combinations(order, 2)):
        print('INVALID HYPOTHESIS')
    else:
        print(''.join(order))
