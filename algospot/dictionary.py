# fleo0917's
from itertools import combinations
from string import ascii_lowercase as ascii


def dfs(now):
    if vst[now]:
        return
    vst[now] = 1
    for nxt in inv.get(now, []):
        dfs(nxt)
    order.append(now)

for case in range(int(input())):
    n = int(input())
    words = [input() for _ in range(n)]
    inv = {}
    for i in range(n-1):
        for i, j in zip(words[i], words[i+1]):
            if i != j:
                inv.setdefault(j, set()).add(i)
                break
    vst = {c: 0 for c in ascii}
    order = []
    for c in ascii:
        dfs(c)
    if any(a in inv and b in inv[a] for a, b in combinations(order, 2)):
        print('INVALID HYPOTHESIS')
    else:
        print(''.join(order))
