from collections import Counter
from functools import reduce
import operator


def eratosthenes(L):
    minFactor = [i for i in range(L+1)]
    minFactor[0] = minFactor[1] = -1
    for i in range(2, int(len(minFactor)**0.5)+1):
        for k in range(i*i, L+1, i):
            if minFactor[k] == k:
                minFactor[k] = i
    return minFactor


def divisor_count(v):
    cnt = Counter()
    while v >= 1:
        cnt += Counter(v)
        v = minFactor[v]
    return reduce(operator.mul, [c+1 for v, c in cnt], 1)


for case in range(int(input())):
    L = 10000000
    minFactor = eratosthenes(L)
    print(divisor_count(2))
