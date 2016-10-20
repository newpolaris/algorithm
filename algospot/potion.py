# from fractions import gcd
from functools import reduce
import math


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
    ratio = max(p[i]/frac[i] for i in range(len(r)))
    ratio = max(int(math.ceil(ratio)), 1)
    need = [ratio*frac[i] - p[i] for i in range(len(r))]
    print(' '.join(str(i) for i in need))
