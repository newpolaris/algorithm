import math


def sec(s):
    cnt = sum(c.isalpha() for c in s)
    return math.log10(26)*cnt + len(s) - cnt

for c in range(int(input())):
    n = int(input())
    pw = sorted([input().lower() for i in range(n)])
    print(max(pw, key=sec))
