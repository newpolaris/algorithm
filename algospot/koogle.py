import math


for c in range(int(input())):
    n = int(input())
    l = sorted([input().lower() for i in range(n)])
    pw = ('', 0)
    for s in l:
        cnt = 0
        for c in s:
            if 'a' <= c <= 'z':
                cnt += 1
        power = cnt + math.log(10)*(len(s) - cnt)/math.log(26)
        if pw[1] < power:
            pw = (s, power)
    print(pw[0])
