for i in xrange(input()):
    a, b = map(int, (raw_input().split()))
    c = 0
    if b >= a:
        c = b - a + 4
    print(c)
