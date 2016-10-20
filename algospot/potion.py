# from fractions import gcd
from functools import reduce


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

for c in range(int(input())):
    n = int(input())
    r = list(map(int, input().split()))
    p = list(map(int, input().split()))
    res = reduce(gcd, r)
    frac = [i//res for i in r]
    # instead of ceil. it use (a-1)//b + 1
    ratio = max((a-1)//b + 1 for a, b in zip(p, frac))
    ratio = max(ratio, 1)
    need = [ratio*a - b for a, b in zip(frac, p)]
    print(' '.join(str(i) for i in need))
