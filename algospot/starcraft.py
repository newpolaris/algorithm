import operator as op

def ncr(n, r):
    r = min(r, n-r)
    if r == 0: return 1
    numer = reduce(op.mul, xrange(n, n-r, -1))
    denom = reduce(op.mul, xrange(1, r+1))
    return numer//denom

for t in xrange(input()):
    p, k = map(int, raw_input().split())
    p = float(p)/100
    pc = 1.0 - p
    prob = sum(ncr(k+i-1, i)*pow(p, k)*pow(pc,i) for i in range(k))
    print int(round(prob*100))
    
