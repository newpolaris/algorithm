# fleo0917's answer

from itertools import accumulate

for case in xrange(input()):
    N, K = map(int, raw_input().split())
    seq = map(int, raw_input().split())
    acc = [0] + [i % K for i in accumulate(seq)]

    cnt = [0]*K
    for i in acc:
        cnt[i % K] += 1
    MOD = 20091101
    ans1 = sum((i*(i-1)//2) % MOD for i in cnt) % MOD 

    ans2 = [0]*(N+1)
    prev = [-1]*K
    for i in range(N+1):
        if i > 0:
            ans2[i] = ans2[i-1]
        else:
            ans2[i] = 0
        loc = prev[acc[i]]
        if loc != -1:
            ans2[i] = max(ans2[i], ans2[loc] + 1)
        prev[acc[i]] = i

    print(ans1, ans2[N])
