def dfs(i):
    bUsed[i] = bTwice[i] = True
    for a in adj[i]:
        if not bUsed[a]:
            dfs(a)
        elif bTwice[a]:
            bCycle[0] = True
    sol.append(i)
    bTwice[i] = False

for c in range(int(input())):
    n = int(input())
    l = [input().strip() for _ in range(n)]
    adj = [[] for _ in range(26)]
    for i in range(1, len(l)):
        a, b = l[i-1], l[i]
        k = min(len(a), len(b))
        for i in range(k):
            x, y = ord(a[i])-ord('a'), ord(b[i])-ord('a')
            if x == y:
                continue
            adj[y].append(x)
            break
    bUsed = [False for i in range(26)]
    bTwice = [False for i in range(26)]
    bCycle = [False]
    sol = []
    for i in range(26):
        if not bUsed[i]:
            dfs(i)
    sol = [chr(i+ord('a')) for i in sol]
    if bCycle[0] is True:
        print('INVALID HYPOTHESIS')
    else:
        print(''.join(sol))
