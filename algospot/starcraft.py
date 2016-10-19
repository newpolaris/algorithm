import operator as op

def ncr(n, r):
    r = min(r, n-r)
    if r == 0: return 1
    numer = reduce(op.mul, xrange(n, n-r, -1))
    denom = reduce(op.mul, xrange(1, r+1))
    return numer//denom

for t in xrange(input()):
    pi, k = map(int, raw_input().split())
    p = float(pi)/100
    pc = 1.0 - p
    prob = pow(p, k)
    for i in xrange(k-1):
        prob += ncr(k+i, k-1)*pow(p, k)*pow(pc, 1+i)
    prob = int(round(prob*100))
    print prob
    
