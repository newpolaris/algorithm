queue = [tuple(range(i)) for i in range(1, 9)]
cache = {s: 0 for s in queue}
for q in queue:
    l = len(q)
    for i in range(l):
        for j in range(i+2, l+1):
            p = q[:i] + q[i:j][::-1] + q[j:]
            if p not in cache:
                queue.append(p)
                cache[p] = cache[q] + 1

for _ in range(int(input())):
    n = int(input())
    v = map(int, input().split())
    vi = tuple([i[0] for i in sorted(enumerate(v), key=lambda x:x[1])])
    print(cache[vi])
