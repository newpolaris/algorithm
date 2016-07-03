for _ in xrange(input()):
    N, K = map(int, raw_input().split())
    grade = map(int, raw_input().split())
    grade = zip(*[iter(grade)]*2)

    lo, hi = -0.0, 1.0
    for i in xrange(100):
        mid = (hi + lo)/2.0
        if sum(sorted(mid*c - r for r, c in grade)[-K:]) >= 0:
            hi = mid
        else:
            lo = mid
    print('%.8f'%lo)
