from string import ascii_lowercase as ascii


def eulercircuit(here):
    d = dic.get(here, [])
    for c in d:
        while d:
            w = d.pop()
            eulercircuit(w[-1])
            ans.append(w)


def check(ans):
    if len(ans) != n:
        return False
    for i in range(n - 1):
        if ans[i][-1] != ans[i+1][0]:
            return False
    return True

for case in range(int(input())):
    n = int(input())
    words = [input().strip() for _ in range(n)]
    dic = {}
    inDeg = {c: 0 for c in ascii}
    otDeg = {c: 0 for c in ascii}
    for w in words:
        dic.setdefault(w[0], []).append(w)
        inDeg[w[0]] += 1
        otDeg[w[-1]] += 1
    st = -1
    for c in ascii:
        if inDeg[c] > 0 and (st == -1 or inDeg[c] == otDeg[c] + 1):
            st = c
    ans = []
    eulercircuit(st)
    ans.reverse()
    if check(ans):
        print(' '.join(ans))
    else:
        print('IMPOSSIBLE')
