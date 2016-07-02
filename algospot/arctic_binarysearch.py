# warn : 768 ms in pypy

def dist(a, b):
    return (C[a][0]-C[b][0])**2 + (C[a][1]-C[b][1])**2

def p(d):
    visited, q = [0], [0]
    while len(q):
        here = q.pop()
        K = [i for i in range(0, N) if i not in visited and dist(here, i) <= d]
        visited.extend(K)
        q.extend(K)
    return len(visited) == N


for c in xrange(input()):
    N = input()
    C = [map(float, raw_input().split()) for _ in xrange(N)]
    lo, hi = 0, 1e7
    while hi-lo > 0.009:
        mid = (lo + hi)/2
        if p(mid):
            hi = mid
        else:
            lo = mid
    print('%.2f' %lo**0.5)
