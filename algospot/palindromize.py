for i in xrange(input()):
    a = raw_input()
    ra = a[::-1]

    n = len(a)
    pi = [0]*n
    m = 0
    for i in range(1,n):
        while m > 0 and ra[i] != ra[m]:
            m = pi[m-1]
        if ra[i] == ra[m]:
            m += 1
        pi[i] = m
    k = 0
    for i in range(0,n):
        while k > 0 and a[i] != ra[k]:
            k = pi[k-1]
        if a[i] == ra[k]:
            k += 1
            if i - 1 == n:
                break
    print(n*2 - k)


