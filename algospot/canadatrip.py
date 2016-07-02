for c in xrange(input()):
    N, K = map(int, raw_input().split())
    Cities = [map(int, raw_input().split()) for _ in xrange(N)]
    lo, hi = 0, 8030000
    while lo < hi:
        mid = lo + (hi-lo)//2
        if sum((M-L+min(mid, L))//G + 1 for L, M, G in Cities if L - M <= mid) >= K:
            hi = mid
        else:
            lo = mid + 1
    print('%d' %lo)
