from itertools import combinations

def bitcount(n):
    return bin(n).count("1")

def possible(taken, semester):
    return [s for s in classes[semester] if all(taken & 1<<p for p in prerequisite[s])]
    
def graduate(taken, semester):
    if bitcount(taken) >= k:
        return 0
    if semester >= m:
        return inf
    ret = cache[taken][semester]
    if ret > 0:
        return ret
    cache[taken][semester] = inf
    canTake = possible(taken, semester) 
    takes = list(combinations(canTake, min(l, len(canTake))))
    for take in takes:
        t = sum(1 << x for x in take)
        cache[taken][semester] = min(cache[taken][semester], graduate(t | taken, semester + 1) + 1)
    cache[taken][semester] = min(cache[taken][semester], graduate(taken, semester + 1))
    return cache[taken][semester]
        
def read(i):
    return [map(int, raw_input().split())[1:] for _ in range(i)]

for c in xrange(input()):
    n, k, m, l = map(int, raw_input().split())
    inf = k+1
    prerequisite = read(n)
    classes = read(m)
    cache = [[-1]*m for _ in range(1<<n)]
    need = graduate(0, 0)
    print need if need < m else "IMPOSSIBLE"
