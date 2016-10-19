for t in xrange(input()):
    n = int(input())
    a = sorted(map(float, raw_input().split()))
    maxscore = max((x+y)/2 for x, y in zip(a, reversed(a)))
    print("%.1f" % maxscore)
