import heapq

# f = open("ordering.in")
# input = f.readline

for c in range(int(input())):
    n, m = map(int, input().split())
    bRoot = [True] * n
    bUsed = [False] * n
    child = [set() for i in range(n)]
    parent = [set() for i in range(n)]
    for i in range(m):
        dep = input().strip()
        pa, ch = map(lambda c: ord(c) - ord('A'), dep)
        child[pa].add(ch)
        parent[ch].add(pa)
        bRoot[ch] = False
    h = []
    root = [i for i in range(len(bRoot)) if bRoot[i]]
    for i in root:
        heapq.heappush(h, i)
    ans = []
    while len(h) > 0:
        k = heapq.heappop(h)
        if bUsed[k]:
            continue

        if all(bUsed[j] for j in parent[k]):
            bUsed[k] = True
            ans.append(k)
            for i in child[k]:
                heapq.heappush(h, i)
    print(''.join([chr(i+ord('A')) for i in ans]))
