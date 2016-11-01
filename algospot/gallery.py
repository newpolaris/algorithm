from collections import defaultdict


def dfs(here):
    global installed
    if visited[here]:
        return 'visited'
    visited[here] = 1
    children = defaultdict(int)
    for nxt in halls[here]:
        children[dfs(nxt)] += 1
    if children['unwatched']:
        installed += 1
        return 'installed'
    if children['installed']:
        return 'watched'
    return 'unwatched'

for case in range(int(input())):
    G, H = map(int, input().split())
    halls = defaultdict(list)
    visited = [0]*G
    installed = 0
    for a, b in (map(int, input().split()) for _ in range(H)):
        halls[a].append(b)
        halls[b].append(a)
    for i in range(G):
        if dfs(i) == 'unwatched':
            installed += 1
    print(installed)
