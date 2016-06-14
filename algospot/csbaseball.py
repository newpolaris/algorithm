for i in xrange(input()):
    a, b = map(int, (raw_input().split()))
    print (0 if b < a else b - a + 4)
