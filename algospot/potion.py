# from fractions import gcd
from functools import reduce


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

for c in range(int(input())):
    n = int(input())
    # 넣어야할 양
    r = list(map(int, input().split()))
    # 넣어버린 양
    p = list(map(int, input().split()))
    res = reduce(gcd, r)
    # 넣어야할 양의 비율 구하기
    frac = [i//res for i in r]
    # 비율 중 가장 높은 것에 맞추기 위해 비율 계산
    # Instead of ceil(), use (a-1)//b + 1
    ratio = max((a-1)//b+1 for a, b in zip(p, frac))
    ratio = max(ratio, 1)
    # 가장 높은 비율에 맞춰 계속 넣기
    need = [ratio*a - b for a, b in zip(frac, p)]
    print(' '.join(str(i) for i in need))
