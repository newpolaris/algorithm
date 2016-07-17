def accumulate(l):
    t = 0
    for i in l:
        t += i
        yield t

for t in xrange(input()):
    n, k = map(int, raw_input().split())
    l = map(int, raw_input().split())
    s = [0] + [i % k for i in accumulate(l)]
    c = [0]*k
    for i in s:
        c[i] += 1
    m = 20091101
    a = sum(i*(i-1)//2 % m for i in c) % m
    b, last = 0, 0
    p = [-1]*k
    for i in range(len(s)):
        r = s[i]
        if p[r] >= last:
            b, last = b+1, i
        p[r] = i
    print a, b
