def p(mid):
    num, last = 1, 0
    for i in range(1, M):
        if L[i] - L[last] >= mid:
            last = i
            num = num + 1
    return num >= N
    
for c in xrange(input()):
    N, M = map(int, raw_input().split())
    L = list(map(float, raw_input().split()))
    lo, hi = 0, 240
    while (hi - lo > 0.0001):
        mid = lo + (hi-lo)/2.0
        if p(mid):
            lo = mid
        else:
            hi = mid
    print('%.2f' %lo)
