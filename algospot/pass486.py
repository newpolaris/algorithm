import sys

if sys.version_info[0] < 3:
    input = raw_input


def eratosthenes(L):
    minFactor = [i for i in range(L+1)]
    minFactor[0] = minFactor[1] = -1
    sqrtn = int((L+1)**0.5)
    for i in range(2, sqrtn+1):
        for k in range(i*i, L+1, i):
            if minFactor[k] == k:
                minFactor[k] = i
    return minFactor


def count_divisor(minFactor):
    N = len(minFactor)
    minFactorCnt = [1]*N
    divisorCnt = [0]*N
    divisorCnt[1] = 1
    for i in range(2, N):
        m = i // minFactor[i]
        d = 1
        if minFactor[i] == minFactor[m]:
            d = minFactorCnt[i] = minFactorCnt[m]+1
            f = minFactorCnt[i]+1
        else:
            f = 2
        divisorCnt[i] = divisorCnt[m]*f//d
    return divisorCnt


L = 10000000
minFactor = eratosthenes(L)
divisorCnt = count_divisor(minFactor)
for case in range(int(input())):
    n, lo, hi = map(int, input().split())
    print(sum(divisorCnt[i] == n for i in range(lo, hi+1)))
