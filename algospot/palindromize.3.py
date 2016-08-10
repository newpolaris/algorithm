def partial(s):
    m = len(s)
    pi = [0]*m
    begin = 1
    matched = 0
    while begin+matched < m:
        if s[begin+matched] == s[matched]:
            matched += 1
            pi[begin+matched-1] = matched
        else:
            if matched == 0:
                begin += 1
            else:
                begin += matched - pi[matched-1]
                matched = pi[matched-1]
    return pi

for t in xrange(input()):
    s = raw_input()
    ol = len(s)
    # reverse : caba + abac -> abac caba
    s = s[::-1] + s
    pt = partial(s)
    l = len(s)
    k = l-1
    # in case of 'abaa'
    # s = 'aabaabaa' so, pt = [0, 1, 0, 1, 2, 3, 4, 5]
    # find valid deleted pt[k]. k = 4, pt[k] = 2
    while pt[k] > ol:
        k = pt[k]-1

    print l - pt[k]
